/**
 * Copyright
 */

#include <type_traits>

#ifndef BITTOOLS_BIT_TOOLS_HPP_
#define BITTOOLS_BIT_TOOLS_HPP_

template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
constexpr bool GetBit(T const& num, size_t bit) {
  return ((num & (static_cast<T>(0x01) << bit)) != 0x00);
}

template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
constexpr T SetBit(T const& num, size_t bit) {
  return (num | (static_cast<T>(0x01) << bit));
}

template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
constexpr T ClearBit(T const& num, size_t bit) {
  return (num & (~(static_cast<T>(0x01) << bit)));
}

template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
constexpr T ClearBitRange(T const& num, size_t from, size_t to) {
  T mask = (static_cast<T>(0x01) << from) - 1;
  // -1 = ~(0)
  mask |= (~static_cast<T>(0x0)) << (to + 1);
  return (num & mask);
}

template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
constexpr T SetBitRange(T const& num, size_t from, size_t to) {
  T mask = (static_cast<T>(0x01) << (to - from + 1)) - 1;
  mask <<= from;
  return (num | mask);
}

// this can be done via SetBit or ClearBit
// first we clear the bit and then or with the val.
template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
constexpr T UpdateBit(T const& num, size_t bit, bool val) {
  T mask = ~(static_cast<T>(0x01) << bit);
  T bit_value = val ? (static_cast<T>(0x1) << bit) : static_cast<T>(0x0);
  return (num & mask) | (bit_value);
}

template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
constexpr T ToggleBit(T const& num, size_t bit) {
  T mask = (static_cast<T>(0x01) << bit);
  return (num ^ mask);
}

#endif  // BITTOOLS_BIT_TOOLS_HPP_
