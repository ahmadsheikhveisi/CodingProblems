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

class LeetCode_112_PathSum : public ::testing::TestWithParam<std::tuple<std::vector<int>, int, bool>> {};

TEST_P(LeetCode_112_PathSum, test1) {
    auto [arr, target, output] = GetParam();
    Solution s{};
    auto tree = CreateTree(arr);
    auto result = s.hasPathSum(tree[0].get(), target);
    EXPECT_EQ(result, output);
}

constexpr int null{std::numeric_limits<int>::min()};

INSTANTIATE_TEST_SUITE_P(LeetCode_112_Suite,
                        LeetCode_112_PathSum,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{5,4,8,11,null,13,4,7,2,null,null,null,null,null,1}, 22, true),
                            std::make_tuple(std::vector<int>{1,2,3}, 5, false),
                            std::make_tuple(std::vector<int>{null}, 0, false)));
