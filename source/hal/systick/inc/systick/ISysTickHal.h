#ifndef ISYS_TICK_HAL_H
#define ISYS_TICK_HAL_H

#include <cstdint>
#include "systick/types.h"

namespace stm32::hal {

class ISysTickHal
{
public:
  virtual void setClockSource(SysTickClockSource source) = 0;
  virtual void enable() = 0;
  virtual void disable() = 0;
  virtual void enableInterrupts() = 0;
  virtual void disableInterrupts() = 0;
  virtual void setReloadValue(uint32_t value) = 0;
  virtual uint32_t getReloadValue() = 0;
  virtual uint32_t getCurrentValue() = 0;
  virtual void clear() = 0;
};

} // namespace

#endif /* ISYS_TICK_HAL_H */
