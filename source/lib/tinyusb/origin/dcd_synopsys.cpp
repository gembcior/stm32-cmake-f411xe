/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Scott Shawcroft, 2019 William D. Jones for Adafruit Industries
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 * Copyright (c) 2020 Jan Duempelmann
 * Copyright (c) 2020 Reinhard Panhuber
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * This file is part of the TinyUSB stack.
 */

#include "tusb_option.h"
#include "stm32f4xx.h"
#include "device/dcd.h"

// Since TinyUSB doesn't use SOF for now, and this interrupt too often (1ms interval)
// We disable SOF for now until needed later on
#define USE_SOF     0

#define EP_MAX_FS       USB_OTG_FS_MAX_IN_ENDPOINTS
#define EP_FIFO_SIZE_FS USB_OTG_FS_TOTAL_FIFO_SIZE
#define EP_MAX_HS       USB_OTG_HS_MAX_IN_ENDPOINTS
#define EP_FIFO_SIZE_HS USB_OTG_HS_TOTAL_FIFO_SIZE

#define EP_MAX            EP_MAX_FS
#define EP_FIFO_SIZE      EP_FIFO_SIZE_FS
#define RHPORT_REGS_BASE  USB_OTG_FS_PERIPH_BASE
#define RHPORT_IRQn       OTG_FS_IRQn

#define GLOBAL_BASE(_port)     ((USB_OTG_GlobalTypeDef*) RHPORT_REGS_BASE)
#define DEVICE_BASE(_port)     (USB_OTG_DeviceTypeDef *) (RHPORT_REGS_BASE + USB_OTG_DEVICE_BASE)
#define OUT_EP_BASE(_port)     (USB_OTG_OUTEndpointTypeDef *) (RHPORT_REGS_BASE + USB_OTG_OUT_ENDPOINT_BASE)
#define IN_EP_BASE(_port)      (USB_OTG_INEndpointTypeDef *) (RHPORT_REGS_BASE + USB_OTG_IN_ENDPOINT_BASE)
#define FIFO_BASE(_port, _x)   ((volatile uint32_t *) (RHPORT_REGS_BASE + USB_OTG_FIFO_BASE + (_x) * USB_OTG_FIFO_SIZE))


/* D-RAL */
extern uint32_t TxFifoAllocatedWords;
extern bool OutEndpointClosed;
extern uint32_t Endpoint0Pending[2];
extern uint32_t SetupPacket[2];
#include "otg_fs/OtgFsDeviceHal.h"
using namespace stm32::hal;
#include "tinyusb/port.h"
extern TuEndpoint& getEndpoint(uint32_t number, OtgFsEndpointDirection direction);
#include "objects/objects.h"
using namespace stm32::objects;
#include "dral/otg_fs_device.h"
/* D-RAL END */

enum {
  DCD_HIGH_SPEED        = 0, // Highspeed mode
  DCD_FULL_SPEED_USE_HS = 1, // Full speed in Highspeed port (probably with internal PHY)
  DCD_FULL_SPEED        = 3, // Full speed with internal PHY
};


typedef struct {
  uint8_t * buffer;
  tu_fifo_t * ff;
  uint16_t total_len;
  uint16_t max_size;
  uint8_t interval;
} xfer_ctl_t;

typedef volatile uint32_t * usb_fifo_t;


// Calculate the RX FIFO size according to recommendations from reference manual
static inline uint16_t calc_rx_ff_size(uint16_t ep_size)
{
  return 15 + 2*(ep_size/4) + 2*EP_MAX;
}

static void update_grxfsiz(uint8_t rhport)
{
  (void) rhport;

  USB_OTG_GlobalTypeDef * usb_otg = GLOBAL_BASE(rhport);

  // Determine largest EP size for RX FIFO
  uint16_t max_epsize = 0;
  for (uint8_t epnum = 0; epnum < EP_MAX; epnum++)
  {
    auto& endpoint = getEndpoint(epnum, OtgFsEndpointDirection::Out);
    max_epsize = tu_max16(max_epsize, endpoint.maxPacketSize);
  }

  // Update size of RX FIFO
  usb_otg->GRXFSIZ = calc_rx_ff_size(max_epsize);
}

