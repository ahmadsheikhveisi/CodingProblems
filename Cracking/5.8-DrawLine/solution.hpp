/**
 * Copyright
 * A monochrome screen is stored as a single array of bytes, allowing eight
 * consecutive pixels to stored in one byte. The screen has width w, where w is
 * divisible by 8 (that is, no byte will be split across rows). The height of
 * the screen, of course, can be derived fron the length of the array and the
 * width. Implement a function that draws a horizontal line from (x1, y) to (x2,
 * y). The method signature should look something like:
 * DrawLine(byte[] screen, int width, int x1, int x2, int y)
 */

#ifndef CRACKING_5_8_DRAWLINE_SOLUTION_HPP_
#define CRACKING_5_8_DRAWLINE_SOLUTION_HPP_

#include <algorithm>
#include <cstddef>
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
  void DrawLine(std::reference_wrapper<std::vector<uint8_t>> rscreen,
                size_t width, size_t x1, size_t x2, size_t y) {
    if ((x1 >= width) || (x2 >= width) || (x1 > x2)) {
      return;
    }
    auto& screen = rscreen.get();
    size_t height{screen.size() / (width / 8)};
    if (y >= height) {
      return;
    }
    size_t first_byte{((y * width) / 8) + x1 / 8};
    size_t last_byte{((y * width) / 8) + x2 / 8};
    if (first_byte != last_byte) {
      screen[first_byte] = SetBitRange(screen[first_byte], x1 % 8, 7);
      screen[last_byte] = SetBitRange(screen[last_byte], 0, x2 % 8);
      for (size_t cnt{first_byte + 1}; cnt < last_byte; ++cnt) {
        screen[cnt] = 0xFF;
      }
    } else {
      screen[first_byte] = SetBitRange(screen[first_byte], x1 % 8, x2 % 8);
    }
  }
};

#endif  // CRACKING_5_8_DRAWLINE_SOLUTION_HPP_
