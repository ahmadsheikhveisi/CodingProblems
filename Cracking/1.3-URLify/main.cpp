/* COPYRIGHT
 * Given two strings, write a method to decide if one is a permutation
 * of the other.
 *
 * Note: case sensivity, white space.
 * string find returns the index and it can be npos
 * Mind the end of string
 */

#include <algorithm>
#include <iostream>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::string URLify(std::string_view in_str, size_t size) {
  size_t cnt{0};
  std::string res;
  std::string_view str{in_str.substr(0, size)};
  while (cnt < size) {
    auto found = str.find(' ', cnt);
    if (found == std::string::npos) {
      break;
    } else {
      res += std::string(str.substr(cnt, found - cnt)) + "%20";
      cnt = found + 1;
    }
  }
  if (cnt < size) {
    res += std::string(str.substr(cnt, size - cnt));
  }
  return res;
}

int main() {
  std::cout << URLify("aabc c abc  ", 10) << '\n';
  std::cout << URLify("aabc  caba  ", 10) << '\n';
  return 0;
}
