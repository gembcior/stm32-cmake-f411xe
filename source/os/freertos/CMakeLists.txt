include(FetchContent)

FetchContent_Declare(freertos
  GIT_REPOSITORY    https://github.com/FreeRTOS/FreeRTOS-Kernel.git
  GIT_TAG           V10.4.4
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)

FetchContent_GetProperties(freertos)
FetchContent_MakeAvailable(freertos)

add_library(freertos STATIC)

target_sources(freertos
  PRIVATE
    ${freertos_SOURCE_DIR}/croutine.c
    ${freertos_SOURCE_DIR}/event_groups.c
    ${freertos_SOURCE_DIR}/list.c
    ${freertos_SOURCE_DIR}/queue.c
    ${freertos_SOURCE_DIR}/stream_buffer.c
    ${freertos_SOURCE_DIR}/tasks.c
    ${freertos_SOURCE_DIR}/timers.c

  PUBLIC
    ${freertos_SOURCE_DIR}/portable/GCC/ARM_CM4F/port.c
    ${freertos_SOURCE_DIR}/portable/MemMang/heap_4.c
)

target_include_directories(freertos
  PUBLIC
    ${freertos_SOURCE_DIR}/include
    ${freertos_SOURCE_DIR}/portable/GCC/ARM_CM4F
    inc/freertos
    inc
)

add_subdirectory(src)