// Setup the control endpoint 0.
static void bus_reset(uint8_t rhport)
{
  (void) rhport;

  USB_OTG_GlobalTypeDef * usb_otg = GLOBAL_BASE(rhport);
  USB_OTG_DeviceTypeDef * dev = DEVICE_BASE(rhport);
  USB_OTG_OUTEndpointTypeDef * out_ep = OUT_EP_BASE(rhport);
  USB_OTG_INEndpointTypeDef * in_ep = IN_EP_BASE(rhport);

//  tu_memclr(xfer_status, sizeof(xfer_status));
  OutEndpointClosed = false;

  // clear device address
  dev->DCFG &= ~USB_OTG_DCFG_DAD_Msk;

  // 1. NAK for all OUT endpoints
  for(uint8_t n = 0; n < EP_MAX; n++) {
    out_ep[n].DOEPCTL |= USB_OTG_DOEPCTL_SNAK;
  }

  // 2. Un-mask interrupt bits
  dev->DAINTMSK = (1 << USB_OTG_DAINTMSK_OEPM_Pos) | (1 << USB_OTG_DAINTMSK_IEPM_Pos);
  dev->DOEPMSK = USB_OTG_DOEPMSK_STUPM | USB_OTG_DOEPMSK_XFRCM;
  dev->DIEPMSK = USB_OTG_DIEPMSK_TOM | USB_OTG_DIEPMSK_XFRCM;

  // "USB Data FIFOs" section in reference manual
  // Peripheral FIFO architecture
  //
  // The FIFO is split up in a lower part where the RX FIFO is located and an upper part where the TX FIFOs start.
  // We do this to allow the RX FIFO to grow dynamically which is possible since the free space is located
  // between the RX and TX FIFOs. This is required by ISO OUT EPs which need a bigger FIFO than the standard
  // configuration done below.
  //
  // Dynamically FIFO sizes are of interest only for ISO EPs since all others are usually not opened and closed.
  // All EPs other than ISO are opened as soon as the driver starts up i.e. when the host sends a
  // configure interface command. Hence, all IN EPs other the ISO will be located at the top. IN ISO EPs are usually
  // opened when the host sends an additional command: setInterface. At this point in time
  // the ISO EP will be located next to the free space and can change its size. In case more IN EPs change its size
  // an additional memory
  //
  // --------------- 320 or 1024 ( 1280 or 4096 bytes )
  // | IN FIFO 0   |
  // --------------- (320 or 1024) - 16
  // | IN FIFO 1   |
  // --------------- (320 or 1024) - 16 - x
  // |   . . . .   |
  // --------------- (320 or 1024) - 16 - x - y - ... - z
  // | IN FIFO MAX |
  // ---------------
  // |    FREE     |
  // --------------- GRXFSIZ
  // | OUT FIFO    |
  // | ( Shared )  |
  // --------------- 0
  //
  // According to "FIFO RAM allocation" section in RM, FIFO RAM are allocated as follows (each word 32-bits):
  // - Each EP IN needs at least max packet size, 16 words is sufficient for EP0 IN
  //
  // - All EP OUT shared a unique OUT FIFO which uses
  //   - 13 for setup packets + control words (up to 3 setup packets).
  //   - 1 for global NAK (not required/used here).
  //   - Largest-EPsize / 4 + 1. ( FS: 64 bytes, HS: 512 bytes). Recommended is  "2 x (Largest-EPsize/4) + 1"
  //   - 2 for each used OUT endpoint
  //
  //   Therefore GRXFSIZ = 13 + 1 + 1 + 2 x (Largest-EPsize/4) + 2 x EPOUTnum
  //   - FullSpeed (64 Bytes ): GRXFSIZ = 15 + 2 x  16 + 2 x EP_MAX = 47  + 2 x EP_MAX
  //   - Highspeed (512 bytes): GRXFSIZ = 15 + 2 x 128 + 2 x EP_MAX = 271 + 2 x EP_MAX
  //
  //   NOTE: Largest-EPsize & EPOUTnum is actual used endpoints in configuration. Since DCD has no knowledge
  //   of the overall picture yet. We will use the worst scenario: largest possible + EP_MAX
  //
  //   For Isochronous, largest EP size can be 1023/1024 for FS/HS respectively. In addition if multiple ISO
  //   are enabled at least "2 x (Largest-EPsize/4) + 1" are recommended.  Maybe provide a macro for application to
  //   overwrite this.

  usb_otg->GRXFSIZ = calc_rx_ff_size(TUD_OPT_HIGH_SPEED ? 512 : 64);

  TxFifoAllocatedWords = 16;

  // Control IN uses FIFO 0 with 64 bytes ( 16 32-bit word )
  usb_otg->DIEPTXF0_HNPTXFSIZ = (16 << USB_OTG_TX0FD_Pos) | (EP_FIFO_SIZE/4 - TxFifoAllocatedWords);

  // Fixed control EP0 size to 64 bytes
  in_ep[0].DIEPCTL &= ~(0x03 << USB_OTG_DIEPCTL_MPSIZ_Pos);

  getEndpoint(0, OtgFsEndpointDirection::In).maxPacketSize = 64;
  getEndpoint(0, OtgFsEndpointDirection::Out).maxPacketSize = 64;

  out_ep[0].DOEPTSIZ |= (3 << USB_OTG_DOEPTSIZ_STUPCNT_Pos);

  usb_otg->GINTMSK |= USB_OTG_GINTMSK_OEPINT | USB_OTG_GINTMSK_IEPINT;
}

