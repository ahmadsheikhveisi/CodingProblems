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

class LeetCode_23_MergeKSortedLists :
        public ::testing::TestWithParam<std::tuple<std::vector<std::vector<int>>, std::vector<int>>> {};

TEST_P(LeetCode_23_MergeKSortedLists, test1) {
    auto [nums, output] = GetParam();
    std::vector<std::vector<std::shared_ptr<ListNode>>> linked_lists{};
    for (auto const& list : nums) {
        linked_lists.push_back(CreateList(list));
    }
    std::vector<ListNode*> lists{};
    for (auto const& node : linked_lists) {
        lists.push_back(node[0].get());
    }
    Solution s{};
    auto result = s.mergeKLists(lists);
    for (auto const& val : output) {
        ASSERT_NE(result, nullptr);
        ASSERT_EQ(result->val, val);
        result = result->next;
    }
    EXPECT_EQ(result, nullptr);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_23_Suite,
                        LeetCode_23_MergeKSortedLists,
                        ::testing::Values(
                            std::make_tuple(std::vector<std::vector<int>>{{1}},
                                            std::vector<int>{1}),
                            std::make_tuple(std::vector<std::vector<int>>{{1, 4, 5}, {1, 3, 4}, {2, 6}},
                                            std::vector<int>{1, 1, 2, 3, 4, 4, 5, 6}),
                            std::make_tuple(std::vector<std::vector<int>>{},
                                            std::vector<int>{}),
                            std::make_tuple(std::vector<std::vector<int>>{{}},
                                            std::vector<int>{})));
