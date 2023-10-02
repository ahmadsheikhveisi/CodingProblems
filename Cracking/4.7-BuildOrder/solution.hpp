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
#include <utility>
#include <vector>

#include "graph.hpp"

class Solution {
 public:
  std::vector<char> FindBuildOrder(
      std::vector<char> projects,
      std::vector<std::pair<char, char>> dependencies) {
    (void)projects;
    (void)dependencies;
    return {};
  }
};

#endif  // CRACKING_4_7_BUILDORDER_SOLUTION_HPP_
