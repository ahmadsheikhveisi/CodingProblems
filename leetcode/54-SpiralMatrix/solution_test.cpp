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


class LeetCode_54_SpiralMatrix :
    public ::testing::TestWithParam<std::tuple<std::vector<std::vector<int>>,
                                                std::vector<int>>> {};

TEST_P(LeetCode_54_SpiralMatrix, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto result = s.spiralOrder(arr);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_54_Suite,
                        LeetCode_54_SpiralMatrix,
                        ::testing::Values(
                            std::make_tuple(std::vector<std::vector<int>>{{1,2,3,4},
                                                                           {5,6,7,8},
                                                                           {9,10,11,12},
                                                                           {13,14,15,16},
                                                                           {17,18,19,20},
                                                                           {21,22,23,24}},
                                            std::vector<int>{1,2,3,4,8,12,16,20,24,23,22,21,17,13,9,5,6,7,11,15,19,18,14,10}),
                            std::make_tuple(std::vector<std::vector<int>>{{1,2,3},
                                                                           {4,5,6},
                                                                           {7,8,9}},
                                            std::vector<int>{1,2,3,6,9,8,7,4,5}),
                            std::make_tuple(std::vector<std::vector<int>>{{1,2,3,4},
                                                                           {5,6,7,8},
                                                                           {9,10,11,12}},
                                            std::vector<int>{1,2,3,4,8,12,11,10,9,5,6,7})));
