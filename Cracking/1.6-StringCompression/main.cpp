/* COPYRIGHT
 * Implement a method to perform basic string compression using
 * the count of repeated characters. for example, the string
 * aabcccccaaa woud become a2b1c5a3. if the compressed string
 * would not become smaller than the original string your method
 * should return the original string. you can assume the string
 * has only uppercase and lowercase letter.
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

std::string StringCompression(std::string_view str) {
  if (str.size() == 0) {
    return {};
  }
  std::stringstream strm;
  char last_chr{str[0]};
  strm << str[0];
  size_t count{1};
  for (size_t cnt{1}; cnt < str.size(); ++cnt) {
    if (str[cnt] == last_chr) {
      ++count;
    } else {
      strm << count << str[cnt];
      count = 1;
      last_chr = str[cnt];
    }
    if (strm.str().size() >= str.size()) {
      return std::string(str);
    }
  }
  strm << count;
  return strm.str().size() < str.size() ? strm.str() : std::string(str);
}

std::string StringCompressionVector(std::string_view str) {
  if (str.size() == 0) {
    return {};
  }
  std::vector<char> strm;
  strm.reserve(str.size());
  char last_chr{str[0]};
  strm.push_back(str[0]);
  size_t count{1};
  for (size_t cnt{1}; cnt < str.size(); ++cnt) {
    if (str[cnt] == last_chr) {
      ++count;
    } else {
      auto cnt_str = std::to_string(count);
      strm.insert(strm.end(), cnt_str.begin(), cnt_str.end());
      strm.push_back(str[cnt]);
      count = 1;
      last_chr = str[cnt];
    }
  }
  auto cnt_str = std::to_string(count);
  strm.insert(strm.end(), cnt_str.begin(), cnt_str.end());
  auto out_str = std::string(strm.begin(), end(strm));
  return out_str.size() < str.size() ? out_str : std::string(str);
}

int main() {
  std::vector<std::string_view> testlist{"aabcccccaaa", "abc"};
  for (auto str : testlist) {
    std::cout << str << ' ' << StringCompression(str) << '\n';
    std::cout << str << ' ' << StringCompressionVector(str) << '\n';
    std::cout << '\n';
  }
  return 0;
}
