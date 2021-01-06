#include <cstdint>
#include "main/main.h"
#include "scb/ScbDriver.h"
#include "rcc/RccDriver.h"
#include "pwr/PwrDriver.h"
#include "flash/FlashDriver.h"
#include "gpio/GpioDriver.h"

#include "stm32/f411xe/const/general.h"
#include "stm32/f4xx/const/general.h"
#include "stm32/f4xx/const/scb.h"
#include "stm32/f411xe/reg/rcc.h"


namespace gpio = stm32::hal::gpio;
namespace rcc = stm32::hal::rcc;
namespace scb = stm32::hal::scb;
namespace flash = stm32::hal::flash;
namespace pwr = stm32::hal::pwr;


 void init()
{
  rcc::RccDriver rccDriver;
  pwr::PwrDriver pwrDriver;
  flash::FlashDriver flashDriver;

  rccDriver.enablePeripheralClock(rcc::Apb1Peripheral::Pwr);
  pwrDriver.setRegulatorVoltageScaling(pwr::RegulatorVoltageScaleMode::Mode1);

  rccDriver.enableClockSource(rcc::ClockSource::Hse);

  // HSE = 8MHz -> PLLCLK = 96MHz
  constexpr rcc::PllConfiguration pllConfig = {
    .clockSource = rcc::PllClockSource::Hse,
    .pllM = 4,
    .pllN = 100,
    .pllP = 0,
    .pllQ = 4,
  };

  rccDriver.configureMainPll(pllConfig);
  rccDriver.enableClockSource(rcc::ClockSource::Pll);

  rccDriver.setClockDomainPrescaler(rcc::ClockDomain::Apb1, rcc::ClockPrescaler::Div16);
  rccDriver.setClockDomainPrescaler(rcc::ClockDomain::Apb2, rcc::ClockPrescaler::Div16);
  rccDriver.setClockDomainPrescaler(rcc::ClockDomain::Apb2, rcc::ClockPrescaler::Div1);

  flashDriver.setLatency(3);
  flashDriver.enableInstructionCache();
  flashDriver.enableDataCache();
  flashDriver.enablePrefetch();

  rccDriver.setSystemClockSource(rcc::ClockSource::Pll);

  rccDriver.setClockDomainPrescaler(rcc::ClockDomain::Ahb, rcc::ClockPrescaler::Div4);
  rccDriver.setClockDomainPrescaler(rcc::ClockDomain::Apb1, rcc::ClockPrescaler::Div2);

  rccDriver.disableClockSource(rcc::ClockSource::Hsi);
}


extern "C" void SystemInit(void)
{
  scb::ScbDriver scbDriver;
  scbDriver.setCoprocessorAccessPrivileges(0b11);
  scbDriver.setVectorTableOffset(stm32::FlashBase);
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

  static rcc::RccDriver rccDriver;
  static gpio::GpioDriver<gpio::PortC> gpioCDriver;

  rccDriver.enablePeripheralClock(rcc::Ahb1Peripheral::Gpioc);

  constexpr gpio::PortConfig ledConfig = {
    .mode = gpio::PortMode::Output,
    .type = gpio::PortType::PushPull,
    .speed = gpio::PortSpeed::Low,
    .pull = gpio::PortPull::NoPull,
  };

  gpioCDriver.configure(gpio::Pin5, ledConfig);
  gpioCDriver.configure(gpio::Pin8, ledConfig);

  constexpr gpio::PortConfig switchConfig = {
    .mode = gpio::PortMode::Input,
    .type = gpio::PortType::PushPull,
    .speed = gpio::PortSpeed::Low,
    .pull = gpio::PortPull::PullUp,
  };

  gpioCDriver.configure(gpio::Pin13, switchConfig);

  gpioCDriver.setPin(gpio::Pin8, gpio::PinState::High);

  bool ledState = true;
  while (1)
  {
    if (gpioCDriver.getPin(gpio::Pin13) == gpio::PinState::Low) {
      gpioCDriver.setPin(gpio::Pin5, gpio::PinState::High);
    } else {
      if (ledState) {
        ledState = false;
        gpioCDriver.setPin(gpio::Pin5, gpio::PinState::High);
      } else {
        ledState = true;
        gpioCDriver.setPin(gpio::Pin5, gpio::PinState::Low);
      }
      delay(1);
    }
  }
}
