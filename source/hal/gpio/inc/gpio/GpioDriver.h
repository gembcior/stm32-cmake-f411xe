#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <cstdint>
#include "gpio/types.h"
#include "gpio/IGpioDriver.h"
#include "gpio/IGpioHal.h"

namespace stm32::hal {

class GpioDriver : public IGpioDriver
{
public:
  GpioDriver(IGpioHal** gpioHal);

  void configure(Port port, Pin pin, PortConfig config) final;
  void configure(GpioPin pin) final;
  void setPort(Port port, uint32_t value) final;
  uint32_t getPort(Port port) final;
  void setPin(Port port, Pin pin, PinState state) final;
  void setPin(GpioPin pin, PinState state) final;
  PinState getPin(Port port, Pin pin) final;
  PinState getPin(GpioPin pin) final;

private:
  IGpioHal** m_gpioHal;
};

} // namespace

#endif /* GPIO_DRIVER_H */
