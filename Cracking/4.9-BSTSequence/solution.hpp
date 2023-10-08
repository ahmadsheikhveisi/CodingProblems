/**
 * Copyright
 * A binary search tree was created by traversing through an array from left to
 * right and inserting each element. Given a binary search tree with distinct
 * elements, print all possible arrays that could have led to this tree.
 * input:
 *     2
 *    / \
 *   1   3
 * output:
 * {2,1,3}, {2,3,1}
 */

#ifndef CRACKING_4_9_BSTSEQUENCE_SOLUTION_HPP_
#define CRACKING_4_9_BSTSEQUENCE_SOLUTION_HPP_

#include <algorithm>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "binary_search_tree.hpp"

template <typename T>
class Solution {
 public:
  using NodePtr = std::shared_ptr<typename BinarySearchTree<T>::Node>;
  std::vector<std::vector<T>> FindAllArrays(
      [[maybe_unused]] BinarySearchTree<T> bst) {
    return {};
  }
};

#endif  // CRACKING_4_9_BSTSEQUENCE_SOLUTION_HPP_
