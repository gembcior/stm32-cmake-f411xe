#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "gpio/gpio.h"

namespace stm32::system {

namespace gpio = stm32::hal::gpio;

constexpr gpio::GpioPin UserLed4 = {
  .config = {
    .mode = gpio::PortMode::Output,
    .type = gpio::PortType::PushPull,
    .speed = gpio::PortSpeed::Low,
    .pull = gpio::PortPull::NoPull,
  },
  .port = gpio::Port::PortC,
  .pin = gpio::Pin::Pin5,
};


constexpr gpio::GpioPin UserLed3 = {
  .config = {
    .mode = gpio::PortMode::Output,
    .type = gpio::PortType::PushPull,
    .speed = gpio::PortSpeed::Low,
    .pull = gpio::PortPull::NoPull,
  },
  .port = gpio::Port::PortC,
  .pin = gpio::Pin::Pin8,
};


constexpr gpio::GpioPin UserLed2 = {
  .config = {
    .mode = gpio::PortMode::Output,
    .type = gpio::PortType::PushPull,
    .speed = gpio::PortSpeed::Low,
    .pull = gpio::PortPull::NoPull,
  },
  .port = gpio::Port::PortC,
  .pin = gpio::Pin::Pin9,
};

} // namespace

#endif /* CONSTANTS_H */
