#include "OsSystem.h"
#include "rcc/RccHal.h"
#include "pwr/PwrHal.h"
#include "flash/FlashHal.h"
#include "systick/SysTickHal.h"
#include "system/constants.h"


namespace stm32::system {

using namespace stm32::hal;

OsSystem::OsSystem(IRccHal& rccHal, IFlashHal& flashHal, IPwrHal& pwrHal, ISysTickHal& sysTickHal, IGpioDriver& gpioDriver)
  : System(rccHal, flashHal, pwrHal, sysTickHal)
  , m_gpioDriver(gpioDriver)
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

} // namespace
