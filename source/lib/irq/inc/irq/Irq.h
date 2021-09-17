#ifndef IRQ_H
#define IRQ_H

#include <cstdint>
#include "irq/IrqHandler.h"


namespace stm32::irq {

struct Irq
{
  uint32_t position;
  IrqHandler* handler;
};

} // namespace

#endif /* IRQ_H */
