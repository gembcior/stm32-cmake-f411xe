#include "SysTickIrqHandler.h"
#include "objects.h"
#include "ticktack/TickTack.h"


namespace stm32::irq {

void SysTickIrqHandler::onInterrupt()
{
  objects::getObject<lib::TickTack>().tick();
}

} // namespace
