/* COPYRIGHT
 * return true if target strign can be
 * constructed from the elements of string.
 * you may reuse the elements
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

// time complexity is O(Size^targetLen*targetLen)
// space compexity is O(targetLen*targetLen))
bool canConstruct_replace(const std::string& targetStr,
    const std::vector<std::string>& wordBank) {
    if (std::all_of(targetStr.begin(), targetStr.end(),
        [](char chr){return chr == '*';})) {
        return true;
    }
    bool res = false;
    for (const auto& word : wordBank) {
        auto pos = targetStr.find(word);
        // another way can be only remove pos == 0
        if (pos != std::string::npos) {
            std::string temp{targetStr};
            // this is incorrect because creates incorrect string
            // temp.erase(pos, word.size());
            std::fill_n(temp.begin() + pos, word.size(), '*');
            // std::cout << targetStr << "\tfound " << word << ' ' << pos <<
            //        ' ' << word << ' ' << temp << '\n';
            if (canConstruct_replace(temp, wordBank) == true) {
                res = true;
                break;
            }
        }
    }
    return res;
}

bool canConstruct_remove(const std::string& targetStr,
    const std::vector<std::string>& wordBank) {
    if (targetStr.empty()) {
        return true;
    }
    bool res = false;
    for (const auto& word : wordBank) {
        auto pos = targetStr.find(word);
        if (pos != std::string::npos && pos == 0) {
            std::string temp{targetStr};
            temp.erase(pos, word.size());
            // std::cout << targetStr << "\tfound " << word << ' ' << pos <<
            //        ' ' << word << ' ' << temp << '\n';
            if (canConstruct_remove(temp, wordBank) == true) {
                res = true;
                break;
            }
        }
    }
    return res;
}

// time complexity is O(Size*targetLen*targetLen)
// space compexity is O(targetLen*targetLen))
bool canConstruct_remove_hash(const std::string& targetStr,
    const std::vector<std::string>& wordBank,
    std::unordered_map<std::string, bool>* hashTable) {
    if (hashTable->find(targetStr) != hashTable->end()) {
        return hashTable->at(targetStr);
    }
    if (targetStr.empty()) {
        return true;
    }
    bool res = false;
    for (const auto& word : wordBank) {
        auto pos = targetStr.find(word);
        if (pos != std::string::npos && pos == 0) {
            std::string temp{targetStr};
            temp.erase(pos, word.size());
            // std::cout << targetStr << "\tfound " << word << ' ' << pos <<
            //        ' ' << word << ' ' << temp << '\n';
            if (canConstruct_remove_hash(temp, wordBank, hashTable) == true) {
                res = true;
                break;
            }
        }
    }
    (*hashTable)[targetStr] = res;
    return res;
}

bool canConstruct(const std::string& targetStr,
          const std::vector<std::string>& wordBank) {
    std::unordered_map<std::string, bool> hashTable;
    return canConstruct_remove_hash(targetStr, wordBank, &hashTable);
}

int main() {
    std::cout << canConstruct("abcdef", {"ab", "cf", "abc", "cd",
                          "abef", "def", "abcd"}) << '\n';
    std::cout << canConstruct("skateboard", {"bo", "rd", "ate",
                  "t", "ska", "sk", "boar"}) << '\n';
    std::cout << canConstruct("enterapotentpot", {"a", "p", "ent",
                  "enter", "ot", "o", "t"}) << '\n';
    std::cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
                {"e", "ee", "eee", "eeee", "eeeeee",
                "eeeeeee", "eeeeeeee", "eeeeeeeee"}) << '\n';
    return 0;
}
