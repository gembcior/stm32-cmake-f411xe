#include <cstdint>
#include "BlinkerSystem.h"
#include "objects.h"
#include "system/constants.h"


using namespace stm32::objects;
using namespace stm32::system;


int main(void)
{
  auto& system = getSystem();
  system.initialize();

  auto& flasher = getFlasher();

  flasher.setPeriod(500);
  flasher.setPin(UserLed2.port, UserLed2.pin);

  while (1)
  {
    flasher.blink();
  }
}
