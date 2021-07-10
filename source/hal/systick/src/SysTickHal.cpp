#include "systick/SysTickHal.h"
#include "dral/stk.h"


namespace stm32::hal {

using namespace dral::stm32f411;


void SysTickHal::setClockSource(SysTickClockSource source)
{
  stk::ctrl::clksource::write(static_cast<uint32_t>(source));
}


void SysTickHal::enable()
{
  stk::ctrl::enable::write(1);
}


void SysTickHal::disable()
{
  stk::ctrl::enable::write(0);
}

void SysTickHal::enableInterrupts()
{
  stk::ctrl::tickint::write(1);
}


void SysTickHal::disableInterrupts()
{
  stk::ctrl::tickint::write(0);
}


void SysTickHal::setReloadValue(uint32_t value)
{
  stk::load::reload::write(value);
}


uint32_t SysTickHal::getReloadValue()
{
  return stk::load::reload::read();
}


uint32_t SysTickHal::getCurrentValue()
{
  return stk::val::current::read();
}


void SysTickHal::clear()
{
  stk::val::current::write(0);
}


bool SysTickHal::wasCountedToZero()
{
  return stk::ctrl::countflag::read();
}

} // namespace
