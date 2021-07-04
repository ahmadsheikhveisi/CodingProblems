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

int CountConstrunct(const std::string& targetStr,
        const std::vector<std::string>& wordBank) {
    std::unordered_map<std::string, int> hashTable;
    return CountConstruct_(targetStr, wordBank, &hashTable);
}

int main() {
    std::cout << CountConstrunct("abcdef", {"ab", "cf", "abc", "cd",
                          "abef", "def", "abcd"}) << '\n';
    std::cout << CountConstrunct("purple", {"purp", "p", "ur", "le",
                          "purpl"}) << '\n';
    std::cout << CountConstrunct("skateboard", {"bo", "rd", "ate",
                  "t", "ska", "sk", "boar"}) << '\n';
    std::cout << CountConstrunct("enterapotentpot", {"a", "p", "ent",
                  "enter", "ot", "o", "t"}) << '\n';
    std::cout << CountConstrunct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                {"e", "ee", "eee", "eeee", "eeeeee",
                "eeeeeee", "eeeeeeee", "eeeeeeeee"}) << '\n';
    return 0;
}
