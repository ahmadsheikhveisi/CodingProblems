/* COPYRIGHT
*/
#include "gtest/gtest.h"

#include "HexBinStringCompare.hpp"

TEST(HexTest, OneHexDigitPositive) {
    EXPECT_TRUE(HexBinCompare("101", "5"));
}
TEST(HexTest, OneHexDigitPositive2) {
    EXPECT_TRUE(HexBinCompare("01", "1"));
}

TEST(HexTest, OneHexLetterPositive) {
    EXPECT_TRUE(HexBinCompare("1101", "D"));
}

TEST(HexTest, OneHexDigitNagetive) {
    EXPECT_FALSE(HexBinCompare("100", "5"));
}

TEST(HexTest, OneHexLetterNagetive) {
    EXPECT_FALSE(HexBinCompare("1111", "D"));
}

TEST(HexTest, TwoHexLetterPositive) {
    EXPECT_TRUE(HexBinCompare("1011101", "5D"));
}

TEST(HexTest, TwoHexDigitNagetive) {
    EXPECT_FALSE(HexBinCompare("100100", "15"));
}

TEST(HexTest, HexLongPositive) {
    EXPECT_TRUE(HexBinCompare("1001000110100010101100111"
    "10001001101010111100110111101111",
    "123456789ABCDEF"));
}

TEST(HexTest, HexMatchNagetive) {
    EXPECT_FALSE(HexBinCompare("10001000100010001", "1111"));
}

TEST(HexTest, HexMatchPositive) {
    EXPECT_TRUE(HexBinCompare("0001000100010001", "1111"));
}

TEST(HexTest, HexZeroLengthNagetive) {
    EXPECT_FALSE(HexBinCompare("", "1111"));
}

TEST(HexTest, HexZeroLengthNagetive2) {
    EXPECT_FALSE(HexBinCompare("1", ""));
}
