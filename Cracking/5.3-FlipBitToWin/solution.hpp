/**
 * Copyright
 * You have an integer and you can flip exactly one bit from a 0 to a 1. Write
 * code to find the length of the longest sequence of 1s you could create.
 *
 * Input: 11011101111
 * Output: 8
 */

#ifndef CRACKING_5_3_FLIPBITTOWIN_SOLUTION_HPP_
#define CRACKING_5_3_FLIPBITTOWIN_SOLUTION_HPP_

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
  constexpr size_t FlipBitToWin(uint32_t num) {
    size_t res{0};
    size_t last_size{0};
    size_t pos{0};
    bool first_zero{false};
    while (num > 0) {
      if ((num & 0x01) != 0x0) {
        ++last_size;
        res = std::max(last_size, res);
      } else if ((first_zero == false) && (last_size != 0)) {
        first_zero = true;
        ++last_size;
        res = std::max(last_size, res);
      } else {
        first_zero = false;
        last_size = 0;
      }
      num >>= 1;
      ++pos;
    }
    if ((pos < 32) && (first_zero == false)) {
      ++last_size;
      res = std::max(last_size, res);
    }
    return res;
  }
};

#endif  // CRACKING_5_3_FLIPBITTOWIN_SOLUTION_HPP_
