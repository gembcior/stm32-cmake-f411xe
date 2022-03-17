#ifndef OS_IRQ_H
#define OS_IRQ_H

#include "system/constants.h"
#include "objects/objects.h"

#include "irq/Irq.h"
#include "irq/DefaultIrqHandler.h"
#include "irq/ExceptionHandler.h"
#include "irq/IrqAdapterTable.h"
#include <cstdint>

extern "C" {
  void vPortSVCHandler();
  void xPortPendSVHandler();
  void xPortSysTickHandler();
}

namespace stm32::irq {

constexpr uint32_t IrqNumber = 100;


constexpr uint32_t getIrqNumber(uint32_t address)
{
  if (address > 0x3C) {
    return ((address - 0x3C) / 4) - 1;
  } else {
    return IrqNumber + 1;
  }
}


constexpr uint32_t getIrqHandlerPosition(uint32_t address)
{
  return (address / 4) - 2;
}


const Irq NmiIrq = {
  .number = getIrqNumber(0x8),
  .handler = &objects::getObject<DefaultIrqHandler>(),
  .handlerPosition = getIrqHandlerPosition(0x8),
};


const Irq HardFaultIrq = {
  .number = getIrqNumber(0xC),
  .handler = &objects::getObject<ExceptionHandler>(),
  .handlerPosition = getIrqHandlerPosition(0xC),
};


const Irq MemManageIrq = {
  .number = getIrqNumber(0x10),
  .handler = &objects::getObject<ExceptionHandler>(),
  .handlerPosition = getIrqHandlerPosition(0x10),
};


const Irq BusFaultIrq = {
  .number = getIrqNumber(0x14),
  .handler = &objects::getObject<ExceptionHandler>(),
  .handlerPosition = getIrqHandlerPosition(0x14),
};


const Irq UsageFaultIrq = {
  .number = getIrqNumber(0x18),
  .handler = &objects::getObject<ExceptionHandler>(),
  .handlerPosition = getIrqHandlerPosition(0x18),
};


constexpr Irq SvcIrq = {
  .number = getIrqNumber(0x2C),
  .handler = nullptr,
  .handlerPosition = getIrqHandlerPosition(0x2C),
};


const Irq DebugMonIrq = {
  .number = getIrqNumber(0x30),
  .handler = &objects::getObject<DefaultIrqHandler>(),
  .handlerPosition = getIrqHandlerPosition(0x30),
};


constexpr Irq PendSvIrq = {
  .number = getIrqNumber(0x38),
  .handler = nullptr,
  .handlerPosition = getIrqHandlerPosition(0x38),
};


constexpr Irq SysTickIrq = {
  .number = getIrqNumber(0x3C),
  .handler = nullptr,
  .handlerPosition = getIrqHandlerPosition(0x3C),
};


template<uint32_t Size, IrqAdapterPointer ... adapters>
struct IrqAdapterTable<Size, SvcIrq.handlerPosition, adapters...> : IrqAdapterTable<Size, SvcIrq.handlerPosition + 1, adapters..., vPortSVCHandler> { };


template<uint32_t Size, IrqAdapterPointer ... adapters>
struct IrqAdapterTable<Size, PendSvIrq.handlerPosition, adapters...> : IrqAdapterTable<Size, PendSvIrq.handlerPosition + 1, adapters..., xPortPendSVHandler> { };


template<uint32_t Size, IrqAdapterPointer ... adapters>
struct IrqAdapterTable<Size, SysTickIrq.handlerPosition, adapters...> : IrqAdapterTable<Size, SysTickIrq.handlerPosition + 1, adapters..., xPortSysTickHandler> { };


} // namespace

#endif /* OS_IRQ_H */
