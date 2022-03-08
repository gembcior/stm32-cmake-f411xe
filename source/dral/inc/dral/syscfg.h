#ifndef DRAL_STM32F411_SYSCFG_H
#define DRAL_STM32F411_SYSCFG_H

#include "register_model.h"

namespace dral::stm32f411 {

class syscfg
{
public:
  static constexpr uint32_t BaseAddress = 0x40013800;

private:
  template <uint32_t address>
  class MemrmReg: public RegisterModel<address>
  {
  public:
    using mem_mode = FieldModel<address, 0, 0x00000003>;
  };

public:
  using memrm = MemrmReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class PmcReg: public RegisterModel<address>
  {
  public:
    using adc1dc2 = FieldModel<address, 16, 0x00000001>;
  };

public:
  using pmc = PmcReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class Exticr1Reg: public RegisterModel<address>
  {
  public:
    using exti3 = FieldModel<address, 12, 0x0000000F>;
    using exti2 = FieldModel<address, 8, 0x0000000F>;
    using exti1 = FieldModel<address, 4, 0x0000000F>;
    using exti0 = FieldModel<address, 0, 0x0000000F>;
  };

public:
  using exticr1 = Exticr1Reg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class Exticr2Reg: public RegisterModel<address>
  {
  public:
    using exti7 = FieldModel<address, 12, 0x0000000F>;
    using exti6 = FieldModel<address, 8, 0x0000000F>;
    using exti5 = FieldModel<address, 4, 0x0000000F>;
    using exti4 = FieldModel<address, 0, 0x0000000F>;
  };

public:
  using exticr2 = Exticr2Reg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class Exticr3Reg: public RegisterModel<address>
  {
  public:
    using exti11 = FieldModel<address, 12, 0x0000000F>;
    using exti10 = FieldModel<address, 8, 0x0000000F>;
    using exti9 = FieldModel<address, 4, 0x0000000F>;
    using exti8 = FieldModel<address, 0, 0x0000000F>;
  };

public:
  using exticr3 = Exticr3Reg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class Exticr4Reg: public RegisterModel<address>
  {
  public:
    using exti15 = FieldModel<address, 12, 0x0000000F>;
    using exti14 = FieldModel<address, 8, 0x0000000F>;
    using exti13 = FieldModel<address, 4, 0x0000000F>;
    using exti12 = FieldModel<address, 0, 0x0000000F>;
  };

public:
  using exticr4 = Exticr4Reg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class CmpcrReg: public RegisterModel<address>
  {
  public:
    using ready = FieldModel<address, 8, 0x00000001>;
    using cmp_pd = FieldModel<address, 0, 0x00000001>;
  };

public:
  using cmpcr = CmpcrReg<BaseAddress + 0x0020>;
};

}

#endif /* DRAL_STM32F411_SYSCFG_H */
