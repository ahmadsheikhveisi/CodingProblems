/* COPYRIGHT
* A phrase is a palindrome if, after converting all uppercase letters into lowercase
* letters and removing all non-alphanumeric characters, it reads the same forward and backward.
* Alphanumeric characters include letters and numbers.
* 
* Given a string s, return true if it is a palindrome, or false otherwise.
* 
*  
* 
* Example 1:
* 
* Input: s = "A man, a plan, a canal: Panama"
* Output: true
* Explanation: "amanaplanacanalpanama" is a palindrome.
* 
* Example 2:
* 
* Input: s = "race a car"
* Output: false
* Explanation: "raceacar" is not a palindrome.
* 
* Example 3:
* 
* Input: s = " "
* Output: true
* Explanation: s is an empty string "" after removing non-alphanumeric characters.
* Since an empty string reads the same forward and backward, it is a palindrome.
* 
*  
* 
* Constraints:
* 
*     1 <= s.length <= 2 * 10^5
*     s consists only of printable ASCII characters.
* 
* 
*/

#ifndef VALID_PALINDROME_125
#define VALID_PALINDROME_125

#include <string>

class Solution {
 public:
    bool isPalindrome([[maybe_unused]] std::string s) {
        if (s.size() < 2) {
            return true;
        }
        size_t l{0};
        size_t r{s.size() - 1};
        while (l < r) {
            auto left = GetNum(s[l]);
            if (left == 0) {
                ++l;
                continue;
            }
            auto right = GetNum(s[r]);
            if (right == 0) {
                --r;
                continue;
            }
            if (left != right) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
 private:
    static constexpr char GetNum(char chr) {
        if ((chr >= 'A') && (chr <= 'Z')) {
            return (chr - 'A') + 'a';
        } else if ((chr >= 'a') && (chr <= 'z')) {
            return chr;
        } else if ((chr >= '0') && (chr <= '9')) {
            return chr;
        }
        return 0;
    }
    /*
        if (s.size() < 2) {
            return true;
        }
        size_t l{0};
        size_t r{s.size() - 1};
        while (l < r) {
            if (std::isalnum(s[l]) == 0) {
                ++l;
                continue;
            }
            if (std::isalnum(s[r]) == 0) {
                --r;
                continue;
            }
            if (std::tolower(s[l]) != std::tolower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    */
};
#endif // VALID_PALINDROME_125
