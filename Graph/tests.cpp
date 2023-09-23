/**
 * Copyright
 */

#include "gtest/gtest.h"

#include <iostream>  // NOLINT
#include <memory>    // NOLINT

#include "graph.hpp"

TEST(GraphTests, CreateGraph) {
  Graph uut;

  EXPECT_TRUE(uut.AddVertex("a"));
  EXPECT_TRUE(uut.AddVertex("b"));
  EXPECT_TRUE(uut.AddVertex("c"));

  EXPECT_FALSE(uut.AddVertex("a"));

  EXPECT_TRUE(uut.AddEdge("a", "b", 2));
  EXPECT_TRUE(uut.AddEdge("a", "c", 2));
  EXPECT_TRUE(uut.AddEdge("b", "c", 1));
  EXPECT_TRUE(uut.AddEdge("c", "a", 0));
  EXPECT_TRUE(uut.AddEdge("b", "b", 0));  // loop

  EXPECT_FALSE(uut.AddEdge("d", "a", 0));

  uut.Reset();

  auto visitor = [](std::shared_ptr<Graph::Vertex> vertex) {
    std::cout << vertex->name_ << ':';
    for (auto& neighbor : vertex->adjacency_list_) {
      std::cout << neighbor.first->name_ << '-' << neighbor.second.cost_;
      if (neighbor.first->visited_) {
        std::cout << "-v";
      }
      std::cout << ' ';
    }
    std::cout << '\n';
    return true;
  };

  uut.BreadthFirstSearch(begin(uut.graph_)->second, visitor);
  std::cout << '\n';
  uut.Reset();

  uut.DepthFirstSearch(begin(uut.graph_)->second, visitor);

  std::cout << '\n';
  uut.Reset();

  uut.DepthFirstSearch(uut.graph_["c"],
                       [](std::shared_ptr<Graph::Vertex> vertex) {
                         std::cout << vertex->name_ << ' ';
                         if (vertex->name_ == "a") {
                           std::cout << "found\n";
                           return false;
                         }
                         return true;
                       });
}

TEST(GraphTest, BidrectionalTest) {
  Graph uut{false};
  EXPECT_TRUE(uut.AddVertices({"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                               "10", "11", "12", "13", "14"}));
  EXPECT_TRUE(uut.AddEdge("0", "4"));
  EXPECT_TRUE(uut.AddEdge("1", "4"));
  EXPECT_TRUE(uut.AddEdge("2", "5"));
  EXPECT_TRUE(uut.AddEdge("3", "5"));
  EXPECT_TRUE(uut.AddEdge("4", "6"));
  EXPECT_TRUE(uut.AddEdge("5", "6"));
  EXPECT_TRUE(uut.AddEdge("6", "7"));
  EXPECT_TRUE(uut.AddEdge("7", "8"));
  EXPECT_TRUE(uut.AddEdge("8", "9"));
  EXPECT_TRUE(uut.AddEdge("8", "10"));
  EXPECT_TRUE(uut.AddEdge("9", "11"));
  EXPECT_TRUE(uut.AddEdge("9", "12"));
  EXPECT_TRUE(uut.AddEdge("10", "13"));
  EXPECT_TRUE(uut.AddEdge("10", "14"));
  auto path = uut.BidirectionalSearch(uut.FindVertedByName("0"),
                                      uut.FindVertedByName("14"));

  for (auto vx : path) {
    std::cout << vx->name_ << ' ';
  }
  std::cout << '\n';
}
