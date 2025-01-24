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

class LeetCode_39_CombinationSum : public ::testing::TestWithParam<
    std::tuple<std::vector<int>, int, std::vector<std::vector<int>>>> {};

TEST_P(LeetCode_39_CombinationSum, test1) {
    auto [arr, target, output] = GetParam();
    Solution s{};
    auto result = s.combinationSum(arr, target);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_39_Suite,
                        LeetCode_39_CombinationSum,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{2,3,6,7}, 7, std::vector<std::vector<int>>{{2,2,3},{7}}),
                            std::make_tuple(std::vector<int>{3,2,7,6}, 7, std::vector<std::vector<int>>{{3,2,2},{7}}),
                            std::make_tuple(std::vector<int>{2,5,3}, 8, std::vector<std::vector<int>>{{2,2,2,2},{2,3,3},{5,3}}),
                            std::make_tuple(std::vector<int>{2}, 1, std::vector<std::vector<int>>{})));
