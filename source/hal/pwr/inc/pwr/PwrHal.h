#ifndef PWR_HAL_H
#define PWR_HAL_H

#include "pwr/IPwrHal.h"

namespace stm32::hal {

class PwrHal : public IPwrHal
{
public:
  void setRegulatorVoltageScaling(RegulatorVoltageScaleMode mode) final;
};

} // namespace

#endif /* PWR_HAL_H */
