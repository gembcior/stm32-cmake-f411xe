#include "gtest/gtest.h"
#include "logger/Logger.h"
#include "logger/MockLoggerCallback.h"
#include "LoggerOutputBuffer.h"
#include <string>


using namespace ::testing;
using namespace stm32::lib;
using namespace std;


class LoggerTest : public testing::TestWithParam<Logger::CallbackId>
{
public:
  LoggerTest()
  {
    m_logger.registerOutput(LoggerOutputBuffer::outputFunction);
  }

  void checkMessage(const string expectedMessage)
  {
    ASSERT_STREQ(expectedMessage.c_str(), LoggerOutputBuffer::getPointer());
  }

protected:
  Logger m_logger;
};


TEST_F(LoggerTest, info) {
  const string testMessage = "This is a test info message";
  const string expectedMessage = testMessage + "\n\r";

  m_logger.info(testMessage.c_str());
  checkMessage(expectedMessage);
}


TEST_F(LoggerTest, warning) {
  const string testMessage = "This is a test warning message";
  string expectedMessage = "\x1B[33mW: " + testMessage + "\n\r\x1B[39m";


  m_logger.warning(testMessage.c_str());
  checkMessage(expectedMessage);
}


TEST_F(LoggerTest, error) {
  const string testMessage = "This is a test error message";
  string expectedMessage = "\x1B[31mE: "+ testMessage + "\n\r\x1B[39m";

  m_logger.error(testMessage.c_str());
  checkMessage(expectedMessage);
}


TEST_F(LoggerTest, fatal) {
  const string testMessage = "This is a test fatal message";
  string expectedMessage = "\x1B[30m\x1B[41mF: " + testMessage + "\n\r\x1B[49m\x1B[39m";

  m_logger.fatal(testMessage.c_str());
  checkMessage(expectedMessage);
}


string callbackIdToString(const TestParamInfo<LoggerTest::ParamType>& id)
{
  string name;

  switch (id.param) {
    case Logger::CallbackId::InfoExit:
      name = "Info";
      break;
    case Logger::CallbackId::WarningExit:
      name = "Warning";
      break;
    case Logger::CallbackId::ErrorExit:
      name = "Error";
      break;
    case Logger::CallbackId::FatalExit:
      name = "Fatal";
      break;
    default:
      break;
  };

  return name;
}


INSTANTIATE_TEST_SUITE_P(LoggerCallback, LoggerTest,
    Values(Logger::CallbackId::InfoExit,
           Logger::CallbackId::WarningExit,
           Logger::CallbackId::ErrorExit,
           Logger::CallbackId::FatalExit),
    callbackIdToString);


TEST_P(LoggerTest, callbackCall) {
  const string testMessage = "This is a test fatal message";
  NiceMock<MockLoggerCallback> callback;
  auto id = GetParam();

  m_logger.registerCallback(id, &callback);

  EXPECT_CALL(callback, call);

  switch (id) {
    case Logger::CallbackId::InfoExit:
      m_logger.info(testMessage.c_str());
      break;
    case Logger::CallbackId::WarningExit:
      m_logger.warning(testMessage.c_str());
      break;
    case Logger::CallbackId::ErrorExit:
      m_logger.error(testMessage.c_str());
      break;
    case Logger::CallbackId::FatalExit:
      m_logger.fatal(testMessage.c_str());
      break;
    default:
      break;
  };
}


TEST_P(LoggerTest, noCallbackCall) {
  const string testMessage = "This is a test fatal message";
  NiceMock<MockLoggerCallback> callback;
  auto id = GetParam();

  EXPECT_CALL(callback, call).Times(0);

  switch (id) {
    case Logger::CallbackId::InfoExit:
      m_logger.info(testMessage.c_str());
      break;
    case Logger::CallbackId::WarningExit:
      m_logger.warning(testMessage.c_str());
      break;
    case Logger::CallbackId::ErrorExit:
      m_logger.error(testMessage.c_str());
      break;
    case Logger::CallbackId::FatalExit:
      m_logger.fatal(testMessage.c_str());
      break;
    default:
      break;
  };
}
