/**
 * Copyright
 * Given a binary tree, design an algorithm which creates a linked list of all
 * the nodes at each depth. if you have a tree with depth D, you'll have D
 * linked lists.
 */

#ifndef CRACKING_4_3_LISTOFDEPTH_SOLUTION_HPP_
#define CRACKING_4_3_LISTOFDEPTH_SOLUTION_HPP_

#include <memory>
#include <vector>

#include "binary_tree.hpp"
#include "singly_linked_list.hpp"

template <typename T>
class Solution {
 public:
  using Node = typename BinaryTree<T>::Node;

  LinkedList<std::shared_ptr<Node>> ListOfDepths(BinaryTree<T> const& tree) {
    return LinkedList<std::shared_ptr<Node>>{tree.root_};
  }
};

#endif  // CRACKING_4_3_LISTOFDEPTH_SOLUTION_HPP_
