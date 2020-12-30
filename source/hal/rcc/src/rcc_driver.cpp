#include "rcc/rcc_driver.h"
#include "stm32/f411xe/reg/rcc.h"

namespace stm32::hal::rcc {

void RccDriver::enableClockSource(ClockSource clockSource)
{
  switch (clockSource) {
    case ClockSource::Hsi:
      stm32::rcc::cr::hsion::write(1);
      while(stm32::rcc::cr::hsirdy::read() != 1)
      break;
    case ClockSource::Hse:
      stm32::rcc::cr::hseon::write(1);
      while(stm32::rcc::cr::hserdy::read() != 1)
      break;
    case ClockSource::Pll:
      stm32::rcc::cr::pllon::write(1);
      while(stm32::rcc::cr::pllrdy::read() != 1)
      break;
    case ClockSource::Plli2s:
      stm32::rcc::cr::plli2son::write(1);
      while(stm32::rcc::cr::plli2srdy::read() != 1)
      break;
    default:
      break;
  };
}


void RccDriver::disableClockSource(ClockSource clockSource)
{
  switch (clockSource) {
    case ClockSource::Hsi:
      stm32::rcc::cr::hsion::write(0);
      break;
    case ClockSource::Hse:
      stm32::rcc::cr::hseon::write(0);
      break;
    case ClockSource::Pll:
      stm32::rcc::cr::pllon::write(0);
      break;
    case ClockSource::Plli2s:
      stm32::rcc::cr::plli2son::write(0);
      break;
    default:
      break;
  };
}


void RccDriver::setSystemClockSource(ClockSource clockSource)
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
  };

  stm32::rcc::cfgr::sw::write(sw);
  while (stm32::rcc::cfgr::sws::read() != sw);
}


// TODO try different approach
void RccDriver::setClockDomainPrescaler(ClockDomain clockDomain, ClockPrescaler clockPrescaler)
{
  switch (clockDomain) {
    case ClockDomain::Ahb:
      stm32::rcc::cfgr::hpre::write(AhbPrescalerTable[static_cast<uint32_t>(clockPrescaler)]);
      break;
    case ClockDomain::Apb1:
      stm32::rcc::cfgr::ppre1::write(ApbPrescalerTable[static_cast<uint32_t>(clockPrescaler)]);
      break;
    case ClockDomain::Apb2:
      stm32::rcc::cfgr::ppre2::write(ApbPrescalerTable[static_cast<uint32_t>(clockPrescaler)]);
      break;
    default:
      break;
  }
}


void RccDriver::configureMainPll(const PllConfiguration config)
{
  stm32::rcc::pllcfgr::pllm::write(config.pllM);
  stm32::rcc::pllcfgr::plln::write(config.pllN);
  stm32::rcc::pllcfgr::pllp::write(config.pllP);
  stm32::rcc::pllcfgr::pllq::write(config.pllQ);
  stm32::rcc::pllcfgr::pllsrc::write(static_cast<uint32_t>(config.clockSource));
}

void RccDriver::enablePeripheralClock(Apb1Peripheral peripheral)
{
  switch (peripheral) {
    case Apb1Peripheral::Pwr:
      stm32::rcc::apb1enr::pwren::write(1);
      break;
    case Apb1Peripheral:: I2c3:
      stm32::rcc::apb1enr::i2c3en::write(1);
      break;
    case Apb1Peripheral::I2c2:
      stm32::rcc::apb1enr::i2c2en::write(1);
      break;
    case Apb1Peripheral::I2c1:
      stm32::rcc::apb1enr::i2c1en::write(1);
      break;
    case Apb1Peripheral::Usart2:
      stm32::rcc::apb1enr::usart2en::write(1);
      break;
    case Apb1Peripheral::Spi3:
      stm32::rcc::apb1enr::spi3en::write(1);
      break;
    case Apb1Peripheral::Spi2:
      stm32::rcc::apb1enr::spi2en::write(1);
      break;
    case Apb1Peripheral::Wwdg:
      stm32::rcc::apb1enr::wwdgen::write(1);
      break;
    case Apb1Peripheral::Tim5:
      stm32::rcc::apb1enr::tim5en::write(1);
      break;
    case Apb1Peripheral::Tim4:
      stm32::rcc::apb1enr::tim4en::write(1);
      break;
    case Apb1Peripheral::Tim3:
      stm32::rcc::apb1enr::tim3en::write(1);
      break;
    case Apb1Peripheral::Tim2:
      stm32::rcc::apb1enr::tim2en::write(1);
      break;
    default:
      break;
  }
}


void RccDriver::enablePeripheralClock(Apb2Peripheral peripheral)
{
  switch (peripheral) {
    case Apb2Peripheral::Spi5:
      stm32::rcc::apb2enr::spi5en::write(1);
      break;
    case Apb2Peripheral::Tim11:
      stm32::rcc::apb2enr::tim11en::write(1);
      break;
    case Apb2Peripheral::Tim10:
      stm32::rcc::apb2enr::tim10en::write(1);
      break;
    case Apb2Peripheral::Tim9:
      stm32::rcc::apb2enr::tim9en::write(1);
      break;
    case Apb2Peripheral::Syscfg:
      stm32::rcc::apb2enr::syscfgen::write(1);
      break;
    case Apb2Peripheral::Spi4:
      stm32::rcc::apb2enr::spi4en::write(1);
      break;
    case Apb2Peripheral::Spi1:
      stm32::rcc::apb2enr::spi1en::write(1);
      break;
    case Apb2Peripheral::Sdio:
      stm32::rcc::apb2enr::sdioen::write(1);
      break;
    case Apb2Peripheral::Adc1:
      stm32::rcc::apb2enr::adc1en::write(1);
      break;
    case Apb2Peripheral::Usart6:
      stm32::rcc::apb2enr::usart6en::write(1);
      break;
    case Apb2Peripheral::Usart1:
      stm32::rcc::apb2enr::usart1en::write(1);
      break;
    case Apb2Peripheral::Tim1:
      stm32::rcc::apb2enr::tim1en::write(1);
      break;
    default:
      break;
  }
}


void RccDriver::enablePeripheralClock(Ahb1Peripheral peripheral)
{
  switch (peripheral) {
    case Ahb1Peripheral::Dma2:
      stm32::rcc::ahb1enr::dma2en::write(1);
      break;
    case Ahb1Peripheral::Dma1:
      stm32::rcc::ahb1enr::dma1en::write(1);
      break;
    case Ahb1Peripheral::Crc:
      stm32::rcc::ahb1enr::crcen::write(1);
      break;
    case Ahb1Peripheral::Gpioh:
      stm32::rcc::ahb1enr::gpiohen::write(1);
      break;
    case Ahb1Peripheral::Gpioe:
      stm32::rcc::ahb1enr::gpioeen::write(1);
      break;
    case Ahb1Peripheral::Gpiod:
      stm32::rcc::ahb1enr::gpioden::write(1);
      break;
    case Ahb1Peripheral::Gpioc:
      stm32::rcc::ahb1enr::gpiocen::write(1);
      break;
    case Ahb1Peripheral::Gpiob:
      stm32::rcc::ahb1enr::gpioben::write(1);
      break;
    case Ahb1Peripheral::Gpioa:
      stm32::rcc::ahb1enr::gpioaen::write(1);
      break;
    default:
      break;
  }
}


void RccDriver::enablePeripheralClock(Ahb2Peripheral peripheral)
{
  switch (peripheral) {
    case Ahb2Peripheral::Otgfs:
      stm32::rcc::ahb2enr::otgfsen::write(1);
      break;
    default:
      break;
  }
}

}
