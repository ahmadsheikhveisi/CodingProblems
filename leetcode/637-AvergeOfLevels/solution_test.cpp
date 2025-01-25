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

class LeetCode_637_AvergeOfLevels : public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<double>>> {};

TEST_P(LeetCode_637_AvergeOfLevels, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto tree = CreateTree(arr);
    auto result = s.avergeOfLevels(tree[0].get());
    EXPECT_EQ(result, output);
}

constexpr int null{std::numeric_limits<int>::min()};

INSTANTIATE_TEST_SUITE_P(LeetCode_637_Suite,
                        LeetCode_637_AvergeOfLevels,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{3,9,20,null,null,15,7}, std::vector<double>{3.0, 14.5, 11.0}),
                            std::make_tuple(std::vector<int>{3,9,20,15,7}, std::vector<double>{3.0, 14.5, 11.0})));
