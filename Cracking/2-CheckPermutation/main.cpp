/* COPYRIGHT
 * Given two strings, write a method to decide if one is a permutation
 * of the other.
 *
 * Note: case sensivity, white space.
 */

#include <algorithm>
#include <iostream>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool CheckPermutationHash(std::string_view str1, std::string_view str2) {
  if (str1.size() != str2.size()) {
    return false;
  }
  std::unordered_map<char, size_t> hashtable1;
  for (auto chr : str1) {
    ++hashtable1[chr];
  }
  std::unordered_map<char, size_t> hashtable2;
  for (auto chr : str2) {
    ++hashtable2[chr];
  }
  return hashtable1 == hashtable2;
}

bool CheckPermutationSort(std::string str1, std::string str2) {
  if (str1.size() != str2.size()) {
    return false;
  }
  std::sort(begin(str1), end(str1));
  std::sort(begin(str2), end(str2));
  return str1 == str2;
}

int main() {
  std::cout << CheckPermutationHash("aabc", "cabc") << '\n';
  std::cout << CheckPermutationSort("aabc", "caba") << '\n';
  return 0;
}
