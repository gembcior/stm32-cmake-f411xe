#ifndef UART_TYPES_H
#define UART_TYPES_H

#include <cstdint>

namespace stm32::hal {

  enum class UartMode {
    Tx,
    Rx,
    TxRx,
  };

  enum class UartDataLength {
    Data8Bits,
    Data9Bits,
  };


  enum class UartParity {
    Disable,
    EvenParity,
    OddParity,
  };


  enum class UartStopBits {
    OneStopBit,
    HalfStopBit,
    TwoStopBits,
  };


  enum class UartInterrupt {
    ParityErrorIrq,
    TxDataEmptyIrq,
    TxCompleteIrq,
    RxNotEmptyIrq,
    IdleLineIrq,
  };


  enum class UartDma {
    Tx,
    Rx,
    TxRx,
  };


  struct UartConfiguration {
    UartMode mode;
    uint32_t baudRate;
    UartDataLength dataLength;
    UartParity parity;
    UartStopBits stopBits;
  };


  struct UartInterruptConfiguration {
    UartInterruptConfiguration() :
      enableParityErrorIrq(false),
      enableTxDataEmpytIrq(false),
      enableTxCompleteIrq(false),
      enableRxNotEmpytIrq(false),
      enableIdleLineIrq(false)
    {}

    bool enableParityErrorIrq;
    bool enableTxDataEmpytIrq;
    bool enableTxCompleteIrq;
    bool enableRxNotEmpytIrq;
    bool enableIdleLineIrq;
  };


  struct UartDmaConfiguration {
    UartDmaConfiguration() :
      enableDmaTx(false),
      enableDmaRx(false)
    {}

    bool enableDmaTx;
    bool enableDmaRx;
  };


  struct UartDataDescriptor {
    uint32_t* data;
    uint32_t size;
  };
}

#endif /* UART_TYPES_H */
