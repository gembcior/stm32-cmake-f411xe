#ifndef STM32_F411XE_CONST_RCC_H
#define STM32_F411XE_CONST_RCC_H

#include <cstdint>
#include "stm32/f411xe/const/general.h"

namespace stm32::constants::rcc {

  namespace cr {
    constexpr uint32_t Address      = RccBase + 0x0;

    constexpr uint32_t HsionPos     = 0;
    constexpr uint32_t HsionMsk     = 0x1;

    constexpr uint32_t HsirdyPos    = 1;
    constexpr uint32_t HsirdyMsk    = 0x1;

    constexpr uint32_t HsitrimPos   = 3;
    constexpr uint32_t HsitrimMsk   = 0x1F;

    constexpr uint32_t HsicalPos    = 8;
    constexpr uint32_t HsicalMsk    = 0xFF;

    constexpr uint32_t HseonPos     = 16;
    constexpr uint32_t HseonMsk     = 0x1;

    constexpr uint32_t HserdyPos    = 17;
    constexpr uint32_t HserdyMsk    = 0x1;

    constexpr uint32_t HsebypPos    = 18;
    constexpr uint32_t HsebypMsk    = 0x1;

    constexpr uint32_t CssonPos     = 19;
    constexpr uint32_t CssonMsk     = 0x1;

    constexpr uint32_t PllonPos     = 24;
    constexpr uint32_t PllonMsk     = 0x1;

    constexpr uint32_t PllrdyPos    = 25;
    constexpr uint32_t PllrdyMsk    = 0x1;

    constexpr uint32_t Plli2sonPos  = 26;
    constexpr uint32_t Plli2SonMsk  = 0x1;

    constexpr uint32_t Plli2srdyPos = 27;
    constexpr uint32_t Plli2srdyMsk = 0x1;
  }

  namespace pllcfgr {
    constexpr uint32_t Address   = RccBase + 0x4;

    constexpr uint32_t PllmPos   = 0;
    constexpr uint32_t PllmMsk   = 0x3F;

    constexpr uint32_t PllnPos   = 6;
    constexpr uint32_t PllnMsk   = 0x1FF;

    constexpr uint32_t PllpPos   = 16;
    constexpr uint32_t PllpMsk   = 0x3;

    constexpr uint32_t PllsrcPos = 22;
    constexpr uint32_t PllsrcMsk = 0x1;

    constexpr uint32_t PllqPos   = 24;
    constexpr uint32_t PllqMsk   = 0xF;
  }

  namespace cfgr {
    constexpr uint32_t Address    = RccBase + 0x8;

    constexpr uint32_t SwPos      = 0;
    constexpr uint32_t SwMsk      = 0x3;

    constexpr uint32_t SwsPos     = 2;
    constexpr uint32_t SwsMsk     = 0x3;

    constexpr uint32_t HprePos    = 4;
    constexpr uint32_t HpreMsk    = 0xF;

    constexpr uint32_t Ppre1Pos   = 10;
    constexpr uint32_t Ppre1Msk   = 0x7;

    constexpr uint32_t Ppre2Pos   = 13;
    constexpr uint32_t Ppre2Msk   = 0x7;

    constexpr uint32_t RtcprePos  = 16;
    constexpr uint32_t RtcpreMsk  = 0x1F;

    constexpr uint32_t Mco1Pos    = 21;
    constexpr uint32_t Mco1Msk    = 0x3;

    constexpr uint32_t I2ssrcPos  = 23;
    constexpr uint32_t I2ssrcMsk  = 0x1;

    constexpr uint32_t Mco1prePos = 24;
    constexpr uint32_t Mco1preMsk = 0x7;

    constexpr uint32_t Mco2prePos = 27;
    constexpr uint32_t Mco2preMsk = 0x7;

    constexpr uint32_t Mco2Pos    = 30;
    constexpr uint32_t Mco2Msk    = 0x3;
  };

  namespace cir {
    constexpr uint32_t Address        = RccBase + 0xC;

    constexpr uint32_t LsirdyfPos     = 0;
    constexpr uint32_t LsirdyfMsk     = 0x1;

