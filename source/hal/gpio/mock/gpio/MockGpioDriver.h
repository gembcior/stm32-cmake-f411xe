#ifndef MOCK_GPIO_DRIVER_H
#define MOCK_GPIO_DRIVER_H

#include "gmock/gmock.h"
#include "gpio/IGpioDriver.h"


class MockGpioDriver : public stm32::hal::IGpioDriver
{
 public:
  MOCK_METHOD(void, configure, (stm32::hal::Port port, stm32::hal::Pin pin, stm32::hal::PortConfig config), (override));
  MOCK_METHOD(void, configure, (stm32::hal::GpioPin pin), (override));
  MOCK_METHOD(void, setPort, (stm32::hal::Port port, uint32_t value), (override));
  MOCK_METHOD(uint32_t, getPort, (stm32::hal::Port port), (override));
  MOCK_METHOD(void, setPin, (stm32::hal::Port port, stm32::hal::Pin pin, stm32::hal::PinState state), (override));
  MOCK_METHOD(void, setPin, (stm32::hal::GpioPin pin, stm32::hal::PinState state), (override));
  MOCK_METHOD(stm32::hal::PinState, getPin, (stm32::hal::Port port, stm32::hal::Pin pin), (override));
  MOCK_METHOD(stm32::hal::PinState, getPin, (stm32::hal::GpioPin pin), (override));
};

#endif /* MOCK_GPIO_DRIVER_H */
