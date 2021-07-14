#ifndef OS_SYSTEM_H
#define OS_SYSTEM_H

#include "system/System.h"
#include "flash/IFlashHal.h"
#include "rcc/IRccHal.h"
#include "pwr/IPwrHal.h"
#include "gpio/IGpioDriver.h"
#include "systick/ISysTickHal.h"

namespace stm32::system {


class OsSystem : public System
{
public:
  OsSystem(
      hal::IRccHal& rccHal,
      hal::IFlashHal& flashHal,
      hal::IPwrHal& pwrHal,
      hal::ISysTickHal& sysTickHal,
      hal::IGpioDriver& gpioDriver);

  void initialize();

private:
  void enablePeripherals() final;
  void setupGpio() final;

private:
  hal::IGpioDriver& m_gpioDriver;
};

} // namespace

#endif /* OS_SYSTEM_H */
