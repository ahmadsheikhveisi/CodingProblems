/**
 * Copyright
 */

#ifndef BINARYTREE_TREE_HPP_
#define BINARYTREE_TREE_HPP_

#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <utility>
#include <vector>

template <typename T>
class Tree {
 public:
  class Node {
   public:
    explicit Node(T&& value) : value_{std::move(value)} {
      // std::cout << "move constructed\n";
    }
    explicit Node(T const& value) : value_{value} {
      // std::cout << "copy constructed\n";
    }
    template <typename S>
    void AddAChild(S&& value) {
      children_.emplace_back(Node{std::forward<S>(value)});
    }

    T value_;
    std::vector<Node> children_{};
  };

  explicit Tree(T&& value) : root_{std::move(value)} {};
  explicit Tree(T const& value) : root_{value} {};

  bool IsBinaryTree() {
    bool ret{true};
    BreadthFirstSearch(root_, [&ret](Node const& node) {
      ret = (node.children_.size() <= 2);
      return ret;
    });
    return ret;
  }

  using Operation = std::function<bool(Node const&)>;
  // level search
  void BreadthFirstSearch(Node const& node, Operation operation) {
    std::queue<std::reference_wrapper<Node const>> qu;
    qu.push(node);
    while (!qu.empty()) {
      auto nd = qu.front();
      qu.pop();
      if (!operation(nd)) {
        return;
      }
      for (auto const& child : nd.get().children_) {
        qu.push(child);
      }
    }
  }

  Node root_;
};

#endif  // BINARYTREE_TREE_HPP_
