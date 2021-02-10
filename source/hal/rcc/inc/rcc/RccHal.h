#ifndef RCC_HAL_H
#define RCC_HAL_H

#include <cstdint>
#include "rcc/IRccHal.h"

namespace stm32::hal::rcc {

class RccHal : public IRccHal
{
public:
  void enableClockSource(ClockSource clockSource) final;
  void disableClockSource(ClockSource clockSource) final;
  void setSystemClockSource(ClockSource clockSource) final;
  void setClockDomainPrescaler(ClockDomain clockDomain, ClockPrescaler clockPrescaler) final;
  void configureMainPll(const PllConfiguration config) final;
  void enablePeripheralClock(Apb1Peripheral peripheral) final;
  void enablePeripheralClock(Apb2Peripheral peripheral) final;
  void enablePeripheralClock(Ahb1Peripheral peripheral) final;
  void enablePeripheralClock(Ahb2Peripheral peripheral) final;

private:
  static constexpr uint32_t ApbPrescalerTable[] = {0b000, 0b100, 0b101, 0b110, 0b111};
  static constexpr uint32_t AhbPrescalerTable[] = {0b0000, 0b1000, 0b1001, 0b1010, 0b1011, 0b1100, 0b1101, 0b1110, 0b1111};
};

} // namespace

#endif /* RCC_HAL_H */
