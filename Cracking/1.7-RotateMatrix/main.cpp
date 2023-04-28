/* COPYRIGHT
 * Given an image represented by an NxN matrix, where each
 * pixel in the image is 4 bytes, write a method to rotate
 * the image by 90 degrees. do it in place.
 *
 * Note: case insensive, ignore white space.
 * Palindrome has an even occurance of all charactors, except
 * it can have only one odd occurance.
 * 00010000 - 1 = 00001111
 * 00101000 - 1 = 00100111
 *
 * count if: count the elements between two iterators that satisfy a
 * condition.
 *
 * string find returns the index and it can be npos
 *
 * Mind the end of string, when searching.
 *
 * A 90 degree rotation over the center, can be created by a mirror over
 * diag and a mirror over vertical axis
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using Matrix = std::vector<std::vector<std::uint32_t>>;

void printMatrix(Matrix const& mat) {
  for (const auto& row : mat) {
    for (auto pix : row) {
      std::cout << pix << ' ';
      if (pix / 10 == 0) {
        std::cout << ' ';
      }
    }
    std::cout << '\n';
  }
}

void RotateMatrix(Matrix* pmat) {
  if (pmat == nullptr || pmat->size() == 0 ||
      pmat->size() != pmat->at(0).size()) {
    return;
  }
  auto& mat = *pmat;
  for (size_t rcnt{0}; rcnt < mat.size(); ++rcnt) {
    for (size_t ccnt{rcnt + 1}; ccnt < mat[rcnt].size(); ++ccnt) {
      std::swap(mat[rcnt][ccnt], mat[ccnt][rcnt]);
    }
  }

  for (size_t rcnt{0}; rcnt < mat.size(); ++rcnt) {
    for (size_t ccnt{0}; ccnt < mat[rcnt].size() / 2; ++ccnt) {
      std::swap(mat[rcnt][ccnt], mat[rcnt][mat[rcnt].size() - ccnt - 1]);
    }
  }
}

void RotateMatrixLayer(Matrix* pmat) {
  if (pmat == nullptr || pmat->size() == 0 ||
      pmat->size() != pmat->at(0).size()) {
    return;
  }
  auto& mat = *pmat;
  auto size{mat.size()};
  for (size_t layer{0}; layer < size / 2; ++layer) {
    for (size_t ccnt{layer}; ccnt < size - 1 - layer; ++ccnt) {
      auto& top = mat[layer][ccnt];
      auto& left = mat[size - ccnt - 1][layer];
      auto& bottom = mat[size - layer - 1][size - ccnt - 1];
      auto& right = mat[ccnt][size - 1 - layer];

      auto temp = top;
      top = left;
      left = bottom;
      bottom = right;
      right = temp;
    }
  }
}

int main() {
  std::vector<std::vector<uint32_t>> testlist{{1, 2, 3, 4, 5},
                                              {6, 7, 8, 9, 10},
                                              {11, 12, 13, 14, 15},
                                              {16, 17, 18, 19, 20},
                                              {21, 22, 23, 24, 25}};
  printMatrix(testlist);
  std::cout << '\n';
  RotateMatrix(&testlist);
  printMatrix(testlist);
  std::cout << '\n';
  RotateMatrixLayer(&testlist);
  printMatrix(testlist);
  return 0;
}
