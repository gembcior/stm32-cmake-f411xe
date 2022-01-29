#ifndef IRQ_MANAGER_H
#define IRQ_MANAGER_H

#include <cstdint>
#include "irq/IrqHandler.h"
#include "irq/Irq.h"
#include "nvic/NvicHal.h"

namespace stm32::irq {

template<uint32_t IrqNumber>
class IrqManager
{
public:
  static IrqHandler* IrqHandlerList[IrqNumber];

public:
  IrqManager(hal::NvicHal& nvicHal) : m_nvicHal(nvicHal)
  {}

  void registerIrqHandler(const Irq& irq);
  void enableIrq(const Irq& irq);
  void setIrqPriority(const Irq& irq);

private:
  hal::NvicHal& m_nvicHal;
};


template<uint32_t IrqNumber>
IrqHandler* IrqManager<IrqNumber>::IrqHandlerList[] = {};


template<uint32_t IrqNumber>
void IrqManager<IrqNumber>::registerIrqHandler(const Irq& irq)
{
  IrqHandlerList[irq.handlerPosition] = irq.handler;
}


template<uint32_t IrqNumber>
void IrqManager<IrqNumber>::enableIrq(const Irq& irq)
{
  m_nvicHal.enableIrq(irq.number);
}


template<uint32_t IrqNumber>
void IrqManager<IrqNumber>::setIrqPriority(const Irq& irq)
{
  m_nvicHal.setIrqPriority(irq.number, irq.priority);
}

} // namespace

#endif /* IRQ_MANAGER_H */
