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


class LeetCode_73_SetMatrixZeroes :
    public ::testing::TestWithParam<std::tuple<std::vector<std::vector<int>>,
                                                std::vector<std::vector<int>>>> {};

TEST_P(LeetCode_73_SetMatrixZeroes, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    s.setZeroes(arr);
    EXPECT_EQ(arr, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_73_Suite,
                        LeetCode_73_SetMatrixZeroes,
                        ::testing::Values(
                            std::make_tuple(std::vector<std::vector<int>>{{1, 1, 1},
                                                                           {1, 0, 1},
                                                                           {1, 1, 1}},
                                            std::vector<std::vector<int>>{{1, 0, 1},
                                                                           {0, 0, 0},
                                                                           {1, 0, 1}}),
                            std::make_tuple(std::vector<std::vector<int>>{{0, 1, 2, 0},
                                                                           {3, 4, 5, 2},
                                                                           {1, 3, 1, 5}},
                                            std::vector<std::vector<int>>{{0, 0, 0, 0},
                                                                           {0, 4, 5, 0},
                                                                           {0, 3, 1, 0}})));
