/* COPYRIGHT
 * https://leetcode.com/submissions/detail/526772587/
 * Runtime: 12 ms, faster than 94.90% of C++ online submissions for Longest Palindromic Substring.
 * Memory Usage: 12.8 MB, less than 50.32% of C++ online submissions for Longest Palindromic Substring.
*/

#include "BestSolution.h"

#include <string>
#include <iostream>

std::string BestSolution::longestPalindrome(std::string_view s) {
    if (is_palindromic(s)) {
        return std::string(s);
    }
    size_t max_size = 1;
    size_t start_index = 0;
    size_t t_indx = 0;
    size_t t_size = 1;

    for (size_t cnt = 0; cnt < s.size(); ++cnt) {
        ++t_size;
        // auto temp = s.substr(t_indx, t_size);
        if (t_indx > 0) {
            // temp = s.substr(t_indx - 1, t_size);
            if (is_palindromic(s.substr(t_indx - 1, t_size + 1)) == true) {
                --t_indx;
                ++t_size;
            }
        }
        // temp = s.substr(t_indx, t_size);
        while (is_palindromic(s.substr(t_indx, t_size)) == false) {
            ++t_indx;
            --t_size;
        }
        // temp = s.substr(t_indx, t_size);
        if (t_size > max_size) {
            start_index = t_indx;
            max_size = t_size;
        }
    }

    return std::string(s.substr(start_index, max_size));
}
