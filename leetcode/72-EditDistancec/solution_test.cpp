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


class LeetCode_72_EditDistance :
    public ::testing::TestWithParam<std::tuple<std::string, std::string, int>> {};

TEST_P(LeetCode_72_EditDistance, test1) {
    auto [word1, word2, output] = GetParam();
    Solution s{};
    auto result = s.editDistance(word1, word2);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_72_Suite,
                        LeetCode_72_EditDistance,
                        ::testing::Values(
                            std::make_tuple("horse", "ros", 3),
                            std::make_tuple("intention", "execution", 5),
                            std::make_tuple("a", "b", 1),
                            std::make_tuple("a", "a", 0),
                            std::make_tuple("a", "", 1),
                            std::make_tuple("", "a", 1),
                            std::make_tuple("", "", 0),
                            std::make_tuple("a", "aa", 1)));
