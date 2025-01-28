/* COPYRIGHT
* Given an integer array nums, return the length of the longest strictly increasing
* subsequence.
* 
* Example 1:
* 
* Input: nums = [10,9,2,5,3,7,101,18]
* Output: 4
* Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
* 
* Example 2:
* 
* Input: nums = [0,1,0,3,2,3]
* Output: 4
* 
* Example 3:
* 
* Input: nums = [7,7,7,7,7,7,7]
* Output: 1
* 
*  
* 
* Constraints:
* 
*     1 <= nums.length <= 2500
*     -10^4 <= nums[i] <= 10^4
* 
*  
* 
* Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
* 
*/
#ifndef LONGEST_INCREASING_SUBSEQUENCE_300
#define LONGEST_INCREASING_SUBSEQUENCE_300

#include <vector>

class Solution {
 public:
    int lengthOfLIS([[maybe_unused]] std::vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        std::vector<int> res{};
        res.reserve(nums.size());
        res.push_back(nums[0]);
        for (size_t i{1}; i < nums.size(); ++i) {
            if (res.back() < nums[i]) {
                res.push_back(nums[i]);
            } else {
                auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
                *it = nums[i];
            }
        }
        return static_cast<int>(res.size());
    }
 private:
};


#endif // LONGEST_INCREASING_SUBSEQUENCE_300
