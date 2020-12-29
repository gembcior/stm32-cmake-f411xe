#ifndef STM32_F411XE_CONST_GPIO_H
#define STM32_F411XE_CONST_GPIO_H

#include "../../reg_model/reg_model.h"
#include "../const/general.h"
#include "../const/gpio.h"

namespace stm32::gpio {
  namespace a {
    namespace moder {
      using moder0  = RegisterModel<GpioABase + Offset, Moder0Pos,  Moder0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder1  = RegisterModel<GpioABase + Offset, Moder1Pos,  Moder1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder2  = RegisterModel<GpioABase + Offset, Moder2Pos,  Moder2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder3  = RegisterModel<GpioABase + Offset, Moder3Pos,  Moder3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder4  = RegisterModel<GpioABase + Offset, Moder4Pos,  Moder4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder5  = RegisterModel<GpioABase + Offset, Moder5Pos,  Moder5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder6  = RegisterModel<GpioABase + Offset, Moder6Pos,  Moder6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder7  = RegisterModel<GpioABase + Offset, Moder7Pos,  Moder7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder8  = RegisterModel<GpioABase + Offset, Moder8Pos,  Moder8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder9  = RegisterModel<GpioABase + Offset, Moder9Pos,  Moder9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder10 = RegisterModel<GpioABase + Offset, Moder10Pos, Moder10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder11 = RegisterModel<GpioABase + Offset, Moder11Pos, Moder11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder12 = RegisterModel<GpioABase + Offset, Moder12Pos, Moder12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder13 = RegisterModel<GpioABase + Offset, Moder13Pos, Moder13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder14 = RegisterModel<GpioABase + Offset, Moder14Pos, Moder14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder15 = RegisterModel<GpioABase + Offset, Moder15Pos, Moder15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace otyper {
      using ot0  = RegisterModel<GpioABase + Offset, Ot0Pos,  Ot0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot1  = RegisterModel<GpioABase + Offset, Ot1Pos,  Ot1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot2  = RegisterModel<GpioABase + Offset, Ot2Pos,  Ot2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot3  = RegisterModel<GpioABase + Offset, Ot3Pos,  Ot3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot4  = RegisterModel<GpioABase + Offset, Ot4Pos,  Ot4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot5  = RegisterModel<GpioABase + Offset, Ot5Pos,  Ot5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot6  = RegisterModel<GpioABase + Offset, Ot6Pos,  Ot6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot7  = RegisterModel<GpioABase + Offset, Ot7Pos,  Ot7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot8  = RegisterModel<GpioABase + Offset, Ot8Pos,  Ot8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot9  = RegisterModel<GpioABase + Offset, Ot9Pos,  Ot9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot10 = RegisterModel<GpioABase + Offset, Ot10Pos, Ot10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot11 = RegisterModel<GpioABase + Offset, Ot11Pos, Ot11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot12 = RegisterModel<GpioABase + Offset, Ot12Pos, Ot12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot13 = RegisterModel<GpioABase + Offset, Ot13Pos, Ot13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot14 = RegisterModel<GpioABase + Offset, Ot14Pos, Ot14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot15 = RegisterModel<GpioABase + Offset, Ot15Pos, Ot15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace ospeedr {
      using ospeed0  = RegisterModel<GpioABase + Offset, Ospeed0Pos,  Ospeed0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed1  = RegisterModel<GpioABase + Offset, Ospeed1Pos,  Ospeed1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed2  = RegisterModel<GpioABase + Offset, Ospeed2Pos,  Ospeed2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed3  = RegisterModel<GpioABase + Offset, Ospeed3Pos,  Ospeed3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed4  = RegisterModel<GpioABase + Offset, Ospeed4Pos,  Ospeed4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed5  = RegisterModel<GpioABase + Offset, Ospeed5Pos,  Ospeed5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed6  = RegisterModel<GpioABase + Offset, Ospeed6Pos,  Ospeed6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed7  = RegisterModel<GpioABase + Offset, Ospeed7Pos,  Ospeed7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed8  = RegisterModel<GpioABase + Offset, Ospeed8Pos,  Ospeed8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed9  = RegisterModel<GpioABase + Offset, Ospeed9Pos,  Ospeed9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed10 = RegisterModel<GpioABase + Offset, Ospeed10Pos, Ospeed10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed11 = RegisterModel<GpioABase + Offset, Ospeed11Pos, Ospeed11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed12 = RegisterModel<GpioABase + Offset, Ospeed12Pos, Ospeed12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed13 = RegisterModel<GpioABase + Offset, Ospeed13Pos, Ospeed13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed14 = RegisterModel<GpioABase + Offset, Ospeed14Pos, Ospeed14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed15 = RegisterModel<GpioABase + Offset, Ospeed15Pos, Ospeed15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace pupdr {
      using pupd0  = RegisterModel<GpioABase + Offset, Pupd0Pos,  Pupd0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd1  = RegisterModel<GpioABase + Offset, Pupd1Pos,  Pupd1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd2  = RegisterModel<GpioABase + Offset, Pupd2Pos,  Pupd2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd3  = RegisterModel<GpioABase + Offset, Pupd3Pos,  Pupd3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd4  = RegisterModel<GpioABase + Offset, Pupd4Pos,  Pupd4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd5  = RegisterModel<GpioABase + Offset, Pupd5Pos,  Pupd5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd6  = RegisterModel<GpioABase + Offset, Pupd6Pos,  Pupd6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd7  = RegisterModel<GpioABase + Offset, Pupd7Pos,  Pupd7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd8  = RegisterModel<GpioABase + Offset, Pupd8Pos,  Pupd8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd9  = RegisterModel<GpioABase + Offset, Pupd9Pos,  Pupd9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd10 = RegisterModel<GpioABase + Offset, Pupd10Pos, Pupd10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd11 = RegisterModel<GpioABase + Offset, Pupd11Pos, Pupd11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd12 = RegisterModel<GpioABase + Offset, Pupd12Pos, Pupd12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd13 = RegisterModel<GpioABase + Offset, Pupd13Pos, Pupd13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd14 = RegisterModel<GpioABase + Offset, Pupd14Pos, Pupd14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd15 = RegisterModel<GpioABase + Offset, Pupd15Pos, Pupd15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace idr {
      using id0  = RegisterModel<GpioABase + Offset, Id0Pos,  Id0Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id1  = RegisterModel<GpioABase + Offset, Id1Pos,  Id1Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id2  = RegisterModel<GpioABase + Offset, Id2Pos,  Id2Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id3  = RegisterModel<GpioABase + Offset, Id3Pos,  Id3Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id4  = RegisterModel<GpioABase + Offset, Id4Pos,  Id4Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id5  = RegisterModel<GpioABase + Offset, Id5Pos,  Id5Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id6  = RegisterModel<GpioABase + Offset, Id6Pos,  Id6Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id7  = RegisterModel<GpioABase + Offset, Id7Pos,  Id7Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id8  = RegisterModel<GpioABase + Offset, Id8Pos,  Id8Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id9  = RegisterModel<GpioABase + Offset, Id9Pos,  Id9Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id10 = RegisterModel<GpioABase + Offset, Id10Pos, Id10Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id11 = RegisterModel<GpioABase + Offset, Id11Pos, Id11Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id12 = RegisterModel<GpioABase + Offset, Id12Pos, Id12Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id13 = RegisterModel<GpioABase + Offset, Id13Pos, Id13Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id14 = RegisterModel<GpioABase + Offset, Id14Pos, Id14Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id15 = RegisterModel<GpioABase + Offset, Id15Pos, Id15Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
    }

    namespace odr {
      using od0  = RegisterModel<GpioABase + Offset, Od0Pos,  Od0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od1  = RegisterModel<GpioABase + Offset, Od1Pos,  Od1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od2  = RegisterModel<GpioABase + Offset, Od2Pos,  Od2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od3  = RegisterModel<GpioABase + Offset, Od3Pos,  Od3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od4  = RegisterModel<GpioABase + Offset, Od4Pos,  Od4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od5  = RegisterModel<GpioABase + Offset, Od5Pos,  Od5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od6  = RegisterModel<GpioABase + Offset, Od6Pos,  Od6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od7  = RegisterModel<GpioABase + Offset, Od7Pos,  Od7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od8  = RegisterModel<GpioABase + Offset, Od8Pos,  Od8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od9  = RegisterModel<GpioABase + Offset, Od9Pos,  Od9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od10 = RegisterModel<GpioABase + Offset, Od10Pos, Od10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od11 = RegisterModel<GpioABase + Offset, Od11Pos, Od11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od12 = RegisterModel<GpioABase + Offset, Od12Pos, Od12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od13 = RegisterModel<GpioABase + Offset, Od13Pos, Od13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od14 = RegisterModel<GpioABase + Offset, Od14Pos, Od14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od15 = RegisterModel<GpioABase + Offset, Od15Pos, Od15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace bsrr {
      using bs0  = RegisterModel<GpioABase + Offset, Bs0Pos,  Bs0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs1  = RegisterModel<GpioABase + Offset, Bs1Pos,  Bs1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs2  = RegisterModel<GpioABase + Offset, Bs2Pos,  Bs2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs3  = RegisterModel<GpioABase + Offset, Bs3Pos,  Bs3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs4  = RegisterModel<GpioABase + Offset, Bs4Pos,  Bs4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs5  = RegisterModel<GpioABase + Offset, Bs5Pos,  Bs5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs6  = RegisterModel<GpioABase + Offset, Bs6Pos,  Bs6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs7  = RegisterModel<GpioABase + Offset, Bs7Pos,  Bs7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs8  = RegisterModel<GpioABase + Offset, Bs8Pos,  Bs8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs9  = RegisterModel<GpioABase + Offset, Bs9Pos,  Bs9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs10 = RegisterModel<GpioABase + Offset, Bs10Pos, Bs10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs11 = RegisterModel<GpioABase + Offset, Bs11Pos, Bs11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs12 = RegisterModel<GpioABase + Offset, Bs12Pos, Bs12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs13 = RegisterModel<GpioABase + Offset, Bs13Pos, Bs13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs14 = RegisterModel<GpioABase + Offset, Bs14Pos, Bs14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs15 = RegisterModel<GpioABase + Offset, Bs15Pos, Bs15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br0  = RegisterModel<GpioABase + Offset, Br0Pos,  Br0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br1  = RegisterModel<GpioABase + Offset, Br1Pos,  Br1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br2  = RegisterModel<GpioABase + Offset, Br2Pos,  Br2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br3  = RegisterModel<GpioABase + Offset, Br3Pos,  Br3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br4  = RegisterModel<GpioABase + Offset, Br4Pos,  Br4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br5  = RegisterModel<GpioABase + Offset, Br5Pos,  Br5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br6  = RegisterModel<GpioABase + Offset, Br6Pos,  Br6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br7  = RegisterModel<GpioABase + Offset, Br7Pos,  Br7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br8  = RegisterModel<GpioABase + Offset, Br8Pos,  Br8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br9  = RegisterModel<GpioABase + Offset, Br9Pos,  Br9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br10 = RegisterModel<GpioABase + Offset, Br10Pos, Br10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br11 = RegisterModel<GpioABase + Offset, Br11Pos, Br11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br12 = RegisterModel<GpioABase + Offset, Br12Pos, Br12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br13 = RegisterModel<GpioABase + Offset, Br13Pos, Br13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br14 = RegisterModel<GpioABase + Offset, Br14Pos, Br14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br15 = RegisterModel<GpioABase + Offset, Br15Pos, Br15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
    }

    namespace lckr {
      using lck0  = RegisterModel<GpioABase + Offset, Lck0Pos,  Lck0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck1  = RegisterModel<GpioABase + Offset, Lck1Pos,  Lck1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck2  = RegisterModel<GpioABase + Offset, Lck2Pos,  Lck2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck3  = RegisterModel<GpioABase + Offset, Lck3Pos,  Lck3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck4  = RegisterModel<GpioABase + Offset, Lck4Pos,  Lck4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck5  = RegisterModel<GpioABase + Offset, Lck5Pos,  Lck5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck6  = RegisterModel<GpioABase + Offset, Lck6Pos,  Lck6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck7  = RegisterModel<GpioABase + Offset, Lck7Pos,  Lck7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck8  = RegisterModel<GpioABase + Offset, Lck8Pos,  Lck8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck9  = RegisterModel<GpioABase + Offset, Lck9Pos,  Lck9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck10 = RegisterModel<GpioABase + Offset, Lck10Pos, Lck10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck11 = RegisterModel<GpioABase + Offset, Lck11Pos, Lck11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck12 = RegisterModel<GpioABase + Offset, Lck12Pos, Lck12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck13 = RegisterModel<GpioABase + Offset, Lck13Pos, Lck13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck14 = RegisterModel<GpioABase + Offset, Lck14Pos, Lck14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck15 = RegisterModel<GpioABase + Offset, Lck15Pos, Lck15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lckk  = RegisterModel<GpioABase + Offset, LckkPos,  LckkMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrl {
      using afsel0 = RegisterModel<GpioABase + Offset, Afsel0Pos, Afsel0Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel1 = RegisterModel<GpioABase + Offset, Afsel1Pos, Afsel1Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel2 = RegisterModel<GpioABase + Offset, Afsel2Pos, Afsel2Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel3 = RegisterModel<GpioABase + Offset, Afsel3Pos, Afsel3Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel4 = RegisterModel<GpioABase + Offset, Afsel4Pos, Afsel4Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel5 = RegisterModel<GpioABase + Offset, Afsel5Pos, Afsel5Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel6 = RegisterModel<GpioABase + Offset, Afsel6Pos, Afsel6Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel7 = RegisterModel<GpioABase + Offset, Afsel7Pos, Afsel7Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrh {
      using afsel8  = RegisterModel<GpioABase + Offset, Afsel8Pos,  Afsel8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel9  = RegisterModel<GpioABase + Offset, Afsel9Pos,  Afsel9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel10 = RegisterModel<GpioABase + Offset, Afsel10Pos, Afsel10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel11 = RegisterModel<GpioABase + Offset, Afsel11Pos, Afsel11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel12 = RegisterModel<GpioABase + Offset, Afsel12Pos, Afsel12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel13 = RegisterModel<GpioABase + Offset, Afsel13Pos, Afsel13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel14 = RegisterModel<GpioABase + Offset, Afsel14Pos, Afsel14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel15 = RegisterModel<GpioABase + Offset, Afsel15Pos, Afsel15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }
  }

  namespace b {
    namespace moder {
      using moder0  = RegisterModel<GpioBBase + Offset, Moder0Pos,  Moder0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder1  = RegisterModel<GpioBBase + Offset, Moder1Pos,  Moder1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder2  = RegisterModel<GpioBBase + Offset, Moder2Pos,  Moder2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder3  = RegisterModel<GpioBBase + Offset, Moder3Pos,  Moder3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder4  = RegisterModel<GpioBBase + Offset, Moder4Pos,  Moder4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder5  = RegisterModel<GpioBBase + Offset, Moder5Pos,  Moder5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder6  = RegisterModel<GpioBBase + Offset, Moder6Pos,  Moder6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder7  = RegisterModel<GpioBBase + Offset, Moder7Pos,  Moder7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder8  = RegisterModel<GpioBBase + Offset, Moder8Pos,  Moder8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder9  = RegisterModel<GpioBBase + Offset, Moder9Pos,  Moder9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder10 = RegisterModel<GpioBBase + Offset, Moder10Pos, Moder10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder11 = RegisterModel<GpioBBase + Offset, Moder11Pos, Moder11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder12 = RegisterModel<GpioBBase + Offset, Moder12Pos, Moder12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder13 = RegisterModel<GpioBBase + Offset, Moder13Pos, Moder13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder14 = RegisterModel<GpioBBase + Offset, Moder14Pos, Moder14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder15 = RegisterModel<GpioBBase + Offset, Moder15Pos, Moder15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace otyper {
      using ot0  = RegisterModel<GpioBBase + Offset, Ot0Pos,  Ot0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot1  = RegisterModel<GpioBBase + Offset, Ot1Pos,  Ot1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot2  = RegisterModel<GpioBBase + Offset, Ot2Pos,  Ot2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot3  = RegisterModel<GpioBBase + Offset, Ot3Pos,  Ot3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot4  = RegisterModel<GpioBBase + Offset, Ot4Pos,  Ot4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot5  = RegisterModel<GpioBBase + Offset, Ot5Pos,  Ot5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot6  = RegisterModel<GpioBBase + Offset, Ot6Pos,  Ot6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot7  = RegisterModel<GpioBBase + Offset, Ot7Pos,  Ot7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot8  = RegisterModel<GpioBBase + Offset, Ot8Pos,  Ot8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot9  = RegisterModel<GpioBBase + Offset, Ot9Pos,  Ot9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot10 = RegisterModel<GpioBBase + Offset, Ot10Pos, Ot10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot11 = RegisterModel<GpioBBase + Offset, Ot11Pos, Ot11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot12 = RegisterModel<GpioBBase + Offset, Ot12Pos, Ot12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot13 = RegisterModel<GpioBBase + Offset, Ot13Pos, Ot13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot14 = RegisterModel<GpioBBase + Offset, Ot14Pos, Ot14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot15 = RegisterModel<GpioBBase + Offset, Ot15Pos, Ot15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace ospeedr {
      using ospeed0  = RegisterModel<GpioBBase + Offset, Ospeed0Pos,  Ospeed0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed1  = RegisterModel<GpioBBase + Offset, Ospeed1Pos,  Ospeed1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed2  = RegisterModel<GpioBBase + Offset, Ospeed2Pos,  Ospeed2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed3  = RegisterModel<GpioBBase + Offset, Ospeed3Pos,  Ospeed3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed4  = RegisterModel<GpioBBase + Offset, Ospeed4Pos,  Ospeed4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed5  = RegisterModel<GpioBBase + Offset, Ospeed5Pos,  Ospeed5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed6  = RegisterModel<GpioBBase + Offset, Ospeed6Pos,  Ospeed6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed7  = RegisterModel<GpioBBase + Offset, Ospeed7Pos,  Ospeed7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed8  = RegisterModel<GpioBBase + Offset, Ospeed8Pos,  Ospeed8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed9  = RegisterModel<GpioBBase + Offset, Ospeed9Pos,  Ospeed9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed10 = RegisterModel<GpioBBase + Offset, Ospeed10Pos, Ospeed10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed11 = RegisterModel<GpioBBase + Offset, Ospeed11Pos, Ospeed11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed12 = RegisterModel<GpioBBase + Offset, Ospeed12Pos, Ospeed12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed13 = RegisterModel<GpioBBase + Offset, Ospeed13Pos, Ospeed13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed14 = RegisterModel<GpioBBase + Offset, Ospeed14Pos, Ospeed14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed15 = RegisterModel<GpioBBase + Offset, Ospeed15Pos, Ospeed15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace pupdr {
      using pupd0  = RegisterModel<GpioBBase + Offset, Pupd0Pos,  Pupd0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd1  = RegisterModel<GpioBBase + Offset, Pupd1Pos,  Pupd1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd2  = RegisterModel<GpioBBase + Offset, Pupd2Pos,  Pupd2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd3  = RegisterModel<GpioBBase + Offset, Pupd3Pos,  Pupd3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd4  = RegisterModel<GpioBBase + Offset, Pupd4Pos,  Pupd4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd5  = RegisterModel<GpioBBase + Offset, Pupd5Pos,  Pupd5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd6  = RegisterModel<GpioBBase + Offset, Pupd6Pos,  Pupd6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd7  = RegisterModel<GpioBBase + Offset, Pupd7Pos,  Pupd7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd8  = RegisterModel<GpioBBase + Offset, Pupd8Pos,  Pupd8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd9  = RegisterModel<GpioBBase + Offset, Pupd9Pos,  Pupd9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd10 = RegisterModel<GpioBBase + Offset, Pupd10Pos, Pupd10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd11 = RegisterModel<GpioBBase + Offset, Pupd11Pos, Pupd11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd12 = RegisterModel<GpioBBase + Offset, Pupd12Pos, Pupd12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd13 = RegisterModel<GpioBBase + Offset, Pupd13Pos, Pupd13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd14 = RegisterModel<GpioBBase + Offset, Pupd14Pos, Pupd14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd15 = RegisterModel<GpioBBase + Offset, Pupd15Pos, Pupd15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace idr {
      using id0  = RegisterModel<GpioBBase + Offset, Id0Pos,  Id0Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id1  = RegisterModel<GpioBBase + Offset, Id1Pos,  Id1Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id2  = RegisterModel<GpioBBase + Offset, Id2Pos,  Id2Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id3  = RegisterModel<GpioBBase + Offset, Id3Pos,  Id3Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id4  = RegisterModel<GpioBBase + Offset, Id4Pos,  Id4Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id5  = RegisterModel<GpioBBase + Offset, Id5Pos,  Id5Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id6  = RegisterModel<GpioBBase + Offset, Id6Pos,  Id6Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id7  = RegisterModel<GpioBBase + Offset, Id7Pos,  Id7Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id8  = RegisterModel<GpioBBase + Offset, Id8Pos,  Id8Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id9  = RegisterModel<GpioBBase + Offset, Id9Pos,  Id9Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id10 = RegisterModel<GpioBBase + Offset, Id10Pos, Id10Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id11 = RegisterModel<GpioBBase + Offset, Id11Pos, Id11Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id12 = RegisterModel<GpioBBase + Offset, Id12Pos, Id12Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id13 = RegisterModel<GpioBBase + Offset, Id13Pos, Id13Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id14 = RegisterModel<GpioBBase + Offset, Id14Pos, Id14Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id15 = RegisterModel<GpioBBase + Offset, Id15Pos, Id15Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
    }

    namespace odr {
      using od0  = RegisterModel<GpioBBase + Offset, Od0Pos,  Od0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od1  = RegisterModel<GpioBBase + Offset, Od1Pos,  Od1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od2  = RegisterModel<GpioBBase + Offset, Od2Pos,  Od2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od3  = RegisterModel<GpioBBase + Offset, Od3Pos,  Od3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od4  = RegisterModel<GpioBBase + Offset, Od4Pos,  Od4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od5  = RegisterModel<GpioBBase + Offset, Od5Pos,  Od5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od6  = RegisterModel<GpioBBase + Offset, Od6Pos,  Od6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od7  = RegisterModel<GpioBBase + Offset, Od7Pos,  Od7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od8  = RegisterModel<GpioBBase + Offset, Od8Pos,  Od8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od9  = RegisterModel<GpioBBase + Offset, Od9Pos,  Od9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od10 = RegisterModel<GpioBBase + Offset, Od10Pos, Od10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od11 = RegisterModel<GpioBBase + Offset, Od11Pos, Od11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od12 = RegisterModel<GpioBBase + Offset, Od12Pos, Od12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od13 = RegisterModel<GpioBBase + Offset, Od13Pos, Od13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od14 = RegisterModel<GpioBBase + Offset, Od14Pos, Od14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od15 = RegisterModel<GpioBBase + Offset, Od15Pos, Od15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace bsrr {
      using bs0  = RegisterModel<GpioBBase + Offset, Bs0Pos,  Bs0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs1  = RegisterModel<GpioBBase + Offset, Bs1Pos,  Bs1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs2  = RegisterModel<GpioBBase + Offset, Bs2Pos,  Bs2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs3  = RegisterModel<GpioBBase + Offset, Bs3Pos,  Bs3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs4  = RegisterModel<GpioBBase + Offset, Bs4Pos,  Bs4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs5  = RegisterModel<GpioBBase + Offset, Bs5Pos,  Bs5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs6  = RegisterModel<GpioBBase + Offset, Bs6Pos,  Bs6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs7  = RegisterModel<GpioBBase + Offset, Bs7Pos,  Bs7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs8  = RegisterModel<GpioBBase + Offset, Bs8Pos,  Bs8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs9  = RegisterModel<GpioBBase + Offset, Bs9Pos,  Bs9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs10 = RegisterModel<GpioBBase + Offset, Bs10Pos, Bs10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs11 = RegisterModel<GpioBBase + Offset, Bs11Pos, Bs11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs12 = RegisterModel<GpioBBase + Offset, Bs12Pos, Bs12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs13 = RegisterModel<GpioBBase + Offset, Bs13Pos, Bs13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs14 = RegisterModel<GpioBBase + Offset, Bs14Pos, Bs14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs15 = RegisterModel<GpioBBase + Offset, Bs15Pos, Bs15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br0  = RegisterModel<GpioBBase + Offset, Br0Pos,  Br0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br1  = RegisterModel<GpioBBase + Offset, Br1Pos,  Br1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br2  = RegisterModel<GpioBBase + Offset, Br2Pos,  Br2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br3  = RegisterModel<GpioBBase + Offset, Br3Pos,  Br3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br4  = RegisterModel<GpioBBase + Offset, Br4Pos,  Br4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br5  = RegisterModel<GpioBBase + Offset, Br5Pos,  Br5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br6  = RegisterModel<GpioBBase + Offset, Br6Pos,  Br6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br7  = RegisterModel<GpioBBase + Offset, Br7Pos,  Br7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br8  = RegisterModel<GpioBBase + Offset, Br8Pos,  Br8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br9  = RegisterModel<GpioBBase + Offset, Br9Pos,  Br9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br10 = RegisterModel<GpioBBase + Offset, Br10Pos, Br10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br11 = RegisterModel<GpioBBase + Offset, Br11Pos, Br11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br12 = RegisterModel<GpioBBase + Offset, Br12Pos, Br12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br13 = RegisterModel<GpioBBase + Offset, Br13Pos, Br13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br14 = RegisterModel<GpioBBase + Offset, Br14Pos, Br14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br15 = RegisterModel<GpioBBase + Offset, Br15Pos, Br15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
    }

    namespace lckr {
      using lck0  = RegisterModel<GpioBBase + Offset, Lck0Pos,  Lck0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck1  = RegisterModel<GpioBBase + Offset, Lck1Pos,  Lck1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck2  = RegisterModel<GpioBBase + Offset, Lck2Pos,  Lck2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck3  = RegisterModel<GpioBBase + Offset, Lck3Pos,  Lck3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck4  = RegisterModel<GpioBBase + Offset, Lck4Pos,  Lck4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck5  = RegisterModel<GpioBBase + Offset, Lck5Pos,  Lck5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck6  = RegisterModel<GpioBBase + Offset, Lck6Pos,  Lck6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck7  = RegisterModel<GpioBBase + Offset, Lck7Pos,  Lck7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck8  = RegisterModel<GpioBBase + Offset, Lck8Pos,  Lck8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck9  = RegisterModel<GpioBBase + Offset, Lck9Pos,  Lck9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck10 = RegisterModel<GpioBBase + Offset, Lck10Pos, Lck10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck11 = RegisterModel<GpioBBase + Offset, Lck11Pos, Lck11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck12 = RegisterModel<GpioBBase + Offset, Lck12Pos, Lck12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck13 = RegisterModel<GpioBBase + Offset, Lck13Pos, Lck13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck14 = RegisterModel<GpioBBase + Offset, Lck14Pos, Lck14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck15 = RegisterModel<GpioBBase + Offset, Lck15Pos, Lck15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lckk  = RegisterModel<GpioBBase + Offset, LckkPos,  LckkMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrl {
      using afsel0 = RegisterModel<GpioBBase + Offset, Afsel0Pos, Afsel0Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel1 = RegisterModel<GpioBBase + Offset, Afsel1Pos, Afsel1Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel2 = RegisterModel<GpioBBase + Offset, Afsel2Pos, Afsel2Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel3 = RegisterModel<GpioBBase + Offset, Afsel3Pos, Afsel3Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel4 = RegisterModel<GpioBBase + Offset, Afsel4Pos, Afsel4Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel5 = RegisterModel<GpioBBase + Offset, Afsel5Pos, Afsel5Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel6 = RegisterModel<GpioBBase + Offset, Afsel6Pos, Afsel6Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel7 = RegisterModel<GpioBBase + Offset, Afsel7Pos, Afsel7Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrh {
      using afsel8  = RegisterModel<GpioBBase + Offset, Afsel8Pos,  Afsel8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel9  = RegisterModel<GpioBBase + Offset, Afsel9Pos,  Afsel9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel10 = RegisterModel<GpioBBase + Offset, Afsel10Pos, Afsel10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel11 = RegisterModel<GpioBBase + Offset, Afsel11Pos, Afsel11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel12 = RegisterModel<GpioBBase + Offset, Afsel12Pos, Afsel12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel13 = RegisterModel<GpioBBase + Offset, Afsel13Pos, Afsel13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel14 = RegisterModel<GpioBBase + Offset, Afsel14Pos, Afsel14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel15 = RegisterModel<GpioBBase + Offset, Afsel15Pos, Afsel15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }
  }

  namespace c {
    namespace moder {
      using moder0  = RegisterModel<GpioCBase + Offset, Moder0Pos,  Moder0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder1  = RegisterModel<GpioCBase + Offset, Moder1Pos,  Moder1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder2  = RegisterModel<GpioCBase + Offset, Moder2Pos,  Moder2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder3  = RegisterModel<GpioCBase + Offset, Moder3Pos,  Moder3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder4  = RegisterModel<GpioCBase + Offset, Moder4Pos,  Moder4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder5  = RegisterModel<GpioCBase + Offset, Moder5Pos,  Moder5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder6  = RegisterModel<GpioCBase + Offset, Moder6Pos,  Moder6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder7  = RegisterModel<GpioCBase + Offset, Moder7Pos,  Moder7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder8  = RegisterModel<GpioCBase + Offset, Moder8Pos,  Moder8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder9  = RegisterModel<GpioCBase + Offset, Moder9Pos,  Moder9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder10 = RegisterModel<GpioCBase + Offset, Moder10Pos, Moder10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder11 = RegisterModel<GpioCBase + Offset, Moder11Pos, Moder11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder12 = RegisterModel<GpioCBase + Offset, Moder12Pos, Moder12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder13 = RegisterModel<GpioCBase + Offset, Moder13Pos, Moder13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder14 = RegisterModel<GpioCBase + Offset, Moder14Pos, Moder14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder15 = RegisterModel<GpioCBase + Offset, Moder15Pos, Moder15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace otyper {
      using ot0  = RegisterModel<GpioCBase + Offset, Ot0Pos,  Ot0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot1  = RegisterModel<GpioCBase + Offset, Ot1Pos,  Ot1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot2  = RegisterModel<GpioCBase + Offset, Ot2Pos,  Ot2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot3  = RegisterModel<GpioCBase + Offset, Ot3Pos,  Ot3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot4  = RegisterModel<GpioCBase + Offset, Ot4Pos,  Ot4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot5  = RegisterModel<GpioCBase + Offset, Ot5Pos,  Ot5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot6  = RegisterModel<GpioCBase + Offset, Ot6Pos,  Ot6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot7  = RegisterModel<GpioCBase + Offset, Ot7Pos,  Ot7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot8  = RegisterModel<GpioCBase + Offset, Ot8Pos,  Ot8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot9  = RegisterModel<GpioCBase + Offset, Ot9Pos,  Ot9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot10 = RegisterModel<GpioCBase + Offset, Ot10Pos, Ot10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot11 = RegisterModel<GpioCBase + Offset, Ot11Pos, Ot11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot12 = RegisterModel<GpioCBase + Offset, Ot12Pos, Ot12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot13 = RegisterModel<GpioCBase + Offset, Ot13Pos, Ot13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot14 = RegisterModel<GpioCBase + Offset, Ot14Pos, Ot14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot15 = RegisterModel<GpioCBase + Offset, Ot15Pos, Ot15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace ospeedr {
      using ospeed0  = RegisterModel<GpioCBase + Offset, Ospeed0Pos,  Ospeed0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed1  = RegisterModel<GpioCBase + Offset, Ospeed1Pos,  Ospeed1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed2  = RegisterModel<GpioCBase + Offset, Ospeed2Pos,  Ospeed2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed3  = RegisterModel<GpioCBase + Offset, Ospeed3Pos,  Ospeed3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed4  = RegisterModel<GpioCBase + Offset, Ospeed4Pos,  Ospeed4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed5  = RegisterModel<GpioCBase + Offset, Ospeed5Pos,  Ospeed5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed6  = RegisterModel<GpioCBase + Offset, Ospeed6Pos,  Ospeed6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed7  = RegisterModel<GpioCBase + Offset, Ospeed7Pos,  Ospeed7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed8  = RegisterModel<GpioCBase + Offset, Ospeed8Pos,  Ospeed8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed9  = RegisterModel<GpioCBase + Offset, Ospeed9Pos,  Ospeed9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed10 = RegisterModel<GpioCBase + Offset, Ospeed10Pos, Ospeed10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed11 = RegisterModel<GpioCBase + Offset, Ospeed11Pos, Ospeed11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed12 = RegisterModel<GpioCBase + Offset, Ospeed12Pos, Ospeed12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed13 = RegisterModel<GpioCBase + Offset, Ospeed13Pos, Ospeed13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed14 = RegisterModel<GpioCBase + Offset, Ospeed14Pos, Ospeed14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed15 = RegisterModel<GpioCBase + Offset, Ospeed15Pos, Ospeed15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace pupdr {
      using pupd0  = RegisterModel<GpioCBase + Offset, Pupd0Pos,  Pupd0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd1  = RegisterModel<GpioCBase + Offset, Pupd1Pos,  Pupd1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd2  = RegisterModel<GpioCBase + Offset, Pupd2Pos,  Pupd2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd3  = RegisterModel<GpioCBase + Offset, Pupd3Pos,  Pupd3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd4  = RegisterModel<GpioCBase + Offset, Pupd4Pos,  Pupd4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd5  = RegisterModel<GpioCBase + Offset, Pupd5Pos,  Pupd5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd6  = RegisterModel<GpioCBase + Offset, Pupd6Pos,  Pupd6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd7  = RegisterModel<GpioCBase + Offset, Pupd7Pos,  Pupd7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd8  = RegisterModel<GpioCBase + Offset, Pupd8Pos,  Pupd8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd9  = RegisterModel<GpioCBase + Offset, Pupd9Pos,  Pupd9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd10 = RegisterModel<GpioCBase + Offset, Pupd10Pos, Pupd10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd11 = RegisterModel<GpioCBase + Offset, Pupd11Pos, Pupd11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd12 = RegisterModel<GpioCBase + Offset, Pupd12Pos, Pupd12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd13 = RegisterModel<GpioCBase + Offset, Pupd13Pos, Pupd13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd14 = RegisterModel<GpioCBase + Offset, Pupd14Pos, Pupd14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd15 = RegisterModel<GpioCBase + Offset, Pupd15Pos, Pupd15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace idr {
      using id0  = RegisterModel<GpioCBase + Offset, Id0Pos,  Id0Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id1  = RegisterModel<GpioCBase + Offset, Id1Pos,  Id1Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id2  = RegisterModel<GpioCBase + Offset, Id2Pos,  Id2Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id3  = RegisterModel<GpioCBase + Offset, Id3Pos,  Id3Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id4  = RegisterModel<GpioCBase + Offset, Id4Pos,  Id4Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id5  = RegisterModel<GpioCBase + Offset, Id5Pos,  Id5Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id6  = RegisterModel<GpioCBase + Offset, Id6Pos,  Id6Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id7  = RegisterModel<GpioCBase + Offset, Id7Pos,  Id7Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id8  = RegisterModel<GpioCBase + Offset, Id8Pos,  Id8Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id9  = RegisterModel<GpioCBase + Offset, Id9Pos,  Id9Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id10 = RegisterModel<GpioCBase + Offset, Id10Pos, Id10Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id11 = RegisterModel<GpioCBase + Offset, Id11Pos, Id11Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id12 = RegisterModel<GpioCBase + Offset, Id12Pos, Id12Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id13 = RegisterModel<GpioCBase + Offset, Id13Pos, Id13Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id14 = RegisterModel<GpioCBase + Offset, Id14Pos, Id14Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id15 = RegisterModel<GpioCBase + Offset, Id15Pos, Id15Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
    }

    namespace odr {
      using od0  = RegisterModel<GpioCBase + Offset, Od0Pos,  Od0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od1  = RegisterModel<GpioCBase + Offset, Od1Pos,  Od1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od2  = RegisterModel<GpioCBase + Offset, Od2Pos,  Od2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od3  = RegisterModel<GpioCBase + Offset, Od3Pos,  Od3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od4  = RegisterModel<GpioCBase + Offset, Od4Pos,  Od4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od5  = RegisterModel<GpioCBase + Offset, Od5Pos,  Od5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od6  = RegisterModel<GpioCBase + Offset, Od6Pos,  Od6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od7  = RegisterModel<GpioCBase + Offset, Od7Pos,  Od7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od8  = RegisterModel<GpioCBase + Offset, Od8Pos,  Od8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od9  = RegisterModel<GpioCBase + Offset, Od9Pos,  Od9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od10 = RegisterModel<GpioCBase + Offset, Od10Pos, Od10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od11 = RegisterModel<GpioCBase + Offset, Od11Pos, Od11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od12 = RegisterModel<GpioCBase + Offset, Od12Pos, Od12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od13 = RegisterModel<GpioCBase + Offset, Od13Pos, Od13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od14 = RegisterModel<GpioCBase + Offset, Od14Pos, Od14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od15 = RegisterModel<GpioCBase + Offset, Od15Pos, Od15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace bsrr {
      using bs0  = RegisterModel<GpioCBase + Offset, Bs0Pos,  Bs0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs1  = RegisterModel<GpioCBase + Offset, Bs1Pos,  Bs1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs2  = RegisterModel<GpioCBase + Offset, Bs2Pos,  Bs2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs3  = RegisterModel<GpioCBase + Offset, Bs3Pos,  Bs3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs4  = RegisterModel<GpioCBase + Offset, Bs4Pos,  Bs4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs5  = RegisterModel<GpioCBase + Offset, Bs5Pos,  Bs5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs6  = RegisterModel<GpioCBase + Offset, Bs6Pos,  Bs6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs7  = RegisterModel<GpioCBase + Offset, Bs7Pos,  Bs7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs8  = RegisterModel<GpioCBase + Offset, Bs8Pos,  Bs8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs9  = RegisterModel<GpioCBase + Offset, Bs9Pos,  Bs9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs10 = RegisterModel<GpioCBase + Offset, Bs10Pos, Bs10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs11 = RegisterModel<GpioCBase + Offset, Bs11Pos, Bs11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs12 = RegisterModel<GpioCBase + Offset, Bs12Pos, Bs12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs13 = RegisterModel<GpioCBase + Offset, Bs13Pos, Bs13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs14 = RegisterModel<GpioCBase + Offset, Bs14Pos, Bs14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs15 = RegisterModel<GpioCBase + Offset, Bs15Pos, Bs15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br0  = RegisterModel<GpioCBase + Offset, Br0Pos,  Br0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br1  = RegisterModel<GpioCBase + Offset, Br1Pos,  Br1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br2  = RegisterModel<GpioCBase + Offset, Br2Pos,  Br2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br3  = RegisterModel<GpioCBase + Offset, Br3Pos,  Br3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br4  = RegisterModel<GpioCBase + Offset, Br4Pos,  Br4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br5  = RegisterModel<GpioCBase + Offset, Br5Pos,  Br5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br6  = RegisterModel<GpioCBase + Offset, Br6Pos,  Br6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br7  = RegisterModel<GpioCBase + Offset, Br7Pos,  Br7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br8  = RegisterModel<GpioCBase + Offset, Br8Pos,  Br8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br9  = RegisterModel<GpioCBase + Offset, Br9Pos,  Br9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br10 = RegisterModel<GpioCBase + Offset, Br10Pos, Br10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br11 = RegisterModel<GpioCBase + Offset, Br11Pos, Br11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br12 = RegisterModel<GpioCBase + Offset, Br12Pos, Br12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br13 = RegisterModel<GpioCBase + Offset, Br13Pos, Br13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br14 = RegisterModel<GpioCBase + Offset, Br14Pos, Br14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br15 = RegisterModel<GpioCBase + Offset, Br15Pos, Br15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
    }

    namespace lckr {
      using lck0  = RegisterModel<GpioCBase + Offset, Lck0Pos,  Lck0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck1  = RegisterModel<GpioCBase + Offset, Lck1Pos,  Lck1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck2  = RegisterModel<GpioCBase + Offset, Lck2Pos,  Lck2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck3  = RegisterModel<GpioCBase + Offset, Lck3Pos,  Lck3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck4  = RegisterModel<GpioCBase + Offset, Lck4Pos,  Lck4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck5  = RegisterModel<GpioCBase + Offset, Lck5Pos,  Lck5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck6  = RegisterModel<GpioCBase + Offset, Lck6Pos,  Lck6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck7  = RegisterModel<GpioCBase + Offset, Lck7Pos,  Lck7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck8  = RegisterModel<GpioCBase + Offset, Lck8Pos,  Lck8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck9  = RegisterModel<GpioCBase + Offset, Lck9Pos,  Lck9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck10 = RegisterModel<GpioCBase + Offset, Lck10Pos, Lck10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck11 = RegisterModel<GpioCBase + Offset, Lck11Pos, Lck11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck12 = RegisterModel<GpioCBase + Offset, Lck12Pos, Lck12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck13 = RegisterModel<GpioCBase + Offset, Lck13Pos, Lck13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck14 = RegisterModel<GpioCBase + Offset, Lck14Pos, Lck14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck15 = RegisterModel<GpioCBase + Offset, Lck15Pos, Lck15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lckk  = RegisterModel<GpioCBase + Offset, LckkPos,  LckkMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrl {
      using afsel0 = RegisterModel<GpioCBase + Offset, Afsel0Pos, Afsel0Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel1 = RegisterModel<GpioCBase + Offset, Afsel1Pos, Afsel1Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel2 = RegisterModel<GpioCBase + Offset, Afsel2Pos, Afsel2Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel3 = RegisterModel<GpioCBase + Offset, Afsel3Pos, Afsel3Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel4 = RegisterModel<GpioCBase + Offset, Afsel4Pos, Afsel4Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel5 = RegisterModel<GpioCBase + Offset, Afsel5Pos, Afsel5Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel6 = RegisterModel<GpioCBase + Offset, Afsel6Pos, Afsel6Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel7 = RegisterModel<GpioCBase + Offset, Afsel7Pos, Afsel7Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrh {
      using afsel8  = RegisterModel<GpioCBase + Offset, Afsel8Pos,  Afsel8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel9  = RegisterModel<GpioCBase + Offset, Afsel9Pos,  Afsel9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel10 = RegisterModel<GpioCBase + Offset, Afsel10Pos, Afsel10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel11 = RegisterModel<GpioCBase + Offset, Afsel11Pos, Afsel11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel12 = RegisterModel<GpioCBase + Offset, Afsel12Pos, Afsel12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel13 = RegisterModel<GpioCBase + Offset, Afsel13Pos, Afsel13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel14 = RegisterModel<GpioCBase + Offset, Afsel14Pos, Afsel14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel15 = RegisterModel<GpioCBase + Offset, Afsel15Pos, Afsel15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }
  }

  namespace d {
    namespace moder {
      using moder0  = RegisterModel<GpioDBase + Offset, Moder0Pos,  Moder0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder1  = RegisterModel<GpioDBase + Offset, Moder1Pos,  Moder1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder2  = RegisterModel<GpioDBase + Offset, Moder2Pos,  Moder2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder3  = RegisterModel<GpioDBase + Offset, Moder3Pos,  Moder3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder4  = RegisterModel<GpioDBase + Offset, Moder4Pos,  Moder4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder5  = RegisterModel<GpioDBase + Offset, Moder5Pos,  Moder5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder6  = RegisterModel<GpioDBase + Offset, Moder6Pos,  Moder6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder7  = RegisterModel<GpioDBase + Offset, Moder7Pos,  Moder7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder8  = RegisterModel<GpioDBase + Offset, Moder8Pos,  Moder8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder9  = RegisterModel<GpioDBase + Offset, Moder9Pos,  Moder9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder10 = RegisterModel<GpioDBase + Offset, Moder10Pos, Moder10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder11 = RegisterModel<GpioDBase + Offset, Moder11Pos, Moder11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder12 = RegisterModel<GpioDBase + Offset, Moder12Pos, Moder12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder13 = RegisterModel<GpioDBase + Offset, Moder13Pos, Moder13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder14 = RegisterModel<GpioDBase + Offset, Moder14Pos, Moder14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder15 = RegisterModel<GpioDBase + Offset, Moder15Pos, Moder15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace otyper {
      using ot0  = RegisterModel<GpioDBase + Offset, Ot0Pos,  Ot0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot1  = RegisterModel<GpioDBase + Offset, Ot1Pos,  Ot1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot2  = RegisterModel<GpioDBase + Offset, Ot2Pos,  Ot2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot3  = RegisterModel<GpioDBase + Offset, Ot3Pos,  Ot3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot4  = RegisterModel<GpioDBase + Offset, Ot4Pos,  Ot4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot5  = RegisterModel<GpioDBase + Offset, Ot5Pos,  Ot5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot6  = RegisterModel<GpioDBase + Offset, Ot6Pos,  Ot6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot7  = RegisterModel<GpioDBase + Offset, Ot7Pos,  Ot7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot8  = RegisterModel<GpioDBase + Offset, Ot8Pos,  Ot8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot9  = RegisterModel<GpioDBase + Offset, Ot9Pos,  Ot9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot10 = RegisterModel<GpioDBase + Offset, Ot10Pos, Ot10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot11 = RegisterModel<GpioDBase + Offset, Ot11Pos, Ot11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot12 = RegisterModel<GpioDBase + Offset, Ot12Pos, Ot12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot13 = RegisterModel<GpioDBase + Offset, Ot13Pos, Ot13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot14 = RegisterModel<GpioDBase + Offset, Ot14Pos, Ot14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot15 = RegisterModel<GpioDBase + Offset, Ot15Pos, Ot15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace ospeedr {
      using ospeed0  = RegisterModel<GpioDBase + Offset, Ospeed0Pos,  Ospeed0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed1  = RegisterModel<GpioDBase + Offset, Ospeed1Pos,  Ospeed1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed2  = RegisterModel<GpioDBase + Offset, Ospeed2Pos,  Ospeed2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed3  = RegisterModel<GpioDBase + Offset, Ospeed3Pos,  Ospeed3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed4  = RegisterModel<GpioDBase + Offset, Ospeed4Pos,  Ospeed4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed5  = RegisterModel<GpioDBase + Offset, Ospeed5Pos,  Ospeed5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed6  = RegisterModel<GpioDBase + Offset, Ospeed6Pos,  Ospeed6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed7  = RegisterModel<GpioDBase + Offset, Ospeed7Pos,  Ospeed7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed8  = RegisterModel<GpioDBase + Offset, Ospeed8Pos,  Ospeed8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed9  = RegisterModel<GpioDBase + Offset, Ospeed9Pos,  Ospeed9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed10 = RegisterModel<GpioDBase + Offset, Ospeed10Pos, Ospeed10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed11 = RegisterModel<GpioDBase + Offset, Ospeed11Pos, Ospeed11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed12 = RegisterModel<GpioDBase + Offset, Ospeed12Pos, Ospeed12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed13 = RegisterModel<GpioDBase + Offset, Ospeed13Pos, Ospeed13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed14 = RegisterModel<GpioDBase + Offset, Ospeed14Pos, Ospeed14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed15 = RegisterModel<GpioDBase + Offset, Ospeed15Pos, Ospeed15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace pupdr {
      using pupd0  = RegisterModel<GpioDBase + Offset, Pupd0Pos,  Pupd0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd1  = RegisterModel<GpioDBase + Offset, Pupd1Pos,  Pupd1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd2  = RegisterModel<GpioDBase + Offset, Pupd2Pos,  Pupd2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd3  = RegisterModel<GpioDBase + Offset, Pupd3Pos,  Pupd3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd4  = RegisterModel<GpioDBase + Offset, Pupd4Pos,  Pupd4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd5  = RegisterModel<GpioDBase + Offset, Pupd5Pos,  Pupd5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd6  = RegisterModel<GpioDBase + Offset, Pupd6Pos,  Pupd6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd7  = RegisterModel<GpioDBase + Offset, Pupd7Pos,  Pupd7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd8  = RegisterModel<GpioDBase + Offset, Pupd8Pos,  Pupd8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd9  = RegisterModel<GpioDBase + Offset, Pupd9Pos,  Pupd9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd10 = RegisterModel<GpioDBase + Offset, Pupd10Pos, Pupd10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd11 = RegisterModel<GpioDBase + Offset, Pupd11Pos, Pupd11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd12 = RegisterModel<GpioDBase + Offset, Pupd12Pos, Pupd12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd13 = RegisterModel<GpioDBase + Offset, Pupd13Pos, Pupd13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd14 = RegisterModel<GpioDBase + Offset, Pupd14Pos, Pupd14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd15 = RegisterModel<GpioDBase + Offset, Pupd15Pos, Pupd15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace idr {
      using id0  = RegisterModel<GpioDBase + Offset, Id0Pos,  Id0Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id1  = RegisterModel<GpioDBase + Offset, Id1Pos,  Id1Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id2  = RegisterModel<GpioDBase + Offset, Id2Pos,  Id2Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id3  = RegisterModel<GpioDBase + Offset, Id3Pos,  Id3Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id4  = RegisterModel<GpioDBase + Offset, Id4Pos,  Id4Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id5  = RegisterModel<GpioDBase + Offset, Id5Pos,  Id5Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id6  = RegisterModel<GpioDBase + Offset, Id6Pos,  Id6Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id7  = RegisterModel<GpioDBase + Offset, Id7Pos,  Id7Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id8  = RegisterModel<GpioDBase + Offset, Id8Pos,  Id8Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id9  = RegisterModel<GpioDBase + Offset, Id9Pos,  Id9Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id10 = RegisterModel<GpioDBase + Offset, Id10Pos, Id10Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id11 = RegisterModel<GpioDBase + Offset, Id11Pos, Id11Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id12 = RegisterModel<GpioDBase + Offset, Id12Pos, Id12Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id13 = RegisterModel<GpioDBase + Offset, Id13Pos, Id13Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id14 = RegisterModel<GpioDBase + Offset, Id14Pos, Id14Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id15 = RegisterModel<GpioDBase + Offset, Id15Pos, Id15Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
    }

    namespace odr {
      using od0  = RegisterModel<GpioDBase + Offset, Od0Pos,  Od0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od1  = RegisterModel<GpioDBase + Offset, Od1Pos,  Od1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od2  = RegisterModel<GpioDBase + Offset, Od2Pos,  Od2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od3  = RegisterModel<GpioDBase + Offset, Od3Pos,  Od3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od4  = RegisterModel<GpioDBase + Offset, Od4Pos,  Od4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od5  = RegisterModel<GpioDBase + Offset, Od5Pos,  Od5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od6  = RegisterModel<GpioDBase + Offset, Od6Pos,  Od6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od7  = RegisterModel<GpioDBase + Offset, Od7Pos,  Od7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od8  = RegisterModel<GpioDBase + Offset, Od8Pos,  Od8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od9  = RegisterModel<GpioDBase + Offset, Od9Pos,  Od9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od10 = RegisterModel<GpioDBase + Offset, Od10Pos, Od10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od11 = RegisterModel<GpioDBase + Offset, Od11Pos, Od11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od12 = RegisterModel<GpioDBase + Offset, Od12Pos, Od12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od13 = RegisterModel<GpioDBase + Offset, Od13Pos, Od13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od14 = RegisterModel<GpioDBase + Offset, Od14Pos, Od14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od15 = RegisterModel<GpioDBase + Offset, Od15Pos, Od15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace bsrr {
      using bs0  = RegisterModel<GpioDBase + Offset, Bs0Pos,  Bs0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs1  = RegisterModel<GpioDBase + Offset, Bs1Pos,  Bs1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs2  = RegisterModel<GpioDBase + Offset, Bs2Pos,  Bs2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs3  = RegisterModel<GpioDBase + Offset, Bs3Pos,  Bs3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs4  = RegisterModel<GpioDBase + Offset, Bs4Pos,  Bs4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs5  = RegisterModel<GpioDBase + Offset, Bs5Pos,  Bs5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs6  = RegisterModel<GpioDBase + Offset, Bs6Pos,  Bs6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs7  = RegisterModel<GpioDBase + Offset, Bs7Pos,  Bs7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs8  = RegisterModel<GpioDBase + Offset, Bs8Pos,  Bs8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs9  = RegisterModel<GpioDBase + Offset, Bs9Pos,  Bs9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs10 = RegisterModel<GpioDBase + Offset, Bs10Pos, Bs10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs11 = RegisterModel<GpioDBase + Offset, Bs11Pos, Bs11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs12 = RegisterModel<GpioDBase + Offset, Bs12Pos, Bs12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs13 = RegisterModel<GpioDBase + Offset, Bs13Pos, Bs13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs14 = RegisterModel<GpioDBase + Offset, Bs14Pos, Bs14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs15 = RegisterModel<GpioDBase + Offset, Bs15Pos, Bs15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br0  = RegisterModel<GpioDBase + Offset, Br0Pos,  Br0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br1  = RegisterModel<GpioDBase + Offset, Br1Pos,  Br1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br2  = RegisterModel<GpioDBase + Offset, Br2Pos,  Br2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br3  = RegisterModel<GpioDBase + Offset, Br3Pos,  Br3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br4  = RegisterModel<GpioDBase + Offset, Br4Pos,  Br4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br5  = RegisterModel<GpioDBase + Offset, Br5Pos,  Br5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br6  = RegisterModel<GpioDBase + Offset, Br6Pos,  Br6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br7  = RegisterModel<GpioDBase + Offset, Br7Pos,  Br7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br8  = RegisterModel<GpioDBase + Offset, Br8Pos,  Br8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br9  = RegisterModel<GpioDBase + Offset, Br9Pos,  Br9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br10 = RegisterModel<GpioDBase + Offset, Br10Pos, Br10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br11 = RegisterModel<GpioDBase + Offset, Br11Pos, Br11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br12 = RegisterModel<GpioDBase + Offset, Br12Pos, Br12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br13 = RegisterModel<GpioDBase + Offset, Br13Pos, Br13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br14 = RegisterModel<GpioDBase + Offset, Br14Pos, Br14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br15 = RegisterModel<GpioDBase + Offset, Br15Pos, Br15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
    }

    namespace lckr {
      using lck0  = RegisterModel<GpioDBase + Offset, Lck0Pos,  Lck0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck1  = RegisterModel<GpioDBase + Offset, Lck1Pos,  Lck1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck2  = RegisterModel<GpioDBase + Offset, Lck2Pos,  Lck2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck3  = RegisterModel<GpioDBase + Offset, Lck3Pos,  Lck3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck4  = RegisterModel<GpioDBase + Offset, Lck4Pos,  Lck4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck5  = RegisterModel<GpioDBase + Offset, Lck5Pos,  Lck5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck6  = RegisterModel<GpioDBase + Offset, Lck6Pos,  Lck6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck7  = RegisterModel<GpioDBase + Offset, Lck7Pos,  Lck7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck8  = RegisterModel<GpioDBase + Offset, Lck8Pos,  Lck8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck9  = RegisterModel<GpioDBase + Offset, Lck9Pos,  Lck9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck10 = RegisterModel<GpioDBase + Offset, Lck10Pos, Lck10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck11 = RegisterModel<GpioDBase + Offset, Lck11Pos, Lck11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck12 = RegisterModel<GpioDBase + Offset, Lck12Pos, Lck12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck13 = RegisterModel<GpioDBase + Offset, Lck13Pos, Lck13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck14 = RegisterModel<GpioDBase + Offset, Lck14Pos, Lck14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck15 = RegisterModel<GpioDBase + Offset, Lck15Pos, Lck15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lckk  = RegisterModel<GpioDBase + Offset, LckkPos,  LckkMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrl {
      using afsel0 = RegisterModel<GpioDBase + Offset, Afsel0Pos, Afsel0Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel1 = RegisterModel<GpioDBase + Offset, Afsel1Pos, Afsel1Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel2 = RegisterModel<GpioDBase + Offset, Afsel2Pos, Afsel2Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel3 = RegisterModel<GpioDBase + Offset, Afsel3Pos, Afsel3Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel4 = RegisterModel<GpioDBase + Offset, Afsel4Pos, Afsel4Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel5 = RegisterModel<GpioDBase + Offset, Afsel5Pos, Afsel5Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel6 = RegisterModel<GpioDBase + Offset, Afsel6Pos, Afsel6Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel7 = RegisterModel<GpioDBase + Offset, Afsel7Pos, Afsel7Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrh {
      using afsel8  = RegisterModel<GpioDBase + Offset, Afsel8Pos,  Afsel8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel9  = RegisterModel<GpioDBase + Offset, Afsel9Pos,  Afsel9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel10 = RegisterModel<GpioDBase + Offset, Afsel10Pos, Afsel10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel11 = RegisterModel<GpioDBase + Offset, Afsel11Pos, Afsel11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel12 = RegisterModel<GpioDBase + Offset, Afsel12Pos, Afsel12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel13 = RegisterModel<GpioDBase + Offset, Afsel13Pos, Afsel13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel14 = RegisterModel<GpioDBase + Offset, Afsel14Pos, Afsel14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel15 = RegisterModel<GpioDBase + Offset, Afsel15Pos, Afsel15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }
  }

  namespace e {
    namespace moder {
      using moder0  = RegisterModel<GpioEBase + Offset, Moder0Pos,  Moder0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder1  = RegisterModel<GpioEBase + Offset, Moder1Pos,  Moder1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder2  = RegisterModel<GpioEBase + Offset, Moder2Pos,  Moder2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder3  = RegisterModel<GpioEBase + Offset, Moder3Pos,  Moder3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder4  = RegisterModel<GpioEBase + Offset, Moder4Pos,  Moder4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder5  = RegisterModel<GpioEBase + Offset, Moder5Pos,  Moder5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder6  = RegisterModel<GpioEBase + Offset, Moder6Pos,  Moder6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder7  = RegisterModel<GpioEBase + Offset, Moder7Pos,  Moder7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder8  = RegisterModel<GpioEBase + Offset, Moder8Pos,  Moder8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder9  = RegisterModel<GpioEBase + Offset, Moder9Pos,  Moder9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder10 = RegisterModel<GpioEBase + Offset, Moder10Pos, Moder10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder11 = RegisterModel<GpioEBase + Offset, Moder11Pos, Moder11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder12 = RegisterModel<GpioEBase + Offset, Moder12Pos, Moder12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder13 = RegisterModel<GpioEBase + Offset, Moder13Pos, Moder13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder14 = RegisterModel<GpioEBase + Offset, Moder14Pos, Moder14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder15 = RegisterModel<GpioEBase + Offset, Moder15Pos, Moder15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace otyper {
      using ot0  = RegisterModel<GpioEBase + Offset, Ot0Pos,  Ot0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot1  = RegisterModel<GpioEBase + Offset, Ot1Pos,  Ot1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot2  = RegisterModel<GpioEBase + Offset, Ot2Pos,  Ot2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot3  = RegisterModel<GpioEBase + Offset, Ot3Pos,  Ot3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot4  = RegisterModel<GpioEBase + Offset, Ot4Pos,  Ot4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot5  = RegisterModel<GpioEBase + Offset, Ot5Pos,  Ot5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot6  = RegisterModel<GpioEBase + Offset, Ot6Pos,  Ot6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot7  = RegisterModel<GpioEBase + Offset, Ot7Pos,  Ot7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot8  = RegisterModel<GpioEBase + Offset, Ot8Pos,  Ot8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot9  = RegisterModel<GpioEBase + Offset, Ot9Pos,  Ot9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot10 = RegisterModel<GpioEBase + Offset, Ot10Pos, Ot10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot11 = RegisterModel<GpioEBase + Offset, Ot11Pos, Ot11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot12 = RegisterModel<GpioEBase + Offset, Ot12Pos, Ot12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot13 = RegisterModel<GpioEBase + Offset, Ot13Pos, Ot13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot14 = RegisterModel<GpioEBase + Offset, Ot14Pos, Ot14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot15 = RegisterModel<GpioEBase + Offset, Ot15Pos, Ot15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace ospeedr {
      using ospeed0  = RegisterModel<GpioEBase + Offset, Ospeed0Pos,  Ospeed0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed1  = RegisterModel<GpioEBase + Offset, Ospeed1Pos,  Ospeed1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed2  = RegisterModel<GpioEBase + Offset, Ospeed2Pos,  Ospeed2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed3  = RegisterModel<GpioEBase + Offset, Ospeed3Pos,  Ospeed3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed4  = RegisterModel<GpioEBase + Offset, Ospeed4Pos,  Ospeed4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed5  = RegisterModel<GpioEBase + Offset, Ospeed5Pos,  Ospeed5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed6  = RegisterModel<GpioEBase + Offset, Ospeed6Pos,  Ospeed6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed7  = RegisterModel<GpioEBase + Offset, Ospeed7Pos,  Ospeed7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed8  = RegisterModel<GpioEBase + Offset, Ospeed8Pos,  Ospeed8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed9  = RegisterModel<GpioEBase + Offset, Ospeed9Pos,  Ospeed9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed10 = RegisterModel<GpioEBase + Offset, Ospeed10Pos, Ospeed10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed11 = RegisterModel<GpioEBase + Offset, Ospeed11Pos, Ospeed11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed12 = RegisterModel<GpioEBase + Offset, Ospeed12Pos, Ospeed12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed13 = RegisterModel<GpioEBase + Offset, Ospeed13Pos, Ospeed13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed14 = RegisterModel<GpioEBase + Offset, Ospeed14Pos, Ospeed14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed15 = RegisterModel<GpioEBase + Offset, Ospeed15Pos, Ospeed15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace pupdr {
      using pupd0  = RegisterModel<GpioEBase + Offset, Pupd0Pos,  Pupd0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd1  = RegisterModel<GpioEBase + Offset, Pupd1Pos,  Pupd1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd2  = RegisterModel<GpioEBase + Offset, Pupd2Pos,  Pupd2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd3  = RegisterModel<GpioEBase + Offset, Pupd3Pos,  Pupd3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd4  = RegisterModel<GpioEBase + Offset, Pupd4Pos,  Pupd4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd5  = RegisterModel<GpioEBase + Offset, Pupd5Pos,  Pupd5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd6  = RegisterModel<GpioEBase + Offset, Pupd6Pos,  Pupd6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd7  = RegisterModel<GpioEBase + Offset, Pupd7Pos,  Pupd7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd8  = RegisterModel<GpioEBase + Offset, Pupd8Pos,  Pupd8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd9  = RegisterModel<GpioEBase + Offset, Pupd9Pos,  Pupd9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd10 = RegisterModel<GpioEBase + Offset, Pupd10Pos, Pupd10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd11 = RegisterModel<GpioEBase + Offset, Pupd11Pos, Pupd11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd12 = RegisterModel<GpioEBase + Offset, Pupd12Pos, Pupd12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd13 = RegisterModel<GpioEBase + Offset, Pupd13Pos, Pupd13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd14 = RegisterModel<GpioEBase + Offset, Pupd14Pos, Pupd14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd15 = RegisterModel<GpioEBase + Offset, Pupd15Pos, Pupd15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace idr {
      using id0  = RegisterModel<GpioEBase + Offset, Id0Pos,  Id0Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id1  = RegisterModel<GpioEBase + Offset, Id1Pos,  Id1Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id2  = RegisterModel<GpioEBase + Offset, Id2Pos,  Id2Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id3  = RegisterModel<GpioEBase + Offset, Id3Pos,  Id3Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id4  = RegisterModel<GpioEBase + Offset, Id4Pos,  Id4Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id5  = RegisterModel<GpioEBase + Offset, Id5Pos,  Id5Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id6  = RegisterModel<GpioEBase + Offset, Id6Pos,  Id6Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id7  = RegisterModel<GpioEBase + Offset, Id7Pos,  Id7Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id8  = RegisterModel<GpioEBase + Offset, Id8Pos,  Id8Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id9  = RegisterModel<GpioEBase + Offset, Id9Pos,  Id9Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id10 = RegisterModel<GpioEBase + Offset, Id10Pos, Id10Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id11 = RegisterModel<GpioEBase + Offset, Id11Pos, Id11Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id12 = RegisterModel<GpioEBase + Offset, Id12Pos, Id12Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id13 = RegisterModel<GpioEBase + Offset, Id13Pos, Id13Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id14 = RegisterModel<GpioEBase + Offset, Id14Pos, Id14Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id15 = RegisterModel<GpioEBase + Offset, Id15Pos, Id15Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
    }

    namespace odr {
      using od0  = RegisterModel<GpioEBase + Offset, Od0Pos,  Od0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od1  = RegisterModel<GpioEBase + Offset, Od1Pos,  Od1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od2  = RegisterModel<GpioEBase + Offset, Od2Pos,  Od2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od3  = RegisterModel<GpioEBase + Offset, Od3Pos,  Od3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od4  = RegisterModel<GpioEBase + Offset, Od4Pos,  Od4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od5  = RegisterModel<GpioEBase + Offset, Od5Pos,  Od5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od6  = RegisterModel<GpioEBase + Offset, Od6Pos,  Od6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od7  = RegisterModel<GpioEBase + Offset, Od7Pos,  Od7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od8  = RegisterModel<GpioEBase + Offset, Od8Pos,  Od8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od9  = RegisterModel<GpioEBase + Offset, Od9Pos,  Od9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od10 = RegisterModel<GpioEBase + Offset, Od10Pos, Od10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od11 = RegisterModel<GpioEBase + Offset, Od11Pos, Od11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od12 = RegisterModel<GpioEBase + Offset, Od12Pos, Od12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od13 = RegisterModel<GpioEBase + Offset, Od13Pos, Od13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od14 = RegisterModel<GpioEBase + Offset, Od14Pos, Od14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od15 = RegisterModel<GpioEBase + Offset, Od15Pos, Od15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace bsrr {
      using bs0  = RegisterModel<GpioEBase + Offset, Bs0Pos,  Bs0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs1  = RegisterModel<GpioEBase + Offset, Bs1Pos,  Bs1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs2  = RegisterModel<GpioEBase + Offset, Bs2Pos,  Bs2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs3  = RegisterModel<GpioEBase + Offset, Bs3Pos,  Bs3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs4  = RegisterModel<GpioEBase + Offset, Bs4Pos,  Bs4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs5  = RegisterModel<GpioEBase + Offset, Bs5Pos,  Bs5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs6  = RegisterModel<GpioEBase + Offset, Bs6Pos,  Bs6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs7  = RegisterModel<GpioEBase + Offset, Bs7Pos,  Bs7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs8  = RegisterModel<GpioEBase + Offset, Bs8Pos,  Bs8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs9  = RegisterModel<GpioEBase + Offset, Bs9Pos,  Bs9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs10 = RegisterModel<GpioEBase + Offset, Bs10Pos, Bs10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs11 = RegisterModel<GpioEBase + Offset, Bs11Pos, Bs11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs12 = RegisterModel<GpioEBase + Offset, Bs12Pos, Bs12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs13 = RegisterModel<GpioEBase + Offset, Bs13Pos, Bs13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs14 = RegisterModel<GpioEBase + Offset, Bs14Pos, Bs14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs15 = RegisterModel<GpioEBase + Offset, Bs15Pos, Bs15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br0  = RegisterModel<GpioEBase + Offset, Br0Pos,  Br0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br1  = RegisterModel<GpioEBase + Offset, Br1Pos,  Br1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br2  = RegisterModel<GpioEBase + Offset, Br2Pos,  Br2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br3  = RegisterModel<GpioEBase + Offset, Br3Pos,  Br3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br4  = RegisterModel<GpioEBase + Offset, Br4Pos,  Br4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br5  = RegisterModel<GpioEBase + Offset, Br5Pos,  Br5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br6  = RegisterModel<GpioEBase + Offset, Br6Pos,  Br6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br7  = RegisterModel<GpioEBase + Offset, Br7Pos,  Br7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br8  = RegisterModel<GpioEBase + Offset, Br8Pos,  Br8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br9  = RegisterModel<GpioEBase + Offset, Br9Pos,  Br9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br10 = RegisterModel<GpioEBase + Offset, Br10Pos, Br10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br11 = RegisterModel<GpioEBase + Offset, Br11Pos, Br11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br12 = RegisterModel<GpioEBase + Offset, Br12Pos, Br12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br13 = RegisterModel<GpioEBase + Offset, Br13Pos, Br13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br14 = RegisterModel<GpioEBase + Offset, Br14Pos, Br14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br15 = RegisterModel<GpioEBase + Offset, Br15Pos, Br15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
    }

    namespace lckr {
      using lck0  = RegisterModel<GpioEBase + Offset, Lck0Pos,  Lck0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck1  = RegisterModel<GpioEBase + Offset, Lck1Pos,  Lck1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck2  = RegisterModel<GpioEBase + Offset, Lck2Pos,  Lck2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck3  = RegisterModel<GpioEBase + Offset, Lck3Pos,  Lck3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck4  = RegisterModel<GpioEBase + Offset, Lck4Pos,  Lck4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck5  = RegisterModel<GpioEBase + Offset, Lck5Pos,  Lck5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck6  = RegisterModel<GpioEBase + Offset, Lck6Pos,  Lck6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck7  = RegisterModel<GpioEBase + Offset, Lck7Pos,  Lck7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck8  = RegisterModel<GpioEBase + Offset, Lck8Pos,  Lck8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck9  = RegisterModel<GpioEBase + Offset, Lck9Pos,  Lck9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck10 = RegisterModel<GpioEBase + Offset, Lck10Pos, Lck10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck11 = RegisterModel<GpioEBase + Offset, Lck11Pos, Lck11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck12 = RegisterModel<GpioEBase + Offset, Lck12Pos, Lck12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck13 = RegisterModel<GpioEBase + Offset, Lck13Pos, Lck13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck14 = RegisterModel<GpioEBase + Offset, Lck14Pos, Lck14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck15 = RegisterModel<GpioEBase + Offset, Lck15Pos, Lck15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lckk  = RegisterModel<GpioEBase + Offset, LckkPos,  LckkMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrl {
      using afsel0 = RegisterModel<GpioEBase + Offset, Afsel0Pos, Afsel0Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel1 = RegisterModel<GpioEBase + Offset, Afsel1Pos, Afsel1Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel2 = RegisterModel<GpioEBase + Offset, Afsel2Pos, Afsel2Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel3 = RegisterModel<GpioEBase + Offset, Afsel3Pos, Afsel3Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel4 = RegisterModel<GpioEBase + Offset, Afsel4Pos, Afsel4Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel5 = RegisterModel<GpioEBase + Offset, Afsel5Pos, Afsel5Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel6 = RegisterModel<GpioEBase + Offset, Afsel6Pos, Afsel6Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel7 = RegisterModel<GpioEBase + Offset, Afsel7Pos, Afsel7Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrh {
      using afsel8  = RegisterModel<GpioEBase + Offset, Afsel8Pos,  Afsel8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel9  = RegisterModel<GpioEBase + Offset, Afsel9Pos,  Afsel9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel10 = RegisterModel<GpioEBase + Offset, Afsel10Pos, Afsel10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel11 = RegisterModel<GpioEBase + Offset, Afsel11Pos, Afsel11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel12 = RegisterModel<GpioEBase + Offset, Afsel12Pos, Afsel12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel13 = RegisterModel<GpioEBase + Offset, Afsel13Pos, Afsel13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel14 = RegisterModel<GpioEBase + Offset, Afsel14Pos, Afsel14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel15 = RegisterModel<GpioEBase + Offset, Afsel15Pos, Afsel15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }
  }

  namespace h {
    namespace moder {
      using moder0  = RegisterModel<GpioHBase + Offset, Moder0Pos,  Moder0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder1  = RegisterModel<GpioHBase + Offset, Moder1Pos,  Moder1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder2  = RegisterModel<GpioHBase + Offset, Moder2Pos,  Moder2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder3  = RegisterModel<GpioHBase + Offset, Moder3Pos,  Moder3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder4  = RegisterModel<GpioHBase + Offset, Moder4Pos,  Moder4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder5  = RegisterModel<GpioHBase + Offset, Moder5Pos,  Moder5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder6  = RegisterModel<GpioHBase + Offset, Moder6Pos,  Moder6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder7  = RegisterModel<GpioHBase + Offset, Moder7Pos,  Moder7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder8  = RegisterModel<GpioHBase + Offset, Moder8Pos,  Moder8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder9  = RegisterModel<GpioHBase + Offset, Moder9Pos,  Moder9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder10 = RegisterModel<GpioHBase + Offset, Moder10Pos, Moder10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder11 = RegisterModel<GpioHBase + Offset, Moder11Pos, Moder11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder12 = RegisterModel<GpioHBase + Offset, Moder12Pos, Moder12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder13 = RegisterModel<GpioHBase + Offset, Moder13Pos, Moder13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder14 = RegisterModel<GpioHBase + Offset, Moder14Pos, Moder14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using moder15 = RegisterModel<GpioHBase + Offset, Moder15Pos, Moder15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace otyper {
      using ot0  = RegisterModel<GpioHBase + Offset, Ot0Pos,  Ot0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot1  = RegisterModel<GpioHBase + Offset, Ot1Pos,  Ot1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot2  = RegisterModel<GpioHBase + Offset, Ot2Pos,  Ot2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot3  = RegisterModel<GpioHBase + Offset, Ot3Pos,  Ot3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot4  = RegisterModel<GpioHBase + Offset, Ot4Pos,  Ot4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot5  = RegisterModel<GpioHBase + Offset, Ot5Pos,  Ot5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot6  = RegisterModel<GpioHBase + Offset, Ot6Pos,  Ot6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot7  = RegisterModel<GpioHBase + Offset, Ot7Pos,  Ot7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot8  = RegisterModel<GpioHBase + Offset, Ot8Pos,  Ot8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot9  = RegisterModel<GpioHBase + Offset, Ot9Pos,  Ot9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot10 = RegisterModel<GpioHBase + Offset, Ot10Pos, Ot10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot11 = RegisterModel<GpioHBase + Offset, Ot11Pos, Ot11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot12 = RegisterModel<GpioHBase + Offset, Ot12Pos, Ot12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot13 = RegisterModel<GpioHBase + Offset, Ot13Pos, Ot13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot14 = RegisterModel<GpioHBase + Offset, Ot14Pos, Ot14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ot15 = RegisterModel<GpioHBase + Offset, Ot15Pos, Ot15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace ospeedr {
      using ospeed0  = RegisterModel<GpioHBase + Offset, Ospeed0Pos,  Ospeed0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed1  = RegisterModel<GpioHBase + Offset, Ospeed1Pos,  Ospeed1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed2  = RegisterModel<GpioHBase + Offset, Ospeed2Pos,  Ospeed2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed3  = RegisterModel<GpioHBase + Offset, Ospeed3Pos,  Ospeed3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed4  = RegisterModel<GpioHBase + Offset, Ospeed4Pos,  Ospeed4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed5  = RegisterModel<GpioHBase + Offset, Ospeed5Pos,  Ospeed5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed6  = RegisterModel<GpioHBase + Offset, Ospeed6Pos,  Ospeed6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed7  = RegisterModel<GpioHBase + Offset, Ospeed7Pos,  Ospeed7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed8  = RegisterModel<GpioHBase + Offset, Ospeed8Pos,  Ospeed8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed9  = RegisterModel<GpioHBase + Offset, Ospeed9Pos,  Ospeed9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed10 = RegisterModel<GpioHBase + Offset, Ospeed10Pos, Ospeed10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed11 = RegisterModel<GpioHBase + Offset, Ospeed11Pos, Ospeed11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed12 = RegisterModel<GpioHBase + Offset, Ospeed12Pos, Ospeed12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed13 = RegisterModel<GpioHBase + Offset, Ospeed13Pos, Ospeed13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed14 = RegisterModel<GpioHBase + Offset, Ospeed14Pos, Ospeed14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using ospeed15 = RegisterModel<GpioHBase + Offset, Ospeed15Pos, Ospeed15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace pupdr {
      using pupd0  = RegisterModel<GpioHBase + Offset, Pupd0Pos,  Pupd0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd1  = RegisterModel<GpioHBase + Offset, Pupd1Pos,  Pupd1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd2  = RegisterModel<GpioHBase + Offset, Pupd2Pos,  Pupd2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd3  = RegisterModel<GpioHBase + Offset, Pupd3Pos,  Pupd3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd4  = RegisterModel<GpioHBase + Offset, Pupd4Pos,  Pupd4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd5  = RegisterModel<GpioHBase + Offset, Pupd5Pos,  Pupd5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd6  = RegisterModel<GpioHBase + Offset, Pupd6Pos,  Pupd6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd7  = RegisterModel<GpioHBase + Offset, Pupd7Pos,  Pupd7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd8  = RegisterModel<GpioHBase + Offset, Pupd8Pos,  Pupd8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd9  = RegisterModel<GpioHBase + Offset, Pupd9Pos,  Pupd9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd10 = RegisterModel<GpioHBase + Offset, Pupd10Pos, Pupd10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd11 = RegisterModel<GpioHBase + Offset, Pupd11Pos, Pupd11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd12 = RegisterModel<GpioHBase + Offset, Pupd12Pos, Pupd12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd13 = RegisterModel<GpioHBase + Offset, Pupd13Pos, Pupd13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd14 = RegisterModel<GpioHBase + Offset, Pupd14Pos, Pupd14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using pupd15 = RegisterModel<GpioHBase + Offset, Pupd15Pos, Pupd15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace idr {
      using id0  = RegisterModel<GpioHBase + Offset, Id0Pos,  Id0Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id1  = RegisterModel<GpioHBase + Offset, Id1Pos,  Id1Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id2  = RegisterModel<GpioHBase + Offset, Id2Pos,  Id2Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id3  = RegisterModel<GpioHBase + Offset, Id3Pos,  Id3Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id4  = RegisterModel<GpioHBase + Offset, Id4Pos,  Id4Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id5  = RegisterModel<GpioHBase + Offset, Id5Pos,  Id5Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id6  = RegisterModel<GpioHBase + Offset, Id6Pos,  Id6Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id7  = RegisterModel<GpioHBase + Offset, Id7Pos,  Id7Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id8  = RegisterModel<GpioHBase + Offset, Id8Pos,  Id8Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id9  = RegisterModel<GpioHBase + Offset, Id9Pos,  Id9Msk,  PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id10 = RegisterModel<GpioHBase + Offset, Id10Pos, Id10Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id11 = RegisterModel<GpioHBase + Offset, Id11Pos, Id11Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id12 = RegisterModel<GpioHBase + Offset, Id12Pos, Id12Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id13 = RegisterModel<GpioHBase + Offset, Id13Pos, Id13Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id14 = RegisterModel<GpioHBase + Offset, Id14Pos, Id14Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
      using id15 = RegisterModel<GpioHBase + Offset, Id15Pos, Id15Msk, PolicyExecutor<RegisterPolicy::ReadOnly, FieldPolicy::ReadOnly>>;
    }

    namespace odr {
      using od0  = RegisterModel<GpioHBase + Offset, Od0Pos,  Od0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od1  = RegisterModel<GpioHBase + Offset, Od1Pos,  Od1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od2  = RegisterModel<GpioHBase + Offset, Od2Pos,  Od2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od3  = RegisterModel<GpioHBase + Offset, Od3Pos,  Od3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od4  = RegisterModel<GpioHBase + Offset, Od4Pos,  Od4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od5  = RegisterModel<GpioHBase + Offset, Od5Pos,  Od5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od6  = RegisterModel<GpioHBase + Offset, Od6Pos,  Od6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od7  = RegisterModel<GpioHBase + Offset, Od7Pos,  Od7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od8  = RegisterModel<GpioHBase + Offset, Od8Pos,  Od8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od9  = RegisterModel<GpioHBase + Offset, Od9Pos,  Od9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od10 = RegisterModel<GpioHBase + Offset, Od10Pos, Od10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od11 = RegisterModel<GpioHBase + Offset, Od11Pos, Od11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od12 = RegisterModel<GpioHBase + Offset, Od12Pos, Od12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od13 = RegisterModel<GpioHBase + Offset, Od13Pos, Od13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od14 = RegisterModel<GpioHBase + Offset, Od14Pos, Od14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using od15 = RegisterModel<GpioHBase + Offset, Od15Pos, Od15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace bsrr {
      using bs0  = RegisterModel<GpioHBase + Offset, Bs0Pos,  Bs0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs1  = RegisterModel<GpioHBase + Offset, Bs1Pos,  Bs1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs2  = RegisterModel<GpioHBase + Offset, Bs2Pos,  Bs2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs3  = RegisterModel<GpioHBase + Offset, Bs3Pos,  Bs3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs4  = RegisterModel<GpioHBase + Offset, Bs4Pos,  Bs4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs5  = RegisterModel<GpioHBase + Offset, Bs5Pos,  Bs5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs6  = RegisterModel<GpioHBase + Offset, Bs6Pos,  Bs6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs7  = RegisterModel<GpioHBase + Offset, Bs7Pos,  Bs7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs8  = RegisterModel<GpioHBase + Offset, Bs8Pos,  Bs8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs9  = RegisterModel<GpioHBase + Offset, Bs9Pos,  Bs9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs10 = RegisterModel<GpioHBase + Offset, Bs10Pos, Bs10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs11 = RegisterModel<GpioHBase + Offset, Bs11Pos, Bs11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs12 = RegisterModel<GpioHBase + Offset, Bs12Pos, Bs12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs13 = RegisterModel<GpioHBase + Offset, Bs13Pos, Bs13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs14 = RegisterModel<GpioHBase + Offset, Bs14Pos, Bs14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using bs15 = RegisterModel<GpioHBase + Offset, Bs15Pos, Bs15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br0  = RegisterModel<GpioHBase + Offset, Br0Pos,  Br0Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br1  = RegisterModel<GpioHBase + Offset, Br1Pos,  Br1Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br2  = RegisterModel<GpioHBase + Offset, Br2Pos,  Br2Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br3  = RegisterModel<GpioHBase + Offset, Br3Pos,  Br3Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br4  = RegisterModel<GpioHBase + Offset, Br4Pos,  Br4Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br5  = RegisterModel<GpioHBase + Offset, Br5Pos,  Br5Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br6  = RegisterModel<GpioHBase + Offset, Br6Pos,  Br6Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br7  = RegisterModel<GpioHBase + Offset, Br7Pos,  Br7Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br8  = RegisterModel<GpioHBase + Offset, Br8Pos,  Br8Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br9  = RegisterModel<GpioHBase + Offset, Br9Pos,  Br9Msk,  PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br10 = RegisterModel<GpioHBase + Offset, Br10Pos, Br10Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br11 = RegisterModel<GpioHBase + Offset, Br11Pos, Br11Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br12 = RegisterModel<GpioHBase + Offset, Br12Pos, Br12Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br13 = RegisterModel<GpioHBase + Offset, Br13Pos, Br13Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br14 = RegisterModel<GpioHBase + Offset, Br14Pos, Br14Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
      using br15 = RegisterModel<GpioHBase + Offset, Br15Pos, Br15Msk, PolicyExecutor<RegisterPolicy::WriteOnly, FieldPolicy::WriteOnly>>;
    }

    namespace lckr {
      using lck0  = RegisterModel<GpioHBase + Offset, Lck0Pos,  Lck0Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck1  = RegisterModel<GpioHBase + Offset, Lck1Pos,  Lck1Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck2  = RegisterModel<GpioHBase + Offset, Lck2Pos,  Lck2Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck3  = RegisterModel<GpioHBase + Offset, Lck3Pos,  Lck3Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck4  = RegisterModel<GpioHBase + Offset, Lck4Pos,  Lck4Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck5  = RegisterModel<GpioHBase + Offset, Lck5Pos,  Lck5Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck6  = RegisterModel<GpioHBase + Offset, Lck6Pos,  Lck6Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck7  = RegisterModel<GpioHBase + Offset, Lck7Pos,  Lck7Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck8  = RegisterModel<GpioHBase + Offset, Lck8Pos,  Lck8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck9  = RegisterModel<GpioHBase + Offset, Lck9Pos,  Lck9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck10 = RegisterModel<GpioHBase + Offset, Lck10Pos, Lck10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck11 = RegisterModel<GpioHBase + Offset, Lck11Pos, Lck11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck12 = RegisterModel<GpioHBase + Offset, Lck12Pos, Lck12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck13 = RegisterModel<GpioHBase + Offset, Lck13Pos, Lck13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck14 = RegisterModel<GpioHBase + Offset, Lck14Pos, Lck14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lck15 = RegisterModel<GpioHBase + Offset, Lck15Pos, Lck15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using lckk  = RegisterModel<GpioHBase + Offset, LckkPos,  LckkMsk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrl {
      using afsel0 = RegisterModel<GpioHBase + Offset, Afsel0Pos, Afsel0Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel1 = RegisterModel<GpioHBase + Offset, Afsel1Pos, Afsel1Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel2 = RegisterModel<GpioHBase + Offset, Afsel2Pos, Afsel2Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel3 = RegisterModel<GpioHBase + Offset, Afsel3Pos, Afsel3Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel4 = RegisterModel<GpioHBase + Offset, Afsel4Pos, Afsel4Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel5 = RegisterModel<GpioHBase + Offset, Afsel5Pos, Afsel5Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel6 = RegisterModel<GpioHBase + Offset, Afsel6Pos, Afsel6Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel7 = RegisterModel<GpioHBase + Offset, Afsel7Pos, Afsel7Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }

    namespace afrh {
      using afsel8  = RegisterModel<GpioHBase + Offset, Afsel8Pos,  Afsel8Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel9  = RegisterModel<GpioHBase + Offset, Afsel9Pos,  Afsel9Msk,  PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel10 = RegisterModel<GpioHBase + Offset, Afsel10Pos, Afsel10Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel11 = RegisterModel<GpioHBase + Offset, Afsel11Pos, Afsel11Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel12 = RegisterModel<GpioHBase + Offset, Afsel12Pos, Afsel12Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel13 = RegisterModel<GpioHBase + Offset, Afsel13Pos, Afsel13Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel14 = RegisterModel<GpioHBase + Offset, Afsel14Pos, Afsel14Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
      using afsel15 = RegisterModel<GpioHBase + Offset, Afsel15Pos, Afsel15Msk, PolicyExecutor<RegisterPolicy::ReadWrite, FieldPolicy::ReadWrite>>;
    }
  }
}
#endif /* STM32_F411XE_CONST_GPIO_H */
