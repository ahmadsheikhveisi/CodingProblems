/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(FirstCommonAncestor, test1) {
  Solution<int> uut{};
  BinaryTree<int> bt{0};
  bt.root_->SetLeft(1);
  bt.root_->SetRight(2);
  bt.root_->left_->SetLeft(3);
  bt.root_->left_->SetRight(4);
  bt.root_->right_->SetLeft(5);
  bt.root_->right_->SetRight(6);
  bt.root_->left_->left_->SetLeft(7);
  bt.root_->left_->left_->SetRight(8);
  bt.root_->left_->right_->SetLeft(9);
  bt.root_->left_->right_->SetRight(10);
  bt.root_->right_->left_->SetLeft(11);
  bt.root_->right_->left_->SetRight(12);
  bt.root_->right_->right_->SetLeft(13);
  bt.root_->right_->right_->SetRight(14);
  auto res = uut.FindFirstCommonAncestor(bt, bt.root_->right_->right_,
                                         bt.root_->right_->left_->right_);

  EXPECT_EQ(res, bt.root_->right_);
}
