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
StaticTask_t blinkerTaskBuffer;


class BlinkerTask : public os::StaticTask
{
public:
  BlinkerTask(StackType_t* stackBuffer, StaticTask_t* taskBuffer) :
    StaticTask("BlinkerTask", blinkerTaskStackSize, 24, stackBuffer, taskBuffer)
  {}

  void run() final
  {
    auto& logger = getLogger();
    auto& flasher = getFlasher();

    logger.info("Blinker Task Started");

    flasher.setPeriod(500);
    flasher.setPin(UserLed2.port, UserLed2.pin);

    while(1)
    {
      flasher.blink();
    }
  }
};


constexpr uint32_t uartTaskStackSize = 1024;
StackType_t uartTaskStack[uartTaskStackSize];
StaticTask_t uartTaskBuffer;


class UartTask : public os::StaticTask
{
public:
  UartTask(StackType_t* stackBuffer, StaticTask_t* taskBuffer) :
    StaticTask("UartTask", uartTaskStackSize, 24, stackBuffer, taskBuffer)
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

  uart.configure(uartConfig);
  uart.enable();

  auto& logger = getLogger();
  logger.registerOutput(writeUart);
  logger.info("Blinker application started!");

  BlinkerTask blinkerTask(blinkerTaskStack, &blinkerTaskBuffer);
  UartTask uartTask(uartTaskStack, &uartTaskBuffer);

  auto& scheduler = getScheduler();
  if (!scheduler.addTask(blinkerTask)) logger.error("Blinker Task create failed!");
  if (!scheduler.addTask(uartTask)) logger.error("Uart Task create failed");

  logger.info("Tasks created. Starting scheduler!");

  scheduler.start();

  while (1);
}
