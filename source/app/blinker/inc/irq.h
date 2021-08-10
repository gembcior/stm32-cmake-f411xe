#ifndef IRQ_IRQ_H
#define IRQ_IRQ_H

#include "SysTickIrqHandler.h"
#include "irq/Irq.h"
#include "irq/IrqHandlerAdapter.h"
#include "irq.h"
#include "system/constants.h"
#include "objects/objects.h"
#include "irq/DefaultIrqHandler.h"
#include "irq/ExceptionHandler.h"

namespace stm32::irq {

const Irq NmiIrq = {
  .position = 2,
  .adapter = irqHandlerAdapter<system::MaxIrqNumber, 2>,
  .handler = &objects::getObject<DefaultIrqHandler>(),
};


const Irq HardFaultIrq = {
  .position = 3,
  .adapter = irqHandlerAdapter<system::MaxIrqNumber, 3>,
  .handler = &objects::getObject<ExceptionHandler>(),
};


const Irq MemManageIrq = {
  .position = 4,
  .adapter = irqHandlerAdapter<system::MaxIrqNumber, 4>,
  .handler = &objects::getObject<ExceptionHandler>(),
};


const Irq BusFaultIrq = {
  .position = 5,
  .adapter = irqHandlerAdapter<system::MaxIrqNumber, 5>,
  .handler = &objects::getObject<ExceptionHandler>(),
};


const Irq UsageFaultIrq = {
  .position = 6,
  .adapter = irqHandlerAdapter<system::MaxIrqNumber, 6>,
  .handler = &objects::getObject<ExceptionHandler>(),
};


const Irq SvcIrq = {
  .position = 11,
  .adapter = irqHandlerAdapter<system::MaxIrqNumber, 11>,
  .handler = &objects::getObject<DefaultIrqHandler>(),
};


const Irq DebugMonIrq = {
  .position = 12,
  .adapter = irqHandlerAdapter<system::MaxIrqNumber, 12>,
  .handler = &objects::getObject<DefaultIrqHandler>(),
};


const Irq PendSvIrq = {
  .position = 14,
  .adapter = irqHandlerAdapter<system::MaxIrqNumber, 14>,
  .handler = &objects::getObject<DefaultIrqHandler>(),
};


const Irq SysTickIrq = {
  .position = 15,
  .adapter = irqHandlerAdapter<system::MaxIrqNumber, 15>,
  .handler = &objects::getObject<SysTickIrqHandler>(),
};

} // namespace

#endif /* IRQ_IRQ_H */
