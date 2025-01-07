/* COPYRIGHT
*/

#ifndef RADIX_SORT_HPP
#define RADIX_SORT_HPP

#include <algorithm>
#include <ranges>

namespace SortAlgorithm {

class RadixSort {
 public:
    /// @brief Radix sort algorithm
    ///        Time complexity: O(n * k) where k is the number of digits in the largest number
    ///        Space complexity: O(n + k)
    ///        Stable: Yes
    ///        number of swaps: O(n)
    ///        number of comparisons: O(n)
    /// @param range 
    static void Sort(std::ranges::range auto& range) {
        if (std::distance(range.begin(), range.end()) < 2) {
            return;
        }
        auto max = *std::max_element(range.begin(), range.end());
        for (int exp = 1; max / exp > 0; exp *= 10) {
            CountingSort(range, exp);
        }
    }
 private:
    static void CountingSort(std::ranges::range auto& range, int exp) {
        auto const range_size = std::distance(range.begin(), range.end());
        std::vector<int> output(range_size);
        std::vector<int> count(10, 0);

        for (auto& i : range) {
            count[(i / exp) % 10]++;
        }
        // Change count[i] so that count[i] now contains actual
        // position of this digit in output[]
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = range_size - 1; i >= 0; i--) {
            auto val = *std::next(range.begin(), i);
            auto index = (val / exp) % 10;
            auto index_count = count[index];
            output[index_count - 1] = val;
            count[index]--;
        }

        std::copy(output.begin(), output.end(), range.begin());
    }
};
} // namespace SortAlgorithm
#endif // RADIX_SORT_HPP
