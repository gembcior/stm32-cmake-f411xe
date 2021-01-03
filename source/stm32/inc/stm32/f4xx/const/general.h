#ifndef STM32_F4XX_CONST_GENERAL_H
#define STM32_F4XX_CONST_GENERAL_H

#include <cstdint>

namespace stm32 {

    constexpr uint32_t ScsBase       = 0xE000E000;
    constexpr uint32_t ItmBase       = 0xE0000000;
    constexpr uint32_t DwtBase       = 0xE0001000;
    constexpr uint32_t TpiBase       = 0xE0040000;
    constexpr uint32_t CoreDebugBase = 0xE000EDF0;
    constexpr uint32_t SysTickBase   = ScsBase + 0x0010;
    constexpr uint32_t NvicBase      = ScsBase + 0x0100;
    constexpr uint32_t ScbBase       = ScsBase + 0x0D00;
    constexpr uint32_t MpuBase       = ScsBase + 0x0D90;
    constexpr uint32_t FpuBase       = ScsBase + 0x0F30;

}

#endif /* STM32_F4XX_CONST_GENERAL_H */
