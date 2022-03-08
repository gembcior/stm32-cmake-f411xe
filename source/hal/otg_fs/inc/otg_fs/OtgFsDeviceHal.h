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
  void setPeriodicFrameInterval(OtgFsPeriodicFrameInterval interval);
  void setSpeed(OtgFsSpeed speed);
  void setInEndpointInterruptMask(OtgFsDeviceInEndpointInterrupt interrupt, OtgFsInterruptMask mask);
  void setOutEndpointInterruptMask(OtgFsDeviceOutEndpointInterrupt interrupt, OtgFsInterruptMask mask);
  void setAllInEndpointInterruptMask(uint32_t interrupt, OtgFsInterruptMask mask);
  void setAllInEndpointInterruptMask(OtgFsInterruptMask mask);
  void setAllOutEndpointInterruptMask(uint32_t interrupt, OtgFsInterruptMask mask);
  void setAllOutEndpointInterruptMask(OtgFsInterruptMask mask);
  void setNonZeroLenStatusOutHandshake(OtgFSNonZeroLenStatusOutHandshake handshake);
  OtgFsSpeed getSpeed();

  void startXfer(OtgFsEndpoint& ep);
  void activateEndpoint(OtgFsEndpoint& ep);
  void deactivateEndpoint(OtgFsEndpoint& ep);
  void setStall(OtgFsEndpoint& ep);
  void clearStall(OtgFsEndpoint& ep);


private:
  void startEndpoint0Xfer(OtgFsEndpoint& ep);
  void startEndpointXXfer(OtgFsEndpoint& ep);

  void activateEndpoint0(OtgFsEndpoint& ep);
  void activateEndpointX(OtgFsEndpoint& ep);

  void deactivateEndpoint0(OtgFsEndpoint& ep);
  void deactivateEndpointX(OtgFsEndpoint& ep);
};

} // namespace

#endif /* OTG_FS_DEVICE_HAL_H */
