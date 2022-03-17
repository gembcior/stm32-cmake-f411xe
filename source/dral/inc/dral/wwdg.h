#ifndef DRAL_STM32F411_WWDG_H
#define DRAL_STM32F411_WWDG_H

#include "register_model.h"

namespace dral::stm32f411 {

class wwdg
{
public:
  static constexpr uint32_t BaseAddress = 0x40002C00;

private:
  template <uint32_t address>
  class CrReg: public RegisterModel<address>
  {
  public:
    using wdga = FieldModel<address, 7, 0x00000001>;
    using t = FieldModel<address, 0, 0x0000007F>;
  };

public:
  using cr = CrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class CfrReg: public RegisterModel<address>
  {
  public:
    using ewi = FieldModel<address, 9, 0x00000001>;
    using wdgtb1 = FieldModel<address, 8, 0x00000001>;
    using wdgtb0 = FieldModel<address, 7, 0x00000001>;
    using w = FieldModel<address, 0, 0x0000007F>;
  };

public:
  using cfr = CfrReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class SrReg: public RegisterModel<address>
  {
  public:
    using ewif = FieldModel<address, 0, 0x00000001>;
  };

public:
  using sr = SrReg<BaseAddress + 0x0008>;
};

}

#endif /* DRAL_STM32F411_WWDG_H */
