#ifndef GPIO_HAL_H
#define GPIO_HAL_H

#include <cstdint>
#include "stm32/f4/f411xe/gpio.h"

namespace stm32::hal::gpio {

using PortA = dral::stm32::f4::f411xe::gpio::gpioA;
using PortB = dral::stm32::f4::f411xe::gpio::gpioB;
using PortC = dral::stm32::f4::f411xe::gpio::gpioC;
using PortD = dral::stm32::f4::f411xe::gpio::gpioD;
using PortE = dral::stm32::f4::f411xe::gpio::gpioE;
using PortH = dral::stm32::f4::f411xe::gpio::gpioH;


enum Pin {
  Pin0,
  Pin1,
  Pin2,
  Pin3,
  Pin4,
  Pin5,
  Pin6,
  Pin7,
  Pin8,
  Pin9,
  Pin10,
  Pin11,
  Pin12,
  Pin13,
  Pin14,
  Pin15,
};


enum class PortMode {
  Input,
  Output,
  AlternateFunction,
  Analog,
};


enum class PortType {
  PushPull,
  OpenDrain,
};


enum class PortSpeed {
  Low,
  Medium,
  Fast,
  High,
};


enum class PortPull {
  NoPull,
  PullUp,
  PullDown,
};


enum class PinState {
  Low,
  High,
};


enum class PortAlternateFunction {
  Af0 = 0,
  Af1,
  Af2,
  Af3,
  Af4,
  Af5,
  Af6,
  Af7,
  Af8,
  Af9,
  Af10,
  Af11,
  Af12,
  Af13,
  Af14,
  Af15,
};


struct PortConfig {
  PortMode mode;
  PortType type;
  PortSpeed speed;
  PortPull pull;
  PortAlternateFunction af = PortAlternateFunction::Af0;
};


template<typename Port>
class GpioHal
{
public:
  void setMode(PortMode mode);
  void setMode(Pin pin, PortMode mode);

  void setType(PortType type);
  void setType(Pin pin, PortType type);

  void setSpeed(PortSpeed speed);
  void setSpeed(Pin pin, PortSpeed speed);

  void setPull(PortPull pull);
  void setPull(Pin pin, PortPull pull);

  void setAlternateFunction(PortAlternateFunction af);
  void setAlternateFunction(Pin pin, PortAlternateFunction af);

  void configure(PortConfig config);
  void configure(Pin pin, PortConfig config);

  void setPort(uint32_t value);
  uint32_t getPort();

