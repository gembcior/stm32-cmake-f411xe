#include "nvic/NvicHal.h"
#include "dral/nvic.h"


namespace stm32::hal {

using namespace dral::stm32f411;

void NvicHal::enableIrq(uint32_t irq)
{
  constexpr uint32_t irqNumInIser = 32;
  nvic::iserx::write(irq / irqNumInIser, 1 << (irq % irqNumInIser));
}


void NvicHal::disableIrq(uint32_t irq)
{
  constexpr uint32_t irqNumInIcer = 32;
  nvic::icerx::write(irq / irqNumInIcer, 1 << (irq % irqNumInIcer));
}


void NvicHal::setPendingIrq(uint32_t irq)
{
  constexpr uint32_t irqNumInIspr = 32;
  nvic::isprx::write(irq / irqNumInIspr, 1 << (irq % irqNumInIspr));
}


void NvicHal::clearPendingIrq(uint32_t irq)
{
  constexpr uint32_t irqNumInIcpr = 32;
  nvic::icprx::write(irq / irqNumInIcpr, 1 << (irq % irqNumInIcpr));
}


bool NvicHal::isIrqActive(uint32_t irq)
{
  constexpr uint32_t irqNumInIabr = 32;
  uint32_t value = nvic::iabrx::read(irq / irqNumInIabr) >> (irq % irqNumInIabr);
  return (value & 0x1);
}


void NvicHal::setIrqPriority(uint32_t irq, uint32_t priority)
{
  constexpr uint32_t irqNumInIpr = 4;
  uint32_t value = priority & nvic::ipr0::ipr_n0::Mask;
  value = value << ((irq % irqNumInIpr) * 8);
  nvic::iprx::write(irq / irqNumInIpr, value);
}




} // namespace
