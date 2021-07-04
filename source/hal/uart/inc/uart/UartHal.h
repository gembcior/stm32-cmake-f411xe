#ifndef UART_HAL_H
#define UART_HAL_H

#include "uart/IUartHal.h"
#include "dral/usart1.h"
#include "dral/usart2.h"
#include "dral/usart6.h"

namespace stm32::hal {

using UART1 = dral::stm32f411::usart1;
using UART2 = dral::stm32f411::usart2;
using UART6 = dral::stm32f411::usart6;


template<typename Uart>
class UartHal : public IUartHal
{
public:
  bool isTxEmpty() final;
  bool isTxComplete() final;
  bool isRxNotEmpty() final;
  bool isIdleLine() final;

  void writeData(uint32_t data) final;
  uint32_t readData() final;

  void enable() final;
  void disable() final;

  void setMode(UartMode mode) final;
  void setBaudRate(uint32_t mantissa, uint32_t fraction) final;
  void setParity(UartParity parity) final;
  void setStopBits(UartStopBits stopBits) final;
  void setDataLength(UartDataLength dataLength) final;

  void enableInterrupt(UartInterrupt interrupt) final;
  void disableInterrupt(UartInterrupt interrupt) final;

  void enableDma(UartDma dma) final;
  void disableDma(UartDma dma) final;
};


template<typename Uart>
bool UartHal<Uart>::isTxEmpty()
{
  return Uart::sr::txe::read();
}


template<typename Uart>
bool UartHal<Uart>::isTxComplete()
{
  return Uart::sr::tc::read();
}


template<typename Uart>
bool UartHal<Uart>::isRxNotEmpty()
{
  return Uart::sr::rxne::read();
}


template<typename Uart>
bool UartHal<Uart>::isIdleLine()
{
  return Uart::sr::idle::read();
}


template<typename Uart>
void UartHal<Uart>::writeData(uint32_t data)
{
  Uart::dr::dr::write(data);
}


template<typename Uart>
uint32_t UartHal<Uart>::readData()
{
  return Uart::dr::dr::read();
}


template<typename Uart>
void UartHal<Uart>::enable()
{
  Uart::cr1::ue::write(1);
}


template<typename Uart>
void UartHal<Uart>::disable()
{
  Uart::cr1::ue::write(0);
}


template<typename Uart>
void UartHal<Uart>::setMode(UartMode mode)
{
  switch (mode) {
    case UartMode::Tx:
      Uart::cr1::te::write(1);
      Uart::cr1::re::write(0);
      break;
    case UartMode::Rx:
      Uart::cr1::te::write(0);
      Uart::cr1::re::write(1);
      break;
    case UartMode::TxRx:
      Uart::cr1::te::write(1);
      Uart::cr1::re::write(1);
      break;
  }
}


template<typename Uart>
void UartHal<Uart>::setBaudRate(uint32_t mantissa, uint32_t fraction)
{
  Uart::brr::div_fraction::write(fraction);
  Uart::brr::div_mantissa::write(mantissa);
}


template<typename Uart>
void UartHal<Uart>::setParity(UartParity parity)
{
  switch (parity) {
    case UartParity::Disable:
      Uart::cr1::pce::write(0);
      break;
    case UartParity::EvenParity:
      Uart::cr1::pce::write(1);
      Uart::cr1::ps::write(0);
      break;
    case UartParity::OddParity:
      Uart::cr1::pce::write(1);
      Uart::cr1::ps::write(1);
      break;
  }
}


template<typename Uart>
void UartHal<Uart>::setStopBits(UartStopBits stopBits)
{
  switch (stopBits) {
    case UartStopBits::HalfStopBit:
      Uart::cr2::stop::write(0b01);
      break;
    case UartStopBits::OneStopBit:
      Uart::cr2::stop::write(0b00);
      break;
    case UartStopBits::TwoStopBits:
      Uart::cr2::stop::write(0b10);
      break;
  }
}


template<typename Uart>
void UartHal<Uart>::setDataLength(UartDataLength dataLength)
{
  switch (dataLength) {
    case UartDataLength::Data8Bits:
      Uart::cr1::m::write(0);
      break;
    case UartDataLength::Data9Bits:
      Uart::cr1::m::write(1);
      break;
  }
}


template<typename Uart>
void UartHal<Uart>::enableInterrupt(UartInterrupt interrupt)
{
  switch (interrupt) {
    case UartInterrupt::ParityErrorIrq:
      Uart::cr1::peie::write(1);
      break;
    case UartInterrupt::TxDataEmptyIrq:
      Uart::cr1::txeie::write(1);
      break;
    case UartInterrupt::TxCompleteIrq:
      Uart::cr1::tcie::write(1);
      break;
    case UartInterrupt::RxNotEmptyIrq:
      Uart::cr1::rxneie::write(1);
      break;
    case UartInterrupt::IdleLineIrq:
      Uart::cr1::idleie::write(1);
      break;
  }
}


template<typename Uart>
void UartHal<Uart>::disableInterrupt(UartInterrupt interrupt)
{
  switch (interrupt) {
    case UartInterrupt::ParityErrorIrq:
      Uart::cr1::peie::write(0);
      break;
    case UartInterrupt::TxDataEmptyIrq:
      Uart::cr1::txeie::write(0);
      break;
    case UartInterrupt::TxCompleteIrq:
      Uart::cr1::tcie::write(0);
      break;
    case UartInterrupt::RxNotEmptyIrq:
      Uart::cr1::rxneie::write(0);
      break;
    case UartInterrupt::IdleLineIrq:
      Uart::cr1::idleie::write(0);
      break;
  }
}


template<typename Uart>
void UartHal<Uart>::enableDma(UartDma dma)
{
  switch (dma) {
    case UartDma::Tx:
      Uart::cr3::dmat::write(1);
      break;
    case UartDma::Rx:
      Uart::cr3::dmar::write(1);
      break;
    case UartDma::TxRx:
      Uart::cr3::dmat::write(1);
      Uart::cr3::dmar::write(1);
      break;
  }
}


template<typename Uart>
void UartHal<Uart>::disableDma(UartDma dma)
{
  switch (dma) {
    case UartDma::Tx:
      Uart::cr3::dmat::write(0);
      break;
    case UartDma::Rx:
      Uart::cr3::dmar::write(0);
      break;
    case UartDma::TxRx:
      Uart::cr3::dmat::write(0);
      Uart::cr3::dmar::write(0);
      break;
  }
}

} // namespace

#endif /* UART_HAL_H */
