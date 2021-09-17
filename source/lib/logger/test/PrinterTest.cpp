#include "gtest/gtest.h"
#include "logger/Printer.h"
#include <string>


using namespace ::testing;
using namespace stm32::lib;
using namespace std;


template<typename T>
class PrinterTest : public Test
{
public:
  PrinterTest()
  {
    m_printer.registerOutput(printerOutputFunction);
  }

  static void printerOutputFunction(const char character)
  {
    m_message += character;
  }

protected:
  Printer m_printer;
  static string m_message;
};

template<typename T>
string PrinterTest<T>::m_message;

using PrinterArgumentsTypes = Types<
  char,
  int,
  unsigned int,
  const char*,
  char*
>;
TYPED_TEST_SUITE(PrinterTest, PrinterArgumentsTypes);


TYPED_TEST(PrinterTest, simplePrint) {
  const string testMessage = "This is a test info message";
  Printer* printer = &this->m_printer;
  string* message = &this->m_message;

  printer->print(testMessage.c_str());
  ASSERT_STREQ(testMessage.c_str(), message->c_str());
}


TYPED_TEST(PrinterTest, singleArgument) {
  const string testMessage = "This is a test info message {}";
  Printer* printer = &this->m_printer;
  string* message = &this->m_message;

  printer->print(testMessage.c_str());
  ASSERT_STREQ(testMessage.c_str(), message->c_str());
}
