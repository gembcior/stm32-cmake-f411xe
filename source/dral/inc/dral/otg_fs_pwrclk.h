#ifndef DRAL_STM32F411_OTG_FS_PWRCLK_H
#define DRAL_STM32F411_OTG_FS_PWRCLK_H

#include "register_model.h"

namespace dral::stm32f411 {

class otg_fs_pwrclk
{
public:
  static constexpr uint32_t BaseAddress = 0x50000E00;

private:
  template <uint32_t address>
  class Fs_pcgcctlReg: public RegisterModel<address>
  {
  public:
    using stppclk = FieldModel<address, 0, 0x00000001>;
    using gatehclk = FieldModel<address, 1, 0x00000001>;
    using physusp = FieldModel<address, 4, 0x00000001>;
  };

public:
  using fs_pcgcctl = Fs_pcgcctlReg<BaseAddress + 0x0000>;
};

}

#endif /* DRAL_STM32F411_OTG_FS_PWRCLK_H */
