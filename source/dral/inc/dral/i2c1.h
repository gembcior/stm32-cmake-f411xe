#ifndef DRAL_STM32F411_I2C1_H
#define DRAL_STM32F411_I2C1_H

#include "register_model.h"

namespace dral::stm32f411 {

class i2c1
{
public:
  static constexpr uint32_t BaseAddress = 0x40005400;

private:
  template <uint32_t address>
  class Cr1Reg: public RegisterModel<address>
  {
  public:
    using swrst = FieldModel<address, 15, 0x00000001>;
    using alert = FieldModel<address, 13, 0x00000001>;
    using pec = FieldModel<address, 12, 0x00000001>;
    using pos = FieldModel<address, 11, 0x00000001>;
    using ack = FieldModel<address, 10, 0x00000001>;
    using stop = FieldModel<address, 9, 0x00000001>;
    using start = FieldModel<address, 8, 0x00000001>;
    using nostretch = FieldModel<address, 7, 0x00000001>;
    using engc = FieldModel<address, 6, 0x00000001>;
    using enpec = FieldModel<address, 5, 0x00000001>;
    using enarp = FieldModel<address, 4, 0x00000001>;
    using smbtype = FieldModel<address, 3, 0x00000001>;
    using smbus = FieldModel<address, 1, 0x00000001>;
    using pe = FieldModel<address, 0, 0x00000001>;
  };

public:
  using cr1 = Cr1Reg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class Cr2Reg: public RegisterModel<address>
  {
  public:
    using last = FieldModel<address, 12, 0x00000001>;
    using dmaen = FieldModel<address, 11, 0x00000001>;
    using itbufen = FieldModel<address, 10, 0x00000001>;
    using itevten = FieldModel<address, 9, 0x00000001>;
    using iterren = FieldModel<address, 8, 0x00000001>;
    using freq = FieldModel<address, 0, 0x0000003F>;
  };

public:
  using cr2 = Cr2Reg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class Oar1Reg: public RegisterModel<address>
  {
  public:
    using addmode = FieldModel<address, 15, 0x00000001>;
    using add10 = FieldModel<address, 8, 0x00000003>;
    using add7 = FieldModel<address, 1, 0x0000007F>;
    using add0 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using oar1 = Oar1Reg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class Oar2Reg: public RegisterModel<address>
  {
  public:
    using add2 = FieldModel<address, 1, 0x0000007F>;
    using endual = FieldModel<address, 0, 0x00000001>;
  };

public:
  using oar2 = Oar2Reg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class DrReg: public RegisterModel<address>
  {
  public:
    using dr = FieldModel<address, 0, 0x000000FF>;
  };

public:
  using dr = DrReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class Sr1Reg: public RegisterModel<address>
  {
  public:
    using smbalert = FieldModel<address, 15, 0x00000001>;
    using timeout = FieldModel<address, 14, 0x00000001>;
    using pecerr = FieldModel<address, 12, 0x00000001>;
    using ovr = FieldModel<address, 11, 0x00000001>;
    using af = FieldModel<address, 10, 0x00000001>;
    using arlo = FieldModel<address, 9, 0x00000001>;
    using berr = FieldModel<address, 8, 0x00000001>;
    using txe = FieldModel<address, 7, 0x00000001>;
    using rxne = FieldModel<address, 6, 0x00000001>;
    using stopf = FieldModel<address, 4, 0x00000001>;
    using add10 = FieldModel<address, 3, 0x00000001>;
    using btf = FieldModel<address, 2, 0x00000001>;
    using addr = FieldModel<address, 1, 0x00000001>;
    using sb = FieldModel<address, 0, 0x00000001>;
  };

public:
  using sr1 = Sr1Reg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class Sr2Reg: public RegisterModel<address>
  {
  public:
    using pec = FieldModel<address, 8, 0x000000FF>;
    using dualf = FieldModel<address, 7, 0x00000001>;
    using smbhost = FieldModel<address, 6, 0x00000001>;
    using smbdefault = FieldModel<address, 5, 0x00000001>;
    using gencall = FieldModel<address, 4, 0x00000001>;
    using tra = FieldModel<address, 2, 0x00000001>;
    using busy = FieldModel<address, 1, 0x00000001>;
    using msl = FieldModel<address, 0, 0x00000001>;
  };

public:
  using sr2 = Sr2Reg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class CcrReg: public RegisterModel<address>
  {
  public:
    using f_s = FieldModel<address, 15, 0x00000001>;
    using duty = FieldModel<address, 14, 0x00000001>;
    using ccr = FieldModel<address, 0, 0x00000FFF>;
  };

public:
  using ccr = CcrReg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class TriseReg: public RegisterModel<address>
  {
  public:
    using trise = FieldModel<address, 0, 0x0000003F>;
  };

public:
  using trise = TriseReg<BaseAddress + 0x0020>;
};

}

#endif /* DRAL_STM32F411_I2C1_H */
