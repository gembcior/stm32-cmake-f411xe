#ifndef USB_IRQ_HANDLER_H
#define USB_IRQ_HANDLER_H

#include "irq/IrqHandler.h"


namespace stm32::irq {

class UsbIrqHandler : public IrqHandler
{
public:
  void onInterrupt() final;
};

}

#endif /* USB_IRQ_HANDLER_H */
