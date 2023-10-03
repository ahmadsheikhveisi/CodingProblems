/**
 * Copyright
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
            std::vector<std::string>({"e", "f", "a", "b", "d", "c"}));
}
