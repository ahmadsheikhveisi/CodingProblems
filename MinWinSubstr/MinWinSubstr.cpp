/* COPYRIGHT
 * Min Window Substring
 * Have the function MinWindowSubstring(strArr) take the array of 
 * strings stored in strArr, which will contain only two strings, 
 * the first parameter being the string N and the second parameter 
 * being a string K of some characters, and your goal is to determine 
 * the smallest substring of N that contains all the characters in K. 
 * For example: if strArr is ["aaabaaddae", "aed"] then the smallest 
 * substring of N that contains the characters a, e, and d is "dae" 
 * located at the end of the string. So for this example your program 
 * should return the string dae.
 * 
 * Another example: if strArr is ["aabdccdbcacd", "aad"] then the smallest 
 * substring of N that contains all of the characters in K is "aabd" which 
 * is located at the beginning of the string. Both parameters will be strings 
 * ranging in length from 1 to 50 characters and all of K's characters will 
 * exist somewhere in the string N. Both strings will only contains lowercase 
 * alphabetic characters.
 * Examples
 * Input: {"ahffaksfajeeubsne", "jefaa"}
 * Output: aksfaje
 * Input: {"aaffhkksemckelloe", "fhea"}
 * Output: affhkkse
 * https://coderbyte.com/results/AHSHV:Min%20Window%20Substring:Cpp
 * this solution's time complexity is O(n)
*/

#include <string>
#include <vector>
#include <iostream>
#include <array>

std::string_view MinWindowSubstring(std::string_view NStr,
    std::string_view KStr) {
    std::vector<int> k_count(256, 0);
    size_t k_unique = 0;
    for (const auto& chr : KStr) {
        if (k_count[chr] == 0) {
            k_unique++;
        }
        k_count[chr]++;
    }
    std::vector<int> n_hash(256, 0);
    size_t t_idx = 0;
    size_t t_len = 0;
    size_t start_index = 0;
    size_t min_len = NStr.size();
    size_t covered = 0;
    // find the first one
    int cnt = 0;
    for (; cnt < NStr.size(); ++cnt) {
        if (k_count[NStr[cnt]] > 0) {
            break;
        }
    }
    for (; cnt < NStr.size(); ++cnt) {
        if (k_count[NStr[cnt]] > 0) {
            n_hash[NStr[cnt]]++;
            if (n_hash[NStr[cnt]] == k_count[NStr[cnt]]) {
                covered++;
                if (covered == k_unique) {
                    // all are covered
                    // how many we can remove from the beginning
                    size_t t_chr = t_idx;
                    for (; t_chr < cnt; t_chr++) {
                        if (k_count[NStr[t_chr]] > 0) {
                            // this character is in K string
                            // now we have to see if it can be removed
                            if (n_hash[NStr[t_chr]] > k_count[NStr[t_chr]]) {
                                // the number of occurance of this character
                                // in this substring is bigger than we need
                                n_hash[NStr[t_chr]]--;
                            } else {
                                // we can't remove anymore
                                break;
                            }
                        }
                    }
                    t_idx = t_chr;
                    t_len = cnt - t_idx + 1;
                    if (t_len < min_len) {
                        start_index = t_idx;
                        min_len = t_len;
                    }
                    // we need to remove this one to see if it occurs again.
                    covered--;
                    n_hash[NStr[t_idx]]--;
                    t_idx++;
                }
            }
        } else {
            // the character wasn't in K string
            t_len++;
        }
    }

    return NStr.substr(start_index, min_len);
}

int main(void) {
    std::cout << MinWindowSubstring("aeeddea",
        "aed") << '\n';  // "dae"
    std::cout << MinWindowSubstring("aaabaaddae",
        "aed") << '\n';  // "dae"
    std::cout << MinWindowSubstring("aacbdccdbcacad",
        "aad") << '\n';  // "aabd"
    std::cout << MinWindowSubstring("ahffaksfajeeubsne",
        "jefaa") << '\n';  // aksfaje
    std::cout << MinWindowSubstring("aaffhkksemckelloe",
        "fhea") << '\n';   // affhkkse
    return 0;
}
