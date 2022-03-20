#ifndef OS_LOGGER_H
#define OS_LOGGER_H

#include "logger/Logger.h"
#include "logger/ILoggerCallback.h"
#include "os/Mutex.h"

namespace stm32::lib {

class OsLogger : public Logger
{
public:
  OsLogger(os::Mutex& mutex) : Logger(),
    m_mutex(mutex)
  {};

  template<typename ... Args>
  void info(const char* text, Args ... args);

  template<typename ... Args>
  void warning(const char* text, Args ... args);

  template<typename ... Args>
  void error(const char* text, Args ... args);

  template<typename ... Args>
  void fatal(const char* text, Args ... args);

private:
    os::Mutex& m_mutex;
};


template<typename ... Args>
void OsLogger::info(const char* text, Args ... args)
{
  m_mutex.lock();
  Logger::info(text, args...);
  m_mutex.unlock();
}


template<typename ... Args>
void OsLogger::warning(const char* text, Args ... args)
{
  m_mutex.lock();
  Logger::warning(text, args...);
  m_mutex.unlock();
}


template<typename ... Args>
void OsLogger::error(const char* text, Args ... args)
{
  m_mutex.lock();
  Logger::error(text, args...);
  m_mutex.unlock();
}


template<typename ... Args>
void OsLogger::fatal(const char* text, Args ... args)
{
  m_mutex.lock();
  Logger::fatal(text, args...);
  m_mutex.unlock();
}

} // namespace

#endif /* OS_LOGGER_H */
