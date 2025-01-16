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


class LeetCode_27_RemoveElement :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>> {};

TEST_P(LeetCode_27_RemoveElement, test1) {
    auto [nums, val, output] = GetParam();
    Solution s{};
    auto result = s.removeElement(nums, val);
    EXPECT_EQ(result, output.size());
    std::sort(nums.begin(), nums.begin() + result);
    std::sort(output.begin(), output.end());
    for(int i{0}; i < result; ++i) {
        EXPECT_EQ(nums[i], output[i]);
    }
}


INSTANTIATE_TEST_SUITE_P(LeetCode_27_Suite,
                        LeetCode_27_RemoveElement,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{3,2,2,3},3,std::vector<int>{2,2}),
                            std::make_tuple(std::vector<int>{3,2,2,3},4,std::vector<int>{3,2,2,3}),
                            std::make_tuple(std::vector<int>{0,1,2,2,3,0,4,2},2,std::vector<int>{0,1,4,0,3})));
