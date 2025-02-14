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

class LeetCode_12_IntegerToRoman : public ::testing::TestWithParam<std::tuple<int, std::string>> {};

TEST_P(LeetCode_12_IntegerToRoman, test1) {
    auto [intput, output] = GetParam();
    Solution s{};
    auto result = s.intToRoman(intput);
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_12_Suite,
                        LeetCode_12_IntegerToRoman,
                        ::testing::Values(
                            std::make_tuple(3749, "MMMDCCXLIX"),
                            std::make_tuple(58, "LVIII"),
                            std::make_tuple(1994, "MCMXCIV")));
