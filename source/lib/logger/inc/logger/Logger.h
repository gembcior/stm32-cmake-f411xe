#ifndef LOGGER_H
#define LOGGER_H

#include "logger/Printer.h"
#include "logger/ILoggerCallback.h"

namespace stm32::lib {

enum class LoggerLevel : char {
  Info = 'I',
  Warning = 'W',
  Error = 'E',
  Fatal = 'F',
};


enum class LoggerCallbackId {
  InfoExit,
  WarningExit,
  ErrorExit,
  FatalExit,
  Count,
};


class Logger : public Printer
{
public:
  void registerCallback(LoggerCallbackId id, ILoggerCallback* callback);

  template<typename ... Args>
  void info(const char* text, Args ... args);

  template<typename ... Args>
  void warning(const char* text, Args ... args);

  template<typename ... Args>
  void error(const char* text, Args ... args);

  template<typename ... Args>
  void fatal(const char* text, Args ... args);

private:
  void printLevel(LoggerLevel level);

private:
  static constexpr unsigned int callbackCount = static_cast<unsigned int>(LoggerCallbackId::Count);

private:
  ILoggerCallback* m_callback[callbackCount] = {};
};


template<typename ... Args>
void Logger::info(const char* text, Args ... args)
{
  print(text, args...);
  printEndLine();

  if (m_callback[static_cast<unsigned int>(LoggerCallbackId::InfoExit)]) {
    m_callback[static_cast<unsigned int>(LoggerCallbackId::InfoExit)]->call();
  }
}


template<typename ... Args>
void Logger::warning(const char* text, Args ... args)
{
  printColorMark(PrinterColorMark::Yellow);
  printLevel(LoggerLevel::Warning);
  print(text, args...);
  printColorMark(PrinterColorMark::Default);
  printEndLine();

  if (m_callback[static_cast<unsigned int>(LoggerCallbackId::WarningExit)]) {
    m_callback[static_cast<unsigned int>(LoggerCallbackId::WarningExit)]->call();
  }
}


template<typename ... Args>
void Logger::error(const char* text, Args ... args)
{
  printColorMark(PrinterColorMark::Red);
  printLevel(LoggerLevel::Error);
  print(text, args...);
  printColorMark(PrinterColorMark::Default);
  printEndLine();

  if (m_callback[static_cast<unsigned int>(LoggerCallbackId::ErrorExit)]) {
    m_callback[static_cast<unsigned int>(LoggerCallbackId::ErrorExit)]->call();
  }
}


template<typename ... Args>
void Logger::fatal(const char* text, Args ... args)
{
  printColorMark(PrinterColorMark::Black);
  printColorMark(PrinterColorMark::Red, PrinterColorType::Background);
  printLevel(LoggerLevel::Fatal);
  print(text, args...);
  printColorMark(PrinterColorMark::Default, PrinterColorType::Background);
  printColorMark(PrinterColorMark::Default);
  printEndLine();

  if (m_callback[static_cast<unsigned int>(LoggerCallbackId::FatalExit)]) {
    m_callback[static_cast<unsigned int>(LoggerCallbackId::FatalExit)]->call();
  }
}

} // namespace

#endif /* LOGGER_H */
