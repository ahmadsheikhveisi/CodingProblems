/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(BuildOrder, BuildOrderExample) {
  Solution uut;

  EXPECT_EQ(uut.FindBuildOrder(
                {'a', 'b', 'c', 'd', 'e', 'f'},
                {{'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}}),
            std::vector<char>({'f', 'e', 'a', 'b', 'd', 'c'}));
}
