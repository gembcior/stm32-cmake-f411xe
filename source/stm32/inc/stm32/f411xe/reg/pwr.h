#ifndef STM32_F411XE_REG_PWR_H
#define STM32_F411XE_REG_PWR_H

#include "reg_model/reg_model.h"
#include "../const/general.h"
#include "../const/pwr.h"

namespace stm32::pwr {
  namespace cr {
    using lpds   = RegisterModel<PwrBase, LpdsPos,   LpdsMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pdds   = RegisterModel<PwrBase, PddsPos,   PddsMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using cwuf   = RegisterModel<PwrBase, CwufPos,   CwufMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using csbf   = RegisterModel<PwrBase, CsbfPos,   CsbfMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pvde   = RegisterModel<PwrBase, PvdePos,   PvdeMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pls    = RegisterModel<PwrBase, PlsPos,    PlsMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dbp    = RegisterModel<PwrBase, DbpPos,    DbpMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using fpds   = RegisterModel<PwrBase, FpdsPos,   FpdsMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lplvds = RegisterModel<PwrBase, LplvdsPos, LplvdsMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using mrlvds = RegisterModel<PwrBase, MrlvdsPos, MrlvdsMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using adcdc1 = RegisterModel<PwrBase, Adcdc1Pos, Adcdc1Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using vos    = RegisterModel<PwrBase, VosPos,    VosMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using fmssr  = RegisterModel<PwrBase, FmssrPos,  FmssrMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using fissr  = RegisterModel<PwrBase, FissrPos,  FissrMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace csr {
    using wuf    = RegisterModel<PwrBase, WufPos,    WufMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using sbf    = RegisterModel<PwrBase, SbfPos,    SbfMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pvdo   = RegisterModel<PwrBase, PvdoPos,   PvdoMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using brr    = RegisterModel<PwrBase, BrrPos,    BrrMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using ewup   = RegisterModel<PwrBase, EwupPos,   EwupMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using bre    = RegisterModel<PwrBase, BrePos,    BreMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using vosrdy = RegisterModel<PwrBase, VosrdyPos, VosrdyMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }
}

#endif /* STM32_F411XE_REG_PWR_H */
