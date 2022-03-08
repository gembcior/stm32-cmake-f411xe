#ifndef DRAL_STM32F411_CRC_H
#define DRAL_STM32F411_CRC_H

#include "register_model.h"

namespace dral::stm32f411 {

class crc
{
public:
  static constexpr uint32_t BaseAddress = 0x40023000;

private:
  template <uint32_t address>
  class DrReg: public RegisterModel<address>
  {
  public:
    using dr = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using dr = DrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class IdrReg: public RegisterModel<address>
  {
  public:
    using idr = FieldModel<address, 0, 0x000000FF>;
  };

public:
  using idr = IdrReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class CrReg: public RegisterModel<address>
  {
  public:
    using cr = FieldModel<address, 0, 0x00000001>;
  };

public:
  using cr = CrReg<BaseAddress + 0x0008>;
};

}

#endif /* DRAL_STM32F411_CRC_H */
