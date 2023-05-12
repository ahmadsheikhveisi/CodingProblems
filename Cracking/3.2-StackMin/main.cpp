/* COPYRIGHT
 * How would you design a stack which, in addition to push and pop
 * has a function min which returns the minimum element? push, pop
 * and min should all operate in O(1) time.
 * 
 * we can have a second stack!
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

template<typename T>
class mtype {
  class Node {
   public:
    T data;
    std::shared_ptr<Node> next{nullptr};
    std::shared_ptr<Node> last_min{nullptr};
    Node() : data(T{}) {};
    explicit Node(T&& t_data): data(std::move(t_data)) {}
    explicit Node(const T& t_data) : data(t_data) {}
  };
  std::shared_ptr<Node> stack_top{nullptr};
 public:
 mtype(): stack_top{nullptr} {}

  T& top() {
    return stack_top->data;
  }
  T& min() {
    return stack_top->last_min->data;
  }
  template<typename U>
  void push(U&& val) {
    auto ptr = std::make_shared<Node>(std::forward<U>(val));
    if (stack_top == nullptr) {
      stack_top = ptr;
      stack_top->last_min = stack_top;
    } else {
      ptr->next = stack_top;
      if (ptr->data < stack_top->last_min->data) {
        ptr->last_min = ptr;
      } else {
        ptr->last_min = stack_top->last_min;
      }
      stack_top = ptr;
    }
  }

  void pop() {
    if (stack_top != nullptr) {
      stack_top = stack_top->next;
    }
  }

  friend std::ostream& operator<<(std::ostream& ostm, const mtype& val) {
    auto ptr = val.stack_top;
    while (ptr != nullptr) {
      std::cout << ptr->data << ' ';
      ptr = ptr->next;
    }
    return ostm;
  }
};

template<typename T>
class minstack {
 private:
  stack_impl::stack<T> data;
  stack_impl::stack<T> mins;
 public:
  template<typename U>
  void push(U&& val){
    data.push(std::forward<U>(val));
    if (mins.size() != 0) {
      if (data.top() <= mins.top()) {
        mins.push(data.top());
      }
    } else {
      mins.push(data.top());
    }
  }
  void pop() {
    if (data.top() == mins.top()) {
      mins.pop();
    }
    data.pop();
  }
  T& min() {
    return mins.top();
  }
  friend std::ostream& operator<<(std::ostream& ostm,  minstack& val) {
    ostm << "data " << val.data << '\n';
    ostm << "min " << val.mins;
    return ostm;
  }
};

int main() {
  minstack<int> mstk;
  mstk.push(13);
  mstk.push(14);
  mstk.push(1);
  mstk.push(16);
  std::cout << mstk << '\n';
  std::cout << mstk.min() << '\n';
  mstk.pop();
  mstk.pop();
  mstk.pop();
  std::cout << mstk.min() << '\n';
  mstk.push(9);
  mstk.push(8);
  mstk.push(8);
  mstk.push(7);
  mstk.pop();
  std::cout << "full " << mstk << '\n';
  std::cout << mstk.min() << '\n';

  return 0;
}
