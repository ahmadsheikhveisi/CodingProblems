/* COPYRIGHT
* Given an array of distinct integers candidates and a target integer target,
* return a list of all unique combinations of candidates where the chosen numbers sum to target.
* You may return the combinations in any order.
* 
* The same number may be chosen from candidates an unlimited number of times.
* Two combinations are unique if the frequency of at least one of the chosen numbers is different.
* 
* The test cases are generated such that the number of unique combinations
* that sum up to target is less than 150 combinations for the given input.
* 
*  
* 
* Example 1:
* 
* Input: candidates = [2,3,6,7], target = 7
* Output: [[2,2,3],[7]]
* Explanation:
* 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
* 7 is a candidate, and 7 = 7.
* These are the only two combinations.
* 
* Example 2:
* 
* Input: candidates = [2,3,5], target = 8
* Output: [[2,2,2,2],[2,3,3],[3,5]]
* 
* Example 3:
* 
* Input: candidates = [2], target = 1
* Output: []
* 
*  
* 
* Constraints:
* 
*     1 <= candidates.length <= 30
*     2 <= candidates[i] <= 40
*     All elements of candidates are distinct.
*     1 <= target <= 40
* 
* 
*/

#ifndef BEST_TIME_TO_BUY_AND_SELL_STOCK_II_122
#define BEST_TIME_TO_BUY_AND_SELL_STOCK_II_122

#include <algorithm>
#include <vector>

// 2^N
class Solution {
 public:
    std::vector<std::vector<int>> combinationSum([[maybe_unused]] std::vector<int>& candidates,
                        [[maybe_unused]] int target) {
        std::vector<std::vector<int>> result{};
        std::vector<int> current{};
        combinationSum(candidates, target, result, current, 0);        
        return result;
    }
 private:
    void combinationSum(std::vector<int>& candidates, int target,
        std::vector<std::vector<int>>& result, std::vector<int>& current,
        size_t index) {
        if ((index >= candidates.size()) || (target < 0)) {
            return;
        }
        if (target == 0) {
            result.push_back(current);
            return;
        }
        current.push_back(candidates[index]);
        combinationSum(candidates, target - candidates[index], result, current, index);
        current.pop_back();
        combinationSum(candidates, target, result, current, index + 1);
    }
};

// 2^NxN
class Solution_2powNxN {
 public:
    std::vector<std::vector<int>> combinationSum([[maybe_unused]] std::vector<int>& candidates,
                        [[maybe_unused]] int target) {
        std::vector<std::vector<int>> result{};
        std::vector<int> current{};
        combinationSum(candidates, target, result, current, 0);
        std::erase_if(result, [](const std::vector<int>& v) { return v.empty(); });
        
        return result;
    }
 private:
    void combinationSum(std::vector<int>& candidates, int target,
        std::vector<std::vector<int>>& result, std::vector<int> current,
        size_t index) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) {
            return;
        }
        for (size_t i{index}; i < candidates.size(); ++i) {
            current.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], result, current, i);
            current.pop_back();
        }
    }
};
#endif // BEST_TIME_TO_BUY_AND_SELL_STOCK_II_122
