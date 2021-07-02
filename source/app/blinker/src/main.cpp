#include <cstdint>
#include "BlinkerSystem.h"
#include "objects.h"
#include "system/constants.h"
#include "uart/types.h"


using namespace stm32::objects;
using namespace stm32::system;
using namespace stm32::hal;


void writeUart(const char character)
{
  auto& uart = getUartDriver();
  uart.write(character);
}


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

  auto& logger = getLogger();
  logger.registerOutput(writeUart);

  while (1)
  {
    flasher.blink();
    logger.info("Hello World! {}", 1236);
    logger.warning("{} {}!", "Hello", "World");
  }
}
