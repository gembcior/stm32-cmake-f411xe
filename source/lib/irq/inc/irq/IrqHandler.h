#ifndef IRQ_HANDLER_H
#define IRQ_HANDLER_H

namespace stm32::irq {

class IrqHandler
{
public:
  virtual inline void onInterrupt() = 0;
};

} // namespace

#endif /* IRQ_HANDLER_H */
