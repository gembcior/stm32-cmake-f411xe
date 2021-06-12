#ifndef SCB_HAL_H
#define SCB_HAL_H

#include <cstdint>
#include "scb/IScbHal.h"

namespace stm32::hal {

class ScbHal : public IScbHal
{
public:
  void setCoprocessorAccessPrivileges(uint32_t privilege);
  void setVectorTableOffset(uint32_t offset);
};

} // namespace

#endif /* SCB_HAL_H */
