#ifndef STM32_F4XX_REG_SCB_H
#define STM32_F4XX_REG_SCB_H

#include "stm32/register_model/register_model.h"
#include "stm32/f4xx/const/general.h"
#include "stm32/f4xx/const/scb.h"

namespace stm32::regs::scb {

using namespace stm32::constants::scb;

template <uint32_t address, RegisterPolicy regPolicy>
class CpuidReg: public RegisterModel<address, regPolicy>
{
public:
  using implementer = FieldModel<address, cpuid::ImplementerPos, cpuid::ImplementerMsk, regPolicy, FieldPolicy::ReadOnly>;
  using variant     = FieldModel<address, cpuid::VariantPos,     cpuid::VariantMsk,     regPolicy, FieldPolicy::ReadOnly>;
  using constant    = FieldModel<address, cpuid::ConstantPos,    cpuid::ConstantMsk,    regPolicy, FieldPolicy::ReadOnly>;
  using partno      = FieldModel<address, cpuid::PartnoPos,      cpuid::PartnoMsk,      regPolicy, FieldPolicy::ReadOnly>;
  using revision    = FieldModel<address, cpuid::RevisionPos,    cpuid::RevisionMsk,    regPolicy, FieldPolicy::ReadOnly>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class VtorReg: public RegisterModel<address, regPolicy>
{
public:
  using tbloff = FieldModel<address, vtor::TbloffPos, vtor::TbloffMsk, regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class CpacrReg: public RegisterModel<address, regPolicy>
{
public:
  using cp10 = FieldModel<address, cpacr::Cp10Pos, cpacr::Cp10Msk, regPolicy, FieldPolicy::ReadWrite>;
  using cp11 = FieldModel<address, cpacr::Cp11Pos, cpacr::Cp11Msk, regPolicy, FieldPolicy::ReadWrite>;
};


using cpuid = CpuidReg<cpuid::Address, RegisterPolicy::ReadOnly>;
using vtor  = VtorReg<vtor::Address, RegisterPolicy::ReadWrite>;
using cpacr = CpacrReg<cpacr::Address, RegisterPolicy::ReadWrite>;

}

#endif /* STM32_F4XX_REG_SCB_H */
