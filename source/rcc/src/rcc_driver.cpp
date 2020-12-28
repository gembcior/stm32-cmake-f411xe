#include "rcc/rcc_driver.h"
#include "stm32/f411xe/reg/rcc.h"

namespace stm32::hal {

void RccDriver::enableClockSource(ClockSource clockSource)
{
  switch (clockSource) {
    case ClockSource::HSI:
      rcc::cr::hsion::write(1);
      while(rcc::cr::hsirdy::read() != 1)
      break;
    case ClockSource::HSE:
      rcc::cr::hseon::write(1);
      while(rcc::cr::hserdy::read() != 1)
      break;
    case ClockSource::PLL:
      rcc::cr::pllon::write(1);
      while(rcc::cr::pllrdy::read() != 1)
      break;
    case ClockSource::PLLI2S:
      rcc::cr::plli2son::write(1);
      while(rcc::cr::plli2srdy::read() != 1)
      break;
    default:
      break;
  };
}


void RccDriver::disableClockSource(ClockSource clockSource)
{
  switch (clockSource) {
    case ClockSource::HSI:
      rcc::cr::hsion::write(0);
      break;
    case ClockSource::HSE:
      rcc::cr::hseon::write(0);
      break;
    case ClockSource::PLL:
      rcc::cr::pllon::write(0);
      break;
    case ClockSource::PLLI2S:
      rcc::cr::plli2son::write(0);
      break;
    default:
      break;
  };
}


void RccDriver::setSystemClockSource(ClockSource clockSource)
{
  uint32_t sw = 0;

  switch (clockSource) {
    case ClockSource::HSI:
      sw = 0;
      break;
    case ClockSource::HSE:
      sw = 1;
      break;
    case ClockSource::PLL:
      sw = 2;
      break;
    default:
      break;
  };

  rcc::cfgr::sw::write(sw);
  while (rcc::cfgr::sws::read() != sw);
}


void RccDriver::setClockDomainPrescaler(ClockDomain clockDomain, ClockPrescaler clockPrescaler)
{
}


void RccDriver::configureMainPll(const PllConfiguration config)
{
}

void RccDriver::enablePeripheralClock(Apb1Peripheral peripheral)
{
}


void RccDriver::enablePeripheralClock(Apb2Peripheral peripheral)
{
}


void RccDriver::enablePeripheralClock(Ahb1Peripheral peripheral)
{
}


void RccDriver::enablePeripheralClock(Ahb2Peripheral peripheral)
{
}

}
