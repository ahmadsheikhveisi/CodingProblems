/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(BinaryToString, test1) {
  [[maybe_unused]] Solution uut {};
  static_assert(uut.FlipBitToWin(0b11011101111) == 8, "ERROR");
  EXPECT_EQ(uut.FlipBitToWin(0b11011101111), 8);
  EXPECT_EQ(uut.FlipBitToWin(0b11011001111), 5);
  EXPECT_EQ(uut.FlipBitToWin(0b11010001111), 5);
  EXPECT_EQ(uut.FlipBitToWin(0b11010001101), 4);
  EXPECT_EQ(uut.FlipBitToWin(0b00000001100), 3);
  EXPECT_EQ(uut.FlipBitToWin(0b00000010110), 4);
  EXPECT_EQ(uut.FlipBitToWin(0b11000000000), 3);
  EXPECT_EQ(uut.FlipBitToWin(0b11001001111), 5);
  EXPECT_EQ(uut.FlipBitToWin(0b11000011110), 5);
  EXPECT_EQ(uut.FlipBitToWin(0b11001011110), 6);
  EXPECT_EQ(uut.FlipBitToWin(0xFFFFFFFF), 32);
}
