/* COPYRIGHT
*/

#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <algorithm>
#include <ranges>
#include <utility>

namespace SortAlgorithm {
class QuickSort {
 public:
    /// @brief Quick sort algorithm using Hoare's Partition Algorithm
    ///     Time complexity: O(n log n)
    ///     Space complexity: O(log n)
    ///     if the input is already sorted, the best case time complexity is O(n log n)
    ///     if the input is sorted in reverse order, the worst case time complexity is O(n^2)
    ///     number of swaps is O(n log n), best case is O(0)
    ///     number of comparisons is O(n log n), best case is O(n log n)
    /// @param range 
    static void Sort(std::ranges::range auto& range) {
        if (std::distance(begin(range), end(range)) < 2) {
            return;
        }
        //Print(range);
        QuickSortHelper(range, 0, std::distance(begin(range), end(range))-1);
        //std::cout << "----------" << std::endl;
    }

 private:
    /// @brief This function is a helper function for QuickSort
    /// @param range 
    /// @param low 
    /// @param high 
    static void QuickSortHelper(std::ranges::range auto& range, size_t low, size_t high) {
        if (low < high) {
            size_t pivot{Partition(range, low, high)};
            //Print(range);
            if (pivot > 0) {
                QuickSortHelper(range, low, pivot - 1);
            }
            QuickSortHelper(range, pivot + 1, high);
        }
    }
    /// @brief This function partitions the range into two parts.
    ///    The left part is less than or equal to the pivot. The right part is greater than the pivot.
    ///    The pivot is the first element in the range.
    ///    Time complexity: O(n)
    ///    Space complexity: O(1)
    /// @param range 
    /// @param low 
    /// @param high 
    /// @return 
    static size_t Partition(std::ranges::range auto& range, size_t low, size_t high) {
        auto pivot_value = *(std::next(begin(range), low));
        size_t low_cnt = low + 1;
        size_t high_cnt = high;

        while (low_cnt <= high_cnt) {
            while ((low_cnt <= high_cnt) && (*(std::next(begin(range), low_cnt)) <= pivot_value)) {
                ++low_cnt;
            }
            while ((low_cnt <= high_cnt) && (*(std::next(begin(range), high_cnt)) > pivot_value)) {
                --high_cnt;
            }
            if (low_cnt < high_cnt) {
                std::iter_swap(std::next(begin(range), low_cnt), std::next(begin(range), high_cnt));
            }
        }
        std::iter_swap(std::next(begin(range), low), std::next(begin(range), high_cnt));
        return high_cnt;
    }

    static void Print(std::ranges::range auto& range) {
        for (const auto& elem : range) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

} // namespace SortAlgorithm
#endif // QUICK_SORT_HPP