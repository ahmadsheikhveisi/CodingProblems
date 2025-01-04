/* COPYRIGHT
*/

#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <functional>
#include <initializer_list>
#include <optional>
#include <queue>
#include <utility>
#include <vector>

namespace SortAlgorithm {
class HeapSort {
 public:
    /// @brief Heap sort algorithm
    ///     Time complexity: O(n log n)
    ///     Space complexity: O(1)
    ///     The heapify function has a time complexity of O(log n)
    ///     The heapify function is called n times, so the time complexity is O(n log n)
    ///     The space complexity is O(1) because the heapify function is done in place
    ///     The number of comparisons is O(n log n), the best case is O(n log n)
    ///     The number of swaps is O(n log n), the best case is O(n log n)
    /// @param range 
    static void Sort(std::ranges::range auto& range) {
        /* Solution using std::priority_queue and O(n) space complexity
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq{};
        for (auto elem : range) {
            pq.push(elem);
        }
        for (auto& elem : range) {
            elem = pq.top();
            pq.pop();
        }*/
        const ssize_t n{std::distance(std::begin(range), std::end(range))};
        if (n < 2) {
            return;
        }
        // start from the most right non-leaf node
        for (ssize_t i{n / 2 - 1}; i >= 0; i--) {
            Heapify(range, n, i);
        }
        for (auto i = n - 1; i > 0; i--) {
            std::iter_swap(std::next(begin(range), 0), std::next(begin(range), i));
            // the size of the heap is i because the rest of elements are already sorted
            Heapify(range, i, 0);
        }
    }
 private:
    static void Heapify(std::ranges::range auto& range, ssize_t n, ssize_t root) {
        ssize_t largest_index{root};
        ssize_t left_child_index{2 * root + 1};
        ssize_t right_child_index{2 * root + 2};
        if ((left_child_index < n) && (*std::next(begin(range), left_child_index) >
                        *std::next(begin(range), largest_index))) {
            largest_index = left_child_index;
        }
        if ((right_child_index < n) && (*std::next(begin(range), right_child_index) >
                        *std::next(begin(range), largest_index))) {
            largest_index = right_child_index;
        }
        if (largest_index != root) {
            std::iter_swap(std::next(begin(range), root),
                           std::next(begin(range), largest_index));
            // since the subtree root is changed, we need to heapify it
            Heapify(range, n, largest_index);
        }
    }

};
}  // namespace SortAlgorithm
#endif // HEAP_SORT_HPP
