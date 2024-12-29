#include <array>
#include <list>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <ranges>
#include <forward_list>
#include <deque>

#include "gtest/gtest.h"
#include "sorting_algorithms.hpp"

namespace {

constexpr std::initializer_list<int> unsorted_arr {64, 34, 25, 12, 22, 11, 90};
constexpr std::initializer_list<int> sorted_arr {11, 12, 22, 25, 34, 64, 90};
constexpr std::initializer_list<int> reversed_sorted_arr {90, 64, 34, 25, 22, 12, 11};

constexpr std::initializer_list<int> empty_arr {};
constexpr std::initializer_list<int> size_one_arr {1};
constexpr std::initializer_list<int> all_equal_arr {1, 1, 1, 1, 1, 1, 1};

template <typename T>
class SortingAlgorithmsTest : public ::testing::Test {};

using SortAlgorithmsTestingTypes = ::testing::Types<SortAlgorithm::BubbleSort,
        SortAlgorithm::InsertionSort, SortAlgorithm::SelectionSort, SortAlgorithm::MergeSort>;

template <typename... Ts>
struct TypeList {};

template <size_t N>
using ContainersLists = TypeList<std::array<int, N>,
                                std::list<int>,
                                std::vector<int>,
                                std::forward_list<int>,
                                std::deque<int>>;


TYPED_TEST_SUITE_P(SortingAlgorithmsTest);

template <typename T>
struct GetContainer {
    T operator()(std::initializer_list<int> arr) {
        return T{arr};
    }
};

template <size_t N>
struct GetContainer<std::array<int, N>> {
    std::array<int, N> operator()(std::initializer_list<int> in_arr) {
        std::array<int, N> arr_copy{};
        std::copy(in_arr.begin(), in_arr.end(), arr_copy.begin());
        return arr_copy;
    }
};

/*template <typename T>
T GetContainer(std::initializer_list<int> in_arr) {
    return T{in_arr};
}
template <>
std::array<int, unsorted_arr_size> GetContainer<std::array<int, unsorted_arr_size>>(std::initializer_list<int> in_arr) {
    std::array<int, unsorted_arr_size> arr_copy{};
    std::copy(in_arr.begin(), in_arr.end(), arr_copy.begin());
    return arr_copy;
}*/

// Helper to process each type in the list
template <typename T, class U>
void ProcessType(U u, std::initializer_list<int> in_arr,
                std::initializer_list<int> exp_arr) {
    //std::cout << typeid(T).name() << std::endl;
    auto temp_arr = GetContainer<T>{}(in_arr);
    T input_arr{temp_arr};
    u.Sort(input_arr);
    T expexted_arr{GetContainer<T>{}(exp_arr)};
    EXPECT_EQ(input_arr, expexted_arr);
}

// Function to process all types in the list
template <typename... Ts, class U>
void ProcessTypeList(TypeList<Ts...>, U u, std::initializer_list<int> in_arr
                    , std::initializer_list<int> exp_arr) {
    (ProcessType<Ts>(u, in_arr, exp_arr), ...); // Fold expression to call ProcessType for each type
}

TYPED_TEST_P(SortingAlgorithmsTest, SortsArray) {
    ProcessTypeList(ContainersLists<unsorted_arr.size()>{}, TypeParam{}, unsorted_arr, sorted_arr);
}

TYPED_TEST_P(SortingAlgorithmsTest, SortsSortedArray) {
    ProcessTypeList(ContainersLists<sorted_arr.size()>{}, TypeParam{}, sorted_arr, sorted_arr);
    //std::array arr_copy = sorted_arr;
    //TypeParam::Sort(arr_copy);
    //EXPECT_EQ(arr_copy, sorted_arr);
}

TYPED_TEST_P(SortingAlgorithmsTest, SortsReversedSortedArray) {
    ProcessTypeList(ContainersLists<reversed_sorted_arr.size()>{}, TypeParam{}, reversed_sorted_arr, sorted_arr);
    //std::array arr_copy = reversed_sorted_arr;
    //TypeParam::Sort(arr_copy);
    //EXPECT_EQ(arr_copy, sorted_arr);
}

TYPED_TEST_P(SortingAlgorithmsTest, SortsEmptyArray) {
    ProcessTypeList(ContainersLists<empty_arr.size()>{}, TypeParam{}, empty_arr, empty_arr);
}

TYPED_TEST_P(SortingAlgorithmsTest, SortsSizeOneArray) {
    ProcessTypeList(ContainersLists<size_one_arr.size()>{}, TypeParam{}, size_one_arr, size_one_arr);
}

TYPED_TEST_P(SortingAlgorithmsTest, SortsAllEqualArray) {
    ProcessTypeList(ContainersLists<all_equal_arr.size()>{}, TypeParam{}, all_equal_arr, all_equal_arr);
}

REGISTER_TYPED_TEST_SUITE_P(SortingAlgorithmsTest,
        SortsArray,
        SortsSortedArray,
        SortsReversedSortedArray,
        SortsEmptyArray,
        SortsSizeOneArray,
        SortsAllEqualArray
);

INSTANTIATE_TYPED_TEST_SUITE_P(SortAlgorithms,
        SortingAlgorithmsTest,
        SortAlgorithmsTestingTypes
);

}  // namespace

