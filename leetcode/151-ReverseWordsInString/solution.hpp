/* COPYRIGHT
* Given an input string s, reverse the order of the words.
* 
* A word is defined as a sequence of non-space characters.
* The words in s will be separated by at least one space.
* 
* Return a string of the words in reverse order concatenated by a single space.
* 
* Note that s may contain leading or trailing spaces or multiple spaces between two words.
* The returned string should only have a single space separating the words.
* Do not include any extra spaces.
* 
* Example 1:
* 
* Input: s = "the sky is blue"
* Output: "blue is sky the"
* 
* Example 2:
* 
* Input: s = "  hello world  "
hello world
dlrow olleh

* Output: "world hello"
* Explanation: Your reversed string should not contain leading or trailing spaces.
* 
* Example 3:
* 
* Input: s = "a good   example"
* Output: "example good a"
* Explanation: You need to reduce multiple spaces between two words to a
* single space in the reversed string.
* 
* Constraints:
* 
*     1 <= s.length <= 10^4
*     s contains English letters (upper-case and lower-case), digits, and spaces ' '.
*     There is at least one word in s.
* 
*  
* 
* Follow-up: If the string data type is mutable in your language,
* can you solve it in-place with O(1) extra space?
* 
*/
#ifndef REVERSE_WORDS_IN_STRING_151
#define REVERSE_WORDS_IN_STRING_151

#include <algorithm>
#include <string>

class Solution {
 public:
    std::string reverseWords([[maybe_unused]] std::string s) {
        size_t cnt{0};
        size_t start{0};
        size_t end{0};
        auto size = s.size();
        std::reverse(begin(s), std::end(s));

        while (cnt < size) {
            if (s[cnt] == ' ') {
                ++cnt;
                continue;
            }
            // found a word
            while ((cnt < size) && (s[cnt] != ' ')) {
                s[end] = s[cnt];
                ++cnt;
                ++end;
            }
            std::reverse(std::next(begin(s), start), std::next(begin(s), end));
            s[end] = ' ';
            ++end;
            start = end;
            ++cnt;
        }
        s.resize(end - 1);
        return s;
    }
 private:
};


#endif // REVERSE_WORDS_IN_STRING_151
