#include "FreeRTOS.h"
#include "task.h"

#include <cstdint>
#include "objects.h"
#include "system/constants.h"
#include "uart/types.h"
#include "logger/OsLogger.h"
#include "ticktack/TickTack.h"

#include "os/Task.h"
#include "os/Scheduler.h"


using namespace stm32::objects;
using namespace stm32::system;
using namespace stm32::hal;
using namespace stm32::lib;
using namespace stm32::irq;
using namespace os;


void writeUart(const char character)
{
  auto& uart = getObject<UartDriver>();
  uart.write(character);
}


constexpr uint32_t blinkerTaskStackSize = 1024;
StackType_t blinkerTaskStack[blinkerTaskStackSize] = {};


class BlinkerTask : public Task
{
public:
  BlinkerTask(StackType_t* stackBuffer) :
    Task("BlinkerTask", blinkerTaskStackSize, 24, stackBuffer)
  {}

  void run() final
  {
    auto& logger = getObject<OsLogger>();
    auto& flasher = getObject<Flasher>();

    logger.info("Blinker Task Started");

    flasher.setPeriod(0);
    flasher.setPin(UserLed2.port, UserLed2.pin);

    while(1)
    {
      flasher.blink();
    }
  }
};


constexpr uint32_t uartTaskStackSize = 1024;
StackType_t uartTaskStack[uartTaskStackSize] = {};


class UartTask : public Task
{
public:
  UartTask(StackType_t* stackBuffer) :
    Task("UartTask", uartTaskStackSize, 24, stackBuffer)
  {}

  void run() final
  {
    auto& logger = getObject<OsLogger>();
    auto& gpio = getObject<GpioDriver>();

    logger.info("Uart Task Started");

    bool buttonLock = false;
    while(1)
    {
      if (gpio.getPin(UserButton) == PinState::Low && !buttonLock) {
        logger.info("User Button pushed");
        buttonLock = true;
        getObject<TickTack>().tick();
      } else if (gpio.getPin(UserButton) == PinState::High && buttonLock) {
        logger.info("User Button released");
        buttonLock = false;
      }
    }
  }
};


BlinkerTask blinkerTask(blinkerTaskStack);
UartTask uartTask(uartTaskStack);


int main(void)
{
  getIrqVectorTable();
  auto& system = getObject<System>();
  auto& uart = getObject<UartDriver>();
  auto& logger = getObject<OsLogger>();

  system.initialize();

  UartConfiguration uartConfig = {
    .mode = UartMode::Tx,
    .baudRate = 115200,
    .dataLength = UartDataLength::Data8Bits,
    .parity = UartParity::Disable,
    .stopBits = UartStopBits::OneStopBit
  };

  uart.configure(uartConfig);
  uart.enable();

  logger.registerOutput(writeUart);
  logger.info("Blinker application started!");

  auto& scheduler = getObject<Scheduler>();
  if (!scheduler.addTask(blinkerTask)) logger.error("Blinker Task create failed!");
  if (!scheduler.addTask(uartTask)) logger.error("Uart Task create failed");

  logger.info("Tasks created. Starting scheduler!");

  auto field1 = blinkerTask.getBuffer();
  (void)field1->ucDummy19;
  scheduler.start();

  while (1);
}
