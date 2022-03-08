#ifndef OTG_FS_CORE_HAL_H
#define OTG_FS_CORE_HAL_H

#include "types.h"
#include "dral/otg_fs_global.h"

namespace stm32::hal {

class OtgFsCoreHal
{
public:
  void init();
  void reset();
  void resetPhyClk();
  void selectPhy(OtgFsPhy phy);

  void setCurrentMode(OtgFsMode mode);
  void setFsTimeout(uint8_t fs);
  void setTurnaroundTime(uint32_t hclk);

  void disableVBusSensing();
  void enableVBusSensing();

  void enableGlobalInterrupts();
  void disableGlobalInterrupts();

  void activateTransceiver();
  void deactivateTransceiver();

  void flushTxFifo(uint32_t fifoNumber);
  void flushRxFifo();

  void setInterruptMask(OtgFsInterrupt interrupt, OtgFsInterruptMask mask);
  void clearInterrupt(OtgFsInterrupt interrupt);
  uint32_t getInterruptStatus();
  bool getInterruptStatus(OtgFsInterrupt interrupt);
  bool getInterruptStatus(uint32_t status, OtgFsInterrupt interrupt);

  void readFifoPacket(uint8_t* const buffer, uint32_t byteCount);
  void writeFifoPacket(uint32_t fifoNumber, const uint8_t* buffer, uint32_t byteCount);

public:
  static constexpr uint32_t getRxFifoSize(uint32_t endpointSize)
  {
    return 15 + (2 * (endpointSize / 4)) + (2 * MaxEndpoints);
  }

  static constexpr uint32_t getFifoAddress(uint32_t fifoNumber)
  {
    constexpr uint32_t base = dral::stm32f411::otg_fs_global::BaseAddress + 0x1000U;
    constexpr uint32_t fifoSize = 0x1000U;
    return base + (fifoNumber * fifoSize);
  }
};

} // namespace

#endif /* OTG_FS_CORE_HAL_H */
