/* COPYRIGHT
 * Assume you a method isSubstring which checks if one word is a
 * substring of another. Given two strings, s1 and s2, write code
 * to check if s2 is a rotation of s1 using only one call to
 * isSubstring.
 *
 * Note: case insensive, ignore white space.
 * Palindrome has an even occurance of all charactors, except
 * it can have only one odd occurance.
 * 00010000 - 1 = 00001111
 * 00101000 - 1 = 00100111
 *
 * count if: count the elements between two iterators that satisfy a
 * condition.
 *
 * string find returns the index and it can be npos
 *
 * Mind the end of string, when searching.
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool isSubstring(std::string_view big, std::string_view small) {
  return big.find(small) != std::string::npos;
}

bool StringRotation(std::string_view str1, std::string_view str2) {
  if (str1.size() != str2.size()) {
    return false;
  }
  std::string big{str1};
  big += big;
  return isSubstring(big, str2);
}

int main() {
  std::vector<std::tuple<std::string_view, std::string_view>> testlist{
      {"abc", "cba"},
      {"waterbottle", "erbottlewat"},
      {"abc", "cab"},
      {"bca", "abc"},
      {"", ""}};
  for (auto [str1, str2] : testlist) {
    std::cout << str1 << ' ' << str2 << ' ' << StringRotation(str1, str2)
              << '\n';
  }
  return 0;
}
