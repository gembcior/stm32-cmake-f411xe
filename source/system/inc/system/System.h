#ifndef FLASH_HAL_H
#define FLASH_HAL_H

#include <cstdint>

namespace stm32::hal::flash {

class FlashHal
{
public:
  void enableDataCache();
  void enableInstructionCache();
  void enablePrefetch();
  void setLatency(uint32_t latency);

};

} // namespace

#endif /* FLASH_HAL_H */