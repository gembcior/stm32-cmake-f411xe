#ifndef DRAL_STM32F411_PWR_H
#define DRAL_STM32F411_PWR_H

#include "register_model.h"

namespace dral::stm32f411 {

class pwr
{
public:
  static constexpr uint32_t BaseAddress = 0x40007000;

private:
  template <uint32_t address>
  class CrReg: public RegisterModel<address>
  {
  public:
    using vos = FieldModel<address, 14, 0x00000003>;
    using adcdc1 = FieldModel<address, 13, 0x00000001>;
    using fpds = FieldModel<address,  9, 0x00000001>;
    using dbp = FieldModel<address,  8, 0x00000001>;
    using pls = FieldModel<address,  5, 0x00000007>;
    using pvde = FieldModel<address,  4, 0x00000001>;
    using csbf = FieldModel<address,  3, 0x00000001>;
    using cwuf = FieldModel<address,  2, 0x00000001>;
    using pdds = FieldModel<address,  1, 0x00000001>;
    using lpds = FieldModel<address,  0, 0x00000001>;

  };

public:
  using cr = CrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class CsrReg: public RegisterModel<address>
  {
  public:
    using wuf = FieldModel<address,  0, 0x00000001>;
    using sbf = FieldModel<address,  1, 0x00000001>;
    using pvdo = FieldModel<address,  2, 0x00000001>;
    using brr = FieldModel<address,  3, 0x00000001>;
    using ewup = FieldModel<address,  8, 0x00000001>;
    using bre = FieldModel<address,  9, 0x00000001>;
    using vosrdy = FieldModel<address, 14, 0x00000001>;

  };

public:
  using csr = CsrReg<BaseAddress + 0x0004>;


};

}

#endif /* DRAL_STM32F411_PWR_H */
