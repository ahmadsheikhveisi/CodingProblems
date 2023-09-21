/**
 * Copyright
*/

#include "gtest/gtest.h"

#include <iostream>
#include <memory>

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
    EXPECT_TRUE(uut.AddEdge("b", "b", 0)); // loop

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

    uut.BreadthFirstSearch(begin(uut.graph)->second, visitor);
    std::cout << '\n';
    uut.Reset();

    uut.DepthFirstSearch(begin(uut.graph)->second, visitor);

    std::cout << '\n';
    uut.Reset();

    uut.DepthFirstSearch(uut.graph["c"], [](std::shared_ptr<Graph::Vertex> vertex) {
        std::cout << vertex->name_ << ' ';
        if (vertex->name_ == "a") {
            std::cout << "found\n";
            return false;
        }
        return true;
    });
}
