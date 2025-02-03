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

class LeetCode_100_SameTree : public ::testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>, bool>> {};

TEST_P(LeetCode_100_SameTree, test1) {
    auto [arr1, arr2, output] = GetParam();
    Solution s{};
    auto p = CreateTree(arr1);
    auto q = CreateTree(arr2);
    auto result = s.isSameTree(p[0].get(), q[0].get());
    EXPECT_EQ(result, output);
}

constexpr int null{std::numeric_limits<int>::min()};

INSTANTIATE_TEST_SUITE_P(LeetCode_100_Suite,
                        LeetCode_100_SameTree,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{1,2,3}, std::vector<int>{1,2,3}, true),
                            std::make_tuple(std::vector<int>{1,2,1}, std::vector<int>{1,1,2}, false),
                            std::make_tuple(std::vector<int>{1,2}, std::vector<int>{1,null,2}, false)));
