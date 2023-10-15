/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(CheckSubTree, test1) {
  [[maybe_unused]] Solution<int> uut { 0 };
  uut.SetLeftWithCount(uut.root_, 1);
  uut.SetRigthWithCount(uut.root_, 2);

  uut.SetLeftWithCount(uut.root_->left_, 3);
  uut.SetRigthWithCount(uut.root_->left_, 4);

  uut.SetLeftWithCount(uut.root_->right_, 5);
  uut.SetRigthWithCount(uut.root_->right_, 6);

  std::vector<size_t> num_chosen(7, 0);

  for (size_t cnt{0}; cnt < 7000; ++cnt) {
    auto random_node = uut.GetRandomNode();
    ++num_chosen[random_node->value_];
  }

  for (auto const mem : num_chosen) {
    std::cout << mem << ' ';
  }
  std::cout << '\n';
}

TEST(CheckSubTree, test2) {
  [[maybe_unused]] Solution<int> uut { 4 };
}
