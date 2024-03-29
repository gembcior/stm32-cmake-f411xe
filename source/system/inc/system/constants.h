#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "gpio/types.h"

namespace stm32::system {

constexpr uint32_t SystemClock = 96'000'000U;
constexpr uint32_t SysTickClock = 1000U;


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


constexpr hal::GpioPin Uart2Tx = {
  .config = {
    .mode = hal::PortMode::AlternateFunction,
    .type = hal::PortType::PushPull,
    .speed = hal::PortSpeed::Fast,
    .pull = hal::PortPull::NoPull,
    .af = hal::PortAlternateFunction::Af7,
  },
  .port = hal::Port::PortA,
  .pin = hal::Pin::Pin2,
};


constexpr hal::GpioPin UserButton = {
  .config = {
    .mode = hal::PortMode::Input,
    .type = hal::PortType::PushPull,
    .speed = hal::PortSpeed::Low,
    .pull = hal::PortPull::PullUp,
  },
  .port = hal::Port::PortC,
  .pin = hal::Pin::Pin13,
};


constexpr hal::GpioPin UsbOtgFsDm = {
  .config = {
    .mode = hal::PortMode::AlternateFunction,
    .type = hal::PortType::PushPull,
    .speed = hal::PortSpeed::High,
    .pull = hal::PortPull::NoPull,
    .af = hal::PortAlternateFunction::Af10,
  },
  .port = hal::Port::PortA,
  .pin = hal::Pin::Pin11,
};


constexpr hal::GpioPin UsbOtgFsDp = {
  .config = {
    .mode = hal::PortMode::AlternateFunction,
    .type = hal::PortType::PushPull,
    .speed = hal::PortSpeed::High,
    .pull = hal::PortPull::NoPull,
    .af = hal::PortAlternateFunction::Af10,
  },
  .port = hal::Port::PortA,
  .pin = hal::Pin::Pin12,
};

} // namespace

#endif /* CONSTANTS_H */
