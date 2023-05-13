/* COPYRIGHT
 * Describe how you could use a single array to implement three stacks.
 *
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
 * structured binding auto [a, b) = std::tuple
 * to use current variables: std::tie(a,b, _) = std::tuple
 *
 * in linked lists, if you can use the size, you can acheive O(1) space
 * complexity. otherwise, recursion gives O(N) space complexity. don't forget
 * the runner approach.
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "stack.hpp"

static constexpr size_t stack_size_default{10};
static constexpr size_t number_of_stacks_default{3};
template <typename T, size_t StackNum = number_of_stacks_default,
          size_t StackSize = stack_size_default>
class mtype {
  class Node {
   public:
    T data;
    Node *next{nullptr};
    Node() : data(T{}) {}
    explicit Node(T &&t_data) : data(std::move(t_data)) {}
    explicit Node(const T &t_data) : data(t_data) {}
  };
  std::array<Node, StackSize> arr;
  std::array<Node *, StackNum> topN;
  Node *empty_top{nullptr};

 public:
  mtype() {
    for (size_t cnt{0}; cnt < StackSize - 1; ++cnt) {
      arr.at(cnt).next = &arr.at(cnt + 1);
    }
    for (size_t cnt{0}; cnt < StackNum; ++cnt) {
      topN.at(cnt) = nullptr;
    }
    empty_top = &arr.at(0);
  }
  T &top(size_t stack_idx) { return topN.at(stack_idx)->data; }
  template <typename U>
  bool push(U &&val, size_t stack_idx) {
    if (stack_idx > StackNum - 1) {
      return false;
    }
    if (empty_top == nullptr) {
      return false;
    }
    empty_top->data = std::forward<U>(val);
    auto next_empty = empty_top->next;
    if (topN.at(stack_idx) == nullptr) {
      topN.at(stack_idx) = empty_top;
      topN.at(stack_idx)->next = nullptr;
    } else {
      empty_top->next = topN.at(stack_idx);
      topN.at(stack_idx) = empty_top;
    }
    empty_top = next_empty;
    return true;
  }

  void pop(size_t stack_idx) {
    if (stack_idx > StackNum - 1) {
      return;
    }
    if (topN.at(stack_idx) == nullptr) {
      return;
    }
    auto next_top = topN.at(stack_idx)->next;
    if (empty_top != nullptr) {
      topN.at(stack_idx)->next = empty_top;
      empty_top = topN.at(stack_idx);

    } else {
      empty_top = topN.at(stack_idx);
      empty_top->next = nullptr;
    }
    topN.at(stack_idx) = next_top;
  }

  void print(size_t stack_idx) {
    if (stack_idx > StackNum - 1) {
      return;
    }
    auto ptr = topN.at(stack_idx);
    while (ptr) {
      std::cout << ptr->data << ' ';
      ptr = ptr->next;
    }
    std::cout << '\n';
  }

  friend std::ostream &operator<<(std::ostream &ostm, const mtype &val) {
    for (auto const &mem : val.arr) {
      std::cout << mem.data << ' ';
    }
    return ostm;
  }
};

int main() {
  mtype<int> mstk;
  std::vector<int> const data0{13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
  for (auto num : data0) {
    mstk.push(num, 0);
  }
  std::cout << "full " << mstk << '\n';
  mstk.print(0);
  mstk.pop(0);
  mstk.print(0);
  mstk.pop(0);
  mstk.print(0);
  std::vector<int> const data1{7, 8, 9, 9};
  for (auto num : data1) {
    mstk.push(num, 1);
  }

  mstk.push(data1.back(), 2);
  std::cout << "full " << mstk << '\n';
  mstk.print(0);
  mstk.print(1);
  mstk.print(2);
  std::cout << "top " << mstk.top(0) << '\n';

  return 0;
}
