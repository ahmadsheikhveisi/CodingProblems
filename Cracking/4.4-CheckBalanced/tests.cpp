/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "binary_tree.hpp"

TEST(CheckBalanced, CheckBalancedSuccess) {
  BinaryTree<int> tree{5};
  tree.root_->SetLeft(10);
  tree.root_->SetRight(15);
  tree.root_->left_->SetLeft(20);
  tree.root_->left_->SetRight(25);
  tree.root_->left_->right_->SetRight(45);
  tree.root_->right_->SetLeft(30);
  tree.root_->right_->SetRight(35);

  EXPECT_TRUE(tree.IsBalancedBinaryTreeAVL());
}
