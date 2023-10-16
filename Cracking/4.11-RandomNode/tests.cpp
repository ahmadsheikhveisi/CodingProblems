/**
 * Copyright
 */

#include <chrono>  //NOLINT

#include "gtest/gtest.h"

#include "solution.hpp"

template <typename T>
void GetRandomNodeMore(std::reference_wrapper<T> ref_uut) {
  constexpr size_t kRepition{1000};
  auto& uut = ref_uut.get();
  std::vector<size_t> num_chosen(uut.BinaryTreeSize(), 0);

  auto start = std::chrono::high_resolution_clock::now();

  for (size_t cnt{0}; cnt < (uut.BinaryTreeSize() * kRepition); ++cnt) {
    auto random_node = uut.GetRandomNode();
    ++num_chosen[random_node->value_];
  }

  auto stop = std::chrono::high_resolution_clock::now();

  for (auto const mem : num_chosen) {
    std::cout << mem << ' ';
  }
  std::cout << '\n';

  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Time taken by function: " << duration.count()
            << " microseconds\n";
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

TEST(CheckSubTree, test3) {
  [[maybe_unused]] SolutionLogNOpt<int> uut { 3 };
  uut.Insert(1);
  uut.Insert(5);
  uut.Insert(0);
  uut.Insert(2);
  uut.Insert(4);
  uut.Insert(6);

  GetRandomNodeMore<SolutionLogNOpt<int>>(uut);
}
