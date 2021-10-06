#ifndef LOGGER_H
#define LOGGER_H

#include "logger/Printer.h"
#include "logger/ILoggerCallback.h"

namespace stm32::lib {

class Logger : public Printer
{
public:
  enum class CallbackId {
    InfoExit,
    WarningExit,
    ErrorExit,
    FatalExit,
    Count,
  };

public:
  Logger();

  void registerCallback(CallbackId id, ILoggerCallback* callback);

  template<typename ... Args>
  void info(const char* text, Args ... args);

  template<typename ... Args>
  void warning(const char* text, Args ... args);

  template<typename ... Args>
  void error(const char* text, Args ... args);

  template<typename ... Args>
  void fatal(const char* text, Args ... args);

private:
  enum class Level : char {
    Info = 'I',
    Warning = 'W',
    Error = 'E',
    Fatal = 'F',
  };

private:
  static constexpr unsigned int callbackCount = static_cast<unsigned int>(CallbackId::Count);

private:
  void printLevel(Level level);

private:
  ILoggerCallback* m_callback[callbackCount] = {};
};


template<typename ... Args>
void Logger::info(const char* text, Args ... args)
{
  print(text, args...);

  if (m_callback[static_cast<unsigned int>(CallbackId::InfoExit)]) {
    m_callback[static_cast<unsigned int>(CallbackId::InfoExit)]->call();
  }
}


template<typename ... Args>
void Logger::warning(const char* text, Args ... args)
{
  printColorMark(Color::Yellow);
  printLevel(Level::Warning);
  print(text, args...);
  printColorMark(Color::Default);

  if (m_callback[static_cast<unsigned int>(CallbackId::WarningExit)]) {
    m_callback[static_cast<unsigned int>(CallbackId::WarningExit)]->call();
  }
}


template<typename ... Args>
void Logger::error(const char* text, Args ... args)
{
  printColorMark(Color::Red);
  printLevel(Level::Error);
  print(text, args...);
  printColorMark(Color::Default);

  if (m_callback[static_cast<unsigned int>(CallbackId::ErrorExit)]) {
    m_callback[static_cast<unsigned int>(CallbackId::ErrorExit)]->call();
  }
}


template<typename ... Args>
void Logger::fatal(const char* text, Args ... args)
{
  printColorMark(Color::Black);
  printColorMark(Color::Red, ColorType::Background);
  printLevel(Level::Fatal);
  print(text, args...);
  printColorMark(Color::Default, ColorType::Background);
  printColorMark(Color::Default);

  if (m_callback[static_cast<unsigned int>(CallbackId::FatalExit)]) {
    m_callback[static_cast<unsigned int>(CallbackId::FatalExit)]->call();
  }
}

} // namespace

#endif /* LOGGER_H */
