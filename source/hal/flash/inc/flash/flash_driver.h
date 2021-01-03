#ifndef FLASH_DRIVER_H
#define FLASH_DRIVER_H

#include <cstdint>
#include "stm32/f411xe/reg/flash.h"

namespace stm32::hal::flash {

namespace flash = stm32::regs::flash;


class FlashDriver
{
public:
  void enableDataCache();
  void enableInstructionCache();
  void enablePrefetch();
  void setLatency(uint32_t latency);

};


void FlashDriver::enableDataCache()
{
  flash::acr::dcen::write(1);
}


void FlashDriver::enableInstructionCache()
{
  flash::acr::icen::write(1);
}


void FlashDriver::enablePrefetch()
{
  flash::acr::prften::write(1);
}


void FlashDriver::setLatency(uint32_t latency)
{
  flash::acr::latency::write(latency);
}

} // namespace

#endif /* FLASH_DRIVER_H */
