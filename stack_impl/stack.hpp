/* COPYRIGHT
*/

#ifndef STACK_IMPL_STACK_HPP_
#define STACK_IMPL_STACK_HPP_

#include <signal.h>

#include <iostream>
#include <memory>
#include <utility>

namespace stack_impl {
template<typename T>
class stack {
 private:
    class Node {
     public:
        T data;
        std::shared_ptr<Node> next{nullptr};
        explicit Node(T&& t_data): data(std::move(t_data)) {
            std::cout << "Creating data from: " << t_data.print();
            // data = std::move(t_data);
            std::cout << " To:" << data.print() << '\n';
        }
        explicit Node(const T& t_data): data(std::move(t_data)) {
            std::cout << "Copying data from: " << t_data.print();
            // data = std::move(t_data);
            std::cout << " To:" << data.print() << '\n';
        }
    };
    size_t size_;
    std::shared_ptr<Node> top_;

    void set_top(std::shared_ptr<Node> ptr) {
        if (top_ == nullptr) {
            top_ = ptr;
        } else {
            ptr->next = top_;
            top_ = ptr;
        }
    }

 public:
    stack() : size_(0), top_{nullptr} {}
    void push(T&& val) {
        std::cout << "Forwarding: " << val.print() << '\n';
        auto ptr = std::make_shared<Node>(std::forward<T>(val));
        std::cout << "Setting top: " << ptr->data.print() << '\n';
        set_top(ptr);
        ++size_;
    }
    void push(const T& val) {
        std::cout << "Copying: " << val.print() << '\n';
        auto ptr = std::make_shared<Node>(val);
        std::cout << "Setting top: " << ptr->data.print() << '\n';
        set_top(ptr);
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
