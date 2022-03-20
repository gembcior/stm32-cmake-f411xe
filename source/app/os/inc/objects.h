#ifndef OS_OBJECTS_H
#define OS_OBJECTS_H

#include "objects/objects.h"
#include "system/System.h"
#include "os/Scheduler.h"
#include "irq/IrqAdapterTable.h"
#include "irq/IrqManager.h"
#include "irq.h"
#include "logger/OsLogger.h"

namespace stm32::objects {

template<>
system::System& getObject<system::System>();

const irq::IrqAdapterPointer* getIrqVectorTable();

template<>
irq::IrqManager<irq::IrqNumber>& getObject<irq::IrqManager<irq::IrqNumber>>();

template<>
lib::OsLogger& getObject<lib::OsLogger>();

} // namespace

#endif /* OS_OBJECTS_H */
