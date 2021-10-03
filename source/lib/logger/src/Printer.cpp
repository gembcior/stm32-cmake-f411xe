#include "logger/Printer.h"
#include <charconv>


namespace stm32::lib {

Printer::Printer(bool endLine) :
  m_out(nullptr),
  m_endLine(endLine)
{
}


void Printer::registerOutput(OutputFunction out)
{
  m_out = out;
}


void Printer::printColorMark(char mark, char type)
{
  if (m_out) {
    m_out(EscCharacter);
    m_out('[');
    m_out(type);
    m_out(mark);
    m_out('m');
  }
}


void Printer::printAttributeMark(char mark)
{
  if (m_out) {
    m_out(EscCharacter);
    m_out('[');
    m_out(mark);
    m_out('m');
  }
}


void Printer::printEndLine()
{
  if (m_out) {
    m_out('\n');
    m_out('\r');
  }
}


void Printer::parseColorMark(const char* &text)
{
  if (*text == ColorStartMark) {
    text++;
    if (*text == ColorNumberMark) {
      text++;
      char colorMark = Default;
      char colorType = Foreground;
      while (*text != ColorEndMark) {
        if (*text == 'f') {
          colorType = Foreground;
        } else if (*text == 'b') {
          colorType = Background;
        } else if (*text >= Black && *text <= Default) {
          colorMark = *text;
        } else {
          colorMark = Default;
          colorType = Foreground;
        }
        text++;
      }
      text++;
      printColorMark(colorMark, colorType);
    } else if (*text == ColorEndMark) {
      text++;
      printColorMark(Default);
    } else {
      text--;
    }
  }
}


void Printer::updateFormat(char text, ArgumentFormat& format)
{
  if (text == '#') {
    format.alternateForm = true;
  } else if (text == '>') {
    format.alignDirection = End;
  } else if (text == '<') {
    format.alignDirection = Start;
  } else if (text == 'x') {
    format.type = Hex;
  } else if (text == 'b') {
    format.type = Bin;
  } else if (text == 'd') {
    format.type = Dec;
  } else if (text == 'f') {
    format.type = Float;
  } else if (text == '0') {
    format.padding = true;
  } else if (text == '.') {
    format.dot = true;
  } else if (text >= '1' && text <= '9') {
    if (format.dot) {
      format.precision = (format.precision * 10) + (text - '0');
    } else {
      format.width = (format.width * 10) + (text - '0');
    }
  }
}


void Printer::mainPrint(const char* text)
{
  while (*text) {
    parseColorMark(text);
    if (m_out) m_out(*text);
    text++;
  }
  if (m_endLine) printEndLine();
}


void Printer::printBuffer(const char* buffer)
{
  while (*buffer) {
    if (m_out) m_out(*buffer);
    buffer++;
  }
}


//template<>
//void Printer::printArgument(int argument, ArgumentFormat format)
//{
//  printIntArgument(argument, format);
//}


//template<>
//void Printer::printArgument(unsigned int argument, ArgumentFormat format)
//{
//  char buffer[MaxDigits] = {};
//
//  uint32_t base;
//  switch (format.type) {
//    case Dec:
//      base = 10;
//      break;
//    case Hex:
//      base = 16;
//      break;
//    case Bin:
//      base = 2;
//      break;
//    default:
//      base = 10;
//      break;
//  }
//
//  std::to_chars(buffer, buffer + MaxDigits, argument, base);
//  printBuffer(buffer);
//}


//template<>
//void Printer::printArgument(const char* argument, ArgumentFormat format)
//{
//  printBuffer(argument);
//}
//
//
//template<>
//void Printer::printArgument(const char* &argument, ArgumentFormat format)
//{
//  printBuffer(argument);
//}
//
//
//template<>
//void Printer::printArgument(char* argument, ArgumentFormat format)
//{
//  printBuffer(argument);
//}

} // namespace
