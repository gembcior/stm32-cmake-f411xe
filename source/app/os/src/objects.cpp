#include "objects.h"
#include "objects/objects.h"

#include "OsSystem.h"

#include "scb/ScbHal.h"
#include "rcc/RccHal.h"
#include "flash/FlashHal.h"
#include "pwr/PwrHal.h"
#include "gpio/GpioDriver.h"
#include "systick/SysTickHal.h"
#include <array>
#include "irq/IrqAdapterTable.h"
#include "irq.h"
#include "os/Mutex.h"

namespace stm32::objects {

using namespace stm32::hal;
using namespace stm32::irq;
using namespace stm32::system;


template<>
system::System& getObject<system::System>()
{
  static system::OsSystem system(
      getObject<ScbHal>(),
      getObject<RccHal>(),
      getObject<FlashHal>(),
      getObject<PwrHal>(),
      getObject<SysTickHal>(),
      getObject<GpioDriver>(),
      getObject<IrqManager<IrqNumber>>()
  );

  return system;
}


const IrqAdapterPointer* getIrqVectorTable()
{
  __attribute__ (( section (".irq_vector_table")))
  static const std::array<IrqAdapterPointer, IrqNumber> IrqVectorTable = IrqAdapterTable<IrqNumber>::Table;

  return reinterpret_cast<IrqAdapterPointer const*>(IrqVectorTable.data());
}


template<>
IrqManager<IrqNumber>& getObject<IrqManager<IrqNumber>>()
{
  static IrqManager<IrqNumber> irqManager(getObject<NvicHal>());
  return irqManager;
}

template<>
lib::OsLogger& getObject<lib::OsLogger>()
{
  static os::Mutex mutex;
  static lib::OsLogger logger(mutex);

  return logger;
}


} // namespace
