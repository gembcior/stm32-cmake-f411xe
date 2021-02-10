#ifndef GPIO_H
#define GPIO_H

#include <cstdint>

namespace stm32::hal::gpio {

enum class Pin : uint32_t {
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


enum class Port : uint32_t {
  PortA,
  PortB,
  PortC,
  PortD,
  PortE,
  PortH,
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


enum class PinState : uint32_t {
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


struct GpioPin {
  PortConfig config;
  Port port;
  Pin pin;
};

} // namespace

#endif /* GPIO_H */
