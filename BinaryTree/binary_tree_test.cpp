/**
 * Copyright
 */

#include "gtest/gtest.h"

#include <iostream>     // NOLINT
#include <string_view>  // NOLINT

#include "binary_heap.hpp"
#include "binary_tree.hpp"
#include "tree.hpp"

TEST(TreeTest, IsBinaryTree) {
  Tree<std::string_view> uut{"Zero"};
  uut.root_.AddAChild("One");
  uut.root_.AddAChild("Two");
  uut.root_.children_[0].AddAChild("Three");
  uut.root_.children_[0].AddAChild("Four");
  uut.root_.children_[1].AddAChild("Five");
  uut.root_.children_[1].AddAChild("Six");
  EXPECT_TRUE(uut.IsBinaryTree());
}

TEST(TreeTest, IsNotBinaryTree) {
  Tree<std::string_view> uut{"Zero"};
  uut.root_.AddAChild("One");
  uut.root_.AddAChild("Two");
  uut.root_.children_[0].AddAChild("Three");
  uut.root_.children_[0].AddAChild("Four");
  uut.root_.children_[1].AddAChild("Five");
  uut.root_.children_[1].AddAChild("Six");
  uut.root_.children_[1].AddAChild("Seven");
  EXPECT_FALSE(uut.IsBinaryTree());
}

TEST(BinaryTreeTest, AddNodeTest) {
  BinaryTree<int> uut{0};
  uut.root_->SetLeft(1);
  uut.root_->SetRight(2);

  EXPECT_EQ(uut.root_->left_->value_, 1);
  EXPECT_EQ(uut.root_->right_->value_, 2);

  uut.root_->left_->SetLeft(3);
  uut.root_->left_->SetRight(4);
  uut.root_->right_->SetLeft(5);
  uut.root_->right_->SetRight(6);

  uut.BreadthFirstSearch(uut.root_,
                         [](std::shared_ptr<BinaryTree<int>::Node> node) {
                           if (node != nullptr) {
                             std::cout << node->value_ << '\n';
                           }
                           return true;
                         });
  std::cout << "====\n";
  uut.InOrderSearch(uut.root_, [](std::shared_ptr<BinaryTree<int>::Node> node) {
    if (node != nullptr) {
      std::cout << node->value_ << '\n';
    }
    return true;
  });
  std::cout << "====\n";
  uut.PreOrderSearch(uut.root_,
                     [](std::shared_ptr<BinaryTree<int>::Node> node) {
                       if (node != nullptr) {
                         std::cout << node->value_ << '\n';
                       }
                       return true;
                     });
  std::cout << "====\n";
  uut.PostOrderSearch(uut.root_,
                      [](std::shared_ptr<BinaryTree<int>::Node> node) {
                        if (node != nullptr) {
                          std::cout << node->value_ << '\n';
                        }
                        return true;
                      });
  EXPECT_TRUE(uut.IsFullBinaryTree());
}

TEST(BinaryTreeTest, CompeleteBinaryTreeTest) {
  BinaryTree<int> uut{1};
  uut.root_->SetLeft(2);
  uut.root_->SetRight(3);
  uut.root_->left_->SetLeft(4);
  uut.root_->left_->SetRight(5);
  uut.root_->right_->SetRight(6);
  EXPECT_FALSE(uut.IsCompleteBinaryTree());
  EXPECT_FALSE(uut.IsFullBinaryTree());
}

TEST(BinaryTreeTest, CompeleteBinaryTreeTestSuccess) {
  BinaryTree<int> uut{1};
  uut.root_->SetLeft(2);
  uut.root_->SetRight(3);
  uut.root_->left_->SetLeft(4);
  uut.root_->left_->SetRight(5);
  uut.root_->right_->SetLeft(6);
  EXPECT_TRUE(uut.IsCompleteBinaryTree());
  EXPECT_FALSE(uut.IsFullBinaryTree());
}

TEST(BinaryTreeTest, FullBinaryTreeTestSuccess) {
  BinaryTree<int> uut{1};
  uut.root_->SetLeft(2);
  uut.root_->SetRight(3);
  uut.root_->left_->SetLeft(4);
  uut.root_->left_->SetRight(5);
  uut.root_->right_->SetLeft(6);
  uut.root_->right_->SetRight(7);
  EXPECT_TRUE(uut.IsCompleteBinaryTree());
  EXPECT_TRUE(uut.IsFullBinaryTree());
  EXPECT_TRUE(uut.IsCompleteBinaryTree());
}

TEST(BinaryHeapTest, AddElement) {
  BinaryHeap<std::string_view> uut{{"one", "two", "three", "four"}};
  EXPECT_EQ(uut.GetLeft(0).value().get(), "two");
  EXPECT_NE(uut.GetLeft(0).value().get(), "three");
  EXPECT_EQ(uut.GetRight(0).value().get(), "three");
  EXPECT_NE(uut.GetRight(0).value().get(), "four");
  EXPECT_FALSE(uut.GetRight(1).has_value());
  EXPECT_EQ(uut.GetParent(2).value().get(), "one");
}

TEST(BinaryHeapTest, BreadthFirstTraverse) {
  BinaryHeap<std::string_view> uut{{"one", "two", "three", "four", "five"}};

  std::vector<std::string_view> out{"two", "four", "five"};
  size_t test_index{0};

  uut.BreadthFirstSearch(1, [&uut, &out, &test_index](size_t index) {
    EXPECT_EQ(uut.arr_[index], out[test_index]);
    ++test_index;
    std::cout << uut.arr_[index] << '\n';
    return true;
  });
}

TEST(BinaryHeapTest, InsertTest) {
  BinaryHeap<int> uut{};
  uut.Insert(1);
  uut.Insert(2);
  uut.Insert(3);
  uut.Insert(4);
  uut.Insert(5);
  uut.Insert(0);
  for (auto const& mem : uut.arr_) {
    std::cout << mem << '\n';
  }
}

TEST(BinaryHeapTest, InsertMaxHeapTest) {
  BinaryHeap<int> uut{{}, [](const int& a, const int& b) {
                        // this is the max heap
                        return a > b;
                      }};
  uut.Insert(1);
  uut.Insert(2);
  uut.Insert(3);
  uut.Insert(4);
  uut.Insert(5);
  uut.Insert(6);
  for (auto const& mem : uut.arr_) {
    std::cout << mem << '\n';
  }
}

TEST(BinaryHeapTest, RemoveTopHeapTest) {
  BinaryHeap<int> uut{};
  uut.Insert(1);
  uut.Insert(2);
  uut.Insert(3);
  uut.Insert(4);
  uut.Insert(5);
  uut.Insert(0);
  for (auto const& mem : uut.arr_) {
    std::cout << mem << '\n';
  }
  std::cout << "extracted " << uut.Extract() << '\n';
  for (auto const& mem : uut.arr_) {
    std::cout << mem << '\n';
  }
  std::cout << "extracted " << uut.Extract() << '\n';
  for (auto const& mem : uut.arr_) {
    std::cout << mem << '\n';
  }
  std::cout << "extracted " << uut.Extract() << '\n';
  for (auto const& mem : uut.arr_) {
    std::cout << mem << '\n';
  }
  std::cout << "extracted " << uut.Extract() << '\n';
  for (auto const& mem : uut.arr_) {
    std::cout << mem << '\n';
  }
  std::cout << "extracted " << uut.Extract() << '\n';
  for (auto const& mem : uut.arr_) {
    std::cout << mem << '\n';
  }
}
