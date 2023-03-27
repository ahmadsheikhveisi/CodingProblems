/* COPYRIGHT
*/

#include <string>
#include <algorithm>
#include <string_view>
#include <vector>
#include <iostream>

void permutation(std::string_view prefix, std::string_view str) {
    if (str.size() == 0) {
        std::cout << "out " << prefix << '\n';
    } else {
        // std::cout << '\n';
        // std::cout << "prefix " << prefix << " str " << str << '\n';
        for (size_t i = 0; i < str.size(); ++i) {
            // std::cout << i << " prefix " << prefix << " str " << str << '\n';
            auto rem1 = std::string(str.substr(0, i));
            auto rem2 = std::string(str.substr(i + 1));
            auto rem = rem1 + rem2;
            auto pre2 = std::string{str[i]};
            auto pre = std::string(prefix) + pre2;
            // std::cout << i << " pre " << pre << " rem " << rem << '\n';
            permutation(pre, rem);
         }
        // std::cout << "return " << prefix << " str " << str << '\n';
    }
}

void permutation(std::string_view str) {
    permutation("", str);
}


int main(void) {
    permutation("1234");
    return 0;
}
