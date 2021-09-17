#ifndef OS_SYSTEM_H
#define OS_SYSTEM_H

#include "system/System.h"
#include "system/constants.h"
#include "scb/IScbHal.h"
#include "flash/IFlashHal.h"
#include "rcc/IRccHal.h"
#include "pwr/IPwrHal.h"
#include "gpio/IGpioDriver.h"
#include "systick/ISysTickHal.h"
#include "irq/IrqManager.h"
#include "irq.h"

namespace stm32::system {


class OsSystem : public System
{
public:
  OsSystem(
      hal::IScbHal& scbHal,
      hal::IRccHal& rccHal,
      hal::IFlashHal& flashHal,
      hal::IPwrHal& pwrHal,
      hal::ISysTickHal& sysTickHal,
      hal::IGpioDriver& gpioDriver,
      irq::IrqManager<irq::IrqNumber>& irqManager);

  void initialize();

private:
  void enablePeripherals() final;
  void setupGpio() final;
  void setupInterrupts() final;
  void setupSysTick() final;

private:
  hal::IScbHal& m_scbHal;
  hal::IGpioDriver& m_gpioDriver;
  irq::IrqManager<irq::IrqNumber>& m_irqManager;
};

} // namespace

#endif /* OS_SYSTEM_H */