// Set turn-around timeout according to link speed
uint32_t SystemCoreClock = 96000000U;

static tusb_speed_t get_speed(uint8_t rhport)
{
  (void) rhport;
  USB_OTG_DeviceTypeDef * dev = DEVICE_BASE(rhport);
  uint32_t const enum_spd = (dev->DSTS & USB_OTG_DSTS_ENUMSPD_Msk) >> USB_OTG_DSTS_ENUMSPD_Pos;
  return (enum_spd == DCD_HIGH_SPEED) ? TUSB_SPEED_HIGH : TUSB_SPEED_FULL;
}


static void dcd_edpt_disable (uint8_t rhport, uint8_t ep_addr, bool stall)
{
  (void) rhport;

  USB_OTG_GlobalTypeDef * usb_otg = GLOBAL_BASE(rhport);
  USB_OTG_DeviceTypeDef * dev = DEVICE_BASE(rhport);
  USB_OTG_OUTEndpointTypeDef * out_ep = OUT_EP_BASE(rhport);
  USB_OTG_INEndpointTypeDef * in_ep = IN_EP_BASE(rhport);

  uint8_t const epnum = tu_edpt_number(ep_addr);
  uint8_t const dir   = tu_edpt_dir(ep_addr);

  if(dir == TUSB_DIR_IN) {
    // Only disable currently enabled non-control endpoint
    if ( (epnum == 0) || !(in_ep[epnum].DIEPCTL & USB_OTG_DIEPCTL_EPENA) ){
      in_ep[epnum].DIEPCTL |= USB_OTG_DIEPCTL_SNAK | (stall ? USB_OTG_DIEPCTL_STALL : 0);
    } else {
      // Stop transmitting packets and NAK IN xfers.
      in_ep[epnum].DIEPCTL |= USB_OTG_DIEPCTL_SNAK;
      while((in_ep[epnum].DIEPINT & USB_OTG_DIEPINT_INEPNE) == 0);

      // Disable the endpoint.
      in_ep[epnum].DIEPCTL |= USB_OTG_DIEPCTL_EPDIS | (stall ? USB_OTG_DIEPCTL_STALL : 0);
      while((in_ep[epnum].DIEPINT & USB_OTG_DIEPINT_EPDISD_Msk) == 0);
      in_ep[epnum].DIEPINT = USB_OTG_DIEPINT_EPDISD;
    }

    // Flush the FIFO, and wait until we have confirmed it cleared.
    usb_otg->GRSTCTL |= (epnum << USB_OTG_GRSTCTL_TXFNUM_Pos);
    usb_otg->GRSTCTL |= USB_OTG_GRSTCTL_TXFFLSH;
    while((usb_otg->GRSTCTL & USB_OTG_GRSTCTL_TXFFLSH_Msk) != 0);
  } else {
    // Only disable currently enabled non-control endpoint
    if ( (epnum == 0) || !(out_ep[epnum].DOEPCTL & USB_OTG_DOEPCTL_EPENA) ){
      out_ep[epnum].DOEPCTL |= stall ? USB_OTG_DOEPCTL_STALL : 0;
    } else {
      // Asserting GONAK is required to STALL an OUT endpoint.
      // Simpler to use polling here, we don't use the "B"OUTNAKEFF interrupt
      // anyway, and it can't be cleared by user code. If this while loop never
      // finishes, we have bigger problems than just the stack.
      dev->DCTL |= USB_OTG_DCTL_SGONAK;
      while((usb_otg->GINTSTS & USB_OTG_GINTSTS_BOUTNAKEFF_Msk) == 0);

      // Ditto here- disable the endpoint.
      out_ep[epnum].DOEPCTL |= USB_OTG_DOEPCTL_EPDIS | (stall ? USB_OTG_DOEPCTL_STALL : 0);
      while((out_ep[epnum].DOEPINT & USB_OTG_DOEPINT_EPDISD_Msk) == 0);
      out_ep[epnum].DOEPINT = USB_OTG_DOEPINT_EPDISD;

      // Allow other OUT endpoints to keep receiving.
      dev->DCTL |= USB_OTG_DCTL_CGONAK;
    }
  }
}


