#ifndef BLINKER_IRQ_H
#define BLINKER_IRQ_H

#include "system/constants.h"
#include "objects/objects.h"

#include "irq/Irq.h"
#include "irq/DefaultIrqHandler.h"
#include "irq/ExceptionHandler.h"
#include "SysTickIrqHandler.h"


namespace stm32::irq {

constexpr uint32_t IrqNumber = 32;


constexpr uint32_t getIrqPosition(uint32_t address)
{
  return (address / 4) - 2;
}

const Irq NmiIrq = {
  .position = getIrqPosition(0x8),
  .handler = &objects::getObject<DefaultIrqHandler>(),
};


const Irq HardFaultIrq = {
  .position = getIrqPosition(0xC),
  .handler = &objects::getObject<ExceptionHandler>(),
};


const Irq MemManageIrq = {
  .position = getIrqPosition(0x10),
  .handler = &objects::getObject<ExceptionHandler>(),
};


const Irq BusFaultIrq = {
  .position = getIrqPosition(0x14),
  .handler = &objects::getObject<ExceptionHandler>(),
};


const Irq UsageFaultIrq = {
  .position = getIrqPosition(0x18),
  .handler = &objects::getObject<ExceptionHandler>(),
};


const Irq SvcIrq = {
  .position = getIrqPosition(0x2C),
  .handler = &objects::getObject<DefaultIrqHandler>(),
};


const Irq DebugMonIrq = {
  .position = getIrqPosition(0x30),
  .handler = &objects::getObject<DefaultIrqHandler>(),
};


const Irq PendSvIrq = {
  .position = getIrqPosition(0x38),
  .handler = &objects::getObject<DefaultIrqHandler>(),
};


const Irq SysTickIrq = {
  .position = getIrqPosition(0x3C),
  .handler = &objects::getObject<SysTickIrqHandler>(),
};

} // namespace

#endif /* BLINKER_IRQ_H */
