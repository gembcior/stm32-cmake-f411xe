#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

#include "irq/IrqHandler.h"


namespace stm32::irq {

class ExceptionHandler : public IrqHandler
{
public:
  void onInterrupt() final;
};

}

#endif /* EXCEPTION_HANDLER_H */
