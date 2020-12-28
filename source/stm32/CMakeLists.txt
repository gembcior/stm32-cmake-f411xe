add_library(stm32 INTERFACE)

target_include_directories(stm32
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_link_libraries(stm32
  INTERFACE
    reg_model
)
