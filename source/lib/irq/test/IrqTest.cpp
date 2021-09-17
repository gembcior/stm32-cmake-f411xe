#include "gtest/gtest.h"
#include "irq/Irq.h"


using namespace ::testing;
using namespace stm32::irq;


class IrqTest : public Test
{
public:
};


TEST_F(IrqTest, dummy) {
  EXPECT_EQ(1, 1);
}
