#include "ticktack/TickTack.h"


namespace stm32::ticktack {

TickTack::TickTack()
  : m_counter(0)
  , m_period(0)
  , m_tick(false)
{
}


void TickTack::tick()
{
  m_counter++;

  if (m_counter > m_period) {
    m_counter = 0;
    m_tick = !m_tick;
  }
}


void TickTack::setPeriod(uint32_t ticks)
{
  m_period = ticks;
}


bool TickTack::getTick()
{
  return m_tick;
}

} // namespace
