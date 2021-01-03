#include <cstdint>
#include "main/main.h"
#include "scb/scb_driver.h"
#include "rcc/rcc_driver.h"
#include "pwr/pwr_driver.h"
#include "flash/flash_driver.h"
#include "stm32/f411xe/const/general.h"
#include "stm32/f4xx/const/general.h"
#include "stm32/f4xx/const/scb.h"
#include "gpio/GpioDriver.h"

namespace gpio = stm32::hal::gpio;
namespace rcc = stm32::hal::rcc;
namespace scb = stm32::hal::scb;
namespace flash = stm32::hal::flash;
namespace pwr = stm32::hal::pwr;

extern "C" void SystemInit(void)
{
  uint32_t* cpacr = (uint32_t*)stm32::constants::scb::cpacr::Address;
  uint32_t* vtor = (uint32_t*)stm32::constants::scb::vtor::Address;
  *cpacr |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
  *vtor = stm32::FlashBase; /* Vector Table Relocation in Internal FLASH */
}

int main(void)
{
//  static scb::ScbDriver scbDriver;
//  static rcc::RccDriver rccDriver;
//  static pwr::PwrDriver pwrDriver;
//  static flash::FlashDriver flashDriver;
//  static gpio::GpioDriver<gpio::PortA> gpioADriver;
//  static gpio::GpioDriver<gpio::PortC> gpioCDriver;
//
//  scbDriver.setCoprocessorAccessPrivileges(0b11);
//  scbDriver.setVectorTableOffset(stm32::FlashBase);
//  rccDriver.enableClockSource(rcc::ClockSource::Hse);
//  rccDriver.enablePeripheralClock(rcc::Apb1Peripheral::Pwr);
//  pwrDriver.setRegulatorVoltageScaling(pwr::RegulatorVoltageScaleMode::Mode1);
//  flashDriver.setLatency(3);
//  flashDriver.enableInstructionCache();
//  flashDriver.enableDataCache();
//  flashDriver.enablePrefetch();
//  rccDriver.setClockDomainPrescaler(rcc::ClockDomain::Ahb, rcc::ClockPrescaler::Div1);
//  rccDriver.setClockDomainPrescaler(rcc::ClockDomain::Apb1, rcc::ClockPrescaler::Div2);
//  rccDriver.setClockDomainPrescaler(rcc::ClockDomain::Apb2, rcc::ClockPrescaler::Div1);
//
//  // HSE = 8MHz -> PLLCLK = 100MHz
//  constexpr rcc::PllConfiguration pllConfig = {
//    .clockSource = rcc::PllClockSource::Hse,
//    .pllM = 4,    // Division factor:       4
//    .pllN = 100,  // Multiplication factor: 100
//    .pllP = 0,    // Division factor:       2
//    .pllQ = 4,    // Division factor:       4
//  };
//
//  rccDriver.configureMainPll(pllConfig);
//  rccDriver.enableClockSource(rcc::ClockSource::Pll);
//  rccDriver.setSystemClockSource(rcc::ClockSource::Pll);
//
//  constexpr gpio::PortConfig pa5Config = {
//    .mode = gpio::PortMode::Output,
//    .type = gpio::PortType::PushPull,
//    .speed = gpio::PortSpeed::Low,
//    .pull = gpio::PortPull::NoPull,
//  };
//
//  gpioADriver.configure(gpio::Pin5, pa5Config);
//
//  constexpr gpio::PortConfig pc13Config = {
//    .mode = gpio::PortMode::Input,
//    .type = gpio::PortType::PushPull,
//    .speed = gpio::PortSpeed::Low,
//    .pull = gpio::PortPull::PullUp,
//  };
//
//  gpioCDriver.configure(gpio::Pin13, pc13Config);

  while (1)
  {
//    if (gpioCDriver.getPin(gpio::Pin13) == gpio::PinState::Low) {
//      gpioADriver.setPin(gpio::Pin5, gpio::PinState::High);
//    } else {
//      gpioADriver.setPin(gpio::Pin5, gpio::PinState::Low);
//    }
  }
}
