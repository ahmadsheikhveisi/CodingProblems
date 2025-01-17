/* COPYRIGHT
* There are n children standing in a line. Each child is assigned a rating
* value given in the integer array ratings.
* 
* You are giving candies to these children subjected to the following requirements:
* 
*     Each child must have at least one candy.
*     Children with a higher rating get more candies than their neighbors.
* 
* Return the minimum number of candies you need to have to distribute the candies to the children.
* 
* Example 1:
* Input: ratings = [1,0,2]
* Output: 5
* Explanation: You can allocate to the first, second and third child with 2, 1, 2
* candies respectively.
* 
* Example 2:
* Input: ratings = [1,2,2]
* Output: 4
* Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
* The third child gets 1 candy because it satisfies the above two conditions.
* 
* Constraints:
* 
*     n == ratings.length
*     1 <= n <= 2 * 10^4
*     0 <= ratings[i] <= 2 * 10^4
*/
#ifndef CANDY_135
#define CANDY_135

#include <numeric>
#include <vector>

class Solution {
 public:
    int candy([[maybe_unused]] std::vector<int>& ratings) {
        if (ratings.size() == 0) {
            return 0;
        }
        if (ratings.size() == 1) {
            return 1;
        }

        int total{1};  // Start with 1 candy for the first child
        int up = 0, down = 0, peak = 0; // Variables to track slopes and peak candies

        for (size_t i{1}; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                // Increasing slope
                up++;
                peak = up;
                down = 0; // Reset down slope
                total += up + 1;
            } else if (ratings[i] < ratings[i - 1]) {
                // Decreasing slope
                down++;
                up = 0; // Reset up slope
                total += down;
                // Adjust for the peak, as the peak is double-counted
                if (down > peak) {
                    total++;
                }
            } else {
                // Flat (equal ratings)
                up = down = 0;
                peak = 0;
                total += 1; // Each child gets at least 1 candy
            }
        }

        return total;
    }

    /// @brief Two pass greedy algorithm
    ///        this method use O(n) space and O(n) time
    /// @param ratings 
    /// @return total number of candies
    int candy_On_space([[maybe_unused]] std::vector<int>& ratings) {
        if (ratings.size() == 0) {
            return 0;
        }
        std::vector<int> candy(ratings.size(), 1);
        for (size_t i{1}; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for (int i{static_cast<int>(ratings.size()) - 2}; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = std::max(candy[i], candy[i + 1] + 1);
            }
        }
        return std::accumulate(begin(candy), end(candy), 0);
    }
 private:
};


#endif // CANDY_135
