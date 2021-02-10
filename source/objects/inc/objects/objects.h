#ifndef OBJECTS_H
#define OBJECTS_H

#include "rcc/RccHal.h"
#include "flash/FlashHal.h"
#include "pwr/PwrHal.h"
#include "gpio/GpioHal.h"
#include "gpio/GpioDriver.h"
#include "system/System.h"
#include "flasher/Flasher.h"

namespace stm32::objects {

hal::rcc::RccHal& getRccHal();
hal::flash::FlashHal& getFlashHal();
hal::pwr::PwrHal& getPwrHal();
system::System& getSystem();
flasher::Flasher& getFlasher();
hal::gpio::GpioDriver& getGpioDriver();

template<typename Port>
hal::gpio::GpioHal<Port>& getGpioHal()
{
  static hal::gpio::GpioHal<Port> gpioHal;
  return gpioHal;
}

} // namespace

#endif /* OBJECTS_H */