void dcd_edpt_stall (uint8_t rhport, uint8_t ep_addr)
{
  dcd_edpt_disable(rhport, ep_addr, true);
}

void dcd_edpt_clear_stall (uint8_t rhport, uint8_t ep_addr)
{
  (void) rhport;

  USB_OTG_OUTEndpointTypeDef * out_ep = OUT_EP_BASE(rhport);
  USB_OTG_INEndpointTypeDef * in_ep = IN_EP_BASE(rhport);

  uint8_t const epnum = tu_edpt_number(ep_addr);
  uint8_t const dir   = tu_edpt_dir(ep_addr);

  // Clear stall and reset data toggle
  if(dir == TUSB_DIR_IN) {
    in_ep[epnum].DIEPCTL &= ~USB_OTG_DIEPCTL_STALL;
    in_ep[epnum].DIEPCTL |= USB_OTG_DIEPCTL_SD0PID_SEVNFRM;
  } else {
    out_ep[epnum].DOEPCTL &= ~USB_OTG_DOEPCTL_STALL;
    out_ep[epnum].DOEPCTL |= USB_OTG_DOEPCTL_SD0PID_SEVNFRM;
  }
}

/*------------------------------------------------------------------*/

static void handle_rxflvl_ints(uint8_t rhport, USB_OTG_OUTEndpointTypeDef * out_ep) {
  USB_OTG_GlobalTypeDef * usb_otg = GLOBAL_BASE(rhport);
  usb_fifo_t rx_fifo = FIFO_BASE(rhport, 0);

  // Pop control word off FIFO
  uint32_t ctl_word = usb_otg->GRXSTSP;
  uint8_t pktsts = (ctl_word & USB_OTG_GRXSTSP_PKTSTS_Msk) >> USB_OTG_GRXSTSP_PKTSTS_Pos;
  uint8_t epnum = (ctl_word &  USB_OTG_GRXSTSP_EPNUM_Msk) >>  USB_OTG_GRXSTSP_EPNUM_Pos;
  uint16_t bcnt = (ctl_word & USB_OTG_GRXSTSP_BCNT_Msk) >> USB_OTG_GRXSTSP_BCNT_Pos;

  auto& device = getObject<OtgFsDeviceHal>();

  switch(pktsts) {
    case 0x01: // Global OUT NAK (Interrupt)
      break;

    case 0x02: // Out packet recvd
    {
      auto& endpoint = getEndpoint(epnum, OtgFsEndpointDirection::Out);

      // Read packet off RxFIFO
      if (endpoint.xferFifo)
      {
        // Ring buffer
        tu_fifo_write_n_const_addr_full_words(endpoint.xferFifo, (const void *) rx_fifo, bcnt);
      }
      else
      {
        // Linear buffer
        device.readFifoPacket(endpoint.xferBuffer, bcnt);

        // Increment pointer to xfer data
        endpoint.xferBuffer += bcnt;
      }

      // Truncate transfer length in case of short packet
      if(bcnt < endpoint.maxPacketSize) {
        endpoint.xferLen -= (out_ep[epnum].DOEPTSIZ & USB_OTG_DOEPTSIZ_XFRSIZ_Msk) >> USB_OTG_DOEPTSIZ_XFRSIZ_Pos;
        if(epnum == 0) {
          endpoint.xferLen -= Endpoint0Pending[TUSB_DIR_OUT];
          Endpoint0Pending[TUSB_DIR_OUT] = 0;
          endpoint.xferLen = 0;
        }
      }
    }
    break;

    case 0x03: // Out packet done (Interrupt)
      break;

    case 0x04: // Setup packet done (Interrupt)
      out_ep[epnum].DOEPTSIZ |= (3 << USB_OTG_DOEPTSIZ_STUPCNT_Pos);
      break;

    case 0x06: // Setup packet recvd
      // We can receive up to three setup packets in succession, but
      // only the last one is valid.
      SetupPacket[0] = (* rx_fifo);
      SetupPacket[1] = (* rx_fifo);
      break;

    default: // Invalid
      TU_BREAKPOINT();
      break;
  }
}

