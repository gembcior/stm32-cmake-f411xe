#include <cstdint>
#include "tusb_option.h"
#include "device/dcd.h"
#include "objects/objects.h"
#include "otg_fs/OtgFsDeviceHal.h"
#include <array>

#include "dral/otg_fs_device.h"
#include "dral/otg_fs_global.h"

#include "tinyusb/tusb_config.h"
#include "tinyusb/port.h"

extern "C" {

/* Device API */
void dcd_init (uint8_t rhport);
void dcd_int_enable (uint8_t rhport);
void dcd_int_disable (uint8_t rhport);
void dcd_int_handler(uint8_t rhport);
void dcd_set_address (uint8_t rhport, uint8_t dev_addr);
void dcd_remote_wakeup(uint8_t rhport);
void dcd_connect(uint8_t rhport);
void dcd_disconnect(uint8_t rhport);

/* Endpoints API */
bool dcd_edpt_open (uint8_t rhport, tusb_desc_endpoint_t const * desc_edpt);
void dcd_edpt_close (uint8_t rhport, uint8_t ep_addr);
void dcd_edpt_close_all (uint8_t rhport);
bool dcd_edpt_xfer (uint8_t rhport, uint8_t ep_addr, uint8_t * buffer, uint16_t total_bytes);
bool dcd_edpt_xfer_fifo (uint8_t rhport, uint8_t ep_addr, tu_fifo_t * ff, uint16_t total_bytes);
void dcd_edpt_stall (uint8_t rhport, uint8_t ep_addr);
void dcd_edpt_clear_stall (uint8_t rhport, uint8_t ep_addr);

}


using namespace stm32::objects;
using namespace stm32::hal;
using namespace dral::stm32f411;


/* Device API */

void dcd_init (uint8_t rhport)
{
  (void) rhport;

  auto& device = getObject<OtgFsDeviceHal>();
  device.init();

  dcd_connect(rhport);
}


void dcd_int_enable (uint8_t rhport)
{
  (void) rhport;

  auto& device = getObject<OtgFsDeviceHal>();
  device.enableGlobalInterrupts();
}


void dcd_int_disable (uint8_t rhport)
{
  (void) rhport;

  auto& device = getObject<OtgFsDeviceHal>();
  device.disableGlobalInterrupts();
}


void dcd_set_address (uint8_t rhport, uint8_t dev_addr)
{
  (void) rhport;
  TU_LOG(1, "dcd_set_address\n\r");

  auto& device = getObject<OtgFsDeviceHal>();
  device.setAddress(dev_addr);

  dcd_edpt_xfer(rhport, tu_edpt_addr(0, TUSB_DIR_IN), NULL, 0);
}


void dcd_remote_wakeup (uint8_t rhport)
{
  (void) rhport;
  TU_LOG(1, "dcd_remote_wakeup\n\r");

  auto& device = getObject<OtgFsDeviceHal>();
  device.wakeup();
}


void dcd_connect(uint8_t rhport)
{
  (void) rhport;

  auto& device = getObject<OtgFsDeviceHal>();
  device.connect();
}


void dcd_disconnect(uint8_t rhport)
{
  (void) rhport;

  auto& device = getObject<OtgFsDeviceHal>();
  device.disconnect();
}


/* Endpoints API */


TuEndpoint& getEndpoint(uint32_t number, OtgFsEndpointDirection direction)
{
  static std::array<TuEndpoint, MaxEndpoints> in = [] {
    std::array<TuEndpoint, MaxEndpoints> init = {};
    for (unsigned i = 0; i < MaxEndpoints; i++) {
      init[i].number = i;
      init[i].direction = OtgFsEndpointDirection::In;
      init[i].xferBuffer = nullptr;
      init[i].xferFifo = nullptr;
      init[i].pending = false;
    }
    return init;
  }();

  static std::array<TuEndpoint, MaxEndpoints> out = [] {
    std::array<TuEndpoint, MaxEndpoints> init = {};
    for (unsigned i = 0; i < MaxEndpoints; i++) {
      init[i].number = i;
      init[i].direction = OtgFsEndpointDirection::Out;
      init[i].xferBuffer = nullptr;
      init[i].xferFifo = nullptr;
      init[i].pending = false;
    }
    return init;
  }();

  if (direction == OtgFsEndpointDirection::In) {
    return in[number];
  } else {
    return out[number];
  }
}


