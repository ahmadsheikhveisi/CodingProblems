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
#include <memory>

#include "stack.hpp"

template<typename T, size_t StackNum = 3, size_t StackSize = 10>
class mtype {
  class Node {
   public:
    T data;
    Node* next{nullptr};
    Node() : data(T{}) {};
    explicit Node(T&& t_data): data(std::move(t_data)) {}
    explicit Node(const T& t_data) : data(t_data) {}
  };
  std::array<Node, StackSize> arr;
  std::array<Node*, StackNum> topN;
  Node* empty_top{nullptr};
 public:
 mtype() {
  for (size_t cnt{0}; cnt < StackSize - 1; ++cnt) {
    arr[cnt].next = &arr[cnt + 1];
  }
  for (size_t cnt{0}; cnt < StackNum - 1; ++cnt) {
    topN[cnt] = nullptr;
  }
  empty_top = &arr[0];
 }
  T& top(size_t stack_idx) {
    return topN.at(stack_idx)->data;
  }
  template<typename U>
  bool push(U&& val, size_t stack_idx) {
    if (stack_idx > StackNum - 1) {
      return false;
    }
    if (empty_top == nullptr) {
      return false;
    }
    empty_top->data = std::forward<U>(val);
    auto next_empty = empty_top->next;
    if (topN[stack_idx] == nullptr) {
      topN[stack_idx] = empty_top;
      topN[stack_idx]->next = nullptr;
    } else {
      empty_top->next = topN[stack_idx];
      topN[stack_idx] = empty_top;
    }
    empty_top = next_empty;
    return true;
  }

  void pop(size_t stack_idx) {
    if (stack_idx > StackNum - 1) {
      return;
    }
    if (topN[stack_idx] == nullptr) {
      return;
    }
    auto next_top = topN[stack_idx]->next;
    if (empty_top != nullptr) {
      topN[stack_idx]->next = empty_top;
      empty_top = topN[stack_idx];
      
    } else {
      empty_top = topN[stack_idx];
      empty_top->next = nullptr;
    }
    topN[stack_idx] = next_top;
  }

  void print(size_t stack_idx) {
    if (stack_idx > StackNum - 1) {
      return;
    }
    auto ptr = topN[stack_idx];
    while (ptr) {
      std::cout << ptr->data << ' ';
      ptr = ptr->next;
    }
    std::cout << '\n';
  }

  friend std::ostream& operator<<(std::ostream& ostm, const mtype& val) {
    for (auto const& mem : val.arr) {
      std::cout << mem.data << ' ';
    }
    return ostm;
  }
};

int main() {
  mtype<int> mstk;
  mstk.push(13,0);
  mstk.push(14,0);
  mstk.push(15,0);
  mstk.push(16,0);
  mstk.push(17,0);
  mstk.push(18,0);
  mstk.push(19,0);
  mstk.push(20,0);
  mstk.push(21,0);
  mstk.push(22,0);
  mstk.push(23,0);
  mstk.push(24,0);
  std::cout << "full " << mstk << '\n';
  mstk.print(0);
  mstk.pop(0);
  mstk.print(0);
  mstk.pop(0);
  mstk.print(0);
  mstk.push(7,1);
  mstk.push(8,1);
  mstk.push(9,1);
  std::cout << "full " << mstk << '\n';
  mstk.print(0);
  mstk.print(1);
  mstk.print(2);
  std::cout << "top " << mstk.top(0) << '\n';

  return 0;
}
