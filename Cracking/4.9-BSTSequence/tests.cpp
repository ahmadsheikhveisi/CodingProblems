/**
 * Copyright
 * we need to add operator == to bt
 * it should go to all the nodes, comparing the nodes.
 */

#include "gtest/gtest.h"

#include "solution.hpp"

template<typename T>
BinarySearchTree<T> BuildBinarySearchTree(std::vector<T> const& vec) {
  if (vec.size() < 1) {
    std::cout << "can't build bst\n";
    return BinarySearchTree<T>{T{}};
  }
  BinarySearchTree<T> res{vec[0]};
  for (size_t cnt{1}; cnt < vec.size(); ++cnt) {
    res.Insert(vec[cnt]);
  }
  return res;
}

TEST(BSTSequence, test1) {
  [[maybe_unused]] Solution<int> uut {};
  [[maybe_unused]] BinarySearchTree<int> bst { 2 };
  bst.Insert(1);
  bst.Insert(3);
  for (auto const& vec : uut.FindAllArrays(bst)) {
    EXPECT_TRUE(bst == BuildBinarySearchTree(vec));
  }
}

TEST(BSTSequence, test2) {
  [[maybe_unused]] Solution<int> uut {};
  BinarySearchTree<int> bst { 5 };
  bst.Insert(7);
  bst.Insert(3);
  bst.Insert(2);
  bst.Insert(4);
  bst.Insert(6);
  bst.Insert(8);
  for (auto const& vec : uut.FindAllArrays(bst)) {
    EXPECT_TRUE(bst == BuildBinarySearchTree(vec));
  }
}
