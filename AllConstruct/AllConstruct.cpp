/* COPYRIGHT
 * return all of the ways a target strign can be
 * constructed from the elements of string.
 * you may reuse the elements
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

// time complexity O(size)
// space complexity
std::vector<std::vector<std::string_view>>
AllConstruct_(std::string_view targetStr,
    const std::vector<std::string_view>& wordBank,
    std::unordered_map<std::string_view,
        std::vector<std::vector<std::string_view>>>* hashTable) {
    if (hashTable->find(targetStr) != hashTable->end()) {
        return hashTable->at(targetStr);
    }
    std::vector<std::vector<std::string_view>> res;
    for (auto word : wordBank) {
        std::vector<std::string_view> word_res;
        auto pos = targetStr.find(word);
        if (pos != std::string::npos && pos == 0) {
            auto temp = targetStr.substr(pos + word.size());
            if (temp.empty()) {
                word_res.push_back(word);
                res.push_back(word_res);
            } else {
                auto temp_res = AllConstruct_(temp, wordBank, hashTable);
                if (temp_res.size() != 0) {
                    word_res.push_back(word);
                }
                for (const auto& cnt_res : temp_res) {
                    std::vector<std::string_view> temp_word_res{word_res};
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

std::vector<std::vector<std::string_view>>
AllConstruct_table(std::string_view targetStr,
    const std::vector<std::string_view>& wordBank) {
    std::vector<std::vector<std::vector<std::string_view>>>
        res(targetStr.size() + 1);
    for (auto word : wordBank) {
        if (targetStr.substr(0, word.size()) == word) {
            res[word.size()].push_back(std::vector<std::string_view>{word});
        }
    }
    for (size_t cnt = 1; cnt < res.size(); ++cnt) {
        if (res[cnt].size() != 0) {
            for (auto word : wordBank) {
                if (targetStr.substr(cnt, word.size()) == word) {
                    auto temp_res = res[cnt];
                    std::for_each(begin(temp_res), end(temp_res),
                        [&](std::vector<std::string_view>& pvec){
                            pvec.push_back(word);
                        });
                    res[cnt + word.size()].insert(
                        res[cnt + word.size()].end(),
                        std::make_move_iterator(temp_res.begin()),
                        std::make_move_iterator(temp_res.end()));
                }
            }
        }
    }

    return res.back();
}

std::vector<std::vector<std::string_view>>
AllConstruct(std::string_view targetStr,
    const std::vector<std::string_view>& wordBank) {
    // std::unordered_map<std::string_view,
    //    std::vector<std::vector<std::string_view>>> hashTable;
    // return AllConstruct_(targetStr, wordBank, &hashTable);
    return AllConstruct_table(targetStr, wordBank);
}

void printres(const std::vector<std::vector<std::string_view>>& res) {
    for (const auto& vec : res) {
        for (const auto word : vec) {
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
    printres(AllConstruct("eeeeeeeeeeeeeeeeeeeeeef",
                {"e", "ee", "eee", "eeee", "eeeeee",
                "eeeeeee", "eeeeeeee", "eeeeeeeee"}));
    return 0;
}
