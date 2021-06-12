#ifndef DRAL_STM32F411_SDIO_H
#define DRAL_STM32F411_SDIO_H

#include "register_model.h"

namespace dral::stm32f411 {

class sdio
{
public:
  static constexpr uint32_t BaseAddress = 0x40012C00;

private:
  template <uint32_t address>
  class PowerReg: public RegisterModel<address>
  {
  public:
    using pwrctrl = FieldModel<address,  0, 0x00000003>;

  };

public:
  using power = PowerReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class ClkcrReg: public RegisterModel<address>
  {
  public:
    using hwfc_en = FieldModel<address, 14, 0x00000001>;
    using negedge = FieldModel<address, 13, 0x00000001>;
    using widbus = FieldModel<address, 11, 0x00000003>;
    using bypass = FieldModel<address, 10, 0x00000001>;
    using pwrsav = FieldModel<address,  9, 0x00000001>;
    using clken = FieldModel<address,  8, 0x00000001>;
    using clkdiv = FieldModel<address,  0, 0x000000FF>;

  };

public:
  using clkcr = ClkcrReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class ArgReg: public RegisterModel<address>
  {
  public:
    using cmdarg = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using arg = ArgReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class CmdReg: public RegisterModel<address>
  {
  public:
    using ce_atacmd = FieldModel<address, 14, 0x00000001>;
    using nien = FieldModel<address, 13, 0x00000001>;
    using encmdcompl = FieldModel<address, 12, 0x00000001>;
    using sdiosuspend = FieldModel<address, 11, 0x00000001>;
    using cpsmen = FieldModel<address, 10, 0x00000001>;
    using waitpend = FieldModel<address,  9, 0x00000001>;
    using waitint = FieldModel<address,  8, 0x00000001>;
    using waitresp = FieldModel<address,  6, 0x00000003>;
    using cmdindex = FieldModel<address,  0, 0x0000003F>;

  };

public:
  using cmd = CmdReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class RespcmdReg: public RegisterModel<address>
  {
  public:
    using respcmd = FieldModel<address,  0, 0x0000003F>;

  };

public:
  using respcmd = RespcmdReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class Resp1Reg: public RegisterModel<address>
  {
  public:
    using cardstatus1 = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using resp1 = Resp1Reg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class Resp2Reg: public RegisterModel<address>
  {
  public:
    using cardstatus2 = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using resp2 = Resp2Reg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class Resp3Reg: public RegisterModel<address>
  {
  public:
    using cardstatus3 = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using resp3 = Resp3Reg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class Resp4Reg: public RegisterModel<address>
  {
  public:
    using cardstatus4 = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using resp4 = Resp4Reg<BaseAddress + 0x0020>;

private:
  template <uint32_t address>
  class DtimerReg: public RegisterModel<address>
  {
  public:
    using datatime = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using dtimer = DtimerReg<BaseAddress + 0x0024>;

private:
  template <uint32_t address>
  class DlenReg: public RegisterModel<address>
  {
  public:
    using datalength = FieldModel<address,  0, 0x01FFFFFF>;

  };

public:
  using dlen = DlenReg<BaseAddress + 0x0028>;

private:
  template <uint32_t address>
  class DctrlReg: public RegisterModel<address>
  {
  public:
    using sdioen = FieldModel<address, 11, 0x00000001>;
    using rwmod = FieldModel<address, 10, 0x00000001>;
    using rwstop = FieldModel<address,  9, 0x00000001>;
    using rwstart = FieldModel<address,  8, 0x00000001>;
    using dblocksize = FieldModel<address,  4, 0x0000000F>;
    using dmaen = FieldModel<address,  3, 0x00000001>;
    using dtmode = FieldModel<address,  2, 0x00000001>;
    using dtdir = FieldModel<address,  1, 0x00000001>;
    using dten = FieldModel<address,  0, 0x00000001>;

  };

public:
  using dctrl = DctrlReg<BaseAddress + 0x002C>;

private:
  template <uint32_t address>
  class DcountReg: public RegisterModel<address>
  {
  public:
    using datacount = FieldModel<address,  0, 0x01FFFFFF>;

  };

public:
  using dcount = DcountReg<BaseAddress + 0x0030>;

private:
  template <uint32_t address>
  class StaReg: public RegisterModel<address>
  {
  public:
    using ceataend = FieldModel<address, 23, 0x00000001>;
    using sdioit = FieldModel<address, 22, 0x00000001>;
    using rxdavl = FieldModel<address, 21, 0x00000001>;
    using txdavl = FieldModel<address, 20, 0x00000001>;
    using rxfifoe = FieldModel<address, 19, 0x00000001>;
    using txfifoe = FieldModel<address, 18, 0x00000001>;
    using rxfifof = FieldModel<address, 17, 0x00000001>;
    using txfifof = FieldModel<address, 16, 0x00000001>;
    using rxfifohf = FieldModel<address, 15, 0x00000001>;
    using txfifohe = FieldModel<address, 14, 0x00000001>;
    using rxact = FieldModel<address, 13, 0x00000001>;
    using txact = FieldModel<address, 12, 0x00000001>;
    using cmdact = FieldModel<address, 11, 0x00000001>;
    using dbckend = FieldModel<address, 10, 0x00000001>;
    using stbiterr = FieldModel<address,  9, 0x00000001>;
    using dataend = FieldModel<address,  8, 0x00000001>;
    using cmdsent = FieldModel<address,  7, 0x00000001>;
    using cmdrend = FieldModel<address,  6, 0x00000001>;
    using rxoverr = FieldModel<address,  5, 0x00000001>;
    using txunderr = FieldModel<address,  4, 0x00000001>;
    using dtimeout = FieldModel<address,  3, 0x00000001>;
    using ctimeout = FieldModel<address,  2, 0x00000001>;
    using dcrcfail = FieldModel<address,  1, 0x00000001>;
    using ccrcfail = FieldModel<address,  0, 0x00000001>;

  };

public:
  using sta = StaReg<BaseAddress + 0x0034>;

private:
  template <uint32_t address>
  class IcrReg: public RegisterModel<address>
  {
  public:
    using ceataendc = FieldModel<address, 23, 0x00000001>;
    using sdioitc = FieldModel<address, 22, 0x00000001>;
    using dbckendc = FieldModel<address, 10, 0x00000001>;
    using stbiterrc = FieldModel<address,  9, 0x00000001>;
    using dataendc = FieldModel<address,  8, 0x00000001>;
    using cmdsentc = FieldModel<address,  7, 0x00000001>;
    using cmdrendc = FieldModel<address,  6, 0x00000001>;
    using rxoverrc = FieldModel<address,  5, 0x00000001>;
    using txunderrc = FieldModel<address,  4, 0x00000001>;
    using dtimeoutc = FieldModel<address,  3, 0x00000001>;
    using ctimeoutc = FieldModel<address,  2, 0x00000001>;
    using dcrcfailc = FieldModel<address,  1, 0x00000001>;
    using ccrcfailc = FieldModel<address,  0, 0x00000001>;

  };

public:
  using icr = IcrReg<BaseAddress + 0x0038>;

private:
  template <uint32_t address>
  class MaskReg: public RegisterModel<address>
  {
  public:
    using ceataendie = FieldModel<address, 23, 0x00000001>;
    using sdioitie = FieldModel<address, 22, 0x00000001>;
    using rxdavlie = FieldModel<address, 21, 0x00000001>;
    using txdavlie = FieldModel<address, 20, 0x00000001>;
    using rxfifoeie = FieldModel<address, 19, 0x00000001>;
    using txfifoeie = FieldModel<address, 18, 0x00000001>;
    using rxfifofie = FieldModel<address, 17, 0x00000001>;
    using txfifofie = FieldModel<address, 16, 0x00000001>;
    using rxfifohfie = FieldModel<address, 15, 0x00000001>;
    using txfifoheie = FieldModel<address, 14, 0x00000001>;
    using rxactie = FieldModel<address, 13, 0x00000001>;
    using txactie = FieldModel<address, 12, 0x00000001>;
    using cmdactie = FieldModel<address, 11, 0x00000001>;
    using dbckendie = FieldModel<address, 10, 0x00000001>;
    using stbiterrie = FieldModel<address,  9, 0x00000001>;
    using dataendie = FieldModel<address,  8, 0x00000001>;
    using cmdsentie = FieldModel<address,  7, 0x00000001>;
    using cmdrendie = FieldModel<address,  6, 0x00000001>;
    using rxoverrie = FieldModel<address,  5, 0x00000001>;
    using txunderrie = FieldModel<address,  4, 0x00000001>;
    using dtimeoutie = FieldModel<address,  3, 0x00000001>;
    using ctimeoutie = FieldModel<address,  2, 0x00000001>;
    using dcrcfailie = FieldModel<address,  1, 0x00000001>;
    using ccrcfailie = FieldModel<address,  0, 0x00000001>;

  };

public:
  using mask = MaskReg<BaseAddress + 0x003C>;

private:
  template <uint32_t address>
  class FifocntReg: public RegisterModel<address>
  {
  public:
    using fifocount = FieldModel<address,  0, 0x00FFFFFF>;

  };

public:
  using fifocnt = FifocntReg<BaseAddress + 0x0048>;

private:
  template <uint32_t address>
  class FifoReg: public RegisterModel<address>
  {
  public:
    using fifodata = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using fifo = FifoReg<BaseAddress + 0x0080>;


};

}

#endif /* DRAL_STM32F411_SDIO_H */
