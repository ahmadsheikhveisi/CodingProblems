/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(BitInsert, test1) {
  Solution uut{};
  EXPECT_EQ(uut.Insert(0b100'0000'0000, 0b1'0011, 2, 6), 0b100'0100'1100);
}
