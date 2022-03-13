#include "otg_fs/OtgFsDeviceHal.h"
#include "dral/otg_fs_device.h"
#include "dral/otg_fs_pwrclk.h"
#include "dral/otg_fs_global.h"
#include "system/constants.h"


namespace stm32::hal {

using namespace dral::stm32f411;
using namespace stm32::system;

void OtgFsDeviceHal::init()
{
  OtgFsCoreHal::init();

  setCurrentMode(OtgFsMode::Device);
  setSpeed(OtgFsSpeed::FullSpeed);
  setNonZeroLenStatusOutHandshake(OtgFSNonZeroLenStatusOutHandshake::StallHandshake);

  setInterruptMask(OtgFsInterrupt::Usbrst, OtgFsInterruptMask::UnMasked);
  setInterruptMask(OtgFsInterrupt::Enumdne, OtgFsInterruptMask::UnMasked);
//  setInterruptMask(OtgFsInterrupt::Esusp, OtgFsInterruptMask::UnMasked);
  setInterruptMask(OtgFsInterrupt::Usbsusp, OtgFsInterruptMask::UnMasked);
  setInterruptMask(OtgFsInterrupt::Wkupint, OtgFsInterruptMask::UnMasked);
  setInterruptMask(OtgFsInterrupt::Rxflvl, OtgFsInterruptMask::UnMasked);
//  setInterruptMask(OtgFsInterrupt::Sof, OtgFsInterruptMask::UnMasked);

  setTurnaroundTime(SystemClock);
  disableVBusSensing();
  activateTransceiver();

  enableGlobalInterrupts();
}


void OtgFsDeviceHal::connect()
{
  otg_fs_pwrclk::fs_pcgcctl::gatehclk::write(0);
  otg_fs_pwrclk::fs_pcgcctl::stppclk::write(0);
  otg_fs_device::fs_dctl::sdis::write(0);
}


void OtgFsDeviceHal::disconnect()
{
  otg_fs_pwrclk::fs_pcgcctl::gatehclk::write(0);
  otg_fs_pwrclk::fs_pcgcctl::stppclk::write(0);
  otg_fs_device::fs_dctl::sdis::write(1);
}


void OtgFsDeviceHal::wakeup()
{
  otg_fs_device::fs_dctl::rwusig::write(1);
  // TODO add 1ms to 15ms according to spec
  otg_fs_device::fs_dctl::rwusig::write(0);
}


void OtgFsDeviceHal::setAddress(uint8_t address)
{
  otg_fs_device::fs_dcfg::dad::write(address);
}


void OtgFsDeviceHal::setPeriodicFrameInterval(OtgFsPeriodicFrameInterval interval)
{
  otg_fs_device::fs_dcfg::pfivl::write(static_cast<uint32_t>(interval));
}



void OtgFsDeviceHal::setSpeed(OtgFsSpeed speed)
{
  otg_fs_device::fs_dcfg::dspd::write(static_cast<uint32_t>(speed));
}


OtgFsSpeed OtgFsDeviceHal::getSpeed()
{
  uint32_t speed = otg_fs_device::fs_dsts::enumspd::read();
  return static_cast<OtgFsSpeed>(speed);
}


void OtgFsDeviceHal::setInEndpointInterruptMask(OtgFsDeviceInEndpointInterrupt interrupt, OtgFsInterruptMask mask)
{
  uint32_t diepmsk = otg_fs_device::fs_diepmsk::read();

  uint32_t value = ((mask == OtgFsInterruptMask::UnMasked) ? 1U : 0U) << static_cast<uint32_t>(interrupt);
  value = (diepmsk & ~value) | value;

  otg_fs_device::fs_diepmsk::write(value);
}


void OtgFsDeviceHal::setOutEndpointInterruptMask(OtgFsDeviceOutEndpointInterrupt interrupt, OtgFsInterruptMask mask)
{
  uint32_t doepmsk = otg_fs_device::fs_doepmsk::read();

  uint32_t value = ((mask == OtgFsInterruptMask::UnMasked) ? 1U : 0U) << static_cast<uint32_t>(interrupt);
  value = (doepmsk & ~value) | value;

  otg_fs_device::fs_doepmsk::write(value);
}


void OtgFsDeviceHal::setAllInEndpointInterruptMask(uint32_t interrupt, OtgFsInterruptMask mask)
{
  interrupt = ((mask == OtgFsInterruptMask::UnMasked) ? 1U : 0U) << interrupt;
  uint32_t value = (otg_fs_device::fs_daintmsk::iepm::read() & ~interrupt) | interrupt;
  otg_fs_device::fs_daintmsk::iepm::write(value);
}


void OtgFsDeviceHal::setAllInEndpointInterruptMask(OtgFsInterruptMask mask)
{
  uint32_t value = (mask == OtgFsInterruptMask::UnMasked) ? 0xFFFFU : 0U;
  otg_fs_device::fs_daintmsk::iepm::write(value);
}


void OtgFsDeviceHal::setAllOutEndpointInterruptMask(uint32_t interrupt, OtgFsInterruptMask mask)
{
  interrupt = ((mask == OtgFsInterruptMask::UnMasked) ? 1U : 0U) << interrupt;
  uint32_t value = (otg_fs_device::fs_daintmsk::oepm::read() & ~interrupt) | interrupt;
  otg_fs_device::fs_daintmsk::oepm::write(value);
}


void OtgFsDeviceHal::setAllOutEndpointInterruptMask(OtgFsInterruptMask mask)
{
  uint32_t value = (mask == OtgFsInterruptMask::UnMasked) ? 0xFFFFU : 0U;
  otg_fs_device::fs_daintmsk::oepm::write(value);
}


void OtgFsDeviceHal::setNonZeroLenStatusOutHandshake(OtgFSNonZeroLenStatusOutHandshake handshake)
{
  otg_fs_device::fs_dcfg::nzlsohsk::write(static_cast<uint32_t>(handshake));
}


void OtgFsDeviceHal::activateEndpoint(OtgFsEndpoint& ep)
{
  if (ep.number == 0) {
    activateEndpoint0(ep);
  } else {
    activateEndpointX(ep);
  }
}


void OtgFsDeviceHal::activateEndpoint0(OtgFsEndpoint& ep)
{
  if (ep.direction == OtgFsEndpointDirection::In) {
    if (otg_fs_device::fs_diepctl0::usbaep::read() == 0U) {
      otg_fs_device::fs_diepctl0::mpsiz::write(ep.maxPacketSize);
      otg_fs_device::fs_diepctl0::eptyp::write( static_cast<uint32_t>(ep.type));
      otg_fs_device::fs_diepctl0::txfnum::write(ep.number);
      otg_fs_device::fs_diepctl0::usbaep::write(1);
    }
    setAllInEndpointInterruptMask(ep.number, OtgFsInterruptMask::UnMasked);
  } else if (ep.direction == OtgFsEndpointDirection::Out) {
    if (otg_fs_device::doepctl0::usbaep::read() == 0U) {
      otg_fs_device::doepctl0::mpsiz::write(ep.maxPacketSize);
      otg_fs_device::doepctl0::eptyp::write(static_cast<uint32_t>(ep.type));
      otg_fs_device::doepctl0::usbaep::write(1);
    }
    setAllOutEndpointInterruptMask(ep.number, OtgFsInterruptMask::UnMasked);
  }
}


void OtgFsDeviceHal::activateEndpointX(OtgFsEndpoint& ep)
{
  const uint32_t endpointRegNumber = ep.number - 1;

  if (ep.direction == OtgFsEndpointDirection::In) {
    if (otg_fs_device::diepctlx::usbaep::read(endpointRegNumber) == 0U) {
      otg_fs_device::diepctlx::mpsiz::write(endpointRegNumber, ep.maxPacketSize);
      otg_fs_device::diepctlx::eptyp::write(endpointRegNumber, static_cast<uint32_t>(ep.type));
      otg_fs_device::diepctlx::txfnum::write(endpointRegNumber, endpointRegNumber);
      otg_fs_device::diepctlx::sd0pid_sevnfrm::write(endpointRegNumber, ep.type != OtgFsEndpointType::Isochronous ? 1U : 0U);
      otg_fs_device::diepctlx::usbaep::write(endpointRegNumber, 1);
    }
    setAllInEndpointInterruptMask(ep.number, OtgFsInterruptMask::UnMasked);
  } else if (ep.direction == OtgFsEndpointDirection::Out) {
    if (otg_fs_device::doepctlx::usbaep::read(endpointRegNumber) == 0U) {
      otg_fs_device::doepctlx::mpsiz::write(endpointRegNumber, ep.maxPacketSize);
      otg_fs_device::doepctlx::eptyp::write(endpointRegNumber, static_cast<uint32_t>(ep.type));
      otg_fs_device::doepctlx::sd0pid_sevnfrm::write(endpointRegNumber, ep.type != OtgFsEndpointType::Isochronous ? 1U : 0U);
      otg_fs_device::doepctlx::usbaep::write(endpointRegNumber, 1);
    }
    setAllOutEndpointInterruptMask(ep.number, OtgFsInterruptMask::UnMasked);
  }
}


void OtgFsDeviceHal::deactivateEndpoint(OtgFsEndpoint& ep)
{
  if (ep.number == 0) {
    deactivateEndpoint0(ep);
  } else {
    deactivateEndpointX(ep);
  }
}


void OtgFsDeviceHal::deactivateEndpoint0(OtgFsEndpoint& ep)
{
  if (ep.direction == OtgFsEndpointDirection::In) {
    if (otg_fs_device::fs_diepctl0::usbaep::read() == 1U) {
      otg_fs_device::fs_diepctl0::snak::write(1);
      otg_fs_device::fs_diepctl0::epdis::write(1);
    }

    setAllInEndpointInterruptMask(ep.number, OtgFsInterruptMask::Masked);

    otg_fs_device::fs_diepctl0::mpsiz::write(0);
    otg_fs_device::fs_diepctl0::eptyp::write(0);
    otg_fs_device::fs_diepctl0::txfnum::write(0);
    otg_fs_device::fs_diepctl0::usbaep::write(0);
  } else if (ep.direction == OtgFsEndpointDirection::Out) {
    if (otg_fs_device::fs_diepctl0::usbaep::read() == 1U) {
      otg_fs_device::fs_diepctl0::snak::write(1);
      otg_fs_device::fs_diepctl0::epdis::write(1);
    }

    setAllOutEndpointInterruptMask(ep.number, OtgFsInterruptMask::Masked);

    otg_fs_device::fs_diepctl0::mpsiz::write(0);
    otg_fs_device::fs_diepctl0::eptyp::write(0);
    otg_fs_device::fs_diepctl0::usbaep::write(0);
  }
}


void OtgFsDeviceHal::deactivateEndpointX(OtgFsEndpoint& ep)
{
  const uint32_t endpointRegNumber = ep.number - 1;

  if (ep.direction == OtgFsEndpointDirection::In) {
    if (otg_fs_device::diepctlx::usbaep::read(endpointRegNumber) == 1U) {
      otg_fs_device::diepctlx::snak::write(endpointRegNumber, 1);
      otg_fs_device::diepctlx::epdis::write(endpointRegNumber, 1);
    }

    setAllInEndpointInterruptMask(ep.number, OtgFsInterruptMask::Masked);

    otg_fs_device::diepctlx::mpsiz::write(endpointRegNumber, 0);
    otg_fs_device::diepctlx::eptyp::write(endpointRegNumber, 0);
    otg_fs_device::diepctlx::txfnum::write(endpointRegNumber, 0);
    otg_fs_device::diepctlx::sd0pid_sevnfrm::write(endpointRegNumber, 0);
    otg_fs_device::diepctlx::usbaep::write(endpointRegNumber, 0);
  } else if (ep.direction == OtgFsEndpointDirection::Out) {
    if (otg_fs_device::doepctlx::usbaep::read(endpointRegNumber) == 1U) {
      otg_fs_device::doepctlx::snak::write(endpointRegNumber, 1);
      otg_fs_device::doepctlx::epdis::write(endpointRegNumber, 1);
    }

    setAllOutEndpointInterruptMask(ep.number, OtgFsInterruptMask::Masked);

    otg_fs_device::doepctlx::mpsiz::write(endpointRegNumber, 0);
    otg_fs_device::doepctlx::eptyp::write(endpointRegNumber, 0);
    otg_fs_device::doepctlx::sd0pid_sevnfrm::write(endpointRegNumber, 0);
    otg_fs_device::doepctlx::usbaep::write(endpointRegNumber, 0);
  }

  ep.maxPacketSize = 0;
}


void OtgFsDeviceHal::startXfer(OtgFsEndpoint& ep)
{
  if (ep.number == 0) {
    startEndpoint0Xfer(ep);
  } else {
    startEndpointXXfer(ep);
  }
}


void OtgFsDeviceHal::startEndpoint0Xfer(OtgFsEndpoint& ep)
{
  uint32_t xferLen;
  if (ep.xferLen > ep.maxPacketSize) {
    xferLen = ep.maxPacketSize;
  } else {
    xferLen = ep.xferLen;
  }

  if (ep.direction == OtgFsEndpointDirection::In) {
    otg_fs_device::dieptsiz0::pktcnt::write(1);
    otg_fs_device::dieptsiz0::xfrsiz::write(xferLen);

    otg_fs_device::fs_diepctl0::cnak::write(1);
    otg_fs_device::fs_diepctl0::epena::write(1);

    if (xferLen > 0U) {
      uint32_t ineptxfem = otg_fs_device::diepempmsk::ineptxfem::read();
      otg_fs_device::diepempmsk::ineptxfem::write(ineptxfem | (1 << ep.number));
    }
  } else {
    otg_fs_device::doeptsiz0::pktcnt::write(1);
    otg_fs_device::doeptsiz0::xfrsiz::write(xferLen);

    otg_fs_device::doepctl0::cnak::write(1);
    otg_fs_device::doepctl0::epena::write(1);
  }
}


void OtgFsDeviceHal::startEndpointXXfer(OtgFsEndpoint& ep)
{
  const uint32_t endpointRegNumber = ep.number - 1;
  uint32_t packetCount;

  if (ep.xferLen == 0) {
    packetCount = 1;
  } else {
    packetCount = (ep.xferLen + ep.maxPacketSize - 1U) / ep.maxPacketSize;
  }

  if (ep.direction == OtgFsEndpointDirection::In) {
    otg_fs_device::dieptsizx::pktcnt::write(endpointRegNumber, packetCount);
    otg_fs_device::dieptsizx::xfrsiz::write(endpointRegNumber, ep.xferLen);

    auto enpointType = static_cast<OtgFsEndpointType>(otg_fs_device::diepctlx::eptyp::read(endpointRegNumber));
    if ((enpointType == OtgFsEndpointType::Isochronous) && (ep.interval == 1)) {
      if ((otg_fs_device::fs_dsts::fnsof::read() & 1U) == 0U) {
        otg_fs_device::diepctlx::soddfrm::write(endpointRegNumber, 1);
      } else {
        otg_fs_device::diepctlx::sd0pid_sevnfrm::write(endpointRegNumber, 1);
      }
    }

    otg_fs_device::diepctlx::cnak::write(endpointRegNumber, 1);
    otg_fs_device::diepctlx::epena::write(endpointRegNumber, 1);

    if (ep.xferLen > 0) {
      uint32_t ineptxfem = otg_fs_device::diepempmsk::ineptxfem::read();
      otg_fs_device::diepempmsk::ineptxfem::write(ineptxfem | (1 << ep.number));
    }
  } else {
    otg_fs_device::doeptsizx::pktcnt::write(endpointRegNumber, packetCount);
//    otg_fs_device::doeptsizx::xfrsiz::write(endpointRegNumber, ep.maxPacketSize * packetCount);
    otg_fs_device::doeptsizx::xfrsiz::write(endpointRegNumber, ep.xferLen);

    auto enpointType = static_cast<OtgFsEndpointType>(otg_fs_device::doepctlx::eptyp::read(endpointRegNumber));
    if ((enpointType == OtgFsEndpointType::Isochronous) && (ep.interval == 1)) {
      if ((otg_fs_device::fs_dsts::fnsof::read() & 1U) == 0U) {
        otg_fs_device::doepctlx::soddfrm::write(endpointRegNumber, 1);
      } else {
        otg_fs_device::doepctlx::sd0pid_sevnfrm::write(endpointRegNumber, 1);
      }
    }
    otg_fs_device::doepctlx::cnak::write(endpointRegNumber, 1);
    otg_fs_device::doepctlx::epena::write(endpointRegNumber, 1);
  }
}


void OtgFsDeviceHal::setStall(OtgFsEndpoint& ep)
{
  const uint32_t endpointRegNumber = ep.number - 1;

  if (ep.direction == OtgFsEndpointDirection::In) {
    if (ep.number == 0) {
      otg_fs_device::fs_diepctl0::stall::write(1);
      otg_fs_device::fs_diepctl0::snak::write(1);
    } else {
      if (otg_fs_device::diepctlx::epena::read(endpointRegNumber) == 0U) {
        otg_fs_device::diepctlx::epdis::write(endpointRegNumber, 0);
      }
      otg_fs_device::diepctlx::stall::write(endpointRegNumber, 1);
      otg_fs_device::diepctlx::snak::write(endpointRegNumber, 1);
    }
  } else if (ep.direction == OtgFsEndpointDirection::Out) {
    if (ep.number == 0) {
      otg_fs_device::doepctl0::stall::write(1);
      otg_fs_device::doepctl0::snak::write(1);
    } else {
      if (otg_fs_device::doepctlx::epena::read(endpointRegNumber) == 0U) {
        otg_fs_device::doepctlx::epdis::write(endpointRegNumber, 0);
      }
      otg_fs_device::doepctlx::stall::write(endpointRegNumber, 1);
      otg_fs_device::doepctlx::snak::write(endpointRegNumber, 1);
    }
  }
}


void OtgFsDeviceHal::clearStall(OtgFsEndpoint& ep)
{
  const uint32_t endpointRegNumber = ep.number - 1;

  if (ep.direction == OtgFsEndpointDirection::In) {
    if (ep.number == 0) {
      otg_fs_device::fs_diepctl0::stall::write(0);
    } else {
      otg_fs_device::diepctlx::stall::write(endpointRegNumber, 0);
      if (ep.type == OtgFsEndpointType::Interrupt || ep.type == OtgFsEndpointType::Bulk) {
        otg_fs_device::diepctlx::sd0pid_sevnfrm::write(endpointRegNumber, 1);
      }
    }
  } else if (ep.direction == OtgFsEndpointDirection::Out) {
    if (ep.number == 0) {
      otg_fs_device::doepctl0::stall::write(0);
    } else {
      otg_fs_device::doepctlx::stall::write(endpointRegNumber, 0);
      if (ep.type == OtgFsEndpointType::Interrupt || ep.type == OtgFsEndpointType::Bulk) {
        otg_fs_device::doepctlx::sd0pid_sevnfrm::write(endpointRegNumber, 1);
      }
    }
  }
}


void OtgFsDeviceHal::busReset()
{
  otg_fs_device::doepctl0::snak::write(1);
  for (uint32_t i = 0; i < (MaxEndpoints - 1); i++) {
    otg_fs_device::doepctlx::snak::write(i, 1);
  }

  setAllInEndpointInterruptMask(0, OtgFsInterruptMask::UnMasked);
  setAllOutEndpointInterruptMask(0, OtgFsInterruptMask::UnMasked);

  setOutEndpointInterruptMask(OtgFsDeviceOutEndpointInterrupt::Stup, OtgFsInterruptMask::UnMasked);
  setOutEndpointInterruptMask(OtgFsDeviceOutEndpointInterrupt::Xfrc, OtgFsInterruptMask::UnMasked);

  setInEndpointInterruptMask(OtgFsDeviceInEndpointInterrupt::Xfrc, OtgFsInterruptMask::UnMasked);
  setInEndpointInterruptMask(OtgFsDeviceInEndpointInterrupt::To, OtgFsInterruptMask::UnMasked);

  constexpr uint32_t rxFifoSize = getRxFifoSize(EndpointSize);
  otg_fs_global::fs_grxfsiz::rxfd::write(rxFifoSize);

  otg_fs_global::fs_gnptxfsiz_device::tx0fd::write(16);
  const uint32_t txFifoStartAddress = (EndpointFifoSize / 4U) - 16U;
  otg_fs_global::fs_gnptxfsiz_device::tx0fsa::write(txFifoStartAddress);

  otg_fs_device::doeptsiz0::stupcnt::write(3);
}


bool OtgFsDeviceHal::getInEndpointInterruptStatus(OtgFsEndpoint& ep, OtgFsDeviceInEndpointInterrupt interrupt)
{
  return (otg_fs_device::diepintx::read(ep.number) >> static_cast<uint32_t>(interrupt)) & 0x1U;
}


void OtgFsDeviceHal::clearInEndpointInterruptStatus(OtgFsEndpoint& ep, OtgFsDeviceInEndpointInterrupt interrupt)
{
  otg_fs_device::diepintx::write(ep.number, 1U << static_cast<uint32_t>(interrupt));
}


bool OtgFsDeviceHal::getOutEndpointInterruptStatus(OtgFsEndpoint& ep, OtgFsDeviceOutEndpointInterrupt interrupt)
{
  return (otg_fs_device::doepintx::read(ep.number) >> static_cast<uint32_t>(interrupt)) & 0x1U;
}


void OtgFsDeviceHal::clearOutEndpointInterruptStatus(OtgFsEndpoint& ep, OtgFsDeviceOutEndpointInterrupt interrupt)
{
  otg_fs_device::diepintx::write(ep.number, 1U << static_cast<uint32_t>(interrupt));
}

} // namespace
