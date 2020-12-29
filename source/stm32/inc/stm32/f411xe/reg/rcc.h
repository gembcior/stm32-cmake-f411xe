#ifndef STM32_F411XE_REG_RCC_H
#define STM32_F411XE_REG_RCC_H

#include "../../reg_model/reg_model.h"
#include "../const/general.h"
#include "../const/rcc.h"

namespace stm32::rcc {
  namespace cr {
    using hsion     = RegisterModel<RccBase + Offset, HsionPos,     HsionMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hsirdy    = RegisterModel<RccBase + Offset, HsirdyPos,    HsirdyMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using hsitrim   = RegisterModel<RccBase + Offset, HsitrimPos,   HsitrimMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hsical    = RegisterModel<RccBase + Offset, HsicalPos,    HsicalMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using hseon     = RegisterModel<RccBase + Offset, HseonPos,     HseonMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hserdy    = RegisterModel<RccBase + Offset, HserdyPos,    HserdyMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using hsebyp    = RegisterModel<RccBase + Offset, HsebypPos,    HsebypMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using csson     = RegisterModel<RccBase + Offset, CssonPos,     CssonMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllon     = RegisterModel<RccBase + Offset, PllonPos,     PllonMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllrdy    = RegisterModel<RccBase + Offset, PllrdyPos,    PllrdyMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using plli2son  = RegisterModel<RccBase + Offset, Plli2sonPos,  Plli2SonMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using plli2srdy = RegisterModel<RccBase + Offset, Plli2srdyPos, Plli2srdyMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
  }

