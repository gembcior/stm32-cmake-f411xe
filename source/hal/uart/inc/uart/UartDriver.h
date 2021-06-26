#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include "uart/IUartDriver.h"
#include "uart/IUartHal.h"
#include "uart/types.h"
#include <cstdint>

namespace stm32::hal {

class UartDriver : public IUartDriver
{
public:
  UartDriver(IUartHal& uartHal, uint32_t clk);

  void write(const uint8_t* data, uint32_t size) final;
  void read(uint8_t* buffer, uint32_t size) final;

  void enable() final;
  void disable() final;

  void configure(UartConfiguration config) final;
  void configureInterrupts(UartInterruptConfiguration config) final;
  void configureDma(UartDmaConfiguration config) final;

private:
  constexpr uint32_t getDiv(uint32_t baud);
  constexpr uint32_t getDivMantissa(uint32_t baud);
  constexpr uint32_t getDivFraction(uint32_t baud);

private:
  IUartHal& m_uartHal;
  uint32_t m_clk;
};

} // namespace

#endif /* UART_DRIVER_H */
