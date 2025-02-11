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

std::vector<std::shared_ptr<ListNode>> CreateList(std::vector<int> const& list) {
    if (list.size() == 0) {
        return {nullptr};
    }
    std::vector<std::shared_ptr<ListNode>> nodes{};
    nodes.reserve(list.size());
    for (auto const& val : list) {
        nodes.emplace_back(std::make_shared<ListNode>(val));
    }
    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->next = nodes[i + 1].get();
    }
    return nodes;
}

class LeetCode_82_RemoveDuplicatesFromListII :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {};

TEST_P(LeetCode_82_RemoveDuplicatesFromListII, test1) {
    auto [input, output] = GetParam();
    auto nodes = CreateList(input);
    Solution s{};
    auto result = s.deleteDuplicates(nodes[0].get());
    for (size_t i = 0; i < output.size(); ++i) {
        ASSERT_NE(result, nullptr);
        EXPECT_EQ(result->val, output[i]);
        result = result->next;
    }
    EXPECT_EQ(result, nullptr);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_82_Suite,
                        LeetCode_82_RemoveDuplicatesFromListII,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{1,2,2},std::vector<int>{1}),
                            std::make_tuple(std::vector<int>{1,1},std::vector<int>{}),
                            std::make_tuple(std::vector<int>{1,2,3,3,4,4,5},std::vector<int>{1,2,5}),
                            std::make_tuple(std::vector<int>{1,1,1,2,3},std::vector<int>{2,3})));
