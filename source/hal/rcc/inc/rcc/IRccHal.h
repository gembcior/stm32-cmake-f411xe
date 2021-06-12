#ifndef IRCC_HAL_H
#define IRCC_HAL_H

#include <cstdint>
#include "rcc/types.h"

namespace stm32::hal {

class IRccHal
{
public:
  virtual void enableClockSource(ClockSource clockSource) = 0;
  virtual void disableClockSource(ClockSource clockSource) = 0;
  virtual void setSystemClockSource(ClockSource clockSource) = 0;
  virtual void setClockDomainPrescaler(ClockDomain clockDomain, ClockPrescaler clockPrescaler) = 0;
  virtual void configureMainPll(const PllConfiguration config) = 0;
  virtual void enablePeripheralClock(Apb1Peripheral peripheral) = 0;
  virtual void enablePeripheralClock(Apb2Peripheral peripheral) = 0;
  virtual void enablePeripheralClock(Ahb1Peripheral peripheral) = 0;
  virtual void enablePeripheralClock(Ahb2Peripheral peripheral) = 0;
};

} // namespace

#endif /* IRCC_HAL_H */
