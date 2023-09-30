/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "binary_tree.hpp"

TEST(ValidateBST, ValidateBSTFail) {
  BinaryTree<int> tree{5};
  tree.root_->SetLeft(10);
  tree.root_->SetRight(15);
  tree.root_->left_->SetLeft(20);
  tree.root_->left_->SetRight(25);
  tree.root_->left_->right_->SetRight(45);
  tree.root_->right_->SetLeft(30);
  tree.root_->right_->SetRight(35);

  EXPECT_FALSE(tree.IsBinarySearchTree());
}

TEST(ValidateBST, ValidateBSTSuccess) {
  BinaryTree<int> tree{5};
  tree.root_->SetLeft(3);
  tree.root_->SetRight(7);
  tree.root_->left_->SetLeft(2);
  tree.root_->left_->SetRight(4);
  tree.root_->right_->SetLeft(6);
  tree.root_->right_->SetRight(8);
  tree.root_->right_->right_->SetRight(9);

  EXPECT_TRUE(tree.IsBinarySearchTree());
}

TEST(ValidateBST, ValidateBSTFaild2) {
  BinaryTree<int> tree{20};
  tree.root_->SetLeft(10);
  tree.root_->SetRight(30);
  tree.root_->left_->SetRight(25);

  EXPECT_FALSE(tree.IsBinarySearchTree());
}

TEST(ValidateBST, ValidateBSTSuccess2) {
  BinaryTree<int> tree{20};
  tree.root_->SetLeft(10);
  tree.root_->SetRight(30);
  tree.root_->left_->SetLeft(5);
  tree.root_->left_->SetRight(15);
  tree.root_->left_->left_->SetLeft(3);
  tree.root_->left_->left_->SetRight(7);
  tree.root_->left_->right_->SetRight(17);

  EXPECT_TRUE(tree.IsBinarySearchTree());
}
