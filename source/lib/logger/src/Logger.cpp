#include "logger/Logger.h"


namespace stm32::logger {

Logger::Logger()
{
}


void Logger::registerCallback(LoggerCallbackId id, ILoggerCallback* callback)
{
  m_callback[static_cast<unsigned int>(id)] = callback;
}


void Logger::printLevel(LoggerLevel level)
{
  const char levelText[] = {
    static_cast<char>(level),
    ':',
    ' '
  };

  printBuffer(levelText);
}

} // namespace
