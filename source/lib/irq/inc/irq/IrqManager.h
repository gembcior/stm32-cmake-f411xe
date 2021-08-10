#ifndef IRQ_MANAGER_H
#define IRQ_MANAGER_H

#include <cstdint>
#include "irq/IrqHandler.h"
#include "irq/Irq.h"

namespace stm32::irq {

template<uint32_t MaxIrqNumber>
class IrqManager
{
public:
  static IrqHandler* IrqHandlerList[MaxIrqNumber];

public:
  IrqManager(uint32_t* irqVectorTable);

  void registerIrqHandler(Irq irq);
  uint32_t getIrqVectorTableAddress();

private:
  uint32_t* m_irqVectorTable;
};


template<uint32_t MaxIrqNumber>
IrqHandler* IrqManager<MaxIrqNumber>::IrqHandlerList[] = {};


template<uint32_t MaxIrqNumber>
IrqManager<MaxIrqNumber>::IrqManager(uint32_t* irqVectorTable) :
  m_irqVectorTable(irqVectorTable)
{
}


template<uint32_t MaxIrqNumber>
void IrqManager<MaxIrqNumber>::registerIrqHandler(Irq irq)
{
  IrqHandlerList[irq.position] = irq.handler;
  m_irqVectorTable[irq.position] = reinterpret_cast<uint32_t>(irq.adapter);
}


template<uint32_t MaxIrqNumber>
uint32_t IrqManager<MaxIrqNumber>::getIrqVectorTableAddress()
{
  return reinterpret_cast<uint32_t>(m_irqVectorTable);
}

} // namespace

#endif /* IRQ_MANAGER_H */
