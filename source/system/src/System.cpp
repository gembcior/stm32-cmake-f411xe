#include "system/System.h"
#include "rcc/RccHal.h"
#include "pwr/PwrHal.h"
#include "flash/FlashHal.h"
#include "system/constants.h"


namespace stm32::system {

System::System(rcc::IRccHal& rccHal, flash::IFlashHal& flashHal, pwr::IPwrHal& pwrHal, gpio::IGpioDriver& gpioDriver)
  : m_rccHal(rccHal)
  , m_flashHal(flashHal)
  , m_pwrHal(pwrHal)
  , m_gpioDriver(gpioDriver)
{
}


void System::initialize()
{
  setupClock();
  enablePeripherals();
  setupGpio();
}


void System::setupClock()
{
  m_rccHal.enablePeripheralClock(rcc::Apb1Peripheral::Pwr);
  m_pwrHal.setRegulatorVoltageScaling(pwr::RegulatorVoltageScaleMode::Mode1);

  m_rccHal.enableClockSource(rcc::ClockSource::Hse);

  // HSE = 8MHz -> PLLCLK = 96MHz
  constexpr rcc::PllConfiguration pllConfig = {
    .clockSource = rcc::PllClockSource::Hse,
    .pllM = 4,
    .pllN = 96,
    .pllP = 0,
    .pllQ = 4,
  };

  m_rccHal.configureMainPll(pllConfig);
  m_rccHal.enableClockSource(rcc::ClockSource::Pll);

  m_rccHal.setClockDomainPrescaler(rcc::ClockDomain::Apb1, rcc::ClockPrescaler::Div16);
  m_rccHal.setClockDomainPrescaler(rcc::ClockDomain::Apb2, rcc::ClockPrescaler::Div16);
  m_rccHal.setClockDomainPrescaler(rcc::ClockDomain::Apb2, rcc::ClockPrescaler::Div1);

  m_flashHal.setLatency(3);

  m_flashHal.enableInstructionCache();
  m_flashHal.enableDataCache();
  m_flashHal.enablePrefetch();

  m_rccHal.setSystemClockSource(rcc::ClockSource::Pll);

  m_rccHal.setClockDomainPrescaler(rcc::ClockDomain::Ahb, rcc::ClockPrescaler::Div4);
  m_rccHal.setClockDomainPrescaler(rcc::ClockDomain::Apb1, rcc::ClockPrescaler::Div2);

  m_rccHal.disableClockSource(rcc::ClockSource::Hsi);
}


void System::enablePeripherals()
{
  m_rccHal.enablePeripheralClock(rcc::Ahb1Peripheral::Gpioc);
}


void System::setupGpio()
{
  m_gpioDriver.configure(UserLed2);
  m_gpioDriver.configure(UserLed3);
  m_gpioDriver.configure(UserLed4);
}

} // namespace
