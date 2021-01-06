#include "rcc/RccDriver.h"
#include "stm32/f411xe/reg/rcc.h"


namespace stm32::hal::rcc {

namespace rcc = stm32::regs::rcc;

void RccDriver::enableClockSource(ClockSource clockSource)
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
  }

  rcc::cfgr::sw::write(sw);
  while (rcc::cfgr::sws::read() != sw);
}


// TODO try different approach
void RccDriver::setClockDomainPrescaler(ClockDomain clockDomain, ClockPrescaler clockPrescaler)
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


void RccDriver::configureMainPll(const PllConfiguration config)
{
  rcc::pllcfgr::pllsrc::write(static_cast<uint32_t>(config.clockSource));
  rcc::pllcfgr::pllp::write(config.pllP);
  rcc::pllcfgr::plln::write(config.pllN);
  rcc::pllcfgr::pllm::write(config.pllM);
  rcc::pllcfgr::pllq::write(config.pllQ);
}

}
