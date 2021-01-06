#ifndef STM32_F411XE_CONST_FLASH_H
#define STM32_F411XE_CONST_FLASH_H

#include <cstdint>
#include "stm32/f411xe/const/general.h"

namespace stm32::constants::flash {

  namespace acr {
    constexpr uint32_t Address      = FlashRBase + 0x0;

    constexpr uint32_t LatencyPos   = 0;
    constexpr uint32_t LatencyMsk   = 0xF;

    constexpr uint32_t PrftenPos   = 8;
    constexpr uint32_t PrftenMsk   = 0x1;

    constexpr uint32_t IcenPos   = 9;
    constexpr uint32_t IcenMsk   = 0x1;

    constexpr uint32_t DcenPos   = 10;
    constexpr uint32_t DcenMsk   = 0x1;

    constexpr uint32_t IcrstPos   = 11;
    constexpr uint32_t IcrstMsk   = 0x1;

    constexpr uint32_t DcrstPos   = 12;
    constexpr uint32_t DcrstMsk   = 0x1;
  }

}

#endif /* STM32_F411XE_CONST_FLASH_H */
