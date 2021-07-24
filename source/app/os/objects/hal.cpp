#include "objects.h"
#include "system/constants.h"

namespace stm32::objects {

using namespace stm32::hal;

RccHal& getRccHal()
{
  static RccHal rccHal;
  return rccHal;
}


FlashHal& getFlashHal()
{
  static FlashHal flashHal;
  return flashHal;
}


PwrHal& getPwrHal()
{
  static PwrHal pwrHal;
  return pwrHal;
}


GpioDriver& getGpioDriver()
{
  static IGpioHal* gpioHal[] = {
    &getGpioHal<PortA>(),
    nullptr,
    &getGpioHal<PortC>(),
    nullptr,
    nullptr,
    nullptr
  };

  static GpioDriver gpioDriver(gpioHal);
  return gpioDriver;
}


SysTickHal& getSysTickHal()
{
  static SysTickHal sysTickHal;
  return sysTickHal;
}


NvicHal& getNvicHal()
{
  static NvicHal nvicHal;
  return nvicHal;
}


UartDriver& getUartDriver()
{
  static UartDriver uartDriver(getUartHal<UART2>(), system::SystemClock / 2);
  return uartDriver;
}

} // namespace
