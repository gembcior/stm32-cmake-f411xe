#ifndef STM32_F411XE_REG_FLASH_H
#define STM32_F411XE_REG_FLASH_H

#include "stm32/register_model/register_model.h"
#include "stm32/f411xe/const/general.h"
#include "stm32/f411xe/const/flash.h"

namespace stm32::regs::flash {

using namespace stm32::constants::flash;


template <uint32_t address, RegisterPolicy regPolicy>
class AcrReg: public RegisterModel<address, regPolicy>
{
public:
  using latency = FieldModel<address, acr::LatencyPos, acr::LatencyMsk, regPolicy, FieldPolicy::ReadWrite>;
  using prften  = FieldModel<address, acr::PrftenPos,  acr::PrftenMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using icen    = FieldModel<address, acr::IcenPos,    acr::IcenMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using dcen    = FieldModel<address, acr::DcenPos,    acr::DcenMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using icrst   = FieldModel<address, acr::IcrstPos,   acr::IcrstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using dcrst   = FieldModel<address, acr::DcrstPos,   acr::DcrstMsk,   regPolicy, FieldPolicy::ReadWrite>;
};


using acr = AcrReg<acr::Address, RegisterPolicy::ReadWrite>;

}

#endif /* STM32_F411XE_REG_FLASH_H */
