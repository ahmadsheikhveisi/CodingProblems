/**
 * Copyright
*/

#ifndef BINARYTREE_BINARY_SEARCH_TREE_HPP_
#define BINARYTREE_BINARY_SEARCH_TREE_HPP_

#include "binary_tree.hpp"

template<typename T>
class BinarySearcyTree : public BinaryTree {
 public:
    explicit BinarySearcyTree(T const& value) : BinaryTree{value} {}
    explicit BinarySearcyTree(T&& value) : BinaryTree{std::move(value)} {}

    template<typename U>
    void Insert(U&& value) {

    }
};

#endif  // BINARYTREE_BINARY_SEARCH_TREE_HPP_
