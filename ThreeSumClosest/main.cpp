/* COPYRIGHT
 * https://leetcode.com/problems/3sum-closest/
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * 
 * Example 1:
 * 
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * Constraints:
 *     3 <= nums.length <= 10^3
 *     -10^3 <= nums[i] <= 10^3
 *     -10^4 <= target <= 10^4
 * 
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>

/* https://leetcode.com/submissions/detail/530674321/
 * Runtime: 4 ms, faster than 97.81% of C++ online submissions for 3Sum Closest.
 * Memory Usage: 10 MB, less than 13.16% of C++ online submissions for 3Sum Closest.
*/
class Solution {
    int disint(int num1, int num2) {
        return num1 > num2? num1 - num2: num2 - num1;
    }

 public:
    int threeSumClosest(const std::vector<int>& in_nums, int target) {
        std::vector<int> nums{in_nums};
        std::sort(nums.begin(), nums.end());
        int res = std::accumulate(nums.begin(), nums.begin() + 3, 0);
        for (size_t cnt = 0; cnt < nums.size(); ++cnt) {
            size_t lb = cnt + 1;
            size_t ub = nums.size() - 1;
            while (lb < ub) {
                auto sum = nums[cnt] + nums[lb] + nums[ub];
                if (disint(sum, target) < disint(res, target)) {
                    res = sum;
                }
                if (sum > target) {
                    --ub;
                } else if (sum < target) {
                    ++lb;
                } else {
                    return sum;
                }
            }
        }
        return res;
    }
};

int main(void) {
    auto obj = Solution();
    std::cout << obj.threeSumClosest({-1, 2, 1, -4}, 1) << '\n';
    std::cout << obj.threeSumClosest({1, 1, 1, 1}, 100) << '\n';
    return 0;
}
