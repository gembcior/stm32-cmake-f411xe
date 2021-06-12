#include "system/System.h"
#include "rcc/RccHal.h"
#include "pwr/PwrHal.h"
#include "flash/FlashHal.h"
#include "system/constants.h"
#include "systick/SysTickHal.h"


namespace stm32::system {

using namespace stm32::hal;

System::System(IRccHal& rccHal, IFlashHal& flashHal, IPwrHal& pwrHal, ISysTickHal& sysTickHal)
  : m_rccHal(rccHal)
  , m_flashHal(flashHal)
  , m_pwrHal(pwrHal)
  , m_sysTickHal(sysTickHal)
{
}


void System::initialize()
{
  setupClock();
  setupSysTick();
  enablePeripherals();
  setupGpio();
  enableInterrupts();
}


void System::setupClock()
{
  m_rccHal.enablePeripheralClock(Apb1Peripheral::Pwr);
  m_pwrHal.setRegulatorVoltageScaling(RegulatorVoltageScaleMode::Mode1);

  m_rccHal.enableClockSource(ClockSource::Hse);

  // HSE = 8MHz -> PLLCLK = 96MHz
  // PLLCLK = (HSE * (pllN / pllM)) / pllP = (8MHz * (96 / 4)) / 2 = 96MHz
  constexpr PllConfiguration pllConfig = {
    .clockSource = PllClockSource::Hse,
    .pllM = 4,
    .pllN = 96,
    .pllP = 0,
    .pllQ = 4,
  };

  m_rccHal.configureMainPll(pllConfig);
  m_rccHal.enableClockSource(ClockSource::Pll);

  m_rccHal.setClockDomainPrescaler(ClockDomain::Apb1, ClockPrescaler::Div16);
  m_rccHal.setClockDomainPrescaler(ClockDomain::Apb2, ClockPrescaler::Div16);

  m_flashHal.setLatency(3);

  m_flashHal.enableInstructionCache();
  m_flashHal.enableDataCache();
  m_flashHal.enablePrefetch();

  m_rccHal.setSystemClockSource(ClockSource::Pll);

  m_rccHal.setClockDomainPrescaler(ClockDomain::Ahb, ClockPrescaler::Div1);
  m_rccHal.setClockDomainPrescaler(ClockDomain::Apb1, ClockPrescaler::Div2);
  m_rccHal.setClockDomainPrescaler(ClockDomain::Apb2, ClockPrescaler::Div1);

  m_rccHal.disableClockSource(ClockSource::Hsi);
}


void System::enableInterrupts()
{
  __asm volatile ("cpsie i");
}


void System::setupSysTick()
{
  m_sysTickHal.setClockSource(SysTickClockSource::AhbDiv8);
  constexpr uint32_t reloadValue = SystemClock / (8 * SysTickClock);
  m_sysTickHal.setReloadValue(reloadValue);
  m_sysTickHal.clear();
  m_sysTickHal.enableInterrupts();
  m_sysTickHal.enable();
}


void System::enablePeripherals()
{
}


void System::setupGpio()
{
}

} // namespace
