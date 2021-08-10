#ifndef FLASHER_H
#define FLASHER_H

#include "IFlasher.h"
#include "gpio/GpioDriver.h"
#include "ticktack/TickTack.h"

namespace stm32::lib {

class Flasher : public IFlasher
{
public:
  Flasher(hal::IGpioDriver& gpioDriver, lib::ITickTack& tickTack, uint32_t tickFrequency);

  void setPin(hal::Port port, hal::Pin pin) final;
  void setPeriod(uint32_t period) final;
  void blink() final;

private:
  hal::IGpioDriver& m_gpioDriver;
  lib::ITickTack& m_tickTack;
  uint32_t m_tickFrequency;
  hal::Port m_port;
  hal::Pin m_pin;
  bool m_ledState;
};

} // namespace

#endif /* FLASHER_H */
