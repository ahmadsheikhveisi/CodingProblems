/**
 * Copyright
 */

#include <bitset>

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(DebuggerTest, test1) {
  [[maybe_unused]] Solution uut {};
  std::cout << std::bitset<32>(uut.Debugger(0b00100)) << '\n';
  std::cout << std::bitset<32>(uut.Debugger(0b00000)) << '\n';
  std::cout << std::bitset<32>(uut.Debugger(0b00111)) << '\n';
  std::cout << std::bitset<32>(uut.Debugger(0b01100)) << '\n';
}

