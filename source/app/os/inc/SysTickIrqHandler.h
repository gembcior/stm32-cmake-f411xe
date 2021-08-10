#ifndef SYSTICK_IRQ_HANDLER_H
#define SYSTICK_IRQ_HANDLER_H

#include "irq/IrqHandler.h"


namespace stm32::irq {

class SysTickIrqHandler : public IrqHandler
{
public:
  void onInterrupt() final;
};

}

#endif /* SYSTICK_IRQ_HANDLER_H */
