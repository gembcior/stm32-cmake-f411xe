#include "otg_fs/OtgFsDeviceHal.h"
#include "dral/otg_fs_device.h"
#include "dral/otg_fs_pwrclk.h"
#include "dral/otg_fs_global.h"

// TODO fix endpoints index number

namespace stm32::hal {

using namespace dral::stm32f411;

void OtgFsDeviceHal::init()
{
  OtgFsCoreHal::init();
  otg_fs_device::fs_dcfg::nzlsohsk::write(1);
  setSpeed(OtgFsSpeed::FullSpeed);
  setCurrentMode(OtgFsMode::Device);
  disableVBusSensing();
  activateTransceiver();
  setInterruptMask(OtgFsInterruptMask::Usbrst, true);
  setInterruptMask(OtgFsInterruptMask::Enumdnem, true);
  setInterruptMask(OtgFsInterruptMask::Usbsuspm, true);
  setInterruptMask(OtgFsInterruptMask::Wuim, true);
  setInterruptMask(OtgFsInterruptMask::Rxflvlm, true);
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


void OtgFsDeviceHal::setInEndPointInterruptMask(OtgFsDeviceInEndpointInterruptMask interrupt, bool mask)
{
  // TODO
  switch (interrupt) {
    case OtgFsDeviceInEndpointInterruptMask::Xfrcm:
        otg_fs_device::fs_diepmsk::xfrcm::write(mask);
        break;
    default:
      break;
  }
}


void OtgFsDeviceHal::setOutEndPointInterruptMask(OtgFsDeviceOutEndpointInterruptMask interrupt, bool mask)
{
  // TODO
  switch (interrupt) {
    default:
      break;
  }
}


void OtgFsDeviceHal::setAllInEndPointInterruptMask(uint32_t interrupt, bool mask)
{
  interrupt = static_cast<uint32_t>(mask) << interrupt;
  auto value = (otg_fs_device::fs_daintmsk::iepm::read() & ~interrupt) | interrupt;
  otg_fs_device::fs_daintmsk::iepm::write(value);
}


void OtgFsDeviceHal::setAllOutEndPointInterruptMask(uint32_t interrupt, bool mask)
{
  interrupt = static_cast<uint32_t>(mask) << interrupt;
  auto value = (otg_fs_device::fs_daintmsk::oepm::read() & ~interrupt) | interrupt;
  otg_fs_device::fs_daintmsk::oepm::write(value);
}


void OtgFsDeviceHal::activateEndpoint(OtgFsEndpoint& ep)
{
  if (ep.direction == OtgFsEndpointDirection::In) {
    uint32_t iepm = otg_fs_device::fs_daintmsk::iepm::read();
    otg_fs_device::fs_daintmsk::iepm::write(iepm | 1 << ep.number);

    if (otg_fs_device::diepctlx::usbaep::read(ep.number) == 0) {
      otg_fs_device::diepctlx::mpsiz::write(ep.number, ep.maxPacketSize);
      otg_fs_device::diepctlx::eptyp::write(ep.number, static_cast<uint32_t>(ep.type));
      otg_fs_device::diepctlx::txfnum::write(ep.number, ep.number);
      otg_fs_device::diepctlx::sd0pid_sevnfrm::write(ep.number, ep.type != OtgFsEndpointType::Isochronous ? 1 : 0);
      otg_fs_device::diepctlx::usbaep::write(ep.number, 1);
    }
  } else if (ep.direction == OtgFsEndpointDirection::Out) {
    uint32_t oepm = otg_fs_device::fs_daintmsk::oepm::read();
    otg_fs_device::fs_daintmsk::oepm::write(oepm | 1 << ep.number);

    if (otg_fs_device::doepctlx::usbaep::read(ep.number) == 0) {
      otg_fs_device::doepctlx::mpsiz::write(ep.number, ep.maxPacketSize);
      otg_fs_device::doepctlx::eptyp::write(ep.number, static_cast<uint32_t>(ep.type));
      otg_fs_device::doepctlx::sd0pid_sevnfrm::write(ep.number, ep.type != OtgFsEndpointType::Isochronous ? 1 : 0);
      otg_fs_device::doepctlx::usbaep::write(ep.number, 1);
    }
  }
}


void OtgFsDeviceHal::deactivateEndpoint(OtgFsEndpoint& ep)
{
  if (ep.direction == OtgFsEndpointDirection::In) {
    if (otg_fs_device::diepctlx::usbaep::read(ep.number) == 1) {
      otg_fs_device::diepctlx::snak::write(ep.number, 1);
      otg_fs_device::diepctlx::epdis::write(ep.number, 1);
    }

    uint32_t iepm = otg_fs_device::fs_daintmsk::iepm::read();
    otg_fs_device::fs_daintmsk::iepm::write(iepm & ~(1 << ep.number));

    otg_fs_device::diepctlx::mpsiz::write(ep.number, 0);
    otg_fs_device::diepctlx::eptyp::write(ep.number, 0);
    otg_fs_device::diepctlx::txfnum::write(ep.number, 0);
    otg_fs_device::diepctlx::sd0pid_sevnfrm::write(ep.number, 0);
    otg_fs_device::diepctlx::usbaep::write(ep.number, 0);
  } else if (ep.direction == OtgFsEndpointDirection::Out) {
    if (otg_fs_device::doepctlx::usbaep::read(ep.number) == 1) {
      otg_fs_device::doepctlx::snak::write(ep.number, 1);
      otg_fs_device::doepctlx::epdis::write(ep.number, 1);
    }

    uint32_t oepm = otg_fs_device::fs_daintmsk::oepm::read();
    otg_fs_device::fs_daintmsk::oepm::write(oepm & ~(1 << ep.number));

    otg_fs_device::doepctlx::mpsiz::write(ep.number, 0);
    otg_fs_device::doepctlx::eptyp::write(ep.number, 0);
    otg_fs_device::doepctlx::sd0pid_sevnfrm::write(ep.number, 0);
    otg_fs_device::doepctlx::usbaep::write(ep.number, 0);
  }
}


// TODO handle endpoint 0
void OtgFsDeviceHal::startXfer(OtgFsEndpoint& ep)
{
  if (ep.direction == OtgFsEndpointDirection::In) {
    if (ep.xferLen == 0) {
      otg_fs_device::dieptsizx::xfrsiz::write(ep.number, 0);
      otg_fs_device::dieptsizx::pktcnt::write(ep.number, 1);
    } else {
      uint32_t packetCount = (ep.xferLen + ep.maxPacketSize - 1) / ep.maxPacketSize;
      otg_fs_device::dieptsizx::pktcnt::write(ep.number, packetCount);
      otg_fs_device::dieptsizx::xfrsiz::write(ep.number, ep.xferLen);

      otg_fs_device::diepctlx::epena::write(ep.number, 1);
      otg_fs_device::diepctlx::cnak::write(ep.number, 1);

      if (otg_fs_device::diepctlx::eptyp::read(ep.number) == static_cast<uint32_t>(OtgFsEndpointType::Isochronous)) {
        if ((otg_fs_device::fs_dsts::read() & 1) == 0) {
          otg_fs_device::diepctlx::soddfrm::write(ep.number, 1);
        } else {
          otg_fs_device::diepctlx::sd0pid_sevnfrm::write(ep.number, 1);
        }
      }

      if (ep.xferLen > 0) {
        otg_fs_device::diepempmsk::write(1 << ep.number);
      }
    }
  } else if (ep.direction == OtgFsEndpointDirection::Out) {
    if (ep.xferLen == 0) {
      otg_fs_device::doeptsizx::xfrsiz::write(ep.number, ep.maxPacketSize);
      otg_fs_device::doeptsizx::pktcnt::write(ep.number, 1);
    } else {
      uint32_t packetCount = (ep.xferLen + ep.maxPacketSize - 1) / ep.maxPacketSize;
      otg_fs_device::doeptsizx::pktcnt::write(ep.number, packetCount);
      otg_fs_device::doeptsizx::xfrsiz::write(ep.number, ep.maxPacketSize * packetCount);

      if (otg_fs_device::doepctlx::eptyp::read(ep.number) == static_cast<uint32_t>(OtgFsEndpointType::Isochronous)) {
        if ((otg_fs_device::fs_dsts::read() & 1) == 0) {
          otg_fs_device::doepctlx::soddfrm::write(ep.number, 1);
        } else {
          otg_fs_device::doepctlx::sd0pid_sevnfrm::write(ep.number, 1);
        }
      }

      otg_fs_device::doepctlx::epena::write(ep.number, 1);
      otg_fs_device::doepctlx::cnak::write(ep.number, 1);
    }
  }
}


// TODO handle endpoint 0
void OtgFsDeviceHal::setStall(OtgFsEndpoint& ep)
{
  if (ep.direction == OtgFsEndpointDirection::In) {
    if ((otg_fs_device::diepctlx::epena::read(ep.number) == 0) && (ep.number != 0)) {
      otg_fs_device::diepctlx::epdis::write(ep.number, 0);
    }
    otg_fs_device::diepctlx::stall::write(ep.number, 1);
  } else if (ep.direction == OtgFsEndpointDirection::Out) {
    if ((otg_fs_device::doepctlx::epena::read(ep.number) == 0) && (ep.number != 0)) {
      otg_fs_device::doepctlx::epdis::write(ep.number, 0);
    }
    otg_fs_device::doepctlx::stall::write(ep.number, 1);
  }
}


void OtgFsDeviceHal::clearStall(OtgFsEndpoint& ep)
{
  if (ep.direction == OtgFsEndpointDirection::In) {
    otg_fs_device::diepctlx::stall::write(ep.number, 0);
    if (ep.type == OtgFsEndpointType::Interrupt || ep.type == OtgFsEndpointType::Bulk) {
      otg_fs_device::diepctlx::sd0pid_sevnfrm::write(ep.number, 1);
    }
  } else if (ep.direction == OtgFsEndpointDirection::Out) {
    otg_fs_device::doepctlx::stall::write(ep.number, 0);
    if (ep.type == OtgFsEndpointType::Interrupt || ep.type == OtgFsEndpointType::Bulk) {
      otg_fs_device::doepctlx::sd0pid_sevnfrm::write(ep.number, 1);
    }
  }
}

} // namespace
