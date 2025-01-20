/* COPYRIGHT
* You are given an m x n matrix board containing letters 'X' and 'O',
* capture regions that are surrounded:
* 
*     Connect: A cell is connected to adjacent cells horizontally or vertically.
*     Region: To form a region connect every 'O' cell.
*     Surround: The region is surrounded with 'X' cells
*         if you can connect the region with 'X' cells and none of the region cells
*         are on the edge of the board.
* 
* To capture a surrounded region, replace all 'O's with 'X's in-place within the original board.
* You do not need to return anything.
* 
* Example 1:
* Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
* 
* Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
* 
* Explanation:
* 
* In the above diagram, the bottom region is not captured because it is on the edge of the board
* and cannot be surrounded.
* 
* Example 2:
* Input: board = [["X"]]
* 
* Output: [["X"]]
* 
* Constraints:
* 
*     m == board.length
*     n == board[i].length
*     1 <= m, n <= 200
*     board[i][j] is 'X' or 'O'.
*/
#ifndef SURROUNDED_REGIONS_130
#define SURROUNDED_REGIONS_130

#include <array>
#include <charconv>
#include <cstdint>
#include <sstream>
#include <string>
#include <vector>

class Solution {
 public:
    void solve([[maybe_unused]] std::vector<std::vector<char>>& board) {
        if (board.empty()) return;
        rows_ = static_cast<int>(board.size());
        cols_ = static_cast<int>(board[0].size());
        if (rows_ < 3 || cols_ < 3) return;
        std::vector<std::vector<bool>> visited(rows_, std::vector<bool>(cols_, false));
        // visit all the cells connected to borders
        for (int i{0}; i < rows_; ++i) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                Visit(board, visited, i, 0);
            }
            if (board[i][cols_ - 1] == 'O' && !visited[i][cols_ - 1]) {
                Visit(board, visited, i, cols_ - 1);
            }
        }
        for (int j{0}; j < cols_; ++j) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                Visit(board, visited, 0, j);
            }
            if (board[rows_ - 1][j] == 'O' && !visited[rows_ - 1][j]) {
                Visit(board, visited, rows_ - 1, j);
            }
        }
        // flip all the cells that are not connected to the borders
        for (int i{0}; i < rows_; ++i) {
            for (int j{0}; j < cols_; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
 private:
    void Visit(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, int i, int j) {
        if ((i < 0) || (i >= rows_) || (j < 0) || (j >= cols_ ) || 
            (visited[i][j]) || (board[i][j] == 'X')) return;
        visited[i][j] = true;
        Visit(board, visited, i - 1, j);
        Visit(board, visited, i + 1, j);
        Visit(board, visited, i, j - 1);
        Visit(board, visited, i, j + 1);
    }
    




    void solve_O1_Space([[maybe_unused]] std::vector<std::vector<char>>& board) {
        if (board.empty()) return;
        rows_ = static_cast<int>(board.size());
        cols_ = static_cast<int>(board[0].size());
        if (rows_ < 3 || cols_ < 3) return;
        // Mark all 'O' cells that are connected to the border
        for (int i{0}; i < rows_; ++i) {
            if (board[i][0] == 'O') {
                Flip(board, i, 0, 'O', 'T');
            }
            if (board[i][cols_ - 1] == 'O') {
                Flip(board, i, cols_ - 1, 'O', 'T');
            }
        }
        for (int j{0}; j < cols_; ++j) {
            if (board[0][j] == 'O') {
                Flip(board, 0, j, 'O', 'T');
            }
            if (board[rows_ - 1][j] == 'O') {
                Flip(board, rows_ - 1, j, 'O', 'T');
            }
        }
        // Mark all 'O' cells that are not connected to the border
        for (int i{0}; i < rows_; ++i) {
            for (int j{0}; j < cols_; ++j) {
                if (board[i][j] == 'O') {
                    Flip(board, i, j, 'O', 'X');
                }
            }
        }
        // Restore the border cells
        for (int i{0}; i < rows_; ++i) {
            for (int j{0}; j < cols_; ++j) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void Flip(std::vector<std::vector<char>>& board, int i, int j, char from, char to) {
        if (i < 0 || i >= rows_ || j < 0 || j >= cols_ || board[i][j] != from) return;
        board[i][j] = to;
        Flip(board, i - 1, j, from, to);
        Flip(board, i + 1, j, from, to);
        Flip(board, i, j - 1, from, to);
        Flip(board, i, j + 1, from, to);
    }
    int rows_{0};
    int cols_{0};
};


#endif // SURROUNDED_REGIONS_130
