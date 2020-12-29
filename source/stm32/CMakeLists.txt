add_library(stm32 INTERFACE)

target_include_directories(stm32
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
