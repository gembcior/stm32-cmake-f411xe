#include "rcc/RccHal.h"
#include "stm32/f4/f411xe/rcc.h"


namespace stm32::hal::rcc {

namespace rcc = dral::stm32::f4::f411xe::rcc;

void RccHal::enableClockSource(ClockSource clockSource)
{
  switch (clockSource) {
    case ClockSource::Hsi:
      rcc::cr::hsion::write(1);
      while (rcc::cr::hsirdy::read() != 1);
      break;
    case ClockSource::Hse:
      rcc::cr::hseon::write(1);
      while (rcc::cr::hserdy::read() != 1);
      break;
    case ClockSource::Pll:
      rcc::cr::pllon::write(1);
      while (rcc::cr::pllrdy::read() != 1);
      break;
    case ClockSource::Plli2s:
      rcc::cr::plli2son::write(1);
      while (rcc::cr::plli2srdy::read() != 1);
      break;
    default:
      break;
  }
}


void RccHal::disableClockSource(ClockSource clockSource)
{
  switch (clockSource) {
    case ClockSource::Hsi:
      rcc::cr::hsion::write(0);
      break;
    case ClockSource::Hse:
      rcc::cr::hseon::write(0);
      break;
    case ClockSource::Pll:
      rcc::cr::pllon::write(0);
      break;
    case ClockSource::Plli2s:
      rcc::cr::plli2son::write(0);
      break;
    default:
      break;
  }
}


void RccHal::setSystemClockSource(ClockSource clockSource)
{
  uint32_t sw = 0;

  switch (clockSource) {
    case ClockSource::Hsi:
      sw = 0;
      break;
    case ClockSource::Hse:
      sw = 1;
      break;
    case ClockSource::Pll:
      sw = 2;
      break;
    default:
      break;
  }

  rcc::cfgr::sw::write(sw);
  while (rcc::cfgr::sws::read() != sw);
}


// TODO try different approach
void RccHal::setClockDomainPrescaler(ClockDomain clockDomain, ClockPrescaler clockPrescaler)
{
  switch (clockDomain) {
    case ClockDomain::Ahb:
      rcc::cfgr::hpre::write(AhbPrescalerTable[static_cast<uint32_t>(clockPrescaler)]);
      break;
    case ClockDomain::Apb1:
      rcc::cfgr::ppre1::write(ApbPrescalerTable[static_cast<uint32_t>(clockPrescaler)]);
      break;
    case ClockDomain::Apb2:
      rcc::cfgr::ppre2::write(ApbPrescalerTable[static_cast<uint32_t>(clockPrescaler)]);
      break;
    default:
      break;
  }
}


void RccHal::configureMainPll(const PllConfiguration config)
{
  rcc::pllcfgr::pllsrc::write(static_cast<uint32_t>(config.clockSource));
  rcc::pllcfgr::pllp::write(config.pllP);
  rcc::pllcfgr::plln::write(config.pllN);
  rcc::pllcfgr::pllm::write(config.pllM);
  rcc::pllcfgr::pllq::write(config.pllQ);
}


void RccHal::enablePeripheralClock(Apb1Peripheral peripheral)
{
  switch (peripheral) {
    case Apb1Peripheral::Pwr:
      rcc::apb1enr::pwren::write(1);
      break;
    case Apb1Peripheral:: I2c3:
      rcc::apb1enr::i2c3en::write(1);
      break;
    case Apb1Peripheral::I2c2:
      rcc::apb1enr::i2c2en::write(1);
      break;
    case Apb1Peripheral::I2c1:
      rcc::apb1enr::i2c1en::write(1);
      break;
    case Apb1Peripheral::Usart2:
      rcc::apb1enr::usart2en::write(1);
      break;
    case Apb1Peripheral::Spi3:
      rcc::apb1enr::spi3en::write(1);
      break;
    case Apb1Peripheral::Spi2:
      rcc::apb1enr::spi2en::write(1);
      break;
    case Apb1Peripheral::Wwdg:
      rcc::apb1enr::wwdgen::write(1);
      break;
    case Apb1Peripheral::Tim5:
      rcc::apb1enr::tim5en::write(1);
      break;
    case Apb1Peripheral::Tim4:
      rcc::apb1enr::tim4en::write(1);
      break;
    case Apb1Peripheral::Tim3:
      rcc::apb1enr::tim3en::write(1);
      break;
    case Apb1Peripheral::Tim2:
      rcc::apb1enr::tim2en::write(1);
      break;
    default:
      break;
  }
}


void RccHal::enablePeripheralClock(Apb2Peripheral peripheral)
{
  switch (peripheral) {
    case Apb2Peripheral::Spi5:
      rcc::apb2enr::spi5en::write(1);
      break;
    case Apb2Peripheral::Tim11:
      rcc::apb2enr::tim11en::write(1);
      break;
    case Apb2Peripheral::Tim10:
      rcc::apb2enr::tim10en::write(1);
      break;
    case Apb2Peripheral::Tim9:
      rcc::apb2enr::tim9en::write(1);
      break;
    case Apb2Peripheral::Syscfg:
      rcc::apb2enr::syscfgen::write(1);
      break;
    case Apb2Peripheral::Spi4:
      rcc::apb2enr::spi4en::write(1);
      break;
    case Apb2Peripheral::Spi1:
      rcc::apb2enr::spi1en::write(1);
      break;
    case Apb2Peripheral::Sdio:
      rcc::apb2enr::sdioen::write(1);
      break;
    case Apb2Peripheral::Adc1:
      rcc::apb2enr::adc1en::write(1);
      break;
    case Apb2Peripheral::Usart6:
      rcc::apb2enr::usart6en::write(1);
      break;
    case Apb2Peripheral::Usart1:
      rcc::apb2enr::usart1en::write(1);
      break;
    case Apb2Peripheral::Tim1:
      rcc::apb2enr::tim1en::write(1);
      break;
    default:
      break;
  }
}


void RccHal::enablePeripheralClock(Ahb1Peripheral peripheral)
{
  switch (peripheral) {
    case Ahb1Peripheral::Dma2:
      rcc::ahb1enr::dma2en::write(1);
      break;
    case Ahb1Peripheral::Dma1:
      rcc::ahb1enr::dma1en::write(1);
      break;
    case Ahb1Peripheral::Crc:
      rcc::ahb1enr::crcen::write(1);
      break;
    case Ahb1Peripheral::Gpioh:
      rcc::ahb1enr::gpiohen::write(1);
      break;
    case Ahb1Peripheral::Gpioe:
      rcc::ahb1enr::gpioeen::write(1);
      break;
    case Ahb1Peripheral::Gpiod:
      rcc::ahb1enr::gpioden::write(1);
      break;
    case Ahb1Peripheral::Gpioc:
      rcc::ahb1enr::gpiocen::write(1);
      break;
    case Ahb1Peripheral::Gpiob:
      rcc::ahb1enr::gpioben::write(1);
      break;
    case Ahb1Peripheral::Gpioa:
      rcc::ahb1enr::gpioaen::write(1);
      break;
    default:
      break;
  }
}


void RccHal::enablePeripheralClock(Ahb2Peripheral peripheral)
{
  switch (peripheral) {
    case Ahb2Peripheral::Otgfs:
      rcc::ahb2enr::otgfsen::write(1);
      break;
    default:
      break;
  }
}

}
