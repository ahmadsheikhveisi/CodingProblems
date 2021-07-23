/* COPYRIGHT
 * https://leetcode.com/submissions/detail/527088910/
 * Runtime: 8 ms, faster than 85.71% of C++ online submissions for Longest Substring Without Repeating Characters.
 * Memory Usage: 8.3 MB, less than 70.16% of C++ online submissions for Longest Substring Without Repeating Characters.
*/

#include "BestSolution.h"

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <unordered_map>

size_t BestSolution::lengthOfLongestSubstring(std::string_view str) {
    std::vector<int> hashTable(256, -1);
    size_t max_len = 0;
    size_t start_indx = 0;
    size_t t_idx = 0;
    size_t t_len = 0;
    for (size_t cnt = 0; cnt < str.size(); ++cnt) {
        if (hashTable[str[cnt]] >= 0) {
            if (t_len > max_len) {
                start_indx = t_idx;
                max_len = t_len;
            }
            // remove all the characters until the last occurence
            auto last_occurance_idx = hashTable[str[cnt]];
            for (size_t chr = t_idx; chr < last_occurance_idx; ++chr) {
                hashTable[str[chr]] = -1;
            }
            t_idx = hashTable[str[cnt]] + 1;
            t_len = cnt - hashTable[str[cnt]];
            hashTable[str[cnt]] = cnt;
        } else {
            hashTable[str[cnt]] = cnt;
            t_len++;
        }
    }
    if (t_len > max_len) {
        start_indx = t_idx;
        max_len = t_len;
    }
    // std::cout << str.substr(start_indx, max_len) << '\n';
    return max_len;
}
