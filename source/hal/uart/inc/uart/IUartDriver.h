#ifndef IUART_DRIVER_H
#define IUART_DRIVER_H

#include <cstdint>
#include "uart/types.h"

namespace stm32::hal {

class IUartDriver
{
public:
  virtual void write(const uint8_t* data, uint32_t size) = 0;
  virtual void read(uint8_t* buffer, uint32_t size) = 0;

  virtual void enable() = 0;
  virtual void disable() = 0;

  virtual void configure(UartConfiguration config) = 0;
  virtual void configureInterrupts(UartInterruptConfiguration config) = 0;
  virtual void configureDma(UartDmaConfiguration config) = 0;
};

} // namespace

#endif /* IUART_DRIVER_H */
