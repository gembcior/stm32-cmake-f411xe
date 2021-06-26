#include <cstdint>
#include "BlinkerSystem.h"
#include "objects.h"
#include "system/constants.h"
#include "uart/types.h"


using namespace stm32::objects;
using namespace stm32::system;
using namespace stm32::hal;


int main(void)
{
  auto& system = getSystem();
  system.initialize();

  auto& flasher = getFlasher();
  flasher.setPeriod(500);
  flasher.setPin(UserLed2.port, UserLed2.pin);

  auto& uart = getUartDriver();

  UartConfiguration uartConfig = {
    .mode = UartMode::Tx,
    .baudRate = 115200,
    .dataLength = UartDataLength::Data8Bits,
    .parity = UartParity::Disable,
    .stopBits = UartStopBits::OneStopBit
  };

  uart.enable();
  uart.configure(uartConfig);

  while (1)
  {
    flasher.blink();
    const char hello[] = "HelloWorld!\n\r";
    uart.write(reinterpret_cast<const uint8_t*>(hello), 13);
  }
}
