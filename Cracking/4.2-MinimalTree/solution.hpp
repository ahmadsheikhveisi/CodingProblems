/**
 * Copyright
 * Given a sorted (increasing order) array with unique integer elements, write
 * an algorithm to create a binary search tree with minimal height.
 */

#ifndef CRACKING_4_2_MINIMALTREE_SOLUTION_HPP_
#define CRACKING_4_2_MINIMALTREE_SOLUTION_HPP_

#include "binary_search_tree.hpp"

template<typename T>
class Solution : public BinarySearchTree<T> {
    explicit Solution(T value) : BinarySearchTree<T>{value} {}

};

#endif  // CRACKING_4_2_MINIMALTREE_SOLUTION_HPP_
