/* COPYRIGHT
* Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
* leaving only distinct numbers from the original list. Return the linked list sorted as well.
* 
*  
* 
* Example 1:
* 
* Input: head = [1,2,3,3,4,4,5]
* Output: [1,2,5]
* 
* Example 2:
* 
* Input: head = [1,1,1,2,3]
* Output: [2,3]
* 
*  
* 
* Constraints:
* 
*     The number of nodes in the list is in the range [0, 300].
*     -100 <= Node.val <= 100
*     The list is guaranteed to be sorted in ascending order.
* 
* 
*/
#ifndef REMOVE_DUPLICATES_FROM_SORTED_LIST_II_82
#define REMOVE_DUPLICATES_FROM_SORTED_LIST_II_82

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while (head) {
        while (head->next && head->val == head->next->val)
            head = head->next;
        if (prev->next == head)
            prev = head;
        else
            prev->next = head->next;
        head = head->next;
        }

        return dummy.next;
    }
    ListNode* deleteDuplicates_my([[maybe_unused]] ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) {
            return head;
        }
        ListNode dummy{0, nullptr};
        auto prev = &dummy;
        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                auto val = head->val;
                while (head != nullptr && head->val == val) {
                    head = head->next;
                }
                continue;
            }
            prev->next = head;
            prev = head;
            if (head != nullptr) {
                head = head->next;
            }
            prev->next = nullptr;
        }
        return dummy.next;
    }
 private:
};
#endif // REMOVE_DUPLICATES_FROM_SORTED_LIST_II_82
