#include "flash/FlashHal.h"
#include "stm32/f4/f411xe/flash.h"


namespace stm32::hal::flash {

namespace flash = dral::stm32::f4::f411xe::flash;

void FlashHal::enableDataCache()
{
  flash::acr::dcen::write(1);
}


void FlashHal::enableInstructionCache()
{
  flash::acr::icen::write(1);
}


void FlashHal::enablePrefetch()
{
  flash::acr::prften::write(1);
}


void FlashHal::setLatency(uint32_t latency)
{
  flash::acr::latency::write(latency);
}

} // namespace
