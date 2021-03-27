#ifndef IFLASH_HAL_H
#define IFLASH_HAL_H

#include <cstdint>

namespace stm32::hal::flash {

class IFlashHal
{
public:
  virtual void enableDataCache() = 0;
  virtual void enableInstructionCache() = 0;
  virtual void enablePrefetch() = 0;
  virtual void setLatency(uint32_t latency) = 0;
};

} // namespace

#endif /* IFLASH_HAL_H */
