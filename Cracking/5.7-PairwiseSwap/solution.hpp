/**
 * Copyright
 * Write a program to swap odd and even bits in an integer with as few
 * instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3
 * are swapped, and so on.)
 */

#ifndef CRACKING_5_7_PAIRWISESWAP_SOLUTION_HPP_
#define CRACKING_5_7_PAIRWISESWAP_SOLUTION_HPP_

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
  constexpr int32_t PairwaseSwap(int32_t num) {
    return ((num & 0xAAAAAAAA) >> 1) | ((num & 0x55555555) << 1);
  }
};

#endif  // CRACKING_5_7_PAIRWISESWAP_SOLUTION_HPP_
