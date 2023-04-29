/* COPYRIGHT
 */

#ifndef SINGLY_LINKED_LIST_IMPL_SINGLY_LINKED_LIST_HPP_
#define SINGLY_LINKED_LIST_IMPL_SINGLY_LINKED_LIST_HPP_

#include <iostream>
#include <memory>
#include <utility>

template <typename T>
class LinkedList {
 public:
  class Node {
   public:
    T data;
    std::shared_ptr<Node> next{nullptr};
    explicit Node(T&& t_data) : data(std::move(t_data)) {}
    explicit Node(T const& t_data) : data(t_data) {}
    // ~Node() { std::cout << "des: " << data << '\n'; }
  };

  LinkedList() : front(nullptr) {}

  LinkedList(std::initializer_list<T> lst) : front(nullptr) {
    auto ptr = front;
    for (auto&& mem : lst) {
      ptr = insert_after(ptr, mem);
    }
  }

  template <typename U>
  std::shared_ptr<Node> insert(std::shared_ptr<Node> pos, U&& data) {
    auto node = std::make_shared<Node>(std::forward<U>(data));
    if (front == pos) {
      node->next = front;
      front = node;
    } else {
      auto prev = front;
      while (prev->next != pos) {
        prev = prev->next;
      }
      prev->next = node;
      node->next = pos;
    }
    ++_size;
    return node;
  }

  template <typename U>
  std::shared_ptr<Node> insert_after(std::shared_ptr<Node> pos, U&& data) {
    auto node = std::make_shared<Node>(std::forward<U>(data));
    if (pos == nullptr) {
      front = node;
    } else {
      node->next = pos->next;
      pos->next = node;
    }
    ++_size;
    return node;
  }

  friend std::ostream& operator<<(std::ostream& ostrm, LinkedList const& lst) {
    auto node{lst.front};
    while (node != nullptr) {
      ostrm << node->data << ' ';
      node = node->next;
    }
    ostrm << '\n';
    return ostrm;
  }

  void rec_reverse() {
    if (front == nullptr) {
      return;
    }
    rec_rev(front)->next = nullptr;
  }
  void On_reverse() {
    if (front == nullptr) {
      return;
    }
    std::shared_ptr<Node> current{front}, next{nullptr}, prev{nullptr};
    while (current->next != nullptr) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    current->next = prev;
    front = current;
  }

  std::shared_ptr<Node> front{nullptr};

  size_t size() const { return _size; }

 private:
  size_t _size{0};

  std::shared_ptr<Node> rec_rev(std::shared_ptr<Node> node) {
    if (node == nullptr) {
      return nullptr;
    }
    if (node->next != nullptr) {
      rec_rev(node->next)->next = node;
    } else {
      front = node;
    }
    return node;
  }
};

#endif  // SINGLY_LINKED_LIST_IMPL_SINGLY_LINKED_LIST_HPP_
