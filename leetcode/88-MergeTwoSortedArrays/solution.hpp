/* COPYRIGHT
* You are given two integer arrays nums1 and nums2,
* sorted in non-decreasing order, and two integers m and n,
* representing the number of elements in nums1 and nums2 respectively.
* Merge nums1 and nums2 into a single array sorted in non-decreasing order.
* 
* The final sorted array should not be returned by the function,
* but instead be stored inside the array nums1. To accommodate this,
* nums1 has a length of m + n, where the first m elements denote the elements
* that should be merged, and the last n elements are set to 0 and should be ignored.
* nums2 has a length of n.
* 
* Example 1:
* Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
* Output: [1,2,2,3,5,6]
* Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
* The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
* 
* Example 2:
* Input: nums1 = [1], m = 1, nums2 = [], n = 0
* Output: [1]
* Explanation: The arrays we are merging are [1] and [].
* The result of the merge is [1].
* 
* Example 3:
* Input: nums1 = [0], m = 0, nums2 = [1], n = 1
* Output: [1]
* Explanation: The arrays we are merging are [] and [1].
* The result of the merge is [1].
* Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
* 
* Constraints:
*     nums1.length == m + n
*     nums2.length == n
*     0 <= m, n <= 200
*     1 <= m + n <= 200
*     -109 <= nums1[i], nums2[j] <= 109
* 
* Follow up: Can you come up with an algorithm that runs in O(m + n) time?
*/
#ifndef MERGE_TWO_SORTED_ARRAYS_88
#define MERGE_TWO_SORTED_ARRAYS_88

#include <vector>

class Solution {
 public:
    void merge([[maybe_unused]] std::vector<int>& nums1, [[maybe_unused]] int m,
        [[maybe_unused]] std::vector<int>& nums2, [[maybe_unused]] int n) {
        int nums1_index{m - 1}, nums2_index{n - 1}, result_index{m + n - 1};
        while ((nums1_index >= 0) && (nums2_index >= 0)) {
            if (nums1[nums1_index] > nums2[nums2_index]) {
                nums1[result_index--] = nums1[nums1_index--];
            } else {
                nums1[result_index--] = nums2[nums2_index--];
            }
        }
        while (nums2_index >= 0) {
            nums1[result_index--] = nums2[nums2_index--];
        }
    }
    void merge_from_start([[maybe_unused]] std::vector<int>& nums1, [[maybe_unused]] int m,
        [[maybe_unused]] std::vector<int>& nums2, [[maybe_unused]] int n) {
        std::vector<int> result(m + n);
        int nums1_index{0}, nums2_index{0}, result_index{0};
        while ((nums1_index < m) && (nums2_index < n)) {
            if (nums1[nums1_index] < nums2[nums2_index]) {
                result[result_index++] = nums1[nums1_index++];
            } else {
                result[result_index++] = nums2[nums2_index++];
            }
        }
        while (nums1_index < m) {
            result[result_index++] = nums1[nums1_index++];
        }
        while (nums2_index < n) {
            result[result_index++] = nums2[nums2_index++];
        }
        nums1 = result;
    }
 private:
};


#endif // MERGE_TWO_SORTED_ARRAYS_88
