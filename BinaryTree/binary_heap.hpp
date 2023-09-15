/**
 * Copyright
 */

#ifndef BINARYTREE_BINARY_HEAP_HPP_
#define BINARYTREE_BINARY_HEAP_HPP_

#include <initializer_list>
#include <optional>
#include <functional>
#include <queue>
#include <vector>



template<typename T>
class BinaryHeap {
 public:
    enum class ChildType :  size_t {
        Left = 1,
        Right = 2
    };
    using Compare = std::function<bool(T const&, T const&)>;
    // default is min-heap
    BinaryHeap(std::initializer_list<T> arr = {}, Compare compare = [](T const& a, T const& b) {return a < b;}) : arr_{arr}, compare_{compare} {}

    std::optional<size_t> GetParentIndex(size_t child_index) {
        if (child_index < 1) {
            return std::nullopt;
        }
        return (child_index - 1)/2;
    }

    std::optional<size_t> GetChildIndex(size_t parent_index, ChildType child) {
        const size_t child_index{2*parent_index + static_cast<size_t>(child)};
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

    std::optional<std::reference_wrapper<T>> GetChild(size_t parent_index, ChildType child){
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
    template<typename W>
    void Insert(W && new_element) {
        const size_t inserted_index{arr_.size()};
        arr_.emplace_back(new_element);
        ReOrderHeap(inserted_index);

    }

    void ReOrderHeap(size_t index) {
        auto const parent_index = GetParentIndex(index);
        if (!parent_index.has_value()) {
            return;
        }
        auto const parent = parent_index.value();
        if (compare_(arr_[parent], arr_[index])) {
            return;
        } 
        std::swap(arr_[parent], arr_[index]);
        ReOrderHeap(parent);
    }

    std::vector<T> arr_;
    Compare compare_;
};

#endif  // BINARYTREE_BINARY_HEAP_HPP_
