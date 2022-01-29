#ifndef DRAL_STM32F411_RTC_H
#define DRAL_STM32F411_RTC_H

#include "register_model.h"

namespace dral::stm32f411 {

class rtc
{
public:
  static constexpr uint32_t BaseAddress = 0x40002800;

private:
  template <uint32_t address>
  class TrReg: public RegisterModel<address>
  {
  public:
    using pm = FieldModel<address, 22, 0x00000001>;
    using ht = FieldModel<address, 20, 0x00000003>;
    using hu = FieldModel<address, 16, 0x0000000F>;
    using mnt = FieldModel<address, 12, 0x00000007>;
    using mnu = FieldModel<address,  8, 0x0000000F>;
    using st = FieldModel<address,  4, 0x00000007>;
    using su = FieldModel<address,  0, 0x0000000F>;

  };

public:
  using tr = TrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class DrReg: public RegisterModel<address>
  {
  public:
    using yt = FieldModel<address, 20, 0x0000000F>;
    using yu = FieldModel<address, 16, 0x0000000F>;
    using wdu = FieldModel<address, 13, 0x00000007>;
    using mt = FieldModel<address, 12, 0x00000001>;
    using mu = FieldModel<address,  8, 0x0000000F>;
    using dt = FieldModel<address,  4, 0x00000003>;
    using du = FieldModel<address,  0, 0x0000000F>;

  };

public:
  using dr = DrReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class CrReg: public RegisterModel<address>
  {
  public:
    using coe = FieldModel<address, 23, 0x00000001>;
    using osel = FieldModel<address, 21, 0x00000003>;
    using pol = FieldModel<address, 20, 0x00000001>;
    using cosel = FieldModel<address, 19, 0x00000001>;
    using bkp = FieldModel<address, 18, 0x00000001>;
    using sub1h = FieldModel<address, 17, 0x00000001>;
    using add1h = FieldModel<address, 16, 0x00000001>;
    using tsie = FieldModel<address, 15, 0x00000001>;
    using wutie = FieldModel<address, 14, 0x00000001>;
    using alrbie = FieldModel<address, 13, 0x00000001>;
    using alraie = FieldModel<address, 12, 0x00000001>;
    using tse = FieldModel<address, 11, 0x00000001>;
    using wute = FieldModel<address, 10, 0x00000001>;
    using alrbe = FieldModel<address,  9, 0x00000001>;
    using alrae = FieldModel<address,  8, 0x00000001>;
    using dce = FieldModel<address,  7, 0x00000001>;
    using fmt = FieldModel<address,  6, 0x00000001>;
    using bypshad = FieldModel<address,  5, 0x00000001>;
    using refckon = FieldModel<address,  4, 0x00000001>;
    using tsedge = FieldModel<address,  3, 0x00000001>;
    using wcksel = FieldModel<address,  0, 0x00000007>;

  };

public:
  using cr = CrReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class IsrReg: public RegisterModel<address>
  {
  public:
    using alrawf = FieldModel<address,  0, 0x00000001>;
    using alrbwf = FieldModel<address,  1, 0x00000001>;
    using wutwf = FieldModel<address,  2, 0x00000001>;
    using shpf = FieldModel<address,  3, 0x00000001>;
    using inits = FieldModel<address,  4, 0x00000001>;
    using rsf = FieldModel<address,  5, 0x00000001>;
    using initf = FieldModel<address,  6, 0x00000001>;
    using init = FieldModel<address,  7, 0x00000001>;
    using alraf = FieldModel<address,  8, 0x00000001>;
    using alrbf = FieldModel<address,  9, 0x00000001>;
    using wutf = FieldModel<address, 10, 0x00000001>;
    using tsf = FieldModel<address, 11, 0x00000001>;
    using tsovf = FieldModel<address, 12, 0x00000001>;
    using tamp1f = FieldModel<address, 13, 0x00000001>;
    using tamp2f = FieldModel<address, 14, 0x00000001>;
    using recalpf = FieldModel<address, 16, 0x00000001>;

  };

public:
  using isr = IsrReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class PrerReg: public RegisterModel<address>
  {
  public:
    using prediv_a = FieldModel<address, 16, 0x0000007F>;
    using prediv_s = FieldModel<address,  0, 0x00007FFF>;

  };

public:
  using prer = PrerReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class WutrReg: public RegisterModel<address>
  {
  public:
    using wut = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using wutr = WutrReg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class CalibrReg: public RegisterModel<address>
  {
  public:
    using dcs = FieldModel<address,  7, 0x00000001>;
    using dc = FieldModel<address,  0, 0x0000001F>;

  };

public:
  using calibr = CalibrReg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class AlrmarReg: public RegisterModel<address>
  {
  public:
    using msk4 = FieldModel<address, 31, 0x00000001>;
    using wdsel = FieldModel<address, 30, 0x00000001>;
    using dt = FieldModel<address, 28, 0x00000003>;
    using du = FieldModel<address, 24, 0x0000000F>;
    using msk3 = FieldModel<address, 23, 0x00000001>;
    using pm = FieldModel<address, 22, 0x00000001>;
    using ht = FieldModel<address, 20, 0x00000003>;
    using hu = FieldModel<address, 16, 0x0000000F>;
    using msk2 = FieldModel<address, 15, 0x00000001>;
    using mnt = FieldModel<address, 12, 0x00000007>;
    using mnu = FieldModel<address,  8, 0x0000000F>;
    using msk1 = FieldModel<address,  7, 0x00000001>;
    using st = FieldModel<address,  4, 0x00000007>;
    using su = FieldModel<address,  0, 0x0000000F>;

  };

public:
  using alrmar = AlrmarReg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class AlrmbrReg: public RegisterModel<address>
  {
  public:
    using msk4 = FieldModel<address, 31, 0x00000001>;
    using wdsel = FieldModel<address, 30, 0x00000001>;
    using dt = FieldModel<address, 28, 0x00000003>;
    using du = FieldModel<address, 24, 0x0000000F>;
    using msk3 = FieldModel<address, 23, 0x00000001>;
    using pm = FieldModel<address, 22, 0x00000001>;
    using ht = FieldModel<address, 20, 0x00000003>;
    using hu = FieldModel<address, 16, 0x0000000F>;
    using msk2 = FieldModel<address, 15, 0x00000001>;
    using mnt = FieldModel<address, 12, 0x00000007>;
    using mnu = FieldModel<address,  8, 0x0000000F>;
    using msk1 = FieldModel<address,  7, 0x00000001>;
    using st = FieldModel<address,  4, 0x00000007>;
    using su = FieldModel<address,  0, 0x0000000F>;

  };

public:
  using alrmbr = AlrmbrReg<BaseAddress + 0x0020>;

private:
  template <uint32_t address>
  class WprReg: public RegisterModel<address>
  {
  public:
    using key = FieldModel<address,  0, 0x000000FF>;

  };

public:
  using wpr = WprReg<BaseAddress + 0x0024>;

private:
  template <uint32_t address>
  class SsrReg: public RegisterModel<address>
  {
  public:
    using ss = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using ssr = SsrReg<BaseAddress + 0x0028>;

private:
  template <uint32_t address>
  class ShiftrReg: public RegisterModel<address>
  {
  public:
    using add1s = FieldModel<address, 31, 0x00000001>;
    using subfs = FieldModel<address,  0, 0x00007FFF>;

  };

public:
  using shiftr = ShiftrReg<BaseAddress + 0x002C>;

private:
  template <uint32_t address>
  class TstrReg: public RegisterModel<address>
  {
  public:
    using pm = FieldModel<address, 22, 0x00000001>;
    using ht = FieldModel<address, 20, 0x00000003>;
    using hu = FieldModel<address, 16, 0x0000000F>;
    using mnt = FieldModel<address, 12, 0x00000007>;
    using mnu = FieldModel<address,  8, 0x0000000F>;
    using st = FieldModel<address,  4, 0x00000007>;
    using su = FieldModel<address,  0, 0x0000000F>;

  };

public:
  using tstr = TstrReg<BaseAddress + 0x0030>;

private:
  template <uint32_t address>
  class TsdrReg: public RegisterModel<address>
  {
  public:
    using wdu = FieldModel<address, 13, 0x00000007>;
    using mt = FieldModel<address, 12, 0x00000001>;
    using mu = FieldModel<address,  8, 0x0000000F>;
    using dt = FieldModel<address,  4, 0x00000003>;
    using du = FieldModel<address,  0, 0x0000000F>;

  };

public:
  using tsdr = TsdrReg<BaseAddress + 0x0034>;

private:
  template <uint32_t address>
  class TsssrReg: public RegisterModel<address>
  {
  public:
    using ss = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using tsssr = TsssrReg<BaseAddress + 0x0038>;

private:
  template <uint32_t address>
  class CalrReg: public RegisterModel<address>
  {
  public:
    using calp = FieldModel<address, 15, 0x00000001>;
    using calw8 = FieldModel<address, 14, 0x00000001>;
    using calw16 = FieldModel<address, 13, 0x00000001>;
    using calm = FieldModel<address,  0, 0x000001FF>;

  };

public:
  using calr = CalrReg<BaseAddress + 0x003C>;

private:
  template <uint32_t address>
  class TafcrReg: public RegisterModel<address>
  {
  public:
    using alarmouttype = FieldModel<address, 18, 0x00000001>;
    using tsinsel = FieldModel<address, 17, 0x00000001>;
    using tamp1insel = FieldModel<address, 16, 0x00000001>;
    using tamppudis = FieldModel<address, 15, 0x00000001>;
    using tampprch = FieldModel<address, 13, 0x00000003>;
    using tampflt = FieldModel<address, 11, 0x00000003>;
    using tampfreq = FieldModel<address,  8, 0x00000007>;
    using tampts = FieldModel<address,  7, 0x00000001>;
    using tamp2trg = FieldModel<address,  4, 0x00000001>;
    using tamp2e = FieldModel<address,  3, 0x00000001>;
    using tampie = FieldModel<address,  2, 0x00000001>;
    using tamp1trg = FieldModel<address,  1, 0x00000001>;
    using tamp1e = FieldModel<address,  0, 0x00000001>;

  };

public:
  using tafcr = TafcrReg<BaseAddress + 0x0040>;

private:
  template <uint32_t address>
  class AlrmassrReg: public RegisterModel<address>
  {
  public:
    using maskss = FieldModel<address, 24, 0x0000000F>;
    using ss = FieldModel<address,  0, 0x00007FFF>;

  };

public:
  using alrmassr = AlrmassrReg<BaseAddress + 0x0044>;

private:
  template <uint32_t address>
  class AlrmbssrReg: public RegisterModel<address>
  {
  public:
    using maskss = FieldModel<address, 24, 0x0000000F>;
    using ss = FieldModel<address,  0, 0x00007FFF>;

  };

public:
  using alrmbssr = AlrmbssrReg<BaseAddress + 0x0048>;

private:
  template <uint32_t address>
  class Bkp0rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp0r = Bkp0rReg<BaseAddress + 0x0050>;

private:
  template <uint32_t address>
  class Bkp1rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp1r = Bkp1rReg<BaseAddress + 0x0054>;

private:
  template <uint32_t address>
  class Bkp2rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp2r = Bkp2rReg<BaseAddress + 0x0058>;

private:
  template <uint32_t address>
  class Bkp3rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp3r = Bkp3rReg<BaseAddress + 0x005C>;

private:
  template <uint32_t address>
  class Bkp4rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp4r = Bkp4rReg<BaseAddress + 0x0060>;

private:
  template <uint32_t address>
  class Bkp5rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp5r = Bkp5rReg<BaseAddress + 0x0064>;

private:
  template <uint32_t address>
  class Bkp6rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp6r = Bkp6rReg<BaseAddress + 0x0068>;

private:
  template <uint32_t address>
  class Bkp7rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp7r = Bkp7rReg<BaseAddress + 0x006C>;

private:
  template <uint32_t address>
  class Bkp8rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp8r = Bkp8rReg<BaseAddress + 0x0070>;

private:
  template <uint32_t address>
  class Bkp9rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp9r = Bkp9rReg<BaseAddress + 0x0074>;

private:
  template <uint32_t address>
  class Bkp10rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp10r = Bkp10rReg<BaseAddress + 0x0078>;

private:
  template <uint32_t address>
  class Bkp11rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp11r = Bkp11rReg<BaseAddress + 0x007C>;

private:
  template <uint32_t address>
  class Bkp12rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp12r = Bkp12rReg<BaseAddress + 0x0080>;

private:
  template <uint32_t address>
  class Bkp13rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp13r = Bkp13rReg<BaseAddress + 0x0084>;

private:
  template <uint32_t address>
  class Bkp14rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp14r = Bkp14rReg<BaseAddress + 0x0088>;

private:
  template <uint32_t address>
  class Bkp15rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp15r = Bkp15rReg<BaseAddress + 0x008C>;

private:
  template <uint32_t address>
  class Bkp16rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp16r = Bkp16rReg<BaseAddress + 0x0090>;

private:
  template <uint32_t address>
  class Bkp17rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp17r = Bkp17rReg<BaseAddress + 0x0094>;

private:
  template <uint32_t address>
  class Bkp18rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp18r = Bkp18rReg<BaseAddress + 0x0098>;

private:
  template <uint32_t address>
  class Bkp19rReg: public RegisterModel<address>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bkp19r = Bkp19rReg<BaseAddress + 0x009C>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class AlrmxssrBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using maskss = FieldModel<address, 24, 0x0000000F, bankOffset>;
    using ss = FieldModel<address,  0, 0x00007FFF, bankOffset>;

  };

public:
  using alrmxssr = AlrmxssrBankReg<BaseAddress + 0x0044, 0x0004>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class BkpxrBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using bkp = FieldModel<address,  0, 0xFFFFFFFF, bankOffset>;

  };

public:
  using bkpxr = BkpxrBankReg<BaseAddress + 0x0050, 0x0004>;


};

}

#endif /* DRAL_STM32F411_RTC_H */
