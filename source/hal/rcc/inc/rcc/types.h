#ifndef RCC_TYPES_H
#define RCC_TYPES_H

#include <cstdint>

namespace stm32::hal {

enum class ClockSource {
  Hsi,
  Hse,
  Pll,
  Plli2s,
};


enum class PllClockSource {
  Hsi = 0,
  Hse = 1,
};


enum class ClockDomain {
  Ahb,
  Apb1,
  Apb2,
};


enum class ClockPrescaler {
  Div1 = 0,
  Div2,
  Div4,
  Div8,
  Div16,
  Div64,
  Div128,
  Div256,
  Div512,
};


enum class Apb1Peripheral {
  Pwr,
  I2c3,
  I2c2,
  I2c1,
  Usart2,
  Spi3,
  Spi2,
  Wwdg,
  Tim5,
  Tim4,
  Tim3,
  Tim2,
};


enum class Apb2Peripheral {
  Tim11,
  Tim10,
  Tim9,
  Syscfg,
  Spi4,
  Spi1,
  Sdio,
  Adc1,
  Usart6,
  Usart1,
  Tim1,
};


enum class Ahb1Peripheral {
  Dma2,
  Dma1,
  Crc,
  Gpioh,
  Gpioe,
  Gpiod,
  Gpioc,
  Gpiob,
  Gpioa,
};


enum class Ahb2Peripheral {
  Otgfs,
};


struct PllConfiguration {
  PllClockSource clockSource;
  uint32_t pllM;
  uint32_t pllN;
  uint32_t pllP;
  uint32_t pllQ;
};

}

#endif /* RCC_TYPES_H */
