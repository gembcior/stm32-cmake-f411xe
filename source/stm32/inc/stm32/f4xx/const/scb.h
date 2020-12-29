#ifndef STM32_F4XX_CONST_SCB_H
#define STM32_F4XX_CONST_SCB_H

#include <cstdint>

namespace stm32::scb {
  namespace cpuid {
    constexpr uint32_t Offset         = 0x0;

    constexpr uint32_t ImplementerPos = 24;
    constexpr uint32_t ImplementerMsk = 0xFF;

    constexpr uint32_t VariantPos     = 20;
    constexpr uint32_t VariantMsk     = 0xF;

    constexpr uint32_t ConstantPos    = 16;
    constexpr uint32_t ConstantMsk    = 0xF;

    constexpr uint32_t PartnoPos      = 4;
    constexpr uint32_t PartnoMsk      = 0xFFF;

    constexpr uint32_t RevisionPos    = 0;
    constexpr uint32_t RevisionMsk    = 0xF;
  }

  namespace icsr {
    constexpr uint32_t Offset         = 0x4;

    constexpr uint32_t NmipendsetPos  = 31;
    constexpr uint32_t NmipendsetMsk  = 1;

    constexpr uint32_t PendsvsetPos   = 28;
    constexpr uint32_t PendsvsetMsk   = 1;

    constexpr uint32_t PendsvclrPos   = 27;
    constexpr uint32_t PendsvclrMsk   = 1;

    constexpr uint32_t PendstsetPos   = 26;
    constexpr uint32_t PendstsetMsk   = 1;

    constexpr uint32_t PendstclrPos   = 25;
    constexpr uint32_t PendstclrMsk   = 1;

    constexpr uint32_t IsrpreemptPos  = 23;
    constexpr uint32_t IsrpreemptMsk  = 1;

    constexpr uint32_t IsrpendingPos  = 22;
    constexpr uint32_t IsrpendingMsk  = 1;

    constexpr uint32_t VectpendingPos = 12;
    constexpr uint32_t VectpendingMsk = 0x1FF;

    constexpr uint32_t RettobasePos   = 11;
    constexpr uint32_t RettobaseMsk   = 1;

    constexpr uint32_t VectactivePos  = 0;
    constexpr uint32_t VectactiveMsk  = 0x1FF;
  }

  namespace vtor {
    constexpr uint32_t Offset    = 0x8;

    constexpr uint32_t TbloffPos = 7;
    constexpr uint32_t TbloffMsk = 0x1FFFFFF;
  }

  namespace aircr {
    constexpr uint32_t Offset           = 0xC;

    constexpr uint32_t VectkeyPos       = 16;
    constexpr uint32_t VectkeyMsk       = 0xFFFF;

    constexpr uint32_t VectkeystatPos   = 16;
    constexpr uint32_t VectkeystatMsk   = 0xFFFF;

    constexpr uint32_t EndianessPos     = 15;
    constexpr uint32_t EndianessMsk     = 1;

    constexpr uint32_t PrigroupPos      = 8;
    constexpr uint32_t PrigroupMsk      = 7;

    constexpr uint32_t SysresetreqPos   = 2;
    constexpr uint32_t SysresetreqMsk   = 1;

    constexpr uint32_t VectclractivePos = 1;
    constexpr uint32_t VectclractiveMsk = 1;

    constexpr uint32_t VectresetPos     = 0;
    constexpr uint32_t VectresetMsk     = 1;
  }

  namespace scr {
    constexpr uint32_t Offset         = 0x10;

    constexpr uint32_t SevonpendPos   = 4;
    constexpr uint32_t SevonpendMsk   = 1;

    constexpr uint32_t SleepdeepPos   = 2;
    constexpr uint32_t SleepdeepMsk   = 1;

    constexpr uint32_t SleeponexitPos = 1;
    constexpr uint32_t SleeponexitMsk = 1;
  }

  namespace ccr {
    constexpr uint32_t Offset            = 0x14;

