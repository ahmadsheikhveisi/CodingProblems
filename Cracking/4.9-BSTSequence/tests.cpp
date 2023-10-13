/**
 * Copyright
 * we need to add operator == to bt
 * it should go to all the nodes, comparing the nodes.
 */

#include "gtest/gtest.h"

#include "solution.hpp"

template <typename T, typename U>
BinarySearchTree<T> BuildBinarySearchTree(U const& vec) {
  if (vec.size() < 1) {
    std::cout << "can't build bst\n";
    return BinarySearchTree<T>{T{}};
  }
  BinarySearchTree<T> res{vec.front()};
  for (auto const& elm : vec) {
    res.Insert(elm);
  }
  return res;
}

TEST(BSTSequence, test1) {
  [[maybe_unused]] Solution<int> uut {};
  [[maybe_unused]] BinarySearchTree<int> bst { 2 };
  bst.Insert(1);
  bst.Insert(3);
  auto all_arrays = uut.FindAllArrays(bst);
  EXPECT_EQ(all_arrays.size(), 2);
  for (auto const& vec : all_arrays) {
    auto res = BuildBinarySearchTree<int>(vec);
    EXPECT_TRUE(bst == res);
    EXPECT_TRUE(res == bst);
  }
}

TEST(BSTSequence, test2) {
  [[maybe_unused]] Solution<int> uut {};
  BinarySearchTree<int> bst{5};
  bst.Insert(7);
  bst.Insert(3);
  bst.Insert(2);
  bst.Insert(4);
  bst.Insert(6);
  bst.Insert(8);
  auto all_arrays = uut.FindAllArrays(bst);
  EXPECT_EQ(all_arrays.size(), 80);
  for (auto const& vec : all_arrays) {
    auto res = BuildBinarySearchTree<int>(vec);
    EXPECT_TRUE(bst == res);
    EXPECT_TRUE(res == bst);
  }
}

TEST(BSTSequence, test3) {
  [[maybe_unused]] Solution<int> uut {};
  BinarySearchTree<int> bst{10};
  bst.Insert(5);
  bst.Insert(20);
  bst.Insert(2);
  bst.Insert(4);
  bst.Insert(30);
  auto all_arrays = uut.FindAllArrays(bst);
  EXPECT_EQ(all_arrays.size(), 10);
  for (auto const& vec : all_arrays) {
    auto res = BuildBinarySearchTree<int>(vec);
    for (auto elm : vec) {
      std::cout << elm << ' ';
    }
    std::cout << '\n';
    EXPECT_TRUE(bst == res);
    EXPECT_TRUE(res == bst);
  }
}
