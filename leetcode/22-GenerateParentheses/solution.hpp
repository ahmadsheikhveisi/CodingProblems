/* COPYRIGHT
* Given n pairs of parentheses, write a function to generate all combinations of
* well-formed parentheses.
* Example 1:
*
* Input: n = 3
* Output: ["((()))","(()())","(())()","()(())","()()()"]
* 
* Example 2:
* 
* Input: n = 1
* Output: ["()"]
* 
* Constraints:
*     1 <= n <= 8
*/
#ifndef GENERATE_PARENTHESES_HPP_22
#define GENERATE_PARENTHESES_HPP_22

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        return std::vector<std::string>(n, "");
    }
 private:
};


#endif // GENERATE_PARENTHESES_HPP_22
