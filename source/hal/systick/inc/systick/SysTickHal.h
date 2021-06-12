#ifndef SYS_TICK_HAL_H
#define SYS_TICK_HAL_H

#include "systick/ISysTickHal.h"

namespace stm32::hal {

class SysTickHal : public ISysTickHal
{
public:
  void setClockSource(SysTickClockSource source) final;
  void enable() final;
  void disable() final;
  void enableInterrupts();
  void disableInterrupts();
  void setReloadValue(uint32_t value) final;
  uint32_t getReloadValue() final;
  uint32_t getCurrentValue() final;
  void clear() final;
};

} // namespace

#endif /* SYS_TICK_HAL_H */
