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

class LeetCode_127_WordLatter : public ::testing::TestWithParam<std::tuple<std::string, std::string, std::vector<std::string>, int>> {};

TEST_P(LeetCode_127_WordLatter, test1) {
    auto [begin_word, end_word, dictionary, output] = GetParam();
    Solution s{};
    auto result = s.ladderLength(begin_word, end_word, dictionary);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_127_Suite,
                        LeetCode_127_WordLatter,
                        ::testing::Values(
                            std::make_tuple("hit", "cog", std::vector<std::string>{"hot","dot","dog","lot","log","cog"}, 5),
                            std::make_tuple("hit", "cog", std::vector<std::string>{"hot","dot","dog","lot","log"}, 0)));
