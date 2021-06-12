#ifndef DRAL_STM32F411_NVIC_H
#define DRAL_STM32F411_NVIC_H

#include "register_model.h"

namespace dral::stm32f411 {

class nvic
{
public:
  static constexpr uint32_t BaseAddress = 0xE000E100;

private:
  template <uint32_t address>
  class Iser0Reg: public RegisterModel<address>
  {
  public:
    using setena = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using iser0 = Iser0Reg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class Iser1Reg: public RegisterModel<address>
  {
  public:
    using setena = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using iser1 = Iser1Reg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class Iser2Reg: public RegisterModel<address>
  {
  public:
    using setena = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using iser2 = Iser2Reg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class Icer0Reg: public RegisterModel<address>
  {
  public:
    using clrena = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using icer0 = Icer0Reg<BaseAddress + 0x0080>;

private:
  template <uint32_t address>
  class Icer1Reg: public RegisterModel<address>
  {
  public:
    using clrena = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using icer1 = Icer1Reg<BaseAddress + 0x0084>;

private:
  template <uint32_t address>
  class Icer2Reg: public RegisterModel<address>
  {
  public:
    using clrena = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using icer2 = Icer2Reg<BaseAddress + 0x0088>;

private:
  template <uint32_t address>
  class Ispr0Reg: public RegisterModel<address>
  {
  public:
    using setpend = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using ispr0 = Ispr0Reg<BaseAddress + 0x0100>;

private:
  template <uint32_t address>
  class Ispr1Reg: public RegisterModel<address>
  {
  public:
    using setpend = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using ispr1 = Ispr1Reg<BaseAddress + 0x0104>;

private:
  template <uint32_t address>
  class Ispr2Reg: public RegisterModel<address>
  {
  public:
    using setpend = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using ispr2 = Ispr2Reg<BaseAddress + 0x0108>;

private:
  template <uint32_t address>
  class Icpr0Reg: public RegisterModel<address>
  {
  public:
    using clrpend = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using icpr0 = Icpr0Reg<BaseAddress + 0x0180>;

private:
  template <uint32_t address>
  class Icpr1Reg: public RegisterModel<address>
  {
  public:
    using clrpend = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using icpr1 = Icpr1Reg<BaseAddress + 0x0184>;

private:
  template <uint32_t address>
  class Icpr2Reg: public RegisterModel<address>
  {
  public:
    using clrpend = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using icpr2 = Icpr2Reg<BaseAddress + 0x0188>;

private:
  template <uint32_t address>
  class Iabr0Reg: public RegisterModel<address>
  {
  public:
    using active = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using iabr0 = Iabr0Reg<BaseAddress + 0x0200>;

private:
  template <uint32_t address>
  class Iabr1Reg: public RegisterModel<address>
  {
  public:
    using active = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using iabr1 = Iabr1Reg<BaseAddress + 0x0204>;

private:
  template <uint32_t address>
  class Iabr2Reg: public RegisterModel<address>
  {
  public:
    using active = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using iabr2 = Iabr2Reg<BaseAddress + 0x0208>;

private:
  template <uint32_t address>
  class Ipr0Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr0 = Ipr0Reg<BaseAddress + 0x0300>;

private:
  template <uint32_t address>
  class Ipr1Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr1 = Ipr1Reg<BaseAddress + 0x0304>;

private:
  template <uint32_t address>
  class Ipr2Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr2 = Ipr2Reg<BaseAddress + 0x0308>;

private:
  template <uint32_t address>
  class Ipr3Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr3 = Ipr3Reg<BaseAddress + 0x030C>;

private:
  template <uint32_t address>
  class Ipr4Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr4 = Ipr4Reg<BaseAddress + 0x0310>;

private:
  template <uint32_t address>
  class Ipr5Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr5 = Ipr5Reg<BaseAddress + 0x0314>;

private:
  template <uint32_t address>
  class Ipr6Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr6 = Ipr6Reg<BaseAddress + 0x0318>;

private:
  template <uint32_t address>
  class Ipr7Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr7 = Ipr7Reg<BaseAddress + 0x031C>;

private:
  template <uint32_t address>
  class Ipr8Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr8 = Ipr8Reg<BaseAddress + 0x0320>;

private:
  template <uint32_t address>
  class Ipr9Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr9 = Ipr9Reg<BaseAddress + 0x0324>;

private:
  template <uint32_t address>
  class Ipr10Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr10 = Ipr10Reg<BaseAddress + 0x0328>;

private:
  template <uint32_t address>
  class Ipr11Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr11 = Ipr11Reg<BaseAddress + 0x032C>;

private:
  template <uint32_t address>
  class Ipr12Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr12 = Ipr12Reg<BaseAddress + 0x0330>;

private:
  template <uint32_t address>
  class Ipr13Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr13 = Ipr13Reg<BaseAddress + 0x0334>;

private:
  template <uint32_t address>
  class Ipr14Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr14 = Ipr14Reg<BaseAddress + 0x0338>;

private:
  template <uint32_t address>
  class Ipr15Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr15 = Ipr15Reg<BaseAddress + 0x033C>;

private:
  template <uint32_t address>
  class Ipr16Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr16 = Ipr16Reg<BaseAddress + 0x0340>;

private:
  template <uint32_t address>
  class Ipr17Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr17 = Ipr17Reg<BaseAddress + 0x0344>;

private:
  template <uint32_t address>
  class Ipr18Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr18 = Ipr18Reg<BaseAddress + 0x0348>;

private:
  template <uint32_t address>
  class Ipr19Reg: public RegisterModel<address>
  {
  public:
    using ipr_n0 = FieldModel<address,  0, 0x000000FF>;
    using ipr_n1 = FieldModel<address,  8, 0x000000FF>;
    using ipr_n2 = FieldModel<address, 16, 0x000000FF>;
    using ipr_n3 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using ipr19 = Ipr19Reg<BaseAddress + 0x034C>;


};

}

#endif /* DRAL_STM32F411_NVIC_H */
