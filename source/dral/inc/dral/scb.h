#ifndef DRAL_STM32F411_SCB_H
#define DRAL_STM32F411_SCB_H

#include "register_model.h"

namespace dral::stm32f411 {

class scb
{
public:
  static constexpr uint32_t BaseAddress = 0xE000ED00;

private:
  template <uint32_t address>
  class CpuidReg: public RegisterModel<address>
  {
  public:
    using revision = FieldModel<address,  0, 0x0000000F>;
    using partno = FieldModel<address,  4, 0x00000FFF>;
    using constant = FieldModel<address, 16, 0x0000000F>;
    using variant = FieldModel<address, 20, 0x0000000F>;
    using implementer = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using cpuid = CpuidReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class IcsrReg: public RegisterModel<address>
  {
  public:
    using vectactive = FieldModel<address,  0, 0x000001FF>;
    using rettobase = FieldModel<address, 11, 0x00000001>;
    using vectpending = FieldModel<address, 12, 0x0000007F>;
    using isrpending = FieldModel<address, 22, 0x00000001>;
    using pendstclr = FieldModel<address, 25, 0x00000001>;
    using pendstset = FieldModel<address, 26, 0x00000001>;
    using pendsvclr = FieldModel<address, 27, 0x00000001>;
    using pendsvset = FieldModel<address, 28, 0x00000001>;
    using nmipendset = FieldModel<address, 31, 0x00000001>;

  };

public:
  using icsr = IcsrReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class VtorReg: public RegisterModel<address>
  {
  public:
    using tbloff = FieldModel<address,  9, 0x001FFFFF>;

  };

public:
  using vtor = VtorReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class AircrReg: public RegisterModel<address>
  {
  public:
    using vectreset = FieldModel<address,  0, 0x00000001>;
    using vectclractive = FieldModel<address,  1, 0x00000001>;
    using sysresetreq = FieldModel<address,  2, 0x00000001>;
    using prigroup = FieldModel<address,  8, 0x00000007>;
    using endianess = FieldModel<address, 15, 0x00000001>;
    using vectkeystat = FieldModel<address, 16, 0x0000FFFF>;

  };

public:
  using aircr = AircrReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class ScrReg: public RegisterModel<address>
  {
  public:
    using sleeponexit = FieldModel<address,  1, 0x00000001>;
    using sleepdeep = FieldModel<address,  2, 0x00000001>;
    using seveonpend = FieldModel<address,  4, 0x00000001>;

  };

public:
  using scr = ScrReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class CcrReg: public RegisterModel<address>
  {
  public:
    using nonbasethrdena = FieldModel<address,  0, 0x00000001>;
    using usersetmpend = FieldModel<address,  1, 0x00000001>;
    using unalign__trp = FieldModel<address,  3, 0x00000001>;
    using div_0_trp = FieldModel<address,  4, 0x00000001>;
    using bfhfnmign = FieldModel<address,  8, 0x00000001>;
    using stkalign = FieldModel<address,  9, 0x00000001>;

  };

public:
  using ccr = CcrReg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class Shpr1Reg: public RegisterModel<address>
  {
  public:
    using pri_4 = FieldModel<address,  0, 0x000000FF>;
    using pri_5 = FieldModel<address,  8, 0x000000FF>;
    using pri_6 = FieldModel<address, 16, 0x000000FF>;

  };

public:
  using shpr1 = Shpr1Reg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class Shpr2Reg: public RegisterModel<address>
  {
  public:
    using pri_11 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using shpr2 = Shpr2Reg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class Shpr3Reg: public RegisterModel<address>
  {
  public:
    using pri_14 = FieldModel<address, 16, 0x000000FF>;
    using pri_15 = FieldModel<address, 24, 0x000000FF>;

  };

public:
  using shpr3 = Shpr3Reg<BaseAddress + 0x0020>;

private:
  template <uint32_t address>
  class ShcrsReg: public RegisterModel<address>
  {
  public:
    using memfaultact = FieldModel<address,  0, 0x00000001>;
    using busfaultact = FieldModel<address,  1, 0x00000001>;
    using usgfaultact = FieldModel<address,  3, 0x00000001>;
    using svcallact = FieldModel<address,  7, 0x00000001>;
    using monitoract = FieldModel<address,  8, 0x00000001>;
    using pendsvact = FieldModel<address, 10, 0x00000001>;
    using systickact = FieldModel<address, 11, 0x00000001>;
    using usgfaultpended = FieldModel<address, 12, 0x00000001>;
    using memfaultpended = FieldModel<address, 13, 0x00000001>;
    using busfaultpended = FieldModel<address, 14, 0x00000001>;
    using svcallpended = FieldModel<address, 15, 0x00000001>;
    using memfaultena = FieldModel<address, 16, 0x00000001>;
    using busfaultena = FieldModel<address, 17, 0x00000001>;
    using usgfaultena = FieldModel<address, 18, 0x00000001>;

  };

public:
  using shcrs = ShcrsReg<BaseAddress + 0x0024>;

private:
  template <uint32_t address>
  class Cfsr_ufsr_bfsr_mmfsrReg: public RegisterModel<address>
  {
  public:
    using iaccviol = FieldModel<address,  1, 0x00000001>;
    using munstkerr = FieldModel<address,  3, 0x00000001>;
    using mstkerr = FieldModel<address,  4, 0x00000001>;
    using mlsperr = FieldModel<address,  5, 0x00000001>;
    using mmarvalid = FieldModel<address,  7, 0x00000001>;
    using ibuserr = FieldModel<address,  8, 0x00000001>;
    using preciserr = FieldModel<address,  9, 0x00000001>;
    using impreciserr = FieldModel<address, 10, 0x00000001>;
    using unstkerr = FieldModel<address, 11, 0x00000001>;
    using stkerr = FieldModel<address, 12, 0x00000001>;
    using lsperr = FieldModel<address, 13, 0x00000001>;
    using bfarvalid = FieldModel<address, 15, 0x00000001>;
    using undefinstr = FieldModel<address, 16, 0x00000001>;
    using invstate = FieldModel<address, 17, 0x00000001>;
    using invpc = FieldModel<address, 18, 0x00000001>;
    using nocp = FieldModel<address, 19, 0x00000001>;
    using unaligned = FieldModel<address, 24, 0x00000001>;
    using divbyzero = FieldModel<address, 25, 0x00000001>;

  };

public:
  using cfsr_ufsr_bfsr_mmfsr = Cfsr_ufsr_bfsr_mmfsrReg<BaseAddress + 0x0028>;

private:
  template <uint32_t address>
  class HfsrReg: public RegisterModel<address>
  {
  public:
    using vecttbl = FieldModel<address,  1, 0x00000001>;
    using forced = FieldModel<address, 30, 0x00000001>;
    using debug_vt = FieldModel<address, 31, 0x00000001>;

  };

public:
  using hfsr = HfsrReg<BaseAddress + 0x002C>;

private:
  template <uint32_t address>
  class MmfarReg: public RegisterModel<address>
  {
  public:
    using mmfar = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using mmfar = MmfarReg<BaseAddress + 0x0034>;

private:
  template <uint32_t address>
  class BfarReg: public RegisterModel<address>
  {
  public:
    using bfar = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using bfar = BfarReg<BaseAddress + 0x0038>;

private:
  template <uint32_t address>
  class AfsrReg: public RegisterModel<address>
  {
  public:
    using impdef = FieldModel<address,  0, 0xFFFFFFFF>;

  };

public:
  using afsr = AfsrReg<BaseAddress + 0x003C>;


};

}

#endif /* DRAL_STM32F411_SCB_H */
