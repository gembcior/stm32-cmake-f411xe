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
  // Clear any pending interrupts
  otg_fs_global::fs_gintsts::write(0xFF'FF'FF'FFU);
  setInterruptMask(OtgFsInterruptMask::Otgint, true);
  setInterruptMask(OtgFsInterruptMask::Mmism, true);
}


void OtgFsCoreHal::reset()
{
  // TODO add timeout guard
  while (otg_fs_global::fs_grstctl::ahbidl::read() == 0);
  otg_fs_global::fs_grstctl::csrst::write(1);
  while (otg_fs_global::fs_grstctl::csrst::read() == 1);
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


void OtgFsCoreHal::setHnpCapability(bool hnp)
{
  // TODO
}


void OtgFsCoreHal::setSrpCapability(bool srp)
{
  // TODO
}



void OtgFsCoreHal::setFsTimeout(uint8_t fs)
{
  // TODO
}



void OtgFsCoreHal::setTurnaroundTime(uint8_t hclk)
{
  // TODO
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
  otg_fs_global::fs_gahbcfg::gint::write(0);
}


void OtgFsCoreHal::resetPhyClk()
{
  otg_fs_pwrclk::fs_pcgcctl::write(0);
}


void OtgFsCoreHal::activateTransceiver()
{
  otg_fs_global::fs_gccfg::pwrdwn::write(1);
}


void OtgFsCoreHal::deactivateTransceiver()
{
  otg_fs_global::fs_gccfg::pwrdwn::write(0);
}


void OtgFsCoreHal::setInterruptMask(OtgFsInterruptMask interrupt, bool mask)
{
  // TODO
  // TODO try to implement this without switch (big size)
  uint32_t value = mask ? 1 : 0;
  switch (interrupt) {
    case OtgFsInterruptMask::Otgint:
      otg_fs_global::fs_gintmsk::otgint::write(value);
      break;
    case OtgFsInterruptMask::Mmism:
      otg_fs_global::fs_gintmsk::mmism::write(value);
    case OtgFsInterruptMask::Usbrst:
      otg_fs_global::fs_gintmsk::usbrst::write(value);
      break;
    case OtgFsInterruptMask::Enumdnem:
      otg_fs_global::fs_gintmsk::enumdnem::write(value);
      break;
    case OtgFsInterruptMask::Usbsuspm:
      otg_fs_global::fs_gintmsk::usbsuspm::write(value);
      break;
    case OtgFsInterruptMask::Wuim:
      otg_fs_global::fs_gintmsk::wuim::write(value);
      break;
    case OtgFsInterruptMask::Rxflvlm:
      otg_fs_global::fs_gintmsk::rxflvlm::write(value);
      break;
    case OtgFsInterruptMask::Sofm:
      otg_fs_global::fs_gintmsk::sofm::write(value);
      break;
    default:
      break;
  }
}


void OtgFsCoreHal::flushTxFifo(uint32_t fifoNumber)
{
  otg_fs_global::fs_grstctl::txfnum::write(fifoNumber);
  otg_fs_global::fs_grstctl::txfflsh::write(1);
  // TODO add timeout guard
  while (otg_fs_global::fs_grstctl::txfflsh::read() != 0);
}


void OtgFsCoreHal::flushRxFifo()
{
  otg_fs_global::fs_grstctl::rxfflsh::write(1);
  // TODO add timeout guard
  while (otg_fs_global::fs_grstctl::rxfflsh::read() != 0);
}


void OtgFsCoreHal::clearInterrupt(OtgFsInterrupt interrupt)
{
  otg_fs_global::fs_gintsts::write(1 << interrupt);
}


uint32_t OtgFsCoreHal::getInterruptStatus()
{
  return otg_fs_global::fs_gintsts::read();
}


bool OtgFsCoreHal::getInterruptStatus(OtgFsInterrupt interrupt)
{
  return (otg_fs_global::fs_gintsts::read() >> interrupt) & 0x1;
}


bool OtgFsCoreHal::getInterruptStatus(uint32_t status, OtgFsInterrupt interrupt)
{
  return (status >> interrupt) & 0x1;
}

} // namespace
