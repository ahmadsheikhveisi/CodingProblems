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

template <typename T>
class Solution {
 public:
  using NodePtr = std::shared_ptr<typename BinaryTree<T>::Node>;
};

#endif  // CRACKING_4_12_PATHWITHSUM_SOLUTION_HPP_
