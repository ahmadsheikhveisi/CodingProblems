/* COPYRIGHT
* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
* The order of the elements may be changed.
* Then return the number of elements in nums which are not equal to val.
* Consider the number of elements in nums which are not equal to val be k,
* to get accepted, you need to do the following things:
* 
* Change the array nums such that the first k elements of nums contain the elements
* which are not equal to val. The remaining elements of nums are not important
* as well as the size of nums.
* Return k.
* 
* Custom Judge:
* The judge will test your solution with the following code:
* 
* int[] nums = [...]; // Input array
* int val = ...; // Value to remove
* int[] expectedNums = [...]; // The expected answer with correct length.
*                             // It is sorted with no values equaling val.
* 
* int k = removeElement(nums, val); // Calls your implementation
* 
* assert k == expectedNums.length;
* sort(nums, 0, k); // Sort the first k elements of nums
* for (int i = 0; i < actualLength; i++) {
*     assert nums[i] == expectedNums[i];
* }
* 
* If all assertions pass, then your solution will be accepted.
* 
* Example 1:
* Input: nums = [3,2,2,3], val = 3
* Output: 2, nums = [2,2,_,_]
* Explanation: Your function should return k = 2, with the first two elements of nums being 2.
* It does not matter what you leave beyond the returned k (hence they are underscores).
* 
* Example 2:
* Input: nums = [0,1,2,2,3,0,4,2], val = 2
* Output: 5, nums = [0,1,4,0,3,_,_,_]
* Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
* Note that the five elements can be returned in any order.
* It does not matter what you leave beyond the returned k (hence they are underscores).
* 
* Constraints:
*     0 <= nums.length <= 100
*     0 <= nums[i] <= 50
*     0 <= val <= 100
*/
#ifndef REMOVE_ELEMENT_27
#define REMOVE_ELEMENT_27

#include <vector>

class Solution {
 public:
    int removeElement(std::vector<int>& nums, int val) {
        int i{0};
        for (int j{0}; j < static_cast<int>(nums.size()); ++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
    int removeElement_longer_approach([[maybe_unused]] std::vector<int>& nums, [[maybe_unused]] int val) {
        int first_index{-1};
        for (int i{0}; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] == val) {
                if (first_index == -1) {
                    first_index = i;
                }
            } else {
                if (first_index != -1) {
                    nums[first_index] = nums[i];
                    ++first_index;
                }
            }
        }
        return first_index == -1 ? static_cast<int>(nums.size()) : first_index;
    }
 private:
};


#endif // REMOVE_ELEMENT_27
