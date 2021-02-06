#ifndef STM32_SCB_HAL_H
#define STM32_SCB_HAL_H

#include <cstdint>

namespace stm32::hal::scb {

class ScbHal
{
public:
  void setCoprocessorAccessPrivileges(uint32_t privilege);
  void setVectorTableOffset(uint32_t offset);
};

} // namespace

#endif /* STM32_SCB_HAL_H */
