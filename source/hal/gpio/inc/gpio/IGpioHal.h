#ifndef IGPIO_HAL_H
#define IGPIO_HAL_H

#include <cstdint>
#include "gpio/gpio.h"

namespace stm32::hal::gpio {

class IGpioHal
{
public:
  virtual void setMode(Pin pin, PortMode mode) = 0;
  virtual void setType(Pin pin, PortType type) = 0;
  virtual void setSpeed(Pin pin, PortSpeed speed) = 0;
  virtual void setPull(Pin pin, PortPull pull) = 0;
  virtual void setAlternateFunction(Pin pin, PortAlternateFunction af) = 0;

  virtual void setPort(uint32_t value) = 0;
  virtual uint32_t getPort() = 0;

  virtual void setPin(Pin pin, PinState state) = 0;
  virtual PinState getPin(Pin pin) = 0;
};

} // namespace

#endif /* IGPIO_HAL_H */
