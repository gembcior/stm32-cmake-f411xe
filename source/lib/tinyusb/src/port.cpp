#include <cstdint>
#include <array>

#include "tusb_option.h"
#include "device/dcd.h"
#include "tinyusb/tusb_config.h"

#include "objects/objects.h"
#include "otg_fs/OtgFsDeviceHal.h"


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

  auto& device = getObject<OtgFsDeviceHal>();
  device.setAddress(dev_addr);

  dcd_edpt_xfer(rhport, tu_edpt_addr(0, TUSB_DIR_IN), NULL, 0);
}


void dcd_remote_wakeup (uint8_t rhport)
{
  (void) rhport;

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

struct TuEndpoint : public stm32::hal::OtgFsEndpoint {
  uint8_t* xferBuffer;
  tu_fifo_t* xferFifo;
};


TuEndpoint& getEndpoint(uint32_t number, OtgFsEndpointDirection direction)
{
  static std::array<TuEndpoint, MaxEndpoints> in = [] {
    std::array<TuEndpoint, MaxEndpoints> init = {};
    for (unsigned i = 0; i < MaxEndpoints; i++) {
      init[i].number = i;
      init[i].direction = OtgFsEndpointDirection::In;
      init[i].xferBuffer = nullptr;
      init[i].xferFifo = nullptr;
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
    }
    return init;
  }();

  if (direction == OtgFsEndpointDirection::In) {
    return in[number];
  } else {
    return out[number];
  }
}


static uint32_t TxFifoAllocatedWords = 16;
static bool OutEndpointClosed = false;
static uint32_t Endpoint0Pending[2];
static TU_ATTR_ALIGNED(4) uint32_t SetupPacket[2];


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
    const uint32_t rxFifoSize = device.calculateRxFifoSize(4 * fifoSize);
    if (device.getRxFifoSize() < rxFifoSize) {
      TU_ASSERT((rxFifoSize + TxFifoAllocatedWords) <= (EndpointFifoSize / 4));
      device.setRxFifoSize(rxFifoSize);
    }
  } else {
    TU_ASSERT((TxFifoAllocatedWords + fifoSize + device.getRxFifoSize()) <= (EndpointFifoSize / 4));

    TxFifoAllocatedWords += fifoSize;
    const uint32_t txFifoStartAddress = (EndpointFifoSize / 4) - TxFifoAllocatedWords;
    device.setTxFifoSize(endpoint.number, fifoSize);
    device.setTxFifoStartAddress(endpoint.number, txFifoStartAddress);
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

    uint32_t fifoSize = device.getTxFifoSize(endpoint.number);
    uint32_t fifoStart = device.getTxFifoStartAddress(endpoint.number);

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
  uint32_t newRxFifoSize = device.calculateRxFifoSize(maxEndpointSize);
  device.setRxFifoSize(newRxFifoSize);
}


void handleRxFifoNonEmpty()
{
  auto& device = getObject<OtgFsDeviceHal>();

  OtgFsRxStatus rxStatus;
  device.getRxStatus(rxStatus);

  volatile uint32_t* rxFifo = reinterpret_cast<volatile uint32_t*>(device.getFifoAddress(0));

  switch (rxStatus.packetStatus) {
    case 0x1U:
      break;

    case 0x2U: {
      auto& endpoint = getEndpoint(rxStatus.endpointNumber, OtgFsEndpointDirection::Out);

      if (endpoint.xferFifo) {
        tu_fifo_write_n_const_addr_full_words(endpoint.xferFifo, (const void*)rxFifo, rxStatus.byteCount);
      } else {
        device.readFifoPacket(endpoint.xferBuffer, rxStatus.byteCount);
        endpoint.xferBuffer += rxStatus.byteCount;
      }

      if(rxStatus.byteCount < endpoint.maxPacketSize) {
        uint32_t xferLen = device.getEndpointXferSize(endpoint);
        endpoint.xferLen -= xferLen;

        if (endpoint.number == 0) {
          endpoint.xferLen = 0;
          Endpoint0Pending[static_cast<uint32_t>(endpoint.direction)] = 0;
        }
      }
    } break;

    case 0x3U:
      break;

    case 0x4U: {
      auto& endpoint = getEndpoint(rxStatus.endpointNumber, OtgFsEndpointDirection::Out);
      device.setOutEndpointSetupPacketCount(endpoint, 3);
    } break;

    case 0x6U:
      device.readFifoPacket(reinterpret_cast<uint8_t*>(SetupPacket), rxStatus.byteCount);
      break;

    default:
      TU_BREAKPOINT();
      break;
  }
}


