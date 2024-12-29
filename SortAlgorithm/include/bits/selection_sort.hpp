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
    ///     number of swaps is O(n), best case is O(0)
    ///     number of comparisons is O(n^2), best case is O(n^2)
    /// @param range 
    static constexpr void Sort(std::ranges::range auto& range) {
        if (std::distance(begin(range), end(range)) < 2) {
            return;
        }
        for (auto iter = begin(range); std::next(iter) != end(range); std::advance(iter, 1)) {
            auto i = std::distance(begin(range), iter);
            auto min_iter = std::ranges::min_element(range | std::views::drop(i + 1));
            if (*min_iter < *iter) {
                std::iter_swap(iter, min_iter);
            }
        }
    }
 private:
};
} // namespace SortAlgorithm
#endif // SELECTION_SORT_HPP
