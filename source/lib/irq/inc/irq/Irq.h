#ifndef IRQ_H
#define IRQ_H

#include <cstdint>
#include "irq/IrqHandler.h"


namespace stm32::irq {

struct Irq
{
  uint32_t number;
  IrqHandler* handler;
  uint32_t handlerPosition;
  uint32_t priority;
};

} // namespace

#endif /* IRQ_H */
