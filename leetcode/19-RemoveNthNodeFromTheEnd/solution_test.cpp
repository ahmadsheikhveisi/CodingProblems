/* COPYRIGHT
*/

#include "solution.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <initializer_list>
#include <vector>

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

class LeetCode_19_RemoveNthNodeFromTheEnd :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int,
        std::vector<int>>> {};

TEST_P(LeetCode_19_RemoveNthNodeFromTheEnd, test1) {
    auto [input, n, output] = GetParam();
    Solution s{};
    auto nodes = CreateList(input);
    auto head = nodes[0].get();
    auto result = s.removeNthFromEnd(head, n);
    auto expected_nodes = CreateList(output);
    auto expected = expected_nodes[0].get();
    while (result != nullptr && expected != nullptr) {
        EXPECT_EQ(result->val, expected->val);
        result = result->next;
        expected = expected->next;
    }
    EXPECT_EQ(result, expected);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_19_RemoveNthNodeFromTheEndSuite,
                        LeetCode_19_RemoveNthNodeFromTheEnd,
                        ::testing::Values(std::make_tuple(std::vector<int>{1, 2, 3, 4, 5}, 2,
                            std::vector<int>{1, 2, 3, 5}),
                            std::make_tuple(std::vector<int>{1}, 1,
                            std::vector<int>{}),
                            std::make_tuple(std::vector<int>{1, 2}, 1,
                            std::vector<int>{1}),
                            std::make_tuple(std::vector<int>{1, 2}, 2,
                            std::vector<int>{2})));
