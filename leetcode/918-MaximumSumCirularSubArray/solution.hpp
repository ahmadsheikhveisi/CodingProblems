/* COPYRIGHT
* Given a circular integer array nums of length n,
* return the maximum possible sum of a non-empty subarray of nums.
* 
* A circular array means the end of the array connects to the beginning of the array.
* Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of
* nums[i] is nums[(i - 1 + n) % n].
* 
* A subarray may only include each element of the fixed buffer nums at most once.
* Formally, for a subarray nums[i], nums[i + 1], ..., nums[j],
* there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
* 
* 
* Example 1:
* 
* Input: nums = [1,-2,3,-2]
* Output: 3
* Explanation: Subarray [3] has maximum sum 3.
* 
* Example 2:
* 
* Input: nums = [5,-3,5]
* Output: 10
* Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
* 
* Example 3:
* 
* Input: nums = [-3,-2,-3]
* Output: -2
* Explanation: Subarray [-2] has maximum sum -2.
* 
*  
* 
* Constraints:
* 
*     n == nums.length
*     1 <= n <= 3 * 10^4
*     -3 * 10^4 <= nums[i] <= 3 * 10^4
* 
*/
#ifndef MAXIMUC_SUM_SUBARRAY_918
#define MAXIMUC_SUM_SUBARRAY_918

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
    int maxSubarraySumCircular([[maybe_unused]] std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int max_sum{nums[0]};
        int running_sum_max{max_sum};
        int total_sum{nums[0]};
        int min_sum{nums[0]};
        int running_sum_min{min_sum};
        size_t negative_count{nums[0] < 0 ? static_cast<size_t>(1) : 0};
        for (std::size_t cnt{1}; cnt < nums.size(); ++cnt) {
            running_sum_max = std::max(nums[cnt], running_sum_max + nums[cnt]);
            max_sum = std::max(running_sum_max, max_sum);
            total_sum += nums[cnt];
            if (nums[cnt] < 0) {
                ++negative_count;
            }
            running_sum_min = std::min(nums[cnt], running_sum_min + nums[cnt]);
            min_sum = std::min(running_sum_min, min_sum);
        }
        if (negative_count == nums.size()) {
            return max_sum;
        }
        return std::max(max_sum, total_sum -  min_sum);
    }
 private:
};

#endif // MAXIMUC_SUM_SUBARRAY_918
