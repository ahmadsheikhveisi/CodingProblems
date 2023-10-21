/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(BinaryToString, test1) {
  [[maybe_unused]] Solution uut {};
  std::cout << uut.BinaryToString(0.72) << '\n';
  std::cout << uut.BinaryToString(0.75) << '\n';
  std::cout << uut.BinaryToString2(0.72) << '\n';
  std::cout << uut.BinaryToString2(0.75) << '\n';
}