    constexpr uint32_t StkalignPos       = 9;
    constexpr uint32_t StkalignMsk       = 1;

    constexpr uint32_t BfhfnmignPos      = 8;
    constexpr uint32_t BfhfnmignMsk      = 1;

    constexpr uint32_t Div0TrpPos        = 4;
    constexpr uint32_t Div0TrpMsk        = 1;

    constexpr uint32_t UnalignTrpPos     = 3;
    constexpr uint32_t UnalignTrpMsk     = 1;

    constexpr uint32_t UsersetmpendPos   = 1;
    constexpr uint32_t UsersetmpendMsk   = 1;

    constexpr uint32_t NonbasethrdenaPos = 0;
    constexpr uint32_t NonbasethrdenaMsk = 1;
  }

  namespace shpr1 {
    constexpr uint32_t Offset            = 0x18;
  }

  namespace shpr2 {
    constexpr uint32_t Offset            = 0x1C;
  }

  namespace shpr3 {
    constexpr uint32_t Offset            = 0x20;
  }

  namespace shcsr {
    constexpr uint32_t Offset            = 0x24;

    constexpr uint32_t UsgfaultenaPos    = 18;
    constexpr uint32_t UsgfaultenaMsk    = 1;

    constexpr uint32_t BusfaultenaPos    = 17;
    constexpr uint32_t BusfaultenaMsk    = 1;

    constexpr uint32_t MemfaultenaPos    = 16;
    constexpr uint32_t MemfaultenaMsk    = 1;

    constexpr uint32_t SvcallpendedPos   = 15;
    constexpr uint32_t SvcallpendedMsk   = 1;

    constexpr uint32_t BusfaultpendedPos = 14;
    constexpr uint32_t BusfaultpendedMsk = 1;

    constexpr uint32_t MemfaultpendedPos = 13;
    constexpr uint32_t MemfaultpendedMsk = 1;

    constexpr uint32_t UsgfaultpendedPos = 12;
    constexpr uint32_t UsgfaultpendedMsk = 1;

    constexpr uint32_t SystickactPos     = 11;
    constexpr uint32_t SystickactMsk     = 1;

    constexpr uint32_t PendsvactPos      = 10;
    constexpr uint32_t PendsvactMsk      = 1;

    constexpr uint32_t MonitoractPos     = 8;
    constexpr uint32_t MonitoractMsk     = 1;

    constexpr uint32_t SvcallactPos      = 7;
    constexpr uint32_t SvcallactMsk      = 1;

    constexpr uint32_t UsgfaultactPos    = 3;
    constexpr uint32_t UsgfaultactMsk    = 1;

    constexpr uint32_t BusfaultactPos    = 1;
    constexpr uint32_t BusfaultactMsk    = 1;

    constexpr uint32_t MemfaultactPos    = 0;
    constexpr uint32_t MemfaultactMsk    = 1;
  }

  namespace cfsr {
    constexpr uint32_t Offset         = 0x28;

    constexpr uint32_t UsgfaultsrPos  = 16;
    constexpr uint32_t UsgfaultsrMsk  = 0xFFFF;

    constexpr uint32_t BusfaultsrPos  = 8;
    constexpr uint32_t BusfaultsrMsk  = 0xFF;

    constexpr uint32_t MemfaultsrPos  = 0;
    constexpr uint32_t MemfaultsrMsk  = 0xFF;

    constexpr uint32_t MmarvalidPos   = MemfaultactPos + 7;
    constexpr uint32_t MmarvalidMsk   = 1;

    constexpr uint32_t MlsperrPos     = MemfaultactPos + 5;
    constexpr uint32_t MlsperrMsk     = 1;

    constexpr uint32_t MstkerrPos     = MemfaultactPos + 4;
    constexpr uint32_t MstkerrMsk     = 1;

    constexpr uint32_t MunstkerrPos   = MemfaultactPos + 3;
    constexpr uint32_t MunstkerrMsk   = 1;

