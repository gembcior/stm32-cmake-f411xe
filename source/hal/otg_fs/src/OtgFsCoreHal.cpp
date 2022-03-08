#include "otg_fs/OtgFsCoreHal.h"
#include "dral/otg_fs_global.h"
#include "dral/otg_fs_pwrclk.h"

namespace stm32::hal {

using namespace dral::stm32f411;


void OtgFsCoreHal::init()
{
  selectPhy(OtgFsPhy::Internal);
  reset();
  resetPhyClk();
  otg_fs_global::fs_gintsts::write(0xFF'FF'FF'FFU);
  setInterruptMask(OtgFsInterrupt::Otgint, OtgFsInterruptMask::UnMasked);
  setInterruptMask(OtgFsInterrupt::Mmis, OtgFsInterruptMask::UnMasked);
}


void OtgFsCoreHal::reset()
{
  // TODO add timeout guard
  while (otg_fs_global::fs_grstctl::ahbidl::read() == 0U);
  otg_fs_global::fs_grstctl::csrst::write(1);
  while (otg_fs_global::fs_grstctl::csrst::read() == 1U);
}


void OtgFsCoreHal::resetPhyClk()
{
  otg_fs_pwrclk::fs_pcgcctl::write(0);
}


void OtgFsCoreHal::selectPhy(OtgFsPhy phy)
{
  switch (phy) {
    case OtgFsPhy::External:
      otg_fs_global::fs_gusbcfg::physel::write(0);
      break;
    case OtgFsPhy::Internal:
      otg_fs_global::fs_gusbcfg::physel::write(1);
      break;
  }
}


void OtgFsCoreHal::setCurrentMode(OtgFsMode mode)
{
  otg_fs_global::fs_gusbcfg::fhmod::write(0);
  otg_fs_global::fs_gusbcfg::fdmod::write(0);

  switch (mode) {
    case OtgFsMode::Device:
      otg_fs_global::fs_gusbcfg::fdmod::write(1);
      break;
    case OtgFsMode::Host:
      otg_fs_global::fs_gusbcfg::fhmod::write(1);
      break;
  }
}


void OtgFsCoreHal::setFsTimeout(uint8_t fs)
{
  // TODO
}



void OtgFsCoreHal::setTurnaroundTime(uint32_t hclk)
{
  uint32_t turnaround;

  if ( hclk >= 32000000U ) {
    turnaround = 0x6U;
  } else if ( hclk >= 27500000U ) {
    turnaround = 0x7U;
  } else if ( hclk >= 24000000U ) {
    turnaround = 0x8U;
  } else if ( hclk >= 21800000U ) {
    turnaround = 0x9U;
  } else if ( hclk >= 20000000U ) {
    turnaround = 0xAU;
  } else if ( hclk >= 18500000U ) {
    turnaround = 0xBU;
  } else if ( hclk >= 17200000U ) {
    turnaround = 0xCU;
  } else if ( hclk >= 16000000U ) {
    turnaround = 0xDU;
  } else if ( hclk >= 15000000U ) {
    turnaround = 0xEU;
  } else {
    turnaround = 0xFU;
  }

  otg_fs_global::fs_gusbcfg::trdt::write(turnaround);
}



void OtgFsCoreHal::disableVBusSensing()
{
  otg_fs_global::fs_gccfg::novbussens::write(1);
  otg_fs_global::fs_gccfg::vbusbsen::write(0);
  otg_fs_global::fs_gccfg::vbusasen::write(0);
}



void OtgFsCoreHal::enableVBusSensing()
{
  otg_fs_global::fs_gccfg::novbussens::write(0);
  otg_fs_global::fs_gccfg::vbusbsen::write(1);
}


void OtgFsCoreHal::enableGlobalInterrupts()
{
  otg_fs_global::fs_gahbcfg::gint::write(1);
}


void OtgFsCoreHal::disableGlobalInterrupts()
{
  otg_fs_global::fs_gahbcfg::gint::write(0);
}


void OtgFsCoreHal::activateTransceiver()
{
  otg_fs_global::fs_gccfg::pwrdwn::write(1);
}


void OtgFsCoreHal::deactivateTransceiver()
{
  otg_fs_global::fs_gccfg::pwrdwn::write(0);
}


void OtgFsCoreHal::setInterruptMask(OtgFsInterrupt interrupt, OtgFsInterruptMask mask)
{
  uint32_t gintmsk = otg_fs_global::fs_gintmsk::read();

  uint32_t value = ((mask == OtgFsInterruptMask::UnMasked) ? 1U : 0U) << static_cast<uint32_t>(interrupt);
  value = (gintmsk & ~value) | value;

  otg_fs_global::fs_gintmsk::write(value);
}


void OtgFsCoreHal::flushTxFifo(uint32_t fifoNumber)
{
  otg_fs_global::fs_grstctl::txfnum::write(fifoNumber);
  otg_fs_global::fs_grstctl::txfflsh::write(1);
  // TODO add timeout guard
  while (otg_fs_global::fs_grstctl::txfflsh::read() != 0U);
}


void OtgFsCoreHal::flushRxFifo()
{
  otg_fs_global::fs_grstctl::rxfflsh::write(1);
  // TODO add timeout guard
  while (otg_fs_global::fs_grstctl::rxfflsh::read() != 0U);
}


void OtgFsCoreHal::clearInterrupt(OtgFsInterrupt interrupt)
{
  otg_fs_global::fs_gintsts::write(1U << static_cast<uint32_t>(interrupt));
}


uint32_t OtgFsCoreHal::getInterruptStatus()
{
  return otg_fs_global::fs_gintsts::read();
}


bool OtgFsCoreHal::getInterruptStatus(OtgFsInterrupt interrupt)
{
  return (otg_fs_global::fs_gintsts::read() >> static_cast<uint32_t>(interrupt)) & 0x1U;
}


bool OtgFsCoreHal::getInterruptStatus(uint32_t status, OtgFsInterrupt interrupt)
{
  return (status >> static_cast<uint32_t>(interrupt)) & 0x1U;
}


void OtgFsCoreHal::readFifoPacket(uint8_t* const buffer, uint32_t byteCount)
{
  uint32_t* rxFifo = reinterpret_cast<uint32_t*>(getFifoAddress(0));

  uint32_t wordsCount = byteCount >> 2U;
  uint32_t* wordsBuffer = reinterpret_cast<uint32_t*>(buffer);

  for(uint32_t i = 0; i < wordsCount; i++) {
    *wordsBuffer++ = *rxFifo;
  }

  uint32_t bytesRemaining = byteCount & 0x3U;

  if (bytesRemaining != 0) {
    uint8_t* bytesBuffer = reinterpret_cast<uint8_t*>(wordsBuffer);
    uint32_t remainingData = *rxFifo;

    for (uint32_t i = 0; i < bytesRemaining; i++) {
      bytesBuffer[i] = (remainingData >> (8 * i)) & 0xFF;
    }
  }
}


void OtgFsCoreHal::writeFifoPacket(uint32_t fifoNumber, const uint8_t* buffer, uint32_t byteCount)
{
  uint32_t* txFifo = reinterpret_cast<uint32_t*>(getFifoAddress(fifoNumber));

  uint32_t wordsCount = byteCount >> 2U;
  const uint32_t* wordsBuffer = reinterpret_cast<const uint32_t*>(buffer);

  for(uint32_t i = 0; i < wordsCount; i++) {
    *txFifo = *wordsBuffer++;
  }

  uint32_t bytesRemaining = byteCount & 0x3U;

  if (bytesRemaining != 0) {
    const uint8_t* bytesBuffer = reinterpret_cast<const uint8_t*>(wordsBuffer);
    uint32_t remainingData = 0;

    for (uint32_t i = 0; i < bytesRemaining; i++) {
      remainingData |= bytesBuffer[i] << (8 * i); 
    }

    *txFifo = remainingData;
  }
}

} // namespace