uint32_t& getEndpoint0PendingXfer(OtgFsEndpointDirection direction)
{
  static std::array<uint32_t, 2> pendingXfer = {0};
  return pendingXfer[static_cast<uint32_t>(direction)];
}


uint32_t TxFifoAllocatedWords = 16;
bool OutEndpointClosed = false;
uint32_t Endpoint0Pending[2];
TU_ATTR_ALIGNED(4) uint32_t SetupPacket[2];


bool dcd_edpt_open (uint8_t rhport, tusb_desc_endpoint_t const * ep_desc)
{
  (void) rhport;

  const auto endpointNumber = tu_edpt_number(ep_desc->bEndpointAddress);
  const auto endpointDirection = static_cast<OtgFsEndpointDirection>(tu_edpt_dir(ep_desc->bEndpointAddress));

  TU_ASSERT(endpointNumber < MaxEndpoints);

  auto& device = getObject<OtgFsDeviceHal>();
  auto& endpoint = getEndpoint(endpointNumber, endpointDirection);

  endpoint.maxPacketSize = ep_desc->wMaxPacketSize.size;
  endpoint.interval = ep_desc->bInterval;
  endpoint.type = static_cast<OtgFsEndpointType>(ep_desc->bmAttributes.xfer);

  const uint32_t fifoSize = (endpoint.maxPacketSize + 3) / 4;

  if (endpoint.direction == OtgFsEndpointDirection::Out) {
    const uint32_t rxFifoSize = device.getRxFifoSize(4 * fifoSize);
    if (otg_fs_global::fs_grxfsiz::rxfd::read() < rxFifoSize) {
      TU_ASSERT((rxFifoSize + TxFifoAllocatedWords) <= (EndpointFifoSize / 4));
      otg_fs_global::fs_grxfsiz::rxfd::write(rxFifoSize);
    }
  } else {
    TU_ASSERT((TxFifoAllocatedWords + fifoSize + otg_fs_global::fs_grxfsiz::rxfd::read()) <= (EndpointFifoSize / 4));

    TxFifoAllocatedWords += fifoSize;
    const uint32_t txFifoStartAddress = (EndpointFifoSize / 4) - TxFifoAllocatedWords;
    if (endpoint.number == 1) {
      otg_fs_global::fs_dieptxf1::ineptxfd::write(fifoSize);
      otg_fs_global::fs_dieptxf1::ineptxsa::write(txFifoStartAddress);
    } else if (endpoint.number == 2) {
      otg_fs_global::fs_dieptxf2::ineptxfd::write(fifoSize);
      otg_fs_global::fs_dieptxf2::ineptxsa::write(txFifoStartAddress);
    } else if (endpoint.number == 3) {
      otg_fs_global::fs_dieptxf3::ineptxfd::write(fifoSize);
      otg_fs_global::fs_dieptxf3::ineptxsa::write(txFifoStartAddress);
    }
  }

  device.activateEndpoint(endpoint);

  return true;
}


void dcd_edpt_close_all (uint8_t rhport)
{
  (void) rhport;

  auto& device = getObject<OtgFsDeviceHal>();

  for (uint32_t i = 1; i < MaxEndpoints; i++) {
    auto& outEndpoint = getEndpoint(i, OtgFsEndpointDirection::Out);
    device.deactivateEndpoint(outEndpoint);

    auto& inEndpoint = getEndpoint(i, OtgFsEndpointDirection::In);
    device.deactivateEndpoint(inEndpoint);
    device.flushTxFifo(i);
  }

  TxFifoAllocatedWords = 16;
}


