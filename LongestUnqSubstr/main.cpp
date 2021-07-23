/* COPYRIGHT
 * Given a string s, find the length of the longest
 * substring without repeating characters.
 * 
 * Constraints
 * 0 <= s.length <= 5 * 104
 * s consists of English letters, digits, symbols and spaces.
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explaination: "abc"
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explaination: "b"
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explaination: "wke"
 * 
 * Input: s = ""
 * Output: 0
*/

#include "BestSolution.h"

#include <iostream>

int main(void) {
    auto obj = BestSolution();
    std::cout << obj.lengthOfLongestSubstring("dvdf") << '\n';
    std::cout << obj.lengthOfLongestSubstring("abcabcbb") << '\n';
    std::cout << obj.lengthOfLongestSubstring("bbbbb") << '\n';
    std::cout << obj.lengthOfLongestSubstring("pwwkew") << '\n';
    std::cout << obj.lengthOfLongestSubstring("") << '\n';
    return 0;
}
