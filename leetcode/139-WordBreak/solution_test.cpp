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

class LeetCode_139_WordBreak : public ::testing::TestWithParam<std::tuple<std::string_view, std::vector<std::string_view>, bool>> {};

TEST_P(LeetCode_139_WordBreak, test1) {
    auto [word, dictionary, output] = GetParam();
    Solution s{};
    auto result = s.wordBreak(word, dictionary);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_139_Suite,
                        LeetCode_139_WordBreak,
                        ::testing::Values(
                            std::make_tuple("leetcode", std::vector<std::string_view>{"leet","code"}, true),
                            std::make_tuple("applepenapple", std::vector<std::string_view>{"apple","pen"}, true),
                            std::make_tuple("catsandog", std::vector<std::string_view>{"cats","dog","sand","and","cat"}, false)));
