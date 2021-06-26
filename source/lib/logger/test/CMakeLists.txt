include(Testing)

stm32_target_add_test(logger
  LoggerTest.cpp
)

#stm32_target_test_link_mock_libraries(logger
#  uart
#)
