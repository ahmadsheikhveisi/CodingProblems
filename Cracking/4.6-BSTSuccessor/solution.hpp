/**
 * Copyright
 * Write an algorithm to find the "next" node (i.e. in-order successor) of a
 * given node in a binary search tree. you may assume that each node has a link
 * to its parent.
 */

#ifndef CRACKING_4_6_BSTSUCCESSOR_SOLUTION_HPP_
#define CRACKING_4_6_BSTSUCCESSOR_SOLUTION_HPP_

#include <algorithm>
#include <memory>
#include <utility>

#include "binary_search_tree.hpp"

template <typename T>
class Solution {
 public:
  class ValueType;
  using Node = typename BinarySearchTree<ValueType>::Node;
  class ValueType {
   public:
    explicit ValueType(std::shared_ptr<Node> parent, T value)
        : parent_{parent}, value_{value} {}
    std::shared_ptr<Node> parent_;
    T value_;
  };

  BinarySearchTree<ValueType> tree_;

  template <typename U>
  explicit Solution(U&& value)
      : tree_{ValueType{nullptr, std::forward<U>(value)}} {}

  std::shared_ptr<Node> FindSuccessor(std::shared_ptr<Node> node) {
    return node;
  }

  template <typename U>
  void InsertWithParentLink(U&& value) {
    InsertNodeWithParentLink(tree_.root_, std::forward<U>(value), nullptr);
  }

 private:
  template <typename U>
  void InsertNodeWithParentLink(
      std::reference_wrapper<std::shared_ptr<Node>> rnode, U&& value,
      std::shared_ptr<Node> parent) {
    auto& node = rnode.get();
    if (node == nullptr) {
      node = std::make_shared<Node>(ValueType{parent, std::forward<U>(value)});
      return;
    }
    if (node->value_.value_ == value) {
      // we can increment a counter.
      return;
    }
    if (node->value_.value_ > value) {
      InsertNodeWithParentLink(node->left_, std::forward<U>(value), node);
    } else {
      InsertNodeWithParentLink(node->right_, std::forward<U>(value), node);
    }
  }
};

#endif  // CRACKING_4_6_BSTSUCCESSOR_SOLUTION_HPP_
