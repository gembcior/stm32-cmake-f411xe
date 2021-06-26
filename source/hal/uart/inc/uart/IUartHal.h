#ifndef IUART_HAL_H
#define IUART_HAL_H

#include <cstdint>
#include "uart/types.h"

namespace stm32::hal {

class IUartHal
{
public:
  virtual bool isTxEmpty() = 0;
  virtual bool isTxComplete() = 0;
  virtual bool isRxNotEmpty() = 0;
  virtual bool isIdleLine() = 0;

  virtual void writeData(uint32_t data) = 0;
  virtual uint32_t readData() = 0;

  virtual void enable() = 0;
  virtual void disable() = 0;

  virtual void setMode(UartMode mode) = 0;
  virtual void setBaudRate(uint32_t mantissa, uint32_t fraction) = 0;
  virtual void setParity(UartParity mode) = 0;
  virtual void setStopBits(UartStopBits stopBits) = 0;
  virtual void setDataLength(UartDataLength dataLength) = 0;

  virtual void enableInterrupt(UartInterrupt interrupt) = 0;
  virtual void disableInterrupt(UartInterrupt interrupt) = 0;

  virtual void enableDma(UartDma dma) = 0;
  virtual void disableDma(UartDma dma) = 0;
};

} // namespace

#endif /* IUART_HAL_H */
