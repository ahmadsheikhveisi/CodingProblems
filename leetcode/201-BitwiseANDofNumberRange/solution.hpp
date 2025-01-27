/* COPYRIGHT
* Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

Example 1:

Input: left = 5, right = 7
Output: 4

Example 2:

Input: left = 0, right = 0
Output: 0

Example 3:

Input: left = 1, right = 2147483647
Output: 0

 

Constraints:

    0 <= left <= right <= 2^31 - 1


*/

#ifndef BITWISE_AND_OF_NUMBER_RANGE_201
#define BITWISE_AND_OF_NUMBER_RANGE_201

class Solution {
 public:
    int rangeBitwiseAnd([[maybe_unused]] int left, [[maybe_unused]] int right) {
        int bit_cnt{0};
        while (left != right) {
            left >>= 1;
            right >>= 1;
            ++bit_cnt;
        }
        return left << bit_cnt;
    }
 private:
};
#endif // BITWISE_AND_OF_NUMBER_RANGE_201
