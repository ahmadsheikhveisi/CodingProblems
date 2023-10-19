/**
 * Copyright
 * You are given a binary tree in which each node contains an integer value
 * (which might be positive or negative). Design an algorithm to count the
 * number of paths that sum to a given value. The path does not need to start or
 * end at the root or a leaf, but it must go downwards (taveling only from
 * parent to child nodes).
 */

#ifndef CRACKING_4_12_PATHWITHSUM_SOLUTION_HPP_
#define CRACKING_4_12_PATHWITHSUM_SOLUTION_HPP_

#include <algorithm>
#include <list>
#include <memory>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "binary_search_tree.hpp"
#include "binary_tree.hpp"

class Solution {
 public:
  using NodePtr = std::shared_ptr<BinaryTree<int32_t>::Node>;
  // time complexity is O(N LogN)
  size_t CountPathWithSum(NodePtr node, int32_t sum) {
    if (node == nullptr) {
      return 0;
    }
    // std::cout << "Start form here " << node->value_ << ' ';
    auto const start_from_here = CountPathWithSumSubTree(node, sum);
    // std::cout << ' ' << start_from_here;
    auto const all_left = CountPathWithSum(node->left_, sum);
    // std::cout << " All left " << all_left;
    auto const all_right = CountPathWithSum(node->right_, sum);
    // std::cout << " All right " << all_right << '\n';
    size_t res{start_from_here + all_left + all_right};
    // std::cout << node->value_ << ' ' << res << '\n';

    return res;
  }

  size_t CountPathWithSumOpt(NodePtr node, int32_t sum) {
    std::unordered_map<int32_t, size_t> mp{};
    return CountPathWithSumOptRec(node, sum, 0, mp);
  }

 private:
  size_t CountPathWithSumOptRec(
      NodePtr node, int32_t target_sum, int32_t running_sum,
      std::reference_wrapper<std::unordered_map<int32_t, size_t>> rmp) {
    auto& mp = rmp.get();
    if (node == nullptr) {
      return 0;
    }
    running_sum += node->value_;
    auto sum = running_sum - target_sum;
    size_t total_path{0};
    if (mp.find(sum) != end(mp)) {
      total_path = mp[sum];
    }
    if (running_sum == target_sum) {
      ++total_path;
    }
    ++mp[running_sum];
    total_path +=
        CountPathWithSumOptRec(node->left_, target_sum, running_sum, rmp);
    total_path +=
        CountPathWithSumOptRec(node->right_, target_sum, running_sum, rmp);
    DecrementHashMap(rmp, running_sum);
    return total_path;
  }

  void DecrementHashMap(
      std::reference_wrapper<std::unordered_map<int32_t, size_t>> rmp,
      int32_t key) {
    auto& mp = rmp.get();
    if (mp.find(key) != end(mp)) {
      --mp[key];
      if (mp[key] == 0) {
        mp.erase(key);
      }
    }
  }

  size_t CountPathWithSumSubTree(NodePtr node, int32_t sum) {
    if (node == nullptr) {
      return 0;
    }
    if (sum == node->value_) {
      return 1;
    }
    return CountPathWithSumSubTree(node->left_, sum - node->value_) +
           CountPathWithSumSubTree(node->right_, sum - node->value_);
  }
};

#endif  // CRACKING_4_12_PATHWITHSUM_SOLUTION_HPP_
