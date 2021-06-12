#ifndef IGPIO_DRIVER_H
#define IGPIO_DRIVER_H

#include <cstdint>
#include "gpio/types.h"

namespace stm32::hal {

class IGpioDriver
{
public:
  virtual void configure(Port port, Pin pin, PortConfig config) = 0;
  virtual void configure(GpioPin pin) = 0;
  virtual void setPort(Port port, uint32_t value) = 0;
  virtual uint32_t getPort(Port port) = 0;
  virtual void setPin(Port port, Pin pin, PinState state) = 0;
  virtual void setPin(GpioPin pin, PinState state) = 0;
  virtual PinState getPin(Port port, Pin pin) = 0;
  virtual PinState getPin(GpioPin pin) = 0;
};

} // namespace

#endif /* IGPIO_DRIVER_H */
