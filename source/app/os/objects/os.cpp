#include "objects.h"
#include "system/constants.h"


namespace stm32::objects {

os::Scheduler& getScheduler()
{
  static os::Scheduler scheduler;
  return scheduler;
}

} // namespace
