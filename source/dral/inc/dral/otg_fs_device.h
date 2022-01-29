#ifndef DRAL_STM32F411_OTG_FS_DEVICE_H
#define DRAL_STM32F411_OTG_FS_DEVICE_H

#include "register_model.h"

namespace dral::stm32f411 {

class otg_fs_device
{
public:
  static constexpr uint32_t BaseAddress = 0x50000800;

private:
  template <uint32_t address>
  class Fs_dcfgReg: public RegisterModel<address>
  {
  public:
    using dspd = FieldModel<address,  0, 0x00000003>;
    using nzlsohsk = FieldModel<address,  2, 0x00000001>;
    using dad = FieldModel<address,  4, 0x0000007F>;
    using pfivl = FieldModel<address, 11, 0x00000003>;

  };

public:
  using fs_dcfg = Fs_dcfgReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class Fs_dctlReg: public RegisterModel<address>
  {
  public:
    using rwusig = FieldModel<address,  0, 0x00000001>;
    using sdis = FieldModel<address,  1, 0x00000001>;
    using ginsts = FieldModel<address,  2, 0x00000001>;
    using gonsts = FieldModel<address,  3, 0x00000001>;
    using tctl = FieldModel<address,  4, 0x00000007>;
    using sginak = FieldModel<address,  7, 0x00000001>;
    using cginak = FieldModel<address,  8, 0x00000001>;
    using sgonak = FieldModel<address,  9, 0x00000001>;
    using cgonak = FieldModel<address, 10, 0x00000001>;
    using poprgdne = FieldModel<address, 11, 0x00000001>;

  };

public:
  using fs_dctl = Fs_dctlReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class Fs_dstsReg: public RegisterModel<address>
  {
  public:
    using suspsts = FieldModel<address,  0, 0x00000001>;
    using enumspd = FieldModel<address,  1, 0x00000003>;
    using eerr = FieldModel<address,  3, 0x00000001>;
    using fnsof = FieldModel<address,  8, 0x00003FFF>;

  };

public:
  using fs_dsts = Fs_dstsReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class Fs_diepmskReg: public RegisterModel<address>
  {
  public:
    using xfrcm = FieldModel<address,  0, 0x00000001>;
    using epdm = FieldModel<address,  1, 0x00000001>;
    using tom = FieldModel<address,  3, 0x00000001>;
    using ittxfemsk = FieldModel<address,  4, 0x00000001>;
    using inepnmm = FieldModel<address,  5, 0x00000001>;
    using inepnem = FieldModel<address,  6, 0x00000001>;

  };

public:
  using fs_diepmsk = Fs_diepmskReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class Fs_doepmskReg: public RegisterModel<address>
  {
  public:
    using xfrcm = FieldModel<address,  0, 0x00000001>;
    using epdm = FieldModel<address,  1, 0x00000001>;
    using stupm = FieldModel<address,  3, 0x00000001>;
    using otepdm = FieldModel<address,  4, 0x00000001>;

  };

public:
  using fs_doepmsk = Fs_doepmskReg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class Fs_daintReg: public RegisterModel<address>
  {
  public:
    using iepint = FieldModel<address,  0, 0x0000FFFF>;
    using oepint = FieldModel<address, 16, 0x0000FFFF>;

  };

public:
  using fs_daint = Fs_daintReg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class Fs_daintmskReg: public RegisterModel<address>
  {
  public:
    using iepm = FieldModel<address,  0, 0x0000FFFF>;
    using oepm = FieldModel<address, 16, 0x0000FFFF>;

  };

public:
  using fs_daintmsk = Fs_daintmskReg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class DvbusdisReg: public RegisterModel<address>
  {
  public:
    using vbusdt = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using dvbusdis = DvbusdisReg<BaseAddress + 0x0028>;

private:
  template <uint32_t address>
  class DvbuspulseReg: public RegisterModel<address>
  {
  public:
    using dvbusp = FieldModel<address,  0, 0x00000FFF>;

  };

public:
  using dvbuspulse = DvbuspulseReg<BaseAddress + 0x002C>;

private:
  template <uint32_t address>
  class DiepempmskReg: public RegisterModel<address>
  {
  public:
    using ineptxfem = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using diepempmsk = DiepempmskReg<BaseAddress + 0x0034>;

private:
  template <uint32_t address>
  class Fs_diepctl0Reg: public RegisterModel<address>
  {
  public:
    using mpsiz = FieldModel<address,  0, 0x00000003>;
    using usbaep = FieldModel<address, 15, 0x00000001>;
    using naksts = FieldModel<address, 17, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using stall = FieldModel<address, 21, 0x00000001>;
    using txfnum = FieldModel<address, 22, 0x0000000F>;
    using cnak = FieldModel<address, 26, 0x00000001>;
    using snak = FieldModel<address, 27, 0x00000001>;
    using epdis = FieldModel<address, 30, 0x00000001>;
    using epena = FieldModel<address, 31, 0x00000001>;

  };

public:
  using fs_diepctl0 = Fs_diepctl0Reg<BaseAddress + 0x0100>;

private:
  template <uint32_t address>
  class Diepctl1Reg: public RegisterModel<address>
  {
  public:
    using epena = FieldModel<address, 31, 0x00000001>;
    using epdis = FieldModel<address, 30, 0x00000001>;
    using soddfrm_sd1pid = FieldModel<address, 29, 0x00000001>;
    using sd0pid_sevnfrm = FieldModel<address, 28, 0x00000001>;
    using snak = FieldModel<address, 27, 0x00000001>;
    using cnak = FieldModel<address, 26, 0x00000001>;
    using txfnum = FieldModel<address, 22, 0x0000000F>;
    using stall = FieldModel<address, 21, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using naksts = FieldModel<address, 17, 0x00000001>;
    using eonum_dpid = FieldModel<address, 16, 0x00000001>;
    using usbaep = FieldModel<address, 15, 0x00000001>;
    using mpsiz = FieldModel<address,  0, 0x000007FF>;

  };

public:
  using diepctl1 = Diepctl1Reg<BaseAddress + 0x0120>;

private:
  template <uint32_t address>
  class Diepctl2Reg: public RegisterModel<address>
  {
  public:
    using epena = FieldModel<address, 31, 0x00000001>;
    using epdis = FieldModel<address, 30, 0x00000001>;
    using soddfrm = FieldModel<address, 29, 0x00000001>;
    using sd0pid_sevnfrm = FieldModel<address, 28, 0x00000001>;
    using snak = FieldModel<address, 27, 0x00000001>;
    using cnak = FieldModel<address, 26, 0x00000001>;
    using txfnum = FieldModel<address, 22, 0x0000000F>;
    using stall = FieldModel<address, 21, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using naksts = FieldModel<address, 17, 0x00000001>;
    using eonum_dpid = FieldModel<address, 16, 0x00000001>;
    using usbaep = FieldModel<address, 15, 0x00000001>;
    using mpsiz = FieldModel<address,  0, 0x000007FF>;

  };

public:
  using diepctl2 = Diepctl2Reg<BaseAddress + 0x0140>;

private:
  template <uint32_t address>
  class Diepctl3Reg: public RegisterModel<address>
  {
  public:
    using epena = FieldModel<address, 31, 0x00000001>;
    using epdis = FieldModel<address, 30, 0x00000001>;
    using soddfrm = FieldModel<address, 29, 0x00000001>;
    using sd0pid_sevnfrm = FieldModel<address, 28, 0x00000001>;
    using snak = FieldModel<address, 27, 0x00000001>;
    using cnak = FieldModel<address, 26, 0x00000001>;
    using txfnum = FieldModel<address, 22, 0x0000000F>;
    using stall = FieldModel<address, 21, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using naksts = FieldModel<address, 17, 0x00000001>;
    using eonum_dpid = FieldModel<address, 16, 0x00000001>;
    using usbaep = FieldModel<address, 15, 0x00000001>;
    using mpsiz = FieldModel<address,  0, 0x000007FF>;

  };

public:
  using diepctl3 = Diepctl3Reg<BaseAddress + 0x0160>;

private:
  template <uint32_t address>
  class Doepctl0Reg: public RegisterModel<address>
  {
  public:
    using epena = FieldModel<address, 31, 0x00000001>;
    using epdis = FieldModel<address, 30, 0x00000001>;
    using snak = FieldModel<address, 27, 0x00000001>;
    using cnak = FieldModel<address, 26, 0x00000001>;
    using stall = FieldModel<address, 21, 0x00000001>;
    using snpm = FieldModel<address, 20, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using naksts = FieldModel<address, 17, 0x00000001>;
    using usbaep = FieldModel<address, 15, 0x00000001>;
    using mpsiz = FieldModel<address,  0, 0x00000003>;

  };

public:
  using doepctl0 = Doepctl0Reg<BaseAddress + 0x0300>;

private:
  template <uint32_t address>
  class Doepctl1Reg: public RegisterModel<address>
  {
  public:
    using epena = FieldModel<address, 31, 0x00000001>;
    using epdis = FieldModel<address, 30, 0x00000001>;
    using soddfrm = FieldModel<address, 29, 0x00000001>;
    using sd0pid_sevnfrm = FieldModel<address, 28, 0x00000001>;
    using snak = FieldModel<address, 27, 0x00000001>;
    using cnak = FieldModel<address, 26, 0x00000001>;
    using stall = FieldModel<address, 21, 0x00000001>;
    using snpm = FieldModel<address, 20, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using naksts = FieldModel<address, 17, 0x00000001>;
    using eonum_dpid = FieldModel<address, 16, 0x00000001>;
    using usbaep = FieldModel<address, 15, 0x00000001>;
    using mpsiz = FieldModel<address,  0, 0x000007FF>;

  };

public:
  using doepctl1 = Doepctl1Reg<BaseAddress + 0x0320>;

private:
  template <uint32_t address>
  class Doepctl2Reg: public RegisterModel<address>
  {
  public:
    using epena = FieldModel<address, 31, 0x00000001>;
    using epdis = FieldModel<address, 30, 0x00000001>;
    using soddfrm = FieldModel<address, 29, 0x00000001>;
    using sd0pid_sevnfrm = FieldModel<address, 28, 0x00000001>;
    using snak = FieldModel<address, 27, 0x00000001>;
    using cnak = FieldModel<address, 26, 0x00000001>;
    using stall = FieldModel<address, 21, 0x00000001>;
    using snpm = FieldModel<address, 20, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using naksts = FieldModel<address, 17, 0x00000001>;
    using eonum_dpid = FieldModel<address, 16, 0x00000001>;
    using usbaep = FieldModel<address, 15, 0x00000001>;
    using mpsiz = FieldModel<address,  0, 0x000007FF>;

  };

public:
  using doepctl2 = Doepctl2Reg<BaseAddress + 0x0340>;

private:
  template <uint32_t address>
  class Doepctl3Reg: public RegisterModel<address>
  {
  public:
    using epena = FieldModel<address, 31, 0x00000001>;
    using epdis = FieldModel<address, 30, 0x00000001>;
    using soddfrm = FieldModel<address, 29, 0x00000001>;
    using sd0pid_sevnfrm = FieldModel<address, 28, 0x00000001>;
    using snak = FieldModel<address, 27, 0x00000001>;
    using cnak = FieldModel<address, 26, 0x00000001>;
    using stall = FieldModel<address, 21, 0x00000001>;
    using snpm = FieldModel<address, 20, 0x00000001>;
    using eptyp = FieldModel<address, 18, 0x00000003>;
    using naksts = FieldModel<address, 17, 0x00000001>;
    using eonum_dpid = FieldModel<address, 16, 0x00000001>;
    using usbaep = FieldModel<address, 15, 0x00000001>;
    using mpsiz = FieldModel<address,  0, 0x000007FF>;

  };

public:
  using doepctl3 = Doepctl3Reg<BaseAddress + 0x0360>;

private:
  template <uint32_t address>
  class Diepint0Reg: public RegisterModel<address>
  {
  public:
    using txfe = FieldModel<address,  7, 0x00000001>;
    using inepne = FieldModel<address,  6, 0x00000001>;
    using ittxfe = FieldModel<address,  4, 0x00000001>;
    using toc = FieldModel<address,  3, 0x00000001>;
    using epdisd = FieldModel<address,  1, 0x00000001>;
    using xfrc = FieldModel<address,  0, 0x00000001>;

  };

public:
  using diepint0 = Diepint0Reg<BaseAddress + 0x0108>;

private:
  template <uint32_t address>
  class Diepint1Reg: public RegisterModel<address>
  {
  public:
    using txfe = FieldModel<address,  7, 0x00000001>;
    using inepne = FieldModel<address,  6, 0x00000001>;
    using ittxfe = FieldModel<address,  4, 0x00000001>;
    using toc = FieldModel<address,  3, 0x00000001>;
    using epdisd = FieldModel<address,  1, 0x00000001>;
    using xfrc = FieldModel<address,  0, 0x00000001>;

  };

public:
  using diepint1 = Diepint1Reg<BaseAddress + 0x0128>;

private:
  template <uint32_t address>
  class Diepint2Reg: public RegisterModel<address>
  {
  public:
    using txfe = FieldModel<address,  7, 0x00000001>;
    using inepne = FieldModel<address,  6, 0x00000001>;
    using ittxfe = FieldModel<address,  4, 0x00000001>;
    using toc = FieldModel<address,  3, 0x00000001>;
    using epdisd = FieldModel<address,  1, 0x00000001>;
    using xfrc = FieldModel<address,  0, 0x00000001>;

  };

public:
  using diepint2 = Diepint2Reg<BaseAddress + 0x0148>;

private:
  template <uint32_t address>
  class Diepint3Reg: public RegisterModel<address>
  {
  public:
    using txfe = FieldModel<address,  7, 0x00000001>;
    using inepne = FieldModel<address,  6, 0x00000001>;
    using ittxfe = FieldModel<address,  4, 0x00000001>;
    using toc = FieldModel<address,  3, 0x00000001>;
    using epdisd = FieldModel<address,  1, 0x00000001>;
    using xfrc = FieldModel<address,  0, 0x00000001>;

  };

public:
  using diepint3 = Diepint3Reg<BaseAddress + 0x0168>;

private:
  template <uint32_t address>
  class Doepint0Reg: public RegisterModel<address>
  {
  public:
    using b2bstup = FieldModel<address,  6, 0x00000001>;
    using otepdis = FieldModel<address,  4, 0x00000001>;
    using stup = FieldModel<address,  3, 0x00000001>;
    using epdisd = FieldModel<address,  1, 0x00000001>;
    using xfrc = FieldModel<address,  0, 0x00000001>;

  };

public:
  using doepint0 = Doepint0Reg<BaseAddress + 0x0308>;

private:
  template <uint32_t address>
  class Doepint1Reg: public RegisterModel<address>
  {
  public:
    using b2bstup = FieldModel<address,  6, 0x00000001>;
    using otepdis = FieldModel<address,  4, 0x00000001>;
    using stup = FieldModel<address,  3, 0x00000001>;
    using epdisd = FieldModel<address,  1, 0x00000001>;
    using xfrc = FieldModel<address,  0, 0x00000001>;

  };

public:
  using doepint1 = Doepint1Reg<BaseAddress + 0x0328>;

private:
  template <uint32_t address>
  class Doepint2Reg: public RegisterModel<address>
  {
  public:
    using b2bstup = FieldModel<address,  6, 0x00000001>;
    using otepdis = FieldModel<address,  4, 0x00000001>;
    using stup = FieldModel<address,  3, 0x00000001>;
    using epdisd = FieldModel<address,  1, 0x00000001>;
    using xfrc = FieldModel<address,  0, 0x00000001>;

  };

public:
  using doepint2 = Doepint2Reg<BaseAddress + 0x0348>;

private:
  template <uint32_t address>
  class Doepint3Reg: public RegisterModel<address>
  {
  public:
    using b2bstup = FieldModel<address,  6, 0x00000001>;
    using otepdis = FieldModel<address,  4, 0x00000001>;
    using stup = FieldModel<address,  3, 0x00000001>;
    using epdisd = FieldModel<address,  1, 0x00000001>;
    using xfrc = FieldModel<address,  0, 0x00000001>;

  };

public:
  using doepint3 = Doepint3Reg<BaseAddress + 0x0368>;

private:
  template <uint32_t address>
  class Dieptsiz0Reg: public RegisterModel<address>
  {
  public:
    using pktcnt = FieldModel<address, 19, 0x00000003>;
    using xfrsiz = FieldModel<address,  0, 0x0000007F>;

  };

public:
  using dieptsiz0 = Dieptsiz0Reg<BaseAddress + 0x0110>;

private:
  template <uint32_t address>
  class Doeptsiz0Reg: public RegisterModel<address>
  {
  public:
    using stupcnt = FieldModel<address, 29, 0x00000003>;
    using pktcnt = FieldModel<address, 19, 0x00000001>;
    using xfrsiz = FieldModel<address,  0, 0x0000007F>;

  };

public:
  using doeptsiz0 = Doeptsiz0Reg<BaseAddress + 0x0310>;

private:
  template <uint32_t address>
  class Dieptsiz1Reg: public RegisterModel<address>
  {
  public:
    using mcnt = FieldModel<address, 29, 0x00000003>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;

  };

public:
  using dieptsiz1 = Dieptsiz1Reg<BaseAddress + 0x0130>;

private:
  template <uint32_t address>
  class Dieptsiz2Reg: public RegisterModel<address>
  {
  public:
    using mcnt = FieldModel<address, 29, 0x00000003>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;

  };

public:
  using dieptsiz2 = Dieptsiz2Reg<BaseAddress + 0x0150>;

private:
  template <uint32_t address>
  class Dieptsiz3Reg: public RegisterModel<address>
  {
  public:
    using mcnt = FieldModel<address, 29, 0x00000003>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;

  };

public:
  using dieptsiz3 = Dieptsiz3Reg<BaseAddress + 0x0170>;

private:
  template <uint32_t address>
  class Dtxfsts0Reg: public RegisterModel<address>
  {
  public:
    using ineptfsav = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using dtxfsts0 = Dtxfsts0Reg<BaseAddress + 0x0118>;

private:
  template <uint32_t address>
  class Dtxfsts1Reg: public RegisterModel<address>
  {
  public:
    using ineptfsav = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using dtxfsts1 = Dtxfsts1Reg<BaseAddress + 0x0138>;

private:
  template <uint32_t address>
  class Dtxfsts2Reg: public RegisterModel<address>
  {
  public:
    using ineptfsav = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using dtxfsts2 = Dtxfsts2Reg<BaseAddress + 0x0158>;

private:
  template <uint32_t address>
  class Dtxfsts3Reg: public RegisterModel<address>
  {
  public:
    using ineptfsav = FieldModel<address,  0, 0x0000FFFF>;

  };

public:
  using dtxfsts3 = Dtxfsts3Reg<BaseAddress + 0x0178>;

private:
  template <uint32_t address>
  class Doeptsiz1Reg: public RegisterModel<address>
  {
  public:
    using rxdpid_stupcnt = FieldModel<address, 29, 0x00000003>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;

  };

public:
  using doeptsiz1 = Doeptsiz1Reg<BaseAddress + 0x0330>;

private:
  template <uint32_t address>
  class Doeptsiz2Reg: public RegisterModel<address>
  {
  public:
    using rxdpid_stupcnt = FieldModel<address, 29, 0x00000003>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;

  };

public:
  using doeptsiz2 = Doeptsiz2Reg<BaseAddress + 0x0350>;

private:
  template <uint32_t address>
  class Doeptsiz3Reg: public RegisterModel<address>
  {
  public:
    using rxdpid_stupcnt = FieldModel<address, 29, 0x00000003>;
    using pktcnt = FieldModel<address, 19, 0x000003FF>;
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF>;

  };

public:
  using doeptsiz3 = Doeptsiz3Reg<BaseAddress + 0x0370>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class DiepctlxBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using epena = FieldModel<address, 31, 0x00000001, bankOffset>;
    using epdis = FieldModel<address, 30, 0x00000001, bankOffset>;
    using soddfrm = FieldModel<address, 29, 0x00000001, bankOffset>;
    using sd0pid_sevnfrm = FieldModel<address, 28, 0x00000001, bankOffset>;
    using snak = FieldModel<address, 27, 0x00000001, bankOffset>;
    using cnak = FieldModel<address, 26, 0x00000001, bankOffset>;
    using txfnum = FieldModel<address, 22, 0x0000000F, bankOffset>;
    using stall = FieldModel<address, 21, 0x00000001, bankOffset>;
    using eptyp = FieldModel<address, 18, 0x00000003, bankOffset>;
    using naksts = FieldModel<address, 17, 0x00000001, bankOffset>;
    using eonum_dpid = FieldModel<address, 16, 0x00000001, bankOffset>;
    using usbaep = FieldModel<address, 15, 0x00000001, bankOffset>;
    using mpsiz = FieldModel<address,  0, 0x000007FF, bankOffset>;

  };

public:
  using diepctlx = DiepctlxBankReg<BaseAddress + 0x0140, 0x0020>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class DoepctlxBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using epena = FieldModel<address, 31, 0x00000001, bankOffset>;
    using epdis = FieldModel<address, 30, 0x00000001, bankOffset>;
    using soddfrm = FieldModel<address, 29, 0x00000001, bankOffset>;
    using sd0pid_sevnfrm = FieldModel<address, 28, 0x00000001, bankOffset>;
    using snak = FieldModel<address, 27, 0x00000001, bankOffset>;
    using cnak = FieldModel<address, 26, 0x00000001, bankOffset>;
    using stall = FieldModel<address, 21, 0x00000001, bankOffset>;
    using snpm = FieldModel<address, 20, 0x00000001, bankOffset>;
    using eptyp = FieldModel<address, 18, 0x00000003, bankOffset>;
    using naksts = FieldModel<address, 17, 0x00000001, bankOffset>;
    using eonum_dpid = FieldModel<address, 16, 0x00000001, bankOffset>;
    using usbaep = FieldModel<address, 15, 0x00000001, bankOffset>;
    using mpsiz = FieldModel<address,  0, 0x000007FF, bankOffset>;

  };

public:
  using doepctlx = DoepctlxBankReg<BaseAddress + 0x0320, 0x0020>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class DiepintxBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using txfe = FieldModel<address,  7, 0x00000001, bankOffset>;
    using inepne = FieldModel<address,  6, 0x00000001, bankOffset>;
    using ittxfe = FieldModel<address,  4, 0x00000001, bankOffset>;
    using toc = FieldModel<address,  3, 0x00000001, bankOffset>;
    using epdisd = FieldModel<address,  1, 0x00000001, bankOffset>;
    using xfrc = FieldModel<address,  0, 0x00000001, bankOffset>;

  };

public:
  using diepintx = DiepintxBankReg<BaseAddress + 0x0108, 0x0020>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class DoepintxBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using b2bstup = FieldModel<address,  6, 0x00000001, bankOffset>;
    using otepdis = FieldModel<address,  4, 0x00000001, bankOffset>;
    using stup = FieldModel<address,  3, 0x00000001, bankOffset>;
    using epdisd = FieldModel<address,  1, 0x00000001, bankOffset>;
    using xfrc = FieldModel<address,  0, 0x00000001, bankOffset>;

  };

public:
  using doepintx = DoepintxBankReg<BaseAddress + 0x0308, 0x0020>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class DieptsizxBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using mcnt = FieldModel<address, 29, 0x00000003, bankOffset>;
    using pktcnt = FieldModel<address, 19, 0x000003FF, bankOffset>;
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF, bankOffset>;

  };

public:
  using dieptsizx = DieptsizxBankReg<BaseAddress + 0x0130, 0x0020>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class DtxfstsxBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using ineptfsav = FieldModel<address,  0, 0x0000FFFF, bankOffset>;

  };

public:
  using dtxfstsx = DtxfstsxBankReg<BaseAddress + 0x0118, 0x0020>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class DoeptsizxBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using rxdpid_stupcnt = FieldModel<address, 29, 0x00000003, bankOffset>;
    using pktcnt = FieldModel<address, 19, 0x000003FF, bankOffset>;
    using xfrsiz = FieldModel<address,  0, 0x0007FFFF, bankOffset>;

  };

public:
  using doeptsizx = DoeptsizxBankReg<BaseAddress + 0x0330, 0x0020>;


};

}

#endif /* DRAL_STM32F411_OTG_FS_DEVICE_H */
