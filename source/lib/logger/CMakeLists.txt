add_library(logger STATIC)

target_include_directories(logger
  PUBLIC
    inc
)

add_subdirectory(src)

if (UNIT_TEST)
  add_subdirectory(test)
endif()
