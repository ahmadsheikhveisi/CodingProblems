/* COPYRIGHT
 * 
*/

#include "solution.hpp"

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> Solution::FindMinCoinRec(int amount,
    const std::vector<int>& denominations,
    std::unordered_map<int, std::vector<int>>* dict) {
    std::vector<int> res;
    if (amount == 0) {
        return res;
    }
    if (dict->find(amount) != dict->end()) {
        return dict->at(amount);
    }
    for (const auto& coin : denominations) {
        if (amount == coin) {
            // this means we have a solution with one coin
            // this is the best scenario
            res.clear();
            res.push_back(coin);
            break;
        } else if (amount > coin) {
            auto tempres = FindMinCoinRec(amount - coin,
                denominations, dict);
            // we want to know whether we need to get this result or not
            if (tempres.size() != 0 &&  // checking for an answer
                (res.size() == 0 ||  // we don't have answer yet
                res.size() > tempres.size() + 1)) {  // or this answer is better
                // plus one because of current coin
                res.clear();
                for (const auto& itm : tempres) {
                    res.push_back(itm);
                }
                res.push_back(coin);
            }
        }
    }
    (*dict)[amount] = res;
    return res;
}

std::vector<int> Solution::FindMinCoin(int amount,
    const std::vector<int>& denominations) {
    std::unordered_map<int, std::vector<int>> dict;
    return FindMinCoinRec(amount, denominations, &dict);
}