    constexpr uint32_t LserdyfPos     = 1;
    constexpr uint32_t LserdyfMsk     = 0x1;

    constexpr uint32_t HsirdyfPos     = 2;
    constexpr uint32_t HsirdyfMsk     = 0x1;

    constexpr uint32_t HserdyfPos     = 3;
    constexpr uint32_t HserdyfMsk     = 0x1;

    constexpr uint32_t PllrdyfPos     = 4;
    constexpr uint32_t PllrdyfMsk     = 0x1;

    constexpr uint32_t Plli2srdyfPos  = 5;
    constexpr uint32_t Plli2srdyfMsk  = 0x1;

    constexpr uint32_t CssfPos        = 7;
    constexpr uint32_t CssfMsk        = 0x1;

    constexpr uint32_t LsirdyiePos    = 8;
    constexpr uint32_t LsirdyieMsk    = 0x1;

    constexpr uint32_t LserdyiePos    = 9;
    constexpr uint32_t LserdyieMsk    = 0x1;

    constexpr uint32_t HsirdyiePos    = 10;;
    constexpr uint32_t HsirdyieMsk    = 0x1;

    constexpr uint32_t HserdyiePos    = 11;
    constexpr uint32_t HserdyieMsk    = 0x1;

    constexpr uint32_t PllrdyiePos    = 12;
    constexpr uint32_t PllrdyieMsk    = 0x1;

    constexpr uint32_t Plli2srdyiePos = 13;
    constexpr uint32_t Plli2srdyieMsk = 0x1;

    constexpr uint32_t LsirdycPos     = 16;
    constexpr uint32_t LsirdycMsk     = 0x1;

    constexpr uint32_t LserdycPos     = 17;
    constexpr uint32_t LserdycMsk     = 0x1;

    constexpr uint32_t HsirdycPos     = 18;
    constexpr uint32_t HsirdycMsk     = 0x1;

    constexpr uint32_t HserdycPos     = 19;
    constexpr uint32_t HserdycMsk     = 0x1;

    constexpr uint32_t PllrdycPos     = 20;
    constexpr uint32_t PllrdycMsk     = 0x1;

    constexpr uint32_t Plli2srdycPos  = 21;
    constexpr uint32_t Plli2srdycMsk  = 0x1;

    constexpr uint32_t CsscPos        = 23;
    constexpr uint32_t CsscMsk        = 0x1;
  }

  namespace ahb1rstr {
    constexpr uint32_t Address     = RccBase + 0x10;

    constexpr uint32_t GpioarstPos = 0;
    constexpr uint32_t GpioarstMsk = 0x1;

    constexpr uint32_t GpiobrstPos = 1;
    constexpr uint32_t GpiobrstMsk = 0x1;

    constexpr uint32_t GpiocrstPos = 2;
    constexpr uint32_t GpiocrstMsk = 0x1;

    constexpr uint32_t GpiodrstPos = 3;
    constexpr uint32_t GpiodrstMsk = 0x1;

    constexpr uint32_t GpioerstPos = 4;
    constexpr uint32_t GpioerstMsk = 0x1;

    constexpr uint32_t GpiohrstPos = 7;
    constexpr uint32_t GpiohrstMsk = 0x1;

    constexpr uint32_t CrcrstPos   = 12;
    constexpr uint32_t CrcrstMsk   = 0x1;

    constexpr uint32_t Dma1rstPos  = 21;
    constexpr uint32_t Dma1rstMsk  = 0x1;

    constexpr uint32_t Dma2rstPos  = 22;
    constexpr uint32_t Dma2rstMsk  = 0x1;
  }

  namespace ahb2rstr {
    constexpr uint32_t Address     = RccBase + 0x14;

    constexpr uint32_t OtgfsrstPos = 7;
    constexpr uint32_t OtgfsrstMsk = 0x1;
  }

  namespace apb1rstr {
    constexpr uint32_t Address      = RccBase + 0x20;

    constexpr uint32_t Tim2rstPos   = 0;
    constexpr uint32_t Tim2rstMsk   = 0x1;

