#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "gpio/types.h"

namespace stm32::system {

constexpr uint32_t SystemClock = 96e6;
constexpr uint32_t SysTickClock = 1e3;


constexpr hal::GpioPin UserLed4 = {
  .config = {
    .mode = hal::PortMode::Output,
    .type = hal::PortType::PushPull,
    .speed = hal::PortSpeed::Low,
    .pull = hal::PortPull::NoPull,
  },
  .port = hal::Port::PortC,
  .pin = hal::Pin::Pin5,
};


constexpr hal::GpioPin UserLed3 = {
  .config = {
    .mode = hal::PortMode::Output,
    .type = hal::PortType::PushPull,
    .speed = hal::PortSpeed::Low,
    .pull = hal::PortPull::NoPull,
  },
  .port = hal::Port::PortC,
  .pin = hal::Pin::Pin8,
};


constexpr hal::GpioPin UserLed2 = {
  .config = {
    .mode = hal::PortMode::Output,
    .type = hal::PortType::PushPull,
    .speed = hal::PortSpeed::Low,
    .pull = hal::PortPull::NoPull,
  },
  .port = hal::Port::PortC,
  .pin = hal::Pin::Pin9,
};

} // namespace

#endif /* CONSTANTS_H */