void dcd_edpt_close (uint8_t rhport, uint8_t ep_addr)
{
  (void) rhport;

  const auto endpointNumber = tu_edpt_number(ep_addr);
  const auto endpointDirection = static_cast<OtgFsEndpointDirection>(tu_edpt_dir(ep_addr));

  auto& endpoint = getEndpoint(endpointNumber, endpointDirection);
  auto& device = getObject<OtgFsDeviceHal>();

  device.deactivateEndpoint(endpoint);

  if (endpoint.direction == OtgFsEndpointDirection::In) {
    device.flushTxFifo(endpoint.number);

    uint32_t fifoSize = 0;
    uint32_t fifoStart = 0;
    if (endpoint.number == 1) {
      fifoStart = otg_fs_global::fs_dieptxf1::ineptxsa::read();
      fifoSize = otg_fs_global::fs_dieptxf1::ineptxfd::read();
    } else if (endpoint.number == 2) {
      fifoStart = otg_fs_global::fs_dieptxf2::ineptxsa::read();
      fifoSize = otg_fs_global::fs_dieptxf2::ineptxfd::read();
    } else if (endpoint.number == 3) {
      fifoStart = otg_fs_global::fs_dieptxf3::ineptxsa::read();
      fifoSize = otg_fs_global::fs_dieptxf3::ineptxfd::read();
    }
    TU_ASSERT(fifoStart == ((EndpointFifoSize / 4) - TxFifoAllocatedWords),);
    TxFifoAllocatedWords -= fifoSize;
  } else {
    OutEndpointClosed = true;
  }
}


bool dcd_edpt_xfer (uint8_t rhport, uint8_t ep_addr, uint8_t * buffer, uint16_t total_bytes)
{
  (void) rhport;

  const auto endpointNumber = tu_edpt_number(ep_addr);
  const auto endpointDirection = static_cast<OtgFsEndpointDirection>(tu_edpt_dir(ep_addr));

  auto& endpoint = getEndpoint(endpointNumber, endpointDirection);

  endpoint.xferBuffer = buffer;
  endpoint.xferFifo = nullptr;
  endpoint.xferLen = total_bytes;

  if (endpoint.number == 0) {
    Endpoint0Pending[static_cast<uint32_t>(endpoint.direction)] = endpoint.xferLen;
    endpoint.xferLen = tu_min32(endpoint.xferLen, endpoint.maxPacketSize);
    Endpoint0Pending[static_cast<uint32_t>(endpoint.direction)] -= endpoint.xferLen;
  }

  auto& device = getObject<OtgFsDeviceHal>();
  device.startXfer(endpoint);

  return true;
}


bool dcd_edpt_xfer_fifo (uint8_t rhport, uint8_t ep_addr, tu_fifo_t * ff, uint16_t total_bytes)
{
  (void) rhport;

  TU_ASSERT(ff->item_size == 1);

  const auto endpointNumber = tu_edpt_number(ep_addr);
  const auto endpointDirection = static_cast<OtgFsEndpointDirection>(tu_edpt_dir(ep_addr));

  auto& endpoint = getEndpoint(endpointNumber, endpointDirection);
  endpoint.xferFifo = ff;
  endpoint.xferBuffer = nullptr;
  endpoint.xferLen = total_bytes;

  auto& device = getObject<OtgFsDeviceHal>();
  device.startXfer(endpoint);

  return true;
}


void dcd_edpt_stall (uint8_t rhport, uint8_t ep_addr)
{
  (void) rhport;

  const auto endpointNumber = tu_edpt_number(ep_addr);
  const auto endpointDirection = static_cast<OtgFsEndpointDirection>(tu_edpt_dir(ep_addr));

  auto& endpoint = getEndpoint(endpointNumber, endpointDirection);
  auto& device = getObject<OtgFsDeviceHal>();

  device.setStall(endpoint);
}


