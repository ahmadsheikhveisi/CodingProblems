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


class LeetCode_34_FindTheFirstAndLastPositionElementInSortedArray :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>> {};

TEST_P(LeetCode_34_FindTheFirstAndLastPositionElementInSortedArray, test1) {
    auto [arr, target, output] = GetParam();
    Solution s{};
    auto results = s.searchRange(arr, target);
    EXPECT_EQ(results, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_34_Suite,
                        LeetCode_34_FindTheFirstAndLastPositionElementInSortedArray,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{5,7,7,8,8,10},8,std::vector<int>{3,4}),
                            std::make_tuple(std::vector<int>{7,7,7,7,7,7},7,std::vector<int>{0,5}),
                            std::make_tuple(std::vector<int>{5,7,8,8,8,10},8,std::vector<int>{2,4}),
                            std::make_tuple(std::vector<int>{5,7,7,8,8,10},7,std::vector<int>{1,2}),
                            std::make_tuple(std::vector<int>{5,7,7,8,8,10},6,std::vector<int>{-1,-1}),
                            std::make_tuple(std::vector<int>{},0,std::vector<int>{-1,-1})
                                ));
