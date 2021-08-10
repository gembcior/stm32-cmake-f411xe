#ifndef IRQ_ADAPTER_H
#define IRQ_ADAPTER_H

#include <cstdint>
#include "irq/IrqManager.h"

namespace stm32::irq {

template<uint32_t MaxIrqNumber, uint32_t Position>
void irqHandlerAdapter() __attribute__ ((interrupt ("IRQ")));


template<uint32_t MaxIrqNumber, uint32_t Position>
void irqHandlerAdapter()
{
  if (IrqManager<MaxIrqNumber>::IrqHandlerList[Position]) {
    IrqManager<MaxIrqNumber>::IrqHandlerList[Position]->onInterrupt();
  }
}

} // namespace

#endif /* IRQ_ADAPTER_H */