static void handle_epout_ints(uint8_t rhport, USB_OTG_DeviceTypeDef * dev, USB_OTG_OUTEndpointTypeDef * out_ep) {
  // DAINT for a given EP clears when DOEPINTx is cleared.
  // OEPINT will be cleared when DAINT's out bits are cleared.
  for(uint8_t n = 0; n < EP_MAX; n++) {
    auto& endpoint = getEndpoint(n, OtgFsEndpointDirection::Out);

    if(dev->DAINT & (1 << (USB_OTG_DAINT_OEPINT_Pos + n))) {
      // SETUP packet Setup Phase done.
      if(out_ep[n].DOEPINT & USB_OTG_DOEPINT_STUP) {
        out_ep[n].DOEPINT =  USB_OTG_DOEPINT_STUP;
        dcd_event_setup_received(rhport, (uint8_t*) &SetupPacket[0], true);
      }

      // OUT XFER complete
      if(out_ep[n].DOEPINT & USB_OTG_DOEPINT_XFRC) {
        out_ep[n].DOEPINT = USB_OTG_DOEPINT_XFRC;

        // EP0 can only handle one packet
        if((n == 0) && Endpoint0Pending[TUSB_DIR_OUT]) {
          // Schedule another packet to be received.
          endpoint.xferLen = Endpoint0Pending[TUSB_DIR_OUT];
//          edpt_schedule_packets2(rhport, n, TUSB_DIR_OUT, Endpoint0Pending[TUSB_DIR_OUT]);
//          edpt_schedule_packets2(rhport, n, TUSB_DIR_OUT, endpoint.xferLen);
          auto& device = getObject<OtgFsDeviceHal>();
          device.startXfer(endpoint);
        } else {
          dcd_event_xfer_complete(rhport, n, endpoint.xferLen, XFER_RESULT_SUCCESS, true);
        }
      }
    }
  }
}

