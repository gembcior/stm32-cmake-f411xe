#ifndef STM32_F411XE_CONST_GENERAL_H
#define STM32_F411XE_CONST_GENERAL_H

#include <cstdint>

namespace stm32 {

  constexpr uint32_t FlashBase             = 0x08000000UL;
  constexpr uint32_t Sram1Base             = 0x20000000UL;
  constexpr uint32_t PeriphBase            = 0x40000000UL;
  constexpr uint32_t Sram1BbBase           = 0x22000000UL;
  constexpr uint32_t PeriphBbBase          = 0x42000000UL;
  constexpr uint32_t BkpSramBbBase         = 0x42480000UL;
  constexpr uint32_t FlashEnd              = 0x0807FFFFUL;
  constexpr uint32_t FlashOtpBase          = 0x1FFF7800UL;
  constexpr uint32_t FlashOtpEnd           = 0x1FFF7A0FUL;
  constexpr uint32_t Apb1PeriphBase        = PeriphBase;
  constexpr uint32_t Apb2PeriphBase        = (PeriphBase + 0x00010000UL);
  constexpr uint32_t Ahb1PeriphBase        = (PeriphBase + 0x00020000UL);
  constexpr uint32_t Ahb2PeriphBase        = (PeriphBase + 0x10000000UL);
  constexpr uint32_t Tim2Base              = (Apb1PeriphBase + 0x0000UL);
  constexpr uint32_t Tim3Base              = (Apb1PeriphBase + 0x0400UL);
  constexpr uint32_t Tim4Base              = (Apb1PeriphBase + 0x0800UL);
  constexpr uint32_t Tim5Base              = (Apb1PeriphBase + 0x0C00UL);
  constexpr uint32_t RtcBase               = (Apb1PeriphBase + 0x2800UL);
  constexpr uint32_t WwdgBase              = (Apb1PeriphBase + 0x2C00UL);
  constexpr uint32_t IwdgBase              = (Apb1PeriphBase + 0x3000UL);
  constexpr uint32_t I2s2ExtBase           = (Apb1PeriphBase + 0x3400UL);
  constexpr uint32_t Spi2Base              = (Apb1PeriphBase + 0x3800UL);
  constexpr uint32_t Spi3Base              = (Apb1PeriphBase + 0x3C00UL);
  constexpr uint32_t I2s3ExtBase           = (Apb1PeriphBase + 0x4000UL);
  constexpr uint32_t Usart2Base            = (Apb1PeriphBase + 0x4400UL);
  constexpr uint32_t I2c1Base              = (Apb1PeriphBase + 0x5400UL);
  constexpr uint32_t I2c2Base              = (Apb1PeriphBase + 0x5800UL);
  constexpr uint32_t I2c3Base              = (Apb1PeriphBase + 0x5C00UL);
  constexpr uint32_t PwrBase               = (Apb1PeriphBase + 0x7000UL);
  constexpr uint32_t Tim1Base              = (Apb2PeriphBase + 0x0000UL);
  constexpr uint32_t Usart1Base            = (Apb2PeriphBase + 0x1000UL);
  constexpr uint32_t Usart6Base            = (Apb2PeriphBase + 0x1400UL);
  constexpr uint32_t Adc1Base              = (Apb2PeriphBase + 0x2000UL);
  constexpr uint32_t Adc1CommonBase        = (Apb2PeriphBase + 0x2300UL);
  constexpr uint32_t SdioBase              = (Apb2PeriphBase + 0x2C00UL);
  constexpr uint32_t Spi1Base              = (Apb2PeriphBase + 0x3000UL);
  constexpr uint32_t Spi4Base              = (Apb2PeriphBase + 0x3400UL);
  constexpr uint32_t SysCfgBase            = (Apb2PeriphBase + 0x3800UL);
  constexpr uint32_t ExtiBase              = (Apb2PeriphBase + 0x3C00UL);
  constexpr uint32_t Tim9Base              = (Apb2PeriphBase + 0x4000UL);
  constexpr uint32_t Tim10Base             = (Apb2PeriphBase + 0x4400UL);
  constexpr uint32_t Tim11Base             = (Apb2PeriphBase + 0x4800UL);
  constexpr uint32_t Spi5Base              = (Apb2PeriphBase + 0x5000UL);
  constexpr uint32_t GpioABase             = (Ahb1PeriphBase + 0x0000UL);
  constexpr uint32_t GpioBBase             = (Ahb1PeriphBase + 0x0400UL);
  constexpr uint32_t GpioCBase             = (Ahb1PeriphBase + 0x0800UL);
  constexpr uint32_t GpioDBase             = (Ahb1PeriphBase + 0x0C00UL);
  constexpr uint32_t GpioEBase             = (Ahb1PeriphBase + 0x1000UL);
  constexpr uint32_t GpioHBase             = (Ahb1PeriphBase + 0x1C00UL);
  constexpr uint32_t CrcBase               = (Ahb1PeriphBase + 0x3000UL);
  constexpr uint32_t RccBase               = (Ahb1PeriphBase + 0x3800UL);
  constexpr uint32_t FlashRBase            = (Ahb1PeriphBase + 0x3C00UL);
  constexpr uint32_t Dma1Base              = (Ahb1PeriphBase + 0x6000UL);
  constexpr uint32_t Dma1Stream0Base       = (Dma1Base + 0x010UL);
  constexpr uint32_t Dma1Stream1Base       = (Dma1Base + 0x028UL);
  constexpr uint32_t Dma1Stream2Base       = (Dma1Base + 0x040UL);
  constexpr uint32_t Dma1Stream3Base       = (Dma1Base + 0x058UL);
  constexpr uint32_t Dma1Stream4Base       = (Dma1Base + 0x070UL);
  constexpr uint32_t Dma1Stream5Base       = (Dma1Base + 0x088UL);
  constexpr uint32_t Dma1Stream6Base       = (Dma1Base + 0x0A0UL);
  constexpr uint32_t Dma1Stream7Base       = (Dma1Base + 0x0B8UL);
  constexpr uint32_t Dma2Base              = (Ahb1PeriphBase + 0x6400UL);
  constexpr uint32_t Dma2Stream0Base       = (Dma2Base + 0x010UL);
  constexpr uint32_t Dma2Stream1Base       = (Dma2Base + 0x028UL);
  constexpr uint32_t Dma2Stream2Base       = (Dma2Base + 0x040UL);
  constexpr uint32_t Dma2Stream3Base       = (Dma2Base + 0x058UL);
  constexpr uint32_t Dma2Stream4Base       = (Dma2Base + 0x070UL);
  constexpr uint32_t Dma2Stream5Base       = (Dma2Base + 0x088UL);
  constexpr uint32_t Dma2Stream6Base       = (Dma2Base + 0x0A0UL);
  constexpr uint32_t Dma2Stream7Base       = (Dma2Base + 0x0B8UL);
  constexpr uint32_t DbgMcuBase            = 0xE0042000UL;
  constexpr uint32_t UsbOtgFsPeriphBase    = 0x50000000UL;
  constexpr uint32_t UsbOtgGlobalBase      = 0x000UL;
  constexpr uint32_t UsbOtgDeviceBase      = 0x800UL;
  constexpr uint32_t UsbOtgInEndpointBase  = 0x900UL;
  constexpr uint32_t UsbOtgOutEndpointBase = 0xB00UL;
  constexpr uint32_t UsbOtgEpRegSize       = 0x20UL;
  constexpr uint32_t UsbOtgHostBase        = 0x400UL;
  constexpr uint32_t UsbOtgHostPortBase    = 0x440UL;
  constexpr uint32_t UsbOtgHostChannelBase = 0x500UL;
  constexpr uint32_t UsbOtgHostChannelSize = 0x20UL;
  constexpr uint32_t UsbOtgPcgcctlBase     = 0xE00UL;
  constexpr uint32_t UsbOtgFifoBase        = 0x1000UL;
  constexpr uint32_t UsbOtgFifoSize        = 0x1000UL;
  constexpr uint32_t UidBase               = 0x1FFF7A10UL;
  constexpr uint32_t FlashSizeBase         = 0x1FFF7A22UL;
  constexpr uint32_t PackageBase           = 0x1FFF7BF0UL;

}

#endif /* STM32_F411XE_CONST_GENERAL_H */
