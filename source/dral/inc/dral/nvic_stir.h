#ifndef DRAL_STM32F411_NVIC_STIR_H
#define DRAL_STM32F411_NVIC_STIR_H

#include "register_model.h"

namespace dral::stm32f411 {

class nvic_stir
{
public:
  static constexpr uint32_t BaseAddress = 0xE000EF00;

private:
  template <uint32_t address>
  class StirReg: public RegisterModel<address>
  {
  public:
    using intid = FieldModel<address, 0, 0x000001FF>;
  };

public:
  using stir = StirReg<BaseAddress + 0x0000>;
};

}

#endif /* DRAL_STM32F411_NVIC_STIR_H */
