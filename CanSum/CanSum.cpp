/* COPYRIGHT
 * is there a combination of numbers in 
 * array the sum of which is a given number.
 * we can use one or more of none unique
 * numbsers from array of non negative numbers.
*/

#include <array>
#include <iostream>
#include <unordered_map>

// time complexity for classical is O(Size^sum)
// space complexity for classical is O(sum)
template<std::size_t Size>
constexpr bool canSum(const std::array<int, Size>& inarr, int sum) {
    bool res = false;
    for (const auto & num : inarr) {
        if (sum == num) {
            res = true;
            break;
        } else if (sum > num) {
            res = canSum(inarr, sum - num);
            if (res == true) {
                break;
            }
        }
    }
    return res;
}

// time complexity for hash is O(m*n)
// space complexity for hash is O(m)
std::unordered_map<int, bool> possibleSum;
template<std::size_t Size>
constexpr bool canSum_hash(const std::array<int, Size>& inarr, int sum) {
    if (possibleSum.find(sum) != possibleSum.end()) {
        // std::cout << "found " << sum << '\n';
        return possibleSum[sum];
    }
    bool res = false;
    for (const auto & num : inarr) {
        if (sum == num) {
            res = true;
            break;
        } else if (sum > num) {
            res = canSum_hash(inarr, sum - num);
            if (res == true) {
                break;
            }
        }
    }
    // std::cout << res << ' ' << sum << '\n';
    possibleSum[sum] = res;
    return res;
}

int main() {
    std::cout << canSum_hash<2>({2, 3}, 7) << '\n';
    possibleSum.clear();
    std::cout << canSum_hash<4>({5, 3, 4, 7}, 7) << '\n';
    possibleSum.clear();
    std::cout << canSum_hash<2>({2, 4}, 7) << '\n';
    possibleSum.clear();
    std::cout << canSum_hash<3>({2, 3, 5}, 8) << '\n';
    possibleSum.clear();
    std::cout << canSum_hash<2>({7, 14}, 300) << '\n';
    possibleSum.clear();
    return 0;
}
