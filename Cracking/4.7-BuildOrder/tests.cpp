/**
 * Copyright
 * there is a list of dependencies and there is a result.
 * how to make sure that the result follow the list of deps.
 */

#include "gtest/gtest.h"

#include "solution.hpp"

template <typename T>
bool CheckRes(std::vector<T> const& build_order, std::vector<T> const& projects,
              std::vector<std::pair<T, T>> const& deps) {
  std::unordered_map<T, size_t> position{};
  size_t pos{0};
  if (!std::is_permutation(begin(projects), end(projects),
                           begin(build_order))) {
    return false;
  }
  if (!std::is_permutation(begin(build_order), end(build_order),
                           begin(projects))) {
    return false;
  }
  for (auto const& poj : build_order) {
    position[poj] = pos;
    ++pos;
  }
  for (auto const& dep : deps) {
    if (position.find(dep.first) == end(position)) {
      return false;
    }
    if (position.find(dep.second) == end(position)) {
      return false;
    }
    if (position[dep.first] > position[dep.second]) {
      return false;
    }
  }
  return true;
}

TEST(BuildOrder, BuildOrderExample) {
  Solution uut;

  std::vector<std::string> projects{{"a", "b", "c", "d", "e", "f"}};
  std::vector<std::pair<std::string, std::string>> dependencies{
      {"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}, {"b", "a"}};
  auto res = uut.FindBuildOrder(projects, dependencies);
  EXPECT_TRUE(CheckRes(res, projects, dependencies));
  auto res_dfs = uut.FindBuildOrderDFS(projects, dependencies);
  EXPECT_TRUE(CheckRes(res_dfs, projects, dependencies));
  for (auto const& node : res_dfs) {
    std::cout << node << ' ';
  }
  std::cout << '\n';
}
TEST(BuildOrder, BuildOrderExampleFail) {
  Solution uut;
  std::vector<std::string> projects{"a", "b", "c", "d", "e", "f"};
  std::vector<std::pair<std::string, std::string>> dependencies{
      {"a", "b"}, {"b", "c"}, {"b", "d"}, {"f", "a"}, {"d", "c"}, {"d", "f"}};
  EXPECT_EQ(uut.FindBuildOrder(projects, dependencies),
            std::vector<std::string>());  // has a cycle
  EXPECT_EQ(uut.FindBuildOrderDFS(projects, dependencies),
            std::vector<std::string>());
}
TEST(BuildOrder, BuildOrderExample2) {
  Solution uut;
  std::vector<std::string> projects{{"a", "b", "c", "d", "e", "f", "g"}};
  std::vector<std::pair<std::string, std::string>> dependencies{
      {"a", "e"}, {"b", "e"}, {"b", "a"}, {"f", "a"},
      {"c", "a"}, {"f", "b"}, {"f", "c"}, {"d", "g"}};
  {
    auto res = uut.FindBuildOrder(projects, dependencies);
    for (auto const& proj : res) {
      std::cout << proj << ' ';
    }
    std::cout << '\n';
    EXPECT_TRUE(CheckRes(res, projects, dependencies));
  }
  {
    auto res = uut.FindBuildOrderDFS(projects, dependencies);
    for (auto const& proj : res) {
      std::cout << proj << ' ';
    }
    std::cout << '\n';
    EXPECT_TRUE(CheckRes(res, projects, dependencies));
  }
}

TEST(CheckResTest, OneExtra) {
  EXPECT_FALSE(CheckRes<int>({1, 2, 3}, {1, 2, 3, 4}, {}));
  EXPECT_FALSE(CheckRes<int>({1, 2, 3, 4}, {1, 2, 3}, {}));
}

TEST(CheckResTest, OneDifferent) {
  EXPECT_FALSE(CheckRes<int>({1, 2, 3, 5}, {1, 2, 3, 4}, {}));
  EXPECT_FALSE(CheckRes<int>({1, 2, 3, 4}, {1, 2, 5, 4}, {}));
}

TEST(CheckResTest, DifferentOrder) {
  EXPECT_TRUE(CheckRes<int>({4, 2, 3, 1}, {1, 2, 3, 4}, {}));
  EXPECT_TRUE(CheckRes<int>({1, 5, 2, 4}, {1, 2, 5, 4}, {}));
}

TEST(BuildOrder, BuildOrderDFS) {
  Solution uut;
  auto res = uut.FindBuildOrderDFS({"1", "2", "3", "4", "5"},
                                   {{"2", "1"}, {"1", "3"}, {"2", "5"}});
  for (const auto& node : res) {
    std::cout << node << ' ';
  }
  std::cout << '\n';
}
