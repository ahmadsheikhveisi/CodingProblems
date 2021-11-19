/* COPYRIGHT
 * 
*/

// this file's inclusion
#include "solution.hpp"

// C inlcusion

// C++ inclusion
#include <vector>
#include <numeric>

// Other libraries inclusion
#include "gtest/gtest.h"

TEST(CoinChangingSolutionTest, EmptySolution) {
    Solution sol;
    auto res = sol.FindMinCoin(5, {3, 4});
    EXPECT_EQ(res.size(), 0);
}

TEST(CoinChangingSolutionTest, ShorterSolution) {
    Solution sol;
    int amount = 6;
    auto res = sol.FindMinCoin(6, {1, 3, 4});
    EXPECT_NE(res.size(), 0);
    EXPECT_EQ(amount, std::accumulate(begin(res), end(res), 0));
    EXPECT_EQ(res.size(), 2);
}

TEST(CoinChangingSolutionTest, LongTest) {
    Solution sol;
    int amount = 600;
    auto res = sol.FindMinCoin(amount, {1, 30, 4});
    EXPECT_NE(res.size(), 0);
    EXPECT_EQ(amount, std::accumulate(begin(res), end(res), 0));
    EXPECT_EQ(res.size(), 20);
}
