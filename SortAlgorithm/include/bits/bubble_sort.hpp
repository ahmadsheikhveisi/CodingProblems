/* COPYRIGHT
*/

#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <algorithm>
#include <ranges>
#include <utility>

#include <iostream>

namespace SortAlgorithm {
class BubbleSort {
 public:
    /// @brief Bubble sort algorithm
    ///     Time complexity: O(n^2)
    ///     Space complexity: O(1)
    ///     if the input is already sorted, the best case time complexity is O(n)
    ///     if the input is sorted in reverse order, the worst case time complexity is O(n^2)
    /// @param range 
    static constexpr void Sort(std::ranges::range auto& range) {
        for (auto i : std::views::iota(0u, range.size())) {
            bool swapped = false;
            for (auto j = range.begin(); j != std::prev(range.end(), i + 1); std::advance(j, 1)) {
                auto j_next = std::next(j);
                if (*j > *j_next) {
                    std::swap(*j, *j_next);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
 private:
};
} // namespace SortAlgorithm
#endif // BUBBLE_SORT_HPP
