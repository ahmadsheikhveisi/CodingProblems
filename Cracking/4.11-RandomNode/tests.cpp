/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

template <typename T>
void GetRandomNodeMore(std::reference_wrapper<T> ref_uut) {
  auto& uut = ref_uut.get();
  std::vector<size_t> num_chosen(uut.BinaryTreeSize(), 0);

  for (size_t cnt{0}; cnt < (uut.BinaryTreeSize() * 1000); ++cnt) {
    auto random_node = uut.GetRandomNode();
    ++num_chosen[random_node->value_];
  }

  for (auto const mem : num_chosen) {
    std::cout << mem << ' ';
  }
  std::cout << '\n';
}

TEST(CheckSubTree, test1) {
  [[maybe_unused]] Solution<int> uut { 0 };
  uut.SetLeftWithCount(uut.root_, 1);
  uut.SetRigthWithCount(uut.root_, 2);

  uut.SetLeftWithCount(uut.root_->left_, 3);
  uut.SetRigthWithCount(uut.root_->left_, 4);

  uut.SetLeftWithCount(uut.root_->right_, 5);
  uut.SetRigthWithCount(uut.root_->right_, 6);

  GetRandomNodeMore<Solution<int>>(uut);
}

TEST(CheckSubTree, test2) {
  [[maybe_unused]] SolutionLogN<int> uut { 3 };
  uut.Insert(1);
  uut.Insert(5);
  uut.Insert(0);
  uut.Insert(2);
  uut.Insert(4);
  uut.Insert(6);

  GetRandomNodeMore<SolutionLogN<int>>(uut);
}
