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

constexpr auto null = std::numeric_limits<int>::min();

template <typename T>
std::vector<std::shared_ptr<TreeNode>> CreateTree(T&& arr) {
    std::vector<std::shared_ptr<TreeNode>> nodes;
    for (auto&& val : arr) {
        if (val == null) {
            nodes.push_back(nullptr);
        } else {
            nodes.push_back(std::make_shared<TreeNode>(val));
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

class LeetCode_103_BinaryTreeZigzagLevelOrderTraversal : public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<std::vector<int>>>> {};

TEST_P(LeetCode_103_BinaryTreeZigzagLevelOrderTraversal, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto tree = CreateTree(arr);
    auto result = s.zigzagLevelOrder(tree[0].get());
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_103_Suite,
                        LeetCode_103_BinaryTreeZigzagLevelOrderTraversal,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{3,9,20,null,null,15,7}, std::vector<std::vector<int>>{{3},{20,9},{15,7}}),
                            std::make_tuple(std::vector<int>{1}, std::vector<std::vector<int>>{{1}}),
                            std::make_tuple(std::vector<int>{null}, std::vector<std::vector<int>>{})));
