/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(CheckSubTree, test1) {
  [[maybe_unused]] Solution<int> uut {};
  BinaryTree<int> bigger{1};
  bigger.root_->SetLeft(2);
  bigger.root_->left_->SetLeft(4);
  bigger.root_->left_->SetRight(5);

  bigger.root_->SetRight(3);
  bigger.root_->right_->SetRight(6);

  BinaryTree<int> smaller{2};
  smaller.root_->SetLeft(4);
  smaller.root_->SetRight(5);

  EXPECT_TRUE(uut.CheckSubTree(bigger.root_, smaller.root_));
  EXPECT_TRUE(uut.CheckSubTreeRec(bigger.root_, smaller.root_));

  BinaryTree<int> not_subtree{3};
  smaller.root_->SetLeft(7);
  smaller.root_->SetRight(6);

  EXPECT_FALSE(uut.CheckSubTree(bigger.root_, not_subtree.root_));
  EXPECT_FALSE(uut.CheckSubTreeRec(bigger.root_, not_subtree.root_));
}

TEST(CheckSubTree, test2) {
  [[maybe_unused]] Solution<int> uut {};
  BinaryTree<int> bigger{1};
  bigger.root_->SetLeft(2);
  bigger.root_->left_->SetLeft(4);
  bigger.root_->left_->left_->SetLeft(5);

  BinaryTree<int> smaller{2};
  smaller.root_->SetRight(4);
  smaller.root_->right_->SetRight(5);

  EXPECT_FALSE(uut.CheckSubTree(bigger.root_, smaller.root_));
  EXPECT_FALSE(uut.CheckSubTreeRec(bigger.root_, smaller.root_));
}
