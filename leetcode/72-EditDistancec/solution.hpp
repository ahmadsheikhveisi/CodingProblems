/* COPYRIGHT
* Given two strings word1 and word2, return the minimum number of operations required to
* convert word1 to word2.
* 
* You have the following three operations permitted on a word:
* 
*     Insert a character
*     Delete a character
*     Replace a character
* 
*  
* 
* Example 1:
* 
* Input: word1 = "horse", word2 = "ros"
* Output: 3
* Explanation: 
* horse -> rorse (replace 'h' with 'r')
* rorse -> rose (remove 'r')
* rose -> ros (remove 'e')
* 
* Example 2:
* 
* Input: word1 = "intention", word2 = "execution"
* Output: 5
* Explanation: 
* intention -> inention (remove 't')
* inention -> enention (replace 'i' with 'e')
* enention -> exention (replace 'n' with 'x')
* exention -> exection (replace 'n' with 'c')
* exection -> execution (insert 'u')
* 
*  
* 
* Constraints:
* 
*     0 <= word1.length, word2.length <= 500
*     word1 and word2 consist of lowercase English letters.
* 
* 
*/
#ifndef EDIT_DISTANCE_72
#define EDIT_DISTANCE_72

#include <string>
#include <vector>

class Solution {
 public:
    int editDistance([[maybe_unused]] std::string word1, [[maybe_unused]] std::string word2) {
        if ((word1.size() == 0) || (word2.size() == 0)) {
            return static_cast<int>(std::max(word1.size(), word2.size()));
        }
        // s1 is the shorter
        // s2 is the longer
        auto s1_size = std::min(word1.size(), word2.size());
        auto s2_size = s1_size == word1.size() ? word2.size() : word1.size();
        std::string& s1{s1_size == word1.size() ? word1 : word2};
        std::string& s2{s1_size == word1.size() ? word2 : word1};
        // s2 is the row
        // s1 is the columns.
        std::vector<std::vector<size_t>> dp(s2_size + 1, std::vector<size_t>(s1_size + 1, 0));
        for (size_t cnt{0}; cnt <= s1_size; ++cnt) {
            dp[0][cnt] = cnt;
        }
        for (size_t cnt{0}; cnt <= s2_size; ++cnt) {
            dp[cnt][0] = cnt;
        }
        for (size_t cnt2{1}; cnt2 <= s2_size; ++cnt2) {
            for (size_t cnt1{1}; cnt1 <= s1_size; ++cnt1) {
                if (s1[cnt1 - 1] == s2[cnt2 - 1]) {
                    dp[cnt2][cnt1] = dp[cnt2 - 1][cnt1 - 1];
                } else {
                    dp[cnt2][cnt1] = 1 + std::min(dp[cnt2 - 1][cnt1], std::min(dp[cnt2][cnt1 - 1],
                                                dp[cnt2 - 1][cnt1 - 1]));
                }
            }
        }
        return static_cast<int>(dp[s2_size][s1_size]);
    }
 private:
};


#endif // EDIT_DISTANCE_72
