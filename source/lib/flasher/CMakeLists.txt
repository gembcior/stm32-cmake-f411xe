add_library(flasher STATIC)

target_include_directories(flasher
  PUBLIC
    inc
)

add_subdirectory(src)

if (UNIT_TEST)
  add_subdirectory(test)
endif()
