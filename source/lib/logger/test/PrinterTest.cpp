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

  void clear()
  {
    LoggerOutputBuffer::clear();
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
  const string testMessage = "This is a test message";
  const string expectedMessage = testMessage + "\n\r";

  m_printer.printEndLine(true);
  m_printer.print(testMessage.c_str());
  checkMessage(expectedMessage);
}


TEST_F(PrinterTest, colorPrint)
{
  string testMessage = "This is a [:f1]red[] test message";
  string expectedMessage = "This is a \x1B[31mred\x1B[39m test message";
  m_printer.print(testMessage.c_str());
  checkMessage(expectedMessage);

  clear();

  testMessage = "This is a background [:b3]yellow[:b] test message";
  expectedMessage = "This is a background \x1B[43myellow\x1B[49m test message";
  m_printer.print(testMessage.c_str());
  checkMessage(expectedMessage);
}


TEST_F(PrinterTest, intArgumentPrint)
{
}


TEST_F(PrinterTest, arrayArgumentPrint)
{
}


TEST_F(PrinterTest, paddingArgumentPrint)
{
}


TEST_F(PrinterTest, alignArgumentPrint)
{
}


TEST_F(PrinterTest, formatArgumentPrint)
{
}
