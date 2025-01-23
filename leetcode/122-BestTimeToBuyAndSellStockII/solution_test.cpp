/* COPYRIGHT
*/

#include "solution.hpp"

#include <gtest/gtest.h>
#include <memory>
#include <initializer_list>
#include <vector>
#include <string>
#include <tuple>
#include <limits>

class LeetCode_122_BestTimeToBuyAndSellStockII : public ::testing::TestWithParam<std::tuple<std::vector<int>, int>> {};

TEST_P(LeetCode_122_BestTimeToBuyAndSellStockII, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto result = s.maxProfit(arr);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_122_Suite,
                        LeetCode_122_BestTimeToBuyAndSellStockII,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{7,1,5,3,6,4}, 7),
                            std::make_tuple(std::vector<int>{1,2,3,4,5}, 4),
                            std::make_tuple(std::vector<int>{7,6,4,3,1}, 0),
                            std::make_tuple(std::vector<int>{1,5,3,100}, 101)));
