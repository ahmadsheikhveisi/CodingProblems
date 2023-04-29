/* COPYRIGHT
 * Write code to partition a linked list around a value x, such that all nodes
 * less than x come before all nodes greater than or equal to x. if x is
 * contained within the list, the values of x only need to be after the elements
 * less than x. The partition element x can appear anywhere in the "right
 * partition"; it does not need to appear between the left and right partitions.
 * Example:
 * Input:  3->5->8->5->10->2->1 [partition = 5]
 * Output: 3->1->2->10->5->5->8
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
void PartitionLinkedList(LinkedList<T>* lst, T val) {
  if (lst->front->next == nullptr) {
    return;
  }
  auto runner_ptr = lst->front;
  auto last_ptr = lst->front;
  while (last_ptr->next != nullptr) {
    last_ptr = last_ptr->next;
  }
  auto inserter_ptr = last_ptr;
  auto prev_ptr = lst->front;
  prev_ptr = nullptr;
  while (runner_ptr != last_ptr) {
    if (runner_ptr->data >= val) {
      auto i_next = inserter_ptr->next;
      auto r_next = runner_ptr->next;
      // insert back
      inserter_ptr->next = runner_ptr;
      runner_ptr->next = i_next;
      inserter_ptr = runner_ptr;
      // update previous- front might be moved..
      if (prev_ptr != nullptr) {
        prev_ptr->next = r_next;
      } else {
        lst->front = r_next;
      }
      // go to the next
      runner_ptr = r_next;

    } else {
      prev_ptr = runner_ptr;
      runner_ptr = runner_ptr->next;
    }
  }
}

int main() {
  std::vector<LinkedList<int>> testlist{{1, 3, 5, 3, 9, 2, 5, 6, 1, 1},
                                        {3, 5, 8, 5, 10, 2, 6},
                                        {9, 5, 8, 4, 10, 2, 1}};
  for (auto& test : testlist) {
    std::cout << test;
    PartitionLinkedList(&test, 5);
    std::cout << test;
    std::cout << '\n';
  }
  return 0;
}
