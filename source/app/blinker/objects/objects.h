#ifndef OBJECTS_H
#define OBJECTS_H

#include "system/System.h"

#include "rcc/RccHal.h"
#include "flash/FlashHal.h"
#include "pwr/PwrHal.h"
#include "gpio/GpioHal.h"
#include "gpio/GpioDriver.h"
#include "systick/SysTickHal.h"
#include "nvic/NvicHal.h"
#include "uart/UartHal.h"
#include "uart/UartDriver.h"

#include "flasher/Flasher.h"
#include "ticktack/TickTack.h"


namespace stm32::objects {

system::System& getSystem();

hal::RccHal& getRccHal();
hal::FlashHal& getFlashHal();
hal::PwrHal& getPwrHal();
hal::SysTickHal& getSysTickHal();
hal::GpioDriver& getGpioDriver();
hal::NvicHal& getNvicHal();
hal::UartDriver& getUartDriver();

flasher::Flasher& getFlasher();
ticktack::TickTack& getTickTack();


template<typename Port>
hal::GpioHal<Port>& getGpioHal()
{
  static hal::GpioHal<Port> gpioHal;
  return gpioHal;
}


template<typename Uart>
hal::UartHal<Uart>& getUartHal()
{
  static hal::UartHal<Uart> uartHal;
  return uartHal;
}

} // namespace

#endif /* OBJECTS_H */
