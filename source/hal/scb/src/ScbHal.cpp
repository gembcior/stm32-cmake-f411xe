#include "scb/ScbHal.h"
#include "stm32/f4/f411xe/scb.h"


namespace stm32::hal::scb {

namespace scb = dral::stm32::f4::f411xe::scb;

void ScbHal::setCoprocessorAccessPrivileges(uint32_t privilege)
{
  uint32_t value = privilege << 22 | privilege << 20;
  scb::cpacr::write(value);
}


void ScbHal::setVectorTableOffset(uint32_t offset)
{
  scb::vtor::tbloff::write(offset >> 9);
}

} // namespace
