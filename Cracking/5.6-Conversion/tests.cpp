/**
 * Copyright
 */

#include <bitset>

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(DebuggerTest, test1) {
  [[maybe_unused]] Solution uut {};
  EXPECT_EQ(uut.NumberOfBitCoversion(29, 15), 2);
  EXPECT_EQ(uut.NumberOfBitCoversion(12, 12), 0);
  static_assert(uut.NumberOfBitCoversion(29, 15) == 2, "ERROR");
  static_assert(uut.NumberOfBitCoversion(12, 12) == 0, "ERROR");
}
