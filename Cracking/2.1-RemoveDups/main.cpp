/* COPYRIGHT
 * Write cde to remove duplicates from an unsorted linked list.
 *
 * How would you solve this proble if a temporary buffer is not allowed.
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
void RemoveDupsHash(std::list<T>* plist) {
  if ((plist == nullptr) || (plist->size() < 2)) {
    return;
  }
  auto p1 = plist->begin();
  std::unordered_set<T> hash;
  while (p1 != plist->end()) {
    if (hash.find(*p1) == end(hash)) {
      hash.insert(*p1);
    } else {
      p1 = plist->erase(p1);
    }
    p1 = std::next(p1);
  }
}

template <typename T>
void RemoveDupsO1Space(std::list<T>* plist) {
  if ((plist == nullptr) || (plist->size() < 2)) {
    return;
  }
  auto p1 = begin(*plist);
  while (p1 != end(*plist)) {
    auto p2 = std::next(p1);
    while (p2 != end(*plist)) {
      if (*p2 == *p1) {
        p2 = plist->erase(p2);
      } else {
        p2 = std::next(p2);
      }
    }
    p1 = std::next(p1);
  }
}

int main() {
  std::vector<std::list<int>> testlist{{1, 3, 5, 3, 9, 2, 5, 6, 1, 0}};
  for (auto& test : testlist) {
    printCon(test);
    RemoveDupsHash(&test);
    printCon(test);
  }
  return 0;
}
