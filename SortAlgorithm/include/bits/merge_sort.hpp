/* COPYRIHGT
*/

#ifndef SORT_ALGORITHM_MERGE_SORT_HPP
#define SORT_ALGORITHM_MERGE_SORT_HPP

#include <algorithm>
#include <ranges>
#include <utility>
#include <vector>

namespace SortAlgorithm {

class MergeSort {
 public:
    /// @brief Merge sort algorithm
    ///     Time complexity: O(n log n)
    ///     Space complexity: O(n)
    ///     number of swaps is O(n log n)
    ///     number of comparisons is O(n log n)
    /// @param range 
    static void Sort(std::ranges::range auto& range) {
        if (std::distance(begin(range), end(range)) < 2) {
            return;
        }
        std::vector<int> temp(std::distance(begin(range), end(range)));
        MergeSortHelper(range, temp, 0, std::distance(begin(range), end(range))-1);
    }

 private:
    static void MergeSortHelper(std::ranges::range auto& range, std::vector<int>& temp, size_t low, size_t high) {
        if (low < high) {
            size_t mid{low + (high - low) / 2};
            MergeSortHelper(range, temp, low, mid);
            MergeSortHelper(range, temp, mid + 1, high);
            Merge(range, temp, low, mid, high);
        }
    }

    static void Merge(std::ranges::range auto& range, std::vector<int>& temp, size_t low, size_t mid, size_t high) {
        size_t low_cnt{low};
        size_t high_cnt{mid + 1};
        size_t temp_cnt{low};
        while ((low_cnt <= mid) && (high_cnt <= high)) {
            if (*(std::next(begin(range), low_cnt)) <= *(std::next(begin(range), high_cnt))) {
                temp[temp_cnt] = *(std::next(begin(range), low_cnt));
                ++low_cnt;
            } else {
                temp[temp_cnt] = *(std::next(begin(range), high_cnt));
                ++high_cnt;
            }
            ++temp_cnt;
        }
        while (low_cnt <= mid) {
            temp[temp_cnt] = *(std::next(begin(range), low_cnt));
            ++low_cnt;
            ++temp_cnt;
        }
        while (high_cnt <= high) {
            temp[temp_cnt] = *(std::next(begin(range), high_cnt));
            ++high_cnt;
            ++temp_cnt;
        }
        std::copy(begin(temp) + low, begin(temp) + high + 1, std::next(begin(range), low));
    }
};
    
} // namespace SortAlgorithm
#endif // SORT_ALGORITHM_MERGE_SORT_HPP