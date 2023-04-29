/* COPYRIGHT
 * Implement an algorithm to find the kth to last element of a signly.
 * linked list.
 *
 * Note: case insensive, ignore white space.
 * Palindrome has an even occurance of all charactors, except
 * it can have only one odd occurance.
 * 00010000 - 1 = 00001111
 * 00101000 - 1 = 00100111
 *
 * count if: count the elements between two iterators that satisfy a
 * condition.
 *
 * string find returns the index and it can be npos
 *
 * Mind the end of string, when searching.
 *
 * 'remove' moves up the elements in the sequence, overwriting the element
 * you wanted removed. (find and move)
 * 'erase' overwrite the elements and resize the sequence.
 * remove-erase idiom: to remove the matching elements from the container.
 * remove is independent of the container while erase depends how the
 * data is stored.
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
void printCon(const T& vec) {
  for (const auto& num : vec) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
}

template <typename T>
T FindKthtoLastDoublyLinked(std::list<T> const& lst, size_t k) {
  if (k >= lst.size()) {
    return T();
  }
  auto pk = std::next(lst.rbegin(), k);
  return *pk;
}

template <typename T>
T FindKthtoLastSinglyLinked(std::list<T> const& lst, size_t k) {
  if (k >= lst.size()) {
    return T();
  }
  auto pk = std::next(lst.begin(), lst.size() - k - 1);
  return *pk;
}

template <typename T>
T FindKthtoLastNoSize(std::list<T> const& lst, size_t k) {
  if (k >= lst.size()) {
    return T();
  }
  auto p1 = lst.begin();
  auto p2 = std::next(p1, k + 1);
  while (p2 != lst.end()) {
    p1 = std::next(p1);
    p2 = std::next(p2);
  }
  return *p1;
}

int main() {
  std::vector<std::list<int>> testlist{{1, 3, 5, 3, 9, 2, 5, 6, 1, 7}};
  for (auto& test : testlist) {
    std::cout << FindKthtoLastNoSize(test, 0) << '\n';
  }
  return 0;
}
