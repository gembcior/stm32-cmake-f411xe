#ifndef STM32_F4XX_REG_SCB_H
#define STM32_F4XX_REG_SCB_H

#include "../../reg_model/reg_model.h"
#include "../const/general.h"
#include "../const/scb.h"

namespace stm32::scb {
  namespace cpuid {
    using implementer = RegisterModel<ScbBase + Offset, ImplementerPos, ImplementerMsk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
    using variant     = RegisterModel<ScbBase + Offset, VariantPos,     VariantMsk,     PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
    using constant    = RegisterModel<ScbBase + Offset, ConstantPos,    ConstantMsk,    PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
    using partno      = RegisterModel<ScbBase + Offset, PartnoPos,      PartnoMsk,      PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
    using revision    = RegisterModel<ScbBase + Offset, RevisionPos,    RevisionMsk,    PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
  }

  namespace icsr {

  }

  namespace vtor {
    using tbloff = RegisterModel<ScbBase + Offset, TbloffPos, TbloffMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace aircr {
  }

  namespace scr {
  }

  namespace ccr {
  }

  namespace shpr1 {
  }

  namespace shpr2 {
  }

  namespace shpr3 {
  }

  namespace shcsr {
  }

  namespace cfsr {
  }

  namespace hfsr {
  }

  namespace mmar {
  }

  namespace bfar {
  }

  namespace afsr {
  }

  namespace actlr {
  }

  namespace cpacr {
    using cp10 = RegisterModel<ScbBase + Offset, Cp10Pos, Cp10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using cp11 = RegisterModel<ScbBase + Offset, Cp11Pos, Cp11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }
}

#endif /* STM32_F4XX_REG_SCB_H */