    constexpr uint32_t DaccviolPos    = MemfaultactPos + 1;
    constexpr uint32_t DaccviolMsk    = 1;

    constexpr uint32_t IaccviolPos    = MemfaultactPos + 0;
    constexpr uint32_t IaccviolMsk    = 1;

    constexpr uint32_t BfarvalidPos   = BusfaultsrPos + 7;
    constexpr uint32_t BfarvalidMsk   = 1;

    constexpr uint32_t LsperrPos      = BusfaultsrPos + 5;
    constexpr uint32_t LsperrMsk      = 1;

    constexpr uint32_t StkerrPos      = BusfaultsrPos + 4;
    constexpr uint32_t StkerrMsk      = 1;

    constexpr uint32_t UnstkerrPos    = BusfaultsrPos + 3;
    constexpr uint32_t UnstkerrMsk    = 1;

    constexpr uint32_t ImpreciserrPos = BusfaultsrPos + 2;
    constexpr uint32_t ImpreciserrMsk = 1;

    constexpr uint32_t PreciserrPos   = BusfaultsrPos + 1;
    constexpr uint32_t PreciserrMsk   = 1;

    constexpr uint32_t IbuserrPos     = BusfaultsrPos + 0;
    constexpr uint32_t IbuserrMsk     = 1;

    constexpr uint32_t DivbyzeroPos   = UsgfaultsrPos + 9;
    constexpr uint32_t DivbyzeroMsk   = 1;

    constexpr uint32_t UnalignedPos   = UsgfaultsrPos + 8;
    constexpr uint32_t UnalignedMsk   = 1;

    constexpr uint32_t NocpPos        = UsgfaultsrPos + 3;
    constexpr uint32_t NocpMsk        = 1;

    constexpr uint32_t InvpcPos       = UsgfaultsrPos + 2;
    constexpr uint32_t InvpcMsk       = 1;

    constexpr uint32_t InvstatePos    = UsgfaultsrPos + 1;
    constexpr uint32_t InvstateMsk    = 1;

    constexpr uint32_t UndefinstrPos  = UsgfaultsrPos + 0;
    constexpr uint32_t UndefinstrMsk  = 1;
  }

  namespace hfsr {
    constexpr uint32_t Offset      = 0x2C;

    constexpr uint32_t DebugevtPos = 31;
    constexpr uint32_t DebugevtMsk = 1;

    constexpr uint32_t ForcedPos   = 30;
    constexpr uint32_t ForcedMsk   = 1;

    constexpr uint32_t VecttblPos  = 1;
    constexpr uint32_t VecttblMsk  = 1;
  }

  namespace mmar {
    constexpr uint32_t Offset      = 0x34;
  }

  namespace bfar {
    constexpr uint32_t Offset      = 0x38;
  }

  namespace afsr {
    constexpr uint32_t Offset      = 0x3C;
  }

  namespace actlr {
    constexpr uint32_t Offset        = 0x8;

    constexpr uint32_t DisoofpPos    = 9;
    constexpr uint32_t DisoofpMsk    = 1;

    constexpr uint32_t DisfpcaPos    = 8;
    constexpr uint32_t DisfpcaMsk    = 1;

    constexpr uint32_t DisfoldPos    = 2;
    constexpr uint32_t DisfoldMsk    = 1;

    constexpr uint32_t DisdefwbufPos = 1;
    constexpr uint32_t DisdefwbufMsk = 1;

    constexpr uint32_t DismcycintPos = 0;
    constexpr uint32_t DismcycintMsk = 1;
  }

  namespace cpacr {
    constexpr uint32_t Offset    = 0x88;

    constexpr uint32_t Cp10Pos = 20;
    constexpr uint32_t Cp10Msk = 0x3;

    constexpr uint32_t Cp11Pos = 22;
    constexpr uint32_t Cp11Msk = 0x3;
  }
}

#endif /* STM32_F4XX_CONST_SCB_H */
