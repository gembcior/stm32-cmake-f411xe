#ifndef DRAL_STM32F411_SPI1_H
#define DRAL_STM32F411_SPI1_H

#include "register_model.h"

namespace dral::stm32f411 {

class spi1
{
public:
  static constexpr uint32_t BaseAddress = 0x40013000;

private:
  template <uint32_t address>
  class Cr1Reg: public RegisterModel<address>
  {
  public:
    using bidimode = FieldModel<address, 15, 0x00000001>;
    using bidioe = FieldModel<address, 14, 0x00000001>;
    using crcen = FieldModel<address, 13, 0x00000001>;
    using crcnext = FieldModel<address, 12, 0x00000001>;
    using dff = FieldModel<address, 11, 0x00000001>;
    using rxonly = FieldModel<address, 10, 0x00000001>;
    using ssm = FieldModel<address, 9, 0x00000001>;
    using ssi = FieldModel<address, 8, 0x00000001>;
    using lsbfirst = FieldModel<address, 7, 0x00000001>;
    using spe = FieldModel<address, 6, 0x00000001>;
    using br = FieldModel<address, 3, 0x00000007>;
    using mstr = FieldModel<address, 2, 0x00000001>;
    using cpol = FieldModel<address, 1, 0x00000001>;
    using cpha = FieldModel<address, 0, 0x00000001>;
  };

public:
  using cr1 = Cr1Reg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class Cr2Reg: public RegisterModel<address>
  {
  public:
    using txeie = FieldModel<address, 7, 0x00000001>;
    using rxneie = FieldModel<address, 6, 0x00000001>;
    using errie = FieldModel<address, 5, 0x00000001>;
    using frf = FieldModel<address, 4, 0x00000001>;
    using ssoe = FieldModel<address, 2, 0x00000001>;
    using txdmaen = FieldModel<address, 1, 0x00000001>;
    using rxdmaen = FieldModel<address, 0, 0x00000001>;
  };

public:
  using cr2 = Cr2Reg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class SrReg: public RegisterModel<address>
  {
  public:
    using tifrfe = FieldModel<address, 8, 0x00000001>;
    using bsy = FieldModel<address, 7, 0x00000001>;
    using ovr = FieldModel<address, 6, 0x00000001>;
    using modf = FieldModel<address, 5, 0x00000001>;
    using crcerr = FieldModel<address, 4, 0x00000001>;
    using udr = FieldModel<address, 3, 0x00000001>;
    using chside = FieldModel<address, 2, 0x00000001>;
    using txe = FieldModel<address, 1, 0x00000001>;
    using rxne = FieldModel<address, 0, 0x00000001>;
  };

public:
  using sr = SrReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class DrReg: public RegisterModel<address>
  {
  public:
    using dr = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using dr = DrReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class CrcprReg: public RegisterModel<address>
  {
  public:
    using crcpoly = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using crcpr = CrcprReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class RxcrcrReg: public RegisterModel<address>
  {
  public:
    using rxcrc = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using rxcrcr = RxcrcrReg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class TxcrcrReg: public RegisterModel<address>
  {
  public:
    using txcrc = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using txcrcr = TxcrcrReg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class I2scfgrReg: public RegisterModel<address>
  {
  public:
    using i2smod = FieldModel<address, 11, 0x00000001>;
    using i2se = FieldModel<address, 10, 0x00000001>;
    using i2scfg = FieldModel<address, 8, 0x00000003>;
    using pcmsync = FieldModel<address, 7, 0x00000001>;
    using i2sstd = FieldModel<address, 4, 0x00000003>;
    using ckpol = FieldModel<address, 3, 0x00000001>;
    using datlen = FieldModel<address, 1, 0x00000003>;
    using chlen = FieldModel<address, 0, 0x00000001>;
  };

public:
  using i2scfgr = I2scfgrReg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class I2sprReg: public RegisterModel<address>
  {
  public:
    using mckoe = FieldModel<address, 9, 0x00000001>;
    using odd = FieldModel<address, 8, 0x00000001>;
    using i2sdiv = FieldModel<address, 0, 0x000000FF>;
  };

public:
  using i2spr = I2sprReg<BaseAddress + 0x0020>;
};

}

#endif /* DRAL_STM32F411_SPI1_H */
