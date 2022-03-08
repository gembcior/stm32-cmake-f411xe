#ifndef DRAL_STM32F411_DMA2_H
#define DRAL_STM32F411_DMA2_H

#include "register_model.h"

namespace dral::stm32f411 {

class dma2
{
public:
  static constexpr uint32_t BaseAddress = 0x40026400;

private:
  template <uint32_t address>
  class LisrReg: public RegisterModel<address>
  {
  public:
    using tcif3 = FieldModel<address, 27, 0x00000001>;
    using htif3 = FieldModel<address, 26, 0x00000001>;
    using teif3 = FieldModel<address, 25, 0x00000001>;
    using dmeif3 = FieldModel<address, 24, 0x00000001>;
    using feif3 = FieldModel<address, 22, 0x00000001>;
    using tcif2 = FieldModel<address, 21, 0x00000001>;
    using htif2 = FieldModel<address, 20, 0x00000001>;
    using teif2 = FieldModel<address, 19, 0x00000001>;
    using dmeif2 = FieldModel<address, 18, 0x00000001>;
    using feif2 = FieldModel<address, 16, 0x00000001>;
    using tcif1 = FieldModel<address, 11, 0x00000001>;
    using htif1 = FieldModel<address, 10, 0x00000001>;
    using teif1 = FieldModel<address, 9, 0x00000001>;
    using dmeif1 = FieldModel<address, 8, 0x00000001>;
    using feif1 = FieldModel<address, 6, 0x00000001>;
    using tcif0 = FieldModel<address, 5, 0x00000001>;
    using htif0 = FieldModel<address, 4, 0x00000001>;
    using teif0 = FieldModel<address, 3, 0x00000001>;
    using dmeif0 = FieldModel<address, 2, 0x00000001>;
    using feif0 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using lisr = LisrReg<BaseAddress + 0x0000>;

private:
  template <uint32_t address>
  class HisrReg: public RegisterModel<address>
  {
  public:
    using tcif7 = FieldModel<address, 27, 0x00000001>;
    using htif7 = FieldModel<address, 26, 0x00000001>;
    using teif7 = FieldModel<address, 25, 0x00000001>;
    using dmeif7 = FieldModel<address, 24, 0x00000001>;
    using feif7 = FieldModel<address, 22, 0x00000001>;
    using tcif6 = FieldModel<address, 21, 0x00000001>;
    using htif6 = FieldModel<address, 20, 0x00000001>;
    using teif6 = FieldModel<address, 19, 0x00000001>;
    using dmeif6 = FieldModel<address, 18, 0x00000001>;
    using feif6 = FieldModel<address, 16, 0x00000001>;
    using tcif5 = FieldModel<address, 11, 0x00000001>;
    using htif5 = FieldModel<address, 10, 0x00000001>;
    using teif5 = FieldModel<address, 9, 0x00000001>;
    using dmeif5 = FieldModel<address, 8, 0x00000001>;
    using feif5 = FieldModel<address, 6, 0x00000001>;
    using tcif4 = FieldModel<address, 5, 0x00000001>;
    using htif4 = FieldModel<address, 4, 0x00000001>;
    using teif4 = FieldModel<address, 3, 0x00000001>;
    using dmeif4 = FieldModel<address, 2, 0x00000001>;
    using feif4 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using hisr = HisrReg<BaseAddress + 0x0004>;

private:
  template <uint32_t address>
  class LifcrReg: public RegisterModel<address>
  {
  public:
    using ctcif3 = FieldModel<address, 27, 0x00000001>;
    using chtif3 = FieldModel<address, 26, 0x00000001>;
    using cteif3 = FieldModel<address, 25, 0x00000001>;
    using cdmeif3 = FieldModel<address, 24, 0x00000001>;
    using cfeif3 = FieldModel<address, 22, 0x00000001>;
    using ctcif2 = FieldModel<address, 21, 0x00000001>;
    using chtif2 = FieldModel<address, 20, 0x00000001>;
    using cteif2 = FieldModel<address, 19, 0x00000001>;
    using cdmeif2 = FieldModel<address, 18, 0x00000001>;
    using cfeif2 = FieldModel<address, 16, 0x00000001>;
    using ctcif1 = FieldModel<address, 11, 0x00000001>;
    using chtif1 = FieldModel<address, 10, 0x00000001>;
    using cteif1 = FieldModel<address, 9, 0x00000001>;
    using cdmeif1 = FieldModel<address, 8, 0x00000001>;
    using cfeif1 = FieldModel<address, 6, 0x00000001>;
    using ctcif0 = FieldModel<address, 5, 0x00000001>;
    using chtif0 = FieldModel<address, 4, 0x00000001>;
    using cteif0 = FieldModel<address, 3, 0x00000001>;
    using cdmeif0 = FieldModel<address, 2, 0x00000001>;
    using cfeif0 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using lifcr = LifcrReg<BaseAddress + 0x0008>;

private:
  template <uint32_t address>
  class HifcrReg: public RegisterModel<address>
  {
  public:
    using ctcif7 = FieldModel<address, 27, 0x00000001>;
    using chtif7 = FieldModel<address, 26, 0x00000001>;
    using cteif7 = FieldModel<address, 25, 0x00000001>;
    using cdmeif7 = FieldModel<address, 24, 0x00000001>;
    using cfeif7 = FieldModel<address, 22, 0x00000001>;
    using ctcif6 = FieldModel<address, 21, 0x00000001>;
    using chtif6 = FieldModel<address, 20, 0x00000001>;
    using cteif6 = FieldModel<address, 19, 0x00000001>;
    using cdmeif6 = FieldModel<address, 18, 0x00000001>;
    using cfeif6 = FieldModel<address, 16, 0x00000001>;
    using ctcif5 = FieldModel<address, 11, 0x00000001>;
    using chtif5 = FieldModel<address, 10, 0x00000001>;
    using cteif5 = FieldModel<address, 9, 0x00000001>;
    using cdmeif5 = FieldModel<address, 8, 0x00000001>;
    using cfeif5 = FieldModel<address, 6, 0x00000001>;
    using ctcif4 = FieldModel<address, 5, 0x00000001>;
    using chtif4 = FieldModel<address, 4, 0x00000001>;
    using cteif4 = FieldModel<address, 3, 0x00000001>;
    using cdmeif4 = FieldModel<address, 2, 0x00000001>;
    using cfeif4 = FieldModel<address, 0, 0x00000001>;
  };

public:
  using hifcr = HifcrReg<BaseAddress + 0x000C>;

private:
  template <uint32_t address>
  class S0crReg: public RegisterModel<address>
  {
  public:
    using chsel = FieldModel<address, 25, 0x00000007>;
    using mburst = FieldModel<address, 23, 0x00000003>;
    using pburst = FieldModel<address, 21, 0x00000003>;
    using ct = FieldModel<address, 19, 0x00000001>;
    using dbm = FieldModel<address, 18, 0x00000001>;
    using pl = FieldModel<address, 16, 0x00000003>;
    using pincos = FieldModel<address, 15, 0x00000001>;
    using msize = FieldModel<address, 13, 0x00000003>;
    using psize = FieldModel<address, 11, 0x00000003>;
    using minc = FieldModel<address, 10, 0x00000001>;
    using pinc = FieldModel<address, 9, 0x00000001>;
    using circ = FieldModel<address, 8, 0x00000001>;
    using dir = FieldModel<address, 6, 0x00000003>;
    using pfctrl = FieldModel<address, 5, 0x00000001>;
    using tcie = FieldModel<address, 4, 0x00000001>;
    using htie = FieldModel<address, 3, 0x00000001>;
    using teie = FieldModel<address, 2, 0x00000001>;
    using dmeie = FieldModel<address, 1, 0x00000001>;
    using en = FieldModel<address, 0, 0x00000001>;
  };

public:
  using s0cr = S0crReg<BaseAddress + 0x0010>;

private:
  template <uint32_t address>
  class S0ndtrReg: public RegisterModel<address>
  {
  public:
    using ndt = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using s0ndtr = S0ndtrReg<BaseAddress + 0x0014>;

private:
  template <uint32_t address>
  class S0parReg: public RegisterModel<address>
  {
  public:
    using pa = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s0par = S0parReg<BaseAddress + 0x0018>;

private:
  template <uint32_t address>
  class S0m0arReg: public RegisterModel<address>
  {
  public:
    using m0a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s0m0ar = S0m0arReg<BaseAddress + 0x001C>;

private:
  template <uint32_t address>
  class S0m1arReg: public RegisterModel<address>
  {
  public:
    using m1a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s0m1ar = S0m1arReg<BaseAddress + 0x0020>;

private:
  template <uint32_t address>
  class S0fcrReg: public RegisterModel<address>
  {
  public:
    using feie = FieldModel<address, 7, 0x00000001>;
    using fs = FieldModel<address, 3, 0x00000007>;
    using dmdis = FieldModel<address, 2, 0x00000001>;
    using fth = FieldModel<address, 0, 0x00000003>;
  };

public:
  using s0fcr = S0fcrReg<BaseAddress + 0x0024>;

private:
  template <uint32_t address>
  class S1crReg: public RegisterModel<address>
  {
  public:
    using chsel = FieldModel<address, 25, 0x00000007>;
    using mburst = FieldModel<address, 23, 0x00000003>;
    using pburst = FieldModel<address, 21, 0x00000003>;
    using ack = FieldModel<address, 20, 0x00000001>;
    using ct = FieldModel<address, 19, 0x00000001>;
    using dbm = FieldModel<address, 18, 0x00000001>;
    using pl = FieldModel<address, 16, 0x00000003>;
    using pincos = FieldModel<address, 15, 0x00000001>;
    using msize = FieldModel<address, 13, 0x00000003>;
    using psize = FieldModel<address, 11, 0x00000003>;
    using minc = FieldModel<address, 10, 0x00000001>;
    using pinc = FieldModel<address, 9, 0x00000001>;
    using circ = FieldModel<address, 8, 0x00000001>;
    using dir = FieldModel<address, 6, 0x00000003>;
    using pfctrl = FieldModel<address, 5, 0x00000001>;
    using tcie = FieldModel<address, 4, 0x00000001>;
    using htie = FieldModel<address, 3, 0x00000001>;
    using teie = FieldModel<address, 2, 0x00000001>;
    using dmeie = FieldModel<address, 1, 0x00000001>;
    using en = FieldModel<address, 0, 0x00000001>;
  };

public:
  using s1cr = S1crReg<BaseAddress + 0x0028>;

private:
  template <uint32_t address>
  class S1ndtrReg: public RegisterModel<address>
  {
  public:
    using ndt = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using s1ndtr = S1ndtrReg<BaseAddress + 0x002C>;

private:
  template <uint32_t address>
  class S1parReg: public RegisterModel<address>
  {
  public:
    using pa = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s1par = S1parReg<BaseAddress + 0x0030>;

private:
  template <uint32_t address>
  class S1m0arReg: public RegisterModel<address>
  {
  public:
    using m0a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s1m0ar = S1m0arReg<BaseAddress + 0x0034>;

private:
  template <uint32_t address>
  class S1m1arReg: public RegisterModel<address>
  {
  public:
    using m1a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s1m1ar = S1m1arReg<BaseAddress + 0x0038>;

private:
  template <uint32_t address>
  class S1fcrReg: public RegisterModel<address>
  {
  public:
    using feie = FieldModel<address, 7, 0x00000001>;
    using fs = FieldModel<address, 3, 0x00000007>;
    using dmdis = FieldModel<address, 2, 0x00000001>;
    using fth = FieldModel<address, 0, 0x00000003>;
  };

public:
  using s1fcr = S1fcrReg<BaseAddress + 0x003C>;

private:
  template <uint32_t address>
  class S2crReg: public RegisterModel<address>
  {
  public:
    using chsel = FieldModel<address, 25, 0x00000007>;
    using mburst = FieldModel<address, 23, 0x00000003>;
    using pburst = FieldModel<address, 21, 0x00000003>;
    using ack = FieldModel<address, 20, 0x00000001>;
    using ct = FieldModel<address, 19, 0x00000001>;
    using dbm = FieldModel<address, 18, 0x00000001>;
    using pl = FieldModel<address, 16, 0x00000003>;
    using pincos = FieldModel<address, 15, 0x00000001>;
    using msize = FieldModel<address, 13, 0x00000003>;
    using psize = FieldModel<address, 11, 0x00000003>;
    using minc = FieldModel<address, 10, 0x00000001>;
    using pinc = FieldModel<address, 9, 0x00000001>;
    using circ = FieldModel<address, 8, 0x00000001>;
    using dir = FieldModel<address, 6, 0x00000003>;
    using pfctrl = FieldModel<address, 5, 0x00000001>;
    using tcie = FieldModel<address, 4, 0x00000001>;
    using htie = FieldModel<address, 3, 0x00000001>;
    using teie = FieldModel<address, 2, 0x00000001>;
    using dmeie = FieldModel<address, 1, 0x00000001>;
    using en = FieldModel<address, 0, 0x00000001>;
  };

public:
  using s2cr = S2crReg<BaseAddress + 0x0040>;

private:
  template <uint32_t address>
  class S2ndtrReg: public RegisterModel<address>
  {
  public:
    using ndt = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using s2ndtr = S2ndtrReg<BaseAddress + 0x0044>;

private:
  template <uint32_t address>
  class S2parReg: public RegisterModel<address>
  {
  public:
    using pa = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s2par = S2parReg<BaseAddress + 0x0048>;

private:
  template <uint32_t address>
  class S2m0arReg: public RegisterModel<address>
  {
  public:
    using m0a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s2m0ar = S2m0arReg<BaseAddress + 0x004C>;

private:
  template <uint32_t address>
  class S2m1arReg: public RegisterModel<address>
  {
  public:
    using m1a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s2m1ar = S2m1arReg<BaseAddress + 0x0050>;

private:
  template <uint32_t address>
  class S2fcrReg: public RegisterModel<address>
  {
  public:
    using feie = FieldModel<address, 7, 0x00000001>;
    using fs = FieldModel<address, 3, 0x00000007>;
    using dmdis = FieldModel<address, 2, 0x00000001>;
    using fth = FieldModel<address, 0, 0x00000003>;
  };

public:
  using s2fcr = S2fcrReg<BaseAddress + 0x0054>;

private:
  template <uint32_t address>
  class S3crReg: public RegisterModel<address>
  {
  public:
    using chsel = FieldModel<address, 25, 0x00000007>;
    using mburst = FieldModel<address, 23, 0x00000003>;
    using pburst = FieldModel<address, 21, 0x00000003>;
    using ack = FieldModel<address, 20, 0x00000001>;
    using ct = FieldModel<address, 19, 0x00000001>;
    using dbm = FieldModel<address, 18, 0x00000001>;
    using pl = FieldModel<address, 16, 0x00000003>;
    using pincos = FieldModel<address, 15, 0x00000001>;
    using msize = FieldModel<address, 13, 0x00000003>;
    using psize = FieldModel<address, 11, 0x00000003>;
    using minc = FieldModel<address, 10, 0x00000001>;
    using pinc = FieldModel<address, 9, 0x00000001>;
    using circ = FieldModel<address, 8, 0x00000001>;
    using dir = FieldModel<address, 6, 0x00000003>;
    using pfctrl = FieldModel<address, 5, 0x00000001>;
    using tcie = FieldModel<address, 4, 0x00000001>;
    using htie = FieldModel<address, 3, 0x00000001>;
    using teie = FieldModel<address, 2, 0x00000001>;
    using dmeie = FieldModel<address, 1, 0x00000001>;
    using en = FieldModel<address, 0, 0x00000001>;
  };

public:
  using s3cr = S3crReg<BaseAddress + 0x0058>;

private:
  template <uint32_t address>
  class S3ndtrReg: public RegisterModel<address>
  {
  public:
    using ndt = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using s3ndtr = S3ndtrReg<BaseAddress + 0x005C>;

private:
  template <uint32_t address>
  class S3parReg: public RegisterModel<address>
  {
  public:
    using pa = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s3par = S3parReg<BaseAddress + 0x0060>;

private:
  template <uint32_t address>
  class S3m0arReg: public RegisterModel<address>
  {
  public:
    using m0a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s3m0ar = S3m0arReg<BaseAddress + 0x0064>;

private:
  template <uint32_t address>
  class S3m1arReg: public RegisterModel<address>
  {
  public:
    using m1a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s3m1ar = S3m1arReg<BaseAddress + 0x0068>;

private:
  template <uint32_t address>
  class S3fcrReg: public RegisterModel<address>
  {
  public:
    using feie = FieldModel<address, 7, 0x00000001>;
    using fs = FieldModel<address, 3, 0x00000007>;
    using dmdis = FieldModel<address, 2, 0x00000001>;
    using fth = FieldModel<address, 0, 0x00000003>;
  };

public:
  using s3fcr = S3fcrReg<BaseAddress + 0x006C>;

private:
  template <uint32_t address>
  class S4crReg: public RegisterModel<address>
  {
  public:
    using chsel = FieldModel<address, 25, 0x00000007>;
    using mburst = FieldModel<address, 23, 0x00000003>;
    using pburst = FieldModel<address, 21, 0x00000003>;
    using ack = FieldModel<address, 20, 0x00000001>;
    using ct = FieldModel<address, 19, 0x00000001>;
    using dbm = FieldModel<address, 18, 0x00000001>;
    using pl = FieldModel<address, 16, 0x00000003>;
    using pincos = FieldModel<address, 15, 0x00000001>;
    using msize = FieldModel<address, 13, 0x00000003>;
    using psize = FieldModel<address, 11, 0x00000003>;
    using minc = FieldModel<address, 10, 0x00000001>;
    using pinc = FieldModel<address, 9, 0x00000001>;
    using circ = FieldModel<address, 8, 0x00000001>;
    using dir = FieldModel<address, 6, 0x00000003>;
    using pfctrl = FieldModel<address, 5, 0x00000001>;
    using tcie = FieldModel<address, 4, 0x00000001>;
    using htie = FieldModel<address, 3, 0x00000001>;
    using teie = FieldModel<address, 2, 0x00000001>;
    using dmeie = FieldModel<address, 1, 0x00000001>;
    using en = FieldModel<address, 0, 0x00000001>;
  };

public:
  using s4cr = S4crReg<BaseAddress + 0x0070>;

private:
  template <uint32_t address>
  class S4ndtrReg: public RegisterModel<address>
  {
  public:
    using ndt = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using s4ndtr = S4ndtrReg<BaseAddress + 0x0074>;

private:
  template <uint32_t address>
  class S4parReg: public RegisterModel<address>
  {
  public:
    using pa = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s4par = S4parReg<BaseAddress + 0x0078>;

private:
  template <uint32_t address>
  class S4m0arReg: public RegisterModel<address>
  {
  public:
    using m0a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s4m0ar = S4m0arReg<BaseAddress + 0x007C>;

private:
  template <uint32_t address>
  class S4m1arReg: public RegisterModel<address>
  {
  public:
    using m1a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s4m1ar = S4m1arReg<BaseAddress + 0x0080>;

private:
  template <uint32_t address>
  class S4fcrReg: public RegisterModel<address>
  {
  public:
    using feie = FieldModel<address, 7, 0x00000001>;
    using fs = FieldModel<address, 3, 0x00000007>;
    using dmdis = FieldModel<address, 2, 0x00000001>;
    using fth = FieldModel<address, 0, 0x00000003>;
  };

public:
  using s4fcr = S4fcrReg<BaseAddress + 0x0084>;

private:
  template <uint32_t address>
  class S5crReg: public RegisterModel<address>
  {
  public:
    using chsel = FieldModel<address, 25, 0x00000007>;
    using mburst = FieldModel<address, 23, 0x00000003>;
    using pburst = FieldModel<address, 21, 0x00000003>;
    using ack = FieldModel<address, 20, 0x00000001>;
    using ct = FieldModel<address, 19, 0x00000001>;
    using dbm = FieldModel<address, 18, 0x00000001>;
    using pl = FieldModel<address, 16, 0x00000003>;
    using pincos = FieldModel<address, 15, 0x00000001>;
    using msize = FieldModel<address, 13, 0x00000003>;
    using psize = FieldModel<address, 11, 0x00000003>;
    using minc = FieldModel<address, 10, 0x00000001>;
    using pinc = FieldModel<address, 9, 0x00000001>;
    using circ = FieldModel<address, 8, 0x00000001>;
    using dir = FieldModel<address, 6, 0x00000003>;
    using pfctrl = FieldModel<address, 5, 0x00000001>;
    using tcie = FieldModel<address, 4, 0x00000001>;
    using htie = FieldModel<address, 3, 0x00000001>;
    using teie = FieldModel<address, 2, 0x00000001>;
    using dmeie = FieldModel<address, 1, 0x00000001>;
    using en = FieldModel<address, 0, 0x00000001>;
  };

public:
  using s5cr = S5crReg<BaseAddress + 0x0088>;

private:
  template <uint32_t address>
  class S5ndtrReg: public RegisterModel<address>
  {
  public:
    using ndt = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using s5ndtr = S5ndtrReg<BaseAddress + 0x008C>;

private:
  template <uint32_t address>
  class S5parReg: public RegisterModel<address>
  {
  public:
    using pa = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s5par = S5parReg<BaseAddress + 0x0090>;

private:
  template <uint32_t address>
  class S5m0arReg: public RegisterModel<address>
  {
  public:
    using m0a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s5m0ar = S5m0arReg<BaseAddress + 0x0094>;

private:
  template <uint32_t address>
  class S5m1arReg: public RegisterModel<address>
  {
  public:
    using m1a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s5m1ar = S5m1arReg<BaseAddress + 0x0098>;

private:
  template <uint32_t address>
  class S5fcrReg: public RegisterModel<address>
  {
  public:
    using feie = FieldModel<address, 7, 0x00000001>;
    using fs = FieldModel<address, 3, 0x00000007>;
    using dmdis = FieldModel<address, 2, 0x00000001>;
    using fth = FieldModel<address, 0, 0x00000003>;
  };

public:
  using s5fcr = S5fcrReg<BaseAddress + 0x009C>;

private:
  template <uint32_t address>
  class S6crReg: public RegisterModel<address>
  {
  public:
    using chsel = FieldModel<address, 25, 0x00000007>;
    using mburst = FieldModel<address, 23, 0x00000003>;
    using pburst = FieldModel<address, 21, 0x00000003>;
    using ack = FieldModel<address, 20, 0x00000001>;
    using ct = FieldModel<address, 19, 0x00000001>;
    using dbm = FieldModel<address, 18, 0x00000001>;
    using pl = FieldModel<address, 16, 0x00000003>;
    using pincos = FieldModel<address, 15, 0x00000001>;
    using msize = FieldModel<address, 13, 0x00000003>;
    using psize = FieldModel<address, 11, 0x00000003>;
    using minc = FieldModel<address, 10, 0x00000001>;
    using pinc = FieldModel<address, 9, 0x00000001>;
    using circ = FieldModel<address, 8, 0x00000001>;
    using dir = FieldModel<address, 6, 0x00000003>;
    using pfctrl = FieldModel<address, 5, 0x00000001>;
    using tcie = FieldModel<address, 4, 0x00000001>;
    using htie = FieldModel<address, 3, 0x00000001>;
    using teie = FieldModel<address, 2, 0x00000001>;
    using dmeie = FieldModel<address, 1, 0x00000001>;
    using en = FieldModel<address, 0, 0x00000001>;
  };

public:
  using s6cr = S6crReg<BaseAddress + 0x00A0>;

private:
  template <uint32_t address>
  class S6ndtrReg: public RegisterModel<address>
  {
  public:
    using ndt = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using s6ndtr = S6ndtrReg<BaseAddress + 0x00A4>;

private:
  template <uint32_t address>
  class S6parReg: public RegisterModel<address>
  {
  public:
    using pa = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s6par = S6parReg<BaseAddress + 0x00A8>;

private:
  template <uint32_t address>
  class S6m0arReg: public RegisterModel<address>
  {
  public:
    using m0a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s6m0ar = S6m0arReg<BaseAddress + 0x00AC>;

private:
  template <uint32_t address>
  class S6m1arReg: public RegisterModel<address>
  {
  public:
    using m1a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s6m1ar = S6m1arReg<BaseAddress + 0x00B0>;

private:
  template <uint32_t address>
  class S6fcrReg: public RegisterModel<address>
  {
  public:
    using feie = FieldModel<address, 7, 0x00000001>;
    using fs = FieldModel<address, 3, 0x00000007>;
    using dmdis = FieldModel<address, 2, 0x00000001>;
    using fth = FieldModel<address, 0, 0x00000003>;
  };

public:
  using s6fcr = S6fcrReg<BaseAddress + 0x00B4>;

private:
  template <uint32_t address>
  class S7crReg: public RegisterModel<address>
  {
  public:
    using chsel = FieldModel<address, 25, 0x00000007>;
    using mburst = FieldModel<address, 23, 0x00000003>;
    using pburst = FieldModel<address, 21, 0x00000003>;
    using ack = FieldModel<address, 20, 0x00000001>;
    using ct = FieldModel<address, 19, 0x00000001>;
    using dbm = FieldModel<address, 18, 0x00000001>;
    using pl = FieldModel<address, 16, 0x00000003>;
    using pincos = FieldModel<address, 15, 0x00000001>;
    using msize = FieldModel<address, 13, 0x00000003>;
    using psize = FieldModel<address, 11, 0x00000003>;
    using minc = FieldModel<address, 10, 0x00000001>;
    using pinc = FieldModel<address, 9, 0x00000001>;
    using circ = FieldModel<address, 8, 0x00000001>;
    using dir = FieldModel<address, 6, 0x00000003>;
    using pfctrl = FieldModel<address, 5, 0x00000001>;
    using tcie = FieldModel<address, 4, 0x00000001>;
    using htie = FieldModel<address, 3, 0x00000001>;
    using teie = FieldModel<address, 2, 0x00000001>;
    using dmeie = FieldModel<address, 1, 0x00000001>;
    using en = FieldModel<address, 0, 0x00000001>;
  };

public:
  using s7cr = S7crReg<BaseAddress + 0x00B8>;

private:
  template <uint32_t address>
  class S7ndtrReg: public RegisterModel<address>
  {
  public:
    using ndt = FieldModel<address, 0, 0x0000FFFF>;
  };

public:
  using s7ndtr = S7ndtrReg<BaseAddress + 0x00BC>;

private:
  template <uint32_t address>
  class S7parReg: public RegisterModel<address>
  {
  public:
    using pa = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s7par = S7parReg<BaseAddress + 0x00C0>;

private:
  template <uint32_t address>
  class S7m0arReg: public RegisterModel<address>
  {
  public:
    using m0a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s7m0ar = S7m0arReg<BaseAddress + 0x00C4>;

private:
  template <uint32_t address>
  class S7m1arReg: public RegisterModel<address>
  {
  public:
    using m1a = FieldModel<address, 0, 0xFFFFFFFF>;
  };

public:
  using s7m1ar = S7m1arReg<BaseAddress + 0x00C8>;

private:
  template <uint32_t address>
  class S7fcrReg: public RegisterModel<address>
  {
  public:
    using feie = FieldModel<address, 7, 0x00000001>;
    using fs = FieldModel<address, 3, 0x00000007>;
    using dmdis = FieldModel<address, 2, 0x00000001>;
    using fth = FieldModel<address, 0, 0x00000003>;
  };

public:
  using s7fcr = S7fcrReg<BaseAddress + 0x00CC>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class SxndtrBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using ndt = FieldModel<address, 0, 0x0000FFFF, bankOffset>;
  };

public:
  using sxndtr = SxndtrBankReg<BaseAddress + 0x0014, 0x0018>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class SxparBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using pa = FieldModel<address, 0, 0xFFFFFFFF, bankOffset>;
  };

public:
  using sxpar = SxparBankReg<BaseAddress + 0x0018, 0x0018>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class Sxm0arBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using m0a = FieldModel<address, 0, 0xFFFFFFFF, bankOffset>;
  };

public:
  using sxm0ar = Sxm0arBankReg<BaseAddress + 0x001C, 0x0018>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class Sxm1arBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using m1a = FieldModel<address, 0, 0xFFFFFFFF, bankOffset>;
  };

public:
  using sxm1ar = Sxm1arBankReg<BaseAddress + 0x0020, 0x0018>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class SxfcrBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using feie = FieldModel<address, 7, 0x00000001, bankOffset>;
    using fs = FieldModel<address, 3, 0x00000007, bankOffset>;
    using dmdis = FieldModel<address, 2, 0x00000001, bankOffset>;
    using fth = FieldModel<address, 0, 0x00000003, bankOffset>;
  };

public:
  using sxfcr = SxfcrBankReg<BaseAddress + 0x0024, 0x0018>;

private:
  template <uint32_t address, uint32_t bankOffset>
  class SxcrBankReg: public RegisterBankModel<address, bankOffset>
  {
  public:
    using chsel = FieldModel<address, 25, 0x00000007, bankOffset>;
    using mburst = FieldModel<address, 23, 0x00000003, bankOffset>;
    using pburst = FieldModel<address, 21, 0x00000003, bankOffset>;
    using ack = FieldModel<address, 20, 0x00000001, bankOffset>;
    using ct = FieldModel<address, 19, 0x00000001, bankOffset>;
    using dbm = FieldModel<address, 18, 0x00000001, bankOffset>;
    using pl = FieldModel<address, 16, 0x00000003, bankOffset>;
    using pincos = FieldModel<address, 15, 0x00000001, bankOffset>;
    using msize = FieldModel<address, 13, 0x00000003, bankOffset>;
    using psize = FieldModel<address, 11, 0x00000003, bankOffset>;
    using minc = FieldModel<address, 10, 0x00000001, bankOffset>;
    using pinc = FieldModel<address, 9, 0x00000001, bankOffset>;
    using circ = FieldModel<address, 8, 0x00000001, bankOffset>;
    using dir = FieldModel<address, 6, 0x00000003, bankOffset>;
    using pfctrl = FieldModel<address, 5, 0x00000001, bankOffset>;
    using tcie = FieldModel<address, 4, 0x00000001, bankOffset>;
    using htie = FieldModel<address, 3, 0x00000001, bankOffset>;
    using teie = FieldModel<address, 2, 0x00000001, bankOffset>;
    using dmeie = FieldModel<address, 1, 0x00000001, bankOffset>;
    using en = FieldModel<address, 0, 0x00000001, bankOffset>;
  };

public:
  using sxcr = SxcrBankReg<BaseAddress + 0x0028, 0x0018>;
};

}

#endif /* DRAL_STM32F411_DMA2_H */
