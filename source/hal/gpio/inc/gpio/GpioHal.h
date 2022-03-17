#ifndef GPIO_HAL_H
#define GPIO_HAL_H

#include <cstdint>
#include "gpio/IGpioHal.h"
#include "dral/gpioa.h"
#include "dral/gpiob.h"
#include "dral/gpioc.h"
#include "dral/gpiod.h"
#include "dral/gpioe.h"
#include "dral/gpioh.h"

namespace stm32::hal {

using PortA = dral::stm32f411::gpioa;
using PortB = dral::stm32f411::gpiob;
using PortC = dral::stm32f411::gpioc;
using PortD = dral::stm32f411::gpiod;
using PortE = dral::stm32f411::gpioe;
using PortH = dral::stm32f411::gpioh;


template<typename Port>
class GpioHal : public IGpioHal
{
public:
  void setMode(Pin pin, PortMode mode);
  void setType(Pin pin, PortType type);
  void setSpeed(Pin pin, PortSpeed speed);
  void setPull(Pin pin, PortPull pull);
  void setAlternateFunction(Pin pin, PortAlternateFunction af);

  void setPort(uint32_t value);
  uint32_t getPort();

  void setPin(Pin pin, PinState state);
  PinState getPin(Pin pin);

private:
  void setPin(Pin pin);
  void resetPin(Pin pin);
};


template<typename Port>
void GpioHal<Port>::setMode(Pin pin, PortMode mode)
{
  const uint32_t position = static_cast<uint32_t>(pin) * 2;
  constexpr uint32_t mask = Port::moder::moder0::Mask;
  uint32_t moder = Port::moder::read() & ~(mask << position);
  Port::moder::write(moder | (static_cast<uint32_t>(mode) << position));
}


template<typename Port>
void GpioHal<Port>::setType(Pin pin, PortType type)
{
  const uint32_t position = static_cast<uint32_t>(pin);
  constexpr uint32_t mask = Port::otyper::ot0::Mask;
  uint32_t otyper = Port::otyper::read() & ~(mask << position);
  Port::otyper::write(otyper | (static_cast<uint32_t>(type) << position));
}


template<typename Port>
void GpioHal<Port>::setSpeed(Pin pin, PortSpeed speed)
{
  const uint32_t position = static_cast<uint32_t>(pin) * 2;
  constexpr uint32_t mask = Port::ospeedr::ospeedr0::Mask;
  uint32_t ospeedr = Port::ospeedr::read() & ~(mask << position);
  Port::ospeedr::write(ospeedr | (static_cast<uint32_t>(speed) << position));
}


template<typename Port>
void GpioHal<Port>::setPull(Pin pin, PortPull pull)
{
  const uint32_t position = static_cast<uint32_t>(pin) * 2;
  constexpr uint32_t mask = Port::pupdr::pupdr0::Mask;
  uint32_t pupdr = Port::pupdr::read() & ~(mask << position);
  Port::pupdr::write(pupdr | (static_cast<uint32_t>(pull) << position));
}


template<typename Port>
void GpioHal<Port>::setAlternateFunction(Pin pin, PortAlternateFunction af)
{
  const uint32_t position = (static_cast<uint32_t>(pin) * 4) % 32;
  constexpr uint32_t mask = Port::afrl::afrl0::Mask;
  uint32_t afrx;

  switch (pin) {
    case Pin::Pin0:
    case Pin::Pin1:
    case Pin::Pin2:
    case Pin::Pin3:
    case Pin::Pin4:
    case Pin::Pin5:
    case Pin::Pin6:
    case Pin::Pin7:
      afrx = Port::afrl::read() & ~(mask << position);
      Port::afrl::write(afrx | (static_cast<uint32_t>(af) << position));
      break;
    case Pin::Pin8:
    case Pin::Pin9:
    case Pin::Pin10:
    case Pin::Pin11:
    case Pin::Pin12:
    case Pin::Pin13:
    case Pin::Pin14:
    case Pin::Pin15:
      afrx = Port::afrh::read() & ~(mask << position);
      Port::afrh::write(afrx | (static_cast<uint32_t>(af) << position));
      break;
    default:
      break;
  }
}


template<typename Port>
void GpioHal<Port>::setPort(uint32_t value)
{
  Port::odr::write(value & 0xFFFF);
}


template<typename Port>
uint32_t GpioHal<Port>::getPort()
{
  return Port::idr::read() & 0xFFFF;
}


template<typename Port>
void GpioHal<Port>::setPin(Pin pin)
{
  Port::bsrr::write(1 << static_cast<uint32_t>(pin));
}


template<typename Port>
void GpioHal<Port>::resetPin(Pin pin)
{
  Port::bsrr::write(1 << (static_cast<uint32_t>(pin) + 16));
}


template<typename Port>
void GpioHal<Port>::setPin(Pin pin, PinState state)
{
  switch (state) {
    case PinState::High:
      setPin(pin);
      break;
    case PinState::Low:
      resetPin(pin);
      break;
    default:
      break;
  }
}


template<typename Port>
PinState GpioHal<Port>::getPin(Pin pin)
{
  uint32_t state = Port::idr::read();
  state = (state >> static_cast<uint32_t>(pin)) & Port::idr::idr0::Mask;
  return static_cast<PinState>(state);
}

} // namespace

#endif /* GPIO_HAL_H */
