/* COPYRIGHT
*/

#include <string>
#include <algorithm>
#include <string_view>
#include <vector>
#include <iostream>
#include <unordered_set>

void permutation(std::string& str, size_t const left, size_t const right,
                 std::unordered_set<std::string>& mset) {
    if (left == right) {
        std::cout << str;
        auto itr = mset.find(str);
        if (itr != mset.end()) {
            std::cout << " !";
        } else {
            mset.insert(str);
        }
        std::cout << '\n';
    } else {
        for (size_t cnt = left; cnt <= right; ++cnt) {
            if (cnt > left && str[left] == str[cnt]) {
                continue;
            }
            if (cnt > left && str[cnt - 1] == str[cnt]) {
                continue;
            }
            std::swap(str[left], str[cnt]);
            permutation(str, left + 1, right, mset);
            std::swap(str[left], str[cnt]);
        }
    }
}

int main() {
    std::string str{"ABBB"};
    std::unordered_set<std::string> mset;
    permutation(str, 0 , str.size() - 1, mset);
    return 0;
}
