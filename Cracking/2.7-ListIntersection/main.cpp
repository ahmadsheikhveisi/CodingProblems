/* COPYRIGHT
 * Given two (singly) linked lists, determine if the two lists intersect. Return
 * the intersecting node. Note that intersection is defined based on reference,
 * not value. That is, if the kth node of the linked list is the exact same node
 * (by reference) as jth node of the second linked list, then they are
 * intersecting.
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
 *
 * in linked lists, if you can use the size, you can acheive O(1) space
 * complexity. otherwise, recursion gives O(N) space complexity.
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
using Nodeptr = std::shared_ptr<typename LinkedList<T>::Node>;

template <typename T>
Nodeptr<T> FindTail(LinkedList<T> const& lst) {
  auto node = lst.front;
  if (node == nullptr) {
    return nullptr;
  }
  while (node->next != nullptr) {
    node = node->next;
  }
  return node;
}

template <typename T>
Nodeptr<T> ListIntersection(LinkedList<T> const& lst1,
                            LinkedList<T> const& lst2) {
  auto shorter = lst1.size() > lst2.size() ? lst2 : lst1;
  auto longer = lst1.size() > lst2.size() ? lst1 : lst2;
  auto ps = shorter.front;
  auto pl = longer.front;
  auto diff_size = longer.size() - shorter.size();
  while (diff_size != 0) {
    --diff_size;
    pl = pl->next;
  }
  while ((pl != ps) && (ps != nullptr) && pl != nullptr) {
    pl = pl->next;
    ps = ps->next;
  }
  return ps;
}

int main() {
  std::vector<std::tuple<LinkedList<int>, LinkedList<int>>> testlist{
      {{7, 1}, {1, 2, 3, 4}}, {{5, 9, 2}, {1, 2, 3}}, {{5, 9, 2}, {3, 4}}};
  for (auto& [lst1, lst2] : testlist) {
    auto node1 = std::make_shared<LinkedList<int>::Node>(10);
    auto node2 = std::make_shared<LinkedList<int>::Node>(11);
    auto node3 = std::make_shared<LinkedList<int>::Node>(12);

    auto tail1 = FindTail(lst1);
    auto tail2 = FindTail(lst2);

    lst1.insert_after(lst1.insert_after(lst1.insert_after(tail1, node1), node2),
                      node3);
    lst2.insert_after(lst2.insert_after(lst2.insert_after(tail2, node1), node2),
                      node3);

    std::cout << lst1 << lst2;
    auto node = ListIntersection(lst1, lst2);
    std::cout << "On=";
    if (node != nullptr) {
      std::cout << node->data << '\n';
    } else {
      std::cout << "nullptr\n";
    }
    std::cout << '\n';
  }

  // no intersection
  auto lst1 = LinkedList<int>({1, 2, 3, 4});
  auto lst2 = LinkedList<int>({4, 5, 6});
  std::cout << lst1 << lst2;
  auto node = ListIntersection(lst1, lst2);
  std::cout << "On=";
  if (node != nullptr) {
    std::cout << node->data << '\n';
  } else {
    std::cout << "nullptr\n";
  }
  return 0;
}
