/**
 * Copyright
 * You are implementing a binary tree class from scratch which, in addition to
 * insert, find, delete, has a method GetRandomNode() which returns a random
 * node from the tree. All nodes should be equally likely to be chosen. Design
 * and implement an algorithm for GetRandomNode, and explain how you would
 * implement the rest of the methods.
 */

#ifndef CRACKING_4_11_RANDOMNODE_SOLUTION_HPP_
#define CRACKING_4_11_RANDOMNODE_SOLUTION_HPP_

#include <algorithm>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "binary_tree.hpp"

template <typename T>
class Solution {
 public:
  using NodePtr = std::shared_ptr<typename BinaryTree<T>::Node>;
};

#endif  // CRACKING_4_11_RANDOMNODE_SOLUTION_HPP_
