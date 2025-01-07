/**
 * Copyright
 */

#include "sieve_of_eratosthenes.hpp"

#include <cstdint>
#include <cstdlib>
#include <vector>

std::vector<uint32_t> SieveOfEratosthenes(uint32_t num) {
  std::vector<uint32_t> res{};
  std::vector<bool> sieve(num / 2 + 1, true);
  res.push_back(2);
  for (uint32_t cnt{3}; cnt * cnt <= num; cnt += 2) {
    if (sieve[cnt / 2] == true) {
      for (uint32_t runner{cnt * cnt}; runner <= num; runner += 2 * cnt) {
        sieve[runner / 2] = false;
      }
    }
  }
  for (size_t cnt{1}; cnt < sieve.size(); ++cnt) {
    if ((sieve[cnt] == true) && ((2 * cnt + 1) <= num)) {
      res.push_back(2 * cnt + 1);
    }
  }
  return res;
}
