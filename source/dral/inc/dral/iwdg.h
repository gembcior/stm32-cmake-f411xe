#ifndef DRAL_STM32F411_IWDG_H
#define DRAL_STM32F411_IWDG_H

#include "register_model.h"

namespace dral::stm32f411 {

class iwdg
{
public:
  static constexpr uint32_t BaseAddress = 0x40003000;

private:
  template <uint32_t address>
  class KrReg: public RegisterModel<address>
  {
  public:
    using key = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using kr = KrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class PrReg: public RegisterModel<address>
  {
  public:
    using pr = FieldModel<address,  0, 0x00000007>;

  };

public:
  using pr = PrReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class RlrReg: public RegisterModel<address>
  {
  public:
    using rl = FieldModel<address,  0, 0x00000FFF>;

  };

public:
  using rlr = RlrReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class SrReg: public RegisterModel<address>
  {
  public:
    using rvu = FieldModel<address,  1, 0x00000001>;
    using pvu = FieldModel<address,  0, 0x00000001>;

  };

public:
  using sr = SrReg<BaseAddress + 0x000C>;


};

}

#endif /* DRAL_STM32F411_IWDG_H */
