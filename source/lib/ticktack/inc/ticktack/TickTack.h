#ifndef TICK_TACK_H
#define TICK_TACK_H

#include "ticktack/ITickTack.h"

namespace stm32::lib {

class TickTack : public ITickTack
{
public:
  TickTack();

  void tick();
  void setPeriod(uint32_t ticks);
  bool getTick();

private:
   uint32_t m_counter;
   uint32_t m_period;
   bool m_tick;
};

} // namespace

#endif /* TICK_TACK_H */
