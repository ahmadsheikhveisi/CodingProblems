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


class LeetCode_169_MajorityElement :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int>> {};

TEST_P(LeetCode_169_MajorityElement, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto result = s.majorityElement(arr);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_169_Suite,
                        LeetCode_169_MajorityElement,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{6,6,6,7,7},6),
                            std::make_tuple(std::vector<int>{3,2,3},3),
                            std::make_tuple(std::vector<int>{2,2,1,1,1,2,2},2)));
