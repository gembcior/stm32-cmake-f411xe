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

flasher::Flasher& getFlasher();
ticktack::TickTack& getTickTack();


template<typename Port>
hal::GpioHal<Port>& getGpioHal()
{
  static hal::GpioHal<Port> gpioHal;
  return gpioHal;
}

} // namespace

#endif /* OBJECTS_H */
