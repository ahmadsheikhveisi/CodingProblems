/**
 * Copyright
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j.
 * Write a method to insert M into N such that M starts at bit j and ends at bit
 * i. You can assume that bits j through i have enough space to fit all of M.
 * that is , if M = 0x10011, you can assume that there are at least 5 bits
 * between j and i. You would not, for example, have j = 3 and i = 2, because M
 * could not fully fit between bit 3 and bit 2.
 *
 * Input: N = 10000000000, M = 10011, i = 2, j = 6
 * Output: N = 10001001100
 */

#ifndef CRACKING_5_1_INSERTION_SOLUTION_HPP_
#define CRACKING_5_1_INSERTION_SOLUTION_HPP_

#include <algorithm>
#include <list>
#include <memory>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "bit_tools.hpp"

class Solution {
 public:
  constexpr int32_t Insert(int32_t N, int32_t M, size_t i, size_t j) {
    N = ClearBitRange(N, i, j);
    N |= (M << i);
    return N;
  }
};

#endif  // CRACKING_5_1_INSERTION_SOLUTION_HPP_
