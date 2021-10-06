#include "logger/Logger.h"


namespace stm32::lib {

Logger::Logger() : Printer(true)
{}


void Logger::registerCallback(CallbackId id, ILoggerCallback* callback)
{
  m_callback[static_cast<unsigned int>(id)] = callback;
}


void Logger::printLevel(Level level)
{
  if (m_out) {
    m_out(static_cast<char>(level));
    m_out(':');
    m_out(' ');
  }
}

} // namespace
