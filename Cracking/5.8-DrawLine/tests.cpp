/**
 * Copyright
 */

#include <bitset>

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(DebuggerTest, test1) {
  [[maybe_unused]] Solution uut {};
  size_t width{24};
  size_t height{3};
  std::vector<uint8_t> screen((height * width / 8), 0);
  uut.DrawLine(screen, width, 3, 20, 1);
  uut.DrawLine(screen, width, 3, 7, 0);
  // uut.DrawLine(screen, width, 16, 20, 0);
  for (size_t y{0}; y < height; ++y) {
    for (size_t x{0}; x < width / 8; ++x) {
      std::cout << std::bitset<8>(screen[x + (y * width / 8)]) << ' ';
    }
    std::cout << '\n';
  }
}
