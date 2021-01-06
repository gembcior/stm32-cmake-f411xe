#ifndef PWR_DRIVER_H
#define PWR_DRIVER_H

#include <cstdint>
#include "stm32/f411xe/reg/pwr.h"

namespace stm32::hal::pwr {

namespace pwr = stm32::regs::pwr;


enum class RegulatorVoltageScaleMode {
  Mode3 = 1,
  Mode2 = 2,
  Mode1 = 3,
};


class PwrDriver
{
public:
  void setRegulatorVoltageScaling(RegulatorVoltageScaleMode mode);
};


inline void PwrDriver::setRegulatorVoltageScaling(RegulatorVoltageScaleMode mode)
{
  pwr::cr::vos::write(static_cast<uint32_t>(mode));
}

} // namespace

#endif /* PWR_DRIVER_H */
