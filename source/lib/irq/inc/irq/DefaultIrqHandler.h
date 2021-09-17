#ifndef DEFAULT_IRQ_HANDLER_H
#define DEFAULT_IRQ_HANDLER_H

#include "irq/IrqHandler.h"


namespace stm32::irq {

class DefaultIrqHandler : public IrqHandler
{
public:
  void onInterrupt() final {};
};

}

#endif /* DEFAULT_IRQ_HANDLER_H */
