#ifndef IRQ_MANAGER_H
#define IRQ_MANAGER_H

#include <cstdint>
#include "irq/IrqHandler.h"
#include "irq/Irq.h"

namespace stm32::irq {

template<uint32_t IrqNumber>
class IrqManager
{
public:
  static IrqHandler* IrqHandlerList[IrqNumber];

public:
  void registerIrqHandler(Irq irq);
};


template<uint32_t IrqNumber>
IrqHandler* IrqManager<IrqNumber>::IrqHandlerList[] = {};


template<uint32_t IrqNumber>
void IrqManager<IrqNumber>::registerIrqHandler(Irq irq)
{
  IrqHandlerList[irq.position] = irq.handler;
}

} // namespace

#endif /* IRQ_MANAGER_H */
