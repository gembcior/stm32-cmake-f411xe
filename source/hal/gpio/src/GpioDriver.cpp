#include <cstdint>
#include "gpio/GpioDriver.h"


namespace stm32::hal {

GpioDriver::GpioDriver(IGpioHal** gpioHal)
  : m_gpioHal(gpioHal)
{
}


void GpioDriver::configure(Port port, Pin pin, PortConfig config)
{
  m_gpioHal[static_cast<uint32_t>(port)]->setMode(pin, config.mode);
  m_gpioHal[static_cast<uint32_t>(port)]->setType(pin, config.type);
  m_gpioHal[static_cast<uint32_t>(port)]->setSpeed(pin, config.speed);
  m_gpioHal[static_cast<uint32_t>(port)]->setPull(pin, config.pull);
  m_gpioHal[static_cast<uint32_t>(port)]->setAlternateFunction(pin, config.af);
}


void GpioDriver::configure(GpioPin pin)
{
  m_gpioHal[static_cast<uint32_t>(pin.port)]->setMode(pin.pin, pin.config.mode);
  m_gpioHal[static_cast<uint32_t>(pin.port)]->setType(pin.pin, pin.config.type);
  m_gpioHal[static_cast<uint32_t>(pin.port)]->setSpeed(pin.pin, pin.config.speed);
  m_gpioHal[static_cast<uint32_t>(pin.port)]->setPull(pin.pin, pin.config.pull);
  m_gpioHal[static_cast<uint32_t>(pin.port)]->setAlternateFunction(pin.pin, pin.config.af);
}


void GpioDriver::setPort(Port port, uint32_t value)
{
}


uint32_t GpioDriver::getPort(Port port)
{
  return 0;
}


void GpioDriver::setPin(Port port, Pin pin, PinState state)
{
  m_gpioHal[static_cast<uint32_t>(port)]->setPin(pin, state);
}


void GpioDriver::setPin(GpioPin pin, PinState state)
{
  m_gpioHal[static_cast<uint32_t>(pin.port)]->setPin(pin.pin, state);
}


PinState GpioDriver::getPin(Port port, Pin pin)
{
  return PinState::High;
}


PinState GpioDriver::getPin(GpioPin pin)
{
  return PinState::High;
}

} // namespace
