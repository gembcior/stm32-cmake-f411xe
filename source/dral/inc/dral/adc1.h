#ifndef DRAL_STM32F411_ADC1_H
#define DRAL_STM32F411_ADC1_H

#include "register_model.h"

namespace dral::stm32f411 {

class adc1
{
public:
  static constexpr uint32_t BaseAddress = 0x40012000;

private:
  template <uint32_t address>
  class SrReg: public RegisterModel<address>
  {
  public:
    using ovr = FieldModel<address,  5, 0x00000001>;
    using strt = FieldModel<address,  4, 0x00000001>;
    using jstrt = FieldModel<address,  3, 0x00000001>;
    using jeoc = FieldModel<address,  2, 0x00000001>;
    using eoc = FieldModel<address,  1, 0x00000001>;
    using awd = FieldModel<address,  0, 0x00000001>;

  };

public:
  using sr = SrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class Cr1Reg: public RegisterModel<address>
  {
  public:
    using ovrie = FieldModel<address, 26, 0x00000001>;
    using res = FieldModel<address, 24, 0x00000003>;
    using awden = FieldModel<address, 23, 0x00000001>;
    using jawden = FieldModel<address, 22, 0x00000001>;
    using discnum = FieldModel<address, 13, 0x00000007>;
    using jdiscen = FieldModel<address, 12, 0x00000001>;
    using discen = FieldModel<address, 11, 0x00000001>;
    using jauto = FieldModel<address, 10, 0x00000001>;
    using awdsgl = FieldModel<address,  9, 0x00000001>;
    using scan = FieldModel<address,  8, 0x00000001>;
    using jeocie = FieldModel<address,  7, 0x00000001>;
    using awdie = FieldModel<address,  6, 0x00000001>;
    using eocie = FieldModel<address,  5, 0x00000001>;
    using awdch = FieldModel<address,  0, 0x0000001F>;

  };

public:
  using cr1 = Cr1Reg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class Cr2Reg: public RegisterModel<address>
  {
  public:
    using swstart = FieldModel<address, 30, 0x00000001>;
    using exten = FieldModel<address, 28, 0x00000003>;
    using extsel = FieldModel<address, 24, 0x0000000F>;
    using jswstart = FieldModel<address, 22, 0x00000001>;
    using jexten = FieldModel<address, 20, 0x00000003>;
    using jextsel = FieldModel<address, 16, 0x0000000F>;
    using align = FieldModel<address, 11, 0x00000001>;
    using eocs = FieldModel<address, 10, 0x00000001>;
    using dds = FieldModel<address,  9, 0x00000001>;
    using dma = FieldModel<address,  8, 0x00000001>;
    using cont = FieldModel<address,  1, 0x00000001>;
    using adon = FieldModel<address,  0, 0x00000001>;

  };

public:
  using cr2 = Cr2Reg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class Smpr1Reg: public RegisterModel<address>
  {
  public:
    using smpx_x = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using smpr1 = Smpr1Reg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class Smpr2Reg: public RegisterModel<address>
  {
  public:
    using smpx_x = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using smpr2 = Smpr2Reg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class Jofr1Reg: public RegisterModel<address>
  {
  public:
    using joffset1 = FieldModel<address,  0, 0x00000FFF>;

  };

public:
  using jofr1 = Jofr1Reg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class Jofr2Reg: public RegisterModel<address>
  {
  public:
    using joffset2 = FieldModel<address,  0, 0x00000FFF>;

  };

public:
  using jofr2 = Jofr2Reg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class Jofr3Reg: public RegisterModel<address>
  {
  public:
    using joffset3 = FieldModel<address,  0, 0x00000FFF>;

  };

public:
  using jofr3 = Jofr3Reg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class Jofr4Reg: public RegisterModel<address>
  {
  public:
    using joffset4 = FieldModel<address,  0, 0x00000FFF>;

  };

public:
  using jofr4 = Jofr4Reg<BaseAddress + 0x0020>;

private:
  template <uint32_t address>
  class HtrReg: public RegisterModel<address>
  {
  public:
    using ht = FieldModel<address,  0, 0x00000FFF>;

  };

public:
  using htr = HtrReg<BaseAddress + 0x0024>;

private:
  template <uint32_t address>
  class LtrReg: public RegisterModel<address>
  {
  public:
    using lt = FieldModel<address,  0, 0x00000FFF>;

  };

public:
  using ltr = LtrReg<BaseAddress + 0x0028>;

private:
  template <uint32_t address>
  class Sqr1Reg: public RegisterModel<address>
  {
  public:
    using l = FieldModel<address, 20, 0x0000000F>;
    using sq16 = FieldModel<address, 15, 0x0000001F>;
    using sq15 = FieldModel<address, 10, 0x0000001F>;
    using sq14 = FieldModel<address,  5, 0x0000001F>;
    using sq13 = FieldModel<address,  0, 0x0000001F>;

  };

public:
  using sqr1 = Sqr1Reg<BaseAddress + 0x002C>;

private:
  template <uint32_t address>
  class Sqr2Reg: public RegisterModel<address>
  {
  public:
    using sq12 = FieldModel<address, 25, 0x0000001F>;
    using sq11 = FieldModel<address, 20, 0x0000001F>;
    using sq10 = FieldModel<address, 15, 0x0000001F>;
    using sq9 = FieldModel<address, 10, 0x0000001F>;
    using sq8 = FieldModel<address,  5, 0x0000001F>;
    using sq7 = FieldModel<address,  0, 0x0000001F>;

  };

public:
  using sqr2 = Sqr2Reg<BaseAddress + 0x0030>;

private:
  template <uint32_t address>
  class Sqr3Reg: public RegisterModel<address>
  {
  public:
    using sq6 = FieldModel<address, 25, 0x0000001F>;
    using sq5 = FieldModel<address, 20, 0x0000001F>;
    using sq4 = FieldModel<address, 15, 0x0000001F>;
    using sq3 = FieldModel<address, 10, 0x0000001F>;
    using sq2 = FieldModel<address,  5, 0x0000001F>;
    using sq1 = FieldModel<address,  0, 0x0000001F>;

  };

public:
  using sqr3 = Sqr3Reg<BaseAddress + 0x0034>;

private:
  template <uint32_t address>
  class JsqrReg: public RegisterModel<address>
  {
  public:
    using jl = FieldModel<address, 20, 0x00000003>;
    using jsq4 = FieldModel<address, 15, 0x0000001F>;
    using jsq3 = FieldModel<address, 10, 0x0000001F>;
    using jsq2 = FieldModel<address,  5, 0x0000001F>;
    using jsq1 = FieldModel<address,  0, 0x0000001F>;

  };

public:
  using jsqr = JsqrReg<BaseAddress + 0x0038>;

private:
  template <uint32_t address>
  class Jdr1Reg: public RegisterModel<address>
  {
  public:
    using jdata = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using jdr1 = Jdr1Reg<BaseAddress + 0x003C>;

private:
  template <uint32_t address>
  class Jdr2Reg: public RegisterModel<address>
  {
  public:
    using jdata = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using jdr2 = Jdr2Reg<BaseAddress + 0x0040>;

private:
  template <uint32_t address>
  class Jdr3Reg: public RegisterModel<address>
  {
  public:
    using jdata = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using jdr3 = Jdr3Reg<BaseAddress + 0x0044>;

private:
  template <uint32_t address>
  class Jdr4Reg: public RegisterModel<address>
  {
  public:
    using jdata = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using jdr4 = Jdr4Reg<BaseAddress + 0x0048>;

private:
  template <uint32_t address>
  class DrReg: public RegisterModel<address>
  {
  public:
    using data = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using dr = DrReg<BaseAddress + 0x004C>;


};

}

#endif /* DRAL_STM32F411_ADC1_H */
