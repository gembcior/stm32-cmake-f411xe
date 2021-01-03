#ifndef SCB_DRIVER_H
#define SCB_DRIVER_H

#include <cstdint>
#include "stm32/f4xx/reg/scb.h"

namespace stm32::hal::scb {

namespace scb = stm32::regs::scb;


class ScbDriver
{
public:
  void setCoprocessorAccessPrivileges(uint32_t privilege);
  void setVectorTableOffset(uint32_t offset);
};


void ScbDriver::setCoprocessorAccessPrivileges(uint32_t privilege)
{
  uint32_t value = privilege << 22 | privilege << 20;
  scb::cpacr::write(value);
}


void ScbDriver::setVectorTableOffset(uint32_t offset)
{
  scb::vtor::tbloff::write(offset >> 9);
}

} // namespace

#endif /* SCB_DRIVER_H */
