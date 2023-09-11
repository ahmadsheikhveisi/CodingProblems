/**
 * Copyright
 */

#include "gtest/gtest.h"

#include <iostream>
#include <string_view>  // NOLINT

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

TEST(BinaryTreeAddNode, AddNodeTest) {
  BinaryTree<int> uut{0};
  uut.root_.SetLeft(1);
  uut.root_.SetRight(2);

  EXPECT_EQ(uut.root_.left_->value_, 1);
  EXPECT_EQ(uut.root_.right_->value_, 2);

  uut.root_.left_->SetLeft(3);
  uut.root_.right_->SetRight(4);

  uut.BreadthFirstSearch(uut.root_,
    [](BinaryTree<int>::Node const& node){
      std::cout << node.value_ << '\n'; return true;});
  std::cout << "====\n";
  uut.InOrderSearch(uut.root_,
    [](BinaryTree<int>::Node const& node){
      std::cout << node.value_ << '\n'; return true;});
  std::cout << "====\n";
  uut.PreOrderSearch(uut.root_,
    [](BinaryTree<int>::Node const& node){
      std::cout << node.value_ << '\n'; return true;});
  std::cout << "====\n";
  uut.PostOrderSearch(uut.root_,
    [](BinaryTree<int>::Node const& node){
      std::cout << node.value_ << '\n'; return true;});
}
