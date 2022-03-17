#ifndef DRAL_STM32F411_FPU_H
#define DRAL_STM32F411_FPU_H

#include "register_model.h"

namespace dral::stm32f411 {

class fpu
{
public:
  static constexpr uint32_t BaseAddress = 0xE000EF34;

private:
  template <uint32_t address>
  class FpccrReg: public RegisterModel<address>
  {
  public:
    using lspact = FieldModel<address, 0, 0x00000001>;
    using user = FieldModel<address, 1, 0x00000001>;
    using thread = FieldModel<address, 3, 0x00000001>;
    using hfrdy = FieldModel<address, 4, 0x00000001>;
    using mmrdy = FieldModel<address, 5, 0x00000001>;
    using bfrdy = FieldModel<address, 6, 0x00000001>;
    using monrdy = FieldModel<address, 8, 0x00000001>;
    using lspen = FieldModel<address, 30, 0x00000001>;
    using aspen = FieldModel<address, 31, 0x00000001>;
  };

public:
  using fpccr = FpccrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class FpcarReg: public RegisterModel<address>
  {
  public:
    using address = FieldModel<address, 3, 0x1FFFFFFF>;
  };

public:
  using fpcar = FpcarReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class FpscrReg: public RegisterModel<address>
  {
  public:
    using ioc = FieldModel<address, 0, 0x00000001>;
    using dzc = FieldModel<address, 1, 0x00000001>;
    using ofc = FieldModel<address, 2, 0x00000001>;
    using ufc = FieldModel<address, 3, 0x00000001>;
    using ixc = FieldModel<address, 4, 0x00000001>;
    using idc = FieldModel<address, 7, 0x00000001>;
    using rmode = FieldModel<address, 22, 0x00000003>;
    using fz = FieldModel<address, 24, 0x00000001>;
    using dn = FieldModel<address, 25, 0x00000001>;
    using ahp = FieldModel<address, 26, 0x00000001>;
    using v = FieldModel<address, 28, 0x00000001>;
    using c = FieldModel<address, 29, 0x00000001>;
    using z = FieldModel<address, 30, 0x00000001>;
    using n = FieldModel<address, 31, 0x00000001>;
  };

public:
  using fpscr = FpscrReg<BaseAddress + 0x0008>;
};

}

#endif /* DRAL_STM32F411_FPU_H */
