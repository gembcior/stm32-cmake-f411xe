#ifndef OTG_FS_DEVICE_HAL_H
#define OTG_FS_DEVICE_HAL_H

#include <cstdint>
#include "otg_fs/OtgFsCoreHal.h"
#include "otg_fs/types.h"


namespace stm32::hal {

class OtgFsDeviceHal : public OtgFsCoreHal
{
public:
  void init();
  void connect();
  void disconnect();
  void wakeup();
  void busReset();
  void setAddress(uint8_t address);
  void setSpeed(OtgFsSpeed speed);

  void setInEndpointInterruptMask(OtgFsDeviceInEndpointInterrupt interrupt, OtgFsInterruptMask mask);
  void setOutEndpointInterruptMask(OtgFsDeviceOutEndpointInterrupt interrupt, OtgFsInterruptMask mask);

  void setEndpointInterruptMask(OtgFsEndpoint& ep, OtgFsInterruptMask mask);
  bool getEndpointInterruptStatus(OtgFsEndpoint& ep);

  void setNonZeroLenStatusOutHandshake(OtgFSNonZeroLenStatusOutHandshake handshake);
  OtgFsSpeed getSpeed();

  void startXfer(OtgFsEndpoint& ep);
  void activateEndpoint(OtgFsEndpoint& ep);
  void deactivateEndpoint(OtgFsEndpoint& ep);
  void setStall(OtgFsEndpoint& ep);
  void clearStall(OtgFsEndpoint& ep);

  bool getInEndpointInterruptStatus(OtgFsEndpoint& ep, OtgFsDeviceInEndpointInterrupt interrupt);
  void clearInEndpointInterruptStatus(OtgFsEndpoint& ep, OtgFsDeviceInEndpointInterrupt interrupt);
  bool getOutEndpointInterruptStatus(OtgFsEndpoint& ep, OtgFsDeviceOutEndpointInterrupt interrupt);
  void clearOutEndpointInterruptStatus(OtgFsEndpoint& ep, OtgFsDeviceOutEndpointInterrupt interrupt);

  uint32_t getEndpointXferSize(OtgFsEndpoint& ep);
  void setOutEndpointSetupPacketCount(OtgFsEndpoint& ep, uint32_t count);
  uint32_t getEndpointPacketCount(OtgFsEndpoint& ep);

  OtgFsInterruptMask getInEndpointFifoEmptyInterruptMask(uint32_t endpointNumber);
  void setInEndpointFifoEmptyInterruptMask(uint32_t endpointNumber, OtgFsInterruptMask mask);

  uint32_t getInEndpointFifoAvailableSpace(OtgFsEndpoint& ep);

private:
  void startEndpoint0Xfer(OtgFsEndpoint& ep);
  void startEndpointXXfer(OtgFsEndpoint& ep);

  void activateEndpoint0(OtgFsEndpoint& ep);
  void activateEndpointX(OtgFsEndpoint& ep);

  void deactivateEndpoint0(OtgFsEndpoint& ep);
  void deactivateEndpointX(OtgFsEndpoint& ep);

  void setAllInEndpointInterruptMask(uint32_t interrupt, OtgFsInterruptMask mask);
  void setAllOutEndpointInterruptMask(uint32_t interrupt, OtgFsInterruptMask mask);
};

} // namespace

#endif /* OTG_FS_DEVICE_HAL_H */
