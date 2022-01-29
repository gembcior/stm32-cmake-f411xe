#ifndef OTG_FS_DEVICE_HAL_H
#define OTG_FS_DEVICE_HAL_H

#include <cstdint>
#include "otg_fs/IOtgFsDeviceHal.h"
#include "otg_fs/OtgFsCoreHal.h"
#include "otg_fs/types.h"


namespace stm32::hal {

class OtgFsDeviceHal : public OtgFsCoreHal, IOtgFsDeviceHal
{
public:
  void init() final;
  void connect() final;
  void disconnect() final;
  void setAddress(uint8_t address) final;
  void setPeriodicFrameInterval(OtgFsPeriodicFrameInterval interval);
  void setSpeed(OtgFsSpeed speed);
  void setInEndPointInterruptMask(OtgFsDeviceInEndpointInterruptMask interrupt, bool mask);
  void setOutEndPointInterruptMask(OtgFsDeviceOutEndpointInterruptMask interrupt, bool mask);
  void setAllInEndPointInterruptMask(uint32_t interrupt, bool mask);
  void setAllOutEndPointInterruptMask(uint32_t interrupt, bool mask);

  void activateEndpoint(OtgFsEndpoint& ep);
  void deactivateEndpoint(OtgFsEndpoint& ep);

  void startXfer(OtgFsEndpoint& ep);
  void setStall(OtgFsEndpoint& ep);
  void clearStall(OtgFsEndpoint& ep);

};

} // namespace

#endif /* OTG_FS_DEVICE_HAL_H */
