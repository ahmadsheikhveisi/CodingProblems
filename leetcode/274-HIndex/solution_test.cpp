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


class LeetCode_274_HIndex :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int>> {};

TEST_P(LeetCode_274_HIndex, test1) {
    auto [input, output] = GetParam();
    Solution s{};
    auto result = s.hIndex(input);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_274_Suite,
                        LeetCode_274_HIndex,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{3,0,6,1,5}, 3),
                            std::make_tuple(std::vector<int>{100}, 1),
                            std::make_tuple(std::vector<int>{1,3,1}, 1)));
