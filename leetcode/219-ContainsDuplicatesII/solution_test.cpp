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


class LeetCode_219_ContainsDuplicatesII :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int, bool>> {};

TEST_P(LeetCode_219_ContainsDuplicatesII, test1) {
    auto [arr, k, output] = GetParam();
    Solution s{};
    auto result = s.containsNearbyDuplicate(arr, k);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_219_Suite,
                        LeetCode_219_ContainsDuplicatesII,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{1,2,3,1},3, true),
                            std::make_tuple(std::vector<int>{1,0,1,1},1, true),
                            std::make_tuple(std::vector<int>{1,2,3,1,2,3},2, false),
                            std::make_tuple(std::vector<int>{99,99},2, true)));
