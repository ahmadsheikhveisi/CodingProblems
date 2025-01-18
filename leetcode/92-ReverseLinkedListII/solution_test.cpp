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

class LeetCode_92_ReverseLinkedListII :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int, int, std::vector<int>>> {};

TEST_P(LeetCode_92_ReverseLinkedListII, test1) {
    auto [input, left, right, output] = GetParam();
    auto nodes = CreateList(input);
    Solution s{};
    auto result = s.reverseBetween(nodes[0].get(), left, right);
    for (size_t i = 0; i < output.size(); ++i) {
        ASSERT_NE(result, nullptr);
        EXPECT_EQ(result->val, output[i]);
        result = result->next;
    }
    EXPECT_EQ(result, nullptr);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_92_Suite,
                        LeetCode_92_ReverseLinkedListII,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{1,2,3,4,5},2,4,std::vector<int>{1,4,3,2,5}),
                            std::make_tuple(std::vector<int>{5},1,1,std::vector<int>{5}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},1,5,std::vector<int>{5,4,3,2,1}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},1,4,std::vector<int>{4,3,2,1,5}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},2,5,std::vector<int>{1,5,4,3,2}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},3,5,std::vector<int>{1,2,5,4,3}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},3,4,std::vector<int>{1,2,4,3,5}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},2,3,std::vector<int>{1,3,2,4,5}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},1,3,std::vector<int>{3,2,1,4,5}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},4,5,std::vector<int>{1,2,3,5,4}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},4,4,std::vector<int>{1,2,3,4,5}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},5,5,std::vector<int>{1,2,3,4,5}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5},5,4,std::vector<int>{1,2,3,4,5})));
