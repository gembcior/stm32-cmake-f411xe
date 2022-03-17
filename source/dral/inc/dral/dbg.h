#ifndef DRAL_STM32F411_DBG_H
#define DRAL_STM32F411_DBG_H

#include "register_model.h"

namespace dral::stm32f411 {

class dbg
{
public:
  static constexpr uint32_t BaseAddress = 0xE0042000;

private:
  template <uint32_t address>
  class Dbgmcu_idcodeReg: public RegisterModel<address>
  {
  public:
    using dev_id = FieldModel<address, 0, 0x00000FFF>;
    using rev_id = FieldModel<address, 16, 0x0000FFFF>;
  };

public:
  using dbgmcu_idcode = Dbgmcu_idcodeReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class Dbgmcu_crReg: public RegisterModel<address>
  {
  public:
    using dbg_sleep = FieldModel<address, 0, 0x00000001>;
    using dbg_stop = FieldModel<address, 1, 0x00000001>;
    using dbg_standby = FieldModel<address, 2, 0x00000001>;
    using trace_ioen = FieldModel<address, 5, 0x00000001>;
    using trace_mode = FieldModel<address, 6, 0x00000003>;
  };

public:
  using dbgmcu_cr = Dbgmcu_crReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class Dbgmcu_apb1_fzReg: public RegisterModel<address>
  {
  public:
    using dbg_tim2_stop = FieldModel<address, 0, 0x00000001>;
    using dbg_tim3_stop = FieldModel<address, 1, 0x00000001>;
    using dbg_tim4_stop = FieldModel<address, 2, 0x00000001>;
    using dbg_tim5_stop = FieldModel<address, 3, 0x00000001>;
    using dbg_rtc_stop = FieldModel<address, 10, 0x00000001>;
    using dbg_wwdg_stop = FieldModel<address, 11, 0x00000001>;
    using dbg_iwdeg_stop = FieldModel<address, 12, 0x00000001>;
    using dbg_i2c1_smbus_timeout = FieldModel<address, 21, 0x00000001>;
    using dbg_i2c2_smbus_timeout = FieldModel<address, 22, 0x00000001>;
    using dbg_i2c3smbus_timeout = FieldModel<address, 23, 0x00000001>;
  };

public:
  using dbgmcu_apb1_fz = Dbgmcu_apb1_fzReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class Dbgmcu_apb2_fzReg: public RegisterModel<address>
  {
  public:
    using dbg_tim1_stop = FieldModel<address, 0, 0x00000001>;
    using dbg_tim9_stop = FieldModel<address, 16, 0x00000001>;
    using dbg_tim10_stop = FieldModel<address, 17, 0x00000001>;
    using dbg_tim11_stop = FieldModel<address, 18, 0x00000001>;
  };

public:
  using dbgmcu_apb2_fz = Dbgmcu_apb2_fzReg<BaseAddress + 0x000C>;
};

}

#endif /* DRAL_STM32F411_DBG_H */
