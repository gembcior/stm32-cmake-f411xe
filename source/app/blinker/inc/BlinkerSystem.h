#ifndef BLINKER_SYSTEM_H
#define BLINKER_SYSTEM_H

#include "system/System.h"
#include "system/constants.h"
#include "scb/IScbHal.h"
#include "flash/IFlashHal.h"
#include "rcc/IRccHal.h"
#include "pwr/IPwrHal.h"
#include "gpio/IGpioDriver.h"
#include "systick/ISysTickHal.h"
#include "irq/IrqManager.h"


namespace stm32::system {

class BlinkerSystem : public System
{
public:
  BlinkerSystem(
      hal::IScbHal& scbHal,
      hal::IRccHal& rccHal,
      hal::IFlashHal& flashHal,
      hal::IPwrHal& pwrHal,
      hal::ISysTickHal& sysTickHal,
      hal::IGpioDriver& gpioDriver,
      irq::IrqManager<MaxIrqNumber>& irqManager);

  void initialize();

private:
  void enablePeripherals() final;
  void setupGpio() final;
  void setupInterrupts() final;

private:
  hal::IScbHal& m_scbHal;
  hal::IGpioDriver& m_gpioDriver;
  irq::IrqManager<MaxIrqNumber>& m_irqManager;
};

} // namespace

#endif /* BLINKER_SYSTEM_H */
