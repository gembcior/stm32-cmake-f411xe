#ifndef DRAL_STM32F411_MPU_H
#define DRAL_STM32F411_MPU_H

#include "register_model.h"

namespace dral::stm32f411 {

class mpu
{
public:
  static constexpr uint32_t BaseAddress = 0xE000ED90;

private:
  template <uint32_t address>
  class Mpu_typerReg: public RegisterModel<address>
  {
  public:
    using separate = FieldModel<address, 0, 0x00000001>;
    using dregion = FieldModel<address, 8, 0x000000FF>;
    using iregion = FieldModel<address, 16, 0x000000FF>;
  };

public:
  using mpu_typer = Mpu_typerReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class Mpu_ctrlReg: public RegisterModel<address>
  {
  public:
    using enable = FieldModel<address, 0, 0x00000001>;
    using hfnmiena = FieldModel<address, 1, 0x00000001>;
    using privdefena = FieldModel<address, 2, 0x00000001>;
  };

public:
  using mpu_ctrl = Mpu_ctrlReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class Mpu_rnrReg: public RegisterModel<address>
  {
  public:
    using region = FieldModel<address, 0, 0x000000FF>;
  };

public:
  using mpu_rnr = Mpu_rnrReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class Mpu_rbarReg: public RegisterModel<address>
  {
  public:
    using region = FieldModel<address, 0, 0x0000000F>;
    using valid = FieldModel<address, 4, 0x00000001>;
    using addr = FieldModel<address, 5, 0x07FFFFFF>;
  };

public:
  using mpu_rbar = Mpu_rbarReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class Mpu_rasrReg: public RegisterModel<address>
  {
  public:
    using enable = FieldModel<address, 0, 0x00000001>;
    using size = FieldModel<address, 1, 0x0000001F>;
    using srd = FieldModel<address, 8, 0x000000FF>;
    using b = FieldModel<address, 16, 0x00000001>;
    using c = FieldModel<address, 17, 0x00000001>;
    using s = FieldModel<address, 18, 0x00000001>;
    using tex = FieldModel<address, 19, 0x00000007>;
    using ap = FieldModel<address, 24, 0x00000007>;
    using xn = FieldModel<address, 28, 0x00000001>;
  };

public:
  using mpu_rasr = Mpu_rasrReg<BaseAddress + 0x0010>;
};

}

#endif /* DRAL_STM32F411_MPU_H */
