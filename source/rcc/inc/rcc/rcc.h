#ifndef RCC_H
#define RCC_H

#include <cstdint>

namespace stm32::hal {

enum class ClockSource {
  HSI,
  HSE,
  PLL,
  PLLI2S,
};


enum class PllClockSource {
  HSI,
  HSE,
};


enum class ClockDomain {
  AHB,
  APB1,
  APB2,
};


enum class ClockPrescaler {
  DIV1,
  DIV2,
  DIV4,
  DIV8,
  DIV16,
  DIV64,
  DIV128,
  DIV256,
  DIV512,
};


enum class Apb1Peripheral {
  PWR,
  I2C3,
  I2C2,
  I2C1,
  USART2,
  SPI3,
  SPI2,
  WWDG,
  TIM5,
  TIM4,
  TIM3,
  TIM2,
};


enum class Apb2Peripheral {
  SPI5,
  TIM11,
  TIM10,
  TIM9,
  SYSCFG,
  SPI4,
  SPI1,
  SDIO,
  ADC1,
  USART6,
  USART1,
  TIM1,
};


enum class Ahb1Peripheral {
  DMA2,
  DMA1,
  CRC,
  GPIOH,
  GPIOE,
  GPIOD,
  GPIOC,
  GPIOB,
  GPIOA,
};


enum class Ahb2Peripheral {
  OTGFS,
};


struct PllConfiguration {
  PllClockSource clockSource;
  uint32_t pllM;
  uint32_t pllN;
  uint32_t pllP;
  uint32_t pllQ;
};

}

#endif /* RCC_H */
