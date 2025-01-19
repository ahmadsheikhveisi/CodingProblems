/* COPYRIGHT
* Given an m x n integer matrix matrix, if an element is 0,
* set its entire row and column to 0's.
* 
* You must do it in place.
* Example 1:
* 
* Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
* Output: [[1,0,1],[0,0,0],[1,0,1]]
* 
* Example 2:
* 
* Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
* Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
* 
* Constraints:
* 
*     m == matrix.length
*     n == matrix[0].length
*     1 <= m, n <= 200
*     -2^31 <= matrix[i][j] <= 2^31 - 1
* 
* Follow up:
* 
*     A straightforward solution using O(mn) space is probably a bad idea.
*     A simple improvement uses O(m + n) space, but still not the best solution.
*     Could you devise a constant space solution?
*/
#ifndef SET_MATRIX_ZEROES_73
#define SET_MATRIX_ZEROES_73

#include <vector>

class Solution {
 public:
    void setZeroes([[maybe_unused]] std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) return;
        auto rows = matrix.size();
        auto cols = matrix[0].size();
        bool zero_first_row{false};
        for (auto num : matrix[0]) {
            if (num == 0) {
                zero_first_row = true;
                break;
            }
        }
        bool zero_first_col{false};
        for (size_t row{0}; row < rows; ++row) {
            if (matrix[row][0] == 0) {
                zero_first_col = true;
                break;
            }
        }
        for (size_t row{1}; row < rows; ++row) {
            for (size_t col{1}; col < cols; ++col) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        for (size_t row{1}; row < rows; ++row) {
            if (matrix[row][0] == 0) {
                for (size_t col{1}; col < cols; ++col) {
                    matrix[row][col] = 0;
                }
            }
        }
        for (size_t col{1}; col < cols; ++col) {
            if (matrix[0][col] == 0) {
                for (size_t row{1}; row < rows; ++row) {
                    matrix[row][col] = 0;
                }
            }
        }
        if (zero_first_row) {
            for (size_t col{0}; col < cols; ++col) {
                matrix[0][col] = 0;
            }
        }
        if (zero_first_col) {
            for (size_t row{0}; row < rows; ++row) {
                matrix[row][0] = 0;
            }
        }
    }
 private:
};


#endif // SET_MATRIX_ZEROES_73
