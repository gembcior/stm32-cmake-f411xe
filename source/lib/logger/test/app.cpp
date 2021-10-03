#include <iostream>
#include <cstdint>

#include "logger/Printer.h"
#include "logger/Logger.h"

using namespace stm32::lib;

void putChar(const char character)
{
  std::cout << character;
}


int main()
{
  Printer printer(true);
  printer.registerOutput(putChar);
  printer.print("Printer test message");
  printer.print("Printer [:f1]test[] message");
  printer.print("Printer [:b2]test[:b] message");
  printer.print("Printer [:f4]test[] {} message", 1234);
  printer.print("Test } lonely {mark {}", 3345);
  printer.print("Test ] lonely [mark {}", 3345);
  printer.print("Test hex {:#x} number", 1234);
  printer.print("Test bin {:#b} number", 1234);
  printer.print("Test padding hex {:08x} number", 0x34);
  printer.print("Test extra padding hex {:#08x} number", 0x34);
  printer.print("Test big padding hex {:018x} number", 0x34);
  printer.print("Test align start {:<8} number", 0x34);
  printer.print("Test align end {:>6} number", 34);
  printer.print("Test align {:#7x} number", 12);
  printer.print("Test {:x} char", '0');
  printer.print("Test {} raw char", '0');
  printer.print("Test {} less than zero", -123);
  printer.print("Test {:x} unsigned long", 1234UL);
  char tablica[] = "testowaTablica";
  printer.print("Test {} char pointer", tablica);
  printer.print("Test {:20} align char pointer", tablica);
  printer.print("Test {:>21} align char pointer", tablica);
  printer.print("Test {} char pointer", "masakra");
  printer.print("Test {:19} align char pointer", "masakra");
  printer.print("Test {:>19} align char pointer", "masakra");

  Logger logger;
  logger.registerOutput(putChar);
  logger.info("test message");
  logger.warning("warning test message");
  logger.error("error [:f4]test[:f1] test message");
  logger.info("test message");

  return 0;
}
