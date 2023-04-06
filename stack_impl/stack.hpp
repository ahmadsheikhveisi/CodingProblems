/* COPYRIGHT
*/

#ifndef STACK_IMPL_STACK_HPP_
#define STACK_IMPL_STACK_HPP_

#include <signal.h>

#include <memory>

namespace stack_impl {
template<typename T>
class stack {
 private:
    class Node {
     public:
        T data;
        std::shared_ptr<Node> next{nullptr};
        explicit Node(T t_data): data(t_data) {}
    };
    size_t size_;
    std::shared_ptr<Node> top_;

 public:
    stack() : size_(0), top_{nullptr} {}
    void push(T val) {
        auto ptr = std::make_shared<Node>(val);
        if (top_ == nullptr) {
            top_ = ptr;
        } else {
            ptr->next = top_;
            top_ = ptr;
        }
        ++size_;
    }
    void pop() {
        if (top_ != nullptr) {
            top_ = top_->next;
            --size_;
        }
    }
    T& top() {
        return top_->data;
    }
    size_t size() {
        return size_;
    }
};
}  // namespace stack_impl

#endif  // STACK_IMPL_STACK_HPP_
