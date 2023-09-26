/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(MinimalHeightBSTTest, CreateBST) {
  Solution<int> uut{{1, 2, 3, 4, 5, 6, 7, 8}};
  EXPECT_TRUE(uut.IsBinarySearchTree());
  uut.BreadthFirstSearch(uut.root_,
                         [](std::shared_ptr<Solution<int>::Node> node) {
                           std::cout << node->value_;
                           if (node->left_ != nullptr) {
                             std::cout << " l:" << node->left_->value_;
                           }
                           if (node->right_ != nullptr) {
                             std::cout << " r: " << node->right_->value_;
                           }
                           std::cout << '\n';
                           return true;
                         });
}
