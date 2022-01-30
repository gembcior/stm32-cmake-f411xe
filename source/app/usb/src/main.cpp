#include <cstdint>
#include "UsbSystem.h"
#include "objects.h"
#include "system/constants.h"
#include "uart/types.h"

#include "objects/objects.h"
#include "logger/Logger.h"
#include "flasher/Flasher.h"

#include "otg_fs/OtgFsDeviceHal.h"
#include "tusb.h"

using namespace stm32::objects;
using namespace stm32::system;
using namespace stm32::hal;
using namespace stm32::lib;


void writeUart(const char character)
{
  auto& uart = getObject<UartDriver>();
  uart.write(character);
}


extern "C" {

void _putchar(char character)
{
  writeUart(character);
}

void tud_cdc_line_state_cb(uint8_t itf, bool dtr, bool rts)
{
  (void) itf;
  (void) rts;
  auto& logger = getObject<Logger>();

  if (dtr) {
    logger.info("Terminal connected");
  } else {
    logger.info("Terminal disconnected");
  }
}

}


void cdc_task(void)
{
  if (tud_cdc_available()) {
    char buf[64];
    uint32_t count = tud_cdc_read(buf, sizeof(buf));

    tud_cdc_write(buf, count);
    tud_cdc_write_flush();
  }
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

  tusb_init();

  while (1)
  {
    tud_task();

    flasher.blink();

    if (gpio.getPin(UserButton) == PinState::Low && !buttonLock) {
      logger.info("User Button pushed");
      buttonLock = true;
    } else if (gpio.getPin(UserButton) == PinState::High && buttonLock) {
      logger.info("User Button released");
      buttonLock = false;
    }

    cdc_task();

  }
}
