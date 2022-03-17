#ifndef USB_OBJECTS_H
#define USB_OBJECTS_H

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

#endif /* USB_OBJECTS_H */
