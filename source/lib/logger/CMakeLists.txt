add_library(logger STATIC)

target_include_directories(logger
  PUBLIC
    inc
)

add_subdirectory(src)

if (UNIT_TEST)
  include(Testing)
  testing_target_add_mock_library(logger)
  add_subdirectory(test)
endif()


add_library(os_logger INTERFACE)

target_include_directories(os_logger
  INTERFACE
    inc
)

target_link_libraries(os_logger
  INTERFACE
    logger
    os
)
