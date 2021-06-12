#include "flasher/Flasher.h"


namespace stm32::flasher {

using namespace stm32::hal;
using namespace stm32::ticktack;

Flasher::Flasher(IGpioDriver& gpioDriver, ITickTack& tickTack, uint32_t tickFrequency)
  : m_gpioDriver(gpioDriver)
  , m_tickTack(tickTack)
  , m_tickFrequency(tickFrequency)
  , m_port(Port::PortA)
  , m_pin(Pin::Pin0)
  , m_ledState(false)
{
}


void Flasher::setPin(Port port, Pin pin)
{
  m_port = port;
  m_pin = pin;
}


void Flasher::setPeriod(uint32_t period)
{
  m_tickTack.setPeriod((period * m_tickFrequency) / 1000);
}


void Flasher::blink()
{
  m_ledState = m_tickTack.getTick();

  if (m_ledState) {
    m_gpioDriver.setPin(m_port, m_pin, PinState::High);
  } else {
    m_gpioDriver.setPin(m_port, m_pin, PinState::Low);
  }
}

} // namespace
