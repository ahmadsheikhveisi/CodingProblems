/* COPYRIGHT
* Given an integer array nums and an integer k,
* return true if there are two distinct indices i and j in the array such that nums[i] == nums[j]
* and abs(i - j) <= k.
* 
*  
* 
* Example 1:
* 
* Input: nums = [1,2,3,1], k = 3
* Output: true
* 
* Example 2:
* 
* Input: nums = [1,0,1,1], k = 1
* Output: true
* 
* Example 3:
* 
* Input: nums = [1,2,3,1,2,3], k = 2
* Output: false
* 
*  
* 
* Constraints:
* 
*     1 <= nums.length <= 10^5
*     -10^9 <= nums[i] <= 10^9
*     0 <= k <= 10^5
* 
*/
#ifndef CONTAINS_DUPLICATS_II_219
#define CONTAINS_DUPLICATS_II_219

#include <unordered_map>
#include <vector>

class Solution {
 public:
    bool containsNearbyDuplicate([[maybe_unused]] std::vector<int>& nums,
                                [[maybe_unused]] int k) {
        std::unordered_map<int, int> hash_map{};
        int left{0};
        int right{0};
        while (right < static_cast<int>(nums.size())) {
            ++hash_map[nums[right]];
            if (hash_map[nums[right]] > 1) {
                return true;
            }
            ++right;
            if (right - left > k) {
                if (hash_map[nums[left]] > 0) {
                    --hash_map[nums[left]];
                }
                ++left;
            }
        }
        return false;
    }
 private:
};


#endif // CONTAINS_DUPLICATS_II_219
