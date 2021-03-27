#include "objects.h"

namespace stm32::objects {

hal::rcc::RccHal& getRccHal()
{
  static hal::rcc::RccHal rccHal;
  return rccHal;
}


hal::flash::FlashHal& getFlashHal()
{
  static hal::flash::FlashHal flashHal;
  return flashHal;
}


hal::pwr::PwrHal& getPwrHal()
{
  static hal::pwr::PwrHal pwrHal;
  return pwrHal;
}


hal::gpio::GpioDriver& getGpioDriver()
{
  using namespace stm32::hal::gpio;

  static IGpioHal* gpioHal[] = {
    nullptr,
    nullptr,
    &getGpioHal<PortC>(),
    nullptr,
    nullptr,
    nullptr
  };

  static GpioDriver gpioDriver(gpioHal);
  return gpioDriver;
}

} // namespace
