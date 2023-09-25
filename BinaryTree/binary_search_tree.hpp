/**
 * Copyright
 */

#ifndef BINARYTREE_BINARY_SEARCH_TREE_HPP_
#define BINARYTREE_BINARY_SEARCH_TREE_HPP_

#include <memory>
#include <utility>

#include "binary_tree.hpp"

template <typename T>
class BinarySearcyTree : public BinaryTree<T> {
 public:
  using Node = typename BinaryTree<T>::Node;
  explicit BinarySearcyTree(T const& value) : BinaryTree<T>{value} {}
  explicit BinarySearcyTree(T&& value) : BinaryTree<T>{std::move(value)} {}

  template <typename U>
  void Insert(U&& value) {
    InsertNode(BinaryTree<T>::root_, std::forward<U>(value));
  }
  template <typename U>
  bool Search(U&& value) {
    return SearchNode(BinaryTree<T>::root_, std::forward<U>(value));
  }

 private:
  template <typename U>
  void InsertNode(std::reference_wrapper<std::shared_ptr<Node>> rnode,
                  U&& value) {
    auto& node = rnode.get();
    if (node == nullptr) {
      node = std::make_shared<Node>(std::forward<U>(value));
      return;
    }
    if (node->value_ == value) {
      // we can increment a counter.
      return;
    }
    if (node->value_ > value) {
      InsertNode(node->left_, std::forward<U>(value));
    } else {
      InsertNode(node->right_, std::forward<U>(value));
    }
  }
  template <typename U>
  bool SearchNode(std::shared_ptr<Node> node, U&& value) {
    if (node == nullptr) {
      return false;
    } else if (node->value_ == value) {
      return true;
    } else if (node->value_ > value) {
      return SearchNode(node->left_, std::forward<U>(value));
    } else {
      return SearchNode(node->right_, std::forward<U>(value));
    }
    return false;
  }
};

#endif  // BINARYTREE_BINARY_SEARCH_TREE_HPP_
