#include "pwr/PwrHal.h"
#include "stm32/f4/f411xe/pwr.h"


namespace stm32::hal::pwr {

namespace pwr = dral::stm32::f4::f411xe::pwr;

void PwrHal::setRegulatorVoltageScaling(RegulatorVoltageScaleMode mode)
{
  pwr::cr::vos::write(static_cast<uint32_t>(mode));
}

} // namespace
