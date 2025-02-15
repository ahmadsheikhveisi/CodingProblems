/* COPYRIGHT
* Given a string s and a dictionary of strings wordDict,
* return true if s can be segmented into a space-separated sequence of one or
* more dictionary words.
* 
* Note that the same word in the dictionary may be reused multiple times in the segmentation.
* 
*  
* 
* Example 1:
* 
* Input: s = "leetcode", wordDict = ["leet","code"]
* Output: true
* Explanation: Return true because "leetcode" can be segmented as "leet code".
* 
* Example 2:
* 
* Input: s = "applepenapple", wordDict = ["apple","pen"]
* Output: true
* Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
* Note that you are allowed to reuse a dictionary word.
* 
* Example 3:
* 
* Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
* Output: false
* 
*  
* 
* Constraints:
* 
*     1 <= s.length <= 300
*     1 <= wordDict.length <= 1000
*     1 <= wordDict[i].length <= 20
*     s and wordDict[i] consist of only lowercase English letters.
*     All the strings of wordDict are unique.
* 
* 
*/

#ifndef WORD_BREAK_139
#define WORD_BREAK_139

#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
 public:
    bool wordBreak([[maybe_unused]] std::string_view s,
                   [[maybe_unused]] std::vector<std::string_view> const& wordDict) {
        //std::unordered_map<std::string_view, bool> hash_map{};
        //return WordBreakHashMap(s, wordDict, hash_map);
        return WordBreakTable(s, wordDict);
    }
 private:
    bool WordBreakTable(std::string_view s, std::vector<std::string_view> const& wordDict) {
        std::vector<bool> table(s.size() + 1, false);
        table[0] = true;
        for (size_t cnt{0}; cnt < table.size(); ++cnt) {
            if (table[cnt]) {
                for (auto const& word : wordDict) {
                    if (s.substr(cnt).starts_with(word)) {
                        table[cnt + word.size()] = true;
                    }
                }
            }
        }
        return table.back();
    }
    bool WordBreakHashMap(std::string_view s, std::vector<std::string_view> const& wordDict,
    std::unordered_map<std::string_view, bool>& hash_map) {
        if (s.empty()) {
            return true;
        }
        if (hash_map.contains(s)) {
            return hash_map.at(s);
        }
        bool res{false};
        for (auto const& word : wordDict) {
            if (s.starts_with(word)) {
                if (WordBreakHashMap(s.substr(word.size()), wordDict, hash_map)) {
                    res = true;
                    break;
                } 
            }
        }
        hash_map[s] = res;
        return res;
    }
};
#endif // WORD_BREAK_139
