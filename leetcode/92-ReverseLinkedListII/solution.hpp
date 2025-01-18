/* COPYRIGHT
* Given the head of a singly linked list and two integers left and right where left <= right,
* reverse the nodes of the list from position left to position right, and return the reversed list.
* 
* Example 1:
* 
* Input: head = [1,2,3,4,5], left = 2, right = 4
* Output: [1,4,3,2,5]
* 
* Example 2:
* Input: head = [5], left = 1, right = 1
* Output: [5]
* 
* Constraints:
* 
*     The number of nodes in the list is n.
*     1 <= n <= 500
*     -500 <= Node.val <= 500
*     1 <= left <= right <= n
* 
*  
* Follow up: Could you do it in one pass?
*/
#ifndef REVERSE_LINKED_LIST_II_92
#define REVERSE_LINKED_LIST_II_92

#include <iostream>
#include <vector>

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
    ListNode* reverseBetween([[maybe_unused]] ListNode* head, [[maybe_unused]] int left,
                            [[maybe_unused]] int right) {
        PrintList(head);
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        if (left >= right) {
            return head;
        }
        auto result = head;
        ListNode* start_prev{nullptr};
        auto start = head;
        int cnt{1};
        while (head != nullptr) {
            if (cnt >= left) {
                break;
            }
            ++cnt;
            start_prev = head;
            start = head->next;
            head = head->next;
        }
        //
        ListNode* next{nullptr};
        ListNode* prev{nullptr};
        while (head != nullptr) {
            if (cnt > right) {
                break; 
            }
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
            ++cnt;
        }
        if (start_prev != nullptr) {
            start_prev->next = prev;
        }
        start->next = head;
        if (left == 1) {
            result = prev;
        }
        PrintList(result);
        return result;
    }
 private:
    void PrintList(ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val << ' ';
            head = head->next;
        }
        std::cout << '\n';
    }
};
#endif // REVERSE_LINKED_LIST_II_92