    constexpr uint32_t Tim3rstPos   = 1;
    constexpr uint32_t Tim3rstMsk   = 0x1;

    constexpr uint32_t Tim4rstPos   = 2;
    constexpr uint32_t Tim4rstMsk   = 0x1;

    constexpr uint32_t Tim5rstPos   = 3;
    constexpr uint32_t Tim5rstMsk   = 0x1;

    constexpr uint32_t WwdgrstPos   = 11;
    constexpr uint32_t WwdgrstMsk   = 0x1;

    constexpr uint32_t Spi2rstPos   = 14;
    constexpr uint32_t Spi2rstMsk   = 0x1;

    constexpr uint32_t Spi3rstPos   = 15;
    constexpr uint32_t Spi3rstMsk   = 0x1;

    constexpr uint32_t Usart2rstPos = 17;
    constexpr uint32_t Usart2rstMsk = 0x1;

    constexpr uint32_t I2c1rstPos   = 21;
    constexpr uint32_t I2c1rstMsk   = 0x1;

    constexpr uint32_t I2c2rstPos   = 22;
    constexpr uint32_t I2c2rstMsk   = 0x1;

    constexpr uint32_t I2c3rstPos   = 23;
    constexpr uint32_t I2c3rstMsk   = 0x1;

    constexpr uint32_t PwrrstPos    = 28;
    constexpr uint32_t PwrrstMsk    = 0x1;
  }

  namespace apb2rstr {
    constexpr uint32_t Address      = RccBase + 0x24;

    constexpr uint32_t Tim1rstPos   = 0;
    constexpr uint32_t Tim1rstMsk   = 0x1;

    constexpr uint32_t Usart1rstPos = 4;
    constexpr uint32_t Usart1rstMsk = 0x1;

    constexpr uint32_t Usart6rstPos = 5;
    constexpr uint32_t Usart6rstMsk = 0x1;

    constexpr uint32_t AdcrstPos    = 8;
    constexpr uint32_t AdcrstMsk    = 0x1;

    constexpr uint32_t SdiorstPos   = 11;
    constexpr uint32_t SdiorstMsk   = 0x1;

    constexpr uint32_t Spi1rstPos   = 12;
    constexpr uint32_t Spi1rstMsk   = 0x1;

    constexpr uint32_t Spi4rstPos   = 13;
    constexpr uint32_t Spi4rstMsk   = 0x1;

    constexpr uint32_t SyscfgrstPos = 14;
    constexpr uint32_t SyscfgrstMsk = 0x1;

    constexpr uint32_t Tim9rstPos   = 16;
    constexpr uint32_t Tim9rstMsk   = 0x1;

    constexpr uint32_t Tim10rstPos  = 17;
    constexpr uint32_t Tim10rstMsk  = 0x1;

    constexpr uint32_t Tim11rstPos  = 18;
    constexpr uint32_t Tim11rstMsk  = 0x1;

    constexpr uint32_t Spi5rstPos   = 20;
    constexpr uint32_t Spi5rstMsk   = 0x1;
  }

  namespace ahb1enr {
    constexpr uint32_t Address    = RccBase + 0x30;

    constexpr uint32_t GpioaenPos = 0;
    constexpr uint32_t GpioaenMsk = 0x1;

    constexpr uint32_t GpiobenPos = 1;
    constexpr uint32_t GpiobenMsk = 0x1;

    constexpr uint32_t GpiocenPos = 2;
    constexpr uint32_t GpiocenMsk = 0x1;

    constexpr uint32_t GpiodenPos = 3;
    constexpr uint32_t GpiodenMsk = 0x1;

    constexpr uint32_t GpioeenPos = 4;
    constexpr uint32_t GpioeenMsk = 0x1;

    constexpr uint32_t GpiohenPos = 7;
    constexpr uint32_t GpiohenMsk = 0x1;

    constexpr uint32_t CrcenPos   = 12;
    constexpr uint32_t CrcenMsk   = 0x1;

    constexpr uint32_t Dma1enPos  = 21;
    constexpr uint32_t Dma1enMsk  = 0x1;

