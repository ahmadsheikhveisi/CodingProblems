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


class LeetCode_918_MaximumSumSubarray :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int>> {};

TEST_P(LeetCode_918_MaximumSumSubarray, test1) {
    auto [input, output] = GetParam();
    Solution s{};
    auto result = s.maxSubarraySumCircular(input);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_918_Suite,
                        LeetCode_918_MaximumSumSubarray,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{8,-15,-29,-19}, 8),
                            std::make_tuple(std::vector<int>{-3,5,5}, 10),
                            std::make_tuple(std::vector<int>{5,-3,5}, 10),
                            std::make_tuple(std::vector<int>{1,-2,3,-2}, 3),
                            std::make_tuple(std::vector<int>{-3,-2,-3}, -2)));
