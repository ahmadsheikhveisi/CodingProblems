/* COPYRIGHT
 */

#ifndef CRACKING_3_3_STACKOFPLATES_SOLUTION_HPP_
#define CRACKING_3_3_STACKOFPLATES_SOLUTION_HPP_

#include <iostream>
#include <iterator>
#include <list>
#include <utility>

#include "stack.hpp"

template <typename T, size_t MaxStackSize>
class SetOfStacks {
 private:
  std::list<stack_impl::stack<T>> list_of_stacks;

  T pop_stack_front(typename std::list<stack_impl::stack<T>>::iterator pstk) {
    if (pstk->size() == 1) {
      auto ret = pstk->top();
      pstk->pop();
      return ret;
    }
    auto push_back = pstk->top();
    pstk->pop();
    auto ret = pop_stack_front(pstk);
    pstk->push(push_back);
    return ret;
  }

 public:
  template <typename U>
  void push(U&& val) {
    if ((list_of_stacks.size() == 0) ||
        (list_of_stacks.back().size() >= MaxStackSize)) {
      list_of_stacks.push_back(stack_impl::stack<T>{});
    }
    list_of_stacks.back().push(std::forward<U>(val));
  }

  T pop() {
    if (list_of_stacks.size() == 0) {
      return T{};
    }
    auto ret = list_of_stacks.back().top();
    list_of_stacks.back().pop();
    if (list_of_stacks.back().size() == 0) {
      list_of_stacks.erase(std::next(list_of_stacks.end(), -1));
    }
    return ret;
  }

  template <typename U>
  void pushAt(U&& val, size_t idx) {
    if (idx >= list_of_stacks.size()) {
      return;
    }
    auto itr = std::next(list_of_stacks.begin(), idx);
    if (itr->size() >= MaxStackSize) {
      if (list_of_stacks.front().size() >= MaxStackSize) {
        list_of_stacks.push_front(stack_impl::stack<T>{});
        idx = idx + 1;
      }
      pushAt(pop_stack_front(itr), idx - 1);
    }
    itr->push(std::forward<U>(val));
  }

  T popAt(size_t idx) {
    if (idx >= list_of_stacks.size()) {
      return T{};
    }
    if (idx == list_of_stacks.size() - 1) {
      return pop();
    }
    auto itr = std::next(list_of_stacks.begin(), idx);
    auto ret = itr->top();
    itr->pop();
    while (std::next(itr) != list_of_stacks.end()) {
      itr->push(pop_stack_front(std::next(itr)));
      itr = std::next(itr);
    }
    if (list_of_stacks.back().size() == 0) {
      list_of_stacks.erase(std::next(list_of_stacks.end(), -1));
    }
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& ostm, SetOfStacks& val) {
    for (auto itr = val.list_of_stacks.rbegin();
         itr != val.list_of_stacks.rend(); itr = std::next(itr)) {
      ostm << *itr << '\n';
    }
    return ostm;
  }
};

#endif  //  CRACKING_3_3_STACKOFPLATES_SOLUTION_HPP_
