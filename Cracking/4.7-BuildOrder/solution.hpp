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
  std::vector<std::string> FindBuildOrderDFS(
      std::vector<std::string> const& projects,
      std::vector<std::pair<std::string, std::string>> const& dependencies) {
    std::unordered_map<std::string, VertexState> visit_state{};
    for (auto const& proj : projects) {
      visit_state[proj] = VertexState::kNotVisited;
    }
    auto graph = BuildGraph(projects, dependencies);
    std::vector<std::string> res{};
    for (auto const& [name, node] : graph.graph_) {
      if (visit_state[name] != VertexState::kVisited) {
        if (!FindBuildOrderDFSRec(res, visit_state, node)) {
          return {};
        }
      }
    }
    std::reverse(begin(res), end(res));
    return res;
  }

  std::vector<std::string> FindBuildOrder(
      std::vector<std::string> const& projects,
      std::vector<std::pair<std::string, std::string>> const& dependencies) {
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

  private:
  enum class VertexState : std::uint8_t {
    kVisiting,
    kNotVisited,
    kVisited,
  };

  Graph BuildGraph(std::vector<std::string> projects,
      std::vector<std::pair<std::string, std::string>> dependencies) {
    Graph graph{};
    for (auto const& proj : projects) {
      graph.AddVertex(proj);
    }
    for (auto const& [from, to] : dependencies) {
      graph.AddEdge(from, to);
      graph.graph_[to]->visited_ = true;
    }
    return graph;
  }

  bool FindBuildOrderDFSRec(std::reference_wrapper<std::vector<std::string>> rres,
                            std::reference_wrapper<std::unordered_map<std::string, VertexState>> rvisit_state,
                            std::shared_ptr<Graph::Vertex> node) {
    auto& res = rres.get();
    auto& visit_state = rvisit_state.get();
    if (visit_state[node->name_] == VertexState::kVisiting) {
      // loop.
      return false;
    }
    visit_state[node->name_] = VertexState::kVisiting;
    for (auto const& chld : node->adjacency_list_) {
      if (visit_state[chld.first->name_] != VertexState::kVisited) {
          if (!FindBuildOrderDFSRec(rres, rvisit_state, chld.first)) {
            return false;
          }
      }
    }
    res.push_back(node->name_);
    visit_state[node->name_] = VertexState::kVisited;
    return true;
  }
};

#endif  // CRACKING_4_7_BUILDORDER_SOLUTION_HPP_
