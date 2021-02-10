#include "objects/objects.h"
#include "gpio/gpio.h"

namespace stm32::objects {

flasher::Flasher& getFlasher()
{
  static flasher::Flasher flasher(getGpioDriver());
  return flasher;
}

} // namespace