static void handle_epin_ints(uint8_t rhport, USB_OTG_DeviceTypeDef * dev, USB_OTG_INEndpointTypeDef * in_ep) {
  // DAINT for a given EP clears when DIEPINTx is cleared.
  // IEPINT will be cleared when DAINT's out bits are cleared.
  for ( uint8_t n = 0; n < EP_MAX; n++ )
  {
    auto& endpoint = getEndpoint(n, OtgFsEndpointDirection::In);

    if ( dev->DAINT & (1 << (USB_OTG_DAINT_IEPINT_Pos + n)) )
    {
      // IN XFER complete (entire xfer).
      if ( in_ep[n].DIEPINT & USB_OTG_DIEPINT_XFRC )
      {
        in_ep[n].DIEPINT = USB_OTG_DIEPINT_XFRC;

        // EP0 can only handle one packet
        if((n == 0) && Endpoint0Pending[TUSB_DIR_IN]) {
          // Schedule another packet to be transmitted.
          endpoint.xferLen = Endpoint0Pending[TUSB_DIR_IN];
//          edpt_schedule_packets2(rhport, n, TUSB_DIR_IN, Endpoint0Pending[TUSB_DIR_IN]);
//          edpt_schedule_packets2(rhport, n, TUSB_DIR_IN, endpoint.xferLen);
          auto& device = getObject<OtgFsDeviceHal>();
          device.startXfer(endpoint);
        } else {
          dcd_event_xfer_complete(rhport, n | TUSB_DIR_IN_MASK, endpoint.xferLen, XFER_RESULT_SUCCESS, true);
        }
      }

      // XFER FIFO empty
      if ( (in_ep[n].DIEPINT & USB_OTG_DIEPINT_TXFE) && (dev->DIEPEMPMSK & (1 << n)) )
      {
        // DIEPINT's TXFE bit is read-only, software cannot clear it.
        // It will only be cleared by hardware when written bytes is more than
        // - 64 bytes or
        // - Half of TX FIFO size (configured by DIEPTXF)

        uint16_t remaining_packets = (in_ep[n].DIEPTSIZ & USB_OTG_DIEPTSIZ_PKTCNT_Msk) >> USB_OTG_DIEPTSIZ_PKTCNT_Pos;

        // Process every single packet (only whole packets can be written to fifo)
        for(uint16_t i = 0; i < remaining_packets; i++)
        {
          uint16_t const remaining_bytes = (in_ep[n].DIEPTSIZ & USB_OTG_DIEPTSIZ_XFRSIZ_Msk) >> USB_OTG_DIEPTSIZ_XFRSIZ_Pos;

          // Packet can not be larger than ep max size
          uint16_t const packet_size = tu_min16(remaining_bytes, endpoint.maxPacketSize);

          // It's only possible to write full packets into FIFO. Therefore DTXFSTS register of current
          // EP has to be checked if the buffer can take another WHOLE packet
          if(packet_size > ((in_ep[n].DTXFSTS & USB_OTG_DTXFSTS_INEPTFSAV_Msk) << 2)) break;

          // Push packet to Tx-FIFO
          if (endpoint.xferFifo)
          {
            usb_fifo_t tx_fifo = FIFO_BASE(rhport, n);
            tu_fifo_read_n_const_addr_full_words(endpoint.xferFifo, (void *) tx_fifo, packet_size);
          }
          else
          {
            auto& device = getObject<OtgFsDeviceHal>();
            device.writeFifoPacket(n, endpoint.xferBuffer, packet_size);

            // Increment pointer to xfer data
            endpoint.xferBuffer += packet_size;
          }
        }

        // Turn off TXFE if all bytes are written.
        if (((in_ep[n].DIEPTSIZ & USB_OTG_DIEPTSIZ_XFRSIZ_Msk) >> USB_OTG_DIEPTSIZ_XFRSIZ_Pos) == 0)
        {
          dev->DIEPEMPMSK &= ~(1 << n);
        }
      }
    }
  }
}

