#include <cstdint>
#include "main/main.h"
#include "rcc/RccHal.h"
#include "pwr/PwrHal.h"
#include "flash/FlashHal.h"
#include "gpio/GpioHal.h"

namespace gpio = stm32::hal::gpio;
namespace rcc = stm32::hal::rcc;
namespace flash = stm32::hal::flash;
namespace pwr = stm32::hal::pwr;


 void init()
{
  rcc::RccHal rccHal;
  pwr::PwrHal pwrHal;
  flash::FlashHal flashHal;

  rccHal.enablePeripheralClock(rcc::Apb1Peripheral::Pwr);
  pwrHal.setRegulatorVoltageScaling(pwr::RegulatorVoltageScaleMode::Mode1);

  rccHal.enableClockSource(rcc::ClockSource::Hse);

  // HSE = 8MHz -> PLLCLK = 96MHz
  constexpr rcc::PllConfiguration pllConfig = {
    .clockSource = rcc::PllClockSource::Hse,
    .pllM = 4,
    .pllN = 100,
    .pllP = 0,
    .pllQ = 4,
  };

  rccHal.configureMainPll(pllConfig);
  rccHal.enableClockSource(rcc::ClockSource::Pll);

  rccHal.setClockDomainPrescaler(rcc::ClockDomain::Apb1, rcc::ClockPrescaler::Div16);
  rccHal.setClockDomainPrescaler(rcc::ClockDomain::Apb2, rcc::ClockPrescaler::Div16);
  rccHal.setClockDomainPrescaler(rcc::ClockDomain::Apb2, rcc::ClockPrescaler::Div1);

  flashHal.setLatency(3);

  flashHal.enableInstructionCache();
  flashHal.enableDataCache();
  flashHal.enablePrefetch();

  rccHal.setSystemClockSource(rcc::ClockSource::Pll);

  rccHal.setClockDomainPrescaler(rcc::ClockDomain::Ahb, rcc::ClockPrescaler::Div4);
  rccHal.setClockDomainPrescaler(rcc::ClockDomain::Apb1, rcc::ClockPrescaler::Div2);

  rccHal.disableClockSource(rcc::ClockSource::Hsi);
}


void delay(uint32_t delay)
{
  for (volatile uint32_t i = 0; i < 100000; i++) {
    for (volatile uint32_t j = 0; j < delay; j++) {
    }
  }
}


int main(void)
{
  init();

  static rcc::RccHal rccHal;
  static gpio::GpioHal<gpio::PortC> gpioCHal;

  rccHal.enablePeripheralClock(rcc::Ahb1Peripheral::Gpioc);

  constexpr gpio::PortConfig ledConfig = {
    .mode = gpio::PortMode::Output,
    .type = gpio::PortType::PushPull,
    .speed = gpio::PortSpeed::Low,
    .pull = gpio::PortPull::NoPull,
  };

  gpioCHal.configure(gpio::Pin5, ledConfig);
  gpioCHal.configure(gpio::Pin8, ledConfig);

  constexpr gpio::PortConfig switchConfig = {
    .mode = gpio::PortMode::Input,
    .type = gpio::PortType::PushPull,
    .speed = gpio::PortSpeed::Low,
    .pull = gpio::PortPull::PullUp,
  };

  gpioCHal.configure(gpio::Pin13, switchConfig);

  gpioCHal.setPin(gpio::Pin8, gpio::PinState::High);

  bool ledState = true;
  while (1)
  {
    if (gpioCHal.getPin(gpio::Pin13) == gpio::PinState::Low) {
      gpioCHal.setPin(gpio::Pin5, gpio::PinState::High);
    } else {
      if (ledState) {
        ledState = false;
        gpioCHal.setPin(gpio::Pin5, gpio::PinState::High);
      } else {
        ledState = true;
        gpioCHal.setPin(gpio::Pin5, gpio::PinState::Low);
      }
      delay(1);
    }
  }
}
