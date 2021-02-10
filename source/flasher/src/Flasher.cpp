#include "flasher/Flasher.h"


namespace stm32::flasher {

Flasher::Flasher(gpio::IGpioDriver& gpioDriver)
  : m_gpioDriver(gpioDriver)
  , m_port(gpio::Port::PortA)
  , m_pin(gpio::Pin::Pin0)
  , m_ledState(false)
{
}


void Flasher::setPin(gpio::Port port, gpio::Pin pin)
{
  m_port = port;
  m_pin = pin;
}


void Flasher::delay(uint32_t delay)
{
  for (volatile uint32_t i = 0; i < 100000; i++) {
    for (volatile uint32_t j = 0; j < delay; j++) {
    }
  }
}


void Flasher::blink()
{
  if (m_ledState) {
    m_ledState = false;
    m_gpioDriver.setPin(m_port, m_pin, gpio::PinState::High);
  } else {
    m_ledState = true;
    m_gpioDriver.setPin(m_port, m_pin, gpio::PinState::Low);
  }
  delay(1);
}

} // namespace
