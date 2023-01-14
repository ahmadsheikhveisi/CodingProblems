/* COPYRIGHT
*/

#include <iostream>
#include <list>
#include <forward_list>
#include <memory>

class Node {
 public:
    int data{0};
    std::shared_ptr<Node> next{nullptr};
    explicit Node(int t_data = 0): data(t_data) {
        std::cout << "con: " << data << '\n';
    }
    ~Node() {
        std::cout << "des: " << data << '\n';
    }
};

class LinkedList {
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

 public:
    std::shared_ptr<Node> front{nullptr};
    void push(int data) {
        auto node = std::make_shared<Node>(data);
        node->next = front;
        front = node;
    }
    void print() {
        auto node{front};
        while (node != nullptr) {
            std::cout << node->data << ' ';
            node = node->next;
        }
        std::cout << '\n';
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
};

int main() {
    LinkedList m_list;
    m_list.push(0);
    m_list.push(1);
    m_list.push(2);
    m_list.push(3);
    m_list.print();
    m_list.rec_reverse();
    m_list.print();
    m_list.On_reverse();
    m_list.print();
    LinkedList empty_list;
    empty_list.print();
    empty_list.On_reverse();
    empty_list.rec_reverse();
    return 0;
}
