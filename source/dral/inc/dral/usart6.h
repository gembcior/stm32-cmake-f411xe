#ifndef DRAL_STM32F411_USART6_H
#define DRAL_STM32F411_USART6_H

#include "register_model.h"

namespace dral::stm32f411 {

class usart6
{
public:
  static constexpr uint32_t BaseAddress = 0x40011400;

private:
  template <uint32_t address>
  class SrReg: public RegisterModel<address>
  {
  public:
    using cts = FieldModel<address,  9, 0x00000001>;
    using lbd = FieldModel<address,  8, 0x00000001>;
    using txe = FieldModel<address,  7, 0x00000001>;
    using tc = FieldModel<address,  6, 0x00000001>;
    using rxne = FieldModel<address,  5, 0x00000001>;
    using idle = FieldModel<address,  4, 0x00000001>;
    using ore = FieldModel<address,  3, 0x00000001>;
    using nf = FieldModel<address,  2, 0x00000001>;
    using fe = FieldModel<address,  1, 0x00000001>;
    using pe = FieldModel<address,  0, 0x00000001>;

  };

public:
  using sr = SrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class DrReg: public RegisterModel<address>
  {
  public:
    using dr = FieldModel<address,  0, 0x000001FF>;

  };

public:
  using dr = DrReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class BrrReg: public RegisterModel<address>
  {
  public:
    using div_mantissa = FieldModel<address,  4, 0x00000FFF>;
    using div_fraction = FieldModel<address,  0, 0x0000000F>;

  };

public:
  using brr = BrrReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class Cr1Reg: public RegisterModel<address>
  {
  public:
    using over8 = FieldModel<address, 15, 0x00000001>;
    using ue = FieldModel<address, 13, 0x00000001>;
    using m = FieldModel<address, 12, 0x00000001>;
    using wake = FieldModel<address, 11, 0x00000001>;
    using pce = FieldModel<address, 10, 0x00000001>;
    using ps = FieldModel<address,  9, 0x00000001>;
    using peie = FieldModel<address,  8, 0x00000001>;
    using txeie = FieldModel<address,  7, 0x00000001>;
    using tcie = FieldModel<address,  6, 0x00000001>;
    using rxneie = FieldModel<address,  5, 0x00000001>;
    using idleie = FieldModel<address,  4, 0x00000001>;
    using te = FieldModel<address,  3, 0x00000001>;
    using re = FieldModel<address,  2, 0x00000001>;
    using rwu = FieldModel<address,  1, 0x00000001>;
    using sbk = FieldModel<address,  0, 0x00000001>;

  };

public:
  using cr1 = Cr1Reg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class Cr2Reg: public RegisterModel<address>
  {
  public:
    using linen = FieldModel<address, 14, 0x00000001>;
    using stop = FieldModel<address, 12, 0x00000003>;
    using clken = FieldModel<address, 11, 0x00000001>;
    using cpol = FieldModel<address, 10, 0x00000001>;
    using cpha = FieldModel<address,  9, 0x00000001>;
    using lbcl = FieldModel<address,  8, 0x00000001>;
    using lbdie = FieldModel<address,  6, 0x00000001>;
    using lbdl = FieldModel<address,  5, 0x00000001>;
    using add = FieldModel<address,  0, 0x0000000F>;

  };

public:
  using cr2 = Cr2Reg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class Cr3Reg: public RegisterModel<address>
  {
  public:
    using onebit = FieldModel<address, 11, 0x00000001>;
    using ctsie = FieldModel<address, 10, 0x00000001>;
    using ctse = FieldModel<address,  9, 0x00000001>;
    using rtse = FieldModel<address,  8, 0x00000001>;
    using dmat = FieldModel<address,  7, 0x00000001>;
    using dmar = FieldModel<address,  6, 0x00000001>;
    using scen = FieldModel<address,  5, 0x00000001>;
    using nack = FieldModel<address,  4, 0x00000001>;
    using hdsel = FieldModel<address,  3, 0x00000001>;
    using irlp = FieldModel<address,  2, 0x00000001>;
    using iren = FieldModel<address,  1, 0x00000001>;
    using eie = FieldModel<address,  0, 0x00000001>;

  };

public:
  using cr3 = Cr3Reg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class GtprReg: public RegisterModel<address>
  {
  public:
    using gt = FieldModel<address,  8, 0x000000FF>;
    using psc = FieldModel<address,  0, 0x000000FF>;

  };

public:
  using gtpr = GtprReg<BaseAddress + 0x0018>;


};

}

#endif /* DRAL_STM32F411_USART6_H */
