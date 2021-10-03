#ifndef PRINTER_H
#define PRINTER_H

#include <cstdint>
#include <type_traits>
#include <charconv>

namespace stm32::lib {

class Printer
{
public:
  using OutputFunction = void(*)(const char);

  enum Color : char {
    Black   = '0',
    Red     = '1',
    Green   = '2',
    Yellow  = '3',
    Blue    = '4',
    Magenta = '5',
    Cyan    = '6',
    White   = '7',
    Default = '9',
  };

  enum ColorType : char {
    Foreground = '3',
    Background = '4',
  };

public:
  Printer(bool endLine = false);

  void registerOutput(OutputFunction out);
  template<typename ... Args>
  void print(const char* text, Args ... arguments);

protected:
  void printColorMark(char mark, char type = Foreground);
  void printAttributeMark(char mark);
  void printEndLine();

protected:
  OutputFunction m_out;

private:
  enum FormatType {
    None,
    Dec,
    Hex,
    Bin,
    Float,
  };

  enum AlignDirection {
    Start,
    End,
  };

  static constexpr char EscCharacter = 0x1B;
  static constexpr unsigned int MaxDigits = 32;
  static constexpr char ArgumentStartMark = '{';
  static constexpr char ArgumentEndMark = '}';
  static constexpr char ArgumentFormatMark = ':';
  static constexpr char ColorStartMark = '[';
  static constexpr char ColorEndMark = ']';
  static constexpr char ColorNumberMark = ArgumentFormatMark;

private:
  struct ArgumentFormat {
    FormatType type = None;
    AlignDirection alignDirection = End;
    uint32_t width = 0;
    uint32_t precision = 0;
    bool padding = false;
    bool alternateForm = false;
    bool dot = false;
  };

private:
  template<typename Arg, typename ... Args>
  void mainPrint(const char* text, Arg argument, Args ... arguments);
  void mainPrint(const char* text);
  void parseColorMark(const char* &text);
  template<typename Arg>
  bool parseArgumentMark(const char* &text, Arg argument);
  void updateFormat(char text, ArgumentFormat& format);
  void printBuffer(const char* buffer);

  template<typename Arg>
  void printArgument(Arg argument, ArgumentFormat format,
      std::enable_if_t<std::is_integral_v<Arg>>* = nullptr);
  template<typename Arg>
  void printArgument(Arg argument, ArgumentFormat format,
      std::enable_if_t<std::is_floating_point_v<Arg>>* = nullptr);
  template<typename Arg>
  void printArgument(Arg argument, ArgumentFormat format,
      std::enable_if_t<std::is_same_v<Arg, char*> || std::is_same_v<Arg, const char*>>* = nullptr);

private:
  bool m_endLine;
};


template<typename ... Args>
void Printer::print(const char* text, Args ... arguments)
{
  mainPrint(text, arguments...);
}


template<typename Arg, typename ... Args>
void Printer::mainPrint(const char* text, Arg argument, Args ... arguments)
{
  while (*text) {
    if (parseArgumentMark(text, argument)) {
      break;
    } else {
      parseColorMark(text);
      if (m_out) m_out(*text);
      text++;
    }
  }
  mainPrint(text, arguments...);
}


template<typename Arg>
bool Printer::parseArgumentMark(const char* &text, Arg argument)
{
  if (*text == ArgumentStartMark) {
    text++;
    ArgumentFormat format;
    if (*text == ArgumentFormatMark) {
      text++;
      while (*text != ArgumentEndMark) {
        updateFormat(*text, format);
        text++;
      }
      text++;
      printArgument(argument, format);
      return true;
    } else if (*text == ArgumentEndMark) {
      text++;
      printArgument(argument, format);
      return true;
    } else {
      text--;
    }
  }
  return false;
}


template<typename Arg>
void Printer::printArgument(Arg argument, ArgumentFormat format,
    std::enable_if_t<std::is_integral_v<Arg>>*)
{
  char buffer[MaxDigits] = {};

  uint32_t base;
  switch (format.type) {
    case Dec:
      base = 10;
      break;
    case Hex:
      base = 16;
      break;
    case Bin:
      base = 2;
      break;
    default:
      base = 10;
      break;
  }

  std::to_chars(buffer, buffer + MaxDigits, argument, base);
  printBuffer(buffer);
}


template<typename Arg>
void Printer::printArgument(Arg argument, ArgumentFormat format,
    std::enable_if_t<std::is_floating_point_v<Arg>>*)
{
}


template<typename Arg>
void Printer::printArgument(Arg argument, ArgumentFormat format,
    std::enable_if_t<std::is_same_v<Arg, char*> || std::is_same_v<Arg, const char*>>*)
{
  printBuffer(argument);
}

}; // namespace

#endif /* PRINTER_H */
