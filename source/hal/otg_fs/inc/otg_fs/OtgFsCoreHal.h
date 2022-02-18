#ifndef OTG_FS_CORE_HAL_H
#define OTG_FS_CORE_HAL_H

#include "otg_fs/IOtgFsCoreHal.h"
#include "types.h"

namespace stm32::hal {

class OtgFsCoreHal : public IOtgFsCoreHal
{
public:


public:
  void init() override;
  void reset() final;
  void selectPhy(OtgFsPhy phy);

  void setCurrentMode(OtgFsMode mode);
  void setHnpCapability(bool hnp);
  void setSrpCapability(bool srp);
  void setFsTimeout(uint8_t fs);
  void setTurnaroundTime(uint8_t hclk);
  void disableVBusSensing();
  void enableVBusSensing();

  void enableGlobalInterrupts() final;
  void disableGlobalInterrupts() final;
  void resetPhyClk() final;
  void activateTransceiver() final;
  void deactivateTransceiver() final;
  // TODO replace bool with enum for mask and unmask
  void setInterruptMask(OtgFsInterruptMask interrupt, bool mask) final;

  void flushTxFifo(uint32_t fifoNumber);
  void flushRxFifo();

  void clearInterrupt(OtgFsInterrupt interrupt) final;
  void clearOtgInterrupt(OtgFsOtgInterrupt interrupt);
  uint32_t getInterruptStatus();
  bool getInterruptStatus(OtgFsInterrupt interrupt);
  bool getInterruptStatus(uint32_t status, OtgFsInterrupt interrupt);
};

} // namespace

#endif /* OTG_FS_CORE_HAL_H */
