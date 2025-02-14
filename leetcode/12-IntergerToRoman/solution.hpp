/* COPYRIGHT
* Seven different symbols represent Roman numerals with the following values:
* Symbol	Value
* I	1
* V	5
* X	10
* L	50
* C	100
* D	500
* M	1000
* 
* Roman numerals are formed by appending the conversions of decimal place values from highest to
* lowest. Converting a decimal place value into a Roman numeral has the following rules:
* 
*  -   If the value does not start with 4 or 9, select the symbol of the maximal value that can be
*          subtracted from the input, append that symbol to the result, subtract its value,
*          and convert the remainder to a Roman numeral.
*  -   If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted
*          from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I)
*          less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX),
*          40 (XL), 90 (XC), 400 (CD) and 900 (CM).
*  -   Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent
*      multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times.
*      If you need to append a symbol 4 times use the subtractive form.
* 
* Given an integer, convert it to a Roman numeral.
* 
*  
* 
* Example 1:
* 
* Input: num = 3749
* 
* Output: "MMMDCCXLIX"
* 
* Explanation:
* 
* 3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
*  700 = DCC as 500 (D) + 100 (C) + 100 (C)
*   40 = XL as 10 (X) less of 50 (L)
*    9 = IX as 1 (I) less of 10 (X)
* Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
* 
* Example 2:
* 
* Input: num = 58
* 
* Output: "LVIII"
* 
* Explanation:
* 
* 50 = L
*  8 = VIII
* 
* Example 3:
* 
* Input: num = 1994
* 
* Output: "MCMXCIV"
* 
* Explanation:
* 
* 1000 = M
*  900 = CM
*   90 = XC
*    4 = IV
* 
*  
* 
* Constraints:
* 
*     1 <= num <= 3999
* 
* 
*/

#ifndef INTEGER_TO_NUM_12
#define INTEGER_TO_NUM_12

#include <algorithm>
#include <array>
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>

class Solution {
 public:
    std::string intToRoman([[maybe_unused]] int num) {
        std::string result{};
        result.reserve(15);
        int cnt{1};
        while (num > 0) {
            auto digit = (num % 10) * cnt;
            if (digit != 0) {
                result = std::string{FindDigit(digit)} + result;
            } 
            num /= 10;
            cnt *= 10;
        }
        return result;
    }
 private:
    static constexpr const std::string_view& FindDigit(int digit) {
        size_t l{0};
        size_t r{digit_map.size() - 1};
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (digit_map[mid].first == digit) {
                return digit_map[mid].second;
            }
            if (digit_map[mid].first > digit) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return digit_map[l].second;
    }
    // std unordered map is a lot slower
    static constexpr std::array<std::pair<int, std::string_view>, 30> digit_map {
        std::make_pair<int, std::string_view>(1, "I"),
        std::make_pair<int, std::string_view>(2, "II"),
        std::make_pair<int, std::string_view>(3, "III"),
        std::make_pair<int, std::string_view>(4, "IV"),
        std::make_pair<int, std::string_view>(5, "V"),
        std::make_pair<int, std::string_view>(6, "VI"),
        std::make_pair<int, std::string_view>(7, "VII"),
        std::make_pair<int, std::string_view>(8, "VIII"),
        std::make_pair<int, std::string_view>(9, "IX"),
        std::make_pair<int, std::string_view>(10, "X"),
        std::make_pair<int, std::string_view>(20, "XX"),
        std::make_pair<int, std::string_view>(30, "XXX"),
        std::make_pair<int, std::string_view>(40, "XL"),
        std::make_pair<int, std::string_view>(50, "L"),
        std::make_pair<int, std::string_view>(60, "LX"),
        std::make_pair<int, std::string_view>(70, "LXX"),
        std::make_pair<int, std::string_view>(80, "LXXX"),
        std::make_pair<int, std::string_view>(90, "XC"),
        std::make_pair<int, std::string_view>(100, "C"),
        std::make_pair<int, std::string_view>(200, "CC"),
        std::make_pair<int, std::string_view>(300, "CCC"),
        std::make_pair<int, std::string_view>(400, "CD"),
        std::make_pair<int, std::string_view>(500, "D"),
        std::make_pair<int, std::string_view>(600, "DC"),
        std::make_pair<int, std::string_view>(700, "DCC"),
        std::make_pair<int, std::string_view>(800, "DCCC"),
        std::make_pair<int, std::string_view>(900, "CM"),
        std::make_pair<int, std::string_view>(1000, "M"),
        std::make_pair<int, std::string_view>(2000, "MM"),
        std::make_pair<int, std::string_view>(3000, "MMM"),
    };
};
#endif // INTEGER_TO_NUM_12
