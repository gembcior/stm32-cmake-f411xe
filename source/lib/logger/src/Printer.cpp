#include "logger/Printer.h"
#include <charconv>


namespace stm32::logger {

Printer::Printer() : m_out(nullptr)
{
}
void Printer::registerOutput(OutputFunction out)
{
  m_out = out;
}


void Printer::printBuffer(const char* buffer)
{
  while (*buffer) {
    if (m_out) m_out(*buffer);
    buffer++;
  }
}


void Printer::mainPrint(const char* text)
{
  printBuffer(text);
  if (m_out) m_out('\n');
  if (m_out) m_out('\r');
}


void Printer::printEscCharacter()
{
  if (m_out) m_out(0x1B);
}


void Printer::printColorMark(PrinterColorMark mark, PrinterColorType type)
{
  printEscCharacter();
  if (m_out) {
    m_out('[');
    m_out(static_cast<char>(type));
    m_out(static_cast<char>(mark));
    m_out('m');
  }
}


void Printer::printAttributeMark(PrinterAttributeMark mark)
{
  printEscCharacter();
  const char attributeMark[] = {
    '[',
    static_cast<char>(mark),
    'm'
  };
  printBuffer(attributeMark);
}


template<>
void Printer::printArgument(int argument)
{
  char buffer[MaxDigits] = {};
  std::to_chars(buffer, buffer + MaxDigits, argument, 10);
  printBuffer(buffer);
}


template<>
void Printer::printArgument(unsigned int argument)
{
  char buffer[MaxDigits] = {};
  std::to_chars(buffer, buffer + MaxDigits, argument, 10);
  printBuffer(buffer);
}


template<>
void Printer::printArgument(const char* argument)
{
  printBuffer(argument);
}


template<>
void Printer::printArgument(char* argument)
{
  printBuffer(argument);
}

} // namespace
