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


class LeetCode_88_MergeTwoSortedArrays :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int,
                std::vector<int>, int, std::vector<int>>> {};

TEST_P(LeetCode_88_MergeTwoSortedArrays, test1) {
    auto [arr1, size1, arr2, size2, output] = GetParam();
    Solution s{};
    s.merge(arr1, size1, arr2, size2);
    EXPECT_EQ(arr1, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_88_Suite,
                        LeetCode_88_MergeTwoSortedArrays,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{1,2,3,0,0,0},3,std::vector<int>{2,5,6},3,std::vector<int>{1,2,2,3,5,6}),
                            
                            std::make_tuple(std::vector<int>{1},1,std::vector<int>{},0,std::vector<int>{1})));
