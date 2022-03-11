#ifndef TU_PORT_H
#define TU_PORT_H

#include "tusb_option.h"
#include "otg_fs/types.h"
#include "device/dcd.h"


struct TuEndpoint : public stm32::hal::OtgFsEndpoint {
  uint8_t* xferBuffer;
  tu_fifo_t* xferFifo;
  uint32_t pending;
};

#endif // !TU_PORT_H
