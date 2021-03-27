#ifndef IPWR_HAL_H
#define IPWR_HAL_H

namespace stm32::hal::pwr {

enum class RegulatorVoltageScaleMode {
  Mode3 = 1,
  Mode2 = 2,
  Mode1 = 3,
};


class IPwrHal
{
public:
  virtual void setRegulatorVoltageScaling(RegulatorVoltageScaleMode mode) = 0;
};

} // namespace

#endif /* IPWR_HAL_H */
