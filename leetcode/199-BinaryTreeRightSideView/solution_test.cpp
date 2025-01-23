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

class LeetCode_199_BinaryTreeRightSideView : public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {};

TEST_P(LeetCode_199_BinaryTreeRightSideView, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto tree = CreateTree(arr);
    auto result = s.rightSideView(tree[0].get());
    EXPECT_EQ(result, output);
}

constexpr int null{std::numeric_limits<int>::min()};

INSTANTIATE_TEST_SUITE_P(LeetCode_199_Suite,
                        LeetCode_199_BinaryTreeRightSideView,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{1,2,3,null,5,null,4}, std::vector<int>{1,3,4}),
                            std::make_tuple(std::vector<int>{1,2,3,4,null,null,null,5,null}, std::vector<int>{1,3,4,5}),
                            std::make_tuple(std::vector<int>{1,null,3}, std::vector<int>{1,3}),
                            std::make_tuple(std::vector<int>{null}, std::vector<int>{})));
