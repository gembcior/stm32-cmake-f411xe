#include <cstdint>
#include "BlinkerSystem.h"
#include "objects.h"
#include "system/constants.h"
#include "uart/types.h"

#include "objects/objects.h"
#include "logger/Logger.h"
#include "flasher/Flasher.h"


using namespace stm32::objects;
using namespace stm32::system;
using namespace stm32::hal;
using namespace stm32::lib;


void writeUart(const char character)
{
  auto& uart = getObject<UartDriver>();
  uart.write(character);
}


int main(void)
{
  getIrqVectorTable();
  auto& system = getObject<System>();
  auto& flasher = getObject<Flasher>();
  auto& uart = getObject<UartDriver>();
  auto& logger = getObject<Logger>();
  auto& gpio = getObject<GpioDriver>();

  system.initialize();

  flasher.setPeriod(500);
  flasher.setPin(UserLed2.port, UserLed2.pin);

  UartConfiguration uartConfig = {
    .mode = UartMode::Tx,
    .baudRate = 115200,
    .dataLength = UartDataLength::Data8Bits,
    .parity = UartParity::Disable,
    .stopBits = UartStopBits::OneStopBit
  };

  uart.enable();
  uart.configure(uartConfig);

  logger.registerOutput(writeUart);
  logger.info("Blinker application started");

  bool buttonLock = false;

  while (1)
  {
    flasher.blink();

    if (gpio.getPin(UserButton) == PinState::Low && !buttonLock) {
      logger.info("User Button pushed");
      buttonLock = true;
    } else if (gpio.getPin(UserButton) == PinState::High && buttonLock) {
      logger.info("User Button released");
      buttonLock = false;
    }
  }
}
