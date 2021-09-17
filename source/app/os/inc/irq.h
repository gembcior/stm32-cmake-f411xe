#ifndef OS_IRQ_H
#define OS_IRQ_H

#include "system/constants.h"
#include "objects/objects.h"

#include "irq/Irq.h"
#include "irq/DefaultIrqHandler.h"
#include "irq/ExceptionHandler.h"
#include "irq/IrqAdapterTable.h"

extern "C" {
  void vPortSVCHandler();
  void xPortPendSVHandler();
  void xPortSysTickHandler();
}

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


const Irq DebugMonIrq = {
  .position = getIrqPosition(0x30),
  .handler = &objects::getObject<DefaultIrqHandler>(),
};


// Overwrite IrqAdapterTable with RTOS handlers
constexpr Irq SvcIrq = {
  .position = getIrqPosition(0x2C),
  .handler = nullptr,
};


constexpr Irq PendSvIrq = {
  .position = getIrqPosition(0x38),
  .handler = nullptr,
};


constexpr Irq SysTickIrq = {
  .position = getIrqPosition(0x3C),
  .handler = nullptr,
};


template<uint32_t Size, IrqAdapterPointer ... adapters>
struct IrqAdapterTable<Size, SvcIrq.position, adapters...> : IrqAdapterTable<Size, SvcIrq.position + 1, adapters..., vPortSVCHandler> { };


template<uint32_t Size, IrqAdapterPointer ... adapters>
struct IrqAdapterTable<Size, PendSvIrq.position, adapters...> : IrqAdapterTable<Size, PendSvIrq.position + 1, adapters..., xPortPendSVHandler> { };


template<uint32_t Size, IrqAdapterPointer ... adapters>
struct IrqAdapterTable<Size, SysTickIrq.position, adapters...> : IrqAdapterTable<Size, SysTickIrq.position + 1, adapters..., xPortSysTickHandler> { };


} // namespace

#endif /* OS_IRQ_H */
