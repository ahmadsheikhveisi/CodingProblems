/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "sieve_of_eratosthenes.hpp"

bool IsPrime(uint32_t num) {
  if (num < 2) {
    return false;
  }
  for (uint32_t cnt{2}; cnt * cnt < num; ++cnt) {
    if ((num % cnt) == 0) {
      std::cout << num << ' ' << cnt << '\n';
      return false;
    }
  }
  return true;
}

TEST(SieveTest, test1) {
  auto res = SieveOfEratosthenes(1000000001);
  for (auto const& prime : res) {
    // std::cout << prime << ' ';
    EXPECT_TRUE(IsPrime(prime));
  }
  std::cout << '\n';
}
