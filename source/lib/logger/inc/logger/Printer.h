#ifndef PRINTER_H
#define PRINTER_H


namespace stm32::logger {

enum class PrinterColorMark : char {
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


enum class PrinterColorType : char {
  Foreground = '3',
  Background = '4',
};


enum class PrinterAttributeMark : char {
  Reset      = '0',
  Bright     = '1',
  Dim        = '2',
  Standout   = '3',
  Underscore = '4',
  Blink      = '5',
  Reverse    = '7',
  Hidden     = '8',
};


class Printer
{
public:
  using OutputFunction = void(*)(const char);

public:
  Printer();

public:
  template<typename ... Args>
  void print(const char* text, Args ... arguments);
  void printColorMark(PrinterColorMark mark, PrinterColorType type = PrinterColorType::Foreground);
  void printAttributeMark(PrinterAttributeMark mark);

  void registerOutput(OutputFunction out);


protected:
  void printBuffer(const char* buffer);

private:
  template<typename Arg, typename ... Args>
  void mainPrint(const char*& text, Arg argument, Args ... arguments);
  void mainPrint(const char* text);


  template<typename T>
  void printArgument(T argument);

  void printEscCharacter();

private:
  static constexpr unsigned int MaxDigits = 12;
  static constexpr char ArgumentStartMark = '{';
  static constexpr char ArgumentEndMark = '}';
  static constexpr char ArgumentFormatMark = ':';

private:
  OutputFunction m_out;
};


template<typename ... Args>
void Printer::print(const char* text, Args ... arguments)
{
  mainPrint(text, arguments...);
}


template<typename Arg, typename ... Args>
void Printer::mainPrint(const char*& text, Arg argument, Args ... arguments)
{
  while (*text) {
    if (*text == ArgumentStartMark) {
      text++;


      if (*text == ArgumentFormatMark) {
        while (*text != ArgumentEndMark) {
          // TODO replace with format parser
          text++;
        }
      }

      if (*text == ArgumentEndMark) {
        text++;
        printArgument(argument);
        break;
      } else {
        if (m_out) m_out(*text);
        text++;
        continue;
      }
    } else {
      if (m_out) m_out(*text);
      text++;
      continue;
    }
  }
  mainPrint(text, arguments...);
}

}; // namespace

#endif /* PRINTER_H */
