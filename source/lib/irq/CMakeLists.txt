add_library(irq INTERFACE)

target_include_directories(irq
  INTERFACE
    inc
)

target_link_libraries(irq
  INTERFACE
    nvic
)

if (UNIT_TEST)
  add_subdirectory(test)
endif()
