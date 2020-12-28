#ifndef STM32_F411XE_REG_RCC_H
#define STM32_F411XE_REG_RCC_H

#include "reg_model/reg_model.h"
#include "../const/general.h"
#include "../const/rcc.h"

namespace stm32::rcc {
  namespace cr {
    using hsion     = RegisterModel<RccBase, HsionPos,     HsionMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hsirdy    = RegisterModel<RccBase, HsirdyPos,    HsirdyMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using hsitrim   = RegisterModel<RccBase, HsitrimPos,   HsitrimMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hsical    = RegisterModel<RccBase, HsicalPos,    HsicalMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using hseon     = RegisterModel<RccBase, HseonPos,     HseonMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hserdy    = RegisterModel<RccBase, HserdyPos,    HserdyMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using hsebyp    = RegisterModel<RccBase, HsebypPos,    HsebypMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using csson     = RegisterModel<RccBase, CssonPos,     CssonMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllon     = RegisterModel<RccBase, PllonPos,     PllonMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllrdy    = RegisterModel<RccBase, PllrdyPos,    PllrdyMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
    using plli2son  = RegisterModel<RccBase, Plli2sonPos,  Plli2SonMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using plli2srdy = RegisterModel<RccBase, Plli2srdyPos, Plli2srdyMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadOnly>>;
  }

