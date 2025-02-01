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
std::vector<std::shared_ptr<TreeNode>> CreateTree(T&& arr) {
    std::vector<std::shared_ptr<TreeNode>> nodes;
    for (auto&& val : arr) {
        if (val == std::numeric_limits<int>::min()) {
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

class LeetCode_236_LowestCommonAncestorOfBinaryTree :
    public ::testing::TestWithParam<std::tuple<std::vector<int>, int, int, int>> {};

TEST_P(LeetCode_236_LowestCommonAncestorOfBinaryTree, test1) {
    auto [arr, p_val, q_val, output] = GetParam();
    Solution s{};
    auto tree = CreateTree(arr);
    TreeNode* p = nullptr;
    TreeNode* q = nullptr;
    for (auto&& node : tree) {
        if (node == nullptr) {
            continue;
        }
        if (node->val == p_val) {
            p = node.get();
        }
        if (node->val == q_val) {
            q = node.get();
        }
    }
    auto result = s.lowestCommonAncestor(tree[0].get(), p, q);
    EXPECT_EQ(result->val, output);
}

constexpr int null{std::numeric_limits<int>::min()};

INSTANTIATE_TEST_SUITE_P(LeetCode_236_Suite,
                        LeetCode_236_LowestCommonAncestorOfBinaryTree,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{3,5,1,6,2,0,8,null,null,7,4}, 5, 1, 3),
                            std::make_tuple(std::vector<int>{3,5,1,6,2,0,8,null,null,7,4}, 5, 4, 5),
                            std::make_tuple(std::vector<int>{1,2}, 1, 2, 1),
                            std::make_tuple(std::vector<int>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}, 4, 5, 2)));
