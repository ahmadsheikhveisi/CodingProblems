/* COPYRIGHT
*/

#include "HexBinStringCompare.hpp"

#include <algorithm>
#include <unordered_map>
#include <string>

bool CheckHexDigit(std::string bin_str, char hex_digit) {
    static const std::unordered_map<std::string, char> hex_map{
        {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
        {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'},
    };
    while (bin_str.size() < 4) {
        bin_str = '0' + bin_str;
    }
    auto itr = hex_map.find(bin_str);
    if ((itr != hex_map.end()) &&
        (itr->second == hex_digit)) {
        return true;
    }
    return false;
}

bool HexBinCompare(std::string const& bin_str, std::string const& hex_str) {
    if ((bin_str.size() == 0) || (hex_str.size() == 0)) {
        return false;
    }
    if (bin_str.size() > hex_str.size() * 4) {
        return false;
    }
    if (bin_str.size() <= (hex_str.size() - 1) * 4) {
        return false;
    }
    for (size_t hex_cnt{0}; hex_cnt < hex_str.size();
        ++hex_cnt) {
        size_t substr_pos{std::min(bin_str.size() - 1,
            ((hex_cnt + 1) * 4) - 1)};
        size_t substr_len{std::min(static_cast<size_t>(4),
            bin_str.size() - (hex_cnt * 4))};
        substr_pos = bin_str.size() - 1 - substr_pos;
        if (false == CheckHexDigit(bin_str.substr(substr_pos, substr_len),
            hex_str[hex_str.size() - 1 - hex_cnt])) {
            return false;
        }
    }
    return true;
}
