/* COPYRIGHT
 * Given a circular linked list, implement an algorithm that returns the node at
 * the beginning of the loop. a Circular linked list is a (corrupt) linked list
 * in whicha node's next pointer points to an ealier node, so s to make a loop
 * in the linked list.
 *
 * Input: A->B->C->D->E->C
 * Output: C
 *
 * Note: case insensive, ignore white space, ASCII, UTF8
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
 * complexity. otherwise, recursion gives O(N) space complexity. don't forget
 * the runner approach.
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
Nodeptr<T> FindLoopListHash(LinkedList<T> const& lst) {
  std::unordered_set<Nodeptr<T>> hash;

  auto node = lst.front;

  while (node != nullptr) {
    if (hash.find(node) != hash.end()) {
      break;
    } else {
      hash.insert(node);
      node = node->next;
    }
  }

  return node;
}

// READ THIS SOLUTION
template <typename T>
Nodeptr<T> FindLoopListPatternMatching(LinkedList<T> const& lst) {
  if (lst.front == nullptr || lst.front->next == nullptr) {
    return nullptr;
  }
  auto pFast = lst.front->next->next;
  auto pSlow = lst.front->next;
  while ((pFast != pSlow) && (pFast != nullptr)) {
    pFast = pFast->next;
    if (pFast != nullptr) {
      pFast = pFast->next;
    }
    pSlow = pSlow->next;
  }
  if (pFast == pSlow) {
    pFast = lst.front;
    while (pFast != pSlow) {
      pFast = pFast->next;
      pSlow = pSlow->next;
    }
  }
  return pFast;
}

template <typename T>
void printNode(Nodeptr<T> node, std::string_view str) {
  std::cout << str << "=";
  if (node != nullptr) {
    std::cout << node->data << '\n';
  } else {
    std::cout << "nullptr\n";
  }
}

int main() {
  std::vector<LinkedList<int>> testlist{{7, 1, 1, 2, 3, 4}, {5, 9, 2, 1, 2, 3}};
  for (auto& lst1 : testlist) {
    auto node1 = std::make_shared<LinkedList<int>::Node>(10);
    auto node2 = std::make_shared<LinkedList<int>::Node>(11);
    auto node3 = std::make_shared<LinkedList<int>::Node>(12);

    auto tail1 = FindTail(lst1);

    lst1.insert_after(lst1.insert_after(lst1.insert_after(tail1, node1), node2),
                      node3);

    node3->next = node1;

    // std::cout << lst1;
    printNode<int>(FindLoopListHash(lst1), "Hash");
    printNode<int>(FindLoopListPatternMatching(lst1), "Pattern Matching");

    std::cout << '\n';
  }

  // no Loop
  auto lst1 = LinkedList<int>({1, 2});
  // std::cout << lst1;
  lst1.front->next->next = lst1.front->next;
  printNode<int>(FindLoopListHash(lst1), "Hash");
  printNode<int>(FindLoopListPatternMatching(lst1), "Pattern Matching");
  return 0;
}
