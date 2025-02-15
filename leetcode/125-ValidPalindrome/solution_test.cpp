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

class LeetCode_125_ValidPalindrome : public ::testing::TestWithParam<std::tuple<std::string, bool>> {};

TEST_P(LeetCode_125_ValidPalindrome, test1) {
    auto [intput, output] = GetParam();
    Solution s{};
    auto result = s.isPalindrome(intput);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_125_Suite,
                        LeetCode_125_ValidPalindrome,
                        ::testing::Values(
                            std::make_tuple("0P", false),
                            std::make_tuple("A man, a plan, a canal: Panama", true),
                            std::make_tuple("race a car", false),
                            std::make_tuple(" ", true)));
