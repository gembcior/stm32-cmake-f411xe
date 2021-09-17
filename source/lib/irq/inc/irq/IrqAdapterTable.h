#ifndef IRQ_VECTOR_TABLE_H
#define IRQ_VECTOR_TABLE_H

#include <cstdint>
#include <array>
#include "irq/IrqManager.h"



namespace stm32::irq {

using IrqAdapterPointer = void(*)();


template<uint32_t IrqNumber, uint32_t Position>
void irqAdapter();


template<uint32_t IrqNumber, uint32_t Position>
void irqAdapter()
{
  if (IrqManager<IrqNumber>::IrqHandlerList[Position]) {
    IrqManager<IrqNumber>::IrqHandlerList[Position]->onInterrupt();
  }
}


template<uint32_t Size, uint32_t Position = 0, IrqAdapterPointer ... adapters>
struct IrqAdapterTable : IrqAdapterTable<Size, Position + 1, adapters..., irqAdapter<Size, Position>> { };


template<uint32_t Size, IrqAdapterPointer...adapters>
struct IrqAdapterTable<Size, Size, adapters...> {
  static constexpr std::array<IrqAdapterPointer, Size> Table = { adapters... };
};

} // namespace

#endif /* IRQ_VECTOR_TABLE_H */
