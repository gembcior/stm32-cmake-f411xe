#include <cstdint>
#include "port.h"
#include "objects/objects.h"
#include "otg_fs/OtgFsDeviceHal.h"
#include <array>


using namespace stm32::objects;
using namespace stm32::hal;

/*------------------------------------------------------------------*/
/* Device API
 *------------------------------------------------------------------*/

void dcd_init (uint8_t rhport)
{
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
  auto& device = getObject<OtgFsDeviceHal>();
  device.setAddress(dev_addr);
  dcd_edpt_xfer(rhport, tu_edpt_addr(0, TUSB_DIR_IN), NULL, 0);
}


void dcd_remote_wakeup (uint8_t rhport)
{
  (void) rhport;
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

//--------------------------------------------------------------------+
// Endpoint API
//--------------------------------------------------------------------+

OtgFsEndpoint& getEndpoint(uint32_t number, OtgFsEndpointDirection direction)
{
  constexpr uint32_t MaxEndpoint = 4;

  static std::array<OtgFsEndpoint, MaxEndpoint> in = [] {
    std::array<OtgFsEndpoint, MaxEndpoint> init = {};
    for (unsigned i = 0; i < MaxEndpoint; i++) {
      init[i].number = i;
      init[i].direction = OtgFsEndpointDirection::In;
    }
    return init;
  }();

  static std::array<OtgFsEndpoint, MaxEndpoint> out = [] {
    std::array<OtgFsEndpoint, MaxEndpoint> init = {};
    for (unsigned i = 0; i < MaxEndpoint; i++) {
      init[i].number = i;
      init[i].direction = OtgFsEndpointDirection::Out;
    }
    return init;
  }();

  if (direction == OtgFsEndpointDirection::In) {
    return in[number];
  } else {
    return out[number];
  }
}


bool dcd_edpt_open (uint8_t rhport, tusb_desc_endpoint_t const * ep_desc)
{
  (void) rhport;

  const auto endpointNumber = tu_edpt_number(ep_desc->bEndpointAddress);
  const auto endpointDirection = static_cast<OtgFsEndpointDirection>(tu_edpt_dir(ep_desc->bEndpointAddress));

  auto& endpoint = getEndpoint(endpointNumber, endpointDirection);

  endpoint.maxPacketSize = ep_desc->wMaxPacketSize.size;
  endpoint.interval = ep_desc->bInterval;

  auto& device = getObject<OtgFsDeviceHal>();

  device.activateEndpoint(endpoint);

  // TODO add FIFO support

  return true;
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
  }
  // TODO add FIFO support
}


bool dcd_edpt_xfer (uint8_t rhport, uint8_t ep_addr, uint8_t * buffer, uint16_t total_bytes)
{
  (void) rhport;
  (void) buffer;

  const auto endpointNumber = tu_edpt_number(ep_addr);
  const auto endpointDirection = static_cast<OtgFsEndpointDirection>(tu_edpt_dir(ep_addr));

  auto& endpoint = getEndpoint(endpointNumber, endpointDirection);
  auto& device = getObject<OtgFsDeviceHal>();

  endpoint.xferLen = total_bytes;
  // TODO do something with buffer

  device.startXfer(endpoint);

  return true;
}


bool dcd_edpt_xfer_fifo (uint8_t rhport, uint8_t ep_addr, tu_fifo_t * ff, uint16_t total_bytes)
{
  (void) rhport;
  (void) ep_addr;
  (void) ff;

  const auto endpointNumber = tu_edpt_number(ep_addr);
  const auto endpointDirection = static_cast<OtgFsEndpointDirection>(tu_edpt_dir(ep_addr));

  auto& endpoint = getEndpoint(endpointNumber, endpointDirection);
  auto& device = getObject<OtgFsDeviceHal>();

  endpoint.xferLen = total_bytes;
  // TODO do something with ff

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

  // TODO set NAK ???
  device.setStall(endpoint);
  device.deactivateEndpoint(endpoint);
  if (endpoint.direction == OtgFsEndpointDirection::In) {
    device.flushTxFifo(endpoint.number);
  }
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


void dcd_int_handler(uint8_t rhport)
{
  (void) rhport;
}
