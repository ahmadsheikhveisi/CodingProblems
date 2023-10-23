/**
 * Copyright
 * Explain what (n & (n - 1)) does.
 */

#ifndef CRACKING_5_5_DEBUGGER_SOLUTION_HPP_
#define CRACKING_5_5_DEBUGGER_SOLUTION_HPP_

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
  // This method set the first '1' bit from the right to zero.
  constexpr int32_t Debugger(int32_t num) { return (num & (num - 1)); }
  // This method checks if num is power of two. meaning it has only one '1'
  constexpr bool Check(int32_t num) { return (num & (num - 1)) == 0; }
};

#endif  // CRACKING_5_5_DEBUGGER_SOLUTION_HPP_
