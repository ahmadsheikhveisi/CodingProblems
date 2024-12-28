#include <array>
#include <list>
#include <vector>
#include <initializer_list>

#include "gtest/gtest.h"
#include "sorting_algorithms.hpp"

namespace {

constexpr std::initializer_list<int> arr {64, 34, 25, 12, 22, 11, 90};
constexpr size_t arr_size{arr.size()};
constexpr std::initializer_list<int> sorted_arr {11, 12, 22, 25, 34, 64, 90};
constexpr std::initializer_list<int> reversed_sorted_arr {90, 64, 34, 25, 22, 12, 11};

template <typename T>
class SortingAlgorithmsTest : public ::testing::Test {

};

using SortAlgorithmsTestingTypes = ::testing::Types<SortAlgorithm::BubbleSort,
        SortAlgorithm::InsertionSort, SortAlgorithm::SelectionSort>;

template <typename... Ts>
struct TypeList {};

using ContainersLists = TypeList<std::array<int, arr_size>, std::list<int>, std::vector<int>>;


TYPED_TEST_SUITE_P(SortingAlgorithmsTest);

template <typename T>
T GetContainer(std::initializer_list<int> arr) {
    return T{arr};
}

template <>
std::array<int, arr_size> GetContainer<std::array<int, arr_size>>(std::initializer_list<int> arr) {
    std::array<int, arr_size> arr_copy;
    std::copy(arr.begin(), arr.end(), arr_copy.begin());
    return arr_copy;
}

// Helper to process each type in the list
template <typename T, class U>
void ProcessType(U u, std::initializer_list<int> arr) {
    //std::cout << typeid(T).name() << std::endl;
    T input_arr{GetContainer<T>(arr)};
    u.Sort(input_arr);
    T expexted_arr{GetContainer<T>(sorted_arr)};
    EXPECT_EQ(input_arr, expexted_arr);
}

// Function to process all types in the list
template <typename... Ts, class U>
void ProcessTypeList(TypeList<Ts...>, U u, std::initializer_list<int> arr) {
    (ProcessType<Ts>(u, arr), ...); // Fold expression to call ProcessType for each type
}

TYPED_TEST_P(SortingAlgorithmsTest, SortsArray) {
    ProcessTypeList(ContainersLists{}, TypeParam{}, arr);
}

TYPED_TEST_P(SortingAlgorithmsTest, SortsSortedArray) {
    ProcessTypeList(ContainersLists{}, TypeParam{}, sorted_arr);
    //std::array arr_copy = sorted_arr;
    //TypeParam::Sort(arr_copy);
    //EXPECT_EQ(arr_copy, sorted_arr);
}

TYPED_TEST_P(SortingAlgorithmsTest, SortsReversedSortedArray) {
    ProcessTypeList(ContainersLists{}, TypeParam{}, reversed_sorted_arr);
    //std::array arr_copy = reversed_sorted_arr;
    //TypeParam::Sort(arr_copy);
    //EXPECT_EQ(arr_copy, sorted_arr);
}

REGISTER_TYPED_TEST_SUITE_P(SortingAlgorithmsTest,
        SortsArray,
        SortsSortedArray,
        SortsReversedSortedArray
);

INSTANTIATE_TYPED_TEST_SUITE_P(SortAlgorithms,
        SortingAlgorithmsTest,
        SortAlgorithmsTestingTypes
);

}  // namespace

