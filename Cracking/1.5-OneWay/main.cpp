/* COPYRIGHT
 * There are three types of edits that can be performed on strings:
 * insert a character, remove a character, or replace a character.
 * Given two strings, write a function to heck if they are one edit
 * (or zero edits) away.
 *
 * pale, ple -> true
 * pales, pale -> true
 * pale, bale -> true
 * pale, bake -> false
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
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool OneWayCheckHash(std::string_view str1, std::string_view str2) {
  if ((str1.size() > str2.size() + 1) || (str2.size() > str1.size() + 1)) {
    return false;
  }
  if (str1.size() == str2.size()) {
    size_t diff{0};
    for (size_t cnt{0}; cnt < str1.size(); ++cnt) {
      if (str1[cnt] != str2[cnt]) {
        ++diff;
      }
    }
    if (diff > 1) {
      return false;
    }
    return true;
  } else {
    std::string_view smaller{str1.size() > str2.size() ? str2 : str1};
    std::string_view bigger{str1.size() > str2.size() ? str1 : str2};
    for (size_t cnt{0}; cnt < smaller.size(); ++cnt) {
      if (smaller[cnt] != bigger[cnt]) {
        if (smaller.substr(cnt) == bigger.substr(cnt + 1)) {
          return true;
        } else {
          return false;
        }
      }
    }
  }

  return true;
}

bool OneWayCheckOpt(std::string_view str1, std::string_view str2) {
  if ((str1.size() > str2.size() + 1) || (str2.size() > str1.size() + 1)) {
    return false;
  }
  bool diff{false};
  std::string_view smaller{str1.size() > str2.size() ? str2 : str1};
  std::string_view bigger{str1.size() > str2.size() ? str1 : str2};
  size_t bigger_cnt{0};
  for (auto chr : smaller) {
    if (chr != bigger[bigger_cnt]) {
      if (diff) {
        return false;
      }
      diff = true;
      if (smaller.size() != bigger.size()) {
        ++bigger_cnt;
      }
    }
    ++bigger_cnt;
  }

  return true;
}

int main() {
  std::vector<std::tuple<std::string_view, std::string_view>> testlist{
      {"pale", "ple"},  {"pales", "pale"}, {"pale", "bale"},
      {"pale", "bake"}, {"pales", "bale"}, {"apple", "aple"}};
  for (auto &mem : testlist) {
    auto [str1, str2] = mem;
    std::cout << str1 << ' ' << str2 << ' ' << OneWayCheckHash(str1, str2)
              << '\n';
    std::cout << "opt " << str1 << ' ' << str2 << ' '
              << OneWayCheckOpt(str1, str2) << '\n';
    std::cout << '\n';
  }
  return 0;
}
