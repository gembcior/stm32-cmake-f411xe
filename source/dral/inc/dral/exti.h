#ifndef DRAL_STM32F411_EXTI_H
#define DRAL_STM32F411_EXTI_H

#include "register_model.h"

namespace dral::stm32f411 {

class exti
{
public:
  static constexpr uint32_t BaseAddress = 0x40013C00;

private:
  template <uint32_t address>
  class ImrReg: public RegisterModel<address>
  {
  public:
    using mr0 = FieldModel<address, 0, 0x00000001>;
    using mr1 = FieldModel<address, 1, 0x00000001>;
    using mr2 = FieldModel<address, 2, 0x00000001>;
    using mr3 = FieldModel<address, 3, 0x00000001>;
    using mr4 = FieldModel<address, 4, 0x00000001>;
    using mr5 = FieldModel<address, 5, 0x00000001>;
    using mr6 = FieldModel<address, 6, 0x00000001>;
    using mr7 = FieldModel<address, 7, 0x00000001>;
    using mr8 = FieldModel<address, 8, 0x00000001>;
    using mr9 = FieldModel<address, 9, 0x00000001>;
    using mr10 = FieldModel<address, 10, 0x00000001>;
    using mr11 = FieldModel<address, 11, 0x00000001>;
    using mr12 = FieldModel<address, 12, 0x00000001>;
    using mr13 = FieldModel<address, 13, 0x00000001>;
    using mr14 = FieldModel<address, 14, 0x00000001>;
    using mr15 = FieldModel<address, 15, 0x00000001>;
    using mr16 = FieldModel<address, 16, 0x00000001>;
    using mr17 = FieldModel<address, 17, 0x00000001>;
    using mr18 = FieldModel<address, 18, 0x00000001>;
    using mr19 = FieldModel<address, 19, 0x00000001>;
    using mr20 = FieldModel<address, 20, 0x00000001>;
    using mr21 = FieldModel<address, 21, 0x00000001>;
    using mr22 = FieldModel<address, 22, 0x00000001>;
  };

public:
  using imr = ImrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class EmrReg: public RegisterModel<address>
  {
  public:
    using mr0 = FieldModel<address, 0, 0x00000001>;
    using mr1 = FieldModel<address, 1, 0x00000001>;
    using mr2 = FieldModel<address, 2, 0x00000001>;
    using mr3 = FieldModel<address, 3, 0x00000001>;
    using mr4 = FieldModel<address, 4, 0x00000001>;
    using mr5 = FieldModel<address, 5, 0x00000001>;
    using mr6 = FieldModel<address, 6, 0x00000001>;
    using mr7 = FieldModel<address, 7, 0x00000001>;
    using mr8 = FieldModel<address, 8, 0x00000001>;
    using mr9 = FieldModel<address, 9, 0x00000001>;
    using mr10 = FieldModel<address, 10, 0x00000001>;
    using mr11 = FieldModel<address, 11, 0x00000001>;
    using mr12 = FieldModel<address, 12, 0x00000001>;
    using mr13 = FieldModel<address, 13, 0x00000001>;
    using mr14 = FieldModel<address, 14, 0x00000001>;
    using mr15 = FieldModel<address, 15, 0x00000001>;
    using mr16 = FieldModel<address, 16, 0x00000001>;
    using mr17 = FieldModel<address, 17, 0x00000001>;
    using mr18 = FieldModel<address, 18, 0x00000001>;
    using mr19 = FieldModel<address, 19, 0x00000001>;
    using mr20 = FieldModel<address, 20, 0x00000001>;
    using mr21 = FieldModel<address, 21, 0x00000001>;
    using mr22 = FieldModel<address, 22, 0x00000001>;
  };

public:
  using emr = EmrReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class RtsrReg: public RegisterModel<address>
  {
  public:
    using tr0 = FieldModel<address, 0, 0x00000001>;
    using tr1 = FieldModel<address, 1, 0x00000001>;
    using tr2 = FieldModel<address, 2, 0x00000001>;
    using tr3 = FieldModel<address, 3, 0x00000001>;
    using tr4 = FieldModel<address, 4, 0x00000001>;
    using tr5 = FieldModel<address, 5, 0x00000001>;
    using tr6 = FieldModel<address, 6, 0x00000001>;
    using tr7 = FieldModel<address, 7, 0x00000001>;
    using tr8 = FieldModel<address, 8, 0x00000001>;
    using tr9 = FieldModel<address, 9, 0x00000001>;
    using tr10 = FieldModel<address, 10, 0x00000001>;
    using tr11 = FieldModel<address, 11, 0x00000001>;
    using tr12 = FieldModel<address, 12, 0x00000001>;
    using tr13 = FieldModel<address, 13, 0x00000001>;
    using tr14 = FieldModel<address, 14, 0x00000001>;
    using tr15 = FieldModel<address, 15, 0x00000001>;
    using tr16 = FieldModel<address, 16, 0x00000001>;
    using tr17 = FieldModel<address, 17, 0x00000001>;
    using tr18 = FieldModel<address, 18, 0x00000001>;
    using tr19 = FieldModel<address, 19, 0x00000001>;
    using tr20 = FieldModel<address, 20, 0x00000001>;
    using tr21 = FieldModel<address, 21, 0x00000001>;
    using tr22 = FieldModel<address, 22, 0x00000001>;
  };

public:
  using rtsr = RtsrReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class FtsrReg: public RegisterModel<address>
  {
  public:
    using tr0 = FieldModel<address, 0, 0x00000001>;
    using tr1 = FieldModel<address, 1, 0x00000001>;
    using tr2 = FieldModel<address, 2, 0x00000001>;
    using tr3 = FieldModel<address, 3, 0x00000001>;
    using tr4 = FieldModel<address, 4, 0x00000001>;
    using tr5 = FieldModel<address, 5, 0x00000001>;
    using tr6 = FieldModel<address, 6, 0x00000001>;
    using tr7 = FieldModel<address, 7, 0x00000001>;
    using tr8 = FieldModel<address, 8, 0x00000001>;
    using tr9 = FieldModel<address, 9, 0x00000001>;
    using tr10 = FieldModel<address, 10, 0x00000001>;
    using tr11 = FieldModel<address, 11, 0x00000001>;
    using tr12 = FieldModel<address, 12, 0x00000001>;
    using tr13 = FieldModel<address, 13, 0x00000001>;
    using tr14 = FieldModel<address, 14, 0x00000001>;
    using tr15 = FieldModel<address, 15, 0x00000001>;
    using tr16 = FieldModel<address, 16, 0x00000001>;
    using tr17 = FieldModel<address, 17, 0x00000001>;
    using tr18 = FieldModel<address, 18, 0x00000001>;
    using tr19 = FieldModel<address, 19, 0x00000001>;
    using tr20 = FieldModel<address, 20, 0x00000001>;
    using tr21 = FieldModel<address, 21, 0x00000001>;
    using tr22 = FieldModel<address, 22, 0x00000001>;
  };

public:
  using ftsr = FtsrReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class SwierReg: public RegisterModel<address>
  {
  public:
    using swier0 = FieldModel<address, 0, 0x00000001>;
    using swier1 = FieldModel<address, 1, 0x00000001>;
    using swier2 = FieldModel<address, 2, 0x00000001>;
    using swier3 = FieldModel<address, 3, 0x00000001>;
    using swier4 = FieldModel<address, 4, 0x00000001>;
    using swier5 = FieldModel<address, 5, 0x00000001>;
    using swier6 = FieldModel<address, 6, 0x00000001>;
    using swier7 = FieldModel<address, 7, 0x00000001>;
    using swier8 = FieldModel<address, 8, 0x00000001>;
    using swier9 = FieldModel<address, 9, 0x00000001>;
    using swier10 = FieldModel<address, 10, 0x00000001>;
    using swier11 = FieldModel<address, 11, 0x00000001>;
    using swier12 = FieldModel<address, 12, 0x00000001>;
    using swier13 = FieldModel<address, 13, 0x00000001>;
    using swier14 = FieldModel<address, 14, 0x00000001>;
    using swier15 = FieldModel<address, 15, 0x00000001>;
    using swier16 = FieldModel<address, 16, 0x00000001>;
    using swier17 = FieldModel<address, 17, 0x00000001>;
    using swier18 = FieldModel<address, 18, 0x00000001>;
    using swier19 = FieldModel<address, 19, 0x00000001>;
    using swier20 = FieldModel<address, 20, 0x00000001>;
    using swier21 = FieldModel<address, 21, 0x00000001>;
    using swier22 = FieldModel<address, 22, 0x00000001>;
  };

public:
  using swier = SwierReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class PrReg: public RegisterModel<address>
  {
  public:
    using pr0 = FieldModel<address, 0, 0x00000001>;
    using pr1 = FieldModel<address, 1, 0x00000001>;
    using pr2 = FieldModel<address, 2, 0x00000001>;
    using pr3 = FieldModel<address, 3, 0x00000001>;
    using pr4 = FieldModel<address, 4, 0x00000001>;
    using pr5 = FieldModel<address, 5, 0x00000001>;
    using pr6 = FieldModel<address, 6, 0x00000001>;
    using pr7 = FieldModel<address, 7, 0x00000001>;
    using pr8 = FieldModel<address, 8, 0x00000001>;
    using pr9 = FieldModel<address, 9, 0x00000001>;
    using pr10 = FieldModel<address, 10, 0x00000001>;
    using pr11 = FieldModel<address, 11, 0x00000001>;
    using pr12 = FieldModel<address, 12, 0x00000001>;
    using pr13 = FieldModel<address, 13, 0x00000001>;
    using pr14 = FieldModel<address, 14, 0x00000001>;
    using pr15 = FieldModel<address, 15, 0x00000001>;
    using pr16 = FieldModel<address, 16, 0x00000001>;
    using pr17 = FieldModel<address, 17, 0x00000001>;
    using pr18 = FieldModel<address, 18, 0x00000001>;
    using pr19 = FieldModel<address, 19, 0x00000001>;
    using pr20 = FieldModel<address, 20, 0x00000001>;
    using pr21 = FieldModel<address, 21, 0x00000001>;
    using pr22 = FieldModel<address, 22, 0x00000001>;
  };

public:
  using pr = PrReg<BaseAddress + 0x0014>;
};

}

#endif /* DRAL_STM32F411_EXTI_H */
