#ifndef FLASHER_H
#define FLASHER_H

#include "flasher/IFlasher.h"
#include "gpio/GpioDriver.h"

namespace stm32::flasher {

namespace gpio   = stm32::hal::gpio;

class Flasher : public IFlasher
{
public:
  Flasher(gpio::IGpioDriver& gpioDriver);

  void setPin(gpio::Port port, gpio::Pin pin) final;
  void blink() final;

private:
  void delay(uint32_t delay);

private:
  gpio::IGpioDriver& m_gpioDriver;
  gpio::Port m_port;
  gpio::Pin m_pin;
  bool m_ledState;
};

} // namespace

#endif /* FLASHER_H */
