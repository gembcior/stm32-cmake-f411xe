#ifndef IRQ_H
#define IRQ_H

#include <cstdint>
#include "irq/IrqHandler.h"


namespace stm32::irq {

struct Irq
{
  using AdapterFunction = void(*)();

  uint32_t position;
  AdapterFunction adapter;
  IrqHandler* handler;
};

} // namespace

#endif /* IRQ_H */
