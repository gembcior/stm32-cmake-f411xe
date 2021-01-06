#ifndef STM32_F411XE_REG_PWR_H
#define STM32_F411XE_REG_PWR_H

#include "stm32/register_model/register_model.h"
#include "stm32/f411xe/const/general.h"
#include "stm32/f411xe/const/pwr.h"

namespace stm32::regs::pwr {

using namespace stm32::constants::pwr;


template <uint32_t address, RegisterPolicy regPolicy>
class CrReg: public RegisterModel<address, regPolicy>
{
public:
  using lpds   = FieldModel<address, cr::LpdsPos,   cr::LpdsMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using pdds   = FieldModel<address, cr::PddsPos,   cr::PddsMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using cwuf   = FieldModel<address, cr::CwufPos,   cr::CwufMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using csbf   = FieldModel<address, cr::CsbfPos,   cr::CsbfMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using pvde   = FieldModel<address, cr::PvdePos,   cr::PvdeMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using pls    = FieldModel<address, cr::PlsPos,    cr::PlsMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using dbp    = FieldModel<address, cr::DbpPos,    cr::DbpMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using fpds   = FieldModel<address, cr::FpdsPos,   cr::FpdsMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using lplvds = FieldModel<address, cr::LplvdsPos, cr::LplvdsMsk, regPolicy, FieldPolicy::ReadWrite>;
  using mrlvds = FieldModel<address, cr::MrlvdsPos, cr::MrlvdsMsk, regPolicy, FieldPolicy::ReadWrite>;
  using adcdc1 = FieldModel<address, cr::Adcdc1Pos, cr::Adcdc1Msk, regPolicy, FieldPolicy::ReadWrite>;
  using vos    = FieldModel<address, cr::VosPos,    cr::VosMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using fmssr  = FieldModel<address, cr::FmssrPos,  cr::FmssrMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using fissr  = FieldModel<address, cr::FissrPos,  cr::FissrMsk,  regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class CsrReg: public RegisterModel<address, regPolicy>
{
public:
  using wuf    = FieldModel<address, csr::WufPos,    csr::WufMsk,    regPolicy, FieldPolicy::ReadOnly>;
  using sbf    = FieldModel<address, csr::SbfPos,    csr::SbfMsk,    regPolicy, FieldPolicy::ReadOnly>;
  using pvdo   = FieldModel<address, csr::PvdoPos,   csr::PvdoMsk,   regPolicy, FieldPolicy::ReadOnly>;
  using brr    = FieldModel<address, csr::BrrPos,    csr::BrrMsk,    regPolicy, FieldPolicy::ReadOnly>;
  using ewup   = FieldModel<address, csr::EwupPos,   csr::EwupMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using bre    = FieldModel<address, csr::BrePos,    csr::BreMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using vosrdy = FieldModel<address, csr::VosrdyPos, csr::VosrdyMsk, regPolicy, FieldPolicy::ReadOnly>;
};


using cr  = CrReg<cr::Address, RegisterPolicy::ReadWrite>;
using csr = CsrReg<csr::Address, RegisterPolicy::ReadWrite>;

}

#endif /* STM32_F411XE_REG_PWR_H */
