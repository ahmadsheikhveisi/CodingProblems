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

  /**
   * this solution O(N+M) in time and space
   */
  bool CheckSubTree([[maybe_unused]] NodePtr node1,
                    [[maybe_unused]] NodePtr node2) {
    std::vector<std::optional<T>> vec1{};
    std::vector<std::optional<T>> vec2{};
    auto lambda =
        [](NodePtr node,
           std::reference_wrapper<std::vector<std::optional<T>>> rvec) {
          auto& vec = rvec.get();
          if (node == nullptr) {
            vec.push_back(std::nullopt);
          } else {
            vec.push_back(node->value_);
          }
          return true;
        };
    BinaryTreePreOrderSearchNode<T>(
        node1, [&vec1, &lambda](NodePtr node) { return lambda(node, vec1); });
    BinaryTreePreOrderSearchNode<T>(
        node2, [&vec2, &lambda](NodePtr node) { return lambda(node, vec2); });
    return CheckSubset(vec1, vec2);
  }

  bool CheckSubset(std::vector<std::optional<T>> const& bigger,
                   std::vector<std::optional<T>> const& smaller) {
    size_t bcnt{0};
    size_t scnt{0};
    while ((bcnt < bigger.size()) && (scnt < smaller.size())) {
      if (bigger[bcnt] == smaller[scnt]) {
        ++scnt;
      } else {
        scnt = 0;
      }
      ++bcnt;
    }
    return (scnt == smaller.size());
  }

  /**
   * this solution is O(log(N) + log(M)) in space.
   * and it takes O(N + kM) in time, k is the number
   * of occurances of the root of smaller tree in the
   * bigger tree.
   */
  bool CheckSubTreeRec(NodePtr node1, NodePtr node2) {
    if (node2 == nullptr) {
      return true;
    } else if (node1 == nullptr) {
      return false;
    } else if ((node1->value_ == node2->value_) &&
               CheckSubTreeRecHelper(node1, node2)) {
      return true;
    }
    return CheckSubTreeRec(node1->left_, node2) ||
           CheckSubTreeRec(node1->right_, node2);
  }

 private:
  bool CheckSubTreeRecHelper(NodePtr node1, NodePtr node2) {
    if ((node1 == nullptr) && (node2 == nullptr)) {
      return true;
    } else if ((node1 == nullptr) || (node2 == nullptr)) {
      return false;
    } else if (node1->value_ != node2->value_) {
      return false;
    }
    return CheckSubTreeRecHelper(node1->left_, node2->left_) &&
           CheckSubTreeRecHelper(node1->right_, node2->right_);
  }
};

#endif  // CRACKING_4_10_CHECKSUBTREE_SOLUTION_HPP_
