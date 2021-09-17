#ifndef OS_OBJECTS_H
#define OS_OBJECTS_H

#include "objects/objects.h"
#include "system/System.h"
#include "os/Scheduler.h"
#include "irq/IrqAdapterTable.h"

namespace stm32::objects {

template<>
system::System& getObject<system::System>();

const irq::IrqAdapterPointer* getIrqVectorTable();

} // namespace

#endif /* OS_OBJECTS_H */
