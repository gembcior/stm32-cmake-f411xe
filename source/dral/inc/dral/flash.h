#ifndef DRAL_STM32F411_FLASH_H
#define DRAL_STM32F411_FLASH_H

#include "register_model.h"

namespace dral::stm32f411 {

class flash
{
public:
  static constexpr uint32_t BaseAddress = 0x40023C00;

private:
  template <uint32_t address>
  class AcrReg: public RegisterModel<address>
  {
  public:
    using latency = FieldModel<address, 0, 0x00000007>;
    using prften = FieldModel<address, 8, 0x00000001>;
    using icen = FieldModel<address, 9, 0x00000001>;
    using dcen = FieldModel<address, 10, 0x00000001>;
    using icrst = FieldModel<address, 11, 0x00000001>;
    using dcrst = FieldModel<address, 12, 0x00000001>;
  };

public:
  using acr = AcrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class KeyrReg: public RegisterModel<address>
  {
  public:
    using key = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using keyr = KeyrReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class OptkeyrReg: public RegisterModel<address>
  {
  public:
    using optkey = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using optkeyr = OptkeyrReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class SrReg: public RegisterModel<address>
  {
  public:
    using eop = FieldModel<address, 0, 0x00000001>;
    using operr = FieldModel<address, 1, 0x00000001>;
    using wrperr = FieldModel<address, 4, 0x00000001>;
    using pgaerr = FieldModel<address, 5, 0x00000001>;
    using pgperr = FieldModel<address, 6, 0x00000001>;
    using pgserr = FieldModel<address, 7, 0x00000001>;
    using bsy = FieldModel<address, 16, 0x00000001>;
  };

public:
  using sr = SrReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class CrReg: public RegisterModel<address>
  {
  public:
    using pg = FieldModel<address, 0, 0x00000001>;
    using ser = FieldModel<address, 1, 0x00000001>;
    using mer = FieldModel<address, 2, 0x00000001>;
    using snb = FieldModel<address, 3, 0x0000000F>;
    using psize = FieldModel<address, 8, 0x00000003>;
    using strt = FieldModel<address, 16, 0x00000001>;
    using eopie = FieldModel<address, 24, 0x00000001>;
    using errie = FieldModel<address, 25, 0x00000001>;
    using lock = FieldModel<address, 31, 0x00000001>;
  };

public:
  using cr = CrReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class OptcrReg: public RegisterModel<address>
  {
  public:
    using optlock = FieldModel<address, 0, 0x00000001>;
    using optstrt = FieldModel<address, 1, 0x00000001>;
    using bor_lev = FieldModel<address, 2, 0x00000003>;
    using wdg_sw = FieldModel<address, 5, 0x00000001>;
    using nrst_stop = FieldModel<address, 6, 0x00000001>;
    using nrst_stdby = FieldModel<address, 7, 0x00000001>;
    using rdp = FieldModel<address, 8, 0x000000FF>;
    using nwrp = FieldModel<address, 16, 0x00000FFF>;
  };

public:
  using optcr = OptcrReg<BaseAddress + 0x0014>;
};

}

#endif /* DRAL_STM32F411_FLASH_H */
