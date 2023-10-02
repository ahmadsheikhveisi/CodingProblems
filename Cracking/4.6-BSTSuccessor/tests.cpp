/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(BSTSuccessor, BSTSuccessorSuccess) {
  Solution<int> uut{5};
  uut.InsertWithParentLink(3);
  BinarySearchTree<int> tree{5};
  uut.InsertWithParentLink(3);
  uut.InsertWithParentLink(7);
  uut.InsertWithParentLink(2);
  uut.InsertWithParentLink(4);
  uut.InsertWithParentLink(6);
  uut.InsertWithParentLink(8);

  uut.tree_.InOrderSearch(
      uut.tree_.root_, [](std::shared_ptr<Solution<int>::Node> node) {
        if (node != nullptr) {
          std::cout << node->value_.value_;
          if (node->value_.parent_ != nullptr) {
            std::cout << ':' << node->value_.parent_->value_.value_;
          }
          std::cout << '\n';
        }
        return true;
      });

  EXPECT_EQ(uut.FindSuccessor(uut.tree_.root_), uut.tree_.root_->right_->left_);
  EXPECT_EQ(uut.FindSuccessor(uut.tree_.root_->left_), uut.tree_.root_->left_->right_);
  EXPECT_EQ(uut.FindSuccessor(uut.tree_.root_->left_->right_), uut.tree_.root_);
  EXPECT_EQ(uut.FindSuccessor(uut.tree_.root_->right_->right_), nullptr);
  EXPECT_EQ(uut.FindSuccessor(uut.tree_.root_->right_->left_), uut.tree_.root_->right_);
}
