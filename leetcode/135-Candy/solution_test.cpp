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


class LeetCode_135_Candy :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int>> {};

TEST_P(LeetCode_135_Candy, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto result = s.candy(arr);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_135_Suite,
                        LeetCode_135_Candy,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{1,0,2},5),
                            std::make_tuple(std::vector<int>{1,2,2},4),
                            std::make_tuple(std::vector<int>{2},1),
                            std::make_tuple(std::vector<int>{2,2,2,2,2},5),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},15),
                            std::make_tuple(std::vector<int>{5,4,3,2,1},15),
                            std::make_tuple(std::vector<int>{1,2,3,4,5,4,3,2,1},25),
                            std::make_tuple(std::vector<int>{1,2,3,4,5,4,3,2,1,2,3,4,5},39),
                            std::make_tuple(std::vector<int>{1,2,3,4,5,4,3,2,1,2,3,4,5,4,3,2,1},49)));
