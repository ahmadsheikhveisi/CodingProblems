/**
 * Copyright
 */

#ifndef BINARYTREE_TRIES_HPP_
#define BINARYTREE_TRIES_HPP_

#include <memory>
#include <string_view>
#include <unordered_map>

class Tries {
 public:
  class Node {
   public:
    std::unordered_map<char, std::shared_ptr<Node>> node_map{};
    bool terminal_{};
  };
  Tries() : root{std::make_shared<Node>()} {}

  void Insert(std::string_view str) {
    auto node = root;
    for (auto chr : str) {
      auto it = node->node_map.find(chr);
      if (it == end(node->node_map)) {
        node->node_map[chr] = std::make_shared<Node>();
      }
      node = node->node_map[chr];
    }
    node->terminal_ = true;
  }

  bool Search(std::string_view str) {
    auto node = root;
    for (auto chr : str) {
      auto it = node->node_map.find(chr);
      if (it == end(node->node_map)) {
        return false;
      }
      node = node->node_map[chr];
    }
    return node->terminal_;
  }

  bool StartWith(std::string_view prefix) {
    auto node = root;
    for (auto chr : prefix) {
      auto it = node->node_map.find(chr);
      if (it == end(node->node_map)) {
        return false;
      }
      node = it->second;
    }
    return true;
  }

  std::shared_ptr<Node> root{};
};

#endif  // BINARYTREE_TRIES_HPP_