  void setPin(Pin pin, PinState state);
  PinState getPin(Pin pin);

private:
  void setPin(Pin pin);
  void resetPin(Pin pin);
};


template<typename Port>
void GpioHal<Port>::setMode(PortMode mode)
{
  switch (mode) {
    case PortMode::Input:
      Port::moder::write(0);
      break;
    case PortMode::Output:
      Port::moder::write(0x55'55'55'55);
      break;
    case PortMode::AlternateFunction:
      Port::moder::write(0xAA'AA'AA'AA);
      break;
    case PortMode::Analog:
      Port::moder::write(0xFF'FF'FF'FF);
      break;
    default:
      break;
  }
}


template<typename Port>
void GpioHal<Port>::setMode(Pin pin, PortMode mode)
{
  switch (pin) {
    case Pin0:
      Port::moder::moder0::write(static_cast<uint32_t>(mode));
      break;
    case Pin1:
      Port::moder::moder1::write(static_cast<uint32_t>(mode));
      break;
    case Pin2:
      Port::moder::moder2::write(static_cast<uint32_t>(mode));
      break;
    case Pin3:
      Port::moder::moder3::write(static_cast<uint32_t>(mode));
      break;
    case Pin4:
      Port::moder::moder4::write(static_cast<uint32_t>(mode));
      break;
    case Pin5:
      Port::moder::moder5::write(static_cast<uint32_t>(mode));
      break;
    case Pin6:
      Port::moder::moder6::write(static_cast<uint32_t>(mode));
      break;
    case Pin7:
      Port::moder::moder7::write(static_cast<uint32_t>(mode));
      break;
    case Pin8:
      Port::moder::moder8::write(static_cast<uint32_t>(mode));
      break;
    case Pin9:
      Port::moder::moder9::write(static_cast<uint32_t>(mode));
      break;
    case Pin10:
      Port::moder::moder10::write(static_cast<uint32_t>(mode));
      break;
    case Pin11:
      Port::moder::moder11::write(static_cast<uint32_t>(mode));
      break;
    case Pin12:
      Port::moder::moder12::write(static_cast<uint32_t>(mode));
      break;
    case Pin13:
      Port::moder::moder13::write(static_cast<uint32_t>(mode));
      break;
    case Pin14:
      Port::moder::moder14::write(static_cast<uint32_t>(mode));
      break;
    case Pin15:
      Port::moder::moder15::write(static_cast<uint32_t>(mode));
      break;
    default:
      break;
  }
}


template<typename Port>
void GpioHal<Port>::setType(PortType type)
{
  switch (type) {
    case PortType::PushPull:
      Port::otyper::write(0);
      break;
    case PortType::OpenDrain:
      Port::otyper::write(1);
      break;
    default:
      break;
  }
}


template<typename Port>
void GpioHal<Port>::setType(Pin pin, PortType type)
{
  switch (pin) {
    case Pin0:
      Port::otyper::ot0::write(static_cast<uint32_t>(type));
      break;
    case Pin1:
      Port::otyper::ot1::write(static_cast<uint32_t>(type));
      break;
    case Pin2:
      Port::otyper::ot2::write(static_cast<uint32_t>(type));
      break;
    case Pin3:
      Port::otyper::ot3::write(static_cast<uint32_t>(type));
      break;
    case Pin4:
      Port::otyper::ot4::write(static_cast<uint32_t>(type));
      break;
    case Pin5:
      Port::otyper::ot5::write(static_cast<uint32_t>(type));
      break;
    case Pin6:
      Port::otyper::ot6::write(static_cast<uint32_t>(type));
      break;
    case Pin7:
      Port::otyper::ot7::write(static_cast<uint32_t>(type));
      break;
    case Pin8:
      Port::otyper::ot8::write(static_cast<uint32_t>(type));
      break;
    case Pin9:
      Port::otyper::ot9::write(static_cast<uint32_t>(type));
      break;
    case Pin10:
      Port::otyper::ot10::write(static_cast<uint32_t>(type));
      break;
    case Pin11:
      Port::otyper::ot11::write(static_cast<uint32_t>(type));
      break;
    case Pin12:
      Port::otyper::ot12::write(static_cast<uint32_t>(type));
      break;
    case Pin13:
      Port::otyper::ot13::write(static_cast<uint32_t>(type));
      break;
    case Pin14:
      Port::otyper::ot14::write(static_cast<uint32_t>(type));
      break;
    case Pin15:
      Port::otyper::ot15::write(static_cast<uint32_t>(type));
      break;
    default:
      break;
  }
}


template<typename Port>
void GpioHal<Port>::setSpeed(PortSpeed speed)
{
}


template<typename Port>
void GpioHal<Port>::setSpeed(Pin pin, PortSpeed speed)
{
  switch (pin) {
    case Pin0:
      Port::ospeedr::ospeedr0::write(static_cast<uint32_t>(speed));
      break;
    case Pin1:
      Port::ospeedr::ospeedr1::write(static_cast<uint32_t>(speed));
      break;
    case Pin2:
      Port::ospeedr::ospeedr2::write(static_cast<uint32_t>(speed));
      break;
    case Pin3:
      Port::ospeedr::ospeedr3::write(static_cast<uint32_t>(speed));
      break;
    case Pin4:
      Port::ospeedr::ospeedr4::write(static_cast<uint32_t>(speed));
      break;
    case Pin5:
      Port::ospeedr::ospeedr5::write(static_cast<uint32_t>(speed));
      break;
    case Pin6:
      Port::ospeedr::ospeedr6::write(static_cast<uint32_t>(speed));
      break;
    case Pin7:
      Port::ospeedr::ospeedr7::write(static_cast<uint32_t>(speed));
      break;
    case Pin8:
      Port::ospeedr::ospeedr8::write(static_cast<uint32_t>(speed));
      break;
    case Pin9:
      Port::ospeedr::ospeedr9::write(static_cast<uint32_t>(speed));
      break;
    case Pin10:
      Port::ospeedr::ospeedr10::write(static_cast<uint32_t>(speed));
      break;
    case Pin11:
      Port::ospeedr::ospeedr11::write(static_cast<uint32_t>(speed));
      break;
    case Pin12:
      Port::ospeedr::ospeedr12::write(static_cast<uint32_t>(speed));
      break;
    case Pin13:
      Port::ospeedr::ospeedr13::write(static_cast<uint32_t>(speed));
      break;
    case Pin14:
      Port::ospeedr::ospeedr14::write(static_cast<uint32_t>(speed));
      break;
    case Pin15:
      Port::ospeedr::ospeedr15::write(static_cast<uint32_t>(speed));
      break;
    default:
      break;
  }
}


template<typename Port>
void GpioHal<Port>::setPull(PortPull pull)
{
}


template<typename Port>
void GpioHal<Port>::setPull(Pin pin, PortPull pull)
{
  switch (pin) {
    case Pin0:
      Port::pupdr::pupdr0::write(static_cast<uint32_t>(pull));
      break;
    case Pin1:
      Port::pupdr::pupdr1::write(static_cast<uint32_t>(pull));
      break;
    case Pin2:
      Port::pupdr::pupdr2::write(static_cast<uint32_t>(pull));
      break;
    case Pin3:
      Port::pupdr::pupdr3::write(static_cast<uint32_t>(pull));
      break;
    case Pin4:
      Port::pupdr::pupdr4::write(static_cast<uint32_t>(pull));
      break;
    case Pin5:
      Port::pupdr::pupdr5::write(static_cast<uint32_t>(pull));
      break;
    case Pin6:
      Port::pupdr::pupdr6::write(static_cast<uint32_t>(pull));
      break;
    case Pin7:
      Port::pupdr::pupdr7::write(static_cast<uint32_t>(pull));
      break;
    case Pin8:
      Port::pupdr::pupdr8::write(static_cast<uint32_t>(pull));
      break;
    case Pin9:
      Port::pupdr::pupdr9::write(static_cast<uint32_t>(pull));
      break;
    case Pin10:
      Port::pupdr::pupdr10::write(static_cast<uint32_t>(pull));
      break;
    case Pin11:
      Port::pupdr::pupdr11::write(static_cast<uint32_t>(pull));
      break;
    case Pin12:
      Port::pupdr::pupdr12::write(static_cast<uint32_t>(pull));
      break;
    case Pin13:
      Port::pupdr::pupdr13::write(static_cast<uint32_t>(pull));
      break;
    case Pin14:
      Port::pupdr::pupdr14::write(static_cast<uint32_t>(pull));
      break;
    case Pin15:
      Port::pupdr::pupdr15::write(static_cast<uint32_t>(pull));
      break;
    default:
      break;
  }
}


template<typename Port>
void GpioHal<Port>::setAlternateFunction(PortAlternateFunction af)
{
}


template<typename Port>
void GpioHal<Port>::setAlternateFunction(Pin pin, PortAlternateFunction af)
{
  switch (pin) {
    case Pin0:
      Port::afrl::afsel0::write(static_cast<uint32_t>(af));
      break;
    case Pin1:
      Port::afrl::afsel1::write(static_cast<uint32_t>(af));
      break;
    case Pin2:
      Port::afrl::afsel2::write(static_cast<uint32_t>(af));
      break;
    case Pin3:
      Port::afrl::afsel3::write(static_cast<uint32_t>(af));
      break;
    case Pin4:
      Port::afrl::afsel4::write(static_cast<uint32_t>(af));
      break;
    case Pin5:
      Port::afrl::afsel5::write(static_cast<uint32_t>(af));
      break;
    case Pin6:
      Port::afrl::afsel6::write(static_cast<uint32_t>(af));
      break;
    case Pin7:
      Port::afrl::afsel7::write(static_cast<uint32_t>(af));
      break;
    case Pin8:
      Port::afrh::afsel8::write(static_cast<uint32_t>(af));
      break;
    case Pin9:
      Port::afrh::afsel9::write(static_cast<uint32_t>(af));
      break;
    case Pin10:
      Port::afrh::afsel10::write(static_cast<uint32_t>(af));
      break;
    case Pin11:
      Port::afrh::afsel11::write(static_cast<uint32_t>(af));
      break;
    case Pin12:
      Port::afrh::afsel12::write(static_cast<uint32_t>(af));
      break;
    case Pin13:
      Port::afrh::afsel13::write(static_cast<uint32_t>(af));
      break;
    case Pin14:
      Port::afrh::afsel14::write(static_cast<uint32_t>(af));
      break;
    case Pin15:
      Port::afrh::afsel15::write(static_cast<uint32_t>(af));
      break;
    default:
      break;
  }
}


template<typename Port>
void GpioHal<Port>::configure(PortConfig config)
{
  setMode(config.mode);
  setType(config.type);
  setSpeed(config.speed);
  setPull(config.pull);
  setAlternateFunction(config.af);
}


template<typename Port>
void GpioHal<Port>::configure(Pin pin, PortConfig config)
{
  setMode(pin, config.mode);
  setType(pin, config.type);
  setSpeed(pin, config.speed);
  setPull(pin, config.pull);
  setAlternateFunction(pin, config.af);
}


template<typename Port>
void GpioHal<Port>::setPort(uint32_t value)
{
}


template<typename Port>
uint32_t GpioHal<Port>::getPort()
{
  return 0;
}


template<typename Port>
void GpioHal<Port>::setPin(Pin pin)
{
  switch (pin) {
    case Pin0:
      Port::bsrr::bs0::write(1);
      break;
    case Pin1:
      Port::bsrr::bs1::write(1);
      break;
    case Pin2:
      Port::bsrr::bs2::write(1);
      break;
    case Pin3:
      Port::bsrr::bs3::write(1);
      break;
    case Pin4:
      Port::bsrr::bs4::write(1);
      break;
    case Pin5:
      Port::bsrr::bs5::write(1);
      break;
    case Pin6:
      Port::bsrr::bs6::write(1);
      break;
    case Pin7:
      Port::bsrr::bs7::write(1);
      break;
    case Pin8:
      Port::bsrr::bs8::write(1);
      break;
    case Pin9:
      Port::bsrr::bs9::write(1);
      break;
    case Pin10:
      Port::bsrr::bs10::write(1);
      break;
    case Pin11:
      Port::bsrr::bs11::write(1);
      break;
    case Pin12:
      Port::bsrr::bs12::write(1);
      break;
    case Pin13:
      Port::bsrr::bs13::write(1);
      break;
    case Pin14:
      Port::bsrr::bs14::write(1);
      break;
    case Pin15:
      Port::bsrr::bs15::write(1);
      break;
    default:
      break;
  }
}


template<typename Port>
void GpioHal<Port>::resetPin(Pin pin)
{
  switch (pin) {
    case Pin0:
      Port::bsrr::br0::write(1);
      break;
    case Pin1:
      Port::bsrr::br1::write(1);
      break;
    case Pin2:
      Port::bsrr::br2::write(1);
      break;
    case Pin3:
      Port::bsrr::br3::write(1);
      break;
    case Pin4:
      Port::bsrr::br4::write(1);
      break;
    case Pin5:
      Port::bsrr::br5::write(1);
      break;
    case Pin6:
      Port::bsrr::br6::write(1);
      break;
    case Pin7:
      Port::bsrr::br7::write(1);
      break;
    case Pin8:
      Port::bsrr::br8::write(1);
      break;
    case Pin9:
      Port::bsrr::br9::write(1);
      break;
    case Pin10:
      Port::bsrr::br10::write(1);
      break;
    case Pin11:
      Port::bsrr::br11::write(1);
      break;
    case Pin12:
      Port::bsrr::br12::write(1);
      break;
    case Pin13:
      Port::bsrr::br13::write(1);
      break;
    case Pin14:
      Port::bsrr::br14::write(1);
      break;
    case Pin15:
      Port::bsrr::br15::write(1);
      break;
    default:
      break;
  }
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
  uint32_t state = 0;

  switch (pin) {
    case Pin0:
      state = Port::idr::id0::read();
      break;
    case Pin1:
      state = Port::idr::id1::read();
      break;
    case Pin2:
      state = Port::idr::id2::read();
      break;
    case Pin3:
      state = Port::idr::id3::read();
      break;
    case Pin4:
      state = Port::idr::id4::read();
      break;
    case Pin5:
      state = Port::idr::id5::read();
      break;
    case Pin6:
      state = Port::idr::id6::read();
      break;
    case Pin7:
      state = Port::idr::id7::read();
      break;
    case Pin8:
      state = Port::idr::id8::read();
      break;
    case Pin9:
      state = Port::idr::id9::read();
      break;
    case Pin10:
      state = Port::idr::id10::read();
      break;
    case Pin11:
      state = Port::idr::id11::read();
      break;
    case Pin12:
      state = Port::idr::id12::read();
      break;
    case Pin13:
      state = Port::idr::id13::read();
      break;
    case Pin14:
      state = Port::idr::id14::read();
      break;
    case Pin15:
      state = Port::idr::id15::read();
      break;
    default:
      break;
  }

  return static_cast<PinState>(state);
}

} // namespace

#endif /* GPIO_HAL_H */
