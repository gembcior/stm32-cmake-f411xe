#ifndef BLINKER_OBJECTS_H
#define BLINKER_OBJECTS_H

#include "objects/objects.h"
#include "system/System.h"
#include "irq/IrqAdapterTable.h"

namespace stm32::objects {

template<>
system::System& getObject<system::System>();

const irq::IrqAdapterPointer* getIrqVectorTable();

} // namespace

#endif /* BLINKER_OBJECTS_H */
