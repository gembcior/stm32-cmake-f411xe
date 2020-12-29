#ifndef STM32_F411XE_CONST_SYSCFG_H
#define STM32_F411XE_CONST_SYSCFG_H

#include "../../reg_model/reg_model.h"
#include "../const/general.h"
#include "../const/syscfg.h"

namespace stm32::syscfg {
  namespace memrmp {
    using MemMode = RegisterModel<SysCfgBase + Offset, MemModePos, MemModeMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace pmc {
    using Adc1dc2 = RegisterModel<SysCfgBase + Offset, Adc1dc2Pos, Adc1dc2Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace exticr1 {
    using Exti0 = RegisterModel<SysCfgBase + Offset, Exti0Pos, Exti0Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti1 = RegisterModel<SysCfgBase + Offset, Exti1Pos, Exti1Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti2 = RegisterModel<SysCfgBase + Offset, Exti2Pos, Exti2Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti3 = RegisterModel<SysCfgBase + Offset, Exti3Pos, Exti3Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace exticr2 {
    using Exti4 = RegisterModel<SysCfgBase + Offset, Exti4Pos, Exti4Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti5 = RegisterModel<SysCfgBase + Offset, Exti5Pos, Exti5Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti6 = RegisterModel<SysCfgBase + Offset, Exti6Pos, Exti6Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti7 = RegisterModel<SysCfgBase + Offset, Exti7Pos, Exti7Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace exticr3 {
    using Exti8  = RegisterModel<SysCfgBase + Offset, Exti8Pos,  Exti8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti9  = RegisterModel<SysCfgBase + Offset, Exti9Pos,  Exti9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti10 = RegisterModel<SysCfgBase + Offset, Exti10Pos, Exti10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti11 = RegisterModel<SysCfgBase + Offset, Exti11Pos, Exti11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace exticr4 {
    using Exti12 = RegisterModel<SysCfgBase + Offset, Exti12Pos, Exti12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti13 = RegisterModel<SysCfgBase + Offset, Exti13Pos, Exti13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti14 = RegisterModel<SysCfgBase + Offset, Exti14Pos, Exti14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Exti15 = RegisterModel<SysCfgBase + Offset, Exti15Pos, Exti15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace cmpcr {
    using CmpPd = RegisterModel<SysCfgBase + Offset, CmpPdPos, CmpPdMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using Ready = RegisterModel<SysCfgBase + Offset, ReadyPos, ReadyMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }
}

#endif /* STM32_F411XE_CONST_SYSCFG_H */
