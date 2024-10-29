/* COPYRIGHT
 * Write an algorithm such that if an element in an MxN matrix
 * is 0, its entire row and column are set to 0.
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
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

template <typename T>
void printMatrix(Matrix<T> const& mat) {
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

template <typename T>
void ZeroMatrix(Matrix<T>* pmat) {
  if (pmat == nullptr || pmat->size() == 0) {
    return;
  }
  auto& mat = *pmat;
  auto len = mat.size();
  auto wid = mat[0].size();
  std::unordered_set<size_t> zero_row;
  std::unordered_set<size_t> zero_col;
  for (size_t rcnt{0}; rcnt < len; ++rcnt) {
    for (size_t ccnt{0}; ccnt < wid; ++ccnt) {
      if (mat[rcnt][ccnt] == 0) {
        zero_row.insert(rcnt);
        zero_col.insert(ccnt);
      }
    }
  }

  for (auto row : zero_row) {
    for (size_t cnt{0}; cnt < wid; ++cnt) {
      mat[row][cnt] = 0;
    }
  }
  for (auto col : zero_col) {
    for (size_t cnt{0}; cnt < len; ++cnt) {
      mat[cnt][col] = 0;
    }
  }
}

template <typename T>
void ZeroMatrixO1Space(Matrix<T>* pmat) {
  if (pmat == nullptr || pmat->size() == 0) {
    return;
  }
  auto& mat = *pmat;
  auto len = mat.size();
  auto wid = mat[0].size();
  bool first_row_zero{false};
  bool first_col_zero{false};
  for (size_t cnt{0}; cnt < wid; ++cnt) {
    if (mat[0][cnt] == 0) {
      first_row_zero = true;
      break;
    }
  }
  for (size_t cnt{0}; cnt < len; ++cnt) {
    if (mat[cnt][0] == 0) {
      first_col_zero = true;
      break;
    }
  }
  for (size_t rcnt{1}; rcnt < len; ++rcnt) {
    for (size_t ccnt{1}; ccnt < wid; ++ccnt) {
      if (mat[rcnt][ccnt] == 0) {
        mat[0][ccnt] = 0;
        mat[rcnt][0] = 0;
      }
    }
  }
  for (size_t ccnt{1}; ccnt < wid; ++ccnt) {
    if (mat[0][ccnt] == 0) {
      for (size_t rcnt{1}; rcnt < len; ++rcnt) {
        mat[rcnt][ccnt] = 0;
      }
    }
  }
  for (size_t rcnt{1}; rcnt < len; ++rcnt) {
    if (mat[rcnt][0] == 0) {
      for (size_t ccnt{1}; ccnt < wid; ++ccnt) {
        mat[rcnt][ccnt] = 0;
      }
    }
  }

  if (first_row_zero) {
    for (size_t cnt{0}; cnt < wid; ++cnt) {
      mat[0][cnt] = 0;
    }
  }

  if (first_col_zero) {
    for (size_t cnt{0}; cnt < len; ++cnt) {
      mat[cnt][0] = 0;
    }
  }
}

int main() {
  std::vector<std::vector<uint32_t>> testlist{{1, 2, 3, 0, 5},
                                              {6, 7, 8, 9, 10},
                                              {11, 12, 13, 14, 15},
                                              {16, 0, 18, 19, 20},
                                              {21, 22, 23, 24, 25}};
  printMatrix(testlist);
  std::cout << '\n';
  ZeroMatrixO1Space(&testlist);
  printMatrix(testlist);
  return 0;
}
