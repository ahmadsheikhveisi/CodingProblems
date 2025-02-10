/* COPYRIGHT
* Given an m x n matrix, return all elements of the matrix in spiral order.
* 
*  
* 
* Example 1:
* 
* Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
* Output: [1,2,3,6,9,8,7,4,5]
* 
* Example 2:
* 
* Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
* Output: [1,2,3,4,8,12,11,10,9,5,6,7]
* 
*  
* 
* Constraints:
* 
*     m == matrix.length
*     n == matrix[i].length
*     1 <= m, n <= 10
*     -100 <= matrix[i][j] <= 100
* 
* 
*/
#ifndef SET_MATRIX_ZEROES_73
#define SET_MATRIX_ZEROES_73

#include <vector>

class Solution {
 public:
    std::vector<int> spiralOrder([[maybe_unused]] std::vector<std::vector<int>>& matrix) {
        std::vector<int> result{};
        int m{static_cast<int>(matrix.size())};
        int n{static_cast<int>(matrix[0].size())};
        result.reserve(m*n);
        Unroll(matrix, result, 0, m - 1, 0, n - 1);
        return result;
    }
 private:
    void Unroll(std::vector<std::vector<int>>& matrix, std::vector<int>& result, int m_start, int m_end,
                int n_start, int n_end) {
        if ((m_start > m_end) || (n_end < n_start)) {
            return;
        }
        if (m_start == m_end) {
            for (int cnt{n_start}; cnt <= n_end; ++cnt) {
                result.push_back(matrix[m_start][cnt]);
            }
            return;
        } else if (n_start == n_end) {
            for (int cnt{m_start}; cnt <= m_end; ++cnt) {
                result.push_back(matrix[cnt][n_start]);
            }
            return;
        }
        // push the first row
        for (int cnt{n_start}; cnt < n_end; ++cnt) {
            result.push_back(matrix[m_start][cnt]);
        }
        // push the last column
        for (int cnt{m_start}; cnt < m_end; ++cnt) {
            result.push_back(matrix[cnt][n_end]);
        }
        // push the last row
        for (int cnt{n_end}; cnt > n_start; --cnt) {
            result.push_back(matrix[m_end][cnt]);
        }
        // push the first column
        for (int cnt{m_end}; cnt > m_start; --cnt) {
            result.push_back(matrix[cnt][n_start]);
        }
        Unroll(matrix, result, m_start + 1, m_end - 1, n_start + 1, n_end - 1);
    }
};


#endif // SET_MATRIX_ZEROES_73
