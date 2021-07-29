/* COPYRIGHT
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
 * 
 * Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.
 * 
 * The tests are generated such that there is exactly one solution. You may not use the same element twice.
 * 
 * Example 1:
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 * Example 2:
 * 
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 * 
 * Example 3:
 * 
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 * 
 *  
 * Constraints:
 * 
 *     2 <= numbers.length <= 3 * 10^4
 *     -1000 <= numbers[i] <= 1000
 *     numbers is sorted in non-decreasing order.
 *     -1000 <= target <= 1000
 *     The tests are generated such that there is exactly one solution.
 * 
*/

#include <vector>
#include <iostream>

void printVec(const std::vector<int>& vec) {
    for (const auto& num : vec) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}


/* Runtime: 4 ms, faster than 89.94% of C++ online submissions for Two Sum II - Input array is sorted.
 * Memory Usage: 9.7 MB, less than 43.77% of C++ online submissions for Two Sum II - Input array is sorted.
 * https://leetcode.com/submissions/detail/530068649/
*/
class Solution {
 public:
    std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
        std::vector<int> res;
        size_t lb = 0;
        size_t ub = numbers.size() - 1;
        while (lb < ub) {
            auto sum = numbers[lb] + numbers[ub];
            if (sum > target) {
                ub--;
            } else if (sum < target) {
                lb++;
            } else {
                res.push_back(lb + 1);
                res.push_back(ub + 1);
                break;
            }
        }
        return res;
    }
};

int main(void) {
    auto obj = Solution();
    printVec(obj.twoSum({2, 7, 11, 15}, 9));
    printVec(obj.twoSum({2, 3, 4, 15}, 6));
    printVec(obj.twoSum({-1, 0}, -1));
    return 0;
}
