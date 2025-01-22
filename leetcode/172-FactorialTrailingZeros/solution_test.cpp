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


class LeetCode_172_FactorialTrailingZeros :
    public ::testing::TestWithParam<std::tuple<int, int>> {};

TEST_P(LeetCode_172_FactorialTrailingZeros, test1) {
    auto [input, output] = GetParam();
    Solution s{};
    auto result = s.trailingZeroes(input);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_172_Suite,
                        LeetCode_172_FactorialTrailingZeros,
                        ::testing::Values(
                            std::make_tuple(10,2),
                            std::make_tuple(3,0),
                            std::make_tuple(5,1),
                            std::make_tuple(0,0)));