    constexpr uint32_t Dma2enPos  = 22;
    constexpr uint32_t Dma2enMsk  = 0x1;
  }

  namespace ahb2enr {
    constexpr uint32_t Address    = RccBase + 0x34;

    constexpr uint32_t OtgfsenPos = 7;
    constexpr uint32_t OtgfsenMsk = 0x1;
  }

  namespace apb1enr {
    constexpr uint32_t Address     = RccBase + 0x40;

    constexpr uint32_t Tim2enPos   = 0;
    constexpr uint32_t Tim2enMsk   = 0x1;

    constexpr uint32_t Tim3enPos   = 1;
    constexpr uint32_t Tim3enMsk   = 0x1;

    constexpr uint32_t Tim4enPos   = 2;
    constexpr uint32_t Tim4enMsk   = 0x1;

    constexpr uint32_t Tim5enPos   = 3;
    constexpr uint32_t Tim5enMsk   = 0x1;

    constexpr uint32_t WwdgenPos   = 11;
    constexpr uint32_t WwdgenMsk   = 0x1;

    constexpr uint32_t Spi2enPos   = 14;
    constexpr uint32_t Spi2enMsk   = 0x1;

    constexpr uint32_t Spi3enPos   = 15;
    constexpr uint32_t Spi3enMsk   = 0x1;

    constexpr uint32_t Usart2enPos = 17;
    constexpr uint32_t Usart2enMsk = 0x1;

    constexpr uint32_t I2c1enPos   = 21;
    constexpr uint32_t I2c1enMsk   = 0x1;

    constexpr uint32_t I2c2enPos   = 22;
    constexpr uint32_t I2c2enMsk   = 0x1;

    constexpr uint32_t I2c3enPos   = 23;
    constexpr uint32_t I2c3enMsk   = 0x1;

    constexpr uint32_t PwrenPos    = 28;
    constexpr uint32_t PwrenMsk    = 0x1;
  }

  namespace apb2enr {
    constexpr uint32_t Address     = RccBase + 0x44;

    constexpr uint32_t Tim1enPos   = 0;
    constexpr uint32_t Tim1enMsk   = 0x1;

    constexpr uint32_t Usart1enPos = 4;
    constexpr uint32_t Usart1enMsk = 0x1;

    constexpr uint32_t Usart6enPos = 5;
    constexpr uint32_t Usart6enMsk = 0x1;

    constexpr uint32_t Adc1enPos   = 8;
    constexpr uint32_t Adc1enMsk   = 0x1;

    constexpr uint32_t SdioenPos   = 11;
    constexpr uint32_t SdioenMsk   = 0x1;

    constexpr uint32_t Spi1enPos   = 12;
    constexpr uint32_t Spi1enMsk   = 0x1;

    constexpr uint32_t Spi4enPos   = 13;
    constexpr uint32_t Spi4enMsk   = 0x1;

    constexpr uint32_t SyscfgenPos = 14;
    constexpr uint32_t SyscfgenMsk = 0x1;

    constexpr uint32_t Tim9enPos   = 16;
    constexpr uint32_t Tim9enMsk   = 0x1;

    constexpr uint32_t Tim10enPos  = 17;
    constexpr uint32_t Tim10enMsk  = 0x1;

    constexpr uint32_t Tim11enPos  = 18;
    constexpr uint32_t Tim11enMsk  = 0x1;

    constexpr uint32_t Spi5enPos   = 20;
    constexpr uint32_t Spi5enMsk   = 0x1;
  }

  namespace ahb1lpenr {
    constexpr uint32_t Address      = RccBase + 0x50;

    constexpr uint32_t GpioalpenPos = 0;
    constexpr uint32_t GpioalpenMsk = 0x1;

    constexpr uint32_t GpioblpenPos = 1;
    constexpr uint32_t GpioblpenMsk = 0x1;

    constexpr uint32_t GpioclpenPos = 2;
    constexpr uint32_t GpioclpenMsk = 0x1;

