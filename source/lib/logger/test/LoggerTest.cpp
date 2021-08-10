#include "gtest/gtest.h"
#include "logger/Logger.h"


using namespace ::testing;
using namespace stm32::lib;


class LoggerTest : public Test
{
public:
};


TEST_F(LoggerTest, dummy) {
  EXPECT_EQ(1, 1);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
