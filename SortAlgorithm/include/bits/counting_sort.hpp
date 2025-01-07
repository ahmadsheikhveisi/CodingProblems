/* COPYRIGHT
*/

#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

#include <algorithm>
#include <ranges>

namespace SortAlgorithm {
class CountingSort {
 public:
    /// @brief Counting sort algorithm
    ///        Time complexity: O(n + k), where n is the number of elements in the input array
    ///        and k is the range of the non-negative key values.
    ///        Space complexity: O(n + k)
    ///        Stable: Yes
    ///        Sorting In Place: No
    ///        Method: Non-comparison based
    ///        When to use: When the range of input data is not significantly greater than the number of elements
    ///        and the input data is integer.
    /// @param range 
    static void Sort(std::ranges::range auto& range) {
        auto const range_size = std::distance(range.begin(), range.end());
        if (range_size < 2) {
            return;
        }
        auto [min_iter, max_iter] = std::ranges::minmax_element(range.begin(), range.end());
        auto min = *min_iter;
        auto max = *max_iter;
        size_t range_diff = max - min + 1;
        std::vector<size_t> count(range_diff, 0);
        for (auto& element : range) {
            count[element - min]++;
        }
        for (size_t i = 1; i < range_diff; i++) {
            count[i] += count[i - 1];
        }
        std::vector<typename std::ranges::range_value_t<decltype(range)>> output(range_size);
        for (auto it = range_size - 1; it >= 0; --it) {
            auto const element = *std::next(range.begin(), it);
            output[count[element - min] - 1] = element;
            count[element - min]--;
        }
        std::ranges::copy(output, range.begin());
    }
 private:
};
}
#endif // COUNTING_SORT_HPP
