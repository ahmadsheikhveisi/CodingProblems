/* COPYRIGHT
 * Container With Most Water
 * https://leetcode.com/problems/container-with-most-water/
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at 
 * coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the
 * line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis 
 * forms a container, such that the container contains the most water.
 * 
 * Notice that you may not slant the container.
 * 
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
 * In this case, the max area of water (blue section) the container can contain is 49.
 * 
 * Example 2:
 * 
 * Input: height = [1,1]
 * Output: 1
 * 
 * Example 3:
 * 
 * Input: height = [4,3,2,1,4]
 * Output: 16
 * 
 * Example 4:
 * 
 * Input: height = [1,2,1]
 * Output: 2
 * 
 * Constraints:
 * 
 *     n == height.length
 *     2 <= n <= 10^5
 *     0 <= height[i] <= 10^4
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <limits>

class Solution {
    class minMaxIdx {
     public:
        size_t min_idx;
        size_t max_idx;
        explicit minMaxIdx(size_t idx) : min_idx(idx), max_idx(idx) {}
        void update(size_t idx) {
            max_idx = std::max(idx, max_idx);
            min_idx = std::min(idx, min_idx);
        }
    };

 public:
    int maxArea(const std::vector<int>& height) {
        size_t max_area = 0;
        std::map<int, minMaxIdx> hashTable;
        for (size_t cnt = 0; cnt < height.size(); ++cnt) {
            auto t_res = hashTable.emplace(
                std::make_pair(height[cnt], minMaxIdx(cnt)));
            if (t_res.second == false) {
                t_res.first->second.update(cnt);
            }
        }
        auto it = hashTable.rbegin();
        size_t min_idx = it->second.min_idx;
        size_t max_idx = it->second.max_idx;
        max_area = it->first * (max_idx - min_idx);
        ++it;
        for (; it != hashTable.rend(); ++it) {
            min_idx = std::min(it->second.min_idx, min_idx);
            max_idx = std::max(it->second.max_idx, max_idx);
            max_area = std::max(it->first * (max_idx - min_idx), max_area);
        }
        return max_area;
    }
};

class Solution2 {
 public:
    int maxArea(const std::vector<int>& height) {
        // ios_base::sync_with_stdio(false);   cin.tie(0); cout.tie(0);

        int ans = std::numeric_limits<int>::min();
        int lb = 0, ub = height.size()-1;
        while (lb < ub) {
            ans = std::max(ans,
            (ub-lb)*((height[lb] < height[ub])?height[lb++]:height[ub--]));
        }
        return ans;
    }
};

int main(void) {
    auto obj = Solution2();
    std::cout << obj.maxArea({8, 20, 1, 2, 3, 4, 5, 6}) << '\n';  // 42
    std::cout << obj.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << '\n';  // 49
    std::cout << obj.maxArea({1, 1}) << '\n';  // 1
    std::cout << obj.maxArea({4, 3, 2, 1, 4}) << '\n';  // 16
    std::cout << obj.maxArea({1, 2, 1}) << '\n';  // 2
    std::cout << obj.maxArea({1, 0, 8, 8, 0, 1}) << '\n';  // 8
    std::cout << obj.maxArea({1, 0, 6, 6, 0, 0, 0, 1}) << '\n';  // 7
    return 0;
}
