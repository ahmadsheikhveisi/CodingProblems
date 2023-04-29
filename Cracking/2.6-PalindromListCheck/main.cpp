/* COPYRIGHT
 * You have two numbers represented by a linked list. where each node contains a
 * single digit.The digits are stored in a reverse order, such that the 1's
 * digit is at the head of the list. Write a function that adds the two numbers
 * and returns the sum as a linked list.
 * Example:
 * Input: 7->1->6 + 5->9->2 (617+295)
 * Output: 2->1->9
 *
 * Follow Up:
 * Suppose the digits are stored in forward order. Repeat the problem.
 * Input: 6->1->7 + 2->9->5 (617+295)
 * Output: 9->1->2
 *
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
 *
 * inlining the ostream& operator<<(ostream& out, classtemplate) is the best
 * way.
 *
 * structured binding auto [a, b] = std::tuple
 * to use current variables: std::tie(a,b, _) = std::tuple
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

#include "singly_linked_list.hpp"

template <typename T>
bool PlindromeListCheckOnSpace(LinkedList<T> const& lst) {
  LinkedList<T> mirror;
  auto fast_runner = lst.front;
  auto slow_runner = lst.front;
  while (fast_runner != nullptr && fast_runner->next != nullptr) {
    mirror.insert(mirror.front, slow_runner->data);
    slow_runner = slow_runner->next;
    fast_runner = fast_runner->next->next;
  }
  if (fast_runner != nullptr) {  // this means size is odd
    slow_runner = slow_runner->next;
  }

  auto mirner = mirror.front;
  while (mirner != nullptr) {
    if (mirner->data != slow_runner->data) {
      return false;
    }
    mirner = mirner->next;
    slow_runner = slow_runner->next;
  }

  return true;
}

template <typename T>
using Nodeptr = std::shared_ptr<typename LinkedList<T>::Node>;

template <typename T>
std::tuple<bool, Nodeptr<T>> NodePlindCheckRec(Nodeptr<T> cur, size_t size,
                                               size_t cnt) {
  if (cnt == ((size / 2) - 1)) {
    if ((size & 0x1) == 0x0) {
      return {(cur->data == cur->next->data), cur->next->next};
    }
    return {(cur->data == cur->next->next->data), cur->next->next->next};
  }
  auto [eq, oth] = NodePlindCheckRec<T>(cur->next, size, ++cnt);
  eq = eq && (oth->data == cur->data);
  return {eq, oth->next};
}

template <typename T>
bool PlindromeListCheckRec(LinkedList<T> const& lst) {
  bool res{true};
  if (lst.size() > 1) {
    std::tie(res, std::ignore) = NodePlindCheckRec<T>(lst.front, lst.size(), 0);
  }
  return res;
}

int main() {
  std::vector<LinkedList<int>> testlist{{7, 1, 6, 6, 1, 7},
                                        {5, 9, 2, 3, 2, 9, 5},
                                        {5, 9, 2, 3, 2, 9, 1},
                                        {5, 9, 2, 3, 7, 9, 5},
                                        {5, 9, 2, 3, 1, 5}};
  for (auto& lst : testlist) {
    std::cout << lst;
    std::cout << "On=" << PlindromeListCheckOnSpace(lst) << '\n';
    std::cout << "On=" << PlindromeListCheckRec(lst) << '\n';
    std::cout << '\n';
  }
  return 0;
}
