/* COPYRIGHT
 * Given a string, write a function to check if it is a permutation
 * of a palindrome. A palindrome is a word or phrase that is the same
 * forwards and backwards. A permutation is a rearrangement of letters.
 * The palindrome does not need to be limited to just dictionary words.
 *
 * input: Tact Coa
 * output: 'taco cat', 'atco cta'
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
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool PalindromePermutationHash(std::string_view str) {
  std::unordered_map<char, size_t> hash;
  for (auto chr : str) {
    if (chr == ' ') {
      continue;
    }
    if ((chr >= 'A') && (chr <= 'Z')) {
      chr = static_cast<char>('a' + (chr - 'A'));
    }
    ++hash[chr];
  }
  // find odd occurances
  return 2 > std::count_if(begin(hash), end(hash), [](const auto &pair) {
           return (pair.second % 2) == 1;
         });
}

bool PalindromePermutationHashOpt(std::string_view str) {
  std::unordered_map<char, size_t> hash;
  size_t countOdd{0};
  for (auto chr : str) {
    if (chr == ' ') {
      continue;
    }
    if ((chr >= 'A') && (chr <= 'Z')) {
      chr = static_cast<char>('a' + (chr - 'A'));
    }
    ++hash[chr];
    if ((hash[chr] % 2) == 1) {
      ++countOdd;
    } else {
      --countOdd;
    }
  }
  // find odd occurances
  return 2 > countOdd;
}

bool PalindromePermutationBitVector(std::string_view str) {
  std::vector<bool> hash(26, false);
  for (auto chr : str) {
    if ((chr >= 'A') && (chr <= 'Z')) {
      chr = static_cast<char>('a' + (chr - 'A'));
    }
    if ((chr < 'a') || (chr > 'z')) {
      continue;
    }
    auto idx = static_cast<size_t>(chr) - 'a';
    hash[idx] = !hash[idx];
  }
  // find odd occurances
  size_t cnt{0};
  for (auto mem : hash) {
    if (mem) {
      ++cnt;
    }
  }
  return 2 > cnt;
}

std::uint32_t createBitVector(std::string_view str) {
  std::uint32_t hash{0};
  for (auto chr : str) {
    if ((chr >= 'A') && (chr <= 'Z')) {
      chr = static_cast<char>('a' + (chr - 'A'));
    }
    if ((chr < 'a') || (chr > 'z')) {
      continue;
    }
    auto idx = static_cast<size_t>(chr) - 'a';
    std::uint32_t mask{static_cast<std::uint32_t>(0x1) << idx};
    if ((hash & mask) == 0) {
      hash |= mask;
    } else {
      hash &= ~mask;
    }
  }
  return hash;
}

bool checkOddOccurance(std::uint32_t hash) { return (hash & (hash - 1)) == 0; }

bool PalindromePermutationBitVectorOpt(std::string_view str) {
  auto bit_vector = createBitVector(str);
  // find odd occurances
  return (bit_vector == 0) || checkOddOccurance(bit_vector);
}

int main() {
  std::vector<std::string_view> testlist{"aabBc", "aabc", "aabc  caba  ",
                                         "aabbcc"};
  for (auto &mem : testlist) {
    std::cout << "hash " << PalindromePermutationHash(mem) << '\n';
    std::cout << "hash opt " << PalindromePermutationHashOpt(mem) << '\n';
    std::cout << "bit vector " << PalindromePermutationBitVector(mem) << '\n';
    std::cout << "bit vector " << PalindromePermutationBitVectorOpt(mem)
              << '\n';
    std::cout << '\n';
  }
  return 0;
}
