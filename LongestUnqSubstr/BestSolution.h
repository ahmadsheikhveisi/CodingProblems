/* COPYRIGHT
*/

#ifndef LONGESTUNQSUBSTR_BESTSOLUTION_H_
#define LONGESTUNQSUBSTR_BESTSOLUTION_H_

#include <string>

#include "Solution.h"

class BestSolution : Solution {
 public:
    size_t lengthOfLongestSubstring(std::string_view s) override;
};

#endif  // LONGESTUNQSUBSTR_BESTSOLUTION_H_
