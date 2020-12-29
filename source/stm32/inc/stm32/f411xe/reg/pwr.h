#ifndef STM32_F411XE_REG_PWR_H
#define STM32_F411XE_REG_PWR_H

#include "../../reg_model/reg_model.h"
#include "../const/general.h"
#include "../const/pwr.h"

namespace stm32::pwr {
  namespace cr {
    using lpds   = RegisterModel<PwrBase + Offset, LpdsPos,   LpdsMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pdds   = RegisterModel<PwrBase + Offset, PddsPos,   PddsMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using cwuf   = RegisterModel<PwrBase + Offset, CwufPos,   CwufMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using csbf   = RegisterModel<PwrBase + Offset, CsbfPos,   CsbfMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pvde   = RegisterModel<PwrBase + Offset, PvdePos,   PvdeMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pls    = RegisterModel<PwrBase + Offset, PlsPos,    PlsMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dbp    = RegisterModel<PwrBase + Offset, DbpPos,    DbpMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using fpds   = RegisterModel<PwrBase + Offset, FpdsPos,   FpdsMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lplvds = RegisterModel<PwrBase + Offset, LplvdsPos, LplvdsMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using mrlvds = RegisterModel<PwrBase + Offset, MrlvdsPos, MrlvdsMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using adcdc1 = RegisterModel<PwrBase + Offset, Adcdc1Pos, Adcdc1Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using vos    = RegisterModel<PwrBase + Offset, VosPos,    VosMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using fmssr  = RegisterModel<PwrBase + Offset, FmssrPos,  FmssrMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using fissr  = RegisterModel<PwrBase + Offset, FissrPos,  FissrMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace csr {
    using wuf    = RegisterModel<PwrBase + Offset, WufPos,    WufMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using sbf    = RegisterModel<PwrBase + Offset, SbfPos,    SbfMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pvdo   = RegisterModel<PwrBase + Offset, PvdoPos,   PvdoMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using brr    = RegisterModel<PwrBase + Offset, BrrPos,    BrrMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using ewup   = RegisterModel<PwrBase + Offset, EwupPos,   EwupMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using bre    = RegisterModel<PwrBase + Offset, BrePos,    BreMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using vosrdy = RegisterModel<PwrBase + Offset, VosrdyPos, VosrdyMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }
}

#endif /* STM32_F411XE_REG_PWR_H */
