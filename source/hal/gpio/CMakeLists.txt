add_library(gpio STATIC)

target_include_directories(gpio
  PUBLIC
    inc
)

if (UNIT_TEST)
  include(Testing)
  testing_target_add_mock_library(gpio)
endif()

add_subdirectory(src)
