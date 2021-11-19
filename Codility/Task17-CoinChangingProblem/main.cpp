/* COPYRIGHT
 * 
*/

#include <iostream>

#include "solution.hpp"

void printvec(const std::vector<int>& vec) {
    std::cout << '[';
    for (const auto& itm : vec) {
        std::cout << itm << ' ';
    }
    std::cout << ']';
    std::cout << '\n';
}

int main() {
    Solution sol;
    printvec(sol.FindMinCoin(6, {1, 3, 4}));
    printvec(sol.FindMinCoin(0, {1, 3, 4}));
    printvec(sol.FindMinCoin(300, {15, 7}));
    return 0;
}
