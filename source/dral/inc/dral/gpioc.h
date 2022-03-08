#ifndef DRAL_STM32F411_GPIOC_H
#define DRAL_STM32F411_GPIOC_H

#include "register_model.h"

namespace dral::stm32f411 {

class gpioc
{
public:
  static constexpr uint32_t BaseAddress = 0x40020800;

private:
  template <uint32_t address>
  class ModerReg: public RegisterModel<address>
  {
  public:
    using moder15 = FieldModel<address, 30, 0x00000003>;
    using moder14 = FieldModel<address, 28, 0x00000003>;
    using moder13 = FieldModel<address, 26, 0x00000003>;
    using moder12 = FieldModel<address, 24, 0x00000003>;
    using moder11 = FieldModel<address, 22, 0x00000003>;
    using moder10 = FieldModel<address, 20, 0x00000003>;
    using moder9 = FieldModel<address, 18, 0x00000003>;
    using moder8 = FieldModel<address, 16, 0x00000003>;
    using moder7 = FieldModel<address, 14, 0x00000003>;
    using moder6 = FieldModel<address, 12, 0x00000003>;
    using moder5 = FieldModel<address, 10, 0x00000003>;
    using moder4 = FieldModel<address, 8, 0x00000003>;
    using moder3 = FieldModel<address, 6, 0x00000003>;
    using moder2 = FieldModel<address, 4, 0x00000003>;
    using moder1 = FieldModel<address, 2, 0x00000003>;
    using moder0 = FieldModel<address, 0, 0x00000003>;
  };

public:
  using moder = ModerReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class OtyperReg: public RegisterModel<address>
  {
  public:
    using ot15 = FieldModel<address, 15, 0x00000001>;
    using ot14 = FieldModel<address, 14, 0x00000001>;
    using ot13 = FieldModel<address, 13, 0x00000001>;
    using ot12 = FieldModel<address, 12, 0x00000001>;
    using ot11 = FieldModel<address, 11, 0x00000001>;
    using ot10 = FieldModel<address, 10, 0x00000001>;
    using ot9 = FieldModel<address, 9, 0x00000001>;
    using ot8 = FieldModel<address, 8, 0x00000001>;
    using ot7 = FieldModel<address, 7, 0x00000001>;
    using ot6 = FieldModel<address, 6, 0x00000001>;
    using ot5 = FieldModel<address, 5, 0x00000001>;
    using ot4 = FieldModel<address, 4, 0x00000001>;
    using ot3 = FieldModel<address, 3, 0x00000001>;
    using ot2 = FieldModel<address, 2, 0x00000001>;
    using ot1 = FieldModel<address, 1, 0x00000001>;
    using ot0 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using otyper = OtyperReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class OspeedrReg: public RegisterModel<address>
  {
  public:
    using ospeedr15 = FieldModel<address, 30, 0x00000003>;
    using ospeedr14 = FieldModel<address, 28, 0x00000003>;
    using ospeedr13 = FieldModel<address, 26, 0x00000003>;
    using ospeedr12 = FieldModel<address, 24, 0x00000003>;
    using ospeedr11 = FieldModel<address, 22, 0x00000003>;
    using ospeedr10 = FieldModel<address, 20, 0x00000003>;
    using ospeedr9 = FieldModel<address, 18, 0x00000003>;
    using ospeedr8 = FieldModel<address, 16, 0x00000003>;
    using ospeedr7 = FieldModel<address, 14, 0x00000003>;
    using ospeedr6 = FieldModel<address, 12, 0x00000003>;
    using ospeedr5 = FieldModel<address, 10, 0x00000003>;
    using ospeedr4 = FieldModel<address, 8, 0x00000003>;
    using ospeedr3 = FieldModel<address, 6, 0x00000003>;
    using ospeedr2 = FieldModel<address, 4, 0x00000003>;
    using ospeedr1 = FieldModel<address, 2, 0x00000003>;
    using ospeedr0 = FieldModel<address, 0, 0x00000003>;
  };

public:
  using ospeedr = OspeedrReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class PupdrReg: public RegisterModel<address>
  {
  public:
    using pupdr15 = FieldModel<address, 30, 0x00000003>;
    using pupdr14 = FieldModel<address, 28, 0x00000003>;
    using pupdr13 = FieldModel<address, 26, 0x00000003>;
    using pupdr12 = FieldModel<address, 24, 0x00000003>;
    using pupdr11 = FieldModel<address, 22, 0x00000003>;
    using pupdr10 = FieldModel<address, 20, 0x00000003>;
    using pupdr9 = FieldModel<address, 18, 0x00000003>;
    using pupdr8 = FieldModel<address, 16, 0x00000003>;
    using pupdr7 = FieldModel<address, 14, 0x00000003>;
    using pupdr6 = FieldModel<address, 12, 0x00000003>;
    using pupdr5 = FieldModel<address, 10, 0x00000003>;
    using pupdr4 = FieldModel<address, 8, 0x00000003>;
    using pupdr3 = FieldModel<address, 6, 0x00000003>;
    using pupdr2 = FieldModel<address, 4, 0x00000003>;
    using pupdr1 = FieldModel<address, 2, 0x00000003>;
    using pupdr0 = FieldModel<address, 0, 0x00000003>;
  };

public:
  using pupdr = PupdrReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class IdrReg: public RegisterModel<address>
  {
  public:
    using idr15 = FieldModel<address, 15, 0x00000001>;
    using idr14 = FieldModel<address, 14, 0x00000001>;
    using idr13 = FieldModel<address, 13, 0x00000001>;
    using idr12 = FieldModel<address, 12, 0x00000001>;
    using idr11 = FieldModel<address, 11, 0x00000001>;
    using idr10 = FieldModel<address, 10, 0x00000001>;
    using idr9 = FieldModel<address, 9, 0x00000001>;
    using idr8 = FieldModel<address, 8, 0x00000001>;
    using idr7 = FieldModel<address, 7, 0x00000001>;
    using idr6 = FieldModel<address, 6, 0x00000001>;
    using idr5 = FieldModel<address, 5, 0x00000001>;
    using idr4 = FieldModel<address, 4, 0x00000001>;
    using idr3 = FieldModel<address, 3, 0x00000001>;
    using idr2 = FieldModel<address, 2, 0x00000001>;
    using idr1 = FieldModel<address, 1, 0x00000001>;
    using idr0 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using idr = IdrReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class OdrReg: public RegisterModel<address>
  {
  public:
    using odr15 = FieldModel<address, 15, 0x00000001>;
    using odr14 = FieldModel<address, 14, 0x00000001>;
    using odr13 = FieldModel<address, 13, 0x00000001>;
    using odr12 = FieldModel<address, 12, 0x00000001>;
    using odr11 = FieldModel<address, 11, 0x00000001>;
    using odr10 = FieldModel<address, 10, 0x00000001>;
    using odr9 = FieldModel<address, 9, 0x00000001>;
    using odr8 = FieldModel<address, 8, 0x00000001>;
    using odr7 = FieldModel<address, 7, 0x00000001>;
    using odr6 = FieldModel<address, 6, 0x00000001>;
    using odr5 = FieldModel<address, 5, 0x00000001>;
    using odr4 = FieldModel<address, 4, 0x00000001>;
    using odr3 = FieldModel<address, 3, 0x00000001>;
    using odr2 = FieldModel<address, 2, 0x00000001>;
    using odr1 = FieldModel<address, 1, 0x00000001>;
    using odr0 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using odr = OdrReg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class BsrrReg: public RegisterModel<address>
  {
  public:
    using br15 = FieldModel<address, 31, 0x00000001>;
    using br14 = FieldModel<address, 30, 0x00000001>;
    using br13 = FieldModel<address, 29, 0x00000001>;
    using br12 = FieldModel<address, 28, 0x00000001>;
    using br11 = FieldModel<address, 27, 0x00000001>;
    using br10 = FieldModel<address, 26, 0x00000001>;
    using br9 = FieldModel<address, 25, 0x00000001>;
    using br8 = FieldModel<address, 24, 0x00000001>;
    using br7 = FieldModel<address, 23, 0x00000001>;
    using br6 = FieldModel<address, 22, 0x00000001>;
    using br5 = FieldModel<address, 21, 0x00000001>;
    using br4 = FieldModel<address, 20, 0x00000001>;
    using br3 = FieldModel<address, 19, 0x00000001>;
    using br2 = FieldModel<address, 18, 0x00000001>;
    using br1 = FieldModel<address, 17, 0x00000001>;
    using br0 = FieldModel<address, 16, 0x00000001>;
    using bs15 = FieldModel<address, 15, 0x00000001>;
    using bs14 = FieldModel<address, 14, 0x00000001>;
    using bs13 = FieldModel<address, 13, 0x00000001>;
    using bs12 = FieldModel<address, 12, 0x00000001>;
    using bs11 = FieldModel<address, 11, 0x00000001>;
    using bs10 = FieldModel<address, 10, 0x00000001>;
    using bs9 = FieldModel<address, 9, 0x00000001>;
    using bs8 = FieldModel<address, 8, 0x00000001>;
    using bs7 = FieldModel<address, 7, 0x00000001>;
    using bs6 = FieldModel<address, 6, 0x00000001>;
    using bs5 = FieldModel<address, 5, 0x00000001>;
    using bs4 = FieldModel<address, 4, 0x00000001>;
    using bs3 = FieldModel<address, 3, 0x00000001>;
    using bs2 = FieldModel<address, 2, 0x00000001>;
    using bs1 = FieldModel<address, 1, 0x00000001>;
    using bs0 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using bsrr = BsrrReg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class LckrReg: public RegisterModel<address>
  {
  public:
    using lckk = FieldModel<address, 16, 0x00000001>;
    using lck15 = FieldModel<address, 15, 0x00000001>;
    using lck14 = FieldModel<address, 14, 0x00000001>;
    using lck13 = FieldModel<address, 13, 0x00000001>;
    using lck12 = FieldModel<address, 12, 0x00000001>;
    using lck11 = FieldModel<address, 11, 0x00000001>;
    using lck10 = FieldModel<address, 10, 0x00000001>;
    using lck9 = FieldModel<address, 9, 0x00000001>;
    using lck8 = FieldModel<address, 8, 0x00000001>;
    using lck7 = FieldModel<address, 7, 0x00000001>;
    using lck6 = FieldModel<address, 6, 0x00000001>;
    using lck5 = FieldModel<address, 5, 0x00000001>;
    using lck4 = FieldModel<address, 4, 0x00000001>;
    using lck3 = FieldModel<address, 3, 0x00000001>;
    using lck2 = FieldModel<address, 2, 0x00000001>;
    using lck1 = FieldModel<address, 1, 0x00000001>;
    using lck0 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using lckr = LckrReg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class AfrlReg: public RegisterModel<address>
  {
  public:
    using afrl7 = FieldModel<address, 28, 0x0000000F>;
    using afrl6 = FieldModel<address, 24, 0x0000000F>;
    using afrl5 = FieldModel<address, 20, 0x0000000F>;
    using afrl4 = FieldModel<address, 16, 0x0000000F>;
    using afrl3 = FieldModel<address, 12, 0x0000000F>;
    using afrl2 = FieldModel<address, 8, 0x0000000F>;
    using afrl1 = FieldModel<address, 4, 0x0000000F>;
    using afrl0 = FieldModel<address, 0, 0x0000000F>;
  };

public:
  using afrl = AfrlReg<BaseAddress + 0x0020>;

private:
  template <uint32_t address>
  class AfrhReg: public RegisterModel<address>
  {
  public:
    using afrh15 = FieldModel<address, 28, 0x0000000F>;
    using afrh14 = FieldModel<address, 24, 0x0000000F>;
    using afrh13 = FieldModel<address, 20, 0x0000000F>;
    using afrh12 = FieldModel<address, 16, 0x0000000F>;
    using afrh11 = FieldModel<address, 12, 0x0000000F>;
    using afrh10 = FieldModel<address, 8, 0x0000000F>;
    using afrh9 = FieldModel<address, 4, 0x0000000F>;
    using afrh8 = FieldModel<address, 0, 0x0000000F>;
  };

public:
  using afrh = AfrhReg<BaseAddress + 0x0024>;
};

}

#endif /* DRAL_STM32F411_GPIOC_H */
