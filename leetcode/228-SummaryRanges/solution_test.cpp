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


class LeetCode_228_SummaryRanges :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<std::string>>> {};

TEST_P(LeetCode_228_SummaryRanges, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto result = s.summaryRanges(arr);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_228_Suite,
                        LeetCode_228_SummaryRanges,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{0,1,2,4,5,7},std::vector<std::string>{"0->2","4->5","7"}),
                            std::make_tuple(std::vector<int>{0,2,3,4,6,8,9},std::vector<std::string>{"0","2->4","6","8->9"}),
                            std::make_tuple(std::vector<int>{},std::vector<std::string>{}),
                            std::make_tuple(std::vector<int>{0},std::vector<std::string>{"0"}),
                            std::make_tuple(std::vector<int>{0,1},std::vector<std::string>{"0->1"}),
                            std::make_tuple(std::vector<int>{0,1,2},std::vector<std::string>{"0->2"}),
                            std::make_tuple(std::vector<int>{0,1,2,3},std::vector<std::string>{"0->3"}),
                            std::make_tuple(std::vector<int>{0,1,2,3,4},std::vector<std::string>{"0->4"})));
