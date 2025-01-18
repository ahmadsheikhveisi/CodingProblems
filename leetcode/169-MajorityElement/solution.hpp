/* COPYRIGHT
* Given an array nums of size n, return the majority element.
* 
* The majority element is the element that appears more than ⌊n / 2⌋ times.
* You may assume that the majority element always exists in the array.
* 
* Example 1:
* Input: nums = [3,2,3]
* Output: 3
* 
* Example 2:
* Input: nums = [2,2,1,1,1,2,2]
* Output: 2
* 
* Constraints:
* 
*     n == nums.length
*     1 <= n <= 5 * 104
*     -109 <= nums[i] <= 109
* 
* Follow-up: Could you solve the problem in linear time and in O(1) space?
*/
#ifndef MAJORITY_ELEMENT_169
#define MAJORITY_ELEMENT_169

#include <vector>

class Solution {
 public:
    int majorityElement([[maybe_unused]] std::vector<int>& nums) {
        int majority_element{nums[0]};
        int majority_count{1};
        for (int i{1}; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] != majority_element) {
                if (majority_count == 0) {
                    majority_element = nums[i];
                } else {
                    --majority_count;
                }
            } else {
                ++majority_count;
            }
        }
        return majority_element;
    }
 private:
};


#endif // MAJORITY_ELEMENT_169
