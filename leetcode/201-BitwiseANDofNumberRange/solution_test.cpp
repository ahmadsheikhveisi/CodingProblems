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

class LeetCode_201_BitwiseANDOfNumberRange : public ::testing::TestWithParam<std::tuple<int, int, int>> {};

TEST_P(LeetCode_201_BitwiseANDOfNumberRange, test1) {
    auto [left, right, output] = GetParam();
    Solution s{};
    auto result = s.rangeBitwiseAnd(left, right);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_201_Suite,
                        LeetCode_201_BitwiseANDOfNumberRange,
                        ::testing::Values(
                            std::make_tuple(5, 7, 4),
                            std::make_tuple(0, 0, 0),
                            std::make_tuple(1, std::numeric_limits<int>::max(), 0),
                            std::make_tuple(0, std::numeric_limits<int>::max(), 0)));
