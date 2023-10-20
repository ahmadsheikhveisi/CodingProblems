/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "bit_tools.hpp"

TEST(BitManipulation, GetBit) {
  static_assert(GetBit(5, 0));
  EXPECT_TRUE(GetBit(5, 0));
  EXPECT_TRUE(GetBit(8, 3));
  EXPECT_FALSE(GetBit(0xFF, 16));
}

TEST(BitManipulation, SetBit) {
  EXPECT_EQ(SetBit(5, 0), 5);
  EXPECT_EQ(SetBit(8, 2), 12);
  EXPECT_EQ(SetBit(0xFF, 16), 0x100FF);
}

TEST(BitManipulation, ClearBit) {
  EXPECT_EQ(ClearBit(5, 0), 4);
  EXPECT_EQ(ClearBit(8, 2), 8);
  EXPECT_EQ(ClearBit(0xFF, 6), 0xBF);
}

TEST(BitManipulation, ClearBitRange) {
  EXPECT_EQ(ClearBitRange((uint8_t)5, 0, 2), 0);
  EXPECT_EQ(ClearBitRange((uint8_t)8, 0, 2), 8);
  EXPECT_EQ(ClearBitRange((uint32_t)0xFF, 4, 7), 0x0F);
}

TEST(BitManipulation, SetBitRange) {
  EXPECT_EQ(SetBitRange((uint8_t)5, 0, 2), 7);
  EXPECT_EQ(SetBitRange((uint8_t)8, 0, 2), 0xF);
  EXPECT_EQ(SetBitRange((uint32_t)0xFF, 4, 7), 0xFF);
}

TEST(BitManipulation, UpdateBit) {
  EXPECT_EQ(UpdateBit(5, 0, false), 4);
  EXPECT_EQ(UpdateBit(8, 2, true), 12);
  EXPECT_EQ(UpdateBit(0xFF, 6, false), 0xBF);
}

TEST(BitManipulation, ToggleBit) {
  EXPECT_EQ(ToggleBit(5, 0), 4);
  EXPECT_EQ(ToggleBit(8, 2), 12);
  EXPECT_EQ(ToggleBit(0xFF, 6), 0xBF);
}
