#include "UsbIrqHandler.h"
#include "objects.h"
#include "tusb.h"


namespace stm32::irq {

void UsbIrqHandler::onInterrupt()
{
  tud_int_handler(BOARD_DEVICE_RHPORT_NUM);
}

} // namespace
