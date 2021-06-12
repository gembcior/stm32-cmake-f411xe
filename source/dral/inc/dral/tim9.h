#ifndef DRAL_STM32F411_TIM9_H
#define DRAL_STM32F411_TIM9_H

#include "register_model.h"

namespace dral::stm32f411 {

class tim9
{
public:
  static constexpr uint32_t BaseAddress = 0x40014000;

private:
  template <uint32_t address>
  class Cr1Reg: public RegisterModel<address>
  {
  public:
    using ckd = FieldModel<address,  8, 0x00000003>;
    using arpe = FieldModel<address,  7, 0x00000001>;
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
    using mms = FieldModel<address,  4, 0x00000007>;

  };

public:
  using cr2 = Cr2Reg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class SmcrReg: public RegisterModel<address>
  {
  public:
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
    using tie = FieldModel<address,  6, 0x00000001>;
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
    using cc2of = FieldModel<address, 10, 0x00000001>;
    using cc1of = FieldModel<address,  9, 0x00000001>;
    using tif = FieldModel<address,  6, 0x00000001>;
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
    using oc2m = FieldModel<address, 12, 0x00000007>;
    using oc2pe = FieldModel<address, 11, 0x00000001>;
    using oc2fe = FieldModel<address, 10, 0x00000001>;
    using cc2s = FieldModel<address,  8, 0x00000003>;
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
    using ic2f = FieldModel<address, 12, 0x00000007>;
    using ic2pcs = FieldModel<address, 10, 0x00000003>;
    using cc2s = FieldModel<address,  8, 0x00000003>;
    using ic1f = FieldModel<address,  4, 0x00000007>;
    using icpcs = FieldModel<address,  2, 0x00000003>;
    using cc1s = FieldModel<address,  0, 0x00000003>;

  };

public:
  using ccmr1_input = Ccmr1_inputReg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class CcerReg: public RegisterModel<address>
  {
  public:
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
    using cnt = FieldModel<address,  0, 0x0000FFFF>;

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
    using arr = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using arr = ArrReg<BaseAddress + 0x002C>;

private:
  template <uint32_t address>
  class Ccr1Reg: public RegisterModel<address>
  {
  public:
    using ccr1 = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using ccr1 = Ccr1Reg<BaseAddress + 0x0034>;

private:
  template <uint32_t address>
  class Ccr2Reg: public RegisterModel<address>
  {
  public:
    using ccr2 = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using ccr2 = Ccr2Reg<BaseAddress + 0x0038>;


};

}

#endif /* DRAL_STM32F411_TIM9_H */
