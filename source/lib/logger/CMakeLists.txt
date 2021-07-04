add_library(logger STATIC)

target_include_directories(logger
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)

if (UNIT_TEST)
  add_subdirectory(test)
endif()
