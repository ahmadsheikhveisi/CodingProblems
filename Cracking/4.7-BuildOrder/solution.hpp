/**
 * Copyright
 * You are given a list of projects and a list of dependencies (which is a list
 * of pairs of projects, where the second project is dependent on the first
 * project). All of a project's dependencies must be built before the project
 * is. Find a build order that will allow the projects to be built. if there is
 * no valid build order, return an error.
 * Input:
 *  projects: a, b, c, d, e, f
 *  dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
 *
 *  output: f, e, a, b, d, c
 */

#ifndef CRACKING_4_7_BUILDORDER_SOLUTION_HPP_
#define CRACKING_4_7_BUILDORDER_SOLUTION_HPP_

#include <algorithm>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "graph.hpp"

class Solution {
 public:
  std::vector<std::string> FindBuildOrder(
      std::vector<std::string> projects,
      std::vector<std::pair<std::string, std::string>> dependencies) {
    Graph graph{};
    std::unordered_map<std::string, std::vector<std::string>> parent_map{};
    std::vector<std::string> build_order{};
    for (auto const& proj : projects) {
      graph.AddVertex(proj);
    }
    for (auto const& [from, to] : dependencies) {
      graph.AddEdge(from, to);
      graph.graph_[to]->visited_ = true;
      parent_map[to].push_back(from);
    }
    for (auto const& [name, vertex] : graph.graph_) {
      if (!vertex->visited_) {
        build_order.push_back(name);
      }
    }
    graph.Reset();
    for (auto const& node : build_order) {
      graph.FindVertedByName(node)->visited_ = true;
    }
    for (size_t cnt{0}; cnt < build_order.size(); ++cnt) {
      /**
       * this doesn't cover the situation where there is triangle dependecies.
       * graph.BreadthFirstSearch(
          graph.FindVertedByName(node),
          [&res](std::shared_ptr<Graph::Vertex> vertex) {
            if (std::find(begin(res), end(res), vertex->name_) == end(res)) {
              res.push_back(vertex->name_);
            }
            return true;
          });*/
      auto vertex = graph.FindVertedByName(build_order[cnt]);
      for (auto const& chld : vertex->adjacency_list_) {
        if (!chld.first->visited_) {
          bool all_build{true};
          for (auto const& parent : parent_map[chld.first->name_]) {
            if (!graph.FindVertedByName(parent)->visited_) {
              all_build = false;
              break;
            }
          }
          if (all_build) {
            build_order.push_back(chld.first->name_);
            chld.first->visited_ = true;
          }
        }
      }
    }
    for (auto const& proj : projects) {
      if (!graph.FindVertedByName(proj)->visited_) {
        return {};
      }
    }
    return build_order;
  }
};

#endif  // CRACKING_4_7_BUILDORDER_SOLUTION_HPP_