    constexpr uint32_t GpiodlpenPos = 3;
    constexpr uint32_t GpiodlpenMsk = 0x1;

    constexpr uint32_t GpioelpenPos = 4;
    constexpr uint32_t GpioelpenMsk = 0x1;

    constexpr uint32_t GpiohlpenPos = 7;
    constexpr uint32_t GpiohlpenMsk = 0x1;

    constexpr uint32_t CrclpenPos   = 12;
    constexpr uint32_t CrclpenMsk   = 0x1;

    constexpr uint32_t FlitflpenPos = 15;
    constexpr uint32_t FlitflpenMsk = 0x1;

    constexpr uint32_t Sram1lpenPos = 16;
    constexpr uint32_t Sram1lpenMsk = 0x1;

    constexpr uint32_t Dma1lpenPos  = 21;
    constexpr uint32_t Dma1lpenMsk  = 0x1;

    constexpr uint32_t Dma2lpenPos  = 22;
    constexpr uint32_t Dma2lpenMsk  = 0x1;
  }

  namespace ahb2lpenr {
    constexpr uint32_t Address      = RccBase + 0x54;

    constexpr uint32_t OtgfslpenPos = 7;
    constexpr uint32_t OtgfslpenMsk = 0x1;
  }

  namespace apb1lpenr {
    constexpr uint32_t Address       = RccBase + 0x60;

    constexpr uint32_t Tim2lpenPos   = 0;
    constexpr uint32_t Tim2lpenMsk   = 0x1;

    constexpr uint32_t Tim3lpenPos   = 1;
    constexpr uint32_t Tim3lpenMsk   = 0x1;

    constexpr uint32_t Tim4lpenPos   = 2;
    constexpr uint32_t Tim4lpenMsk   = 0x1;

    constexpr uint32_t Tim5lpenPos   = 3;
    constexpr uint32_t Tim5lpenMsk   = 0x1;

    constexpr uint32_t WwdglpenPos   = 11;
    constexpr uint32_t WwdglpenMsk   = 0x1;

    constexpr uint32_t Spi2lpenPos   = 14;
    constexpr uint32_t Spi2lpenMsk   = 0x1;

    constexpr uint32_t Spi3lpenPos   = 15;
    constexpr uint32_t Spi3lpenMsk   = 0x1;

    constexpr uint32_t Usart2lpenPos = 17;
    constexpr uint32_t Usart2lpenMsk = 0x1;

    constexpr uint32_t I2c1lpenPos   = 21;
    constexpr uint32_t I2c1lpenMsk   = 0x1;

    constexpr uint32_t I2c2lpenPos   = 22;
    constexpr uint32_t I2c2lpenMsk   = 0x1;

    constexpr uint32_t I2c3lpenPos   = 23;
    constexpr uint32_t I2c3lpenMsk   = 0x1;

    constexpr uint32_t PwrlpenPos    = 28;
    constexpr uint32_t PwrlpenMsk    = 0x1;
  }

  namespace apb2lpenr {
    constexpr uint32_t Address       = RccBase + 0x64;

    constexpr uint32_t Tim1lpenPos   = 0;
    constexpr uint32_t Tim1lpenMsk   = 0x1;

    constexpr uint32_t Usart1lpenPos = 4;
    constexpr uint32_t Usart1lpenMsk = 0x1;

    constexpr uint32_t Usart6lpenPos = 5;
    constexpr uint32_t Usart6lpenMsk = 0x1;

    constexpr uint32_t Adc1lpenPos   = 8;
    constexpr uint32_t Adc1lpenMsk   = 0x1;

    constexpr uint32_t SdiolpenPos   = 11;
    constexpr uint32_t SdiolpenMsk   = 0x1;

    constexpr uint32_t Spi1lpenPos   = 12;
    constexpr uint32_t Spi1lpenMsk   = 0x1;

    constexpr uint32_t Spi4lpenPos   = 13;
    constexpr uint32_t Spi4lpenMsk   = 0x1;

    constexpr uint32_t SyscfglpenPos = 14;
    constexpr uint32_t SyscfglpenMsk = 0x1;

