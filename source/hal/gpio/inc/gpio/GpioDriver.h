#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <cstdint>
#include "stm32/f411xe/reg/gpio.h"

namespace stm32::hal::gpio {

using PortA = stm32::regs::gpio::a;
using PortB = stm32::regs::gpio::b;
using PortC = stm32::regs::gpio::c;
using PortD = stm32::regs::gpio::d;
using PortE = stm32::regs::gpio::e;
using PortH = stm32::regs::gpio::h;


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


struct PortConfig {
  PortMode mode;
  PortType type;
  PortSpeed speed;
  PortPull pull;
};


template<typename Port>
class GpioDriver
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
void GpioDriver<Port>::setMode(PortMode mode)
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
void GpioDriver<Port>::setMode(Pin pin, PortMode mode)
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
void GpioDriver<Port>::setType(PortType type)
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
void GpioDriver<Port>::setType(Pin pin, PortType type)
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
void GpioDriver<Port>::setSpeed(PortSpeed speed)
{
}


template<typename Port>
void GpioDriver<Port>::setSpeed(Pin pin, PortSpeed speed)
{
  switch (pin) {
    case Pin0:
      Port::ospeedr::ospeed0::write(static_cast<uint32_t>(speed));
      break;
    case Pin1:
      Port::ospeedr::ospeed1::write(static_cast<uint32_t>(speed));
      break;
    case Pin2:
      Port::ospeedr::ospeed2::write(static_cast<uint32_t>(speed));
      break;
    case Pin3:
      Port::ospeedr::ospeed3::write(static_cast<uint32_t>(speed));
      break;
    case Pin4:
      Port::ospeedr::ospeed4::write(static_cast<uint32_t>(speed));
      break;
    case Pin5:
      Port::ospeedr::ospeed5::write(static_cast<uint32_t>(speed));
      break;
    case Pin6:
      Port::ospeedr::ospeed6::write(static_cast<uint32_t>(speed));
      break;
    case Pin7:
      Port::ospeedr::ospeed7::write(static_cast<uint32_t>(speed));
      break;
    case Pin8:
      Port::ospeedr::ospeed8::write(static_cast<uint32_t>(speed));
      break;
    case Pin9:
      Port::ospeedr::ospeed9::write(static_cast<uint32_t>(speed));
      break;
    case Pin10:
      Port::ospeedr::ospeed10::write(static_cast<uint32_t>(speed));
      break;
    case Pin11:
      Port::ospeedr::ospeed11::write(static_cast<uint32_t>(speed));
      break;
    case Pin12:
      Port::ospeedr::ospeed12::write(static_cast<uint32_t>(speed));
      break;
    case Pin13:
      Port::ospeedr::ospeed13::write(static_cast<uint32_t>(speed));
      break;
    case Pin14:
      Port::ospeedr::ospeed14::write(static_cast<uint32_t>(speed));
      break;
    case Pin15:
      Port::ospeedr::ospeed15::write(static_cast<uint32_t>(speed));
      break;
    default:
      break;
  }
}


template<typename Port>
void GpioDriver<Port>::setPull(PortPull pull)
{
}


template<typename Port>
void GpioDriver<Port>::setPull(Pin pin, PortPull pull)
{
  switch (pin) {
    case Pin0:
      Port::pupdr::pupd0::write(static_cast<uint32_t>(pull));
      break;
    case Pin1:
      Port::pupdr::pupd1::write(static_cast<uint32_t>(pull));
      break;
    case Pin2:
      Port::pupdr::pupd2::write(static_cast<uint32_t>(pull));
      break;
    case Pin3:
      Port::pupdr::pupd3::write(static_cast<uint32_t>(pull));
      break;
    case Pin4:
      Port::pupdr::pupd4::write(static_cast<uint32_t>(pull));
      break;
    case Pin5:
      Port::pupdr::pupd5::write(static_cast<uint32_t>(pull));
      break;
    case Pin6:
      Port::pupdr::pupd6::write(static_cast<uint32_t>(pull));
      break;
    case Pin7:
      Port::pupdr::pupd7::write(static_cast<uint32_t>(pull));
      break;
    case Pin8:
      Port::pupdr::pupd8::write(static_cast<uint32_t>(pull));
      break;
    case Pin9:
      Port::pupdr::pupd9::write(static_cast<uint32_t>(pull));
      break;
    case Pin10:
      Port::pupdr::pupd10::write(static_cast<uint32_t>(pull));
      break;
    case Pin11:
      Port::pupdr::pupd11::write(static_cast<uint32_t>(pull));
      break;
    case Pin12:
      Port::pupdr::pupd12::write(static_cast<uint32_t>(pull));
      break;
    case Pin13:
      Port::pupdr::pupd13::write(static_cast<uint32_t>(pull));
      break;
    case Pin14:
      Port::pupdr::pupd14::write(static_cast<uint32_t>(pull));
      break;
    case Pin15:
      Port::pupdr::pupd15::write(static_cast<uint32_t>(pull));
      break;
    default:
      break;
  }
}


template<typename Port>
void GpioDriver<Port>::configure(PortConfig config)
{
  setMode(config.mode);
  setType(config.type);
  setSpeed(config.speed);
  setPull(config.pull);
}


template<typename Port>
void GpioDriver<Port>::configure(Pin pin, PortConfig config)
{
  setMode(pin, config.mode);
  setType(pin, config.type);
  setSpeed(pin, config.speed);
  setPull(pin, config.pull);
}


template<typename Port>
void GpioDriver<Port>::setPort(uint32_t value)
{
}


template<typename Port>
uint32_t GpioDriver<Port>::getPort()
{
  return 0;
}


template<typename Port>
void GpioDriver<Port>::setPin(Pin pin)
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
void GpioDriver<Port>::resetPin(Pin pin)
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
void GpioDriver<Port>::setPin(Pin pin, PinState state)
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
PinState GpioDriver<Port>::getPin(Pin pin)
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

#endif /* GPIO_DRIVER_H */
