/**
 * Copyright
 */

#include <bitset>

#include "gtest/gtest.h"

#include "solution.hpp"

void PrintNumAndRes(uint32_t num, Solution::Results res) {
  std::cout << num << ' ' << std::bitset<32>(num) << '\n'
            << res.next_largest_ << ' ' << std::bitset<32>(res.next_largest_)
            << '\n'
            << res.next_smallest_ << ' ' << std::bitset<32>(res.next_smallest_)
            << '\n';
}

TEST(BinaryToString, test1) {
  [[maybe_unused]] Solution uut {};
  uint32_t num{0b11011};
  auto res = uut.NextNumbers(num);
  EXPECT_EQ(res.next_largest_, 0b11101);
  EXPECT_EQ(res.next_smallest_, 0b10111);
  PrintNumAndRes(num, res);
  EXPECT_EQ(uut.GetNextNumberArth(num), 0b11101);
  EXPECT_EQ(uut.GetPrevNumberArth(num), 0b10111);
}

TEST(BinaryToString, test2) {
  [[maybe_unused]] Solution uut {};
  uint32_t num{0b110011};
  auto res = uut.NextNumbers(num);
  EXPECT_EQ(res.next_largest_, 0b110101);
  EXPECT_EQ(res.next_smallest_, 0b101110);
  PrintNumAndRes(num, res);
  EXPECT_EQ(uut.GetNextNumberArth(num), 0b110101);
  EXPECT_EQ(uut.GetPrevNumberArth(num), 0b101110);
}

TEST(BinaryToString, test3) {
  [[maybe_unused]] Solution uut {};
  uint32_t num{0b11000};
  auto res = uut.NextNumbers(num);
  EXPECT_EQ(res.next_largest_, 0b100001);
  EXPECT_EQ(res.next_smallest_, 0b10100);
  PrintNumAndRes(num, res);
  EXPECT_EQ(uut.GetNextNumberArth(num), 0b100001);
  EXPECT_EQ(uut.GetPrevNumberArth(num), 0b10100);
}

TEST(BinaryToString, test4) {
  [[maybe_unused]] Solution uut {};
  uint32_t num{0x80000000};
  auto res = uut.NextNumbers(num);
  EXPECT_EQ(res.next_largest_, 0x80000000);
  EXPECT_EQ(res.next_smallest_, 0x40000000);
  PrintNumAndRes(num, res);
  EXPECT_EQ(uut.GetNextNumberArth(num), 0x80000000);
  EXPECT_EQ(uut.GetPrevNumberArth(num), 0x40000000);
}

TEST(BinaryToString, test5) {
  [[maybe_unused]] Solution uut {};
  uint32_t num{0b11011001111100};
  auto res = uut.NextNumbers(num);
  EXPECT_EQ(res.next_largest_, 0b11011010001111);
  EXPECT_EQ(res.next_smallest_, 0b11011001111010);
  PrintNumAndRes(num, res);
  EXPECT_EQ(uut.GetNextNumberArth(num), 0b11011010001111);
  EXPECT_EQ(uut.GetPrevNumberArth(num), 0b11011001111010);
}

TEST(BinaryToString, test6) {
  [[maybe_unused]] Solution uut {};
  uint32_t num{0b1001111000011};
  auto res = uut.NextNumbers(num);
  EXPECT_EQ(res.next_largest_, 0b1001111000101);
  EXPECT_EQ(res.next_smallest_, 0b1001110111000);
  PrintNumAndRes(num, res);
  EXPECT_EQ(uut.GetNextNumberArth(num), 0b1001111000101);
  EXPECT_EQ(uut.GetPrevNumberArth(num), 0b1001110111000);
}

TEST(BinaryToString, test7) {
  [[maybe_unused]] Solution uut {};
  uint32_t num{0b001};
  auto res = uut.NextNumbers(num);
  EXPECT_EQ(res.next_largest_, 0b010);
  EXPECT_EQ(res.next_smallest_, 0b001);
  PrintNumAndRes(num, res);
  EXPECT_EQ(uut.GetNextNumberArth(num), 0b010);
  EXPECT_EQ(uut.GetPrevNumberArth(num), 0b001);
}

TEST(BinaryToString, test8) {
  [[maybe_unused]] Solution uut {};
  uint32_t num{0};
  auto res = uut.NextNumbers(num);
  EXPECT_EQ(res.next_largest_, 0);
  EXPECT_EQ(res.next_smallest_, 0);
  PrintNumAndRes(num, res);
  EXPECT_EQ(uut.GetNextNumberArth(num), 0);
  EXPECT_EQ(uut.GetPrevNumberArth(num), 0);
}
