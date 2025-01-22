/* COPYRIGHT
* A transformation sequence from word beginWord to word endWord using a dictionary wordList
* is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
* 
*     Every adjacent pair of words differs by a single letter.
*     Every si for 1 <= i <= k is in wordList.
*     Note that beginWord does not need to be in wordList.
*     sk == endWord
* 
* Given two words, beginWord and endWord, and a dictionary wordList,
* return the number of words in the shortest transformation sequence from beginWord to endWord,
* or 0 if no such sequence exists.
* 
*  
* 
* Example 1:
* 
* Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
* Output: 5
* Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
* 
* Example 2:
* 
* Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
* Output: 0
* Explanation: The endWord "cog" is not in wordList,
* therefore there is no valid transformation sequence.
* 
*  
* 
* Constraints:
* 
*     1 <= beginWord.length <= 10
*     endWord.length == beginWord.length
*     1 <= wordList.length <= 5000
*     wordList[i].length == beginWord.length
*     beginWord, endWord, and wordList[i] consist of lowercase English letters.
*     beginWord != endWord
*     All the words in wordList are unique.
* 
* 
*/

#ifndef WORD_LATTER_127
#define WORD_LATTER_127

#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
 public:
    int ladderLength([[maybe_unused]] std::string beginWord,
                     [[maybe_unused]] std::string endWord,
                     [[maybe_unused]] std::vector<std::string>& wordList) {
        if (std::find(begin(wordList), end(wordList), endWord) == end(wordList)) {
            return 0;
        }
        std::unordered_map<std::string, std::vector<std::string>> graph{};
        for (const auto& word : wordList) {
            for (size_t i = 0; i < word.size(); ++i) {
                std::string key = word.substr(0, i) + '*' + word.substr(i + 1);
                graph[key].push_back(word);
            }
        }
        
        return Bfs(beginWord, endWord, graph);
    }
 private:
    int Bfs(std::string beginWord,
            std::string endWord,
            std::unordered_map<std::string, std::vector<std::string>>& graph) {
        std::vector<std::string> queue{beginWord};
        std::unordered_map<std::string, int> visited{{beginWord, 1}};
        while (!queue.empty()) {
            std::string word = queue.front();
            queue.erase(begin(queue));
            for (size_t i = 0; i < word.size(); ++i) {
                std::string key = word.substr(0, i) + '*' + word.substr(i + 1);
                for (const auto& next : graph[key]) {
                    if (next == endWord) {
                        return visited[word] + 1;
                    }
                    if (visited.find(next) == end(visited)) {
                        visited[next] = visited[word] + 1;
                        queue.push_back(next);
                    }
                }
            }
        }
        return 0;

    }
};
#endif // WORD_LATTER_127
