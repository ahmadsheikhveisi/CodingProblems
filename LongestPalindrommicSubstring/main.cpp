/* COPYRIGHT
 * Given a string s, return the longest palindromic 
 * substring in s.
*/

#include "BestSolution.h"
#include "On2Solution.h"

#include <string>
#include <iostream>

int main(void) {
    auto obj = BestSolution();
    std::cout << obj.longestPalindrome("babad") << '\n';  // "bab"
    std::cout << obj.longestPalindrome("cbbd") << '\n';  // "bb"
    std::cout << obj.longestPalindrome("aaaazaaa") << '\n';  // "aaazaaa"
    std::cout << obj.longestPalindrome("ac") << '\n';  // "a"
    return 0;
}
