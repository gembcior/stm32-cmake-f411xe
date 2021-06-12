#ifndef SYSTEM_H
#define SYSTEM_H

#include "flash/IFlashHal.h"
#include "rcc/IRccHal.h"
#include "pwr/IPwrHal.h"
#include "systick/ISysTickHal.h"

namespace stm32::system {


class System
{
public:
  System(hal::IRccHal& rccHal, hal::IFlashHal& flashHal, hal::IPwrHal& pwrHal, hal::ISysTickHal& sysTickHal);
  void initialize();

protected:
  virtual void setupClock();
  virtual void enableInterrupts();
  virtual void setupSysTick();
  virtual void enablePeripherals();
  virtual void setupGpio();

protected:
  hal::IRccHal& m_rccHal;
  hal::IFlashHal& m_flashHal;
  hal::IPwrHal& m_pwrHal;
  hal::ISysTickHal& m_sysTickHal;
};

} // namespace

#endif /* SYSTEM_H */
