add_subdirectory(flasher)
add_subdirectory(ticktack)
add_subdirectory(logger)
add_subdirectory(etl)
add_subdirectory(irq)

if (UNIT_TEST)
  add_subdirectory(fmt)
endif()
