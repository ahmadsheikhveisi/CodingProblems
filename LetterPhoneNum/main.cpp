/* COPYRIGHT Letter Combinations of a Phone Number
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * 
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations 
 * that the number could represent. Return the answer in any order.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * 
 * Example 1:
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * Example 2:
 * 
 * Input: digits = ""
 * Output: []
 * 
 * Example 3:
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * Constraints:
 * 
 *     0 <= digits.length <= 4
 *     digits[i] is a digit in the range ['2', '9'].
*/

#include <vector>
#include <iostream>
#include <string_view>
#include <cmath>
#include <array>

/* https://leetcode.com/submissions/detail/545529440/
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
 * Memory Usage: 6.6 MB, less than 63.02% of C++ online submissions for Letter Combinations of a Phone Number.
 *
*/
class Solution {
    const std::vector<std::vector<char>> mapNumToAlphabet{
        std::vector<char>{' '},  // 0
        std::vector<char>{},  // 1
        std::vector<char>{'a', 'b', 'c'},  // 2
        std::vector<char>{'d', 'e', 'f'},  // 3
        std::vector<char>{'g', 'h', 'i'},  // 4
        std::vector<char>{'j', 'k', 'l'},  // 5
        std::vector<char>{'m', 'n', 'o'},  // 6
        std::vector<char>{'p', 'q', 'r', 's'},  // 7
        std::vector<char>{'t', 'u', 'v'},  // 8
        std::vector<char>{'w', 'x', 'y', 'z'},  // 9
    };
    /*static constexpr char mapNumToAlphabet[10][4]{
        {' '},
        {},  // 1
        {'a', 'b', 'c'},  // 2
        {'d', 'e', 'f'},  // 3
        {'g', 'h', 'i'},  // 4
        {'j', 'k', 'l'},  // 5
        {'m', 'n', 'o'},  // 6
        {'p', 'q', 'r', 's'},  // 7
        {'t', 'u', 'v'},  // 8
        {'w', 'x', 'y', 'z'},  // 9
    };*/

    void addAlphabetToVec(std::string str,
        std::vector<std::string>* vec,
        std::string_view digits,
        size_t cnt) {
        if (str.size() == digits.size()) {
            vec->push_back(str);
            return;
        }
        for (auto chr : mapNumToAlphabet[digits[cnt] - 0x30]) {
            addAlphabetToVec(str + chr, vec, digits, cnt + 1);
        }
    }

 public:
    std::vector<std::string> letterCombinations(std::string_view digits) {
        std::vector<std::string> res;
        if (digits.size() == 0) {
            return res;
        }
        res.reserve(powl(4, digits.size()));
        addAlphabetToVec("", &res, digits, 0);
        return res;
    }
};

void printvec(const std::vector<std::string>& vec) {
    for (auto str : vec) {
        std::cout << str << ' ';
    }
    std::cout << '\n';
}

int main(void) {
    auto obj = Solution();
    printvec(obj.letterCombinations("23"));
    printvec(obj.letterCombinations(""));
    printvec(obj.letterCombinations("2"));
    return 0;
}
