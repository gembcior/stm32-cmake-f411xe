#include "gtest/gtest.h"
#include "logger/Printer.h"
#include "LoggerOutputBuffer.h"
#include <string>


using namespace ::testing;
using namespace stm32::lib;
using namespace std;


class PrinterTest : public Test
{
public:
  PrinterTest()
  {
    m_printer.registerOutput(LoggerOutputBuffer::outputFunction);
  }

  void checkMessage(const string expectedMessage)
  {
    ASSERT_STREQ(expectedMessage.c_str(), LoggerOutputBuffer::getPointer());
  }

protected:
  Printer m_printer;
};


TEST_F(PrinterTest, simplePrint)
{
  const string testMessage = "This is a test message";

  m_printer.print(testMessage.c_str());
  checkMessage(testMessage);
}


TEST_F(PrinterTest, endLinePrint)
{
  const string testMessage = "\n\r";
}
