#include <cstdint>
#include "gtest/gtest.h"
#include "gpio/MockGpioDriver.h"
#include "ticktack/MockTickTack.h"
#include "flasher/Flasher.h"


using namespace ::testing;
using namespace stm32::flasher;
using namespace stm32::hal;


class FlasherTest : public Test
{
public:
  FlasherTest() : m_flasher(m_mockGpioDriver, m_mockTickTack, tickFrequency)
  {}

protected:
  Flasher m_flasher;

  NiceMock<MockGpioDriver> m_mockGpioDriver;
  NiceMock<MockTickTack> m_mockTickTack;

  static constexpr uint32_t tickFrequency = 1e3;
};


TEST_F(FlasherTest, flashOn) {
  EXPECT_CALL(m_mockTickTack, getTick).WillOnce(Return(true));
  EXPECT_CALL(m_mockGpioDriver, setPin(_, _, PinState::High));

  m_flasher.blink();
}


TEST_F(FlasherTest, flashOff) {
  EXPECT_CALL(m_mockTickTack, getTick).WillOnce(Return(false));
  EXPECT_CALL(m_mockGpioDriver, setPin(_, _, PinState::Low));

  m_flasher.blink();
}


TEST_F(FlasherTest, setPeriod) {
  constexpr uint32_t period = 500;

  EXPECT_CALL(m_mockTickTack, setPeriod((period * tickFrequency) / 1000));

  m_flasher.setPeriod(period);
}


TEST_F(FlasherTest, setPin) {
  constexpr Port port = Port::PortC;
  constexpr Pin pin = Pin::Pin9;

  EXPECT_CALL(m_mockGpioDriver, setPin(port, pin, _));

  m_flasher.setPin(port, pin);
  m_flasher.blink();
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
