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
  printer.print("Test hex {:x} number", 1234);
  printer.print("Test bin {:b} number", 1234);
  printer.print("Test padding hex {:08x} number", 0x34);
  printer.print("Test big padding hex {:018x} number", 0x34);
  printer.print("Test align start {:<8} number", 0x34);
  printer.print("Test align end {:>6} number", 34);
  printer.print("Test align {:7} number", 12);
  printer.print("Test {:x} char", '0');
  printer.print("Test {:x} unsigned long", 1234UL);
  printer.print("Test {} float", 1.2);
  char tablica[] = "testowaTablica";
  printer.print("Test {} char pointer", tablica);
  printer.print("Test {} char pointer", "masakra");

  return 0;
}
