#include "LoggerOutputBuffer.h"

using namespace std;

string LoggerOutputBuffer::m_buffer;


void LoggerOutputBuffer::outputFunction(const char character)
{
  m_buffer += character;
}


const char* LoggerOutputBuffer::getPointer()
{
  return m_buffer.c_str();
}


void LoggerOutputBuffer::clear()
{
  m_buffer.clear();
}
