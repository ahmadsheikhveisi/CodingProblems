/* COPYRIGHT
*/

#include <string>
#include <algorithm>
#include <string_view>
#include <vector>
#include <iostream>
#include <unordered_set>

void permutation(std::string prefix, std::string str,
                std::unordered_set<std::string> *mset) {
    if (str.size() == 0) {
        if (mset->find(prefix) == mset->end()) {
            std::cout << "out " << prefix << '\n';
            mset->insert(prefix);
        }
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
            permutation(pre, rem, mset);
         }
        // std::cout << "return " << prefix << " str " << str << '\n';
    }
}

void permutation(std::string str) {
    std::unordered_set<std::string> mset;
    permutation("", str, &mset);
}


int main(void) {
    permutation("1114");
    return 0;
}
