#include "objects.h"
#include "BlinkerSystem.h"

namespace stm32::objects {

system::System& getSystem()
{
  static system::BlinkerSystem system(getRccHal(), getFlashHal(), getPwrHal(), getSysTickHal(), getGpioDriver());
  return system;
}

} // namespace
