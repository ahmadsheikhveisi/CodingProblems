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
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "binary_search_tree.hpp"
#include "binary_tree.hpp"

template <typename T>
T GetRandomValue(T max_val) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<size_t> dis(0, max_val - 1);

  return dis(gen);
}

template <typename T>
class Solution : public BinaryTree<T> {
 public:
  using NodePtr = std::shared_ptr<typename BinaryTree<T>::Node>;
  template <typename U>
  explicit Solution(U&& val)
      : BinaryTree<T>(std::forward<U>(val)), bt_size_{1} {}

  template <typename U>
  void SetLeftWithCount(NodePtr node, U&& val) {
    node->SetLeft(std::forward<U>(val));
    ++bt_size_;
  }

  template <typename U>
  void SetRigthWithCount(NodePtr node, U&& val) {
    node->SetRight(std::forward<U>(val));
    ++bt_size_;
  }

  NodePtr GetRandomNode() {
    auto const random_node_num = GetRandomValue(bt_size_);
    size_t cnt{0};
    NodePtr res{nullptr};
    auto lambda = [&cnt, &random_node_num, &res](NodePtr node) {
      if (cnt == random_node_num) {
        res = node;
        return false;
      }
      ++cnt;
      return true;
    };

    BinaryTree<T>::BreadthFirstSearch(BinaryTree<T>::root_, lambda);

    return res;
  }

  size_t BinaryTreeSize() const { return bt_size_; }

  size_t bt_size_;
};

template <typename T>
class SolutionLogN : public BinarySearchTree<T> {
 public:
  using NodePtr = std::shared_ptr<typename BinarySearchTree<T>::Node>;
  template <typename U>
  explicit SolutionLogN(U&& val) : BinarySearchTree<T>(std::forward<U>(val)) {}
  NodePtr GetRandomNode() {
    return GetRandomNodeRec(BinarySearchTree<T>::root_);
  }

  size_t BinaryTreeSize() const {
    return BinarySearchTree<T>::root_->sub_tree_size;
  }

 private:
  NodePtr GetRandomNodeRec(NodePtr node) {
    auto const left_size =
        (node->left_ == nullptr) ? 0 : node->left_->sub_tree_size;
    auto const random_num = GetRandomValue(node->sub_tree_size);
    if (random_num < left_size) {
      return GetRandomNodeRec(node->left_);
    } else if (left_size == random_num) {
      return node;
    } else {
      return GetRandomNodeRec(node->right_);
    }
  }
};

#endif  // CRACKING_4_11_RANDOMNODE_SOLUTION_HPP_
