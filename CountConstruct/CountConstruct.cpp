/* COPYRIGHT
 * return number of ways a target strign can be
 * constructed from the elements of string.
 * you may reuse the elements
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

// time complexity O(Size*targetLength^2)
// space complexity O(targetLength^2)
int CountConstruct_(const std::string& targetStr,
        const std::vector<std::string>& wordBank,
        std::unordered_map<std::string, int>* hashTable) {
    if (hashTable->find(targetStr) != hashTable->end()) {
        return hashTable->at(targetStr);
    }
    if (targetStr.empty()) {
        return 1;
    }
    int res = 0;
    for (const auto& word : wordBank) {
        auto pos = targetStr.find(word);
        if (pos != std::string::npos && pos == 0) {
            std::string temp{targetStr};
            temp.erase(pos, word.size());
            res += CountConstruct_(temp, wordBank, hashTable);
        }
    }

    (*hashTable)[targetStr] = res;
    return res;
}

int CountConstruct_table(const std::string_view targetStr,
        const std::vector<std::string>& wordBank) {
    std::vector<int> res(targetStr.size() + 1);
    res[0] = 1;
    for (size_t cnt = 0; cnt < res.size(); ++cnt) {
        if (res[cnt] > 0) {
            for (const auto& word : wordBank) {
                if (targetStr.substr(cnt, word.size()) == word) {
                    res[cnt + word.size()] += res[cnt];
                }
            }
        }
    }
    return res.back();
}

int CountConstrunct(const std::string& targetStr,
        const std::vector<std::string>& wordBank) {
    // std::unordered_map<std::string, int> hashTable;
    // return CountConstruct_(targetStr, wordBank, &hashTable);
    return CountConstruct_table(targetStr, wordBank);
}

int main() {
    std::cout << CountConstrunct("abcdef", {"ab", "cf", "abc", "cd",
                          "abef", "def", "abcd"}) << '\n';  // 1
    std::cout << CountConstrunct("purple", {"purp", "p", "ur", "le",
                          "purpl"}) << '\n';  // 2
    std::cout << CountConstrunct("skateboard", {"bo", "rd", "ate",
                  "t", "ska", "sk", "boar"}) << '\n';  // 0
    std::cout << CountConstrunct("enterapotentpot", {"a", "p", "ent",
                  "enter", "ot", "o", "t"}) << '\n';  // 4
    std::cout << CountConstrunct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                {"e", "ee", "eee", "eeee", "eeeeee",
                "eeeeeee", "eeeeeeee", "eeeeeeeee"}) << '\n';  // 0
    return 0;
}
