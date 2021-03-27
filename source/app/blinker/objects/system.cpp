#include "objects.h"
#include "gpio/gpio.h"

namespace stm32::objects {

system::System& getSystem()
{
  static system::System system(getRccHal(), getFlashHal(), getPwrHal(), getGpioDriver());
  return system;
}

} // namespace
