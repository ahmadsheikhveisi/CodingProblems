/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(CheckSubTree, test1) {
  [[maybe_unused]] Solution uut {};
  BinaryTree<int32_t> bt{0};
  bt.root_->SetLeft(1);
  bt.root_->SetRight(2);
  bt.root_->left_->SetLeft(3);
  bt.root_->left_->SetRight(4);
  bt.root_->right_->SetLeft(-3);
  bt.root_->right_->SetRight(-4);
  bt.root_->left_->left_->SetLeft(7);
  bt.root_->left_->left_->SetRight(8);
  bt.root_->left_->right_->SetLeft(9);
  bt.root_->left_->right_->SetRight(10);
  bt.root_->right_->left_->SetLeft(11);
  bt.root_->right_->left_->SetRight(12);
  bt.root_->right_->right_->SetLeft(13);
  bt.root_->right_->right_->SetRight(14);

  std::cout << uut.CountPathWithSum(bt.root_, 10) << '\n';
}

TEST(CheckSubTree, test2) {
  [[maybe_unused]] Solution uut {};
  BinaryTree<int32_t> bt{10};
  bt.root_->SetLeft(5);
  bt.root_->SetRight(-3);
  bt.root_->left_->SetLeft(3);
  bt.root_->left_->SetRight(1);
  bt.root_->right_->SetRight(11);
  bt.root_->left_->left_->SetLeft(3);
  bt.root_->left_->left_->SetRight(-2);
  bt.root_->left_->right_->SetRight(2);

  std::cout << uut.CountPathWithSum(bt.root_, 8) << '\n';
}
