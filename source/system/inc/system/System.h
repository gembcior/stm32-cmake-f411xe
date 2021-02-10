#ifndef SYSTEM_H
#define SYSTEM_H

#include "system/ISystem.h"
#include "flash/FlashHal.h"
#include "rcc/IRccHal.h"
#include "pwr/PwrHal.h"
#include "gpio/GpioDriver.h"

namespace stm32::system {

namespace rcc   = stm32::hal::rcc;
namespace flash = stm32::hal::flash;
namespace pwr   = stm32::hal::pwr;
namespace gpio  = stm32::hal::gpio;


class System : public ISystem
{
public:
  System(rcc::IRccHal& rccHal, flash::IFlashHal& flashHal, pwr::IPwrHal& pwrHal, gpio::IGpioDriver& gpioDriver);
  void initialize() final;

private:
  void setupClock();
  void enablePeripherals();
  void setupGpio();

private:
  rcc::IRccHal& m_rccHal;
  flash::IFlashHal& m_flashHal;
  pwr::IPwrHal& m_pwrHal;
  gpio::IGpioDriver& m_gpioDriver;
};

} // namespace

#endif /* SYSTEM_H */
