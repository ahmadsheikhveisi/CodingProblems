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


class LeetCode_29_DivideTwoIntegers :
    public ::testing::TestWithParam<std::tuple<std::int32_t, std::int32_t, std::int32_t>> {};

TEST_P(LeetCode_29_DivideTwoIntegers, test1) {
    auto [dividend, divisor, output] = GetParam();
    Solution s{};
    auto results = s.divide(dividend, divisor);
    EXPECT_EQ(results, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_29_Suite,
                        LeetCode_29_DivideTwoIntegers,
                        ::testing::Values(
                            std::make_tuple(std::numeric_limits<std::int32_t>::min(),1,std::numeric_limits<std::int32_t>::min()),
                            std::make_tuple(std::numeric_limits<std::int32_t>::max(),-1,std::numeric_limits<std::int32_t>::min() + 1),
                            std::make_tuple(static_cast<std::int32_t>(0x7FFFFFFF),-1,static_cast<std::int32_t>(0x80000001)),
                            std::make_tuple(10,3,3),
                            std::make_tuple(7,-3,-2),
                            std::make_tuple(0,1,0),
                            std::make_tuple(1,1,1),
                            std::make_tuple(1,2,0),
                            std::make_tuple(2,2,1),
                            std::make_tuple(std::numeric_limits<std::int32_t>::min(),-1,std::numeric_limits<std::int32_t>::max()),
                            std::make_tuple(static_cast<std::int32_t>(0x80000000),-1,static_cast<std::int32_t>(0x7FFFFFFF))
                                ));
