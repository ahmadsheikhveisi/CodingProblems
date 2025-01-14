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


class LeetCode_33_SearchInRotatedSortedArray :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int, int>> {};

TEST_P(LeetCode_33_SearchInRotatedSortedArray, test1) {
    auto [arr, target, output] = GetParam();
    Solution s{};
    auto results = s.search(arr, target);
    EXPECT_EQ(results, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_33_Suite,
                        LeetCode_33_SearchInRotatedSortedArray,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{1,3},0,-1),
                            std::make_tuple(std::vector<int>{4,5,6,7,0,1,2},0,4),
                            std::make_tuple(std::vector<int>{4,5,6,7,0,1,2},3,-1),
                            std::make_tuple(std::vector<int>{1,2,4,5,6,7,0},7,5),
                            std::make_tuple(std::vector<int>{1},0,-1)
                                ));
