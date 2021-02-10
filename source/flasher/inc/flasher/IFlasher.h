#ifndef IFLASHER_H
#define IFLASHER_H

#include "gpio/gpio.h"

namespace stm32::flasher {

class IFlasher
{
public:
  virtual void setPin(hal::gpio::Port port, hal::gpio::Pin pin) = 0;
  virtual void blink() = 0;
};

} // namespace

#endif /* IFLASHER_H */
