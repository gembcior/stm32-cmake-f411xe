#ifndef LOGGER_OUTPUT_BUFFER_H
#define LOGGER_OUTPUT_BUFFER_H

#include <string>

class LoggerOutputBuffer
{
public:
  static void outputFunction(const char character);
  static const char* getPointer();
  static void clear();

private:
  static std::string m_buffer;
};

#endif /* LOGGER_OUTPUT_BUFFER_H */
