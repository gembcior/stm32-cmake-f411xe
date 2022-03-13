#ifndef DRAL_STM32F411_OTG_FS_GLOBAL_H
#define DRAL_STM32F411_OTG_FS_GLOBAL_H

#include "register_model.h"

namespace dral::stm32f411 {

class otg_fs_global
{
public:
  static constexpr uint32_t BaseAddress = 0x50000000;

private:
  template <uint32_t address>
  class Fs_gotgctlReg: public RegisterModel<address>
  {
  public:
    using srqscs = FieldModel<address, 0, 0x00000001>;
    using srq = FieldModel<address, 1, 0x00000001>;
    using hngscs = FieldModel<address, 8, 0x00000001>;
    using hnprq = FieldModel<address, 9, 0x00000001>;
    using hshnpen = FieldModel<address, 10, 0x00000001>;
    using dhnpen = FieldModel<address, 11, 0x00000001>;
    using cidsts = FieldModel<address, 16, 0x00000001>;
    using dbct = FieldModel<address, 17, 0x00000001>;
    using asvld = FieldModel<address, 18, 0x00000001>;
    using bsvld = FieldModel<address, 19, 0x00000001>;
  };

public:
  using fs_gotgctl = Fs_gotgctlReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class Fs_gotgintReg: public RegisterModel<address>
  {
  public:
    using sedet = FieldModel<address, 2, 0x00000001>;
    using srsschg = FieldModel<address, 8, 0x00000001>;
    using hnsschg = FieldModel<address, 9, 0x00000001>;
    using hngdet = FieldModel<address, 17, 0x00000001>;
    using adtochg = FieldModel<address, 18, 0x00000001>;
    using dbcdne = FieldModel<address, 19, 0x00000001>;
  };

public:
  using fs_gotgint = Fs_gotgintReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class Fs_gahbcfgReg: public RegisterModel<address>
  {
  public:
    using gint = FieldModel<address, 0, 0x00000001>;
    using txfelvl = FieldModel<address, 7, 0x00000001>;
    using ptxfelvl = FieldModel<address, 8, 0x00000001>;
  };

public:
  using fs_gahbcfg = Fs_gahbcfgReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class Fs_gusbcfgReg: public RegisterModel<address>
  {
  public:
    using tocal = FieldModel<address, 0, 0x00000007>;
    using physel = FieldModel<address, 6, 0x00000001>;
    using srpcap = FieldModel<address, 8, 0x00000001>;
    using hnpcap = FieldModel<address, 9, 0x00000001>;
    using trdt = FieldModel<address, 10, 0x0000000F>;
    using fhmod = FieldModel<address, 29, 0x00000001>;
    using fdmod = FieldModel<address, 30, 0x00000001>;
    using ctxpkt = FieldModel<address, 31, 0x00000001>;
  };

public:
  using fs_gusbcfg = Fs_gusbcfgReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class Fs_grstctlReg: public RegisterModel<address>
  {
  public:
    using csrst = FieldModel<address, 0, 0x00000001>;
    using hsrst = FieldModel<address, 1, 0x00000001>;
    using fcrst = FieldModel<address, 2, 0x00000001>;
    using rxfflsh = FieldModel<address, 4, 0x00000001>;
    using txfflsh = FieldModel<address, 5, 0x00000001>;
    using txfnum = FieldModel<address, 6, 0x0000001F>;
    using ahbidl = FieldModel<address, 31, 0x00000001>;
  };

public:
  using fs_grstctl = Fs_grstctlReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class Fs_gintstsReg: public RegisterModel<address>
  {
  public:
    using cmod = FieldModel<address, 0, 0x00000001>;
    using mmis = FieldModel<address, 1, 0x00000001>;
    using otgint = FieldModel<address, 2, 0x00000001>;
    using sof = FieldModel<address, 3, 0x00000001>;
    using rxflvl = FieldModel<address, 4, 0x00000001>;
    using nptxfe = FieldModel<address, 5, 0x00000001>;
    using ginakeff = FieldModel<address, 6, 0x00000001>;
    using goutnakeff = FieldModel<address, 7, 0x00000001>;
    using esusp = FieldModel<address, 10, 0x00000001>;
    using usbsusp = FieldModel<address, 11, 0x00000001>;
    using usbrst = FieldModel<address, 12, 0x00000001>;
    using enumdne = FieldModel<address, 13, 0x00000001>;
    using isoodrp = FieldModel<address, 14, 0x00000001>;
    using eopf = FieldModel<address, 15, 0x00000001>;
    using iepint = FieldModel<address, 18, 0x00000001>;
    using oepint = FieldModel<address, 19, 0x00000001>;
    using iisoixfr = FieldModel<address, 20, 0x00000001>;
    using ipxfr_incompisoout = FieldModel<address, 21, 0x00000001>;
    using hprtint = FieldModel<address, 24, 0x00000001>;
    using hcint = FieldModel<address, 25, 0x00000001>;
    using ptxfe = FieldModel<address, 26, 0x00000001>;
    using cidschg = FieldModel<address, 28, 0x00000001>;
    using discint = FieldModel<address, 29, 0x00000001>;
    using srqint = FieldModel<address, 30, 0x00000001>;
    using wkupint = FieldModel<address, 31, 0x00000001>;
  };

public:
  using fs_gintsts = Fs_gintstsReg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class Fs_gintmskReg: public RegisterModel<address>
  {
  public:
    using mmism = FieldModel<address, 1, 0x00000001>;
    using otgint = FieldModel<address, 2, 0x00000001>;
    using sofm = FieldModel<address, 3, 0x00000001>;
    using rxflvlm = FieldModel<address, 4, 0x00000001>;
    using nptxfem = FieldModel<address, 5, 0x00000001>;
    using ginakeffm = FieldModel<address, 6, 0x00000001>;
    using gonakeffm = FieldModel<address, 7, 0x00000001>;
    using esuspm = FieldModel<address, 10, 0x00000001>;
    using usbsuspm = FieldModel<address, 11, 0x00000001>;
    using usbrst = FieldModel<address, 12, 0x00000001>;
    using enumdnem = FieldModel<address, 13, 0x00000001>;
    using isoodrpm = FieldModel<address, 14, 0x00000001>;
    using eopfm = FieldModel<address, 15, 0x00000001>;
    using epmism = FieldModel<address, 17, 0x00000001>;
    using iepint = FieldModel<address, 18, 0x00000001>;
    using oepint = FieldModel<address, 19, 0x00000001>;
    using iisoixfrm = FieldModel<address, 20, 0x00000001>;
    using ipxfrm_iisooxfrm = FieldModel<address, 21, 0x00000001>;
    using prtim = FieldModel<address, 24, 0x00000001>;
    using hcim = FieldModel<address, 25, 0x00000001>;
    using ptxfem = FieldModel<address, 26, 0x00000001>;
    using cidschgm = FieldModel<address, 28, 0x00000001>;
    using discint = FieldModel<address, 29, 0x00000001>;
    using srqim = FieldModel<address, 30, 0x00000001>;
    using wuim = FieldModel<address, 31, 0x00000001>;
  };

public:
  using fs_gintmsk = Fs_gintmskReg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class Fs_grxstsr_deviceReg: public RegisterModel<address>
  {
  public:
    using epnum = FieldModel<address, 0, 0x0000000F>;
    using bcnt = FieldModel<address, 4, 0x000007FF>;
    using dpid = FieldModel<address, 15, 0x00000003>;
    using pktsts = FieldModel<address, 17, 0x0000000F>;
    using frmnum = FieldModel<address, 21, 0x0000000F>;
  };

public:
  using fs_grxstsr_device = Fs_grxstsr_deviceReg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class Fs_grxstsr_hostReg: public RegisterModel<address>
  {
  public:
    using chnum = FieldModel<address, 0, 0x0000000F>;
    using bcnt = FieldModel<address, 4, 0x000007FF>;
    using dpid = FieldModel<address, 15, 0x00000003>;
    using pktsts = FieldModel<address, 17, 0x0000000F>;
  };

public:
  using fs_grxstsr_host = Fs_grxstsr_hostReg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class Fs_grxstsp_deviceReg: public RegisterModel<address>
  {
  public:
    using epnum = FieldModel<address, 0, 0x0000000F>;
    using bcnt = FieldModel<address, 4, 0x000007FF>;
    using dpid = FieldModel<address, 15, 0x00000003>;
    using pktsts = FieldModel<address, 17, 0x0000000F>;
    using frmnum = FieldModel<address, 21, 0x0000000F>;
  };

public:
  using fs_grxstsp_device = Fs_grxstsp_deviceReg<BaseAddress + 0x0020>;

private:
  template <uint32_t address>
  class Fs_grxstsp_hostReg: public RegisterModel<address>
  {
  public:
    using chnum = FieldModel<address, 0, 0x0000000F>;
    using bcnt = FieldModel<address, 4, 0x000007FF>;
    using dpid = FieldModel<address, 15, 0x00000003>;
    using pktsts = FieldModel<address, 17, 0x0000000F>;
  };

public:
  using fs_grxstsp_host = Fs_grxstsp_hostReg<BaseAddress + 0x0020>;

private:
  template <uint32_t address>
  class Fs_grxfsizReg: public RegisterModel<address>
  {
  public:
    using rxfd = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using fs_grxfsiz = Fs_grxfsizReg<BaseAddress + 0x0024>;

private:
  template <uint32_t address>
  class Fs_gnptxfsiz_deviceReg: public RegisterModel<address>
  {
  public:
    using tx0fsa = FieldModel<address, 0, 0x0000FFFF>;
    using tx0fd = FieldModel<address, 16, 0x0000FFFF>;
  };

public:
  using fs_gnptxfsiz_device = Fs_gnptxfsiz_deviceReg<BaseAddress + 0x0028>;

private:
  template <uint32_t address>
  class Fs_gnptxfsiz_hostReg: public RegisterModel<address>
  {
  public:
    using nptxfsa = FieldModel<address, 0, 0x0000FFFF>;
    using nptxfd = FieldModel<address, 16, 0x0000FFFF>;
  };

public:
  using fs_gnptxfsiz_host = Fs_gnptxfsiz_hostReg<BaseAddress + 0x0028>;

private:
  template <uint32_t address>
  class Fs_gnptxstsReg: public RegisterModel<address>
  {
  public:
    using nptxfsav = FieldModel<address, 0, 0x0000FFFF>;
    using nptqxsav = FieldModel<address, 16, 0x000000FF>;
    using nptxqtop = FieldModel<address, 24, 0x0000007F>;
  };

public:
  using fs_gnptxsts = Fs_gnptxstsReg<BaseAddress + 0x002C>;

private:
  template <uint32_t address>
  class Fs_gccfgReg: public RegisterModel<address>
  {
  public:
    using pwrdwn = FieldModel<address, 16, 0x00000001>;
    using vbusasen = FieldModel<address, 18, 0x00000001>;
    using vbusbsen = FieldModel<address, 19, 0x00000001>;
    using sofouten = FieldModel<address, 20, 0x00000001>;
    using novbussens = FieldModel<address, 21, 0x00000001>;
  };

public:
  using fs_gccfg = Fs_gccfgReg<BaseAddress + 0x0038>;

private:
  template <uint32_t address>
  class Fs_cidReg: public RegisterModel<address>
  {
  public:
    using product_id = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using fs_cid = Fs_cidReg<BaseAddress + 0x003C>;

private:
  template <uint32_t address>
  class Fs_hptxfsizReg: public RegisterModel<address>
  {
  public:
    using ptxsa = FieldModel<address, 0, 0x0000FFFF>;
    using ptxfsiz = FieldModel<address, 16, 0x0000FFFF>;
  };

public:
  using fs_hptxfsiz = Fs_hptxfsizReg<BaseAddress + 0x0100>;

private:
  template <uint32_t address>
  class Fs_dieptxf1Reg: public RegisterModel<address>
  {
  public:
    using ineptxsa = FieldModel<address, 0, 0x0000FFFF>;
    using ineptxfd = FieldModel<address, 16, 0x0000FFFF>;
  };

public:
  using fs_dieptxf1 = Fs_dieptxf1Reg<BaseAddress + 0x0104>;

private:
  template <uint32_t address>
  class Fs_dieptxf2Reg: public RegisterModel<address>
  {
  public:
    using ineptxsa = FieldModel<address, 0, 0x0000FFFF>;
    using ineptxfd = FieldModel<address, 16, 0x0000FFFF>;
  };

public:
  using fs_dieptxf2 = Fs_dieptxf2Reg<BaseAddress + 0x0108>;

private:
  template <uint32_t address>
  class Fs_dieptxf3Reg: public RegisterModel<address>
  {
  public:
    using ineptxsa = FieldModel<address, 0, 0x0000FFFF>;
    using ineptxfd = FieldModel<address, 16, 0x0000FFFF>;
  };

public:
  using fs_dieptxf3 = Fs_dieptxf3Reg<BaseAddress + 0x010C>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class Fs_grxstsx_deviceBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using epnum = FieldModel<address, 0, 0x0000000F, bankOffset>;
    using bcnt = FieldModel<address, 4, 0x000007FF, bankOffset>;
    using dpid = FieldModel<address, 15, 0x00000003, bankOffset>;
    using pktsts = FieldModel<address, 17, 0x0000000F, bankOffset>;
    using frmnum = FieldModel<address, 21, 0x0000000F, bankOffset>;
  };

public:
  using fs_grxstsx_device = Fs_grxstsx_deviceBankReg<BaseAddress + 0x001C, 0x0004>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class Fs_grxstsx_hostBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using chnum = FieldModel<address, 0, 0x0000000F, bankOffset>;
    using bcnt = FieldModel<address, 4, 0x000007FF, bankOffset>;
    using dpid = FieldModel<address, 15, 0x00000003, bankOffset>;
    using pktsts = FieldModel<address, 17, 0x0000000F, bankOffset>;
  };

public:
  using fs_grxstsx_host = Fs_grxstsx_hostBankReg<BaseAddress + 0x001C, 0x0004>;
};

}

#endif /* DRAL_STM32F411_OTG_FS_GLOBAL_H */
