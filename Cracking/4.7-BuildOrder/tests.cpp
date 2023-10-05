/**
 * Copyright
 * there is a list of dependencies and there is a result.
 * how to make sure that the result follow the list of deps.
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(BuildOrder, BuildOrderExample) {
  Solution uut;

  EXPECT_EQ(uut.FindBuildOrder({"a", "b", "c", "d", "e", "f"}, {{"a", "d"},
                                                                {"f", "b"},
                                                                {"b", "d"},
                                                                {"f", "a"},
                                                                {"d", "c"},
                                                                {"b", "a"}}),
            std::vector<std::string>({"e", "f", "b", "a", "d", "c"}));

  EXPECT_EQ(uut.FindBuildOrder({"a", "b", "c", "d", "e", "f"}, {{"a", "b"},
                                                                {"b", "c"},
                                                                {"b", "d"},
                                                                {"f", "a"},
                                                                {"d", "c"},
                                                                {"d", "f"}}),
            std::vector<std::string>());  // has a cycle

  auto res =
      uut.FindBuildOrder({"a", "b", "c", "d", "e", "f", "g"}, {{"a", "e"},
                                                               {"b", "e"},
                                                               {"b", "a"},
                                                               {"f", "a"},
                                                               {"c", "a"},
                                                               {"f", "b"},
                                                               {"f", "c"},
                                                               {"d", "g"}});
  for (auto const& proj : res) {
    std::cout << proj << ' ';
  }
  std::cout << '\n';
}
