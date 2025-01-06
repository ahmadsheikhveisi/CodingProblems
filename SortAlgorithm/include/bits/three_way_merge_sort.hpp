/* COPYRIGHT
*/

#ifndef THREE_WAY_MERGE_SORT_HPP
#define THREE_WAY_MERGE_SORT_HPP

#include <ranges>
#include <algorithm>
#include <utility>
#include <iostream>

namespace SortAlgorithm {
class ThreeWayMergeSort {
 public:
    static void Sort(std::ranges::range auto&& range) {
        auto const n = std::distance(std::begin(range), std::end(range));
        if (n <= 1) {
            return;
        }
        auto const mid1_index = n / 3;
        auto const mid2_index = 2 * n / 3;
        auto mid1_iter = std::next(std::begin(range), mid1_index);
        auto mid2_iter = std::next(std::begin(range), mid2_index);
        
        // Create subranges and pass them to the Sort function by reference
        auto subrange1 = range | std::views::take(mid1_index); // std::ranges::subrange(std::begin(range), mid1_iter);
        auto subrange2 = std::ranges::subrange(mid1_iter, mid2_iter);
        auto subrange3 = range | std::views::drop(mid2_index); //std::ranges::subrange(mid2_iter, std::end(range));
        
        ThreeWayMergeSort::Sort(std::ranges::subrange(std::begin(range), mid1_iter));
        ThreeWayMergeSort::Sort(std::ranges::subrange(mid1_iter, mid2_iter));
        ThreeWayMergeSort::Sort(std::ranges::subrange(mid2_iter, std::end(range)));
        //std::inplace_merge(std::begin(range), mid1_iter, mid2_iter);
        //std::inplace_merge(mid1_iter, mid2_iter, std::end(range));

        // Merge the subranges
        std::vector<typename std::ranges::range_value_t<decltype(range)>> temp{};
        auto it1 = std::begin(subrange1);
        auto it2 = std::begin(subrange2);
        auto it3 = std::begin(subrange3);
        while (it1 != std::end(subrange1) && it2 != std::end(subrange2) && it3 != std::end(subrange3)) {
            if (*it1 < *it2) {
                if (*it1 < *it3) {
                    temp.push_back(*it1);
                    std::advance(it1, 1);
                } else {
                    temp.push_back(*it3);
                    std::advance(it3, 1);
                }
            } else {
                if (*it2 < *it3) {
                    temp.push_back(*it2);
                    std::advance(it2, 1);
                } else {
                    temp.push_back(*it3);
                    std::advance(it3, 1);
                }
            }
        }
        while (it1 != std::end(subrange1) && it2 != std::end(subrange2)) {
            if (*it1 < *it2) {
                temp.push_back(*it1);
                std::advance(it1, 1);
            } else {
                temp.push_back(*it2);
                std::advance(it2, 1);
            }
        }
        while (it1 != std::end(subrange1) && it3 != std::end(subrange3)) {
            if (*it1 < *it3) {
                temp.push_back(*it1);
                std::advance(it1, 1);
            } else {
                temp.push_back(*it3);
                std::advance(it3, 1);
            }
        }
        while (it2 != std::end(subrange2) && it3 != std::end(subrange3)) {
            if (*it2 < *it3) {
                temp.push_back(*it2);
                std::advance(it2, 1);
            } else {
                temp.push_back(*it3);
                std::advance(it3, 1);
            }
        }
        while (it1 != std::end(subrange1)) {
            temp.push_back(*it1);
            std::advance(it1, 1);
        }
        while (it2 != std::end(subrange2)) {
            temp.push_back(*it2);
            std::advance(it2, 1);
        }
        while (it3 != std::end(subrange3)) {
            temp.push_back(*it3);
            std::advance(it3, 1);
        }
        std::copy(std::begin(temp), std::end(temp), std::begin(range));

    }

 private:
};
}  // namespace SortAlgorithm
#endif // THREE_WAY_MERGE_SORT_HPP
