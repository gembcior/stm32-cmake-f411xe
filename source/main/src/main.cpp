#include <cstdint>
#include "main/main.h"
#include "system/System.h"
#include "objects/objects.h"
#include "system/constants.h"


using namespace stm32::objects;
using namespace stm32::system;

void delay(uint32_t delay)
{
  for (volatile uint32_t i = 0; i < 100000; i++) {
    for (volatile uint32_t j = 0; j < delay; j++) {
    }
  }
}


int main(void)
{
  auto& system = getSystem();
  system.initialize();

  auto& flasher = getFlasher();

  flasher.setPin(UserLed2.port, UserLed2.pin);

  while (1)
  {
    flasher.blink();
  }
}
