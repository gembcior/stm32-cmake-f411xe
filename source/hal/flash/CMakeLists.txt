add_library(flash STATIC)

target_sources(flash
  PRIVATE
    src/flash_driver.cpp
)

target_include_directories(flash
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(flash
  PRIVATE
    stm32
)
