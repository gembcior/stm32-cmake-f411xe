add_library(ticktack STATIC)

target_include_directories(ticktack
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

if (UNIT_TEST)
  include(Testing)
  stm32_target_add_mock_library(ticktack)
  add_subdirectory(test)
endif()

add_subdirectory(src)
