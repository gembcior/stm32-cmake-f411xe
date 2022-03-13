include(FetchContent)

FetchContent_Declare(tinyusb
  GIT_REPOSITORY    https://github.com/hathach/tinyusb.git
  GIT_TAG           0.12.0
  GIT_SHALLOW       ON
  GIT_PROGRESS      ON
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)

FetchContent_GetProperties(tinyusb)
FetchContent_MakeAvailable(tinyusb)

add_library(tinyusb STATIC)

target_sources(tinyusb
  PRIVATE
    ${tinyusb_SOURCE_DIR}/src/tusb.c
    ${tinyusb_SOURCE_DIR}/src/class/audio/audio_device.c
    ${tinyusb_SOURCE_DIR}/src/class/bth/bth_device.c
    ${tinyusb_SOURCE_DIR}/src/class/cdc/cdc_device.c
    ${tinyusb_SOURCE_DIR}/src/class/cdc/cdc_host.c
    ${tinyusb_SOURCE_DIR}/src/class/cdc/cdc_rndis_host.c
    ${tinyusb_SOURCE_DIR}/src/class/dfu/dfu_device.c
    ${tinyusb_SOURCE_DIR}/src/class/dfu/dfu_rt_device.c
    ${tinyusb_SOURCE_DIR}/src/class/hid/hid_device.c
    ${tinyusb_SOURCE_DIR}/src/class/hid/hid_host.c
    ${tinyusb_SOURCE_DIR}/src/class/midi/midi_device.c
    ${tinyusb_SOURCE_DIR}/src/class/msc/msc_device.c
    ${tinyusb_SOURCE_DIR}/src/class/msc/msc_host.c
    ${tinyusb_SOURCE_DIR}/src/class/net/ecm_rndis_device.c
    ${tinyusb_SOURCE_DIR}/src/class/net/ncm_device.c
    ${tinyusb_SOURCE_DIR}/src/class/usbtmc/usbtmc_device.c
    ${tinyusb_SOURCE_DIR}/src/class/vendor/vendor_device.c
    ${tinyusb_SOURCE_DIR}/src/class/vendor/vendor_host.c
    ${tinyusb_SOURCE_DIR}/src/class/video/video_device.c
    ${tinyusb_SOURCE_DIR}/src/common/tusb_fifo.c
    ${tinyusb_SOURCE_DIR}/src/device/usbd.c
    ${tinyusb_SOURCE_DIR}/src/device/usbd_control.c
    ${tinyusb_SOURCE_DIR}/src/host/hub.c
    ${tinyusb_SOURCE_DIR}/src/host/usbh.c
    ${tinyusb_SOURCE_DIR}/src/host/usbh_control.c
)

target_include_directories(tinyusb
  PUBLIC
    inc
    inc/tinyusb
    ${tinyusb_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(tinyusb
  PUBLIC
    -Wno-deprecated
)

add_subdirectory(src)
