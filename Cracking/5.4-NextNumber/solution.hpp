/**
 * Copyright
 * Given a positive integer, print the next smallest and next largest number
 * that can have the same number of 1 bits in their binary representation.
 */

#ifndef CRACKING_5_4_NEXTNUMBER_SOLUTION_HPP_
#define CRACKING_5_4_NEXTNUMBER_SOLUTION_HPP_

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
  class Results {
   public:
    uint32_t next_smallest_{};
    uint32_t next_largest_{};
  };
  constexpr Results NextNumbers(uint32_t const num) {
    Results res{num, num};
    bool set_largest{false};
    // find the first one after some zeros
    uint32_t mask{static_cast<uint32_t>(1)};
    size_t pos{0};
    // find the first zero
    while (((num & mask) != 0) && (mask != 0)) {
      mask <<= 1;
      ++pos;
    }
    if ((pos != 0) && (pos < (sizeof(uint32_t) * 8)) &&
        ((num & (mask >> 1)) != 0)) {
      // this means the last bit is 1.
      // this is the last one before some 0s
      // and ones started from pos=0
      set_largest = true;
      res.next_largest_ = ClearBit(num, pos - 1);
      res.next_largest_ = SetBit(res.next_largest_, pos);
    }
    size_t first_ones_count{pos};
    // find the first one
    while (((num & mask) == 0) && (mask != 0)) {
      mask <<= 1;
      ++pos;
    }
    if (pos < (sizeof(uint32_t) * 8)) {
      res.next_smallest_ = ClearBitRange(num, 0, pos);
      res.next_smallest_ = SetBit(res.next_smallest_, pos - 1);
      res.next_smallest_ =
          SetBitRange(res.next_smallest_, pos - first_ones_count - 1, pos - 1);
    }
    if (set_largest == false) {
      // find the last one before some 0s
      // and since the largest is not set
      // we know that num started with 1s.
      auto first_pos = pos;
      while (((num & mask) != 0) && (mask != 0)) {
        mask <<= 1;
        ++pos;
      }
      if (pos < (sizeof(uint32_t) * 8)) {
        res.next_largest_ = SetBit(num, pos);
        res.next_largest_ = ClearBitRange(res.next_largest_, 0, pos - 1);
        res.next_largest_ =
            SetBitRange(res.next_largest_, 0, pos - first_pos - 2);
      }
    }
    return res;
  }

  constexpr uint32_t GetNextNumberArth(uint32_t num) {
    uint32_t mask{1};
    size_t count_zeros{0};
    while (((num & mask) == 0) && (count_zeros < (sizeof(uint32_t) * 8))) {
      mask <<= 1;
      ++count_zeros;
    }
    size_t count_ones{0};
    while (((num & mask) != 0) &&
           ((count_zeros + count_ones) < (sizeof(uint32_t) * 8))) {
      mask <<= 1;
      ++count_ones;
    }
    // this will overflow
    // num + (static_cast<uint32_t>(1) << count_zeros) +
    //       (static_cast<uint32_t>(1) << (count_ones - 1)) - 1;
    auto c0power2 = static_cast<uint32_t>(1) << count_zeros;
    uint32_t c1minus1power2{0};
    if (count_ones > 0) {
      c1minus1power2 = static_cast<uint32_t>(1) << (count_ones - 1);
    }
    if (((~(static_cast<uint32_t>(0))) - c0power2) < c1minus1power2) {
      return num;
    }
    if (((~(static_cast<uint32_t>(0))) - c0power2 - c1minus1power2) < num) {
      return num;
    }
    return num + c0power2 + c1minus1power2 - 1;
  }

  constexpr uint32_t GetPrevNumberArth(uint32_t num) {
    uint32_t mask{1};
    size_t count_ones{0};
    while (((num & mask) != 0) && (count_ones < (sizeof(uint32_t) * 8))) {
      mask <<= 1;
      ++count_ones;
    }
    size_t count_zeros{0};
    while (((num & mask) == 0) &&
           ((count_zeros + count_ones) < (sizeof(uint32_t) * 8))) {
      mask <<= 1;
      ++count_zeros;
    }
    uint32_t c0minus1power2{0};
    if (count_zeros > 0) {
      c0minus1power2 = static_cast<uint32_t>(1) << (count_zeros - 1);
    }
    auto c1power2 = static_cast<uint32_t>(1) << count_ones;
    if (((~(static_cast<uint32_t>(0))) - c0minus1power2) < c1power2) {
      return num;
    }
    if ((c0minus1power2 + c1power2) > num) {
      return num;
    }
    return num - c0minus1power2 - c1power2 + 1;
  }
};

#endif  // CRACKING_5_4_NEXTNUMBER_SOLUTION_HPP_
