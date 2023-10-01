/**
 * Copyright
 * A min/max-heap is a complete binary tree (that is, totally filled other than
 * rightmost elements on the last level) where each node is smaller/larger than
 * its children.
 */

#ifndef BINARYTREE_BINARY_HEAP_HPP_
#define BINARYTREE_BINARY_HEAP_HPP_

#include <functional>
#include <initializer_list>
#include <optional>
#include <queue>
#include <utility>
#include <vector>

template <typename T>
class BinaryHeap {
 public:
  enum class ChildType : size_t { Left = 1, Right = 2 };
  using Compare = std::function<bool(T&, T&)>;
  // default is min-heap
  BinaryHeap(std::initializer_list<T> arr = {},
             Compare compare = [](T& a, T& b) { return a < b; })
      : arr_{arr}, compare_{compare} {}

  std::optional<size_t> GetParentIndex(size_t child_index) {
    if (child_index < 1) {
      return std::nullopt;
    }
    return (child_index - 1) / 2;
  }

  std::optional<size_t> GetChildIndex(size_t parent_index, ChildType child) {
    const size_t child_index{2 * parent_index + static_cast<size_t>(child)};
    if (child_index >= arr_.size()) {
      return std::nullopt;
    }
    return child_index;
  }

  std::optional<size_t> GetLeftIndex(size_t parent_index) {
    return GetChildIndex(parent_index, ChildType::Left);
  }

  std::optional<size_t> GetRightIndex(size_t parent_index) {
    return GetChildIndex(parent_index, ChildType::Right);
  }

  std::optional<std::reference_wrapper<T>> GetLeft(size_t parent_index) {
    return GetChild(parent_index, ChildType::Left);
  }

  std::optional<std::reference_wrapper<T>> GetRight(size_t parent_index) {
    return GetChild(parent_index, ChildType::Right);
  }

  std::optional<std::reference_wrapper<T>> GetChild(size_t parent_index,
                                                    ChildType child) {
    const auto child_index = GetChildIndex(parent_index, child);
    if (!child_index.has_value()) {
      return std::nullopt;
    }
    return arr_[child_index.value()];
  }

  std::optional<std::reference_wrapper<T>> GetParent(size_t child_index) {
    const auto parent_index = GetParentIndex(child_index);
    if (!parent_index.has_value()) {
      return std::nullopt;
    }
    return arr_[parent_index.value()];
  }

  using Visit = std::function<bool(size_t)>;
  void BreadthFirstSearch(size_t node_index, Visit const& operation) {
    std::queue<size_t> qu;
    qu.push(node_index);
    while (!qu.empty()) {
      auto nd = qu.front();
      qu.pop();
      if (!operation(nd)) {
        return;
      }
      if (GetLeft(nd).has_value()) {
        qu.push(GetLeftIndex(nd).value());
      }
      if (GetRight(nd).has_value()) {
        qu.push(GetRightIndex(nd).value());
      }
    }
  }

  template <typename W>
  void Insert(W&& new_element) {
    const size_t inserted_index{arr_.size()};
    arr_.emplace_back(new_element);
    BubbleUp(inserted_index);
  }

  void BubbleUp(size_t index) {
    auto const parent_index = GetParentIndex(index);
    if (!parent_index.has_value()) {
      return;
    }
    auto const parent = parent_index.value();
    if (compare_(arr_[parent], arr_[index])) {
      return;
    }
    std::swap(arr_[parent], arr_[index]);
    BubbleUp(parent);
  }

  T Extract() {
    auto temp{arr_.front()};
    std::swap(arr_.front(), arr_.back());
    arr_.pop_back();
    BubbleDown(0);
    return temp;
  }

  void BubbleDown(size_t index) {
    if (arr_.size() < 2) {
      return;
    }
    ChildType compare_child{ChildType::Right};
    if (!GetRight(index).has_value() && !GetLeft(index).has_value()) {
      return;  // no child
    } else if (!GetRight(index).has_value()) {
      compare_child = ChildType::Left;
    } else if (!GetLeft(index).has_value()) {
      compare_child = ChildType::Right;
    } else if (compare_(GetLeft(index).value(), GetRight(index).value())) {
      compare_child = ChildType::Left;
    }
    if (!compare_(arr_[index], GetChild(index, compare_child).value())) {
      std::swap(arr_[index], GetChild(index, compare_child).value().get());
      BubbleDown(GetChildIndex(index, compare_child).value());
    }
  }

  std::vector<T> arr_;
  Compare compare_;
};

#endif  // BINARYTREE_BINARY_HEAP_HPP_
