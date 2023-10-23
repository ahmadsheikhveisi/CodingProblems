/**
 * Copyright
 */

#include <bitset>

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(DebuggerTest, test1) {
  [[maybe_unused]] Solution uut {};
  EXPECT_EQ(uut.PairwaseSwap(0b1100), 0b1100);
  EXPECT_EQ(uut.PairwaseSwap(0b1000), 0b0100);
  EXPECT_EQ(uut.PairwaseSwap(0b1001), 0b0110);
  static_assert(uut.PairwaseSwap(0b0101) == 0b1010, "ERROR");
}
