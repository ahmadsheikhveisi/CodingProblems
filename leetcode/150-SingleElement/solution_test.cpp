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


class LeetCode_150_SingleElement :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int>> {};

TEST_P(LeetCode_150_SingleElement, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto result = s.singleNumber(arr);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_150_Suite,
                        LeetCode_150_SingleElement,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{2,2,1},1),
                            std::make_tuple(std::vector<int>{4,1,2,1,2},4),
                            std::make_tuple(std::vector<int>{1},1)));
