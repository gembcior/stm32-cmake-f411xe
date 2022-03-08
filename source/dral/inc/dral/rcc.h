#ifndef DRAL_STM32F411_RCC_H
#define DRAL_STM32F411_RCC_H

#include "register_model.h"

namespace dral::stm32f411 {

class rcc
{
public:
  static constexpr uint32_t BaseAddress = 0x40023800;

private:
  template <uint32_t address>
  class CrReg: public RegisterModel<address>
  {
  public:
    using plli2srdy = FieldModel<address, 27, 0x00000001>;
    using plli2son = FieldModel<address, 26, 0x00000001>;
    using pllrdy = FieldModel<address, 25, 0x00000001>;
    using pllon = FieldModel<address, 24, 0x00000001>;
    using csson = FieldModel<address, 19, 0x00000001>;
    using hsebyp = FieldModel<address, 18, 0x00000001>;
    using hserdy = FieldModel<address, 17, 0x00000001>;
    using hseon = FieldModel<address, 16, 0x00000001>;
    using hsical = FieldModel<address, 8, 0x000000FF>;
    using hsitrim = FieldModel<address, 3, 0x0000001F>;
    using hsirdy = FieldModel<address, 1, 0x00000001>;
    using hsion = FieldModel<address, 0, 0x00000001>;
  };

public:
  using cr = CrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class PllcfgrReg: public RegisterModel<address>
  {
  public:
    using pllq3 = FieldModel<address, 27, 0x00000001>;
    using pllq2 = FieldModel<address, 26, 0x00000001>;
    using pllq1 = FieldModel<address, 25, 0x00000001>;
    using pllq0 = FieldModel<address, 24, 0x00000001>;
    using pllsrc = FieldModel<address, 22, 0x00000001>;
    using pllp1 = FieldModel<address, 17, 0x00000001>;
    using pllp0 = FieldModel<address, 16, 0x00000001>;
    using plln8 = FieldModel<address, 14, 0x00000001>;
    using plln7 = FieldModel<address, 13, 0x00000001>;
    using plln6 = FieldModel<address, 12, 0x00000001>;
    using plln5 = FieldModel<address, 11, 0x00000001>;
    using plln4 = FieldModel<address, 10, 0x00000001>;
    using plln3 = FieldModel<address, 9, 0x00000001>;
    using plln2 = FieldModel<address, 8, 0x00000001>;
    using plln1 = FieldModel<address, 7, 0x00000001>;
    using plln0 = FieldModel<address, 6, 0x00000001>;
    using pllm5 = FieldModel<address, 5, 0x00000001>;
    using pllm4 = FieldModel<address, 4, 0x00000001>;
    using pllm3 = FieldModel<address, 3, 0x00000001>;
    using pllm2 = FieldModel<address, 2, 0x00000001>;
    using pllm1 = FieldModel<address, 1, 0x00000001>;
    using pllm0 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using pllcfgr = PllcfgrReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class CfgrReg: public RegisterModel<address>
  {
  public:
    using mco2 = FieldModel<address, 30, 0x00000003>;
    using mco2pre = FieldModel<address, 27, 0x00000007>;
    using mco1pre = FieldModel<address, 24, 0x00000007>;
    using i2ssrc = FieldModel<address, 23, 0x00000001>;
    using mco1 = FieldModel<address, 21, 0x00000003>;
    using rtcpre = FieldModel<address, 16, 0x0000001F>;
    using ppre2 = FieldModel<address, 13, 0x00000007>;
    using ppre1 = FieldModel<address, 10, 0x00000007>;
    using hpre = FieldModel<address, 4, 0x0000000F>;
    using sws1 = FieldModel<address, 3, 0x00000001>;
    using sws0 = FieldModel<address, 2, 0x00000001>;
    using sw1 = FieldModel<address, 1, 0x00000001>;
    using sw0 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using cfgr = CfgrReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class CirReg: public RegisterModel<address>
  {
  public:
    using cssc = FieldModel<address, 23, 0x00000001>;
    using plli2srdyc = FieldModel<address, 21, 0x00000001>;
    using pllrdyc = FieldModel<address, 20, 0x00000001>;
    using hserdyc = FieldModel<address, 19, 0x00000001>;
    using hsirdyc = FieldModel<address, 18, 0x00000001>;
    using lserdyc = FieldModel<address, 17, 0x00000001>;
    using lsirdyc = FieldModel<address, 16, 0x00000001>;
    using plli2srdyie = FieldModel<address, 13, 0x00000001>;
    using pllrdyie = FieldModel<address, 12, 0x00000001>;
    using hserdyie = FieldModel<address, 11, 0x00000001>;
    using hsirdyie = FieldModel<address, 10, 0x00000001>;
    using lserdyie = FieldModel<address, 9, 0x00000001>;
    using lsirdyie = FieldModel<address, 8, 0x00000001>;
    using cssf = FieldModel<address, 7, 0x00000001>;
    using plli2srdyf = FieldModel<address, 5, 0x00000001>;
    using pllrdyf = FieldModel<address, 4, 0x00000001>;
    using hserdyf = FieldModel<address, 3, 0x00000001>;
    using hsirdyf = FieldModel<address, 2, 0x00000001>;
    using lserdyf = FieldModel<address, 1, 0x00000001>;
    using lsirdyf = FieldModel<address, 0, 0x00000001>;
  };

public:
  using cir = CirReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class Ahb1rstrReg: public RegisterModel<address>
  {
  public:
    using dma2rst = FieldModel<address, 22, 0x00000001>;
    using dma1rst = FieldModel<address, 21, 0x00000001>;
    using crcrst = FieldModel<address, 12, 0x00000001>;
    using gpiohrst = FieldModel<address, 7, 0x00000001>;
    using gpioerst = FieldModel<address, 4, 0x00000001>;
    using gpiodrst = FieldModel<address, 3, 0x00000001>;
    using gpiocrst = FieldModel<address, 2, 0x00000001>;
    using gpiobrst = FieldModel<address, 1, 0x00000001>;
    using gpioarst = FieldModel<address, 0, 0x00000001>;
  };

public:
  using ahb1rstr = Ahb1rstrReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class Ahb2rstrReg: public RegisterModel<address>
  {
  public:
    using otgfsrst = FieldModel<address, 7, 0x00000001>;
  };

public:
  using ahb2rstr = Ahb2rstrReg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class Apb1rstrReg: public RegisterModel<address>
  {
  public:
    using pwrrst = FieldModel<address, 28, 0x00000001>;
    using i2c3rst = FieldModel<address, 23, 0x00000001>;
    using i2c2rst = FieldModel<address, 22, 0x00000001>;
    using i2c1rst = FieldModel<address, 21, 0x00000001>;
    using uart2rst = FieldModel<address, 17, 0x00000001>;
    using spi3rst = FieldModel<address, 15, 0x00000001>;
    using spi2rst = FieldModel<address, 14, 0x00000001>;
    using wwdgrst = FieldModel<address, 11, 0x00000001>;
    using tim5rst = FieldModel<address, 3, 0x00000001>;
    using tim4rst = FieldModel<address, 2, 0x00000001>;
    using tim3rst = FieldModel<address, 1, 0x00000001>;
    using tim2rst = FieldModel<address, 0, 0x00000001>;
  };

public:
  using apb1rstr = Apb1rstrReg<BaseAddress + 0x0020>;

private:
  template <uint32_t address>
  class Apb2rstrReg: public RegisterModel<address>
  {
  public:
    using tim11rst = FieldModel<address, 18, 0x00000001>;
    using tim10rst = FieldModel<address, 17, 0x00000001>;
    using tim9rst = FieldModel<address, 16, 0x00000001>;
    using syscfgrst = FieldModel<address, 14, 0x00000001>;
    using spi1rst = FieldModel<address, 12, 0x00000001>;
    using sdiorst = FieldModel<address, 11, 0x00000001>;
    using adcrst = FieldModel<address, 8, 0x00000001>;
    using usart6rst = FieldModel<address, 5, 0x00000001>;
    using usart1rst = FieldModel<address, 4, 0x00000001>;
    using tim1rst = FieldModel<address, 0, 0x00000001>;
  };

public:
  using apb2rstr = Apb2rstrReg<BaseAddress + 0x0024>;

private:
  template <uint32_t address>
  class Ahb1enrReg: public RegisterModel<address>
  {
  public:
    using dma2en = FieldModel<address, 22, 0x00000001>;
    using dma1en = FieldModel<address, 21, 0x00000001>;
    using crcen = FieldModel<address, 12, 0x00000001>;
    using gpiohen = FieldModel<address, 7, 0x00000001>;
    using gpioeen = FieldModel<address, 4, 0x00000001>;
    using gpioden = FieldModel<address, 3, 0x00000001>;
    using gpiocen = FieldModel<address, 2, 0x00000001>;
    using gpioben = FieldModel<address, 1, 0x00000001>;
    using gpioaen = FieldModel<address, 0, 0x00000001>;
  };

public:
  using ahb1enr = Ahb1enrReg<BaseAddress + 0x0030>;

private:
  template <uint32_t address>
  class Ahb2enrReg: public RegisterModel<address>
  {
  public:
    using otgfsen = FieldModel<address, 7, 0x00000001>;
  };

public:
  using ahb2enr = Ahb2enrReg<BaseAddress + 0x0034>;

private:
  template <uint32_t address>
  class Apb1enrReg: public RegisterModel<address>
  {
  public:
    using pwren = FieldModel<address, 28, 0x00000001>;
    using i2c3en = FieldModel<address, 23, 0x00000001>;
    using i2c2en = FieldModel<address, 22, 0x00000001>;
    using i2c1en = FieldModel<address, 21, 0x00000001>;
    using usart2en = FieldModel<address, 17, 0x00000001>;
    using spi3en = FieldModel<address, 15, 0x00000001>;
    using spi2en = FieldModel<address, 14, 0x00000001>;
    using wwdgen = FieldModel<address, 11, 0x00000001>;
    using tim5en = FieldModel<address, 3, 0x00000001>;
    using tim4en = FieldModel<address, 2, 0x00000001>;
    using tim3en = FieldModel<address, 1, 0x00000001>;
    using tim2en = FieldModel<address, 0, 0x00000001>;
  };

public:
  using apb1enr = Apb1enrReg<BaseAddress + 0x0040>;

private:
  template <uint32_t address>
  class Apb2enrReg: public RegisterModel<address>
  {
  public:
    using tim1en = FieldModel<address, 0, 0x00000001>;
    using usart1en = FieldModel<address, 4, 0x00000001>;
    using usart6en = FieldModel<address, 5, 0x00000001>;
    using adc1en = FieldModel<address, 8, 0x00000001>;
    using sdioen = FieldModel<address, 11, 0x00000001>;
    using spi1en = FieldModel<address, 12, 0x00000001>;
    using spi4en = FieldModel<address, 13, 0x00000001>;
    using syscfgen = FieldModel<address, 14, 0x00000001>;
    using tim9en = FieldModel<address, 16, 0x00000001>;
    using tim10en = FieldModel<address, 17, 0x00000001>;
    using tim11en = FieldModel<address, 18, 0x00000001>;
  };

public:
  using apb2enr = Apb2enrReg<BaseAddress + 0x0044>;

private:
  template <uint32_t address>
  class Ahb1lpenrReg: public RegisterModel<address>
  {
  public:
    using dma2lpen = FieldModel<address, 22, 0x00000001>;
    using dma1lpen = FieldModel<address, 21, 0x00000001>;
    using sram1lpen = FieldModel<address, 16, 0x00000001>;
    using flitflpen = FieldModel<address, 15, 0x00000001>;
    using crclpen = FieldModel<address, 12, 0x00000001>;
    using gpiohlpen = FieldModel<address, 7, 0x00000001>;
    using gpioelpen = FieldModel<address, 4, 0x00000001>;
    using gpiodlpen = FieldModel<address, 3, 0x00000001>;
    using gpioclpen = FieldModel<address, 2, 0x00000001>;
    using gpioblpen = FieldModel<address, 1, 0x00000001>;
    using gpioalpen = FieldModel<address, 0, 0x00000001>;
  };

public:
  using ahb1lpenr = Ahb1lpenrReg<BaseAddress + 0x0050>;

private:
  template <uint32_t address>
  class Ahb2lpenrReg: public RegisterModel<address>
  {
  public:
    using otgfslpen = FieldModel<address, 7, 0x00000001>;
  };

public:
  using ahb2lpenr = Ahb2lpenrReg<BaseAddress + 0x0054>;

private:
  template <uint32_t address>
  class Apb1lpenrReg: public RegisterModel<address>
  {
  public:
    using pwrlpen = FieldModel<address, 28, 0x00000001>;
    using i2c3lpen = FieldModel<address, 23, 0x00000001>;
    using i2c2lpen = FieldModel<address, 22, 0x00000001>;
    using i2c1lpen = FieldModel<address, 21, 0x00000001>;
    using usart2lpen = FieldModel<address, 17, 0x00000001>;
    using spi3lpen = FieldModel<address, 15, 0x00000001>;
    using spi2lpen = FieldModel<address, 14, 0x00000001>;
    using wwdglpen = FieldModel<address, 11, 0x00000001>;
    using tim5lpen = FieldModel<address, 3, 0x00000001>;
    using tim4lpen = FieldModel<address, 2, 0x00000001>;
    using tim3lpen = FieldModel<address, 1, 0x00000001>;
    using tim2lpen = FieldModel<address, 0, 0x00000001>;
  };

public:
  using apb1lpenr = Apb1lpenrReg<BaseAddress + 0x0060>;

private:
  template <uint32_t address>
  class Apb2lpenrReg: public RegisterModel<address>
  {
  public:
    using tim1lpen = FieldModel<address, 0, 0x00000001>;
    using usart1lpen = FieldModel<address, 4, 0x00000001>;
    using usart6lpen = FieldModel<address, 5, 0x00000001>;
    using adc1lpen = FieldModel<address, 8, 0x00000001>;
    using sdiolpen = FieldModel<address, 11, 0x00000001>;
    using spi1lpen = FieldModel<address, 12, 0x00000001>;
    using spi4lpen = FieldModel<address, 13, 0x00000001>;
    using syscfglpen = FieldModel<address, 14, 0x00000001>;
    using tim9lpen = FieldModel<address, 16, 0x00000001>;
    using tim10lpen = FieldModel<address, 17, 0x00000001>;
    using tim11lpen = FieldModel<address, 18, 0x00000001>;
  };

public:
  using apb2lpenr = Apb2lpenrReg<BaseAddress + 0x0064>;

private:
  template <uint32_t address>
  class BdcrReg: public RegisterModel<address>
  {
  public:
    using bdrst = FieldModel<address, 16, 0x00000001>;
    using rtcen = FieldModel<address, 15, 0x00000001>;
    using rtcsel1 = FieldModel<address, 9, 0x00000001>;
    using rtcsel0 = FieldModel<address, 8, 0x00000001>;
    using lsebyp = FieldModel<address, 2, 0x00000001>;
    using lserdy = FieldModel<address, 1, 0x00000001>;
    using lseon = FieldModel<address, 0, 0x00000001>;
  };

public:
  using bdcr = BdcrReg<BaseAddress + 0x0070>;

private:
  template <uint32_t address>
  class CsrReg: public RegisterModel<address>
  {
  public:
    using lpwrrstf = FieldModel<address, 31, 0x00000001>;
    using wwdgrstf = FieldModel<address, 30, 0x00000001>;
    using wdgrstf = FieldModel<address, 29, 0x00000001>;
    using sftrstf = FieldModel<address, 28, 0x00000001>;
    using porrstf = FieldModel<address, 27, 0x00000001>;
    using padrstf = FieldModel<address, 26, 0x00000001>;
    using borrstf = FieldModel<address, 25, 0x00000001>;
    using rmvf = FieldModel<address, 24, 0x00000001>;
    using lsirdy = FieldModel<address, 1, 0x00000001>;
    using lsion = FieldModel<address, 0, 0x00000001>;
  };

public:
  using csr = CsrReg<BaseAddress + 0x0074>;

private:
  template <uint32_t address>
  class SscgrReg: public RegisterModel<address>
  {
  public:
    using sscgen = FieldModel<address, 31, 0x00000001>;
    using spreadsel = FieldModel<address, 30, 0x00000001>;
    using incstep = FieldModel<address, 13, 0x00007FFF>;
    using modper = FieldModel<address, 0, 0x00001FFF>;
  };

public:
  using sscgr = SscgrReg<BaseAddress + 0x0080>;

private:
  template <uint32_t address>
  class Plli2scfgrReg: public RegisterModel<address>
  {
  public:
    using plli2srx = FieldModel<address, 28, 0x00000007>;
    using plli2snx = FieldModel<address, 6, 0x000001FF>;
  };

public:
  using plli2scfgr = Plli2scfgrReg<BaseAddress + 0x0084>;
};

}

#endif /* DRAL_STM32F411_RCC_H */
