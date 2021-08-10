#ifndef IFLASHER_H
#define IFLASHER_H

#include "gpio/types.h"

namespace stm32::lib {

class IFlasher
{
public:
  virtual void setPin(hal::Port port, hal::Pin pin) = 0;
  virtual void setPeriod(uint32_t period) = 0;
  virtual void blink() = 0;
};

} // namespace

#endif /* IFLASHER_H */
