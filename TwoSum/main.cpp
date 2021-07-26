/* COPYRIGHT
 * https://leetcode.com/problems/two-sum/
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * Example 1:
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * Example 2:
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * Example 3:
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * Constraints:
 * 
 *     2 <= nums.length <= 10^4
 *     -10^9 <= nums[i] <= 10^9
 *     -10^9 <= target <= 10^9
 *     Only one valid answer exists.
 * 
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

/*
 * Runtime: 16 ms, faster than 55.64% of C++ online submissions for Two Sum.
 * Memory Usage: 11.9 MB, less than 16.10% of C++ online submissions for Two Sum.
 * https://leetcode.com/submissions/detail/528629405/
*/
class Solution {
 public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hashTable;
        std::vector<int> res;
        for (size_t cnt = 0; cnt < nums.size(); ++cnt) {
            if (hashTable.find(target - nums[cnt]) != hashTable.end()) {
                res.push_back(hashTable[target - nums[cnt]]);
                res.push_back(cnt);
            } else {
                hashTable[nums[cnt]] = cnt;
            }
        }
        return res;
    }
};

void printVec(const std::vector<int>& vec) {
    std::for_each(begin(vec), end(vec), [](int num){std::cout << num << ' ';});
    std::cout << '\n';
}

int main(void) {
    auto obj = Solution();
    printVec(obj.twoSum({2, 7, 11, 15}, 9));
    printVec(obj.twoSum({3, 2, 4, 15}, 6));
    printVec(obj.twoSum({3, 3}, 6));
}
