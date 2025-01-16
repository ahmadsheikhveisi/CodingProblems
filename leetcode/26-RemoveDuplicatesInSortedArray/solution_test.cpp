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


class LeetCode_26_RemoveDuplicatesInSortedArray :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {};

TEST_P(LeetCode_26_RemoveDuplicatesInSortedArray, test1) {
    auto [nums, output] = GetParam();
    Solution s{};
    auto result = s.removeDuplicates(nums);
    EXPECT_EQ(result, output.size());
    for(int i{0}; i < result; ++i) {
        EXPECT_EQ(nums[i], output[i]);
    }
}


INSTANTIATE_TEST_SUITE_P(LeetCode_26_Suite,
                        LeetCode_26_RemoveDuplicatesInSortedArray,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{1,1,2},std::vector<int>{1,2}),
                            std::make_tuple(std::vector<int>{0,0,1,1,1,2,2,3,3,4},std::vector<int>{0,1,2,3,4}),
                            std::make_tuple(std::vector<int>{0,1,2,3,4},std::vector<int>{0,1,2,3,4})));
