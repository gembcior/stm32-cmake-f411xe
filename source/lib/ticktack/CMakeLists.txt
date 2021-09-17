add_library(ticktack STATIC)

target_include_directories(ticktack
  PUBLIC
    inc
)

add_subdirectory(src)

if (UNIT_TEST)
  include(Testing)
  stm32_target_add_mock_library(ticktack)
  add_subdirectory(test)
endif()
