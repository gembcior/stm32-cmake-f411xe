#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H

#include "rcc.h"

namespace stm32::hal {

class RccDriver
{
public:
  void enableClockSource(ClockSource clockSource);
  void disableClockSource(ClockSource clockSource);
  void setSystemClockSource(ClockSource clockSource);
  void setClockDomainPrescaler(ClockDomain clockDomain, ClockPrescaler clockPrescaler);
  void configureMainPll(const PllConfiguration config);
  void enablePeripheralClock(Apb1Peripheral peripheral);
  void enablePeripheralClock(Apb2Peripheral peripheral);
  void enablePeripheralClock(Ahb1Peripheral peripheral);
  void enablePeripheralClock(Ahb2Peripheral peripheral);
};

} // namespace

#endif /* RCC_DRIVER_H */
