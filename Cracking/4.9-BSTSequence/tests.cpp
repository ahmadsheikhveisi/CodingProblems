/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(BSTSequence, test1) {
  [[maybe_unused]] Solution<int> uut {};
  [[maybe_unused]] BinarySearchTree<int> bst { 0 };
  for (auto const& vec : uut.FindAllArrays(bst)) {
    for (auto const& elm : vec) {
      std::cout << elm << ", ";
    }
    std::cout << '\n';
  }
}
