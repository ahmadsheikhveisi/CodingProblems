/* COPYRIGHT Test class
 * 
*/

#include <iostream>
#include <memory>

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(AdjPntMinDist, Ex1) {
    auto obj = solution::Solution();
    EXPECT_EQ(1, obj.AdjacentPoitMinDis({1, 2}, 1, 2));
}

TEST(AdjPntMinDist, Ex2) {
    auto obj = solution::Solution();
    EXPECT_EQ(2, obj.AdjacentPoitMinDis({3, 4, 5}, 3, 5));
}

TEST(AdjPntMinDist, Ex3) {
    auto obj = solution::Solution();
    EXPECT_EQ(4, obj.AdjacentPoitMinDis(
        {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, 3, 6));
}

TEST(AdjPntMinDist, Ex4) {
    auto obj = solution::Solution();
    EXPECT_EQ(1, obj.AdjacentPoitMinDis({2, 2, 5, 3, 5, 4, 4, 2, 3}, 3, 2));
}

TEST(AdjPntMinDist, Emptyarr) {
    auto obj = solution::Solution();
    EXPECT_EQ(-1, obj.AdjacentPoitMinDis({}, 3, 2));
}

TEST(AdjPntMinDist, NotExisting) {
    auto obj = solution::Solution();
    EXPECT_EQ(-1, obj.AdjacentPoitMinDis({4, 5, 6}, 3, 2));
}
