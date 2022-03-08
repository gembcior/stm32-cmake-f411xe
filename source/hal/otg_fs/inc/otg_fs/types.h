#ifndef OTG_FS_TYPES_H
#define OTG_FS_TYPES_H

#include <cstdint>

namespace stm32::hal {

constexpr uint32_t MaxEndpoints = 4U;
constexpr uint32_t EndpointSize = 64U;
constexpr uint32_t EndpointFifoSize = 1280U;

enum class OtgFsPhy {
  External,
  Internal,
};


enum class OtgFsMode {
  Device,
  Host
};


enum class OtgFsInterruptMask {
  Masked,
  UnMasked,
};


enum class OtgFsInterrupt : uint32_t {
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


enum class OtgFsPeriodicFrameInterval : uint32_t {
  Fi80,
  Fi85,
  Fi90,
  Fi95,
};


enum class OtgFsSpeed : uint32_t {
  FullSpeed = 0b11,
};


enum class OtgFSNonZeroLenStatusOutHandshake : uint32_t {
  OutPacket = 0,
  StallHandshake = 1,
};


enum class OtgFsDeviceInEndpointInterrupt : uint32_t {
  Xfrc   = 0,
  Epd    = 1,
  To     = 3,
  Ittxfe = 4,
  Inepnm = 5,
  Inepne = 6,
  Nak    = 13,
};


enum class OtgFsDeviceOutEndpointInterrupt : uint32_t {
  Xfrc      = 0,
  Epd       = 1,
  Stup      = 3,
  Otepd     = 4,
  Stsphsrx  = 5,
  Outpkterr = 8,
  Berr      = 12,
  Nak       = 13,
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
  OtgFsEndpointDirection direction;
  OtgFsEndpointType type;
  uint32_t number;
  uint32_t maxPacketSize;
  uint32_t xferLen;
  uint32_t interval;
  uint8_t* buffer;
};

} // namespace

#endif /* OTG_FS_TYPES_H */
