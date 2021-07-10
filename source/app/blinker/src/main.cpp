#include "FreeRTOS.h"
#include "task.h"

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


void blinkerTask(void *pvParameters)
{
  auto& flasher = getFlasher();
  flasher.setPeriod(500);
  flasher.setPin(UserLed2.port, UserLed2.pin);

  auto& logger = getLogger();
  logger.info("Blinker Task Started");

  while(1)
  {
    flasher.blink();
    vTaskDelay(1);
  }

  vTaskDelete( NULL );
}


void uartTask(void *pvParameters)
{
  auto& logger = getLogger();
  auto& gpio = getGpioDriver();

  logger.info("Uart Task Started");

  bool buttonLock = false;
  while(1)
  {
    if (gpio.getPin(UserButton) == PinState::Low && !buttonLock) {
      logger.info("User Button pushed");
      buttonLock = true;
    } else if (gpio.getPin(UserButton) == PinState::High && buttonLock) {
      logger.info("User Button released");
      buttonLock = false;
    }
    vTaskDelay(1);
  }

  vTaskDelete( NULL );
}


int main(void)
{
  auto& system = getSystem();
  system.initialize();

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

  logger.info("Blinker application started!");

  xTaskCreate(&blinkerTask, "blinkerTask", 1024, NULL, 4, NULL);
  xTaskCreate(&uartTask, "uartTask", 1024, NULL, 4, NULL);
  logger.info("Tasks created. Starting scheduler!");
  vTaskStartScheduler();

  while (1);
}
