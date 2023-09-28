/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(MinimalHeightBSTTest, CreateBST) {
  Solution<int> uut{};
  auto temp = uut.ListOfDepths(BinaryTree<int>{0});

  std::cout << temp.front->data->value_ << '\n';
}
