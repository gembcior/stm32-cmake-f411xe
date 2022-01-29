include(Testing)

testing_target_add_test(logger
  LoggerOutputBuffer.cpp
  PrinterTest.cpp
  LoggerTest.cpp
)

testing_target_test_link_libraries(logger
  fmt
)

testing_target_test_link_mock_libraries(logger
  logger
)
