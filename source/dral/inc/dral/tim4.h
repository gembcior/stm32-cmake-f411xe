#ifndef DRAL_STM32F411_TIM4_H
#define DRAL_STM32F411_TIM4_H

#include "register_model.h"

namespace dral::stm32f411 {

class tim4
{
public:
  static constexpr uint32_t BaseAddress = 0x40000800;

private:
  template <uint32_t address>
  class Cr1Reg: public RegisterModel<address>
  {
  public:
    using ckd = FieldModel<address,  8, 0x00000003>;
    using arpe = FieldModel<address,  7, 0x00000001>;
    using cms = FieldModel<address,  5, 0x00000003>;
    using dir = FieldModel<address,  4, 0x00000001>;
    using opm = FieldModel<address,  3, 0x00000001>;
    using urs = FieldModel<address,  2, 0x00000001>;
    using udis = FieldModel<address,  1, 0x00000001>;
    using cen = FieldModel<address,  0, 0x00000001>;

  };

public:
  using cr1 = Cr1Reg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class Cr2Reg: public RegisterModel<address>
  {
  public:
    using ti1s = FieldModel<address,  7, 0x00000001>;
    using mms = FieldModel<address,  4, 0x00000007>;
    using ccds = FieldModel<address,  3, 0x00000001>;

  };

public:
  using cr2 = Cr2Reg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class SmcrReg: public RegisterModel<address>
  {
  public:
    using etp = FieldModel<address, 15, 0x00000001>;
    using ece = FieldModel<address, 14, 0x00000001>;
    using etps = FieldModel<address, 12, 0x00000003>;
    using etf = FieldModel<address,  8, 0x0000000F>;
    using msm = FieldModel<address,  7, 0x00000001>;
    using ts = FieldModel<address,  4, 0x00000007>;
    using sms = FieldModel<address,  0, 0x00000007>;

  };

public:
  using smcr = SmcrReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class DierReg: public RegisterModel<address>
  {
  public:
    using tde = FieldModel<address, 14, 0x00000001>;
    using cc4de = FieldModel<address, 12, 0x00000001>;
    using cc3de = FieldModel<address, 11, 0x00000001>;
    using cc2de = FieldModel<address, 10, 0x00000001>;
    using cc1de = FieldModel<address,  9, 0x00000001>;
    using ude = FieldModel<address,  8, 0x00000001>;
    using tie = FieldModel<address,  6, 0x00000001>;
    using cc4ie = FieldModel<address,  4, 0x00000001>;
    using cc3ie = FieldModel<address,  3, 0x00000001>;
    using cc2ie = FieldModel<address,  2, 0x00000001>;
    using cc1ie = FieldModel<address,  1, 0x00000001>;
    using uie = FieldModel<address,  0, 0x00000001>;

  };

public:
  using dier = DierReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class SrReg: public RegisterModel<address>
  {
  public:
    using cc4of = FieldModel<address, 12, 0x00000001>;
    using cc3of = FieldModel<address, 11, 0x00000001>;
    using cc2of = FieldModel<address, 10, 0x00000001>;
    using cc1of = FieldModel<address,  9, 0x00000001>;
    using tif = FieldModel<address,  6, 0x00000001>;
    using cc4if = FieldModel<address,  4, 0x00000001>;
    using cc3if = FieldModel<address,  3, 0x00000001>;
    using cc2if = FieldModel<address,  2, 0x00000001>;
    using cc1if = FieldModel<address,  1, 0x00000001>;
    using uif = FieldModel<address,  0, 0x00000001>;

  };

public:
  using sr = SrReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class EgrReg: public RegisterModel<address>
  {
  public:
    using tg = FieldModel<address,  6, 0x00000001>;
    using cc4g = FieldModel<address,  4, 0x00000001>;
    using cc3g = FieldModel<address,  3, 0x00000001>;
    using cc2g = FieldModel<address,  2, 0x00000001>;
    using cc1g = FieldModel<address,  1, 0x00000001>;
    using ug = FieldModel<address,  0, 0x00000001>;

  };

public:
  using egr = EgrReg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class Ccmr1_outputReg: public RegisterModel<address>
  {
  public:
    using oc2ce = FieldModel<address, 15, 0x00000001>;
    using oc2m = FieldModel<address, 12, 0x00000007>;
    using oc2pe = FieldModel<address, 11, 0x00000001>;
    using oc2fe = FieldModel<address, 10, 0x00000001>;
    using cc2s = FieldModel<address,  8, 0x00000003>;
    using oc1ce = FieldModel<address,  7, 0x00000001>;
    using oc1m = FieldModel<address,  4, 0x00000007>;
    using oc1pe = FieldModel<address,  3, 0x00000001>;
    using oc1fe = FieldModel<address,  2, 0x00000001>;
    using cc1s = FieldModel<address,  0, 0x00000003>;

  };

public:
  using ccmr1_output = Ccmr1_outputReg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class Ccmr1_inputReg: public RegisterModel<address>
  {
  public:
    using ic2f = FieldModel<address, 12, 0x0000000F>;
    using ic2pcs = FieldModel<address, 10, 0x00000003>;
    using cc2s = FieldModel<address,  8, 0x00000003>;
    using ic1f = FieldModel<address,  4, 0x0000000F>;
    using icpcs = FieldModel<address,  2, 0x00000003>;
    using cc1s = FieldModel<address,  0, 0x00000003>;

  };

public:
  using ccmr1_input = Ccmr1_inputReg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class Ccmr2_outputReg: public RegisterModel<address>
  {
  public:
    using o24ce = FieldModel<address, 15, 0x00000001>;
    using oc4m = FieldModel<address, 12, 0x00000007>;
    using oc4pe = FieldModel<address, 11, 0x00000001>;
    using oc4fe = FieldModel<address, 10, 0x00000001>;
    using cc4s = FieldModel<address,  8, 0x00000003>;
    using oc3ce = FieldModel<address,  7, 0x00000001>;
    using oc3m = FieldModel<address,  4, 0x00000007>;
    using oc3pe = FieldModel<address,  3, 0x00000001>;
    using oc3fe = FieldModel<address,  2, 0x00000001>;
    using cc3s = FieldModel<address,  0, 0x00000003>;

  };

public:
  using ccmr2_output = Ccmr2_outputReg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class Ccmr2_inputReg: public RegisterModel<address>
  {
  public:
    using ic4f = FieldModel<address, 12, 0x0000000F>;
    using ic4psc = FieldModel<address, 10, 0x00000003>;
    using cc4s = FieldModel<address,  8, 0x00000003>;
    using ic3f = FieldModel<address,  4, 0x0000000F>;
    using ic3psc = FieldModel<address,  2, 0x00000003>;
    using cc3s = FieldModel<address,  0, 0x00000003>;

  };

public:
  using ccmr2_input = Ccmr2_inputReg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class CcerReg: public RegisterModel<address>
  {
  public:
    using cc4np = FieldModel<address, 15, 0x00000001>;
    using cc4p = FieldModel<address, 13, 0x00000001>;
    using cc4e = FieldModel<address, 12, 0x00000001>;
    using cc3np = FieldModel<address, 11, 0x00000001>;
    using cc3p = FieldModel<address,  9, 0x00000001>;
    using cc3e = FieldModel<address,  8, 0x00000001>;
    using cc2np = FieldModel<address,  7, 0x00000001>;
    using cc2p = FieldModel<address,  5, 0x00000001>;
    using cc2e = FieldModel<address,  4, 0x00000001>;
    using cc1np = FieldModel<address,  3, 0x00000001>;
    using cc1p = FieldModel<address,  1, 0x00000001>;
    using cc1e = FieldModel<address,  0, 0x00000001>;

  };

public:
  using ccer = CcerReg<BaseAddress + 0x0020>;

private:
  template <uint32_t address>
  class CntReg: public RegisterModel<address>
  {
  public:
    using cnt_h = FieldModel<address, 16, 0x0000FFFF>;
    using cnt_l = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using cnt = CntReg<BaseAddress + 0x0024>;

private:
  template <uint32_t address>
  class PscReg: public RegisterModel<address>
  {
  public:
    using psc = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using psc = PscReg<BaseAddress + 0x0028>;

private:
  template <uint32_t address>
  class ArrReg: public RegisterModel<address>
  {
  public:
    using arr_h = FieldModel<address, 16, 0x0000FFFF>;
    using arr_l = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using arr = ArrReg<BaseAddress + 0x002C>;

private:
  template <uint32_t address>
  class Ccr1Reg: public RegisterModel<address>
  {
  public:
    using ccr1_h = FieldModel<address, 16, 0x0000FFFF>;
    using ccr1_l = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using ccr1 = Ccr1Reg<BaseAddress + 0x0034>;

private:
  template <uint32_t address>
  class Ccr2Reg: public RegisterModel<address>
  {
  public:
    using ccr2_h = FieldModel<address, 16, 0x0000FFFF>;
    using ccr2_l = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using ccr2 = Ccr2Reg<BaseAddress + 0x0038>;

private:
  template <uint32_t address>
  class Ccr3Reg: public RegisterModel<address>
  {
  public:
    using ccr3_h = FieldModel<address, 16, 0x0000FFFF>;
    using ccr3_l = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using ccr3 = Ccr3Reg<BaseAddress + 0x003C>;

private:
  template <uint32_t address>
  class Ccr4Reg: public RegisterModel<address>
  {
  public:
    using ccr4_h = FieldModel<address, 16, 0x0000FFFF>;
    using ccr4_l = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using ccr4 = Ccr4Reg<BaseAddress + 0x0040>;

private:
  template <uint32_t address>
  class DcrReg: public RegisterModel<address>
  {
  public:
    using dbl = FieldModel<address,  8, 0x0000001F>;
    using dba = FieldModel<address,  0, 0x0000001F>;

  };

public:
  using dcr = DcrReg<BaseAddress + 0x0048>;

private:
  template <uint32_t address>
  class DmarReg: public RegisterModel<address>
  {
  public:
    using dmab = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using dmar = DmarReg<BaseAddress + 0x004C>;


};

}

#endif /* DRAL_STM32F411_TIM4_H */