  namespace pllcfgr {
    using pllm   = RegisterModel<RccBase + Offset, PllmPos,   PllmMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using plln   = RegisterModel<RccBase + Offset, PllnPos,   PllnMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllp   = RegisterModel<RccBase + Offset, PllpPos,   PllpMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllsrc = RegisterModel<RccBase + Offset, PllsrcPos, PllsrcMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllq   = RegisterModel<RccBase + Offset, PllqPos,   PllqMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace cfgr {
    using sw      = RegisterModel<RccBase + Offset, SwPos,      SwMsk,      PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using sws     = RegisterModel<RccBase + Offset, SwsPos,     SwsMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using hpre    = RegisterModel<RccBase + Offset, HprePos,    HpreMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using ppre1   = RegisterModel<RccBase + Offset, Ppre1Pos,   Ppre1Msk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using ppre2   = RegisterModel<RccBase + Offset, Ppre2Pos,   Ppre2Msk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using rtcpre  = RegisterModel<RccBase + Offset, RtcprePos,  RtcpreMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using mco1    = RegisterModel<RccBase + Offset, Mco1Pos,    Mco1Msk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2ssrc  = RegisterModel<RccBase + Offset, I2ssrcPos,  I2ssrcMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using mco1pre = RegisterModel<RccBase + Offset, Mco1prePos, Mco1preMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using mco2pre = RegisterModel<RccBase + Offset, Mco2prePos, Mco2preMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using mco2    = RegisterModel<RccBase + Offset, Mco2Pos,    Mco2Msk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace cir {
    using lsirdyf     = RegisterModel<RccBase + Offset, LsirdycPos,     LsirdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using lserdyf     = RegisterModel<RccBase + Offset, LserdyfPos,     LserdyfMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using hsirdyf     = RegisterModel<RccBase + Offset, HsirdyfPos,     HsirdyfMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using hserdyf     = RegisterModel<RccBase + Offset, HserdyfPos,     HserdyfMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using pllrdyf     = RegisterModel<RccBase + Offset, PllrdyfPos,     PllrdyfMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using plli2srdyf  = RegisterModel<RccBase + Offset, Plli2srdyfPos,  Plli2srdyfMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using cssf        = RegisterModel<RccBase + Offset, CssfPos,        CssfMsk,        PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using lsirdyie    = RegisterModel<RccBase + Offset, LsirdyiePos,    LsirdyieMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lserdyie    = RegisterModel<RccBase + Offset, LserdyiePos,    LserdyieMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hsirdyie    = RegisterModel<RccBase + Offset, HsirdyiePos,    HsirdyieMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hserdyie    = RegisterModel<RccBase + Offset, HserdyiePos,    HserdyieMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllrdyie    = RegisterModel<RccBase + Offset, PllrdyiePos,    PllrdyieMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using plli2srdyie = RegisterModel<RccBase + Offset, Plli2srdyiePos, Plli2srdyieMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lsirdyc     = RegisterModel<RccBase + Offset, LsirdycPos,     LsirdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::WriteOnly>>;
    using lserdyc     = RegisterModel<RccBase + Offset, LserdycPos,     LserdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::WriteOnly>>;
    using hsirdyc     = RegisterModel<RccBase + Offset, HsirdycPos,     HsirdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::WriteOnly>>;
    using hserdyc     = RegisterModel<RccBase + Offset, HserdycPos,     HserdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::WriteOnly>>;
    using pllrdyc     = RegisterModel<RccBase + Offset, PllrdycPos,     PllrdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::WriteOnly>>;
    using plli2srdyc  = RegisterModel<RccBase + Offset, Plli2srdycPos,  Plli2srdycMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::WriteOnly>>;
    using cssc        = RegisterModel<RccBase + Offset, CsscPos,        CsscMsk,        PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::WriteOnly>>;
  }

  namespace ahb1rstr {
    using gpioarst = RegisterModel<RccBase + Offset, GpioarstPos, GpioarstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiobrst = RegisterModel<RccBase + Offset, GpiobrstPos, GpiobrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiocrst = RegisterModel<RccBase + Offset, GpiocrstPos, GpiocrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiodrst = RegisterModel<RccBase + Offset, GpiodrstPos, GpiodrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpioerst = RegisterModel<RccBase + Offset, GpioerstPos, GpioerstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiohrst = RegisterModel<RccBase + Offset, GpiohrstPos, GpiohrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using crcrst   = RegisterModel<RccBase + Offset, CrcrstPos,   CrcrstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dma1rst  = RegisterModel<RccBase + Offset, Dma1rstPos,  Dma1rstMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dma2rst  = RegisterModel<RccBase + Offset, Dma2rstPos,  Dma2rstMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace ahb2rstr {
    using otgfsrst = RegisterModel<RccBase + Offset, OtgfsrstPos, OtgfsrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace apb1rstr {
    using tim2rst   = RegisterModel<RccBase + Offset, Tim2rstPos,   Tim2rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim3rst   = RegisterModel<RccBase + Offset, Tim3rstPos,   Tim3rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim4rst   = RegisterModel<RccBase + Offset, Tim4rstPos,   Tim4rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim5rst   = RegisterModel<RccBase + Offset, Tim5rstPos,   Tim5rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using wwdgrst   = RegisterModel<RccBase + Offset, WwdgrstPos,   WwdgrstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi2rst   = RegisterModel<RccBase + Offset, Spi2rstPos,   Spi2rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi3rst   = RegisterModel<RccBase + Offset, Spi3rstPos,   Spi3rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart2rst = RegisterModel<RccBase + Offset, Usart2rstPos, Usart2rstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c1rst   = RegisterModel<RccBase + Offset, I2c1rstPos,   I2c1rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c2rst   = RegisterModel<RccBase + Offset, I2c2rstPos,   I2c2rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c3rst   = RegisterModel<RccBase + Offset, I2c3rstPos,   I2c3rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pwrrst    = RegisterModel<RccBase + Offset, PwrrstPos,    PwrrstMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace apb2rstr {
    using tim1rst   = RegisterModel<RccBase + Offset, Tim1rstPos,   Tim1rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart1rst = RegisterModel<RccBase + Offset, Usart1rstPos, Usart1rstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart6rst = RegisterModel<RccBase + Offset, Usart6rstPos, Usart6rstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using adcrst    = RegisterModel<RccBase + Offset, AdcrstPos,    AdcrstMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using sdiorst   = RegisterModel<RccBase + Offset, SdiorstPos,   SdiorstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi1rst   = RegisterModel<RccBase + Offset, Spi1rstPos,   Spi1rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi4rst   = RegisterModel<RccBase + Offset, Spi4rstPos,   Spi4rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using syscfgrst = RegisterModel<RccBase + Offset, SyscfgrstPos, SyscfgrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim9rst   = RegisterModel<RccBase + Offset, Tim9rstPos,   Tim9rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim10rst  = RegisterModel<RccBase + Offset, Tim10rstPos,  Tim10rstMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim11rst  = RegisterModel<RccBase + Offset, Tim11rstPos,  Tim11rstMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi5rst   = RegisterModel<RccBase + Offset, Spi5rstPos,   Spi5rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace ahb1enr {
    using gpioaen = RegisterModel<RccBase + Offset, GpioaenPos, GpioaenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpioben = RegisterModel<RccBase + Offset, GpiobenPos, GpiobenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiocen = RegisterModel<RccBase + Offset, GpiocenPos, GpiocenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpioden = RegisterModel<RccBase + Offset, GpiodenPos, GpiodenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpioeen = RegisterModel<RccBase + Offset, GpioeenPos, GpioeenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiohen = RegisterModel<RccBase + Offset, GpiohenPos, GpiohenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using crcen   = RegisterModel<RccBase + Offset, CrcenPos,   CrcenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dma1en  = RegisterModel<RccBase + Offset, Dma1enPos,  Dma1enMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dma2en  = RegisterModel<RccBase + Offset, Dma2enPos,  Dma2enMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace ahb2enr {
    using otgfsen = RegisterModel<RccBase + Offset, OtgfsenPos, OtgfsenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace apb1enr {
    using tim2en   = RegisterModel<RccBase + Offset, Tim2enPos,   Tim2enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim3en   = RegisterModel<RccBase + Offset, Tim3enPos,   Tim3enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim4en   = RegisterModel<RccBase + Offset, Tim4enPos,   Tim4enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim5en   = RegisterModel<RccBase + Offset, Tim5enPos,   Tim5enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using wwdgen   = RegisterModel<RccBase + Offset, WwdgenPos,   WwdgenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi2en   = RegisterModel<RccBase + Offset, Spi2enPos,   Spi2enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi3en   = RegisterModel<RccBase + Offset, Spi3enPos,   Spi3enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart2en = RegisterModel<RccBase + Offset, Usart2enPos, Usart2enMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c1en   = RegisterModel<RccBase + Offset, I2c1enPos,   I2c1enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c2en   = RegisterModel<RccBase + Offset, I2c2enPos,   I2c2enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c3en   = RegisterModel<RccBase + Offset, I2c3enPos,   I2c3enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pwren    = RegisterModel<RccBase + Offset, PwrenPos,    PwrenMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace apb2enr {
    using tim1en   = RegisterModel<RccBase + Offset, Tim1enPos,   Tim1enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart1en = RegisterModel<RccBase + Offset, Usart1enPos, Usart1enMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart6en = RegisterModel<RccBase + Offset, Usart6enPos, Usart6enMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using adc1en   = RegisterModel<RccBase + Offset, Adc1enPos,   Adc1enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using sdioen   = RegisterModel<RccBase + Offset, SdioenPos,   SdioenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi1en   = RegisterModel<RccBase + Offset, Spi1enPos,   Spi1enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi4en   = RegisterModel<RccBase + Offset, Spi4enPos,   Spi4enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using syscfgen = RegisterModel<RccBase + Offset, SyscfgenPos, SyscfgenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim9en   = RegisterModel<RccBase + Offset, Tim9enPos,   Tim9enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim10en  = RegisterModel<RccBase + Offset, Tim10enPos,  Tim10enMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim11en  = RegisterModel<RccBase + Offset, Tim11enPos,  Tim11enMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi5en   = RegisterModel<RccBase + Offset, Spi5enPos,   Spi5enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace ahb1lpenr {
    using gpioalpen = RegisterModel<RccBase + Offset, GpioalpenPos, GpioalpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpioblpen = RegisterModel<RccBase + Offset, GpioblpenPos, GpioblpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpioclpen = RegisterModel<RccBase + Offset, GpioclpenPos, GpioclpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiodlpen = RegisterModel<RccBase + Offset, GpiodlpenPos, GpiodlpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpioelpen = RegisterModel<RccBase + Offset, GpioelpenPos, GpioelpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiohlpen = RegisterModel<RccBase + Offset, GpiohlpenPos, GpiohlpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using crclpen   = RegisterModel<RccBase + Offset, CrclpenPos,   CrclpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using flitflpen = RegisterModel<RccBase + Offset, FlitflpenPos, FlitflpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using sram1lpen = RegisterModel<RccBase + Offset, Sram1lpenPos, Sram1lpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dma1lpen  = RegisterModel<RccBase + Offset, Dma1lpenPos,  Dma1lpenMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dma2lpen  = RegisterModel<RccBase + Offset, Dma2lpenPos,  Dma2lpenMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace ahb2lpenr {
    using otgfslpen = RegisterModel<RccBase + Offset, OtgfslpenPos, OtgfslpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace apb1lpenr {
    using tim2lpen   = RegisterModel<RccBase + Offset, Tim2lpenPos,   Tim2lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim3lpen   = RegisterModel<RccBase + Offset, Tim3lpenPos,   Tim3lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim4lpen   = RegisterModel<RccBase + Offset, Tim4lpenPos,   Tim4lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim5lpen   = RegisterModel<RccBase + Offset, Tim5lpenPos,   Tim5lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using wwdglpen   = RegisterModel<RccBase + Offset, WwdglpenPos,   WwdglpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi2lpen   = RegisterModel<RccBase + Offset, Spi2lpenPos,   Spi2lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi3lpen   = RegisterModel<RccBase + Offset, Spi3lpenPos,   Spi3lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart2lpen = RegisterModel<RccBase + Offset, Usart2lpenPos, Usart2lpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c1lpen   = RegisterModel<RccBase + Offset, I2c1lpenPos,   I2c1lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c2lpen   = RegisterModel<RccBase + Offset, I2c2lpenPos,   I2c2lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c3lpen   = RegisterModel<RccBase + Offset, I2c3lpenPos,   I2c3lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pwrlpen    = RegisterModel<RccBase + Offset, PwrlpenPos,    PwrlpenMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace apb2lpenr {
    using tim1lpen   = RegisterModel<RccBase + Offset, Tim1lpenPos,   Tim1lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart1lpen = RegisterModel<RccBase + Offset, Usart1lpenPos, Usart1lpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart6lpen = RegisterModel<RccBase + Offset, Usart6lpenPos, Usart6lpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using adc1lpen   = RegisterModel<RccBase + Offset, Adc1lpenPos,   Adc1lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using sdiolpen   = RegisterModel<RccBase + Offset, SdiolpenPos,   SdiolpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi1lpen   = RegisterModel<RccBase + Offset, Spi1lpenPos,   Spi1lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi4lpen   = RegisterModel<RccBase + Offset, Spi4lpenPos,   Spi4lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using syscfglpen = RegisterModel<RccBase + Offset, SyscfglpenPos, SyscfglpenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim9lpen   = RegisterModel<RccBase + Offset, Tim9lpenPos,   Tim9lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim10lpen  = RegisterModel<RccBase + Offset, Tim10lpenPos,  Tim10lpenMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim11lpen  = RegisterModel<RccBase + Offset, Tim11lpenPos,  Tim11lpenMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi5lpen   = RegisterModel<RccBase + Offset, Spi5lpenPos,   Spi5lpenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace bdcr {
    using lseon  = RegisterModel<RccBase + Offset, LseonPos,  LseonMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lserdy = RegisterModel<RccBase + Offset, LserdyPos, LserdyMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using lsebyp = RegisterModel<RccBase + Offset, LsebypPos, LsebypMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lsemod = RegisterModel<RccBase + Offset, LsemodPos, LsemodMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using rtcsel = RegisterModel<RccBase + Offset, RtcselPos, RtcselMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using rtcen  = RegisterModel<RccBase + Offset, RtcenPos,  RtcenMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using bdrst  = RegisterModel<RccBase + Offset, BdrstPos,  BdrstMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace csr {
    using lsion    = RegisterModel<RccBase + Offset, LsionPos,    LsionMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lsirdy   = RegisterModel<RccBase + Offset, LsirdyPos,   LsirdyMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using rmvf     = RegisterModel<RccBase + Offset, RmvfPos,     RmvfMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>; // rt_w
    using borrstf  = RegisterModel<RccBase + Offset, BorrstfPos,  BorrstfMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using pinrstf  = RegisterModel<RccBase + Offset, PinrstfPos,  PinrstfMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using porrstf  = RegisterModel<RccBase + Offset, PorrstfPos,  PorrstfMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using sftrstf  = RegisterModel<RccBase + Offset, SftrstfPos,  SftrstfMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using iwdgrstf = RegisterModel<RccBase + Offset, IwdgrstfPos, IwdgrstfMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using wwdgrstf = RegisterModel<RccBase + Offset, WwdgrstfPos, WwdgrstfMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using lpwrrstf = RegisterModel<RccBase + Offset, LpwrrstfPos, LpwrrstfMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
  }

  namespace sscgr {
    using modper    = RegisterModel<RccBase + Offset, ModperPos,    ModperMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using incstep   = RegisterModel<RccBase + Offset, IncstepPos,   IncstepMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spreadsel = RegisterModel<RccBase + Offset, SpreadselPos, SpreadselMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using sscgen    = RegisterModel<RccBase + Offset, SscgenPos,    SscgenMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace plli2scfgr {
    using plli2sm = RegisterModel<RccBase + Offset, Plli2smPos, Plli2smMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using plli2sn = RegisterModel<RccBase + Offset, Plli2snPos, Plli2snMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using plli2sr = RegisterModel<RccBase + Offset, Plli2srPos, Plli2srMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace dckcfgr {
    using timpre = RegisterModel<RccBase + Offset, TimprePos, TimpreMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }
}

#endif /* STM32_F411XE_REG_RCC_H */
