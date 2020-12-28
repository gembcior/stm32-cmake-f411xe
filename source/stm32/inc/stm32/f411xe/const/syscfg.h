#ifndef STM32_F411XE_CONST_SYSCFG_H
#define STM32_F411XE_CONST_SYSCFG_H

#include <cstdint>

namespace stm32::syscfg {
  namespace memrmp {
    constexpr uint32_t MemModePos = 0;
    constexpr uint32_t MemModeMsk = 0x3;
  }

  namespace pmc {
    constexpr uint32_t Adc1dc2Pos = 16;
    constexpr uint32_t Adc1dc2Msk = 0x1;
  }

  namespace exticr1 {
    constexpr uint32_t Exti0Pos = 0;
    constexpr uint32_t Exti0Msk = 0xF;

    constexpr uint32_t Exti1Pos = 4;
    constexpr uint32_t Exti1Msk = 0xF;

    constexpr uint32_t Exti2Pos = 8;
    constexpr uint32_t Exti2Msk = 0xF;

    constexpr uint32_t Exti3Pos = 12;
    constexpr uint32_t Exti3Msk = 0xF;
  }

  namespace exticr2 {
    constexpr uint32_t Exti4Pos = 0;
    constexpr uint32_t Exti4Msk = 0xF;

    constexpr uint32_t Exti5Pos = 4;
    constexpr uint32_t Exti5Msk = 0xF;

    constexpr uint32_t Exti6Pos = 8;
    constexpr uint32_t Exti6Msk = 0xF;

    constexpr uint32_t Exti7Pos = 12;
    constexpr uint32_t Exti7Msk = 0xF;
  }

  namespace exticr3 {
    constexpr uint32_t Exti8Pos  = 0;
    constexpr uint32_t Exti8Msk  = 0xF;

    constexpr uint32_t Exti9Pos  = 4;
    constexpr uint32_t Exti9Msk  = 0xF;

    constexpr uint32_t Exti10Pos = 8;
    constexpr uint32_t Exti10Msk = 0xF;

    constexpr uint32_t Exti11Pos = 12;
    constexpr uint32_t Exti11Msk = 0xF;
  }

  namespace exticr4 {
    constexpr uint32_t Exti12Pos = 0;
    constexpr uint32_t Exti12Msk = 0xF;

    constexpr uint32_t Exti13Pos = 4;
    constexpr uint32_t Exti13Msk = 0xF;

    constexpr uint32_t Exti14Pos = 8;
    constexpr uint32_t Exti14Msk = 0xF;

    constexpr uint32_t Exti15Pos = 12;
    constexpr uint32_t Exti15Msk = 0xF;
  }

  namespace cmpcr {
    constexpr uint32_t CmpPdPos = 0;
    constexpr uint32_t CmpPdMsk = 0x1;

    constexpr uint32_t ReadyPos  = 8;
    constexpr uint32_t ReadyMsk  = 0x1;
  }
}

#endif /* STM32_F411XE_CONST_SYSCFG_H */
