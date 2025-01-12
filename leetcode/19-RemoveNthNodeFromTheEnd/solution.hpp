/* COPYRIGHT
*/
#ifndef REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP_19
#define REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP_19

#include <iostream>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
    ListNode* removeNthFromEnd([[maybe_unused]] ListNode* head, [[maybe_unused]] int n) {
        //PrintList(head);
        //std::cout << "n: " << n << '\n';
        FindNthFromEndAndRemove(head, n);
        if (n == 0) {
            head = head->next;
        }
        //PrintList(head);
        //std::cout << "n: " << n << '\n';
        return head;
    }
 private:
    void FindNthFromEndAndRemove(ListNode* head, int& n) {
        if (head == nullptr) {
            return;
        }
        FindNthFromEndAndRemove(head->next, n);
        if (n == 0) {
            head->next = head->next->next;
        }
        --n;
    }
    void PrintList(ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val << ' ';
            head = head->next;
        }
        std::cout << '\n';
    }
};

#endif // REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP_19
