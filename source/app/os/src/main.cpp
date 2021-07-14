#include "FreeRTOS.h"
#include "task.h"

#include <cstdint>
#include "objects.h"
#include "system/constants.h"
#include "uart/types.h"

#include "os/StaticTask.h"
#include "os/Scheduler.h"

using namespace stm32::objects;
using namespace stm32::system;
using namespace stm32::hal;


void writeUart(const char character)
{
  auto& uart = getUartDriver();
  uart.write(character);
}


constexpr uint32_t blinkerTaskStackSize = 1024;
StackType_t blinkerTaskStack[blinkerTaskStackSize];


class BlinkerTask : public os::StaticTask
{
public:
  BlinkerTask(StackType_t* stack) : StaticTask("BlinkerTask", blinkerTaskStackSize, 4, stack)
  {}

  void run() final
  {
    auto& flasher = getFlasher();
    flasher.setPeriod(500);
    flasher.setPin(UserLed2.port, UserLed2.pin);

    auto& logger = getLogger();
    logger.info("Blinker Task Started");

    while(1)
    {
      flasher.blink();
      vTaskDelay(10);
    }
  }
};


constexpr uint32_t uartTaskStackSize = 1024;
StackType_t uartTaskStack[uartTaskStackSize];


class UartTask : public os::StaticTask
{
public:
  UartTask(StackType_t* stack) : StaticTask("UartTask", uartTaskStackSize, 4, stack)
  {}

  void run() final
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
      vTaskDelay(10);
    }
  }
};


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

  auto& scheduler = getScheduler();
  BlinkerTask blinkerTask(blinkerTaskStack);
  UartTask uartTask(uartTaskStack);

  if (!scheduler.addTask(blinkerTask)) logger.error("Blinker Task create failed!");
  if (!scheduler.addTask(uartTask)) logger.error("Uart Task create failed");

  logger.info("Tasks created. Starting scheduler!");

  scheduler.start();

  while (1);
}
