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


class LeetCode_134_GasStation :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>, int>> {};

TEST_P(LeetCode_134_GasStation, test1) {
    auto [gas, cost, output] = GetParam();
    Solution s{};
    auto result = s.canCompleteCircuit(gas, cost);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_134_Suite,
                        LeetCode_134_GasStation,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{1,2,3,4,5}, std::vector<int>{3,4,5,1,2}, 3),
                            std::make_tuple(std::vector<int>{2,3,4}, std::vector<int>{3,3,4}, -1)));
