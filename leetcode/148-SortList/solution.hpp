/* COPYRIGHT
* Given the head of a linked list, return the list after sorting it in ascending order.
* 
* Example 1:
* 
* Input: head = [4,2,1,3]
* Output: [1,2,3,4]
* 
* Example 2:
* 
* Input: head = [-1,5,3,4,0]
* Output: [-1,0,3,4,5]
* 
* Example 3:
* 
* Input: head = []
* Output: []
* 
* Constraints:
* 
*     The number of nodes in the list is in the range [0, 5 * 10^4].
*     -10^5 <= Node.val <= 10^5
* 
* Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
* (i.e. constant space)?
* 
*/
#ifndef SORT_LIST_148
#define SORT_LIST_148

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
 // two_pointers
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head)return NULL;
        if(head->next == NULL)return head;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

      while(fast!=NULL && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      prev->next = NULL;
      ListNode* h1 = sortList(head);
      ListNode* h2 = sortList(slow);
      return mergeList(h1, h2);
    }

    ListNode* mergeList(ListNode* h1, ListNode* h2){
        if(!h1)return h2;
        if(!h2)return h1;
        ListNode* curr = h1->val < h2->val ? h1 : h2;
        ListNode* nxt = curr == h1 ? h2 : h1;
        ListNode* head = curr;
        while(true){
            while(curr->next != NULL && curr->next->val < nxt->val){
                curr=curr->next;
            }
            ListNode* temp = curr->next;
            curr->next = nxt;
            nxt = temp;
            curr=curr->next;
            if(!nxt)break;
        }
        return head;
    }

    void PrintList(ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val << ' ';
            head = head->next;
        }
        std::cout << '\n';
    }
};


class Solution_get_length {
 public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int length = getLength(head);
        ListNode dummy(0);
        dummy.next = head;

        for (int step = 1; step < length; step *= 2) {
            ListNode* prev = &dummy;
            ListNode* curr = dummy.next;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);
                curr = split(right, step); // Move to next pair

                prev->next = merge(left, right); // Merge and attach
                while (prev->next) prev = prev->next; // Move prev to end
            }
        }

        return dummy.next;
    }
 private:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }
    ListNode* split(ListNode* head, int size) {
        for (int i = 1; head && i < size; i++) {
            head = head->next;
        }
        if (!head) return nullptr;

        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Temporary dummy node
        ListNode* tail = &dummy; 

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2; // Append remaining nodes
        return dummy.next;
    }
};

class Solution_long {
 public:
    ListNode* sortList_outoftime([[maybe_unused]] ListNode* head) {
        PrintList(head);
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        size_t size_arr{0};
        auto temp_root{head};
        while (temp_root != nullptr) {
            temp_root = temp_root->next;
            ++size_arr;
        };
        
        return MergeSortHelper(head, 0 , size_arr - 1);;
    }
    ListNode* MergeSortHelper(ListNode* root, size_t low, size_t high) {
        if (low < high) {
            auto mid = low + ((high - low) / 2);
            root = MergeSortHelper(root, low, mid);
            root = MergeSortHelper(root, mid + 1, high);
            root = Merge(root, low, mid, high);
        }
        return root;
    }
    ListNode* Merge(ListNode* root, size_t low, size_t mid, size_t high) {
        ListNode* base_ptr{nullptr};
        if (low > 0) {
            base_ptr = FindNode(root, low - 1);
        }
        ListNode* low_ptr{nullptr};
        if (base_ptr == nullptr) {
            low_ptr = root;
        } else {
            low_ptr = base_ptr->next;
        }
        ListNode* high_ptr{FindNode(low_ptr, mid - low + 1)};
        auto low_cnt = low;
        size_t high_cnt{mid + 1};
        while ((low_cnt <= mid) && (high_cnt <= high)) {
            if (low_ptr->val < high_ptr->val) {
                ++low_cnt;
                if (base_ptr == nullptr) {
                    base_ptr = low_ptr;
                    root = low_ptr;
                } else {
                    base_ptr->next = low_ptr;
                    base_ptr = low_ptr;
                }
                low_ptr = low_ptr->next;
            } else {
                ++high_cnt;
                if (base_ptr == nullptr) {
                    base_ptr = high_ptr;
                    root = high_ptr;
                } else {
                    base_ptr->next = high_ptr;
                    base_ptr = high_ptr;
                }
                high_ptr = high_ptr->next;
            }
        }
        if (low_cnt <= mid) {
            while (low_cnt <= mid) {
                base_ptr->next = low_ptr;
                base_ptr = low_ptr;
                low_ptr = low_ptr->next;
                ++low_cnt;
            }
        }
        if (high_cnt <= high) {
            while (high_cnt <= high) {
                base_ptr->next = high_ptr;
                base_ptr = high_ptr;
                high_ptr = high_ptr->next;
                ++high_cnt;
            }
        }
        base_ptr->next = high_ptr;
        return root;
    }
    ListNode* FindNode(ListNode* root, size_t cnt) {
        ListNode* res{root};
        while (cnt > 0) {
            res = res->next;
            --cnt;
        }
        return res;        
    }
    void PrintList(ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val << ' ';
            head = head->next;
        }
        std::cout << '\n';
    }
};

#endif // REVERSE_LINKED_LIST_II_92
