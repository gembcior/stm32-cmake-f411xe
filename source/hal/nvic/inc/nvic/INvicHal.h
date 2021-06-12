#ifndef INVIC_HAL_H
#define INVIC_HAL_H

#include <cstdint>
#include "nvic/types.h"

namespace stm32::hal {

class INvicHal
{
public:
  virtual void enableIrq(uint32_t irq) = 0;
  virtual void disableIrq(uint32_t irq) = 0;
  virtual void setPendingIrq(uint32_t irq) = 0;
  virtual void clearPendingIrq(uint32_t irq) = 0;
  virtual uint32_t isIrqActive(uint32_t irq) = 0;
  virtual void setIrqPriority(uint32_t irq, uint32_t priority) = 0;

};

} // namespace

#endif /* INVIC_HAL_H */
