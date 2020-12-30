#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H

#include "rcc.h"

namespace stm32::hal::rcc {

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

private:
  static constexpr uint32_t ApbPrescalerTable[] = {0b000, 0b100, 0b101, 0b110, 0b111};
  static constexpr uint32_t AhbPrescalerTable[] = {0b0000, 0b1000, 0b1001, 0b1010, 0b1011, 0b1100, 0b1101, 0b1110, 0b1111};

};

} // namespace

#endif /* RCC_DRIVER_H */
