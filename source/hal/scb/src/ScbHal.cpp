#include "scb/ScbHal.h"
#include "dral/scb.h"
#include "dral/fpu_cpacr.h"


namespace stm32::hal {

using namespace dral::stm32f411;

void ScbHal::setCoprocessorAccessPrivileges(uint32_t privilege)
{
  uint32_t value = privilege << 22 | privilege << 20;
  fpu_cpacr::cpacr::write(value);
}


void ScbHal::setVectorTableOffset(uint32_t offset)
{
  scb::vtor::tbloff::write(offset >> 9);
}

} // namespace
