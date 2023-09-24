/**
 * Copyright
 */

#ifndef CRACKING_4_1_ROUTEBETWEENNODES_SOLUTION_HPP_
#define CRACKING_4_1_ROUTEBETWEENNODES_SOLUTION_HPP_

#include <memory>
#include <string>

#include "graph.hpp"

class solution {
 public:
  solution(std::initializer_list<std::string> vertices) : graph{} {
    graph.AddVertices(vertices);
  }
  bool AddEdge(std::string const& from, std::string const& to) {
    return graph.AddEdge(from, to);
  }
  bool DoesRouteExist(std::string const& start, std::string const& target) {
    bool found{false};
    auto sv = graph.FindVertedByName(start);
    auto tv = graph.FindVertedByName(target);
    if ((sv == nullptr) || (tv == nullptr)) {
      return false;
    }
    auto visitor = [&found, &sv, &tv](std::shared_ptr<Graph::Vertex> vertex) {
      if (vertex == tv) {
        found = true;
        return false;
      }
      return true;
    };
    graph.Reset();
    static_cast<void>(graph.BreadthFirstSearch(sv, visitor));
    return found;
  }

 private:
  Graph graph;
};

#endif  // CRACKING_4_1_ROUTEBETWEENNODES_SOLUTION_HPP_
