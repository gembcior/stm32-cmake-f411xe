#ifndef ISCB_HAL_H
#define ISCB_HAL_H

#include <cstdint>

namespace stm32::hal::scb {

class IScbHal
{
public:
  virtual void setCoprocessorAccessPrivileges(uint32_t privilege) = 0;
  virtual void setVectorTableOffset(uint32_t offset) = 0;
};

} // namespace

#endif /* ISCB_HAL_H */
