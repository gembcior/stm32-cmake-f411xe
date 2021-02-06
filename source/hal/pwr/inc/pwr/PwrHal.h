#ifndef PWR_HAL_H
#define PWR_HAL_H

#include <cstdint>

namespace stm32::hal::pwr {

enum class RegulatorVoltageScaleMode {
  Mode3 = 1,
  Mode2 = 2,
  Mode1 = 3,
};


class PwrHal
{
public:
  void setRegulatorVoltageScaling(RegulatorVoltageScaleMode mode);
};

} // namespace

#endif /* PWR_HAL_H */