void dcd_int_handler(uint8_t rhport)
{
  USB_OTG_GlobalTypeDef * usb_otg = GLOBAL_BASE(rhport);
  USB_OTG_DeviceTypeDef * dev = DEVICE_BASE(rhport);
  USB_OTG_OUTEndpointTypeDef * out_ep = OUT_EP_BASE(rhport);
  USB_OTG_INEndpointTypeDef * in_ep = IN_EP_BASE(rhport);

  uint32_t const int_status = usb_otg->GINTSTS & usb_otg->GINTMSK;

  if(int_status & USB_OTG_GINTSTS_USBRST)
  {
    // USBRST is start of reset.
    usb_otg->GINTSTS = USB_OTG_GINTSTS_USBRST;
    bus_reset(rhport);
  }

  if(int_status & USB_OTG_GINTSTS_ENUMDNE)
  {
    // ENUMDNE is the end of reset where speed of the link is detected

    usb_otg->GINTSTS = USB_OTG_GINTSTS_ENUMDNE;

    tusb_speed_t const speed = get_speed(rhport);

    dcd_event_bus_reset(rhport, speed, true);
  }

  if(int_status & USB_OTG_GINTSTS_USBSUSP)
  {
    usb_otg->GINTSTS = USB_OTG_GINTSTS_USBSUSP;
    dcd_event_bus_signal(rhport, DCD_EVENT_SUSPEND, true);
  }

  if(int_status & USB_OTG_GINTSTS_WKUINT)
  {
    usb_otg->GINTSTS = USB_OTG_GINTSTS_WKUINT;
    dcd_event_bus_signal(rhport, DCD_EVENT_RESUME, true);
  }

  // TODO check USB_OTG_GINTSTS_DISCINT for disconnect detection
  // if(int_status & USB_OTG_GINTSTS_DISCINT)

  if(int_status & USB_OTG_GINTSTS_OTGINT)
  {
    // OTG INT bit is read-only
    uint32_t const otg_int = usb_otg->GOTGINT;

    if (otg_int & USB_OTG_GOTGINT_SEDET)
    {
      dcd_event_bus_signal(rhport, DCD_EVENT_UNPLUGGED, true);
    }

    usb_otg->GOTGINT = otg_int;
  }

  if(int_status & USB_OTG_GINTSTS_SOF)
  {
    usb_otg->GINTSTS = USB_OTG_GINTSTS_SOF;

    // Disable SOF interrupt since currently only used for remote wakeup detection
    usb_otg->GINTMSK &= ~USB_OTG_GINTMSK_SOFM;

    dcd_event_bus_signal(rhport, DCD_EVENT_SOF, true);
  }

  // RxFIFO non-empty interrupt handling.
  if(int_status & USB_OTG_GINTSTS_RXFLVL)
  {
    // RXFLVL bit is read-only

    // Mask out RXFLVL while reading data from FIFO
    usb_otg->GINTMSK &= ~USB_OTG_GINTMSK_RXFLVLM;

    // Loop until all available packets were handled
    do
    {
      handle_rxflvl_ints(rhport, out_ep);
    } while(usb_otg->GINTSTS & USB_OTG_GINTSTS_RXFLVL);

    // Manage RX FIFO size
    if (OutEndpointClosed)
    {
      update_grxfsiz(rhport);

      // Disable flag
      OutEndpointClosed = false;
    }

    usb_otg->GINTMSK |= USB_OTG_GINTMSK_RXFLVLM;
  }

  // OUT endpoint interrupt handling.
  if(int_status & USB_OTG_GINTSTS_OEPINT)
  {
    // OEPINT is read-only
    handle_epout_ints(rhport, dev, out_ep);
  }

  // IN endpoint interrupt handling.
  if(int_status & USB_OTG_GINTSTS_IEPINT)
  {
    // IEPINT bit read-only
    handle_epin_ints(rhport, dev, in_ep);
  }

  //  // Check for Incomplete isochronous IN transfer
  //  if(int_status & USB_OTG_GINTSTS_IISOIXFR) {
  //    printf("      IISOIXFR!\r\n");
  ////    TU_LOG2("      IISOIXFR!\r\n");
  //  }
}
