/* COPYRIGHT
*/

#ifndef LONGESTPALINDROMMICSUBSTRING_SOLUTION_H_
#define LONGESTPALINDROMMICSUBSTRING_SOLUTION_H_

#include <string>

class Solution {
 public:
    virtual std::string longestPalindrome(std::string_view s) = 0;
 protected:
    bool is_palindromic(std::string_view s) {
        int len = s.size();
        int len_2 = len / 2;
        for (int cnt = 0; cnt < len_2; ++cnt) {
            if (s[cnt] != s[len - cnt - 1]) {
                // std::cout << s << " is NOT palindromic " << std::endl;
                return false;
            }
        }
        // std::cout << s << " is palindromic " << std::endl;
        return true;
    }
};

#endif  // LONGESTPALINDROMMICSUBSTRING_SOLUTION_H_
