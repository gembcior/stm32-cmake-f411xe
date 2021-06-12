#ifndef DRAL_STM32F411_STK_H
#define DRAL_STM32F411_STK_H

#include "register_model.h"

namespace dral::stm32f411 {

class stk
{
public:
  static constexpr uint32_t BaseAddress = 0xE000E010;

private:
  template <uint32_t address>
  class CtrlReg: public RegisterModel<address>
  {
  public:
    using enable = FieldModel<address,  0, 0x00000001>;
    using tickint = FieldModel<address,  1, 0x00000001>;
    using clksource = FieldModel<address,  2, 0x00000001>;
    using countflag = FieldModel<address, 16, 0x00000001>;

  };

public:
  using ctrl = CtrlReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class LoadReg: public RegisterModel<address>
  {
  public:
    using reload = FieldModel<address,  0, 0x00FFFFFF>;

  };

public:
  using load = LoadReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class ValReg: public RegisterModel<address>
  {
  public:
    using current = FieldModel<address,  0, 0x00FFFFFF>;

  };

public:
  using val = ValReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class CalibReg: public RegisterModel<address>
  {
  public:
    using tenms = FieldModel<address,  0, 0x00FFFFFF>;
    using skew = FieldModel<address, 30, 0x00000001>;
    using noref = FieldModel<address, 31, 0x00000001>;

  };

public:
  using calib = CalibReg<BaseAddress + 0x000C>;


};

}

#endif /* DRAL_STM32F411_STK_H */
