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
        permute("(", n - 1, n);
        return results;
    }
 private:
    std::vector<std::string> results{};
    void permute(std::string pre, int open_cnt, int close_cnt) {
        if ((open_cnt == 0) && (close_cnt == 0)) {
            results.push_back(pre);
            return;
        }
        if (open_cnt > 0) {
            permute(pre + "(", open_cnt - 1, close_cnt);
        }
        if (open_cnt < close_cnt) {
            permute(pre + ")", open_cnt, close_cnt - 1);
        }
    }
};


#endif // GENERATE_PARENTHESES_HPP_22
