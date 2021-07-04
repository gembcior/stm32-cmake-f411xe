#include "objects.h"
#include "system/constants.h"


namespace stm32::objects {

flasher::Flasher& getFlasher()
{
  static flasher::Flasher flasher(getGpioDriver(), getTickTack(), system::SysTickClock);
  return flasher;
}


ticktack::TickTack& getTickTack()
{
  static ticktack::TickTack tickTack;
  return tickTack;
}


logger::Logger& getLogger()
{
  static logger::Logger logger;
  return logger;
}

} // namespace