  namespace pllcfgr {
    using pllm   = RegisterModel<RccBase, PllmPos,   PllmMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using plln   = RegisterModel<RccBase, PllnPos,   PllnMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllp   = RegisterModel<RccBase, PllpPos,   PllpMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllsrc = RegisterModel<RccBase, PllsrcPos, PllsrcMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllq   = RegisterModel<RccBase, PllqPos,   PllqMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace cfgr {
    using sw      = RegisterModel<RccBase, SwPos,      SwMsk,      PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using sws     = RegisterModel<RccBase, SwsPos,     SwsMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hpre    = RegisterModel<RccBase, HprePos,    HpreMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using ppre1   = RegisterModel<RccBase, Ppre1Pos,   Ppre1Msk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using ppre2   = RegisterModel<RccBase, Ppre2Pos,   Ppre2Msk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using rtcpre  = RegisterModel<RccBase, RtcprePos,  RtcpreMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using mco1    = RegisterModel<RccBase, Mco1Pos,    Mco1Msk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2ssrc  = RegisterModel<RccBase, I2ssrcPos,  I2ssrcMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using mco1pre = RegisterModel<RccBase, Mco1prePos, Mco1preMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using mco2pre = RegisterModel<RccBase, Mco2prePos, Mco2preMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using mco2    = RegisterModel<RccBase, Mco2Pos,    Mco2Msk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace cir {
    using lsirdyf     = RegisterModel<RccBase, LsirdycPos,     LsirdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lserdyf     = RegisterModel<RccBase, LserdyfPos,     LserdyfMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hsirdyf     = RegisterModel<RccBase, HsirdyfPos,     HsirdyfMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hserdyf     = RegisterModel<RccBase, HserdyfPos,     HserdyfMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllrdyf     = RegisterModel<RccBase, PllrdyfPos,     PllrdyfMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using plli2srdyf  = RegisterModel<RccBase, Plli2srdyfPos,  Plli2srdyfMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using cssf        = RegisterModel<RccBase, CssfPos,        CssfMsk,        PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lsirdyie    = RegisterModel<RccBase, LsirdyiePos,    LsirdyieMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lserdyie    = RegisterModel<RccBase, LserdyiePos,    LserdyieMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hsirdyie    = RegisterModel<RccBase, HsirdyiePos,    HsirdyieMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hserdyie    = RegisterModel<RccBase, HserdyiePos,    HserdyieMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllrdyie    = RegisterModel<RccBase, PllrdyiePos,    PllrdyieMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using plli2srdyie = RegisterModel<RccBase, Plli2srdyiePos, Plli2srdyieMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lsirdyc     = RegisterModel<RccBase, LsirdycPos,     LsirdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using lserdyc     = RegisterModel<RccBase, LserdycPos,     LserdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hsirdyc     = RegisterModel<RccBase, HsirdycPos,     HsirdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using hserdyc     = RegisterModel<RccBase, HserdycPos,     HserdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pllrdyc     = RegisterModel<RccBase, PllrdycPos,     PllrdycMsk,     PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using plli2srdyc  = RegisterModel<RccBase, Plli2srdycPos,  Plli2srdycMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using cssc        = RegisterModel<RccBase, CsscPos,        CsscMsk,        PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace ahb1rstr {
    using gpioarst = RegisterModel<RccBase, GpioarstPos, GpioarstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiobrst = RegisterModel<RccBase, GpiobrstPos, GpiobrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiocrst = RegisterModel<RccBase, GpiocrstPos, GpiocrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiodrst = RegisterModel<RccBase, GpiodrstPos, GpiodrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpioerst = RegisterModel<RccBase, GpioerstPos, GpioerstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiohrst = RegisterModel<RccBase, GpiohrstPos, GpiohrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using crcrst   = RegisterModel<RccBase, CrcrstPos,   CrcrstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dma1rst  = RegisterModel<RccBase, Dma1rstPos,  Dma1rstMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dma2rst  = RegisterModel<RccBase, Dma2rstPos,  Dma2rstMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace ahb2rstr {
    using otgfsrst = RegisterModel<RccBase, OtgfsrstPos, OtgfsrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace apb1rstr {
    using tim2rst   = RegisterModel<RccBase, Tim2rstPos,   Tim2rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim3rst   = RegisterModel<RccBase, Tim3rstPos,   Tim3rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim4rst   = RegisterModel<RccBase, Tim4rstPos,   Tim4rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim5rst   = RegisterModel<RccBase, Tim5rstPos,   Tim5rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using wwdgrst   = RegisterModel<RccBase, WwdgrstPos,   WwdgrstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi2rst   = RegisterModel<RccBase, Spi2rstPos,   Spi2rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi3rst   = RegisterModel<RccBase, Spi3rstPos,   Spi3rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart2rst = RegisterModel<RccBase, Usart2rstPos, Usart2rstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c1rst   = RegisterModel<RccBase, I2c1rstPos,   I2c1rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c2rst   = RegisterModel<RccBase, I2c2rstPos,   I2c2rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c3rst   = RegisterModel<RccBase, I2c3rstPos,   I2c3rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pwrrst    = RegisterModel<RccBase, PwrrstPos,    PwrrstMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace apb2rstr {
    using tim1rst   = RegisterModel<RccBase, Tim1rstPos,   Tim1rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart1rst = RegisterModel<RccBase, Usart1rstPos, Usart1rstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart6rst = RegisterModel<RccBase, Usart6rstPos, Usart6rstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using adcrst    = RegisterModel<RccBase, AdcrstPos,    AdcrstMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using sdiorst   = RegisterModel<RccBase, SdiorstPos,   SdiorstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi1rst   = RegisterModel<RccBase, Spi1rstPos,   Spi1rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi4rst   = RegisterModel<RccBase, Spi4rstPos,   Spi4rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using syscfgrst = RegisterModel<RccBase, SyscfgrstPos, SyscfgrstMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim9rst   = RegisterModel<RccBase, Tim9rstPos,   Tim9rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim10rst  = RegisterModel<RccBase, Tim10rstPos,  Tim10rstMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim11rst  = RegisterModel<RccBase, Tim11rstPos,  Tim11rstMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi5rst   = RegisterModel<RccBase, Spi5rstPos,   Spi5rstMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace ahb1enr {
    using gpioaen = RegisterModel<RccBase, GpioaenPos, GpioaenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpioben = RegisterModel<RccBase, GpiobenPos, GpiobenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiocen = RegisterModel<RccBase, GpiocenPos, GpiocenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpioden = RegisterModel<RccBase, GpiodenPos, GpiodenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpioeen = RegisterModel<RccBase, GpioeenPos, GpioeenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using gpiohen = RegisterModel<RccBase, GpiohenPos, GpiohenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using crcen   = RegisterModel<RccBase, CrcenPos,   CrcenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dma1en  = RegisterModel<RccBase, Dma1enPos,  Dma1enMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using dma2en  = RegisterModel<RccBase, Dma2enPos,  Dma2enMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace ahb2enr {
    using otgfsen = RegisterModel<RccBase, OtgfsenPos, OtgfsenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace apb1enr {
    using tim2en   = RegisterModel<RccBase, Tim2enPos,   Tim2enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim3en   = RegisterModel<RccBase, Tim3enPos,   Tim3enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim4en   = RegisterModel<RccBase, Tim4enPos,   Tim4enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim5en   = RegisterModel<RccBase, Tim5enPos,   Tim5enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using wwdgen   = RegisterModel<RccBase, WwdgenPos,   WwdgenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi2en   = RegisterModel<RccBase, Spi2enPos,   Spi2enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi3en   = RegisterModel<RccBase, Spi3enPos,   Spi3enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart2en = RegisterModel<RccBase, Usart2enPos, Usart2enMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c1en   = RegisterModel<RccBase, I2c1enPos,   I2c1enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c2en   = RegisterModel<RccBase, I2c2enPos,   I2c2enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using i2c3en   = RegisterModel<RccBase, I2c3enPos,   I2c3enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using pwren    = RegisterModel<RccBase, PwrenPos,    PwrenMsk,    PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }

  namespace apb2enr {
    using tim1en   = RegisterModel<RccBase, Tim1enPos,   Tim1enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart1en = RegisterModel<RccBase, Usart1enPos, Usart1enMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using usart6en = RegisterModel<RccBase, Usart6enPos, Usart6enMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using adc1en   = RegisterModel<RccBase, Adc1enPos,   Adc1enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using sdioen   = RegisterModel<RccBase, SdioenPos,   SdioenMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi1en   = RegisterModel<RccBase, Spi1enPos,   Spi1enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi4en   = RegisterModel<RccBase, Spi4enPos,   Spi4enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using syscfgen = RegisterModel<RccBase, SyscfgenPos, SyscfgenMsk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim9en   = RegisterModel<RccBase, Tim9enPos,   Tim9enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim10en  = RegisterModel<RccBase, Tim10enPos,  Tim10enMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using tim11en  = RegisterModel<RccBase, Tim11enPos,  Tim11enMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    using spi5en   = RegisterModel<RccBase, Spi5enPos,   Spi5enMsk,   PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
  }
}

#endif /* STM32_F411XE_REG_RCC_H */
