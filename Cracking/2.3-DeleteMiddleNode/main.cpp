/* COPYRIGHT
 * Implement an algorithm to delete a node in the middle (i.e. any node but the
 * first and last node, no necessarily the exact middle) of the singly linked
 * list. given only access to that node. No access to the head of the list.
 * Example: Input: the node c from the linked list a->b->c->d->e->f Result:
 * nothing is returned. but the new linked list looks like a->b->d->e->f
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
void printCon(const T& vec) {
  for (const auto& num : vec) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
}

template <typename T>
void DeleteMiddleNode(LinkedList<T>* lst,
                      std::shared_ptr<typename LinkedList<T>::Node> pos) {
  if ((pos == nullptr) || (pos->next == nullptr)) {
    return;
  }
  // we need access to front, otherwise front will be modified.
  if (lst->front == pos) {
    return;
  }
  pos->data = pos->next->data;
  pos->next = pos->next->next;
}

int main() {
  std::vector<LinkedList<int>> testlist{{1, 3, 5, 3, 9, 2, 5, 6, 1, 7}};
  for (auto& test : testlist) {
    std::cout << test;
    DeleteMiddleNode(&test, test.front);
    DeleteMiddleNode(&test, test.front->next);
    DeleteMiddleNode(&test, test.front->next->next);
    auto back = test.front;
    while (back->next != nullptr) {
      back = back->next;
    }
    DeleteMiddleNode(&test, back);
    std::cout << test;
  }
  return 0;
}
