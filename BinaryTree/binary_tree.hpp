/**
 * Copyright
 */

#ifndef BINARYTREE_BINARY_TREE_HPP_
#define BINARYTREE_BINARY_TREE_HPP_

#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <utility>
#include <vector>

template <typename T>
class BinaryTree {
 public:
  class Node {
   public:
    explicit Node(T const& value) : value_{value} {
      std::cout << "copy constructed\n";
    }
    explicit Node(T&& value) : value_{std::move(value)} {
      std::cout << "move constructed\n";
    };
    template <typename W>
    void SetLeft(W&& value) {
      left_ = std::make_shared<Node>(std::forward<W>(value));
    }
    template <typename W>
    void SetRight(W&& value) {
      right_ = std::make_shared<Node>(std::forward<W>(value));
    }
    std::shared_ptr<Node> left_;
    std::shared_ptr<Node> right_;
    T value_;
  };

  explicit BinaryTree(T const& value) : root_{value} {}
  explicit BinaryTree(T&& value) : root_{std::move(value)} {}
  Node root_;

  using Visit = std::function<bool(Node const&)>;
  // https://www.geeksforgeeks.org/introduction-to-binary-tree-data-structure-and-algorithm-tutorials/
  void BreadthFirstSearch(Node const& node, Visit const& operation) {
    std::queue<std::reference_wrapper<Node const>> qu;
    qu.push(node);
    while (!qu.empty()) {
      auto nd = qu.front();
      qu.pop();
    }
  }

 private:
};

#endif  // BINARYTREE_BINARY_TREE_HPP_
