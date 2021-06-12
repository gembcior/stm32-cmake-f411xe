#ifndef NVIC_HAL_H
#define NVIC_HAL_H

#include "nvic/INvicHal.h"

namespace stm32::hal {

class NvicHal : public INvicHal
{
public:
  void enableIrq(uint32_t irq);
  void disableIrq(uint32_t irq);
  void setPendingIrq(uint32_t irq);
  void clearPendingIrq(uint32_t irq);
  uint32_t isIrqActive(uint32_t irq);
  void setIrqPriority(uint32_t irq, uint32_t priority);
};

} // namespace

#endif /* NVIC_HAL_H */
