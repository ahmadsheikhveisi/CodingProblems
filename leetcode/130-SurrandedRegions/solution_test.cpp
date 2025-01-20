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


class LeetCode_130_SurrandedRegions :
        public ::testing::TestWithParam<
                std::tuple<std::vector<std::vector<char>>,
                            std::vector<std::vector<char>>>> {};

TEST_P(LeetCode_130_SurrandedRegions, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    s.solve(arr);
    EXPECT_EQ(arr, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_130_Suite,
                        LeetCode_130_SurrandedRegions,
                        ::testing::Values(
                            std::make_tuple(std::vector<std::vector<char>>{{'X','X','X','X'},
                                                                           {'X','O','O','X'},
                                                                           {'X','X','O','X'},
                                                                           {'X','O','X','X'}},
                                            std::vector<std::vector<char>>{{'X','X','X','X'},
                                                                           {'X','X','X','X'},
                                                                           {'X','X','X','X'},
                                                                           {'X','O','X','X'}}),
                            std::make_tuple(std::vector<std::vector<char>>{{'X'}},
                                            std::vector<std::vector<char>>{{'X'}}),
                            std::make_tuple(std::vector<std::vector<char>>{{'O'}},
                                            std::vector<std::vector<char>>{{'O'}}),
                            std::make_tuple(std::vector<std::vector<char>>{{'O','O','O','O','X','X'},
                                                                           {'O','O','O','O','O','O'},
                                                                           {'O','X','O','X','O','O'},
                                                                           {'O','X','O','O','X','O'},
                                                                           {'O','X','O','X','O','O'},
                                                                           {'O','X','O','O','O','O'}},
                                            std::vector<std::vector<char>>{{'O','O','O','O','X','X'},
                                                                           {'O','O','O','O','O','O'},
                                                                           {'O','X','O','X','O','O'},
                                                                           {'O','X','O','O','X','O'},
                                                                           {'O','X','O','X','O','O'},
                                                                           {'O','X','O','O','O','O'}})));
