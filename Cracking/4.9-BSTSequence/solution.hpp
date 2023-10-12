/**
 * Copyright
 * A binary search tree was created by traversing through an array from left to
 * right and inserting each element. Given a binary search tree with distinct
 * elements, print all possible arrays that could have led to this tree.
 * input:
 *     2
 *    / \
 *   1   3
 * output:
 * {2,1,3}, {2,3,1}
 */

#ifndef CRACKING_4_9_BSTSEQUENCE_SOLUTION_HPP_
#define CRACKING_4_9_BSTSEQUENCE_SOLUTION_HPP_

#include <algorithm>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "binary_search_tree.hpp"

template <typename T>
class Solution {
 public:
  using NodePtr = std::shared_ptr<typename BinarySearchTree<T>::Node>;
  using Result = std::list<std::list<T>>;
  Result FindAllArrays(
      [[maybe_unused]] BinarySearchTree<T> bst) {
    /**
     * this methode is based on the idea that the answer is
     * the permutation of the each level. but that is not correct
     * we can insert the values from other subtrees and still
     * get the same binary tree. this solution only gives a partial
     * answer.
    Result res{};
    std::unordered_map<NodePtr, size_t> depth_map{};
    std::vector<std::vector<NodePtr>> depth_vec{};
    depth_map[bst.root_] = 0;
    size_t max_depth{0};
    res.push_back({});
    auto visitor = [&depth_map, &max_depth, &depth_vec](NodePtr node) {
      if (node != nullptr) {
        auto parent_depth = depth_map[node];
        if (node->left_ != nullptr) {
          depth_map[node->left_] = parent_depth + 1;
        }
        if (node->right_ != nullptr) {
          depth_map[node->right_] = parent_depth + 1;
        }
        max_depth = std::max(max_depth, parent_depth);
        // auto cnt = std::count_if(begin(depth_map), end(depth_map),
        // [&parent_depth](std::pair<NodePtr, size_t> pr){return pr.second ==
        // parent_depth;});
        if (depth_vec.size() <= parent_depth) {
          depth_vec.push_back({});
        }
        depth_vec[parent_depth].push_back(node);
      }
      return true;
    };
    bst.BreadthFirstSearch(bst.root_, visitor);

    for (auto& nodes : depth_vec) {
      std::vector<T> depth_vals{};
      for (auto& node : nodes) {
        depth_vals.push_back(node->value_);
      }
      std::vector<std::vector<T>> dep_perm{};
      do {
        dep_perm.push_back(depth_vals);
      } while (std::next_permutation(begin(depth_vals), end(depth_vals)));
      std::vector<std::vector<T>> new_res{};
      for (auto const& perm : dep_perm) {
        for (auto elm_res : res) {
          elm_res.insert(end(elm_res), begin(perm), end(perm));
          new_res.push_back(elm_res);
        }
      }
      res = new_res;
    }*/

    return FindAllArraysNode(bst.root_);
  }
  private:
  Result FindAllArraysNode(NodePtr node) {
    if (node == nullptr) {
      return {};
    }
    if ((node->left_ == nullptr) && (node->right_ == nullptr)) {
      return {{node->value_}};
    }
    auto left = FindAllArraysNode(node->left_);
    auto right = FindAllArraysNode(node->right_);

    auto res = CombineLeftRight(left, right);
    for (auto & vec : res) {
      vec.insert(begin(vec),node->value_);
    }
    return res;
  }

  Result CombineLeftRight(Result const& left,
                          Result const& right) {
    Result res{};

    for (auto lit = begin(left); lit != end(left); std::advance(lit, 1)) {
      for (auto rit = begin(right); rit != end(right); std::advance(rit, 1)) {
        Result temp{};
        CombineTwoContainers(temp, {}, *rit, *lit);
        for (auto const& elm : temp) {
          res.insert(end(res), elm);
        }
      }
    }
    return res;                                                
  }
  template<typename U>
  void CombineTwoContainers(Result& res, U prefix, U left, U right) {
    if (left.empty() || right.empty()) {
      for (auto const& elm : left) {
        prefix.insert(end(prefix), elm);
      }
      for (auto const& elm : right) {
        prefix.insert(end(prefix), elm);
      }
      res.insert(end(res), prefix);
      return;
    }
    prefix.insert(end(prefix), left.front());
    left.erase(begin(left));
    CombineTwoContainers(res, prefix, left, right);
    prefix.insert(end(prefix), right.front());
    right.erase(begin(right));
    CombineTwoContainers(res, prefix, left, right);
  }
  
};

#endif  // CRACKING_4_9_BSTSEQUENCE_SOLUTION_HPP_
