/* COPYRIGHT
*/

#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <ranges>

namespace SortAlgorithm {
class InsertionSort {
public:
    /// @brief Insertion sort algorithm
    ///     Time complexity: O(n^2)
    ///     Space complexity: O(1)
    ///     if the input is already sorted, the best case time complexity is O(n)
    ///     if the input is sorted in reverse order, the worst case time complexity is O(n^2)
    ///     number of swaps is O(n^2), best case is O(0)
    ///     number of comparisons is O(n^2), best case is O(n)
    /// @param arr 
    static void Sort(std::ranges::range auto& arr) {
        if (std::distance(begin(arr), end(arr)) < 2) {
            return;
        }
        for (auto iter = std::next(begin(arr)); iter != end(arr); std::advance(iter, 1)) {
            auto key = *iter;
            // auto j = std::prev(iter);
            auto j = std::next(begin(arr), std::distance(begin(arr), iter)-1);
            // Move elements of arr[0..i-1], that are
            // greater than key, to one position ahead
            // of their current position
            while (j != begin(arr) && *j > key) {
                *(std::next(j)) = *j;
                // j = std::prev(j);
                j = std::next(begin(arr), std::distance(begin(arr), j)-1);
            }
            // Special case for the first element
            if (j == arr.begin() && *j > key) {
                *(std::next(j)) = *j;
                *j = key;
            } else {
                *(std::next(j)) = key;
            }
        }
    }
};

} // namespace SortAlgorithm
#endif // INSERTION_SORT_HPP
