/* COPYRIGHT solution class
 * 
*/

#include "solution.hpp"

#include <algorithm>

namespace solution {

int Solution::AdjacentPoitMinDis(const std::vector<int>& arr, int x, int y) {
    int last_idx = -1;
    int min_dist = arr.size() + 1;
    for (int cnt{0}; cnt < arr.size(); ++cnt) {
        if (arr[cnt] == x || arr[cnt] == y) {
            if (last_idx != -1 && arr[cnt] != arr[last_idx]) {
                min_dist = std::min(min_dist, std::abs(last_idx - cnt));
            }
            last_idx = cnt;
        }
    }
    return min_dist != arr.size() + 1?min_dist:-1;
}

}  // namespace solution