void dcd_edpt_clear_stall (uint8_t rhport, uint8_t ep_addr)
{
  (void) rhport;

  const auto endpointNumber = tu_edpt_number(ep_addr);
  const auto endpointDirection = static_cast<OtgFsEndpointDirection>(tu_edpt_dir(ep_addr));

  auto& endpoint = getEndpoint(endpointNumber, endpointDirection);
  auto& device = getObject<OtgFsDeviceHal>();

  device.clearStall(endpoint);
}



void updateRxFifoSize()
{
  uint32_t maxEndpointSize = 0;
  for (uint32_t epnum = 0; epnum < MaxEndpoints; epnum++) {
    maxEndpointSize = tu_max16(maxEndpointSize, getEndpoint(epnum, OtgFsEndpointDirection::Out).maxPacketSize);
  }

  auto& device = getObject<OtgFsDeviceHal>();
  otg_fs_global::fs_grxfsiz::rxfd::write(device.getRxFifoSize(maxEndpointSize));
}


void handleRxFifoNonEmpty()
{
  uint32_t rxStatus = otg_fs_global::fs_grxstsp_device::read();
  uint32_t packetStatus = otg_fs_global::fs_grxstsp_device::pktsts::getFromRegValue(rxStatus); 
  uint32_t endpointNumber = otg_fs_global::fs_grxstsp_device::epnum::getFromRegValue(rxStatus);
  uint32_t byteCount = otg_fs_global::fs_grxstsp_device::bcnt::getFromRegValue(rxStatus);

  auto& device = getObject<OtgFsDeviceHal>();
  volatile uint32_t* rxFifo = reinterpret_cast<volatile uint32_t*>(device.getFifoAddress(0));

  switch (packetStatus) {
    case 0x1U:
      break;

    case 0x2U: {
      auto& endpoint = getEndpoint(endpointNumber, OtgFsEndpointDirection::Out);

      if (endpoint.xferFifo) {
        tu_fifo_write_n_const_addr_full_words(endpoint.xferFifo, (const void*)rxFifo, byteCount);
      } else {
        device.readFifoPacket(endpoint.xferBuffer, byteCount);
        endpoint.xferBuffer += byteCount;
      }

      if(byteCount < endpoint.maxPacketSize) {
        uint32_t xferLen = (endpoint.number == 0) ? otg_fs_device::doeptsiz0::xfrsiz::read()
                                                  : otg_fs_device::doeptsizx::xfrsiz::read(endpoint.number - 1);
        endpoint.xferLen -= xferLen;

        if (endpoint.number == 0) {
          endpoint.xferLen = 0;
          Endpoint0Pending[static_cast<uint32_t>(endpoint.direction)] = 0;
        }
      }
    } break;

    case 0x3U:
      break;

    case 0x4U:
      if (endpointNumber == 0) {
        otg_fs_device::doeptsiz0::stupcnt::write(3);
      } else {
        otg_fs_device::doeptsizx::rxdpid_stupcnt::write(endpointNumber - 1, 3);
      }
      break;

    case 0x6U:
      device.readFifoPacket(reinterpret_cast<uint8_t*>(SetupPacket), byteCount);
      break;

    default:
      TU_BREAKPOINT();
      break;
  }
}