void handleOutEndpointInterrupt(uint8_t rhport)
{
  auto& device = getObject<OtgFsDeviceHal>();
  (void)device;

  for (uint32_t i = 0; i < MaxEndpoints; i++) {
    auto& endpoint = getEndpoint(i, OtgFsEndpointDirection::Out);

    if (device.getEndpointInterruptStatus(endpoint)) {
      if (device.getOutEndpointInterruptStatus(endpoint, OtgFsDeviceOutEndpointInterrupt::Stup)) {
        device.clearOutEndpointInterruptStatus(endpoint, OtgFsDeviceOutEndpointInterrupt::Stup);

        dcd_event_setup_received(rhport, reinterpret_cast<uint8_t*>(SetupPacket), true);
      }

      if (device.getOutEndpointInterruptStatus(endpoint, OtgFsDeviceOutEndpointInterrupt::Xfrc)) {
        device.clearOutEndpointInterruptStatus(endpoint, OtgFsDeviceOutEndpointInterrupt::Xfrc);

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
  auto& device = getObject<OtgFsDeviceHal>();

  for (uint32_t i = 0; i < MaxEndpoints; i++) {
    auto& endpoint = getEndpoint(i, OtgFsEndpointDirection::In);

    if (device.getEndpointInterruptStatus(endpoint)) {

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

      if (device.getInEndpointInterruptStatus(endpoint, OtgFsDeviceInEndpointInterrupt::Txfe)
      && (device.getInEndpointFifoEmptyInterruptMask(endpoint.number) == OtgFsInterruptMask::UnMasked)) {

        uint32_t remainingPackets = device.getEndpointPacketCount(endpoint);

        for (uint32_t packet = 0; packet < remainingPackets; packet++) {
          uint32_t remainingBytes = device.getEndpointXferSize(endpoint);
          uint32_t packetSize = tu_min32(remainingBytes, endpoint.maxPacketSize);

          if (packetSize > (device.getInEndpointFifoAvailableSpace(endpoint) << 2U)) {
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

        if (device.getEndpointXferSize(endpoint) == 0) {
          device.setInEndpointFifoEmptyInterruptMask(endpoint.number, OtgFsInterruptMask::Masked);
        }
      }
    }

  }
}


void dcd_int_handler(uint8_t rhport)
{
  auto& usb = getObject<OtgFsCoreHal>();
  auto& device = getObject<OtgFsDeviceHal>();

  uint32_t status = usb.getInterruptStatus();

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Usbrst)) {
    usb.clearInterrupt(OtgFsInterrupt::Usbrst);

    OutEndpointClosed = false;
    TxFifoAllocatedWords = 16;
    getEndpoint(0, OtgFsEndpointDirection::In).maxPacketSize = 64;
    getEndpoint(0, OtgFsEndpointDirection::Out).maxPacketSize = 64;

    device.busReset();
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Enumdne)) {
    usb.clearInterrupt(OtgFsInterrupt::Enumdne);

    auto speed = device.getSpeed();
    tusb_speed_t tusbSpeed;

    if (speed == OtgFsSpeed::FullSpeed) {
      tusbSpeed = tusb_speed_t::TUSB_SPEED_FULL;
    } else {
      tusbSpeed = tusb_speed_t::TUSB_SPEED_INVALID;
    }

    dcd_event_bus_reset(rhport, tusbSpeed, true);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Usbsusp)) {
    usb.clearInterrupt(OtgFsInterrupt::Usbsusp);

    dcd_event_bus_signal(rhport, DCD_EVENT_SUSPEND, true);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Wkupint)) {
    usb.clearInterrupt(OtgFsInterrupt::Wkupint);

    dcd_event_bus_signal(rhport, DCD_EVENT_RESUME, true);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Otgint)) {
    if (device.getOtgInterruptStatus(OtgFsOtgInterrupt::Sedet)) {
      dcd_event_bus_signal(rhport, DCD_EVENT_UNPLUGGED, true);
    }

    device.clearOtgInterruptStatus();
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Sof)) {
    usb.clearInterrupt(OtgFsInterrupt::Sof);
    usb.setInterruptMask(OtgFsInterrupt::Sof, OtgFsInterruptMask::Masked);

    dcd_event_bus_signal(rhport, DCD_EVENT_SOF, true);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Rxflvl)) {

    usb.setInterruptMask(OtgFsInterrupt::Rxflvl, OtgFsInterruptMask::Masked);

    do {
      handleRxFifoNonEmpty();
    } while(device.getInterruptStatus(OtgFsInterrupt::Rxflvl));

    if (OutEndpointClosed) {
      updateRxFifoSize();
      OutEndpointClosed = false;
    }

    usb.setInterruptMask(OtgFsInterrupt::Rxflvl, OtgFsInterruptMask::UnMasked);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Oepint)) {
    handleOutEndpointInterrupt(rhport);
  }

  if (usb.getInterruptStatus(status, OtgFsInterrupt::Iepint)) {
    handleInEndpointInterrupt(rhport);
  }
}
