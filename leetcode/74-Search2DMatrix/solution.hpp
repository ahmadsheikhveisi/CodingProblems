/* COPYRIGHT
* You are given an m x n integer matrix matrix with the following two properties:
* 
*     Each row is sorted in non-decreasing order.
*     The first integer of each row is greater than the last integer of the previous row.
* 
* Given an integer target, return true if target is in matrix or false otherwise.
* 
* You must write a solution in O(log(m * n)) time complexity.
* 
*  
* 
* Example 1:
* 
* Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
* Output: true
* 
* Example 2:
* 
* Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
* Output: false
* 
*  
* 
* Constraints:
* 
*     m == matrix.length
*     n == matrix[i].length
*     1 <= m, n <= 100
*     -10^4 <= matrix[i][j], target <= 10^4
* 
* 
*/
#ifndef SEARCH_2D_MATRIX_74
#define SEARCH_2D_MATRIX_74

#include <vector>

class Solution {
 public:
    bool searchMatrix([[maybe_unused]] std::vector<std::vector<int>> const& matrix, int target) {
        if (matrix.empty()) return false;
        auto m = matrix.size();
        auto n = matrix[0].size();
        int low{0};
        auto high = static_cast<int>(m*n - 1);
        while (low < high) {
            auto mid = low + (high - low) / 2;
            auto m_index = mid / n;
            auto n_index = mid % n;
            auto candidate = matrix[m_index][n_index];
            if (candidate == target) {
                return true;
            } else if (candidate > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return matrix[low/n][low%n] == target;
    }
 private:
};


#endif // SEARCH_2D_MATRIX_74
