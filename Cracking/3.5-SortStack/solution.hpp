/* COPYRIGHT
 */

#ifndef CRACKING_3_4_QUEUEVIASTACKS_SOLUTION_HPP_
#define CRACKING_3_4_QUEUEVIASTACKS_SOLUTION_HPP_

#include <iostream>
#include <iterator>
#include <list>
#include <utility>

#include "stack.hpp"

template <typename T>
class SortedStack {
 private:
  stack_impl::stack<T> sorted_stack;

 public:
  template <typename U>
  void push(U&& val) {
    if (sorted_stack.size() == 0) {
      sorted_stack.push(std::forward<U>(val));
      return;
    }
    stack_impl::stack<T> temp_stack;
    while ((sorted_stack.size() != 0) && (val > sorted_stack.top())) {
      temp_stack.push(sorted_stack.top());
      sorted_stack.pop();
    }
    sorted_stack.push(std::forward<U>(val));
    while (temp_stack.size() != 0) {
      sorted_stack.push(temp_stack.top());
      temp_stack.pop();
    }
  }

  T pop() {
    auto ret = sorted_stack.top();
    sorted_stack.pop();
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& ostm, SortedStack& val) {
    ostm << "all " << val.sorted_stack;
    return ostm;
  }
};

#endif  //  CRACKING_3_4_QUEUEVIASTACKS_SOLUTION_HPP_
