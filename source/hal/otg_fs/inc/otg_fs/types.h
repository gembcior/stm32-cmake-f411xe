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


enum OtgFsInterrupt : uint32_t {
  Mmis               = 1,
  Otgint             = 2,
  Sof                = 3,
  Rxflvl             = 4,
  Nptxfe             = 5,
  Ginakeff           = 6,
  Goutnakeff         = 7,
  Esusp              = 10,
  Usbsusp            = 11,
  Usbrst             = 12,
  Enumdne            = 13,
  Isoodrp            = 14,
  Eopf               = 15,
  Iepint             = 18,
  Oepint             = 19,
  Iisoixfr           = 20,
  Ipxfr_incompisoout = 21,
  Hprtint            = 24,
  Hcint              = 25,
  Ptxfe              = 26,
  Cidschg            = 28,
  Discint            = 29,
  Srqint             = 30,
  Wkupint            = 31,
};


enum OtgFsOtgInterrupt : uint32_t {
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
