/* COPYRIGHT
*/

#ifndef CYCLE_SORT_HPP
#define CYCLE_SORT_HPP

#include <vector>
#include <utility>
#include <algorithm>
#include <ranges>

namespace SortAlgorithm {
class CycleSort {
 public:
    /// @brief Cycle sort Algorithm
    ///        Time complexity: O(n^2)
    ///        Space complexity: O(1)
    ///        number of comparisons: O(n^2)
    ///        number of swaps: O(n^2)
    ///        Stable: No
    ///        Method: Selection
    ///        When to use: When memory write or swap operation is costly.
    /// @param range 
    static void Sort(std::ranges::range auto& range) {
        auto const n = std::distance(std::begin(range), std::end(range));
        for (ssize_t i = 0; i < n - 1; ++i) {
            auto item = *std::next(std::begin(range), i);
            ssize_t pos{i};
            // Find position where we put the item.
            // to do this we need to count all the elements that are less than the item
            // and they are on the right side of the item.
            for (auto j = i + 1; j < n; ++j) {
                if (*std::next(std::begin(range), j) < item) {
                    ++pos;
                }
            }
            // if pos is the same as i, then the item is already in the correct position
            if (pos == i) {
                continue;
            }
            // if not, then we need to put the item in the correct position
            while (item == *std::next(std::begin(range), pos)) {
                ++pos;
            }
            if (pos != i) {
                std::swap(item, *std::next(std::begin(range), pos));
            }
            // Rotate the rest of the cycle
            while (pos != i) {
                pos = i;
                for (auto j = i + 1; j < n; ++j) {
                    if (*std::next(std::begin(range), j) < item) {
                        ++pos;
                    }
                }
                while (item == *std::next(std::begin(range), pos)) {
                    ++pos;
                }
                if (item != *std::next(std::begin(range), pos)) {
                    std::swap(item, *std::next(std::begin(range), pos));
                }
            }
        }
    }
 private:
};
} // namespace SortAlgorithm
#endif // CYCLE_SORT_HPP
