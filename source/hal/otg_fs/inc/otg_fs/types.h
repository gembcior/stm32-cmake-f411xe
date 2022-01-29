#ifndef OTG_FS_TYPES_H
#define OTG_FS_TYPES_H

#include <cstdint>

namespace stm32::hal {

enum class OtgFsPhy {
  External,
  Internal,
};


enum class OtgFsMode {
  Device,
  Host
};


enum class OtgFsInterruptMask {
  Mmism,
  Otgint,
  Sofm,
  Rxflvlm,
  Nptxfem,
  Ginakeffm,
  Gonakeffm,
  Esuspm,
  Usbsuspm,
  Usbrst,
  Enumdnem,
  Isoodrpm,
  Eopfm,
  Iepint,
  Oepint,
  Iisoixfrm,
  Iisooxfrm,
  Ipxfrm,
  Prtim,
  Hcim,
  Ptxfem,
  Cidschgm,
  Discint,
  Srqim,
  Wuim,
};


enum class OtgFsPeriodicFrameInterval : uint32_t {
  Fi80,
  Fi85,
  Fi90,
  Fi95,
};


enum class OtgFsSpeed : uint32_t {
  FullSpeed = 0b11,
};


enum class OtgFsDeviceInEndpointInterruptMask {
  Xfrcm,
  Epdm,
  Tom,
  Ittxfemsk,
  Inepnmm,
  Inepnem,
  Nakm,
};


enum class OtgFsDeviceOutEndpointInterruptMask {
  Xfrcm,
  Epdm,
  Stupm,
  Stsphsrxm,
  Outpkterrm,
  Berrm,
  Nakmsk,
};


enum class OtgFsEndpointDirection {
  Out,
  In,
};


enum class OtgFsEndpointType {
  Control,
  Isochronous,
  Bulk,
  Interrupt,
};


struct OtgFsEndpoint
{
  uint32_t number;
  OtgFsEndpointDirection direction;
  OtgFsEndpointType type;
  uint32_t maxPacketSize;
  uint32_t xferLen;
  uint32_t interval;
};

} // namespace

#endif /* OTG_FS_TYPES_H */
