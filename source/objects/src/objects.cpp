#include "objects/objects.h"
#include "system/constants.h"
#include "uart/UartHal.h"
#include "uart/UartDriver.h"
#include "ticktack/TickTack.h"
#include "gpio/GpioHal.h"


namespace stm32::objects {

using namespace stm32::hal;
using namespace stm32::lib;
using namespace stm32::irq;
using namespace stm32::system;


template<>
hal::GpioDriver& getObject<hal::GpioDriver>()
{
  static IGpioHal* gpioHal[] = {
    &getObject<GpioHal<PortA>>(),
    nullptr,
    &getObject<GpioHal<PortC>>(),
    nullptr,
    nullptr,
    nullptr
  };

  static GpioDriver gpioDriver(gpioHal);
  return gpioDriver;
}


template<>
UartDriver& getObject<UartDriver>()
{
  static UartDriver uartDriver(getObject<UartHal<UART2>>(), SystemClock / 2);
  return uartDriver;
}


template<>
Flasher& getObject<Flasher>()
{
  static Flasher flasher(getObject<GpioDriver>(), getObject<TickTack>(), SysTickClock);
  return flasher;
}


template<>
IrqManager<MaxIrqNumber>& getObject<IrqManager<MaxIrqNumber>>()
{
  static uint32_t irqVectorTable[MaxIrqNumber] __attribute__ ((section (".runtime_isr_vector")));
  static IrqManager<MaxIrqNumber> irqManager(irqVectorTable);
  return irqManager;
}

} // namespace
