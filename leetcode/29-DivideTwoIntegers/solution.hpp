/* COPYRIGHT
* Given two integers dividend and divisor, divide two integers without using multiplication,
* division, and mod operator.
* The integer division should truncate toward zero, which means losing its fractional part.
* For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
* Return the quotient after dividing dividend by divisor.
* Note: Assume we are dealing with an environment that could only store integers within
* the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem,
* if the quotient is strictly greater than 231 - 1,
* then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.
* Example 1:
* Input: dividend = 10, divisor = 3
* Output: 3
* Explanation: 10/3 = 3.33333.. which is truncated to 3.
* Example 2:
* Input: dividend = 7, divisor = -3
* Output: -2
* Explanation: 7/-3 = -2.33333.. which is truncated to -2.
* Constraints:
*     -2^31 <= dividend, divisor <= 2^31 - 1
*     divisor != 0
*/
#ifndef DIVIDE_TWO_INTEGERS_HPP_29
#define DIVIDE_TWO_INTEGERS_HPP_29

#include <cstdlib>
#include <cstdint>
#include <limits>
#include <climits>

class Solution {
public:
    // dividend = divisor * quotient + remainder
    // dividend = divisor * (2^31 * a_31 + 2^30 * a_30 + ... + 2^0 * a_0) + remainder
    // dividend = divisor * 2^31 * a_31 + divisor * 2^30 * a_30 + ... + divisor * 2^0 * a_0 + remainder
    // dividend / 2^31 = divisor * a_31 + divisor * 2^30 * a_30 / 2^31 + ... + divisor * 2^0 * a_0 / 2^31 + remainder / 2^31
    // dividend / 2^31 = divisor * a_31 + 0 + ... + 0 + 0
    int divide(std::int32_t dividend, std::int32_t divisor) {
        // min = 0x80000000
        // max = 0x7FFFFFFF
        // min / -1 = max + 1
        if (dividend == std::numeric_limits<std::int32_t>::min() && divisor == -1) {
            return std::numeric_limits<std::int32_t>::max();
        }
        std::int64_t dividend64{dividend};
        std::int64_t divisor64{divisor};
        std::int64_t quotient{0};
        bool is_negative{(dividend64 < 0) != (divisor64 < 0)};
        dividend64 = ((dividend64 < 0)?-1:1)*(dividend64);
        divisor64 = std::abs(divisor64);
        for (std::int32_t cnt{31}; cnt >= 0; --cnt) {
            if ((dividend64 >> cnt) >= divisor64) {
                quotient |= static_cast<std::int64_t>(1) << cnt;
                dividend64 -= divisor64 << cnt;
            }
        }
        if (is_negative) {
            quotient = -1 * quotient;
        }
        return static_cast<std::int32_t>(quotient);
    }
 private:
};


#endif // DIVIDE_TWO_INTEGERS_HPP_29
