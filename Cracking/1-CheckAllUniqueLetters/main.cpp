/* COPYRIGHT
 */

#include <algorithm>
#include <iostream>
#include <string_view>
#include <type_traits>
#include <unordered_set>
#include <vector>

bool CheckAllUniqueCharBitVector(std::string_view str) {
  if (str.size() == 0) {
    return true;
  }
  size_t hash_size{static_cast<size_t>(0x1) << (sizeof(str[0]) * 8)};
  if (str.size() > hash_size) {
    return false;
  }
  std::vector<bool> hash(hash_size, false);
  for (auto chr : str) {
    if (hash[static_cast<size_t>(chr)]) {
      return false;
    } else {
      hash[static_cast<size_t>(chr)] = true;
    }
  }
  return true;
}

bool CheckAllUniqueCharN2NoSpace(std::string_view str) {
  if (str.size() == 0) {
    return true;
  }
  if (str.size() > (static_cast<size_t>(0x1) << (sizeof(str[0]) * 8))) {
    return false;
  }
  for (size_t cnt1{0}; cnt1 < str.size(); ++cnt1) {
    for (size_t cnt2{0}; cnt2 < str.size(); ++cnt2) {
      if (cnt1 != cnt2 && str[cnt1] == str[cnt2]) {
        return false;
      }
    }
  }
  return true;
}

bool CheckAllUniqueLettersSortNLogN(std::string str) {
  std::sort(begin(str), end(str));
  for (size_t cnt{1}; cnt < str.size(); ++cnt) {
    if (str[cnt] == str[cnt - 1]) {
      return false;
    }
  }
  return true;
}

template <typename T>
bool CheckAllUniqueCharHash(T str) {
  if (str.size() == 0) {
    return true;
  }
  if (str.size() > (static_cast<size_t>(0x1) << (sizeof(str[0]) * 8))) {
    return false;
  }
  std::unordered_set<std::decay_t<decltype(str[0])>> hash;
  for (auto chr : str) {
    if (hash.find(chr) != hash.end()) {
      return false;
    } else {
      hash.insert(chr);
    }
  }
  return true;
}

int main() {
  std::cout << CheckAllUniqueCharBitVector("asb4B/") << '\n';
  std::cout << CheckAllUniqueCharN2NoSpace("asb4B/") << '\n';
  std::cout << CheckAllUniqueLettersSortNLogN("asb4B/") << '\n';
  std::cout << CheckAllUniqueLettersSortNLogN("asMnkaKb4B/") << '\n';
  std::cout << CheckAllUniqueCharHash(std::string_view("a/sb4B/")) << '\n';
  std::cout << CheckAllUniqueCharHash(std::wstring(L"asb4B/")) << '\n';
  std::cout << CheckAllUniqueCharHash(std::wstring(L"به استند۲")) << '\n';
  return 0;
}