void handleOutEndpointInterrupt(uint8_t rhport)
{
  for (uint32_t i = 0; i < MaxEndpoints; i++) {

    uint32_t oepint = otg_fs_device::fs_daint::oepint::read();

    if (oepint & (1U << i)) {
      if (otg_fs_device::doepintx::stup::read(i)) {
        otg_fs_device::doepintx::stup::write(i, 1);
        dcd_event_setup_received(rhport, reinterpret_cast<uint8_t*>(SetupPacket), true);
      }

      if (otg_fs_device::doepintx::xfrc::read(i)) {
        otg_fs_device::doepintx::xfrc::write(i, 1);

        auto& endpoint = getEndpoint(i, OtgFsEndpointDirection::Out);

        if((i == 0) && (Endpoint0Pending[static_cast<uint32_t>(endpoint.direction)] > 0)) {
          auto& device = getObject<OtgFsDeviceHal>();
          TuEndpoint copyEndpoint = endpoint;
          copyEndpoint.xferLen = Endpoint0Pending[static_cast<uint32_t>(copyEndpoint.direction)];
          device.startXfer(copyEndpoint);
        } else {
          dcd_event_xfer_complete(rhport, i, endpoint.xferLen, XFER_RESULT_SUCCESS, true);
        }
      }
    }
  }
}


void handleInEndpointInterrupt(uint8_t rhport)
{
  for (uint32_t i = 0; i < MaxEndpoints; i++) {
    auto& device = getObject<OtgFsDeviceHal>();
    auto& endpoint = getEndpoint(i, OtgFsEndpointDirection::In);

    uint32_t iepint = otg_fs_device::fs_daint::iepint::read();

    if (iepint & (1U << i)) {

      if (device.getInEndpointInterruptStatus(endpoint, OtgFsDeviceInEndpointInterrupt::Xfrc)) {
        device.clearInEndpointInterruptStatus(endpoint, OtgFsDeviceInEndpointInterrupt::Xfrc);

        if((i == 0) && (Endpoint0Pending[static_cast<uint32_t>(endpoint.direction)] > 0)) {
          auto& device = getObject<OtgFsDeviceHal>();
          TuEndpoint copyEndpoint = endpoint;
          copyEndpoint.xferLen = Endpoint0Pending[static_cast<uint32_t>(copyEndpoint.direction)];
          device.startXfer(copyEndpoint);
        } else {
          dcd_event_xfer_complete(rhport, i | TUSB_DIR_IN_MASK, endpoint.xferLen, XFER_RESULT_SUCCESS, true);
        }
      }

      if (otg_fs_device::diepintx::txfe::read(i) && (otg_fs_device::diepempmsk::read() & (1U << i))) {
        uint32_t endpointRegNumber = i - 1;

        uint32_t remainingPackets = 0;
        if (endpoint.number == 0) {
          remainingPackets = otg_fs_device::dieptsiz0::pktcnt::read();
        } else {
          remainingPackets = otg_fs_device::dieptsizx::pktcnt::read(endpointRegNumber);
        }

        for (uint32_t packet = 0; packet < remainingPackets; packet++) {
          uint32_t remainingBytes = 0;
          if (endpoint.number == 0) {
            remainingBytes = otg_fs_device::dieptsiz0::xfrsiz::read();
          } else {
            remainingBytes = otg_fs_device::dieptsizx::xfrsiz::read(endpointRegNumber);
          }
          uint32_t packetSize = tu_min32(remainingBytes, endpoint.maxPacketSize);

          if (packetSize > (otg_fs_device::dtxfstsx::ineptfsav::read(i) << 2U)) {
            break;
          }

          if (endpoint.xferFifo) {
            volatile uint32_t* txFifo = reinterpret_cast<uint32_t*>(device.getFifoAddress(i));
            tu_fifo_read_n_const_addr_full_words(endpoint.xferFifo, (void*)txFifo, packetSize);
          } else {
            device.writeFifoPacket(i, endpoint.xferBuffer, packetSize);
            endpoint.xferBuffer += packetSize;
          }
        }

        if ((otg_fs_device::dieptsizx::xfrsiz::read(endpointRegNumber) == 0)
        || ((endpoint.number == 0) && (otg_fs_device::dieptsiz0::xfrsiz::read() == 0))) {
          uint32_t diepempmsk = otg_fs_device::diepempmsk::read();
          otg_fs_device::diepempmsk::write(diepempmsk & ~(1U << i));
        }

      }
    }

  }
}

#if 0

