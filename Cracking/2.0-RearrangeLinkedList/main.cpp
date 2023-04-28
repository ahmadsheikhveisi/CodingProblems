/* COPYRIGHT
 * Suppose you have a linked list a1->a2->...->an->b1->b2...->bn
 * write a function to rearrange it into
 * a1->b1->a2->b2->...->an->bn. the length of the list is even.
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
void RearrangeList(std::list<T>* plist) {
  if ((plist == nullptr) || ((plist->size() & 0x1) != 0)) {
    return;
  }
  auto p1 = std::next(plist->begin(), plist->size() / 2);
  auto p2 = std::next(plist->begin());
  while (p1 != plist->end()) {
    // std::cout << *p1 << ' ' << *p2 << '|';
    p2 = plist->insert(p2, *p1);
    p2 = std::next(p2, 2);
    p1 = std::next(p1);
    // printCon(*plist);
  }
  plist->erase(std::next(p2, -1), p1);
}

int main() {
  std::vector<std::list<int>> testlist{{1, 3, 5, 7, 9, 2, 4, 6, 8, 0}};
  for (auto& test : testlist) {
    printCon(test);
    RearrangeList(&test);
    printCon(test);
  }
  return 0;
}
