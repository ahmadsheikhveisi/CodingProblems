/**
 * Copyright
 * Design an algorithm and write code to find the first common ancestor of two
 * nodes in a binary tree. Avoid storign additional nodes in a data structure.
 * NOTE: this is not a binary search tree.
 */

#ifndef CRACKING_4_8_FIRSTCOMMONANCESTOR_SOLUTION_HPP_
#define CRACKING_4_8_FIRSTCOMMONANCESTOR_SOLUTION_HPP_

#include <algorithm>
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
  NodePtr FindFirstCommonAncestor([[maybe_unused]] BinaryTree<T> bt,
                                  [[maybe_unused]] NodePtr node1,
                                  [[maybe_unused]] NodePtr node2) {
    if (node1 == node2) {
      return node1;
    }
    bool found1{false};
    bool found2{false};
    NodePtr res{nullptr};
    FindFirstCommonAncestorRec(bt.root_, found1, found2, node1, node2, res);
    return res;
  }

 private:
  bool FindFirstCommonAncestorRec(NodePtr node,
                                  std::reference_wrapper<bool> rfound1,
                                  std::reference_wrapper<bool> rfound2,
                                  NodePtr node1, NodePtr node2,
                                  std::reference_wrapper<NodePtr> rres) {
    auto& found1 = rfound1.get();
    auto& found2 = rfound2.get();
    auto& res = rres.get();
    if (node == nullptr) {
      return false;
    }
    auto right_res = FindFirstCommonAncestorRec(node->right_, found1, found2,
                                                node1, node2, res);
    auto left_res = FindFirstCommonAncestorRec(node->left_, found1, found2,
                                               node1, node2, res);
    if (right_res && left_res) {
      if (found1 == false) {
        found1 = true;
        res = node;
      }
      return true;
    }
    if ((node == node1) || (node == node2)) {
      if (right_res || left_res) {
        found2 = true;
      }
      return true;
    }
    if ((found2 == true) && (right_res || left_res)) {
      if (found1 == false) {
        found1 = true;
        res = node;
      }
    }
    return right_res || left_res;
  }
};

#endif  // CRACKING_4_8_FIRSTCOMMONANCESTOR_SOLUTION_HPP_
