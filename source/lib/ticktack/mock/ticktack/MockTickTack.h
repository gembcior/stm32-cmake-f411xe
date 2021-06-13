#ifndef MOCK_TICK_TACK_H
#define MOCK_TICK_TACK_H

#include "gmock/gmock.h"
#include "ticktack/ITickTack.h"


class MockTickTack : public stm32::ticktack::ITickTack
{
 public:
  MOCK_METHOD(void, tick, (), (override));
  MOCK_METHOD(void, setPeriod, (uint32_t ticks), (override));
  MOCK_METHOD(bool, getTick, (), (override));
};

#endif /* MOCK_TICK_TACK_H */
