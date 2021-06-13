#include "gtest/gtest.h"
#include "ticktack/TickTack.h"


using namespace ::testing;
using namespace stm32::ticktack;


class TickTackTest : public Test
{
protected:
  TickTack m_tickTack;
};


TEST_F(TickTackTest, tickAndTack) {
  constexpr uint32_t period = 100;

  m_tickTack.setPeriod(period);

  for (uint32_t i = 0; i < period + 1; i++) {
    EXPECT_EQ(m_tickTack.getTick(), false);
    m_tickTack.tick();
  }

  for (uint32_t i = 0; i < period + 1; i++) {
    EXPECT_EQ(m_tickTack.getTick(), true);
    m_tickTack.tick();
  }

  EXPECT_EQ(m_tickTack.getTick(), false);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
