/* COPYRIGHT
* You are given an array of k linked-lists lists,
* each linked-list is sorted in ascending order.
* 
* Merge all the linked-lists into one sorted linked-list and return it.
* 
* Example 1:
* Input: lists = [[1,4,5],[1,3,4],[2,6]]
* Output: [1,1,2,3,4,4,5,6]
* Explanation: The linked-lists are:
* [
*   1->4->5,
*   1->3->4,
*   2->6
* ]
* merging them into one sorted list:
* 1->1->2->3->4->4->5->6
* 
* Example 2:
* Input: lists = []
* Output: []
* 
* Example 3:
* Input: lists = [[]]
* Output: []
* 
* Constraints:
* 
*     k == lists.length
*     0 <= k <= 10^4
*     0 <= lists[i].length <= 500
*     -10^4 <= lists[i][j] <= 10^4
*     lists[i] is sorted in ascending order.
*     The sum of lists[i].length will not exceed 10^4.
*/
#ifndef MERGE_K_SORTED_LISTS_23
#define MERGE_K_SORTED_LISTS_23

#include <queue>
#include <vector>

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template<> class std::greater<ListNode*> {
 public:
    bool operator()(ListNode* const& lhs, ListNode* const& rhs) const {
        return lhs->val > rhs->val;
    }
};

class Solution {
 public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        std::priority_queue<ListNode*, std::vector<ListNode*>, std::greater<ListNode*>> pq{};
        for (auto const& node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }
        if (pq.empty()) {
            return nullptr;
        }
        auto result = pq.top();
        ListNode* prev{nullptr};
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            if (current->next != nullptr) {
                pq.push(current->next);
            }
            if (prev != nullptr) {
                prev->next = current;
            }
            prev = current;
        }
        return result;
    }
 private:
};


#endif // MERGE_K_SORTED_LISTS_23
