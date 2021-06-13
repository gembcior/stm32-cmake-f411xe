#ifndef MOCK_GPIO_HAL_H
#define MOCK_GPIO_HAL_H

#include "gmock/gmock.h"
#include "gpio/IGpioHal.h"


class MockGpioHal : public stm32::hal::IGpioHal
{
 public:
  MOCK_METHOD(void, setMode, (stm32::hal::Pin pin, stm32::hal::PortMode mode), (override));
  MOCK_METHOD(void, setType, (stm32::hal::Pin pin, stm32::hal::PortType type), (override));
  MOCK_METHOD(void, setSpeed, (stm32::hal::Pin pin, stm32::hal::PortSpeed speed), (override));
  MOCK_METHOD(void, setPull, (stm32::hal::Pin pin, stm32::hal::PortPull pull), (override));
  MOCK_METHOD(void, setAlternateFunction, (stm32::hal::Pin pin, stm32::hal::PortAlternateFunction af), (override));

  MOCK_METHOD(void, setPort, (uint32_t value), (override));
  MOCK_METHOD(uint32_t, getPort, (), (override));

  MOCK_METHOD(void, setPin, (stm32::hal::Pin pin, stm32::hal::PinState state), (override));
  MOCK_METHOD(stm32::hal::PinState, getPin, (stm32::hall::Pin pin), (override));
};

#endif /* MOCK_GPIO_HAL_H */
