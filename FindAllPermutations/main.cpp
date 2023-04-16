/* COPYRIGHT
 * Given a smaller string s and a bigger string b, design an algorithm to find
 * all permutations of the shorter string within the larger one. Print the 
 * location of each permutation.
 * s: abbc
 * b: cbabadcbbabbcbabaabccbabc
 *    ----  ----  ----    ----
 *             ----        ----
 *               ----
 * res: 0,6,9,11,12,20,21
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

constexpr std::uint32_t get_mask(char chr) {
    return (0x1 << (chr - 'a'));
}

std::vector<size_t> Solution(std::string const& s, std::string const& b) {
    std::vector<size_t> res;
    std::unordered_map<char, size_t> s_map, sliding_map;
    std::uint32_t s_hash{0}, sliding_hash{0};
    for (auto chr : s) {
        ++s_map[chr];
        s_hash |= get_mask(chr);
    }
    size_t window_len{0};
    for (size_t cnt{0}; cnt < b.size(); ++cnt) {
        if (s_map.find(b[cnt]) == s_map.end()) {
            // clean up the sliding map and continue
            sliding_map.clear();
            window_len = 0;
            sliding_hash = 0;
            continue;
        }
        ++sliding_map[b[cnt]];
        ++window_len;
        if (window_len > s.size()) {
            auto removed_char{b[cnt - window_len + 1]};
            --sliding_map[removed_char];
            if (sliding_map[removed_char] < s_map[removed_char]) {
                auto remove_mask{~get_mask(removed_char)};
                sliding_hash &= remove_mask;
            }
            --window_len;
        }
        if (sliding_map[b[cnt]] >= s_map[b[cnt]]) {
            sliding_hash |= get_mask(b[cnt]);
        }
        if (sliding_hash == s_hash) {
            res.push_back(cnt - s.size() + 1);
        }
    }
    return res;
}

template<typename T>
void print_vec(std::vector<T> const& vec) {
    for (T const& mem : vec) {
        std::cout << mem << ' ';
    }
    std::cout << '\n';
}

int main() {
    print_vec(Solution("abbc", "cbabadcbbabbcbabaabccbabc"));
    return 0;
}
