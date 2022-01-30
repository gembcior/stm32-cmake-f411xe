#include "UsbSystem.h"
#include "irq.h"

namespace stm32::system {

using namespace stm32::hal;
using namespace stm32::irq;

UsbSystem::UsbSystem(IScbHal& scbHal, IRccHal& rccHal, IFlashHal& flashHal, IPwrHal& pwrHal, ISysTickHal& sysTickHal, IGpioDriver& gpioDriver, IrqManager<IrqNumber>& irqManager)
  : System(rccHal, flashHal, pwrHal, sysTickHal)
  , m_scbHal(scbHal)
  , m_gpioDriver(gpioDriver)
  , m_irqManager(irqManager)
{
}


void UsbSystem::enablePeripherals()
{
  m_rccHal.enablePeripheralClock(Ahb1Peripheral::Gpioc);
  m_rccHal.enablePeripheralClock(Ahb1Peripheral::Gpioa);
  m_rccHal.enablePeripheralClock(Apb1Peripheral::Usart2);
  m_rccHal.enablePeripheralClock(Ahb2Peripheral::Otgfs);
}


void UsbSystem::setupGpio()
{
  m_gpioDriver.configure(UserLed2);
  m_gpioDriver.configure(UserLed3);
  m_gpioDriver.configure(UserLed4);
  m_gpioDriver.configure(Uart2Tx);
  m_gpioDriver.configure(UserButton);
  m_gpioDriver.configure(UsbOtgFsDm);
  m_gpioDriver.configure(UsbOtgFsDp);
}


void UsbSystem::setupInterrupts()
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
  m_irqManager.registerIrqHandler(OtgFsIrq);
  m_irqManager.enableIrq(OtgFsIrq);
  m_irqManager.setIrqPriority(OtgFsIrq);
}

} // namespace
