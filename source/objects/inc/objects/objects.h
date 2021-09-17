#ifndef OBJECTS_H
#define OBJECTS_H

#include "system/constants.h"
#include "uart/UartDriver.h"
#include "flasher/Flasher.h"
#include "gpio/GpioDriver.h"
#include "irq/IrqManager.h"


namespace stm32::objects {

template<typename T>
T& getObject()
{
  static T object;
  return object;
}


template<>
hal::GpioDriver& getObject<hal::GpioDriver>();
template<>
hal::UartDriver& getObject<hal::UartDriver>();
template<>
lib::Flasher& getObject<lib::Flasher>();

} // namespace

#endif /* OBJECTS_H */
