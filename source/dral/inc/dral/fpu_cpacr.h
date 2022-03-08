#ifndef DRAL_STM32F411_FPU_CPACR_H
#define DRAL_STM32F411_FPU_CPACR_H

#include "register_model.h"

namespace dral::stm32f411 {

class fpu_cpacr
{
public:
  static constexpr uint32_t BaseAddress = 0xE000ED88;

private:
  template <uint32_t address>
  class CpacrReg: public RegisterModel<address>
  {
  public:
    using cp = FieldModel<address, 20, 0x0000000F>;
  };

public:
  using cpacr = CpacrReg<BaseAddress + 0x0000>;
};

}

#endif /* DRAL_STM32F411_FPU_CPACR_H */
