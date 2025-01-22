/* COPYRIGHT
* Given an integer n, return the number of trailing zeroes in n!.
* 
* Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
* 
* Example 1:
* 
* Input: n = 3
* Output: 0
* Explanation: 3! = 6, no trailing zero.
* 
* Example 2:
* 
* Input: n = 5
* Output: 1
* Explanation: 5! = 120, one trailing zero.
* 
* Example 3:
* 
* Input: n = 0
* Output: 0
* 
* Constraints:
* 
*     0 <= n <= 104
*
* Follow up: Could you write a solution that works in logarithmic time complexity?
* 
*/
#ifndef FACTORIAL_TRAILING_ZEROS_172
#define FACTORIAL_TRAILING_ZEROS_172

#include <algorithm>

class Solution {
 public:
    int trailingZeroes(int n) {
        int count_5{0};
        while (n >= 5) {
            count_5 += n / 5;
            n /= 5;
        }
        return count_5;
    }
    int trailingZeroes_longer([[maybe_unused]] int n) {
        int temp{n};
        int count_5{0};
        temp = temp - (temp % 5);
        while (temp >= 5) {
            count_5 += temp / 5;
            temp = temp - (temp % 5);
            temp /= 5;
        }
        // there is always more 2s than 5s in n!
        // so we only need to count the number of 5s
        /*temp = n;
        int count_2{0};
        temp = temp - (temp % 2);
        while (temp >= 2) {
            count_2 += temp / 2;
            temp = temp - (temp % 2);
            temp /= 2;
        }
        return std::min(count_5, count_2);
        */
        return count_5;
    }
 private:
};

#endif // FACTORIAL_TRAILING_ZEROS_172
