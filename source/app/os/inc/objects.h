#ifndef OBJECTS_H
#define OBJECTS_H

#include "objects/objects.h"
#include "system/System.h"
#include "os/Scheduler.h"

namespace stm32::objects {

template<>
system::System& getObject<system::System>();

} // namespace

#endif /* OBJECTS_H */
