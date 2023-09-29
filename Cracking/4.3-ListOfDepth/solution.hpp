/**
 * Copyright
 * Given a binary tree, design an algorithm which creates a linked list of all
 * the nodes at each depth. if you have a tree with depth D, you'll have D
 * linked lists.
 * 
 * The depth of a node is the number of edges present in path from the root node of a tree to that node.
 * The height of a node is the number of edges present in the longest path connecting that node to a leaf node.
 */

#ifndef CRACKING_4_3_LISTOFDEPTH_SOLUTION_HPP_
#define CRACKING_4_3_LISTOFDEPTH_SOLUTION_HPP_

#include <unordered_map>
#include <memory>
#include <vector>

#include "binary_tree.hpp"
#include "singly_linked_list.hpp"

template <typename T>
class Solution {
 public:
  using Node = typename BinaryTree<T>::Node;

  std::unordered_map<std::shared_ptr<Node>, size_t> ListOfHeigths(BinaryTree<T> const& tree) {
    std::unordered_map<std::shared_ptr<Node>, size_t> list{};
    ListOfHeigthSubTree(tree.root_, list);
    return list;
  }

  std::unordered_map<std::shared_ptr<Node>, size_t> ListOfDepths(BinaryTree<T> const& tree) {
    std::unordered_map<std::shared_ptr<Node>, size_t> list{};
    ListOfDepthSubTree(tree.root_, 0, list);
    return list;
  }

private:
  size_t ListOfHeigthSubTree(std::shared_ptr<Node> node, std::unordered_map<std::shared_ptr<Node>, size_t>& list) {
    if (node == nullptr) {
      // this only happens when only one of the children is
      // null. so no need to store it.
      return 0;
    }
    if (node->left_ == nullptr && node->right_ == nullptr) {
      // this is a leaf.
      list[node] = 0;
      return 0;
    }
    auto depth = std::max(ListOfHeigthSubTree(node->left_, list), ListOfHeigthSubTree(node->right_, list)) + 1;
    list[node] = depth;
    return depth;
  }

  void ListOfDepthSubTree(std::shared_ptr<Node> node, size_t current_height, std::unordered_map<std::shared_ptr<Node>, size_t>& list) {
    if (node == nullptr) {
      // no need to store it.
      return;
    }
    list[node] = current_height;
    ListOfDepthSubTree(node->left_, current_height + 1, list);
    ListOfDepthSubTree(node->right_, current_height + 1, list);
  }
};

#endif  // CRACKING_4_3_LISTOFDEPTH_SOLUTION_HPP_
