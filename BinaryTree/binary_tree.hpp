/**
 * Copyright
 */

#ifndef BINARYTREE_BINARY_TREE_HPP_
#define BINARYTREE_BINARY_TREE_HPP_

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <tuple>
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

  explicit BinaryTree(T const& value) : root_{std::make_shared<Node>(value)} {}
  explicit BinaryTree(T&& value)
      : root_{std::make_shared<Node>(std::move(value))} {}
  std::shared_ptr<Node> root_{};

  using Visit = std::function<bool(std::shared_ptr<Node>)>;
  // https://www.geeksforgeeks.org/introduction-to-binary-tree-data-structure-and-algorithm-tutorials/
  void BreadthFirstSearch(std::shared_ptr<Node> node, Visit const& operation) {
    std::queue<std::shared_ptr<Node>> qu;
    qu.push(node);
    while (!qu.empty()) {
      auto nd = qu.front();
      qu.pop();
      if (!operation(nd)) {
        return;
      }
      if (nd->left_ != nullptr) {
        qu.push(nd->left_);
      }
      if (nd->right_ != nullptr) {
        qu.push(nd->right_);
      }
    }
  }

  bool PreOrderSearch(std::shared_ptr<Node> node, Visit const& operation) {
    if (!operation(node)) {
      return false;
    }
    if (node->left_ != nullptr) {
      if (!PreOrderSearch(node->left_, operation)) {
        return false;
      }
    }
    if (node->right_ != nullptr) {
      if (!PreOrderSearch(node->right_, operation)) {
        return false;
      }
    }
    return true;
  }
  // most common
  bool InOrderSearch(std::shared_ptr<Node> node, Visit const& operation) {
    if (node != nullptr) {
      if (!InOrderSearch(node->left_, operation)) {
        return false;
      }
    }
    if (!operation(node)) {
      return false;
    }
    if (node != nullptr) {
      if (!InOrderSearch(node->right_, operation)) {
        return false;
      }
    }
    return true;
  }

  bool PostOrderSearch(std::shared_ptr<Node> node, Visit const& operation) {
    if (node != nullptr) {
      if (!PostOrderSearch(node->left_, operation)) {
        return false;
      }
    }
    if (node != nullptr) {
      if (!PostOrderSearch(node->right_, operation)) {
        return false;
      }
    }
    if (!operation(node)) {
      return false;
    }
    return true;
  }
  // https://www.geeksforgeeks.org/types-of-binary-tree/
  bool IsCompleteBinaryTree() {
    // All levels are completely filled except
    // the last level and the last level has the left children
    // a complete binary tree doesn’t have to be a full binary tree.
    // Using Breadth First Search, the last node is the queue is the
    // last node. so if we get any node that is not full before that
    // that tree is not complete.
    bool non_full_node_seen{false};
    bool ret{true};
    BreadthFirstSearch(root_,
                       [&non_full_node_seen, &ret](std::shared_ptr<Node> node) {
                         if (node->left_ != nullptr) {
                           if (non_full_node_seen) {
                             ret = false;
                           }
                         } else {
                           non_full_node_seen = true;
                         }

                         if (ret && (node->right_ != nullptr)) {
                           if (non_full_node_seen) {
                             ret = false;
                           }
                         } else {
                           non_full_node_seen = true;
                         }
                         return ret;
                       });
    return ret;
  }
  // this is wrong
  /*std::tuple<std::shared_ptr<Node>, std::shared_ptr<Node>, bool>
  IsBinarySearchSubTree(std::shared_ptr<Node> root) {
    auto left = root->left_;
    auto right = root->right_;

    if ((left == nullptr) && (right == nullptr)) {
      return {root, root, true};
    } else if ((left == nullptr) && (right != nullptr)) {
      if (right->value_ > root->value_) {
        return {root, right, true};
      } else {
        return {root, right, false};
      }
    } else if ((right == nullptr) && (left != nullptr)) {
      if (left->value_ < root->value_) {
        return {left, root, true};
      } else {
        return {left, root, false};
      }
    }
    // if we get here, none of the child nodes are null
    auto [left_smallest, left_biggest, left_result] =
        IsBinarySearchSubTree(left);
    auto [right_smallest, right_biggest, right_result] =
        IsBinarySearchSubTree(right);

    if (!left_result || !right_result) {
      return {left, right, false};
    }

    if (!((left_biggest->value_ <= root->value_) &&
          (right_smallest->value_ > root->value_))) {
      return {left, right, false};
    }

    if (!(left_smallest->value_ < right_biggest->value_)) {
      return {left, right, false};
    }

    return {left_biggest, right_smallest, true};
  }*/
  bool IsBinarySearchSubTree(std::shared_ptr<Node> node,
                             std::optional<T> min = std::nullopt,
                             std::optional<T> max = std::nullopt) {
    if (node == nullptr) {
      return true;
    }

    if (min.has_value()) {
      if (node->value_ <= min.value()) {
        return false;
      }
    }
    if (max.has_value()) {
      if (node->value_ >= max.value()) {
        return false;
      }
    }
    return IsBinarySearchSubTree(node->left_, min, node->value_) &&
           IsBinarySearchSubTree(node->right_, node->value_, max);
  }

  bool IsBinarySearchTree() {
    // all left desendents <= n < all right desendents
    // The root of a BST is the node that has the largest value in the left
    // subtree and the smallest value in the right subtree
    // We can keep the counter with the node and if we found the duplicate
    // value, then we can increment the counter
    return IsBinarySearchSubTree(root_);
    /*auto [_, __, result] = IsBinarySearchSubTree(root_);
    (void)_;
    (void)__;
    return result;*/
  }

  std::tuple<bool, size_t> IsBalancedBinaryTreeAVLSubTree(
      std::shared_ptr<Node> node) {
    if (node == nullptr) {
      return {true, 0};
    }
    if ((node->left_ == nullptr) && (node->right_ == nullptr)) {
      return {true, 0};
    }
    auto [left_res, left_height] = IsBalancedBinaryTreeAVLSubTree(node->left_);
    auto [right_res, right_height] =
        IsBalancedBinaryTreeAVLSubTree(node->right_);
    auto height = std::max(left_height, right_height);
    auto diff_height = left_height > right_height ? left_height - right_height
                                                  : right_height - left_height;
    auto res = (left_res && right_res) && (diff_height < 1);
    return {res, height};
  }

  bool IsBalancedBinaryTreeAVL() {
    // the height of balaced tree is O(Log n) n:the number of nodes.
    /**
     * the AVL tree maintains O(Log n) height by making sure that the
     * difference between the heights of the left and right subtrees is at
     * most 1. Balanced Binary Search trees are performance-wise good as they
     * provide O(log n) time for search, insert and delete.
     */
    auto res = IsBalancedBinaryTreeAVLSubTree(root_);
    return std::get<bool>(res);
  }

  bool IsBalancedBinaryTreeRedBlack() {
    // the height of balaced tree is O(Log n) n:the number of nodes.
    /**
     * Red-Black trees maintain O(Log n) height by making
     * sure that the number of Black nodes on every root to leaf paths
     * is the same and that there are no adjacent red nodes. Balanced
     * Binary Search trees are performance-wise good as they provide
     * O(log n) time for search, insert and delete.
     */
    return false;
  }

  bool IsFullBinaryTree() {
    // A full binary tree in which every node has either zero or
    // two children. no node with only one child.
    bool ret{true};
    BreadthFirstSearch(root_, [&ret](std::shared_ptr<Node> node) {
      ret = (node != nullptr) &&
            ((node->left_ == nullptr) == (node->right_ == nullptr));
      return ret;
    });
    return ret;
  }

  bool IsPerfectBinaryTree() {
    // A perfect binary tree, is both full and complete.
    // In a Perfect Binary Tree, the number of leaf nodes
    // is the number of internal nodes plus 1.
    // A perfect binary tree has  2^(h+1) + 1 nodes. h is the hight.
    //
    return IsCompleteBinaryTree() && IsFullBinaryTree();
  }

  bool IsDegenrateTree() {
    // every node has only one child. like a list
    // also called pathological
    return false;
  }

  bool IsSkewedTree() {
    // tree is dominated by left nodes or right nodes.
    // there are two types of skewed binary trees:
    // left binary trees and right binary trees.
    return false;
  }

 private:
};

#endif  // BINARYTREE_BINARY_TREE_HPP_
