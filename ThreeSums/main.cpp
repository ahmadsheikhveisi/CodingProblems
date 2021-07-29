/* COPYRIGHT 3Sum
 * https://leetcode.com/problems/3sum/
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * Example 1:
 * 
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * 
 * Example 2:
 * 
 * Input: nums = []
 * Output: []
 * 
 * Example 3:
 * 
 * Input: nums = [0]
 * Output: []
 * 
 * Constraints:
 * 
 *     0 <= nums.length <= 3000
 *     -10^5 <= nums[i] <= 10^5
 * 
*/

#include "LongTestValue.h"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

void printVecofVec(const std::vector<std::vector<int>>& vecvec) {
    std::cout << '[';
    for (const auto& vec : vecvec) {
        std::cout << '[';
        for (const auto& num : vec) {
            std::cout << num << ' ';
        }
        std::cout << ']';
    }
    std::cout << ']' << '\n';
}

/*
 * THIS SOLUTION HITS THE TIME LIMIT
 * https://leetcode.com/submissions/detail/529811980/
*/
class Solution {
    std::vector<std::vector<int>> two_sum(const std::vector<int>& nums,
    size_t omit_cnt, int target) {
        std::unordered_map <int, int> res;
        std::unordered_set<int> hashTable;
        for (size_t cnt = 0; cnt < nums.size(); ++cnt) {
            if (cnt == omit_cnt)
                continue;
            if (hashTable.find(target - nums[cnt]) != hashTable.end()) {
                auto temp_res = target - nums[cnt];
                // check if this solution has been found before
                if (res.find(nums[cnt]) == res.end() &&
                    res.find(temp_res) == res.end()) {
                        res[target - nums[cnt]] = nums[cnt];
                    }
            } else {
                hashTable.insert(nums[cnt]);
            }
        }
        std::vector<std::vector<int>> fres;
        for (auto & itm : res) {
            std::vector<int> temp;
            temp.push_back(itm.first);
            temp.push_back(itm.second);
            fres.emplace_back(temp);
        }
        return fres;
    }

 public:
    std::vector<std::vector<int>> threeSum(const std::vector<int>& nums) {
        std::unordered_set<int> doneNums;
        std::vector<std::vector<int>> res;
        std::unordered_set<std::string> res_str;
        for (size_t cnt = 0; cnt < nums.size(); ++cnt) {
            if (doneNums.find(nums[cnt]) == doneNums.end()) {
                auto t_res = two_sum(nums, cnt, -nums[cnt]);
                std::for_each(t_res.begin(), t_res.end(),
                    [&](std::vector<int> & vec){
                        vec.push_back(nums[cnt]);
                        std::sort(vec.begin(), vec.end());
                        });
                // make sure the results didn't happen before
                for (auto& pvec : t_res) {
                    std::string t_key = std::to_string(pvec[0]) +
                        std::to_string(pvec[1]) + std::to_string(pvec[2]);
                    if (res_str.find(t_key) == res_str.end()) {
                        res_str.emplace(t_key);
                        res.emplace_back(pvec);
                    }
                }
                doneNums.insert(nums[cnt]);
            }
        }

        return res;
    }
};

/* Runtime: 60 ms, faster than 89.41% of C++ online submissions for 3Sum.
 * Memory Usage: 21.1 MB, less than 48.46% of C++ online submissions for 3Sum.
 * https://leetcode.com/submissions/detail/530312480/
*/
class Solution2 {
 public:
    std::vector<std::vector<int>> threeSum(const std::vector<int>& in_nums) {
        std::vector<int> nums{in_nums};
        std::vector<std::vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        std::sort(nums.begin(), nums.end());
        for (size_t cnt = 0; cnt < nums.size(); ++cnt) {
            size_t lb = cnt + 1;
            size_t ub = nums.size() - 1;
            auto target = nums[cnt];
            while (lb < ub) {
                auto sum = nums[lb] + nums[ub];
                if (sum + target > 0) {
                    --ub;
                } else if (sum + target < 0) {
                    ++lb;
                } else {
                    std::vector<int> temp_res(3);
                    temp_res[0] = nums[cnt];
                    temp_res[1] = nums[lb];
                    temp_res[2] = nums[ub];
                    res.emplace_back(temp_res);
                    while (lb < ub && nums[lb] == nums[lb + 1]) {
                        ++lb;
                    }
                    while (lb < ub && nums[ub] == nums[ub - 1]) {
                        --ub;
                    }
                    ++lb;
                    --ub;
                }
            }
            while (cnt + 1 < nums.size() && nums[cnt + 1] == target) {
                ++cnt;
            }
        }
        return res;
    }
};

int main(void) {
    auto obj = Solution2();
    printVecofVec(obj.threeSum({3, 0, -2, -1, 1, 2}));
    std::cout << "--------\n";
    printVecofVec(obj.threeSum({-1, 0, 1, 2, -1, -4, 3, 4, 4}));
    std::cout << "--------\n";
    printVecofVec(obj.threeSum({-1, 0, 1, 2, -1, -4}));
    std::cout << "--------\n";
    printVecofVec(obj.threeSum({0, -1, 0, 0, 1}));
    std::cout << "--------\n";
    printVecofVec(obj.threeSum({}));
    std::cout << "--------\n";
    printVecofVec(obj.threeSum({0}));
    std::cout << "--------\n";
    printVecofVec(obj.threeSum({0, 0, 0, 0}));
    std::cout << "--------\n";
    obj.threeSum(LongTestVector());
    std::cout << "--------\n";
    return 0;
}
