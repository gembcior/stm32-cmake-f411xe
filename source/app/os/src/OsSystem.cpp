#include "OsSystem.h"
#include "rcc/RccHal.h"
#include "pwr/PwrHal.h"
#include "flash/FlashHal.h"
#include "systick/SysTickHal.h"
#include "system/constants.h"
#include "irq/IrqManager.h"
#include "irq.h"


namespace stm32::system {

using namespace stm32::hal;
using namespace stm32::irq;


OsSystem::OsSystem(IScbHal& scbHal, IRccHal& rccHal, IFlashHal& flashHal, IPwrHal& pwrHal, ISysTickHal& sysTickHal, IGpioDriver& gpioDriver, IrqManager<IrqNumber>& irqManager)
  : System(rccHal, flashHal, pwrHal, sysTickHal)
  , m_scbHal(scbHal)
  , m_gpioDriver(gpioDriver)
  , m_irqManager(irqManager)
{
}


void OsSystem::enablePeripherals()
{
  m_rccHal.enablePeripheralClock(Ahb1Peripheral::Gpioc);
  m_rccHal.enablePeripheralClock(Ahb1Peripheral::Gpioa);
  m_rccHal.enablePeripheralClock(Apb1Peripheral::Usart2);
}


void OsSystem::setupGpio()
{
  m_gpioDriver.configure(UserLed2);
  m_gpioDriver.configure(UserLed3);
  m_gpioDriver.configure(UserLed4);
  m_gpioDriver.configure(Uart2Tx);
  m_gpioDriver.configure(UserButton);
}


void OsSystem::setupInterrupts()
{
  m_irqManager.registerIrqHandler(NmiIrq);
  m_irqManager.registerIrqHandler(HardFaultIrq);
  m_irqManager.registerIrqHandler(MemManageIrq);
  m_irqManager.registerIrqHandler(BusFaultIrq);
  m_irqManager.registerIrqHandler(UsageFaultIrq);
  m_irqManager.registerIrqHandler(DebugMonIrq);
}


void OsSystem::setupSysTick()
{
  // Allow RTOS to setup SysTick
}

} // namespace
