#include "gtest/gtest.h"
#include "logger/Printer.h"
#include "LoggerOutputBuffer.h"
#include <string>
#include <array>
#include <tuple>
#include <fmt/core.h> // TODO replace with std when available


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

  template<typename T>
  void basicArgumentTestSequence(T param)
  {
    string testMessage = "This is a argument {} test message";
    string expectedMessage = fmt::format("This is a argument {} test message", param);

    m_printer.print(testMessage.c_str(), param);
    checkMessage(expectedMessage);
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


class PrinterColorTest : public PrinterTest, public testing::WithParamInterface<int> {};
INSTANTIATE_TEST_SUITE_P(PrinterColor, PrinterColorTest, Range(0, 10));


TEST_P(PrinterColorTest, colorPrint)
{
  auto color = to_string(GetParam());

  string testMessage = "This is a [:f" + color + "]red[] test message";
  string expectedMessage = "This is a \x1B[3" + color + "mred\x1B[39m test message";

  m_printer.print(testMessage.c_str());
  checkMessage(expectedMessage);

  clear();

  testMessage = "This is a background [:b" + color + "]yellow[:b] test message";
  expectedMessage = "This is a background \x1B[4" + color + "myellow\x1B[49m test message";

  m_printer.print(testMessage.c_str());
  checkMessage(expectedMessage);
}


class PrinterBoolTest : public PrinterTest, public testing::WithParamInterface<bool> {};
INSTANTIATE_TEST_SUITE_P(PrinterBool, PrinterBoolTest, Bool());


TEST_P(PrinterBoolTest, boolArgumentPrint)
{
  basicArgumentTestSequence(GetParam());
}


constexpr array<int, 4> IntArguments = {1234, -1234, 0x1000, -0x2049};
class PrinterIntTest : public PrinterTest, public testing::WithParamInterface<int> {};
INSTANTIATE_TEST_SUITE_P(PrinterInt, PrinterIntTest, ValuesIn(IntArguments));


TEST_P(PrinterIntTest, intArgumentPrint)
{
  basicArgumentTestSequence(GetParam());
}


constexpr array<const char*, 4> CharArrayArguments = {"Test Message", "Number 1234", "small letters", "snake_test_message"};
class PrinterCharArrayTest : public PrinterTest, public testing::WithParamInterface<const char*> {};
INSTANTIATE_TEST_SUITE_P(PrinterCharArray, PrinterCharArrayTest, ValuesIn(CharArrayArguments));


TEST_P(PrinterCharArrayTest, charArrayArgumentPrint)
{
  basicArgumentTestSequence(GetParam());
}


class PrinterMultipleArgumentsTest : public PrinterTest, public testing::WithParamInterface<tuple<int, const char*>> {};
INSTANTIATE_TEST_SUITE_P(PrinterMultipleArguments, PrinterMultipleArgumentsTest, Combine(ValuesIn(IntArguments), ValuesIn(CharArrayArguments)));


TEST_P(PrinterMultipleArgumentsTest, multipleArgumentPrint)
{
  auto multipleArguments = GetParam();
  string testMessage = "This is a {} multiple {} argument {} test message";
  string expectedMessage = fmt::format("This is a {} multiple {} argument {} test message", get<0>(multipleArguments), get<1>(multipleArguments), get<0>(multipleArguments));

  m_printer.print(testMessage.c_str(), get<0>(multipleArguments), get<1>(multipleArguments), get<0>(multipleArguments));
  checkMessage(expectedMessage);
}


TEST_P(PrinterIntTest, paddingArgumentPrint)
{
  auto testIntArgument = GetParam();
  string testMessage = "This is a padding {:08} argument {:02} test message";
  string expectedMessage = fmt::format("This is a padding {:08} argument {:02} test message", testIntArgument, testIntArgument);

  m_printer.print(testMessage.c_str(), testIntArgument, testIntArgument);
  checkMessage(expectedMessage);
}


TEST_P(PrinterIntTest, alignArgumentPrint)
{
  auto testIntArgument = GetParam();
  string testMessage = "This is a padding {:8} argument {:2} test {:>8} message";
  string expectedMessage = fmt::format("This is a padding {:8} argument {:2} test {:>8} message", testIntArgument, testIntArgument, testIntArgument);

  m_printer.print(testMessage.c_str(), testIntArgument, testIntArgument, testIntArgument);
  checkMessage(expectedMessage);
}


TEST_P(PrinterIntTest, formatArgumentPrint)
{
  auto testIntArgument = GetParam();
  string testMessage = "This {:#b} is a {:x} format {:#x} argument {:b} test message";
  string expectedMessage = fmt::format("This {:#b} is a {:x} format {:#x} argument {:b} test message", testIntArgument, testIntArgument, testIntArgument, testIntArgument);

  m_printer.print(testMessage.c_str(), testIntArgument, testIntArgument, testIntArgument, testIntArgument);
  checkMessage(expectedMessage);
}
