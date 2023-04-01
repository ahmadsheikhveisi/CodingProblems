/* COPYRIGHT
*/

#include <string>
#include <algorithm>
#include <string_view>
#include <vector>
#include <iostream>

void permutation(std::string& str, size_t const left, size_t const right) {
    if (left == right) {
        std::cout << str << '\n';
    } else {
        for (size_t cnt = left; cnt <= right; ++cnt) {
            std::swap(str[left], str[cnt]);
            permutation(str, left + 1, right);
            std::swap(str[left], str[cnt]);
        }
    }
}

int main() {
    std::string str{"123"};
    permutation(str, 0 , str.size() - 1);
    return 0;
}
