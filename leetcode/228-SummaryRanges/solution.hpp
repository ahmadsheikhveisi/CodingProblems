/* COPYRIGHT
* You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
That is, each element of nums is covered by exactly one of the ranges,
and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

    "a->b" if a != b
    "a" if a == b

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

Constraints:

    0 <= nums.length <= 20
    -2^31 <= nums[i] <= 2^31 - 1
    All the values of nums are unique.
    nums is sorted in ascending order.
*/
#ifndef SUMMARY_RANGES_228
#define SUMMARY_RANGES_228

#include <array>
#include <charconv>
#include <cstdint>
#include <sstream>
#include <string>
#include <vector>

class Solution {
 public:
    std::vector<std::string> summaryRanges([[maybe_unused]] std::vector<int>& nums) {
        std::vector<std::string> vec{};
        for (size_t i{0}; i < nums.size(); ++i) {
            std::int64_t start{nums[i]};
            while (((i + 1) < nums.size()) &&
                (static_cast<std::int64_t>(nums[i + 1]) == (static_cast<std::int64_t>(nums[i]) + 1))) {
                ++i;
            }
            constexpr size_t max_size{25}; // -2^31 -> 11 digits + 2 for "->" + 1 for null terminator
            std::array<char, max_size> buffer{};
            auto result = std::to_chars(begin(buffer), end(buffer), start);
            if (start != nums[i]) {
                *result.ptr++ = '-';
                *result.ptr++ = '>';
                result = std::to_chars(result.ptr, end(buffer), nums[i]);
            }
            vec.emplace_back(std::string{buffer.data(), result.ptr});
        }
        return vec;
    }
 private:
};


#endif // SUMMARY_RANGES_228
