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

  uut.FindSuccessor(uut.tree_.root_);
}
