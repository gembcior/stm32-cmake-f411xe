include(Testing)

stm32_target_add_test(logger
  main.cpp
  LoggerOutputBuffer.cpp
  PrinterTest.cpp
  LoggerTest.cpp
)

stm32_target_test_link_libraries(logger
  fmt
)

stm32_target_test_link_mock_libraries(logger
  logger
)
