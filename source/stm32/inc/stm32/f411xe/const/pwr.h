#ifndef STM32_F411XE_CONST_PWR_H
#define STM32_F411XE_CONST_PWR_H

#include <cstdint>

namespace stm32::pwr {
  namespace cr {
    constexpr uint32_t LpdsPos   = 0;
    constexpr uint32_t LpdsMsk   = 0x1;

    constexpr uint32_t PddsPos   = 1;
    constexpr uint32_t PddsMsk   = 0x1;

    constexpr uint32_t CwufPos   = 2;
    constexpr uint32_t CwufMsk   = 0x1;

    constexpr uint32_t CsbfPos   = 3;
    constexpr uint32_t CsbfMsk   = 0x1;

    constexpr uint32_t PvdePos   = 4;
    constexpr uint32_t PvdeMsk   = 0x1;

    constexpr uint32_t PlsPos    = 5;
    constexpr uint32_t PlsMsk    = 0x7;

    constexpr uint32_t DbpPos    = 8;
    constexpr uint32_t DbpMsk    = 0x1;

    constexpr uint32_t FpdsPos   = 9;
    constexpr uint32_t FpdsMsk   = 0x1;

    constexpr uint32_t LplvdsPos = 10;
    constexpr uint32_t LplvdsMsk = 0x1;

    constexpr uint32_t MrlvdsPos = 11;
    constexpr uint32_t MrlvdsMsk = 0x1;

    constexpr uint32_t Adcdc1Pos = 13;
    constexpr uint32_t Adcdc1Msk = 0x1;

    constexpr uint32_t VosPos    = 14;
    constexpr uint32_t VosMsk    = 0x3;

    constexpr uint32_t FmssrPos  = 20;
    constexpr uint32_t FmssrMsk  = 0x1;

    constexpr uint32_t FissrPos  = 21;
    constexpr uint32_t FissrMsk  = 0x1;
  }

  namespace csr {
    constexpr uint32_t WufPos    = 0;
    constexpr uint32_t WufMsk    = 0x1;

    constexpr uint32_t SbfPos    = 1;
    constexpr uint32_t SbfMsk    = 0x1;

    constexpr uint32_t PvdoPos   = 2;
    constexpr uint32_t PvdoMsk   = 0x1;

    constexpr uint32_t BrrPos    = 3;
    constexpr uint32_t BrrMsk    = 0x1;

    constexpr uint32_t EwupPos   = 8;
    constexpr uint32_t EwupMsk   = 0x1;

    constexpr uint32_t BrePos    = 9;
    constexpr uint32_t BreMsk    = 0x1;

    constexpr uint32_t VosrdyPos = 14;
    constexpr uint32_t VosrdyMsk = 0x1;
  }
}

#endif /* STM32_F411XE_CONST_PWR_H */
