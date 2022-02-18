#ifndef IOTG_FS_CORE_HAL_H
#define IOTG_FS_CORE_HAL_H

#include <cstdint>
#include <otg_fs/types.h>

namespace stm32::hal {

class IOtgFsCoreHal
{
public:
  virtual void init() = 0;
  virtual void reset() = 0;
  virtual void enableGlobalInterrupts() = 0;
  virtual void disableGlobalInterrupts() = 0;
  virtual void resetPhyClk() = 0;
  virtual void clearInterrupt(OtgFsInterrupt interrupt) = 0;
  virtual void activateTransceiver() = 0;
  virtual void deactivateTransceiver() = 0;
  virtual void setInterruptMask(OtgFsInterruptMask interrupt, bool mask) = 0;

};

} // namespace

#endif /* IOTG_FS_CORE_HAL_H */
