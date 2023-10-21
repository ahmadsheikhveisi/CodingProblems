/**
 * Copyright
 * Given a real number between 0 and 1 (e.g. 0.72) that is passed as a double,
 * print the binary representation, if the number cannot be represented
 * accurately in binary with at most 32 charactors, print "ERROR".
 */

#ifndef CRACKING_5_2_BINARYTOSTRING_SOLUTION_HPP_
#define CRACKING_5_2_BINARYTOSTRING_SOLUTION_HPP_

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
  std::string BinaryToString(double num) {
    if ((num >= 1) || (num <= 0)) {
      return "ERROR";
    }
    std::string res{};
    while (num > 0) {
      if (res.size() > 32) {
        res = "ERROR";
        break;
      }
      num *= 2;
      if (num >= 1) {
        res += "1";
        num -= 1;
      } else {
        res += "0";
      }
    }

    return res;
  }

  std::string BinaryToString2(double num) {
    if ((num >= 1) || (num <= 0)) {
      return "ERROR";
    }
    std::string res{};
    double cmp{0.5};
    while (num > 0) {
      if (res.size() > 32) {
        return "ERROR";
      }
      if (num >= cmp) {
        res += "1";
        num -= cmp;
      } else {
        res += "0";
      }
      cmp /= 2;
    }
    return res;
  }
};

#endif  // CRACKING_5_2_BINARYTOSTRING_SOLUTION_HPP_
