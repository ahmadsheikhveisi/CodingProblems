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


class LeetCode_300_LongestIncreasingSubsequence :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int>> {};

TEST_P(LeetCode_300_LongestIncreasingSubsequence, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto result = s.lengthOfLIS(arr);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_300_Suite,
                        LeetCode_300_LongestIncreasingSubsequence,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{10,9,2,5,3,7,101,18},4),
                            std::make_tuple(std::vector<int>{0,1,0,3,2,3},4),
                            std::make_tuple(std::vector<int>{7,7,7,7,7,7,7},1)));
