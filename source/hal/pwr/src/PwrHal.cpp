#include "pwr/PwrHal.h"
#include "dral/pwr.h"


namespace stm32::hal {

using namespace dral::stm32f411;

void PwrHal::setRegulatorVoltageScaling(RegulatorVoltageScaleMode mode)
{
  pwr::cr::vos::write(static_cast<uint32_t>(mode));
}

} // namespace
