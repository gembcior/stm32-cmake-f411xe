#include "objects.h"
#include "objects/objects.h"

#include "BlinkerSystem.h"

#include "scb/ScbHal.h"
#include "rcc/RccHal.h"
#include "flash/FlashHal.h"
#include "pwr/PwrHal.h"
#include "gpio/GpioDriver.h"
#include "systick/SysTickHal.h"



namespace stm32::objects {

using namespace stm32::hal;
using namespace stm32::irq;
using namespace stm32::system;


template<>
system::System& getObject<system::System>()
{
  static system::BlinkerSystem system(
      getObject<ScbHal>(),
      getObject<RccHal>(),
      getObject<FlashHal>(),
      getObject<PwrHal>(),
      getObject<SysTickHal>(),
      getObject<GpioDriver>(),
      getObject<IrqManager<MaxIrqNumber>>()
  );

  return system;
}

} // namespace
