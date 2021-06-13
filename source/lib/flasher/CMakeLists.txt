add_library(flasher STATIC)

target_include_directories(flasher
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_subdirectory(src)

if (UNIT_TEST)
  add_subdirectory(test)
endif()
