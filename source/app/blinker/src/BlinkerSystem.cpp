#include "BlinkerSystem.h"
#include "irq.h"

namespace stm32::system {

using namespace stm32::hal;
using namespace stm32::irq;

BlinkerSystem::BlinkerSystem(IScbHal& scbHal, IRccHal& rccHal, IFlashHal& flashHal, IPwrHal& pwrHal, ISysTickHal& sysTickHal, IGpioDriver& gpioDriver, IrqManager<MaxIrqNumber>& irqManager)
  : System(rccHal, flashHal, pwrHal, sysTickHal)
  , m_scbHal(scbHal)
  , m_gpioDriver(gpioDriver)
  , m_irqManager(irqManager)
{
}


void BlinkerSystem::enablePeripherals()
{
  m_rccHal.enablePeripheralClock(Ahb1Peripheral::Gpioc);
  m_rccHal.enablePeripheralClock(Ahb1Peripheral::Gpioa);
  m_rccHal.enablePeripheralClock(Apb1Peripheral::Usart2);
}


void BlinkerSystem::setupGpio()
{
  m_gpioDriver.configure(UserLed2);
  m_gpioDriver.configure(UserLed3);
  m_gpioDriver.configure(UserLed4);
  m_gpioDriver.configure(Uart2Tx);
  m_gpioDriver.configure(UserButton);
}


void BlinkerSystem::setupInterrupts()
{
  m_irqManager.registerIrqHandler(NmiIrq);
  m_irqManager.registerIrqHandler(HardFaultIrq);
  m_irqManager.registerIrqHandler(MemManageIrq);
  m_irqManager.registerIrqHandler(BusFaultIrq);
  m_irqManager.registerIrqHandler(UsageFaultIrq);
  m_irqManager.registerIrqHandler(SvcIrq);
  m_irqManager.registerIrqHandler(DebugMonIrq);
  m_irqManager.registerIrqHandler(PendSvIrq);
  m_irqManager.registerIrqHandler(SysTickIrq);
  m_scbHal.setVectorTableOffset(m_irqManager.getIrqVectorTableAddress());
}

} // namespace
