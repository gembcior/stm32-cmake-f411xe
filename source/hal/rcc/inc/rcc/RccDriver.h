#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H

#include <cstdint>
#include "rcc.h"
#include "stm32/f411xe/reg/rcc.h"

namespace stm32::hal::rcc {

namespace rcc = stm32::regs::rcc;


class RccDriver
{
public:
  void enableClockSource(ClockSource clockSource);
  void disableClockSource(ClockSource clockSource);
  void setSystemClockSource(ClockSource clockSource);
  void setClockDomainPrescaler(ClockDomain clockDomain, ClockPrescaler clockPrescaler);
  void configureMainPll(const PllConfiguration config);
  void enablePeripheralClock(Apb1Peripheral peripheral);
  void enablePeripheralClock(Apb2Peripheral peripheral);
  void enablePeripheralClock(Ahb1Peripheral peripheral);
  void enablePeripheralClock(Ahb2Peripheral peripheral);

private:
  static constexpr uint32_t ApbPrescalerTable[] = {0b000, 0b100, 0b101, 0b110, 0b111};
  static constexpr uint32_t AhbPrescalerTable[] = {0b0000, 0b1000, 0b1001, 0b1010, 0b1011, 0b1100, 0b1101, 0b1110, 0b1111};
};


inline void RccDriver::disableClockSource(ClockSource clockSource)
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


inline void RccDriver::enablePeripheralClock(Apb1Peripheral peripheral)
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


inline void RccDriver::enablePeripheralClock(Apb2Peripheral peripheral)
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


inline void RccDriver::enablePeripheralClock(Ahb1Peripheral peripheral)
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


inline void RccDriver::enablePeripheralClock(Ahb2Peripheral peripheral)
{
  switch (peripheral) {
    case Ahb2Peripheral::Otgfs:
      rcc::ahb2enr::otgfsen::write(1);
      break;
    default:
      break;
  }
}

} // namespace

#endif /* RCC_DRIVER_H */
