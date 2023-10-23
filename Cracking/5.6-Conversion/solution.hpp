/**
 * Copyright
 * Write a function to determine the number of bits you would need to flip to
 * convert integer A to integer B.
 *
 * Input: 29 (11101), 15 (01111)
 * Output: 2
 */

#ifndef CRACKING_5_6_CONVERSION_SOLUTION_HPP_
#define CRACKING_5_6_CONVERSION_SOLUTION_HPP_

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
  constexpr size_t NumberOfBitCoversion(int32_t A, int32_t B) {
    auto num_xor = A ^ B;
    size_t res{0};
    while (num_xor != 0) {
      if ((num_xor & 1) != 0) {
        ++res;
      }
      num_xor >>= 1;
    }
    return res;
  }

  constexpr size_t UsingClearLeastSignificatBit(int32_t A, int32_t B) {
    size_t res{0};
    for (int32_t cnt{A ^ B}; cnt != 0; cnt = cnt & (cnt - 1)) {
      ++res;
    }
    return res;
  }
};

#endif  // CRACKING_5_6_CONVERSION_SOLUTION_HPP_