void dcd_int_handler(uint8_t rhport)
{
  auto& usb = getObject<OtgFsCoreHal>();
  auto& device = getObject<OtgFsDeviceHal>();

  uint32_t status = usb.getInterruptStatus();

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Usbrst)) {
    usb.clearInterrupt(OtgFsInterrupt::Usbrst);

    TU_LOG(1, "IrqUsbrst\n\r");

    OutEndpointClosed = false;
    TxFifoAllocatedWords = 16;
    getEndpoint(0, OtgFsEndpointDirection::In).maxPacketSize = 64;
    getEndpoint(0, OtgFsEndpointDirection::Out).maxPacketSize = 64;

    device.busReset();

    // TODO check if needed
    otg_fs_device::fs_dcfg::dad::write(0);
    otg_fs_global::fs_gintmsk::oepint::write(1);
    otg_fs_global::fs_gintmsk::iepint::write(1);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Enumdne)) {
    usb.clearInterrupt(OtgFsInterrupt::Enumdne);

    TU_LOG(1, "IrqEnumdne\n\r");

    auto speed = device.getSpeed();
    tusb_speed_t tusbSpeed;

    if (speed == OtgFsSpeed::FullSpeed) {
      tusbSpeed = tusb_speed_t::TUSB_SPEED_FULL;
      otg_fs_device::fs_diepctl0::mpsiz::write(0);
    } else {
      tusbSpeed = tusb_speed_t::TUSB_SPEED_INVALID;
    }

    dcd_event_bus_reset(rhport, tusbSpeed, true);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Usbsusp)) {
    usb.clearInterrupt(OtgFsInterrupt::Usbsusp);

    TU_LOG(1, "IrqUsbsusp\n\r");

    dcd_event_bus_signal(rhport, DCD_EVENT_SUSPEND, true);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Wkupint)) {

    TU_LOG(1, "IrqWkupint\n\r");

    usb.clearInterrupt(OtgFsInterrupt::Wkupint);
    dcd_event_bus_signal(rhport, DCD_EVENT_RESUME, true);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Otgint)) {

    TU_LOG(1, "IrqOtgint\n\r");

    uint32_t sedet = otg_fs_global::fs_gotgint::sedet::read();

    if (sedet == 1) {
      dcd_event_bus_signal(rhport, DCD_EVENT_UNPLUGGED, true);
    }

    uint32_t otgInt = otg_fs_global::fs_gotgint::read();
    otg_fs_global::fs_gotgint::write(otgInt);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Sof)) {

    TU_LOG(1, "IrqSof\n\r");

    usb.clearInterrupt(OtgFsInterrupt::Sof);
    usb.setInterruptMask(OtgFsInterrupt::Sof, OtgFsInterruptMask::Masked);
    dcd_event_bus_signal(rhport, DCD_EVENT_SOF, true);

//    TU_LOG(1, "IrqSofEnd\n\r");
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Rxflvl)) {

    usb.setInterruptMask(OtgFsInterrupt::Rxflvl, OtgFsInterruptMask::Masked);

//    TU_LOG(1, "IrqRxflvl\n\r");

    do {
      handleRxFifoNonEmpty();

//      TU_LOG(1, "RxflvlSts %lu\n\r", otg_fs_global::fs_gintsts::rxflvl::read());
    } while(otg_fs_global::fs_gintsts::rxflvl::read() != 0);
    if (OutEndpointClosed) {
      updateRxFifoSize();
      OutEndpointClosed = false;
    }
    usb.setInterruptMask(OtgFsInterrupt::Rxflvl, OtgFsInterruptMask::UnMasked);

//    TU_LOG(1, "IrqRxflvlEnd\n\r");
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Oepint)) {

    TU_LOG(1, "IrqOepint\n\r");

    handleOutEndpointInterrupt(rhport);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Iepint)) {

    TU_LOG(1, "IrqIepint\n\r");

    handleInEndpointInterrupt(rhport);
  }
}

#endif
