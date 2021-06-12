#include "flash/FlashHal.h"
#include "dral/flash.h"


namespace stm32::hal {

using namespace dral::stm32f411;

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
