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

template <typename T>
std::vector<std::shared_ptr<Node>> CreateTree(T&& arr) {
    std::vector<std::shared_ptr<Node>> nodes;
    for (auto&& val : arr) {
        if (val == std::numeric_limits<int>::min()) {
            nodes.push_back(nullptr);
        } else {
            nodes.push_back(std::make_shared<Node>(val));
        }
    }
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i] == nullptr) {
            continue;
        }
        if (2*i+1 < nodes.size()) {
            nodes[i]->left = nodes[2*i+1].get();
        }
        if (2*i+2 < nodes.size()) {
            nodes[i]->right = nodes[2*i+2].get();
        }
    }
    return nodes;
}

class LeetCode_117_PopulatingNextRightPointersInEachNodeII : public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {};

TEST_P(LeetCode_117_PopulatingNextRightPointersInEachNodeII, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto tree = CreateTree(arr);
    auto result = s.connect(tree[0].get());
    std::vector<int> res{};
    while (result != nullptr) {
        auto node = result;
        while (node != nullptr) {
            res.push_back(node->val);
            node = node->next;
        }
        res.push_back(std::numeric_limits<int>::min());
        result = result->left;
    }
    ASSERT_EQ(res, output);
}

constexpr int null{std::numeric_limits<int>::min()};

INSTANTIATE_TEST_SUITE_P(LeetCode_117_Suite,
                        LeetCode_117_PopulatingNextRightPointersInEachNodeII,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{0,2,4,1,null,3,-1,5,1,null,null,null,6,null,8}, std::vector<int>{0,null,2,4,null,1,3,-1,null,5,1,6,8,null}),
                            std::make_tuple(std::vector<int>{1,2,3,4,null,null,5}, std::vector<int>{1,null,2,3,null,4,5,null}),
                            std::make_tuple(std::vector<int>{1,2,3,4,5,null,7}, std::vector<int>{1,null,2,3,null,4,5,7,null}),
                            std::make_tuple(std::vector<int>{null}, std::vector<int>{})));
