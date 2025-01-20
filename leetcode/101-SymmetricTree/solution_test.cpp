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

class LeetCode_101_SymmetricTree : public ::testing::TestWithParam<std::tuple<std::vector<int>, bool>> {};

TEST_P(LeetCode_101_SymmetricTree, test1) {
    auto [arr, output] = GetParam();
    Solution s{};
    auto tree = CreateTree(arr);
    auto result = s.isSymmetric(tree[0].get());
    EXPECT_EQ(result, output);
}


INSTANTIATE_TEST_SUITE_P(LeetCode_101_Suite,
                        LeetCode_101_SymmetricTree,
                        ::testing::Values(
                            std::make_tuple(std::vector<int>{1,2,2,3,4,4,3}, true),
                            std::make_tuple(std::vector<int>{1,2,2,std::numeric_limits<int>::min(),3,std::numeric_limits<int>::min(),3}, false)));
