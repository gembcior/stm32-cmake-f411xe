#include "objects.h"
#include "OsSystem.h"

namespace stm32::objects {

system::System& getSystem()
{
  static system::OsSystem system(getRccHal(), getFlashHal(), getPwrHal(), getSysTickHal(), getGpioDriver());
  return system;
}

} // namespace
