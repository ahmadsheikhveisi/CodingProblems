/* COPYRIGHT
*/

#ifndef LONGESTPALINDROMMICSUBSTRING_BESTSOLUTION_H_
#define LONGESTPALINDROMMICSUBSTRING_BESTSOLUTION_H_

#include <string>

#include "Solution.h"

class BestSolution : Solution {
 public:
    std::string longestPalindrome(std::string_view s) override;
};

#endif  // LONGESTPALINDROMMICSUBSTRING_BESTSOLUTION_H_
