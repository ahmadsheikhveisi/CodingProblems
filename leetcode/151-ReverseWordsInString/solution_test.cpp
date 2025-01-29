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
#include <string_view>


class LeetCode_151_ReverseWordsInString :
    public ::testing::TestWithParam<std::tuple<std::string_view, std::string_view>> {};

TEST_P(LeetCode_151_ReverseWordsInString, test1) {
    auto [str, output] = GetParam();
    Solution s{};
    auto result = s.reverseWords(std::string{str});
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_151_Suite,
                        LeetCode_151_ReverseWordsInString,
                        ::testing::Values(
                            std::make_tuple("the sky is blue","blue is sky the"),
                            std::make_tuple("  hello world  ","world hello"),
                            std::make_tuple("a good   example","example good a")));
