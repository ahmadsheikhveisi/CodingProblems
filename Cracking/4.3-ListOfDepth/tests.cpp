/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(MinimalHeightBSTTest, CreateBST) {
  Solution<int> uut{};
  BinaryTree<int> tree{5};
  tree.root_->SetLeft(10);
  tree.root_->SetRight(15);
  tree.root_->left_->SetLeft(20);
  tree.root_->left_->SetRight(25);
  tree.root_->left_->right_->SetRight(45);
  tree.root_->right_->SetLeft(30);
  tree.root_->right_->SetRight(35);
  auto heights = uut.ListOfHeigths(tree);
  std::cout << "Heights\n";
  for (auto const& itm : heights) {
    std::cout << itm.first->value_ << ' ' << itm.second << '\n';
  }
  auto depths = uut.ListOfDepths(tree);
  std::cout << "Depths\n";
  for (auto const& itm : depths) {
    std::cout << itm.first->value_ << ' ' << itm.second << '\n';
  }
}
