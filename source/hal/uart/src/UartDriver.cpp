#include "uart/UartDriver.h"


namespace stm32::hal {

UartDriver::UartDriver(IUartHal& uartHal, uint32_t clk) :
  m_uartHal(uartHal),
  m_clk(clk)
{
}


constexpr uint32_t UartDriver::getDiv(uint32_t baud)
{
  return (getDivMantissa(baud) << 4) + (getDivFraction(baud) & 0xF0) + (getDivFraction(baud) & 0x0F);
}


constexpr uint32_t UartDriver::getDivMantissa(uint32_t baud)
{
  return ((m_clk * 25) / (4 * baud)) / 100;
}


constexpr uint32_t UartDriver::getDivFraction(uint32_t baud)
{
  return  (((((m_clk * 25) / (4 * baud)) - (getDivMantissa(baud) * 100)) * 16) + 50) / 100;
}


void UartDriver::write(const uint8_t* data, uint32_t size)
{
  for (uint32_t i = 0; i < size; i++) {
    while (!m_uartHal.isTxEmpty());
    m_uartHal.writeData(data[i]);
  };
  while (!m_uartHal.isTxComplete());
}


void UartDriver::read(uint8_t* buffer, uint32_t size)
{
}


void UartDriver::enable()
{
  m_uartHal.enable();
}


void UartDriver::disable()
{
  m_uartHal.disable();
}


void UartDriver::configure(UartConfiguration config)
{
  m_uartHal.setDataLength(config.dataLength);
  m_uartHal.setParity(config.parity);
  m_uartHal.setStopBits(config.stopBits);

  uint32_t uartDiv = getDiv(config.baudRate);
  uint32_t mantissa = (uartDiv >> 4 ) & 0xFFF;
  uint32_t fraction = uartDiv & 0xF;
  m_uartHal.setBaudRate(mantissa, fraction);

  m_uartHal.setMode(config.mode);
}


void UartDriver::configureInterrupts(UartInterruptConfiguration config)
{
}


void UartDriver::configureDma(UartDmaConfiguration config)
{
}

}
