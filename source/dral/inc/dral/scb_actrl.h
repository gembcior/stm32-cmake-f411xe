#ifndef DRAL_STM32F411_SCB_ACTRL_H
#define DRAL_STM32F411_SCB_ACTRL_H

#include "register_model.h"

namespace dral::stm32f411 {

class scb_actrl
{
public:
  static constexpr uint32_t BaseAddress = 0xE000E008;

private:
  template <uint32_t address>
  class ActrlReg: public RegisterModel<address>
  {
  public:
    using dismcycint = FieldModel<address, 0, 0x00000001>;
    using disdefwbuf = FieldModel<address, 1, 0x00000001>;
    using disfold = FieldModel<address, 2, 0x00000001>;
    using disfpca = FieldModel<address, 8, 0x00000001>;
    using disoofp = FieldModel<address, 9, 0x00000001>;
  };

public:
  using actrl = ActrlReg<BaseAddress + 0x0000>;
};

}

#endif /* DRAL_STM32F411_SCB_ACTRL_H */
