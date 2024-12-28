/* COPYRIGHT
*/

#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <algorithm>
#include <ranges>
#include <utility>

namespace SortAlgorithm {
class SelectionSort {
 public:
    /// @brief Selection sort algorithm
    ///     Time complexity: O(n^2)
    ///     Space complexity: O(1)
    ///     if the input is already sorted, the best case time complexity is O(n^2)
    ///     if the input is sorted in reverse order, the worst case time complexity is O(n^2)
    /// @param range 
    static constexpr void Sort(std::ranges::range auto& range) {
        if (range.size() < 2) {
            return;
        }
        for (auto i : std::views::iota(0u, range.size() - 1)) {
            auto temp_range = range | std::views::drop(i + 1);
            auto min_iter = std::ranges::min_element(temp_range);
            auto i_iter = std::next(range.begin(), i);
            if (*min_iter < *i_iter) {
                std::iter_swap(i_iter, min_iter);
            }
        }
    }
 private:
};
} // namespace SortAlgorithm
#endif // SELECTION_SORT_HPP
