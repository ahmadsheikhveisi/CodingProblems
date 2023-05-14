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
class MyQueue {
 private:
  stack_impl::stack<T> push_stack;
  stack_impl::stack<T> pop_stack;

 public:
  template <typename U>
  void push(U&& val) {
    push_stack.push(std::forward<U>(val));
  }

  T pop() {
    if (pop_stack.size() == 0) {
      while (push_stack.size() != 0) {
        pop_stack.push(push_stack.top());
        push_stack.pop();
      }
    }

    auto ret = pop_stack.top();
    pop_stack.pop();
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& ostm, MyQueue& val) {
    ostm << "push " << val.push_stack << "\npop " << val.pop_stack;
    return ostm;
  }
};

#endif  //  CRACKING_3_4_QUEUEVIASTACKS_SOLUTION_HPP_
