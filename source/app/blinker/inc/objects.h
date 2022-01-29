#ifndef BLINKER_OBJECTS_H
#define BLINKER_OBJECTS_H

#include "objects/objects.h"
#include "system/System.h"
#include "irq/IrqAdapterTable.h"
#include "irq/IrqManager.h"
#include "irq.h"

namespace stm32::objects {

template<>
system::System& getObject<system::System>();

const irq::IrqAdapterPointer* getIrqVectorTable();

template<>
irq::IrqManager<irq::IrqNumber>& getObject<irq::IrqManager<irq::IrqNumber>>();

} // namespace

#endif /* BLINKER_OBJECTS_H */
