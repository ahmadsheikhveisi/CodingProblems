/**
 * Copyright
 * Given a sorted (increasing order) array with unique integer elements, write
 * an algorithm to create a binary search tree with minimal height.
 */

#ifndef CRACKING_4_2_MINIMALTREE_SOLUTION_HPP_
#define CRACKING_4_2_MINIMALTREE_SOLUTION_HPP_

#include <memory>
#include <vector>

#include "binary_search_tree.hpp"

template <typename T>
class Solution : public BinarySearchTree<T> {
 public:
  using Node = typename BinarySearchTree<T>::Node;
  explicit Solution(std::initializer_list<T> sorted_values)
      : BinarySearchTree<T>{T{}} {
    if ((sorted_values.size() > 0) &&
        std::is_sorted(begin(sorted_values), end(sorted_values))) {
      std::vector<bool> hash(sorted_values.size(), false);
      SetValues(sorted_values, 0, sorted_values.size() / 2,
                sorted_values.size(), hash, BinarySearchTree<T>::root_);
    }
  }

  void SetValues(std::initializer_list<T> values, size_t begin_index,
                 size_t current, size_t end_index,
                 std::reference_wrapper<std::vector<bool>> rhash,
                 std::shared_ptr<Node> node) {
    auto& hash = rhash.get();
    node->value_ = *std::next(values.begin(), current);
    hash[current] = true;
    auto left_index = (current + begin_index) / 2;
    auto right_index = (current + end_index) / 2;
    if (hash[left_index] == false) {
      node->SetLeft(T{});
      SetValues(values, begin_index, left_index, current, rhash, node->left_);
    }
    if (hash[right_index] == false) {
      node->SetRight(T{});
      SetValues(values, current, right_index, end_index, rhash, node->right_);
    }
  }
};

#endif  // CRACKING_4_2_MINIMALTREE_SOLUTION_HPP_
