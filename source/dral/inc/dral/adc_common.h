#ifndef DRAL_STM32F411_ADC_COMMON_H
#define DRAL_STM32F411_ADC_COMMON_H

#include "register_model.h"

namespace dral::stm32f411 {

class adc_common
{
public:
  static constexpr uint32_t BaseAddress = 0x40012300;

private:
  template <uint32_t address>
  class CsrReg: public RegisterModel<address>
  {
  public:
    using ovr3 = FieldModel<address, 21, 0x00000001>;
    using strt3 = FieldModel<address, 20, 0x00000001>;
    using jstrt3 = FieldModel<address, 19, 0x00000001>;
    using jeoc3 = FieldModel<address, 18, 0x00000001>;
    using eoc3 = FieldModel<address, 17, 0x00000001>;
    using awd3 = FieldModel<address, 16, 0x00000001>;
    using ovr2 = FieldModel<address, 13, 0x00000001>;
    using strt2 = FieldModel<address, 12, 0x00000001>;
    using jstrt2 = FieldModel<address, 11, 0x00000001>;
    using jeoc2 = FieldModel<address, 10, 0x00000001>;
    using eoc2 = FieldModel<address, 9, 0x00000001>;
    using awd2 = FieldModel<address, 8, 0x00000001>;
    using ovr1 = FieldModel<address, 5, 0x00000001>;
    using strt1 = FieldModel<address, 4, 0x00000001>;
    using jstrt1 = FieldModel<address, 3, 0x00000001>;
    using jeoc1 = FieldModel<address, 2, 0x00000001>;
    using eoc1 = FieldModel<address, 1, 0x00000001>;
    using awd1 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using csr = CsrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class CcrReg: public RegisterModel<address>
  {
  public:
    using tsvrefe = FieldModel<address, 23, 0x00000001>;
    using vbate = FieldModel<address, 22, 0x00000001>;
    using adcpre = FieldModel<address, 16, 0x00000003>;
    using dma = FieldModel<address, 14, 0x00000003>;
    using dds = FieldModel<address, 13, 0x00000001>;
    using delay = FieldModel<address, 8, 0x0000000F>;
  };

public:
  using ccr = CcrReg<BaseAddress + 0x0004>;
};

}

#endif /* DRAL_STM32F411_ADC_COMMON_H */
