#ifndef DRAL_STM32F411_OTG_FS_HOST_H
#define DRAL_STM32F411_OTG_FS_HOST_H

#include "register_model.h"

namespace dral::stm32f411 {

class otg_fs_host
{
public:
  static constexpr uint32_t BaseAddress = 0x50000400;

private:
  template <uint32_t address>
  class Fs_hcfgReg: public RegisterModel<address>
  {
  public:
    using fslspcs = FieldModel<address,  0, 0x00000003>;
    using fslss = FieldModel<address,  2, 0x00000001>;

  };

public:
  using fs_hcfg = Fs_hcfgReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class HfirReg: public RegisterModel<address>
  {
  public:
    using frivl = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using hfir = HfirReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class Fs_hfnumReg: public RegisterModel<address>
  {
  public:
    using frnum = FieldModel<address,  0, 0x0000FFFF>;
    using ftrem = FieldModel<address, 16, 0x0000FFFF>;

  };

public:
  using fs_hfnum = Fs_hfnumReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class Fs_hptxstsReg: public RegisterModel<address>
  {
  public:
    using ptxfsavl = FieldModel<address,  0, 0x0000FFFF>;
    using ptxqsav = FieldModel<address, 16, 0x000000FF>;
    using ptxqtop = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using fs_hptxsts = Fs_hptxstsReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class HaintReg: public RegisterModel<address>
  {
  public:
    using haint = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using haint = HaintReg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class HaintmskReg: public RegisterModel<address>
  {
  public:
    using haintm = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using haintmsk = HaintmskReg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class Fs_hprtReg: public RegisterModel<address>
  {
  public:
    using pcsts = FieldModel<address,  0, 0x00000001>;
    using pcdet = FieldModel<address,  1, 0x00000001>;
    using pena = FieldModel<address,  2, 0x00000001>;
    using penchng = FieldModel<address,  3, 0x00000001>;
    using poca = FieldModel<address,  4, 0x00000001>;
    using pocchng = FieldModel<address,  5, 0x00000001>;
    using pres = FieldModel<address,  6, 0x00000001>;
    using psusp = FieldModel<address,  7, 0x00000001>;
    using prst = FieldModel<address,  8, 0x00000001>;
    using plsts = FieldModel<address, 10, 0x00000003>;
    using ppwr = FieldModel<address, 12, 0x00000001>;
    using ptctl = FieldModel<address, 13, 0x0000000F>;
    using pspd = FieldModel<address, 17, 0x00000003>;

  };

public:
  using fs_hprt = Fs_hprtReg<BaseAddress + 0x0040>;

private:
  template <uint32_t address>
  class Fs_hcchar0Reg: public RegisterModel<address>
  {
  public:
    using mpsiz = FieldModel<address,  0, 0x000007FF>;
    using epnum = FieldModel<address, 11, 0x0000000F>;
    using epdir = FieldModel<address, 15, 0x00000001>;
    using lsdev = FieldModel<address, 17, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using mcnt = FieldModel<address, 20, 0x00000003>;
    using dad = FieldModel<address, 22, 0x0000007F>;
    using oddfrm = FieldModel<address, 29, 0x00000001>;
    using chdis = FieldModel<address, 30, 0x00000001>;
    using chena = FieldModel<address, 31, 0x00000001>;

  };

public:
  using fs_hcchar0 = Fs_hcchar0Reg<BaseAddress + 0x0100>;

private:
  template <uint32_t address>
  class Fs_hcchar1Reg: public RegisterModel<address>
  {
  public:
    using mpsiz = FieldModel<address,  0, 0x000007FF>;
    using epnum = FieldModel<address, 11, 0x0000000F>;
    using epdir = FieldModel<address, 15, 0x00000001>;
    using lsdev = FieldModel<address, 17, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using mcnt = FieldModel<address, 20, 0x00000003>;
    using dad = FieldModel<address, 22, 0x0000007F>;
    using oddfrm = FieldModel<address, 29, 0x00000001>;
    using chdis = FieldModel<address, 30, 0x00000001>;
    using chena = FieldModel<address, 31, 0x00000001>;

  };

public:
  using fs_hcchar1 = Fs_hcchar1Reg<BaseAddress + 0x0120>;

private:
  template <uint32_t address>
  class Fs_hcchar2Reg: public RegisterModel<address>
  {
  public:
    using mpsiz = FieldModel<address,  0, 0x000007FF>;
    using epnum = FieldModel<address, 11, 0x0000000F>;
    using epdir = FieldModel<address, 15, 0x00000001>;
    using lsdev = FieldModel<address, 17, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using mcnt = FieldModel<address, 20, 0x00000003>;
    using dad = FieldModel<address, 22, 0x0000007F>;
    using oddfrm = FieldModel<address, 29, 0x00000001>;
    using chdis = FieldModel<address, 30, 0x00000001>;
    using chena = FieldModel<address, 31, 0x00000001>;

  };

public:
  using fs_hcchar2 = Fs_hcchar2Reg<BaseAddress + 0x0140>;

private:
  template <uint32_t address>
  class Fs_hcchar3Reg: public RegisterModel<address>
  {
  public:
    using mpsiz = FieldModel<address,  0, 0x000007FF>;
    using epnum = FieldModel<address, 11, 0x0000000F>;
    using epdir = FieldModel<address, 15, 0x00000001>;
    using lsdev = FieldModel<address, 17, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using mcnt = FieldModel<address, 20, 0x00000003>;
    using dad = FieldModel<address, 22, 0x0000007F>;
    using oddfrm = FieldModel<address, 29, 0x00000001>;
    using chdis = FieldModel<address, 30, 0x00000001>;
    using chena = FieldModel<address, 31, 0x00000001>;

  };

public:
  using fs_hcchar3 = Fs_hcchar3Reg<BaseAddress + 0x0160>;

private:
  template <uint32_t address>
  class Fs_hcchar4Reg: public RegisterModel<address>
  {
  public:
    using mpsiz = FieldModel<address,  0, 0x000007FF>;
    using epnum = FieldModel<address, 11, 0x0000000F>;
    using epdir = FieldModel<address, 15, 0x00000001>;
    using lsdev = FieldModel<address, 17, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using mcnt = FieldModel<address, 20, 0x00000003>;
    using dad = FieldModel<address, 22, 0x0000007F>;
    using oddfrm = FieldModel<address, 29, 0x00000001>;
    using chdis = FieldModel<address, 30, 0x00000001>;
    using chena = FieldModel<address, 31, 0x00000001>;

  };

public:
  using fs_hcchar4 = Fs_hcchar4Reg<BaseAddress + 0x0180>;

private:
  template <uint32_t address>
  class Fs_hcchar5Reg: public RegisterModel<address>
  {
  public:
    using mpsiz = FieldModel<address,  0, 0x000007FF>;
    using epnum = FieldModel<address, 11, 0x0000000F>;
    using epdir = FieldModel<address, 15, 0x00000001>;
    using lsdev = FieldModel<address, 17, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using mcnt = FieldModel<address, 20, 0x00000003>;
    using dad = FieldModel<address, 22, 0x0000007F>;
    using oddfrm = FieldModel<address, 29, 0x00000001>;
    using chdis = FieldModel<address, 30, 0x00000001>;
    using chena = FieldModel<address, 31, 0x00000001>;

  };

public:
  using fs_hcchar5 = Fs_hcchar5Reg<BaseAddress + 0x01A0>;

private:
  template <uint32_t address>
  class Fs_hcchar6Reg: public RegisterModel<address>
  {
  public:
    using mpsiz = FieldModel<address,  0, 0x000007FF>;
    using epnum = FieldModel<address, 11, 0x0000000F>;
    using epdir = FieldModel<address, 15, 0x00000001>;
    using lsdev = FieldModel<address, 17, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using mcnt = FieldModel<address, 20, 0x00000003>;
    using dad = FieldModel<address, 22, 0x0000007F>;
    using oddfrm = FieldModel<address, 29, 0x00000001>;
    using chdis = FieldModel<address, 30, 0x00000001>;
    using chena = FieldModel<address, 31, 0x00000001>;

  };

public:
  using fs_hcchar6 = Fs_hcchar6Reg<BaseAddress + 0x01C0>;

private:
  template <uint32_t address>
  class Fs_hcchar7Reg: public RegisterModel<address>
  {
  public:
    using mpsiz = FieldModel<address,  0, 0x000007FF>;
    using epnum = FieldModel<address, 11, 0x0000000F>;
    using epdir = FieldModel<address, 15, 0x00000001>;
    using lsdev = FieldModel<address, 17, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using mcnt = FieldModel<address, 20, 0x00000003>;
    using dad = FieldModel<address, 22, 0x0000007F>;
    using oddfrm = FieldModel<address, 29, 0x00000001>;
    using chdis = FieldModel<address, 30, 0x00000001>;
    using chena = FieldModel<address, 31, 0x00000001>;

  };

public:
  using fs_hcchar7 = Fs_hcchar7Reg<BaseAddress + 0x01E0>;

private:
  template <uint32_t address>
  class Fs_hcint0Reg: public RegisterModel<address>
  {
  public:
    using xfrc = FieldModel<address,  0, 0x00000001>;
    using chh = FieldModel<address,  1, 0x00000001>;
    using stall = FieldModel<address,  3, 0x00000001>;
    using nak = FieldModel<address,  4, 0x00000001>;
    using ack = FieldModel<address,  5, 0x00000001>;
    using txerr = FieldModel<address,  7, 0x00000001>;
    using bberr = FieldModel<address,  8, 0x00000001>;
    using frmor = FieldModel<address,  9, 0x00000001>;
    using dterr = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcint0 = Fs_hcint0Reg<BaseAddress + 0x0108>;

private:
  template <uint32_t address>
  class Fs_hcint1Reg: public RegisterModel<address>
  {
  public:
    using xfrc = FieldModel<address,  0, 0x00000001>;
    using chh = FieldModel<address,  1, 0x00000001>;
    using stall = FieldModel<address,  3, 0x00000001>;
    using nak = FieldModel<address,  4, 0x00000001>;
    using ack = FieldModel<address,  5, 0x00000001>;
    using txerr = FieldModel<address,  7, 0x00000001>;
    using bberr = FieldModel<address,  8, 0x00000001>;
    using frmor = FieldModel<address,  9, 0x00000001>;
    using dterr = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcint1 = Fs_hcint1Reg<BaseAddress + 0x0128>;

private:
  template <uint32_t address>
  class Fs_hcint2Reg: public RegisterModel<address>
  {
  public:
    using xfrc = FieldModel<address,  0, 0x00000001>;
    using chh = FieldModel<address,  1, 0x00000001>;
    using stall = FieldModel<address,  3, 0x00000001>;
    using nak = FieldModel<address,  4, 0x00000001>;
    using ack = FieldModel<address,  5, 0x00000001>;
    using txerr = FieldModel<address,  7, 0x00000001>;
    using bberr = FieldModel<address,  8, 0x00000001>;
    using frmor = FieldModel<address,  9, 0x00000001>;
    using dterr = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcint2 = Fs_hcint2Reg<BaseAddress + 0x0148>;

private:
  template <uint32_t address>
  class Fs_hcint3Reg: public RegisterModel<address>
  {
  public:
    using xfrc = FieldModel<address,  0, 0x00000001>;
    using chh = FieldModel<address,  1, 0x00000001>;
    using stall = FieldModel<address,  3, 0x00000001>;
    using nak = FieldModel<address,  4, 0x00000001>;
    using ack = FieldModel<address,  5, 0x00000001>;
    using txerr = FieldModel<address,  7, 0x00000001>;
    using bberr = FieldModel<address,  8, 0x00000001>;
    using frmor = FieldModel<address,  9, 0x00000001>;
    using dterr = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcint3 = Fs_hcint3Reg<BaseAddress + 0x0168>;

private:
  template <uint32_t address>
  class Fs_hcint4Reg: public RegisterModel<address>
  {
  public:
    using xfrc = FieldModel<address,  0, 0x00000001>;
    using chh = FieldModel<address,  1, 0x00000001>;
    using stall = FieldModel<address,  3, 0x00000001>;
    using nak = FieldModel<address,  4, 0x00000001>;
    using ack = FieldModel<address,  5, 0x00000001>;
    using txerr = FieldModel<address,  7, 0x00000001>;
    using bberr = FieldModel<address,  8, 0x00000001>;
    using frmor = FieldModel<address,  9, 0x00000001>;
    using dterr = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcint4 = Fs_hcint4Reg<BaseAddress + 0x0188>;

private:
  template <uint32_t address>
  class Fs_hcint5Reg: public RegisterModel<address>
  {
  public:
    using xfrc = FieldModel<address,  0, 0x00000001>;
    using chh = FieldModel<address,  1, 0x00000001>;
    using stall = FieldModel<address,  3, 0x00000001>;
    using nak = FieldModel<address,  4, 0x00000001>;
    using ack = FieldModel<address,  5, 0x00000001>;
    using txerr = FieldModel<address,  7, 0x00000001>;
    using bberr = FieldModel<address,  8, 0x00000001>;
    using frmor = FieldModel<address,  9, 0x00000001>;
    using dterr = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcint5 = Fs_hcint5Reg<BaseAddress + 0x01A8>;

private:
  template <uint32_t address>
  class Fs_hcint6Reg: public RegisterModel<address>
  {
  public:
    using xfrc = FieldModel<address,  0, 0x00000001>;
    using chh = FieldModel<address,  1, 0x00000001>;
    using stall = FieldModel<address,  3, 0x00000001>;
    using nak = FieldModel<address,  4, 0x00000001>;
    using ack = FieldModel<address,  5, 0x00000001>;
    using txerr = FieldModel<address,  7, 0x00000001>;
    using bberr = FieldModel<address,  8, 0x00000001>;
    using frmor = FieldModel<address,  9, 0x00000001>;
    using dterr = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcint6 = Fs_hcint6Reg<BaseAddress + 0x01C8>;

private:
  template <uint32_t address>
  class Fs_hcint7Reg: public RegisterModel<address>
  {
  public:
    using xfrc = FieldModel<address,  0, 0x00000001>;
    using chh = FieldModel<address,  1, 0x00000001>;
    using stall = FieldModel<address,  3, 0x00000001>;
    using nak = FieldModel<address,  4, 0x00000001>;
    using ack = FieldModel<address,  5, 0x00000001>;
    using txerr = FieldModel<address,  7, 0x00000001>;
    using bberr = FieldModel<address,  8, 0x00000001>;
    using frmor = FieldModel<address,  9, 0x00000001>;
    using dterr = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcint7 = Fs_hcint7Reg<BaseAddress + 0x01E8>;

private:
  template <uint32_t address>
  class Fs_hcintmsk0Reg: public RegisterModel<address>
  {
  public:
    using xfrcm = FieldModel<address,  0, 0x00000001>;
    using chhm = FieldModel<address,  1, 0x00000001>;
    using stallm = FieldModel<address,  3, 0x00000001>;
    using nakm = FieldModel<address,  4, 0x00000001>;
    using ackm = FieldModel<address,  5, 0x00000001>;
    using nyet = FieldModel<address,  6, 0x00000001>;
    using txerrm = FieldModel<address,  7, 0x00000001>;
    using bberrm = FieldModel<address,  8, 0x00000001>;
    using frmorm = FieldModel<address,  9, 0x00000001>;
    using dterrm = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcintmsk0 = Fs_hcintmsk0Reg<BaseAddress + 0x010C>;

private:
  template <uint32_t address>
  class Fs_hcintmsk1Reg: public RegisterModel<address>
  {
  public:
    using xfrcm = FieldModel<address,  0, 0x00000001>;
    using chhm = FieldModel<address,  1, 0x00000001>;
    using stallm = FieldModel<address,  3, 0x00000001>;
    using nakm = FieldModel<address,  4, 0x00000001>;
    using ackm = FieldModel<address,  5, 0x00000001>;
    using nyet = FieldModel<address,  6, 0x00000001>;
    using txerrm = FieldModel<address,  7, 0x00000001>;
    using bberrm = FieldModel<address,  8, 0x00000001>;
    using frmorm = FieldModel<address,  9, 0x00000001>;
    using dterrm = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcintmsk1 = Fs_hcintmsk1Reg<BaseAddress + 0x012C>;

private:
  template <uint32_t address>
  class Fs_hcintmsk2Reg: public RegisterModel<address>
  {
  public:
    using xfrcm = FieldModel<address,  0, 0x00000001>;
    using chhm = FieldModel<address,  1, 0x00000001>;
    using stallm = FieldModel<address,  3, 0x00000001>;
    using nakm = FieldModel<address,  4, 0x00000001>;
    using ackm = FieldModel<address,  5, 0x00000001>;
    using nyet = FieldModel<address,  6, 0x00000001>;
    using txerrm = FieldModel<address,  7, 0x00000001>;
    using bberrm = FieldModel<address,  8, 0x00000001>;
    using frmorm = FieldModel<address,  9, 0x00000001>;
    using dterrm = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcintmsk2 = Fs_hcintmsk2Reg<BaseAddress + 0x014C>;

private:
  template <uint32_t address>
  class Fs_hcintmsk3Reg: public RegisterModel<address>
  {
  public:
    using xfrcm = FieldModel<address,  0, 0x00000001>;
    using chhm = FieldModel<address,  1, 0x00000001>;
    using stallm = FieldModel<address,  3, 0x00000001>;
    using nakm = FieldModel<address,  4, 0x00000001>;
    using ackm = FieldModel<address,  5, 0x00000001>;
    using nyet = FieldModel<address,  6, 0x00000001>;
    using txerrm = FieldModel<address,  7, 0x00000001>;
    using bberrm = FieldModel<address,  8, 0x00000001>;
    using frmorm = FieldModel<address,  9, 0x00000001>;
    using dterrm = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcintmsk3 = Fs_hcintmsk3Reg<BaseAddress + 0x016C>;

private:
  template <uint32_t address>
  class Fs_hcintmsk4Reg: public RegisterModel<address>
  {
  public:
    using xfrcm = FieldModel<address,  0, 0x00000001>;
    using chhm = FieldModel<address,  1, 0x00000001>;
    using stallm = FieldModel<address,  3, 0x00000001>;
    using nakm = FieldModel<address,  4, 0x00000001>;
    using ackm = FieldModel<address,  5, 0x00000001>;
    using nyet = FieldModel<address,  6, 0x00000001>;
    using txerrm = FieldModel<address,  7, 0x00000001>;
    using bberrm = FieldModel<address,  8, 0x00000001>;
    using frmorm = FieldModel<address,  9, 0x00000001>;
    using dterrm = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcintmsk4 = Fs_hcintmsk4Reg<BaseAddress + 0x018C>;

private:
  template <uint32_t address>
  class Fs_hcintmsk5Reg: public RegisterModel<address>
  {
  public:
    using xfrcm = FieldModel<address,  0, 0x00000001>;
    using chhm = FieldModel<address,  1, 0x00000001>;
    using stallm = FieldModel<address,  3, 0x00000001>;
    using nakm = FieldModel<address,  4, 0x00000001>;
    using ackm = FieldModel<address,  5, 0x00000001>;
    using nyet = FieldModel<address,  6, 0x00000001>;
    using txerrm = FieldModel<address,  7, 0x00000001>;
    using bberrm = FieldModel<address,  8, 0x00000001>;
    using frmorm = FieldModel<address,  9, 0x00000001>;
    using dterrm = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcintmsk5 = Fs_hcintmsk5Reg<BaseAddress + 0x01AC>;

private:
  template <uint32_t address>
  class Fs_hcintmsk6Reg: public RegisterModel<address>
  {
  public:
    using xfrcm = FieldModel<address,  0, 0x00000001>;
    using chhm = FieldModel<address,  1, 0x00000001>;
    using stallm = FieldModel<address,  3, 0x00000001>;
    using nakm = FieldModel<address,  4, 0x00000001>;
    using ackm = FieldModel<address,  5, 0x00000001>;
    using nyet = FieldModel<address,  6, 0x00000001>;
    using txerrm = FieldModel<address,  7, 0x00000001>;
    using bberrm = FieldModel<address,  8, 0x00000001>;
    using frmorm = FieldModel<address,  9, 0x00000001>;
    using dterrm = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcintmsk6 = Fs_hcintmsk6Reg<BaseAddress + 0x01CC>;

private:
  template <uint32_t address>
  class Fs_hcintmsk7Reg: public RegisterModel<address>
  {
  public:
    using xfrcm = FieldModel<address,  0, 0x00000001>;
    using chhm = FieldModel<address,  1, 0x00000001>;
    using stallm = FieldModel<address,  3, 0x00000001>;
    using nakm = FieldModel<address,  4, 0x00000001>;
    using ackm = FieldModel<address,  5, 0x00000001>;
    using nyet = FieldModel<address,  6, 0x00000001>;
    using txerrm = FieldModel<address,  7, 0x00000001>;
    using bberrm = FieldModel<address,  8, 0x00000001>;
    using frmorm = FieldModel<address,  9, 0x00000001>;
    using dterrm = FieldModel<address, 10, 0x00000001>;

  };

public:
  using fs_hcintmsk7 = Fs_hcintmsk7Reg<BaseAddress + 0x01EC>;

private:
  template <uint32_t address>
  class Fs_hctsiz0Reg: public RegisterModel<address>
  {
  public:
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using dpid = FieldModel<address, 29, 0x00000003>;

  };

public:
  using fs_hctsiz0 = Fs_hctsiz0Reg<BaseAddress + 0x0110>;

private:
  template <uint32_t address>
  class Fs_hctsiz1Reg: public RegisterModel<address>
  {
  public:
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using dpid = FieldModel<address, 29, 0x00000003>;

  };

public:
  using fs_hctsiz1 = Fs_hctsiz1Reg<BaseAddress + 0x0130>;

private:
  template <uint32_t address>
  class Fs_hctsiz2Reg: public RegisterModel<address>
  {
  public:
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using dpid = FieldModel<address, 29, 0x00000003>;

  };

public:
  using fs_hctsiz2 = Fs_hctsiz2Reg<BaseAddress + 0x0150>;

private:
  template <uint32_t address>
  class Fs_hctsiz3Reg: public RegisterModel<address>
  {
  public:
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using dpid = FieldModel<address, 29, 0x00000003>;

  };

public:
  using fs_hctsiz3 = Fs_hctsiz3Reg<BaseAddress + 0x0170>;

private:
  template <uint32_t address>
  class Fs_hctsiz4Reg: public RegisterModel<address>
  {
  public:
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using dpid = FieldModel<address, 29, 0x00000003>;

  };

public:
  using fs_hctsiz4 = Fs_hctsiz4Reg<BaseAddress + 0x0190>;

private:
  template <uint32_t address>
  class Fs_hctsiz5Reg: public RegisterModel<address>
  {
  public:
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using dpid = FieldModel<address, 29, 0x00000003>;

  };

public:
  using fs_hctsiz5 = Fs_hctsiz5Reg<BaseAddress + 0x01B0>;

private:
  template <uint32_t address>
  class Fs_hctsiz6Reg: public RegisterModel<address>
  {
  public:
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using dpid = FieldModel<address, 29, 0x00000003>;

  };

public:
  using fs_hctsiz6 = Fs_hctsiz6Reg<BaseAddress + 0x01D0>;

private:
  template <uint32_t address>
  class Fs_hctsiz7Reg: public RegisterModel<address>
  {
  public:
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using dpid = FieldModel<address, 29, 0x00000003>;

  };

public:
  using fs_hctsiz7 = Fs_hctsiz7Reg<BaseAddress + 0x01F0>;


};

}

#endif /* DRAL_STM32F411_OTG_FS_HOST_H */
