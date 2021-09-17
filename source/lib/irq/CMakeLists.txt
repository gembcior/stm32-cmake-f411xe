add_library(irq INTERFACE)

target_include_directories(irq
  INTERFACE
    inc
)

if (UNIT_TEST)
  add_subdirectory(test)
endif()
