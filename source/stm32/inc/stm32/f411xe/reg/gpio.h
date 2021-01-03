#ifndef STM32_F411XE_REG_GPIO_H
#define STM32_F411XE_REG_GPIO_H

#include "stm32/register_model/register_model.h"
#include "stm32/f411xe/const/general.h"
#include "stm32/f411xe/const/gpio.h"

namespace stm32::regs::gpio {

using namespace stm32::constants::gpio;


template <uint32_t address, RegisterPolicy regPolicy>
class ModerReg: public RegisterModel<address, regPolicy>
{
public:
  using moder0  = FieldModel<address, moder::Moder0Pos,  moder::Moder0Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using moder1  = FieldModel<address, moder::Moder1Pos,  moder::Moder1Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using moder2  = FieldModel<address, moder::Moder2Pos,  moder::Moder2Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using moder3  = FieldModel<address, moder::Moder3Pos,  moder::Moder3Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using moder4  = FieldModel<address, moder::Moder4Pos,  moder::Moder4Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using moder5  = FieldModel<address, moder::Moder5Pos,  moder::Moder5Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using moder6  = FieldModel<address, moder::Moder6Pos,  moder::Moder6Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using moder7  = FieldModel<address, moder::Moder7Pos,  moder::Moder7Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using moder8  = FieldModel<address, moder::Moder8Pos,  moder::Moder8Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using moder9  = FieldModel<address, moder::Moder9Pos,  moder::Moder9Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using moder10 = FieldModel<address, moder::Moder10Pos, moder::Moder10Msk, regPolicy, FieldPolicy::ReadWrite>;
  using moder11 = FieldModel<address, moder::Moder11Pos, moder::Moder11Msk, regPolicy, FieldPolicy::ReadWrite>;
  using moder12 = FieldModel<address, moder::Moder12Pos, moder::Moder12Msk, regPolicy, FieldPolicy::ReadWrite>;
  using moder13 = FieldModel<address, moder::Moder13Pos, moder::Moder13Msk, regPolicy, FieldPolicy::ReadWrite>;
  using moder14 = FieldModel<address, moder::Moder14Pos, moder::Moder14Msk, regPolicy, FieldPolicy::ReadWrite>;
  using moder15 = FieldModel<address, moder::Moder15Pos, moder::Moder15Msk, regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class OtyperReg: public RegisterModel<address, regPolicy>
{
public:
  using ot0  = FieldModel<address, otyper::Ot0Pos,  otyper::Ot0Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ot1  = FieldModel<address, otyper::Ot1Pos,  otyper::Ot1Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ot2  = FieldModel<address, otyper::Ot2Pos,  otyper::Ot2Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ot3  = FieldModel<address, otyper::Ot3Pos,  otyper::Ot3Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ot4  = FieldModel<address, otyper::Ot4Pos,  otyper::Ot4Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ot5  = FieldModel<address, otyper::Ot5Pos,  otyper::Ot5Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ot6  = FieldModel<address, otyper::Ot6Pos,  otyper::Ot6Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ot7  = FieldModel<address, otyper::Ot7Pos,  otyper::Ot7Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ot8  = FieldModel<address, otyper::Ot8Pos,  otyper::Ot8Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ot9  = FieldModel<address, otyper::Ot9Pos,  otyper::Ot9Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ot10 = FieldModel<address, otyper::Ot10Pos, otyper::Ot10Msk, regPolicy, FieldPolicy::ReadWrite>;
  using ot11 = FieldModel<address, otyper::Ot11Pos, otyper::Ot11Msk, regPolicy, FieldPolicy::ReadWrite>;
  using ot12 = FieldModel<address, otyper::Ot12Pos, otyper::Ot12Msk, regPolicy, FieldPolicy::ReadWrite>;
  using ot13 = FieldModel<address, otyper::Ot13Pos, otyper::Ot13Msk, regPolicy, FieldPolicy::ReadWrite>;
  using ot14 = FieldModel<address, otyper::Ot14Pos, otyper::Ot14Msk, regPolicy, FieldPolicy::ReadWrite>;
  using ot15 = FieldModel<address, otyper::Ot15Pos, otyper::Ot15Msk, regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class OspeedrReg: public RegisterModel<address, regPolicy>
{
public:
  using ospeed0  = FieldModel<address, ospeedr::Ospeed0Pos,  ospeedr::Ospeed0Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ospeed1  = FieldModel<address, ospeedr::Ospeed1Pos,  ospeedr::Ospeed1Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ospeed2  = FieldModel<address, ospeedr::Ospeed2Pos,  ospeedr::Ospeed2Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ospeed3  = FieldModel<address, ospeedr::Ospeed3Pos,  ospeedr::Ospeed3Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ospeed4  = FieldModel<address, ospeedr::Ospeed4Pos,  ospeedr::Ospeed4Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ospeed5  = FieldModel<address, ospeedr::Ospeed5Pos,  ospeedr::Ospeed5Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ospeed6  = FieldModel<address, ospeedr::Ospeed6Pos,  ospeedr::Ospeed6Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ospeed7  = FieldModel<address, ospeedr::Ospeed7Pos,  ospeedr::Ospeed7Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ospeed8  = FieldModel<address, ospeedr::Ospeed8Pos,  ospeedr::Ospeed8Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ospeed9  = FieldModel<address, ospeedr::Ospeed9Pos,  ospeedr::Ospeed9Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using ospeed10 = FieldModel<address, ospeedr::Ospeed10Pos, ospeedr::Ospeed10Msk, regPolicy, FieldPolicy::ReadWrite>;
  using ospeed11 = FieldModel<address, ospeedr::Ospeed11Pos, ospeedr::Ospeed11Msk, regPolicy, FieldPolicy::ReadWrite>;
  using ospeed12 = FieldModel<address, ospeedr::Ospeed12Pos, ospeedr::Ospeed12Msk, regPolicy, FieldPolicy::ReadWrite>;
  using ospeed13 = FieldModel<address, ospeedr::Ospeed13Pos, ospeedr::Ospeed13Msk, regPolicy, FieldPolicy::ReadWrite>;
  using ospeed14 = FieldModel<address, ospeedr::Ospeed14Pos, ospeedr::Ospeed14Msk, regPolicy, FieldPolicy::ReadWrite>;
  using ospeed15 = FieldModel<address, ospeedr::Ospeed15Pos, ospeedr::Ospeed15Msk, regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class PupdrReg: public RegisterModel<address, regPolicy>
{
public:
  using pupd0  = FieldModel<address, pupdr::Pupd0Pos,  pupdr::Pupd0Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using pupd1  = FieldModel<address, pupdr::Pupd1Pos,  pupdr::Pupd1Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using pupd2  = FieldModel<address, pupdr::Pupd2Pos,  pupdr::Pupd2Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using pupd3  = FieldModel<address, pupdr::Pupd3Pos,  pupdr::Pupd3Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using pupd4  = FieldModel<address, pupdr::Pupd4Pos,  pupdr::Pupd4Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using pupd5  = FieldModel<address, pupdr::Pupd5Pos,  pupdr::Pupd5Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using pupd6  = FieldModel<address, pupdr::Pupd6Pos,  pupdr::Pupd6Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using pupd7  = FieldModel<address, pupdr::Pupd7Pos,  pupdr::Pupd7Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using pupd8  = FieldModel<address, pupdr::Pupd8Pos,  pupdr::Pupd8Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using pupd9  = FieldModel<address, pupdr::Pupd9Pos,  pupdr::Pupd9Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using pupd10 = FieldModel<address, pupdr::Pupd10Pos, pupdr::Pupd10Msk, regPolicy, FieldPolicy::ReadWrite>;
  using pupd11 = FieldModel<address, pupdr::Pupd11Pos, pupdr::Pupd11Msk, regPolicy, FieldPolicy::ReadWrite>;
  using pupd12 = FieldModel<address, pupdr::Pupd12Pos, pupdr::Pupd12Msk, regPolicy, FieldPolicy::ReadWrite>;
  using pupd13 = FieldModel<address, pupdr::Pupd13Pos, pupdr::Pupd13Msk, regPolicy, FieldPolicy::ReadWrite>;
  using pupd14 = FieldModel<address, pupdr::Pupd14Pos, pupdr::Pupd14Msk, regPolicy, FieldPolicy::ReadWrite>;
  using pupd15 = FieldModel<address, pupdr::Pupd15Pos, pupdr::Pupd15Msk, regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class IdrReg: public RegisterModel<address, regPolicy>
{
public:
  using id0  = FieldModel<address, idr::Id0Pos,  idr::Id0Msk,  regPolicy, FieldPolicy::ReadOnly>;
  using id1  = FieldModel<address, idr::Id1Pos,  idr::Id1Msk,  regPolicy, FieldPolicy::ReadOnly>;
  using id2  = FieldModel<address, idr::Id2Pos,  idr::Id2Msk,  regPolicy, FieldPolicy::ReadOnly>;
  using id3  = FieldModel<address, idr::Id3Pos,  idr::Id3Msk,  regPolicy, FieldPolicy::ReadOnly>;
  using id4  = FieldModel<address, idr::Id4Pos,  idr::Id4Msk,  regPolicy, FieldPolicy::ReadOnly>;
  using id5  = FieldModel<address, idr::Id5Pos,  idr::Id5Msk,  regPolicy, FieldPolicy::ReadOnly>;
  using id6  = FieldModel<address, idr::Id6Pos,  idr::Id6Msk,  regPolicy, FieldPolicy::ReadOnly>;
  using id7  = FieldModel<address, idr::Id7Pos,  idr::Id7Msk,  regPolicy, FieldPolicy::ReadOnly>;
  using id8  = FieldModel<address, idr::Id8Pos,  idr::Id8Msk,  regPolicy, FieldPolicy::ReadOnly>;
  using id9  = FieldModel<address, idr::Id9Pos,  idr::Id9Msk,  regPolicy, FieldPolicy::ReadOnly>;
  using id10 = FieldModel<address, idr::Id10Pos, idr::Id10Msk, regPolicy, FieldPolicy::ReadOnly>;
  using id11 = FieldModel<address, idr::Id11Pos, idr::Id11Msk, regPolicy, FieldPolicy::ReadOnly>;
  using id12 = FieldModel<address, idr::Id12Pos, idr::Id12Msk, regPolicy, FieldPolicy::ReadOnly>;
  using id13 = FieldModel<address, idr::Id13Pos, idr::Id13Msk, regPolicy, FieldPolicy::ReadOnly>;
  using id14 = FieldModel<address, idr::Id14Pos, idr::Id14Msk, regPolicy, FieldPolicy::ReadOnly>;
  using id15 = FieldModel<address, idr::Id15Pos, idr::Id15Msk, regPolicy, FieldPolicy::ReadOnly>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class OdrReg: public RegisterModel<address, regPolicy>
{
public:
  using od0  = FieldModel<address, odr::Od0Pos,  odr::Od0Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using od1  = FieldModel<address, odr::Od1Pos,  odr::Od1Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using od2  = FieldModel<address, odr::Od2Pos,  odr::Od2Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using od3  = FieldModel<address, odr::Od3Pos,  odr::Od3Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using od4  = FieldModel<address, odr::Od4Pos,  odr::Od4Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using od5  = FieldModel<address, odr::Od5Pos,  odr::Od5Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using od6  = FieldModel<address, odr::Od6Pos,  odr::Od6Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using od7  = FieldModel<address, odr::Od7Pos,  odr::Od7Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using od8  = FieldModel<address, odr::Od8Pos,  odr::Od8Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using od9  = FieldModel<address, odr::Od9Pos,  odr::Od9Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using od10 = FieldModel<address, odr::Od10Pos, odr::Od10Msk, regPolicy, FieldPolicy::ReadWrite>;
  using od11 = FieldModel<address, odr::Od11Pos, odr::Od11Msk, regPolicy, FieldPolicy::ReadWrite>;
  using od12 = FieldModel<address, odr::Od12Pos, odr::Od12Msk, regPolicy, FieldPolicy::ReadWrite>;
  using od13 = FieldModel<address, odr::Od13Pos, odr::Od13Msk, regPolicy, FieldPolicy::ReadWrite>;
  using od14 = FieldModel<address, odr::Od14Pos, odr::Od14Msk, regPolicy, FieldPolicy::ReadWrite>;
  using od15 = FieldModel<address, odr::Od15Pos, odr::Od15Msk, regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class BsrrReg: public RegisterModel<address, regPolicy>
{
public:
  using bs0  = FieldModel<address, bsrr::Bs0Pos,  bsrr::Bs0Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using bs1  = FieldModel<address, bsrr::Bs1Pos,  bsrr::Bs1Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using bs2  = FieldModel<address, bsrr::Bs2Pos,  bsrr::Bs2Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using bs3  = FieldModel<address, bsrr::Bs3Pos,  bsrr::Bs3Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using bs4  = FieldModel<address, bsrr::Bs4Pos,  bsrr::Bs4Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using bs5  = FieldModel<address, bsrr::Bs5Pos,  bsrr::Bs5Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using bs6  = FieldModel<address, bsrr::Bs6Pos,  bsrr::Bs6Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using bs7  = FieldModel<address, bsrr::Bs7Pos,  bsrr::Bs7Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using bs8  = FieldModel<address, bsrr::Bs8Pos,  bsrr::Bs8Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using bs9  = FieldModel<address, bsrr::Bs9Pos,  bsrr::Bs9Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using bs10 = FieldModel<address, bsrr::Bs10Pos, bsrr::Bs10Msk, regPolicy, FieldPolicy::WriteOnly>;
  using bs11 = FieldModel<address, bsrr::Bs11Pos, bsrr::Bs11Msk, regPolicy, FieldPolicy::WriteOnly>;
  using bs12 = FieldModel<address, bsrr::Bs12Pos, bsrr::Bs12Msk, regPolicy, FieldPolicy::WriteOnly>;
  using bs13 = FieldModel<address, bsrr::Bs13Pos, bsrr::Bs13Msk, regPolicy, FieldPolicy::WriteOnly>;
  using bs14 = FieldModel<address, bsrr::Bs14Pos, bsrr::Bs14Msk, regPolicy, FieldPolicy::WriteOnly>;
  using bs15 = FieldModel<address, bsrr::Bs15Pos, bsrr::Bs15Msk, regPolicy, FieldPolicy::WriteOnly>;
  using br0  = FieldModel<address, bsrr::Br0Pos,  bsrr::Br0Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using br1  = FieldModel<address, bsrr::Br1Pos,  bsrr::Br1Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using br2  = FieldModel<address, bsrr::Br2Pos,  bsrr::Br2Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using br3  = FieldModel<address, bsrr::Br3Pos,  bsrr::Br3Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using br4  = FieldModel<address, bsrr::Br4Pos,  bsrr::Br4Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using br5  = FieldModel<address, bsrr::Br5Pos,  bsrr::Br5Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using br6  = FieldModel<address, bsrr::Br6Pos,  bsrr::Br6Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using br7  = FieldModel<address, bsrr::Br7Pos,  bsrr::Br7Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using br8  = FieldModel<address, bsrr::Br8Pos,  bsrr::Br8Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using br9  = FieldModel<address, bsrr::Br9Pos,  bsrr::Br9Msk,  regPolicy, FieldPolicy::WriteOnly>;
  using br10 = FieldModel<address, bsrr::Br10Pos, bsrr::Br10Msk, regPolicy, FieldPolicy::WriteOnly>;
  using br11 = FieldModel<address, bsrr::Br11Pos, bsrr::Br11Msk, regPolicy, FieldPolicy::WriteOnly>;
  using br12 = FieldModel<address, bsrr::Br12Pos, bsrr::Br12Msk, regPolicy, FieldPolicy::WriteOnly>;
  using br13 = FieldModel<address, bsrr::Br13Pos, bsrr::Br13Msk, regPolicy, FieldPolicy::WriteOnly>;
  using br14 = FieldModel<address, bsrr::Br14Pos, bsrr::Br14Msk, regPolicy, FieldPolicy::WriteOnly>;
  using br15 = FieldModel<address, bsrr::Br15Pos, bsrr::Br15Msk, regPolicy, FieldPolicy::WriteOnly>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class LckrReg: public RegisterModel<address, regPolicy>
{
public:
  using lck0  = FieldModel<address, lckr::Lck0Pos,  lckr::Lck0Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using lck1  = FieldModel<address, lckr::Lck1Pos,  lckr::Lck1Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using lck2  = FieldModel<address, lckr::Lck2Pos,  lckr::Lck2Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using lck3  = FieldModel<address, lckr::Lck3Pos,  lckr::Lck3Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using lck4  = FieldModel<address, lckr::Lck4Pos,  lckr::Lck4Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using lck5  = FieldModel<address, lckr::Lck5Pos,  lckr::Lck5Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using lck6  = FieldModel<address, lckr::Lck6Pos,  lckr::Lck6Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using lck7  = FieldModel<address, lckr::Lck7Pos,  lckr::Lck7Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using lck8  = FieldModel<address, lckr::Lck8Pos,  lckr::Lck8Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using lck9  = FieldModel<address, lckr::Lck9Pos,  lckr::Lck9Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using lck10 = FieldModel<address, lckr::Lck10Pos, lckr::Lck10Msk, regPolicy, FieldPolicy::ReadWrite>;
  using lck11 = FieldModel<address, lckr::Lck11Pos, lckr::Lck11Msk, regPolicy, FieldPolicy::ReadWrite>;
  using lck12 = FieldModel<address, lckr::Lck12Pos, lckr::Lck12Msk, regPolicy, FieldPolicy::ReadWrite>;
  using lck13 = FieldModel<address, lckr::Lck13Pos, lckr::Lck13Msk, regPolicy, FieldPolicy::ReadWrite>;
  using lck14 = FieldModel<address, lckr::Lck14Pos, lckr::Lck14Msk, regPolicy, FieldPolicy::ReadWrite>;
  using lck15 = FieldModel<address, lckr::Lck15Pos, lckr::Lck15Msk, regPolicy, FieldPolicy::ReadWrite>;
  using lckk  = FieldModel<address, lckr::LckkPos,  lckr::LckkMsk,  regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class AfrlReg: public RegisterModel<address, regPolicy>
{
public:
  using afsel0 = FieldModel<address, afrl::Afsel0Pos, afrl::Afsel0Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel1 = FieldModel<address, afrl::Afsel1Pos, afrl::Afsel1Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel2 = FieldModel<address, afrl::Afsel2Pos, afrl::Afsel2Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel3 = FieldModel<address, afrl::Afsel3Pos, afrl::Afsel3Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel4 = FieldModel<address, afrl::Afsel4Pos, afrl::Afsel4Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel5 = FieldModel<address, afrl::Afsel5Pos, afrl::Afsel5Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel6 = FieldModel<address, afrl::Afsel6Pos, afrl::Afsel6Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel7 = FieldModel<address, afrl::Afsel7Pos, afrl::Afsel7Msk, regPolicy, FieldPolicy::ReadWrite>;
};


template <uint32_t address, RegisterPolicy regPolicy>
class AfrhReg: public RegisterModel<address, regPolicy>
{
public:
  using afsel8  = FieldModel<address, afrh::Afsel8Pos,  afrh::Afsel8Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using afsel9  = FieldModel<address, afrh::Afsel9Pos,  afrh::Afsel9Msk,  regPolicy, FieldPolicy::ReadWrite>;
  using afsel10 = FieldModel<address, afrh::Afsel10Pos, afrh::Afsel10Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel11 = FieldModel<address, afrh::Afsel11Pos, afrh::Afsel11Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel12 = FieldModel<address, afrh::Afsel12Pos, afrh::Afsel12Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel13 = FieldModel<address, afrh::Afsel13Pos, afrh::Afsel13Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel14 = FieldModel<address, afrh::Afsel14Pos, afrh::Afsel14Msk, regPolicy, FieldPolicy::ReadWrite>;
  using afsel15 = FieldModel<address, afrh::Afsel15Pos, afrh::Afsel15Msk, regPolicy, FieldPolicy::ReadWrite>;
};


template<uint32_t address>
class GpioRegs
{
public:
  using moder   = ModerReg<address + moder::Offset, RegisterPolicy::ReadWrite>;
  using otyper  = OtyperReg<address + otyper::Offset, RegisterPolicy::ReadWrite>;
  using ospeedr = OspeedrReg<address + ospeedr::Offset, RegisterPolicy::ReadWrite>;
  using pupdr   = PupdrReg<address + pupdr::Offset, RegisterPolicy::ReadWrite>;
  using idr     = IdrReg<address + idr::Offset, RegisterPolicy::ReadOnly>;
  using odr     = OdrReg<address + odr::Offset, RegisterPolicy::ReadWrite>;
  using bsrr    = BsrrReg<address + bsrr::Offset, RegisterPolicy::WriteOnly>;
  using lckr    = LckrReg<address + lckr::Offset, RegisterPolicy::ReadWrite>;
  using afrl    = AfrlReg<address + afrl::Offset, RegisterPolicy::ReadWrite>;
  using afrh    = AfrhReg<address + afrh::Offset, RegisterPolicy::ReadWrite>;
};


using a = GpioRegs<GpioABase>;
using b = GpioRegs<GpioBBase>;
using c = GpioRegs<GpioCBase>;
using d = GpioRegs<GpioDBase>;
using e = GpioRegs<GpioEBase>;
using h = GpioRegs<GpioHBase>;

}

#endif /* STM32_F411XE_REG_GPIO_H */
