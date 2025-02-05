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


class LeetCode_909_SnakesAndLadders :
    public ::testing::TestWithParam<std::tuple<std::vector<std::vector<int>>, int>> {};

TEST_P(LeetCode_909_SnakesAndLadders, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto result = s.snakesAndLadders(arr);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_909_Suite,
                        LeetCode_909_SnakesAndLadders,
                        ::testing::Values(
                            std::make_tuple(std::vector<std::vector<int>>{{-1,-1,-1},
                                                                          {-1,9,8},
                                                                          {-1,8,9}}, 1),
                            std::make_tuple(std::vector<std::vector<int>>{{1,1,-1},
                                                                          {1,1,1},
                                                                          {-1,1,1}},-1),
                            std::make_tuple(std::vector<std::vector<int>>{{-1,-1,-1,-1,-1,-1},
                                                                        {-1,-1,-1,-1,-1,-1},
                                                                        {-1,-1,-1,-1,-1,-1},
                                                                        {-1,35,-1,-1,13,-1},
                                                                        {-1,-1,-1,-1,-1,-1},
                                                                        {-1,15,-1,-1,-1,-1}},4),
                            std::make_tuple(std::vector<std::vector<int>>{{-1,-1},{-1,3}},1)));
