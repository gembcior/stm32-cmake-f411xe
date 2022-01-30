#ifndef TINYUSB_PORT_H
#define TINYUSB_PORT_H

#include "device/dcd.h"
#include <cstdint>


extern "C" {

// Device Setup
void dcd_init (uint8_t rhport);
void dcd_int_enable (uint8_t rhport);
void dcd_int_disable (uint8_t rhport);
void dcd_int_handler(uint8_t rhport);
void dcd_set_address (uint8_t rhport, uint8_t dev_addr);
void dcd_remote_wakeup(uint8_t rhport);
void dcd_connect(uint8_t rhport);
void dcd_disconnect(uint8_t rhport);

// Endpoints
bool dcd_edpt_open (uint8_t rhport, tusb_desc_endpoint_t const * desc_edpt);
void dcd_edpt_close_all (uint8_t rhport);
bool dcd_edpt_xfer (uint8_t rhport, uint8_t ep_addr, uint8_t * buffer, uint16_t total_bytes);
bool dcd_edpt_xfer_fifo (uint8_t rhport, uint8_t ep_addr, tu_fifo_t * ff, uint16_t total_bytes);
void dcd_edpt_stall (uint8_t rhport, uint8_t ep_addr);
void dcd_edpt_clear_stall (uint8_t rhport, uint8_t ep_addr);

}

#endif /* TINYUSB_PORT_H */
