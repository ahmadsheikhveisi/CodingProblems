/**
 * Copyright
 * T1 and T2 are two very large binary trees, with T1 much bigger than T2.
 * Create an algorithm to determine if T2 is a subtree of T1.
 * A tree T2 is a subtree of T1 if there exists a node n in T1 such that the
 * subtree of n is identical to T2. That is, if you cut off the tree at node n,
 * the two trees would be identical.
 */

#ifndef CRACKING_4_10_CHECKSUBTREE_SOLUTION_HPP_
#define CRACKING_4_10_CHECKSUBTREE_SOLUTION_HPP_

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

#endif  // CRACKING_4_10_CHECKSUBTREE_SOLUTION_HPP_
