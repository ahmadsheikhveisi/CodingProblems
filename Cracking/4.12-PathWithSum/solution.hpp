/**
 * Copyright
 * You are given a binary tree in which each node contains an integer value
 * (which might be positive or negative). Design an algorithm to count the
 * number of paths that sum to a given value. The path does not need to start or
 * end at the root or a leaf, but it must go downwards (taveling only from
 * parent to child nodes).
 */

#ifndef CRACKING_4_12_PATHWITHSUM_SOLUTION_HPP_
#define CRACKING_4_12_PATHWITHSUM_SOLUTION_HPP_

#include <algorithm>
#include <list>
#include <memory>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "binary_search_tree.hpp"
#include "binary_tree.hpp"

class Solution {
 public:
  using NodePtr = std::shared_ptr<BinaryTree<int32_t>::Node>;

  size_t CountPathWithSum(NodePtr node, int32_t sum) {
    if (node == nullptr) {
      return 0;
    }
    // std::cout << "Start form here " << node->value_ << ' ';
    auto const start_from_here = CountPathWithSumSubTree(node, sum);
    // std::cout << ' ' << start_from_here;
    auto const all_left = CountPathWithSum(node->left_, sum);
    // std::cout << " All left " << all_left;
    auto const all_right = CountPathWithSum(node->right_, sum);
    // std::cout << " All right " << all_right << '\n';
    size_t res{start_from_here + all_left + all_right};
    std::cout << node->value_ << ' ' << res << '\n';

    return res;
  }

  size_t CountPathWithSumSubTree(NodePtr node, int32_t sum) {
    if (node == nullptr) {
      return 0;
    }
    if (sum == node->value_) {
      return 1;
    }
    return CountPathWithSumSubTree(node->left_, sum - node->value_) +
           CountPathWithSumSubTree(node->right_, sum - node->value_);
  }
};

#endif  // CRACKING_4_12_PATHWITHSUM_SOLUTION_HPP_