    constexpr uint32_t Tim9lpenPos   = 16;
    constexpr uint32_t Tim9lpenMsk   = 0x1;

    constexpr uint32_t Tim10lpenPos  = 17;
    constexpr uint32_t Tim10lpenMsk  = 0x1;

    constexpr uint32_t Tim11lpenPos  = 18;
    constexpr uint32_t Tim11lpenMsk  = 0x1;

    constexpr uint32_t Spi5lpenPos   = 20;
    constexpr uint32_t Spi5lpenMsk   = 0x1;
  }

  namespace bdcr {
    constexpr uint32_t Address   = RccBase + 0x70;

    constexpr uint32_t LseonPos  = 0;
    constexpr uint32_t LseonMsk  = 0x1;

    constexpr uint32_t LserdyPos = 1;
    constexpr uint32_t LserdyMsk = 0x1;

    constexpr uint32_t LsebypPos = 2;
    constexpr uint32_t LsebypMsk = 0x1;

    constexpr uint32_t LsemodPos = 3;
    constexpr uint32_t LsemodMsk = 0x1;

    constexpr uint32_t RtcselPos = 8;
    constexpr uint32_t RtcselMsk = 0x3;

    constexpr uint32_t RtcenPos  = 15;
    constexpr uint32_t RtcenMsk  = 0x1;

    constexpr uint32_t BdrstPos  = 16;
    constexpr uint32_t BdrstMsk  = 0x1;
  }

  namespace csr {
    constexpr uint32_t Address     = RccBase + 0x74;

    constexpr uint32_t LsionPos    = 0;
    constexpr uint32_t LsionMsk    = 0x1;

    constexpr uint32_t LsirdyPos   = 1;
    constexpr uint32_t LsirdyMsk   = 0x1;

    constexpr uint32_t RmvfPos     = 24;
    constexpr uint32_t RmvfMsk     = 0x1;

    constexpr uint32_t BorrstfPos  = 25;
    constexpr uint32_t BorrstfMsk  = 0x1;

    constexpr uint32_t PinrstfPos  = 26;
    constexpr uint32_t PinrstfMsk  = 0x1;

    constexpr uint32_t PorrstfPos  = 27;
    constexpr uint32_t PorrstfMsk  = 0x1;

    constexpr uint32_t SftrstfPos  = 28;
    constexpr uint32_t SftrstfMsk  = 0x1;

    constexpr uint32_t IwdgrstfPos = 29;
    constexpr uint32_t IwdgrstfMsk = 0x1;

    constexpr uint32_t WwdgrstfPos = 30;
    constexpr uint32_t WwdgrstfMsk = 0x1;

    constexpr uint32_t LpwrrstfPos = 31;
    constexpr uint32_t LpwrrstfMsk = 0x1;
  }

  namespace sscgr {
    constexpr uint32_t Address      = RccBase + 0x80;

    constexpr uint32_t ModperPos    = 0;
    constexpr uint32_t ModperMsk    = 0x1FFF;

    constexpr uint32_t IncstepPos   = 13;
    constexpr uint32_t IncstepMsk   = 0x7FFF;

    constexpr uint32_t SpreadselPos = 30;
    constexpr uint32_t SpreadselMsk = 0x1;

    constexpr uint32_t SscgenPos    = 31;
    constexpr uint32_t SscgenMsk    = 0x1;
  }

  namespace plli2scfgr {
    constexpr uint32_t Address    = RccBase + 0x84;

    constexpr uint32_t Plli2smPos = 0;
    constexpr uint32_t Plli2smMsk = 0x3F;

    constexpr uint32_t Plli2snPos = 6;
    constexpr uint32_t Plli2snMsk = 0x1FF;

    constexpr uint32_t Plli2srPos = 28;
    constexpr uint32_t Plli2srMsk = 0x7;
  }

  namespace dckcfgr {
    constexpr uint32_t Address   = RccBase + 0x8C;

    constexpr uint32_t TimprePos = 24;
    constexpr uint32_t TimpreMsk = 0x1;
  }

}

#endif /* STM32_F411XE_CONST_RCC_H */
