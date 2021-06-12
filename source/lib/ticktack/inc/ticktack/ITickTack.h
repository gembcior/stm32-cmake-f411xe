#ifndef ITICK_TACK_H
#define ITICK_TACK_H

#include <cstdint>

namespace stm32::ticktack {

class ITickTack
{
public:
  virtual void tick() = 0;
  virtual void setPeriod(uint32_t ticks) = 0;
  virtual bool getTick() = 0;
};

} // namespace

#endif /* ITICK_TACK_H */
