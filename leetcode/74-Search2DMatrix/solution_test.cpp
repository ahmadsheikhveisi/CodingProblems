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


class LeetCode_74_Search2DMatrix :
    public ::testing::TestWithParam<std::tuple<std::vector<std::vector<int>>,
                                                int, bool>> {};

TEST_P(LeetCode_74_Search2DMatrix, test1) {
    auto [matrix, target, output] = GetParam();
    Solution s{};
    auto result = s.searchMatrix(matrix, target);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_74_Suite,
                        LeetCode_74_Search2DMatrix,
                        ::testing::Values(
                            std::make_tuple(std::vector<std::vector<int>>{{1,1}},
                                            0, false),
                            std::make_tuple(std::vector<std::vector<int>>{{1,3,5,7},
                                                                           {10,11,16,20},
                                                                           {23,30,34,60}},
                                            3, true),
                            std::make_tuple(std::vector<std::vector<int>>{{1,3,5,7},
                                                                           {10,11,16,20},
                                                                           {23,30,34,60}},
                                            13, false)));
