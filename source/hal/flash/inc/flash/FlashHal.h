#ifndef FLASH_HAL_H
#define FLASH_HAL_H

#include <cstdint>
#include "flash/IFlashHal.h"

namespace stm32::hal {

class FlashHal : public IFlashHal
{
public:
  void enableDataCache() final;
  void enableInstructionCache() final;
  void enablePrefetch() final;
  void setLatency(uint32_t latency) final;

};

} // namespace

#endif /* FLASH_HAL_H */
