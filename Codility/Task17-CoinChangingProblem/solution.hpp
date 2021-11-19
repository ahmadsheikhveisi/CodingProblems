/* COPYRIGHT solution class
 * This file defines solution class.
 * 
*/

#ifndef CODILITY_TASK17_COINCHANGINGPROBLEM_SOLUTION_HPP_
#define CODILITY_TASK17_COINCHANGINGPROBLEM_SOLUTION_HPP_

#include <vector>
#include <unordered_map>

class Solution {
 private:
    std::vector<int> FindMinCoinRec(int amount,
        const std::vector<int>& denominations,
        std::unordered_map<int, std::vector<int>>* dict);
 public:
    std::vector<int> FindMinCoin(int amount,
        const std::vector<int>& denominations);
};

#endif  // CODILITY_TASK17_COINCHANGINGPROBLEM_SOLUTION_HPP_
