/* COPYRIGHT
* Given an array of integers nums sorted in non-decreasing order,
* find the starting and ending position of a given target value.
* 
* If target is not found in the array, return [-1, -1].
* 
* You must write an algorithm with O(log n) runtime complexity.
* 
* Example 1:
* Input: nums = [5,7,7,8,8,10], target = 8
* Output: [3,4]
* 
* Example 2:
* Input: nums = [5,7,7,8,8,10], target = 6
* Output: [-1,-1]
* 
* Example 3:
* Input: nums = [], target = 0
* Output: [-1,-1]
* 
* Constraints:
*     0 <= nums.length <= 10^5
*     -10^9 <= nums[i] <= 10^9
*     nums is a non-decreasing array.
*     -10^9 <= target <= 10^9
*/
#ifndef FIND_THE_FIRST_AND_LAST_ELEMENT_IN_SORTED_ARRAY_34
#define FIND_THE_FIRST_AND_LAST_ELEMENT_IN_SORTED_ARRAY_34

#include <vector>

class Solution {
 public:
    std::vector<int> searchRange([[maybe_unused]] std::vector<int>& nums,
        [[maybe_unused]] int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return {0, 0};
            } else {
                return {-1, -1};
            }
        }
        // find the first of occurance of the element
        int left{0};
        int right{static_cast<int>(nums.size()) - 1};
        while (left < right) {
            int mid{left + (right - left) / 2};
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[left] != target) {
            return {-1, -1};
        }
        int first{left};       
        // find the last occurance of the element
        left = first; 
        right = static_cast<int>(nums.size()) - 1;
        while (left < right) {
            int mid{left + (right - left) / 2};
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (nums[right] != target) {
            --right;
        }
        return {first, right};
    }
 private:
};


#endif // FIND_THE_FIRST_AND_LAST_ELEMENT_IN_SORTED_ARRAY_34
