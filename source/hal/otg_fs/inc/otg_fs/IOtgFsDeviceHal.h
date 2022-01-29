#ifndef IOTG_FS_DEVICE_HAL_H
#define IOTG_FS_DEVICE_HAL_H

#include <cstdint>

namespace stm32::hal {

class IOtgFsDeviceHal
{
public:
  virtual void init() = 0;
  virtual void connect() = 0;
  virtual void disconnect() = 0;
  virtual void setAddress(uint8_t address) = 0;

};

} // namespace

#endif /* IOTG_FS_DEVICE_HAL_H */
