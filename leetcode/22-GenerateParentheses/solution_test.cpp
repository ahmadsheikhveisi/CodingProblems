/* COPYRIGHT
*/

#include "solution.hpp"

#include <gtest/gtest.h>
#include <memory>
#include <initializer_list>
#include <vector>
#include <string>
#include <tuple>


class LeetCode_22_GenerateParentheses :
    public ::testing::TestWithParam<std::tuple<int, std::vector<std::string>>> {};

TEST_P(LeetCode_22_GenerateParentheses, test1) {
    auto [n, output] = GetParam();
    Solution s{};
    auto results = s.generateParenthesis(n);
    EXPECT_EQ(results, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_22_Suite,
                        LeetCode_22_GenerateParentheses,
                        ::testing::Values(std::make_tuple(3,
                            std::vector<std::string>{
                                "((()))", "(()())", "(())()", "()(())", "()()()"}),
                                std::make_tuple(2,
                            std::vector<std::string>{
                                "(())", "()()"})));
