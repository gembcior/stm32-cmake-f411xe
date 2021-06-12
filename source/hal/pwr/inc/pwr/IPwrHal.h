#ifndef IPWR_HAL_H
#define IPWR_HAL_H

#include "pwr/types.h"

namespace stm32::hal {

class IPwrHal
{
public:
  virtual void setRegulatorVoltageScaling(RegulatorVoltageScaleMode mode) = 0;
};

} // namespace

#endif /* IPWR_HAL_H */
