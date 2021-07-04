/* COPYRIGHT
 * return all of the ways a target strign can be
 * constructed from the elements of string.
 * you may reuse the elements
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

// time complexity O(size)
// space complexity
std::vector<std::vector<std::string>>
AllConstruct_(const std::string& targetStr,
    const std::vector<std::string> wordBank,
    std::unordered_map<std::string,
        std::vector<std::vector<std::string>>>* hashTable) {
    if (hashTable->find(targetStr) != hashTable->end()) {
        return hashTable->at(targetStr);
    }
    std::vector<std::vector<std::string>> res;
    for (const auto& word : wordBank) {
        std::vector<std::string> word_res;
        auto pos = targetStr.find(word);
        if (pos != std::string::npos && pos == 0) {
            std::string temp{targetStr};
            temp.erase(pos, word.size());
            if (temp.empty()) {
                word_res.push_back(word);
                res.push_back(word_res);
            } else {
                auto temp_res = AllConstruct_(temp, wordBank, hashTable);
                if (temp_res.size() != 0) {
                    word_res.push_back(word);
                }
                for (const auto& cnt_res : temp_res) {
                    std::vector<std::string> temp_word_res{word_res};
                    temp_word_res.insert(temp_word_res.end(),
                        cnt_res.begin(), cnt_res.end());
                    res.push_back(temp_word_res);
                }
            }
        }
    }
    (*hashTable)[targetStr] = res;
    return res;
}

std::vector<std::vector<std::string>>
AllConstruct(const std::string& targetStr,
    const std::vector<std::string> wordBank) {
    std::unordered_map<std::string,
        std::vector<std::vector<std::string>>> hashTable;
    return AllConstruct_(targetStr, wordBank, &hashTable);
}

void printres(const std::vector<std::vector<std::string>> res) {
    for (const auto& vec : res) {
        for (const auto& word : vec) {
            std::cout << word << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    printres(AllConstruct("purple", {"purp", "p", "ur", "le",
                          "purpl"}));
    printres(AllConstruct("enterapotentpot", {"a", "p", "ent",
                  "enter", "ot", "o", "t"}));
    printres(AllConstruct("abcdef", {"ab", "abc", "cd",
                  "def", "abcd", "ef", "c"}));
    printres(AllConstruct("hello", {"ab", "abc", "cd",
                  "def", "abcd", "ef", "c"}));
    printres(AllConstruct("", {"ab", "abc", "cd",
                  "def", "abcd", "ef", "c"}));
    printres(AllConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                {"e", "ee", "eee", "eeee", "eeeeee",
                "eeeeeee", "eeeeeeee", "eeeeeeeee"}));
    return 0;
}
