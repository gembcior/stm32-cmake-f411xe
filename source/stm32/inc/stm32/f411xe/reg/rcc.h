#ifndef STM32_F411XE_REG_RCC_H
#define STM32_F411XE_REG_RCC_H

#include "stm32/register_model/register_model.h"
#include "stm32/f411xe/const/general.h"
#include "stm32/f411xe/const/rcc.h"

namespace stm32::regs::rcc {

using namespace stm32::constants::rcc;


template <uint32_t address, RegisterPolicy regPolicy>
class CrReg: public RegisterModel<address, regPolicy>
{
public:
  using hsion     = FieldModel<address, cr::HsionPos,     cr::HsionMsk,     regPolicy, FieldPolicy::ReadWrite>;
  using hsirdy    = FieldModel<address, cr::HsirdyPos,    cr::HsirdyMsk,    regPolicy, FieldPolicy::ReadOnly>;
  using hsitrim   = FieldModel<address, cr::HsitrimPos,   cr::HsitrimMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using hsical    = FieldModel<address, cr::HsicalPos,    cr::HsicalMsk,    regPolicy, FieldPolicy::ReadOnly>;
  using hseon     = FieldModel<address, cr::HseonPos,     cr::HseonMsk,     regPolicy, FieldPolicy::ReadWrite>;
  using hserdy    = FieldModel<address, cr::HserdyPos,    cr::HserdyMsk,    regPolicy, FieldPolicy::ReadOnly>;
  using hsebyp    = FieldModel<address, cr::HsebypPos,    cr::HsebypMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using csson     = FieldModel<address, cr::CssonPos,     cr::CssonMsk,     regPolicy, FieldPolicy::ReadWrite>;
  using pllon     = FieldModel<address, cr::PllonPos,     cr::PllonMsk,     regPolicy, FieldPolicy::ReadWrite>;
  using pllrdy    = FieldModel<address, cr::PllrdyPos,    cr::PllrdyMsk,    regPolicy, FieldPolicy::ReadOnly>;
  using plli2son  = FieldModel<address, cr::Plli2sonPos,  cr::Plli2SonMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using plli2srdy = FieldModel<address, cr::Plli2srdyPos, cr::Plli2srdyMsk, regPolicy, FieldPolicy::ReadOnly>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class PllcfgrReg: public RegisterModel<address, regPolicy>
{
public:
  using pllm   = FieldModel<address, pllcfgr::PllmPos,   pllcfgr::PllmMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using plln   = FieldModel<address, pllcfgr::PllnPos,   pllcfgr::PllnMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using pllp   = FieldModel<address, pllcfgr::PllpPos,   pllcfgr::PllpMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using pllsrc = FieldModel<address, pllcfgr::PllsrcPos, pllcfgr::PllsrcMsk, regPolicy, FieldPolicy::ReadWrite>;
  using pllq   = FieldModel<address, pllcfgr::PllqPos,   pllcfgr::PllqMsk,   regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class CfgrReg: public RegisterModel<address, regPolicy>
{
public:
  using sw      = FieldModel<address, cfgr::SwPos,      cfgr::SwMsk,      regPolicy, FieldPolicy::ReadWrite>;
  using sws     = FieldModel<address, cfgr::SwsPos,     cfgr::SwsMsk,     regPolicy, FieldPolicy::ReadOnly>;
  using hpre    = FieldModel<address, cfgr::HprePos,    cfgr::HpreMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using ppre1   = FieldModel<address, cfgr::Ppre1Pos,   cfgr::Ppre1Msk,   regPolicy, FieldPolicy::ReadWrite>;
  using ppre2   = FieldModel<address, cfgr::Ppre2Pos,   cfgr::Ppre2Msk,   regPolicy, FieldPolicy::ReadWrite>;
  using rtcpre  = FieldModel<address, cfgr::RtcprePos,  cfgr::RtcpreMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using mco1    = FieldModel<address, cfgr::Mco1Pos,    cfgr::Mco1Msk,    regPolicy, FieldPolicy::ReadWrite>;
  using i2ssrc  = FieldModel<address, cfgr::I2ssrcPos,  cfgr::I2ssrcMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using mco1pre = FieldModel<address, cfgr::Mco1prePos, cfgr::Mco1preMsk, regPolicy, FieldPolicy::ReadWrite>;
  using mco2pre = FieldModel<address, cfgr::Mco2prePos, cfgr::Mco2preMsk, regPolicy, FieldPolicy::ReadWrite>;
  using mco2    = FieldModel<address, cfgr::Mco2Pos,    cfgr::Mco2Msk,    regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class CirReg: public RegisterModel<address, regPolicy>
{
public:
  using lsirdyf     = FieldModel<address, cir::LsirdycPos,     cir::LsirdycMsk,     regPolicy, FieldPolicy::ReadOnly>;
  using lserdyf     = FieldModel<address, cir::LserdyfPos,     cir::LserdyfMsk,     regPolicy, FieldPolicy::ReadOnly>;
  using hsirdyf     = FieldModel<address, cir::HsirdyfPos,     cir::HsirdyfMsk,     regPolicy, FieldPolicy::ReadOnly>;
  using hserdyf     = FieldModel<address, cir::HserdyfPos,     cir::HserdyfMsk,     regPolicy, FieldPolicy::ReadOnly>;
  using pllrdyf     = FieldModel<address, cir::PllrdyfPos,     cir::PllrdyfMsk,     regPolicy, FieldPolicy::ReadOnly>;
  using plli2srdyf  = FieldModel<address, cir::Plli2srdyfPos,  cir::Plli2srdyfMsk,  regPolicy, FieldPolicy::ReadOnly>;
  using cssf        = FieldModel<address, cir::CssfPos,        cir::CssfMsk,        regPolicy, FieldPolicy::ReadOnly>;
  using lsirdyie    = FieldModel<address, cir::LsirdyiePos,    cir::LsirdyieMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using lserdyie    = FieldModel<address, cir::LserdyiePos,    cir::LserdyieMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using hsirdyie    = FieldModel<address, cir::HsirdyiePos,    cir::HsirdyieMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using hserdyie    = FieldModel<address, cir::HserdyiePos,    cir::HserdyieMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using pllrdyie    = FieldModel<address, cir::PllrdyiePos,    cir::PllrdyieMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using plli2srdyie = FieldModel<address, cir::Plli2srdyiePos, cir::Plli2srdyieMsk, regPolicy, FieldPolicy::ReadWrite>;
  using lsirdyc     = FieldModel<address, cir::LsirdycPos,     cir::LsirdycMsk,     regPolicy, FieldPolicy::WriteOnly>;
  using lserdyc     = FieldModel<address, cir::LserdycPos,     cir::LserdycMsk,     regPolicy, FieldPolicy::WriteOnly>;
  using hsirdyc     = FieldModel<address, cir::HsirdycPos,     cir::HsirdycMsk,     regPolicy, FieldPolicy::WriteOnly>;
  using hserdyc     = FieldModel<address, cir::HserdycPos,     cir::HserdycMsk,     regPolicy, FieldPolicy::WriteOnly>;
  using pllrdyc     = FieldModel<address, cir::PllrdycPos,     cir::PllrdycMsk,     regPolicy, FieldPolicy::WriteOnly>;
  using plli2srdyc  = FieldModel<address, cir::Plli2srdycPos,  cir::Plli2srdycMsk,  regPolicy, FieldPolicy::WriteOnly>;
  using cssc        = FieldModel<address, cir::CsscPos,        cir::CsscMsk,        regPolicy, FieldPolicy::WriteOnly>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Ahb1rstrReg: public RegisterModel<address, regPolicy>
{
public:
  using gpioarst = FieldModel<address, ahb1rstr::GpioarstPos, ahb1rstr::GpioarstMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpiobrst = FieldModel<address, ahb1rstr::GpiobrstPos, ahb1rstr::GpiobrstMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpiocrst = FieldModel<address, ahb1rstr::GpiocrstPos, ahb1rstr::GpiocrstMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpiodrst = FieldModel<address, ahb1rstr::GpiodrstPos, ahb1rstr::GpiodrstMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpioerst = FieldModel<address, ahb1rstr::GpioerstPos, ahb1rstr::GpioerstMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpiohrst = FieldModel<address, ahb1rstr::GpiohrstPos, ahb1rstr::GpiohrstMsk, regPolicy, FieldPolicy::ReadWrite>;
  using crcrst   = FieldModel<address, ahb1rstr::CrcrstPos,   ahb1rstr::CrcrstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using dma1rst  = FieldModel<address, ahb1rstr::Dma1rstPos,  ahb1rstr::Dma1rstMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using dma2rst  = FieldModel<address, ahb1rstr::Dma2rstPos,  ahb1rstr::Dma2rstMsk,  regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Ahb2rstrReg: public RegisterModel<address, regPolicy>
{
public:
  using otgfsrst = FieldModel<address, ahb2rstr::OtgfsrstPos, ahb2rstr::OtgfsrstMsk, regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Apb1rstrReg: public RegisterModel<address, regPolicy>
{
public:
  using tim2rst   = FieldModel<address, apb1rstr::Tim2rstPos,   apb1rstr::Tim2rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim3rst   = FieldModel<address, apb1rstr::Tim3rstPos,   apb1rstr::Tim3rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim4rst   = FieldModel<address, apb1rstr::Tim4rstPos,   apb1rstr::Tim4rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim5rst   = FieldModel<address, apb1rstr::Tim5rstPos,   apb1rstr::Tim5rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using wwdgrst   = FieldModel<address, apb1rstr::WwdgrstPos,   apb1rstr::WwdgrstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi2rst   = FieldModel<address, apb1rstr::Spi2rstPos,   apb1rstr::Spi2rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi3rst   = FieldModel<address, apb1rstr::Spi3rstPos,   apb1rstr::Spi3rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using usart2rst = FieldModel<address, apb1rstr::Usart2rstPos, apb1rstr::Usart2rstMsk, regPolicy, FieldPolicy::ReadWrite>;
  using i2c1rst   = FieldModel<address, apb1rstr::I2c1rstPos,   apb1rstr::I2c1rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using i2c2rst   = FieldModel<address, apb1rstr::I2c2rstPos,   apb1rstr::I2c2rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using i2c3rst   = FieldModel<address, apb1rstr::I2c3rstPos,   apb1rstr::I2c3rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using pwrrst    = FieldModel<address, apb1rstr::PwrrstPos,    apb1rstr::PwrrstMsk,    regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Apb2rstrReg: public RegisterModel<address, regPolicy>
{
public:
  using tim1rst   = FieldModel<address, apb2rstr::Tim1rstPos,   apb2rstr::Tim1rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using usart1rst = FieldModel<address, apb2rstr::Usart1rstPos, apb2rstr::Usart1rstMsk, regPolicy, FieldPolicy::ReadWrite>;
  using usart6rst = FieldModel<address, apb2rstr::Usart6rstPos, apb2rstr::Usart6rstMsk, regPolicy, FieldPolicy::ReadWrite>;
  using adcrst    = FieldModel<address, apb2rstr::AdcrstPos,    apb2rstr::AdcrstMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using sdiorst   = FieldModel<address, apb2rstr::SdiorstPos,   apb2rstr::SdiorstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi1rst   = FieldModel<address, apb2rstr::Spi1rstPos,   apb2rstr::Spi1rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi4rst   = FieldModel<address, apb2rstr::Spi4rstPos,   apb2rstr::Spi4rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using syscfgrst = FieldModel<address, apb2rstr::SyscfgrstPos, apb2rstr::SyscfgrstMsk, regPolicy, FieldPolicy::ReadWrite>;
  using tim9rst   = FieldModel<address, apb2rstr::Tim9rstPos,   apb2rstr::Tim9rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim10rst  = FieldModel<address, apb2rstr::Tim10rstPos,  apb2rstr::Tim10rstMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using tim11rst  = FieldModel<address, apb2rstr::Tim11rstPos,  apb2rstr::Tim11rstMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using spi5rst   = FieldModel<address, apb2rstr::Spi5rstPos,   apb2rstr::Spi5rstMsk,   regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Ahb1enrReg: public RegisterModel<address, regPolicy>
{
public:
  using gpioaen = FieldModel<address, ahb1enr::GpioaenPos, ahb1enr::GpioaenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpioben = FieldModel<address, ahb1enr::GpiobenPos, ahb1enr::GpiobenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpiocen = FieldModel<address, ahb1enr::GpiocenPos, ahb1enr::GpiocenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpioden = FieldModel<address, ahb1enr::GpiodenPos, ahb1enr::GpiodenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpioeen = FieldModel<address, ahb1enr::GpioeenPos, ahb1enr::GpioeenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpiohen = FieldModel<address, ahb1enr::GpiohenPos, ahb1enr::GpiohenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using crcen   = FieldModel<address, ahb1enr::CrcenPos,   ahb1enr::CrcenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using dma1en  = FieldModel<address, ahb1enr::Dma1enPos,  ahb1enr::Dma1enMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using dma2en  = FieldModel<address, ahb1enr::Dma2enPos,  ahb1enr::Dma2enMsk,  regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Ahb2enrReg: public RegisterModel<address, regPolicy>
{
public:
  using otgfsen = FieldModel<address, ahb2enr::OtgfsenPos, ahb2enr::OtgfsenMsk, regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Apb1enrReg: public RegisterModel<address, regPolicy>
{
public:
  using tim2en   = FieldModel<address, apb1enr::Tim2enPos,   apb1enr::Tim2enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim3en   = FieldModel<address, apb1enr::Tim3enPos,   apb1enr::Tim3enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim4en   = FieldModel<address, apb1enr::Tim4enPos,   apb1enr::Tim4enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim5en   = FieldModel<address, apb1enr::Tim5enPos,   apb1enr::Tim5enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using wwdgen   = FieldModel<address, apb1enr::WwdgenPos,   apb1enr::WwdgenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi2en   = FieldModel<address, apb1enr::Spi2enPos,   apb1enr::Spi2enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi3en   = FieldModel<address, apb1enr::Spi3enPos,   apb1enr::Spi3enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using usart2en = FieldModel<address, apb1enr::Usart2enPos, apb1enr::Usart2enMsk, regPolicy, FieldPolicy::ReadWrite>;
  using i2c1en   = FieldModel<address, apb1enr::I2c1enPos,   apb1enr::I2c1enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using i2c2en   = FieldModel<address, apb1enr::I2c2enPos,   apb1enr::I2c2enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using i2c3en   = FieldModel<address, apb1enr::I2c3enPos,   apb1enr::I2c3enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using pwren    = FieldModel<address, apb1enr::PwrenPos,    apb1enr::PwrenMsk,    regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Apb2enrReg: public RegisterModel<address, regPolicy>
{
public:
  using tim1en   = FieldModel<address, apb2enr::Tim1enPos,   apb2enr::Tim1enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using usart1en = FieldModel<address, apb2enr::Usart1enPos, apb2enr::Usart1enMsk, regPolicy, FieldPolicy::ReadWrite>;
  using usart6en = FieldModel<address, apb2enr::Usart6enPos, apb2enr::Usart6enMsk, regPolicy, FieldPolicy::ReadWrite>;
  using adc1en   = FieldModel<address, apb2enr::Adc1enPos,   apb2enr::Adc1enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using sdioen   = FieldModel<address, apb2enr::SdioenPos,   apb2enr::SdioenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi1en   = FieldModel<address, apb2enr::Spi1enPos,   apb2enr::Spi1enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi4en   = FieldModel<address, apb2enr::Spi4enPos,   apb2enr::Spi4enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using syscfgen = FieldModel<address, apb2enr::SyscfgenPos, apb2enr::SyscfgenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using tim9en   = FieldModel<address, apb2enr::Tim9enPos,   apb2enr::Tim9enMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim10en  = FieldModel<address, apb2enr::Tim10enPos,  apb2enr::Tim10enMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using tim11en  = FieldModel<address, apb2enr::Tim11enPos,  apb2enr::Tim11enMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using spi5en   = FieldModel<address, apb2enr::Spi5enPos,   apb2enr::Spi5enMsk,   regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Ahb1lpenrReg: public RegisterModel<address, regPolicy>
{
public:
  using gpioalpen = FieldModel<address, ahb1lpenr::GpioalpenPos, ahb1lpenr::GpioalpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpioblpen = FieldModel<address, ahb1lpenr::GpioblpenPos, ahb1lpenr::GpioblpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpioclpen = FieldModel<address, ahb1lpenr::GpioclpenPos, ahb1lpenr::GpioclpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpiodlpen = FieldModel<address, ahb1lpenr::GpiodlpenPos, ahb1lpenr::GpiodlpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpioelpen = FieldModel<address, ahb1lpenr::GpioelpenPos, ahb1lpenr::GpioelpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using gpiohlpen = FieldModel<address, ahb1lpenr::GpiohlpenPos, ahb1lpenr::GpiohlpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using crclpen   = FieldModel<address, ahb1lpenr::CrclpenPos,   ahb1lpenr::CrclpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using flitflpen = FieldModel<address, ahb1lpenr::FlitflpenPos, ahb1lpenr::FlitflpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using sram1lpen = FieldModel<address, ahb1lpenr::Sram1lpenPos, ahb1lpenr::Sram1lpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using dma1lpen  = FieldModel<address, ahb1lpenr::Dma1lpenPos,  ahb1lpenr::Dma1lpenMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using dma2lpen  = FieldModel<address, ahb1lpenr::Dma2lpenPos,  ahb1lpenr::Dma2lpenMsk,  regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Ahb2lpenrReg: public RegisterModel<address, regPolicy>
{
public:
  using otgfslpen = FieldModel<address, ahb2lpenr::OtgfslpenPos, ahb2lpenr::OtgfslpenMsk, regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Apb1lpenrReg: public RegisterModel<address, regPolicy>
{
public:
  using tim2lpen   = FieldModel<address, apb1lpenr::Tim2lpenPos,   apb1lpenr::Tim2lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim3lpen   = FieldModel<address, apb1lpenr::Tim3lpenPos,   apb1lpenr::Tim3lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim4lpen   = FieldModel<address, apb1lpenr::Tim4lpenPos,   apb1lpenr::Tim4lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim5lpen   = FieldModel<address, apb1lpenr::Tim5lpenPos,   apb1lpenr::Tim5lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using wwdglpen   = FieldModel<address, apb1lpenr::WwdglpenPos,   apb1lpenr::WwdglpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi2lpen   = FieldModel<address, apb1lpenr::Spi2lpenPos,   apb1lpenr::Spi2lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi3lpen   = FieldModel<address, apb1lpenr::Spi3lpenPos,   apb1lpenr::Spi3lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using usart2lpen = FieldModel<address, apb1lpenr::Usart2lpenPos, apb1lpenr::Usart2lpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using i2c1lpen   = FieldModel<address, apb1lpenr::I2c1lpenPos,   apb1lpenr::I2c1lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using i2c2lpen   = FieldModel<address, apb1lpenr::I2c2lpenPos,   apb1lpenr::I2c2lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using i2c3lpen   = FieldModel<address, apb1lpenr::I2c3lpenPos,   apb1lpenr::I2c3lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using pwrlpen    = FieldModel<address, apb1lpenr::PwrlpenPos,    apb1lpenr::PwrlpenMsk,    regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Apb2lpenrReg: public RegisterModel<address, regPolicy>
{
public:
  using tim1lpen   = FieldModel<address, apb2lpenr::Tim1lpenPos,   apb2lpenr::Tim1lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using usart1lpen = FieldModel<address, apb2lpenr::Usart1lpenPos, apb2lpenr::Usart1lpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using usart6lpen = FieldModel<address, apb2lpenr::Usart6lpenPos, apb2lpenr::Usart6lpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using adc1lpen   = FieldModel<address, apb2lpenr::Adc1lpenPos,   apb2lpenr::Adc1lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using sdiolpen   = FieldModel<address, apb2lpenr::SdiolpenPos,   apb2lpenr::SdiolpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi1lpen   = FieldModel<address, apb2lpenr::Spi1lpenPos,   apb2lpenr::Spi1lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spi4lpen   = FieldModel<address, apb2lpenr::Spi4lpenPos,   apb2lpenr::Spi4lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using syscfglpen = FieldModel<address, apb2lpenr::SyscfglpenPos, apb2lpenr::SyscfglpenMsk, regPolicy, FieldPolicy::ReadWrite>;
  using tim9lpen   = FieldModel<address, apb2lpenr::Tim9lpenPos,   apb2lpenr::Tim9lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using tim10lpen  = FieldModel<address, apb2lpenr::Tim10lpenPos,  apb2lpenr::Tim10lpenMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using tim11lpen  = FieldModel<address, apb2lpenr::Tim11lpenPos,  apb2lpenr::Tim11lpenMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using spi5lpen   = FieldModel<address, apb2lpenr::Spi5lpenPos,   apb2lpenr::Spi5lpenMsk,   regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class BdcrReg: public RegisterModel<address, regPolicy>
{
public:
  using lseon  = FieldModel<address, bdcr::LseonPos,  bdcr::LseonMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using lserdy = FieldModel<address, bdcr::LserdyPos, bdcr::LserdyMsk, regPolicy, FieldPolicy::ReadOnly>;
  using lsebyp = FieldModel<address, bdcr::LsebypPos, bdcr::LsebypMsk, regPolicy, FieldPolicy::ReadWrite>;
  using lsemod = FieldModel<address, bdcr::LsemodPos, bdcr::LsemodMsk, regPolicy, FieldPolicy::ReadWrite>;
  using rtcsel = FieldModel<address, bdcr::RtcselPos, bdcr::RtcselMsk, regPolicy, FieldPolicy::ReadWrite>;
  using rtcen  = FieldModel<address, bdcr::RtcenPos,  bdcr::RtcenMsk,  regPolicy, FieldPolicy::ReadWrite>;
  using bdrst  = FieldModel<address, bdcr::BdrstPos,  bdcr::BdrstMsk,  regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class CsrReg: public RegisterModel<address, regPolicy>
{
public:
  using lsion    = FieldModel<address, csr::LsionPos,    csr::LsionMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using lsirdy   = FieldModel<address, csr::LsirdyPos,   csr::LsirdyMsk,   regPolicy, FieldPolicy::ReadOnly>;
  using rmvf     = FieldModel<address, csr::RmvfPos,     csr::RmvfMsk,     regPolicy, FieldPolicy::ReadWrite>; // rt_w
  using borrstf  = FieldModel<address, csr::BorrstfPos,  csr::BorrstfMsk,  regPolicy, FieldPolicy::ReadOnly>;
  using pinrstf  = FieldModel<address, csr::PinrstfPos,  csr::PinrstfMsk,  regPolicy, FieldPolicy::ReadOnly>;
  using porrstf  = FieldModel<address, csr::PorrstfPos,  csr::PorrstfMsk,  regPolicy, FieldPolicy::ReadOnly>;
  using sftrstf  = FieldModel<address, csr::SftrstfPos,  csr::SftrstfMsk,  regPolicy, FieldPolicy::ReadOnly>;
  using iwdgrstf = FieldModel<address, csr::IwdgrstfPos, csr::IwdgrstfMsk, regPolicy, FieldPolicy::ReadOnly>;
  using wwdgrstf = FieldModel<address, csr::WwdgrstfPos, csr::WwdgrstfMsk, regPolicy, FieldPolicy::ReadOnly>;
  using lpwrrstf = FieldModel<address, csr::LpwrrstfPos, csr::LpwrrstfMsk, regPolicy, FieldPolicy::ReadOnly>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class SscgrReg: public RegisterModel<address, regPolicy>
{
public:
  using modper    = FieldModel<address, sscgr::ModperPos,    sscgr::ModperMsk,    regPolicy, FieldPolicy::ReadWrite>;
  using incstep   = FieldModel<address, sscgr::IncstepPos,   sscgr::IncstepMsk,   regPolicy, FieldPolicy::ReadWrite>;
  using spreadsel = FieldModel<address, sscgr::SpreadselPos, sscgr::SpreadselMsk, regPolicy, FieldPolicy::ReadWrite>;
  using sscgen    = FieldModel<address, sscgr::SscgenPos,    sscgr::SscgenMsk,    regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class Plli2scfgrReg: public RegisterModel<address, regPolicy>
{
public:
  using plli2sm = FieldModel<address, plli2scfgr::Plli2smPos, plli2scfgr::Plli2smMsk, regPolicy, FieldPolicy::ReadWrite>;
  using plli2sn = FieldModel<address, plli2scfgr::Plli2snPos, plli2scfgr::Plli2snMsk, regPolicy, FieldPolicy::ReadWrite>;
  using plli2sr = FieldModel<address, plli2scfgr::Plli2srPos, plli2scfgr::Plli2srMsk, regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class DckcfgrReg: public RegisterModel<address, regPolicy>
{
public:
  using timpre = FieldModel<address, dckcfgr::TimprePos, dckcfgr::TimpreMsk, regPolicy, FieldPolicy::ReadWrite>;
};


using cr         = CrReg<cr::Address, RegisterPolicy::ReadWrite>;
using pllcfgr    = PllcfgrReg<pllcfgr::Address, RegisterPolicy::ReadWrite>;
using cfgr       = CfgrReg<cfgr::Address, RegisterPolicy::ReadWrite>;
using cir        = CirReg<cir::Address, RegisterPolicy::ReadWrite>;
using ahb1rstr   = Ahb1rstrReg<ahb1rstr::Address, RegisterPolicy::ReadWrite>;
using ahb2rstr   = Ahb2rstrReg<ahb2rstr::Address, RegisterPolicy::ReadWrite>;
using apb1rstr   = Apb1rstrReg<apb1rstr::Address, RegisterPolicy::ReadWrite>;
using apb2rstr   = Apb2rstrReg<apb2rstr::Address, RegisterPolicy::ReadWrite>;
using ahb1enr    = Ahb1enrReg<ahb1enr::Address, RegisterPolicy::ReadWrite>;
using ahb2enr    = Ahb2enrReg<ahb2enr::Address, RegisterPolicy::ReadWrite>;
using apb1enr    = Apb1enrReg<apb1enr::Address, RegisterPolicy::ReadWrite>;
using apb2enr    = Apb2enrReg<apb2enr::Address, RegisterPolicy::ReadWrite>;
using ahb1lpenr  = Ahb1lpenrReg<ahb1lpenr::Address, RegisterPolicy::ReadWrite>;
using ahb2lpenr  = Ahb2lpenrReg<ahb2lpenr::Address, RegisterPolicy::ReadWrite>;
using apb1lpenr  = Apb1lpenrReg<apb1lpenr::Address, RegisterPolicy::ReadWrite>;
using apb2lpenr  = Apb2lpenrReg<apb2lpenr::Address, RegisterPolicy::ReadWrite>;
using bdcr       = BdcrReg<bdcr::Address, RegisterPolicy::ReadWrite>;
using csr        = CsrReg<csr::Address, RegisterPolicy::ReadWrite>;
using sscgr      = SscgrReg<sscgr::Address, RegisterPolicy::ReadWrite>;
using plli2scfgr = Plli2scfgrReg<plli2scfgr::Address, RegisterPolicy::ReadWrite>;
using dckcfgr    = DckcfgrReg<dckcfgr::Address, RegisterPolicy::ReadWrite>;

}

#endif /* STM32_F411XE_REG_RCC_H */

