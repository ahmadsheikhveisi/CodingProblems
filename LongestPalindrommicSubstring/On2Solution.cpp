/* COPYRIGHT
 * This solution is O(n^2)
*/

#include "On2Solution.h"

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

std::string On2Solution::longestPalindrome(std::string_view str) {
    std::vector<std::vector<bool>> hashTable(str.size(),
        std::vector<bool>(str.size()));
    size_t max_size = 1;
    size_t start_index = 0;
    // all palindrome length 1
    for (size_t cnt = 0; cnt < str.size(); ++cnt) {
        hashTable[cnt][cnt] = true;
    }
    // all palindrome length 2
    for (size_t cnt = 0; cnt < str.size() - 1; ++cnt) {
        hashTable[cnt][cnt + 1] = is_palindromic(str.substr(cnt, 2));
        if (hashTable[cnt][cnt + 1] == true && max_size < 2) {
            start_index = cnt;
            max_size = 2;
        }
    }
    // all other
    for (size_t clmn = 2; clmn < str.size(); ++clmn) {
        for (size_t row =  0; row < clmn - 1; ++row) {
            if (hashTable[row + 1][clmn - 1] && str[row] == str[clmn]) {
                hashTable[row][clmn] = true;
                auto t_len = clmn - row + 1;
                if (t_len > max_size) {
                    max_size = t_len;
                    start_index = row;
                }
            }
        }
    }
    return std::string(str.substr(start_index, max_size));
}
