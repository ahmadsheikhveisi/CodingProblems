/* COPYRIGHT
 * return the shortest combination of numbers in 
 * array the sum of which is a given number.
 * we can reuse one or more of none unique
 * numbsers from array of non negative numbers.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

// time complexity of brute force O(Size^sum*sum)
// space complexity of brute force O(sum * sum)

// time complexity of hash solution is O(Size * sum * sum)
// space comlexity of hash solution O(sum * sum)

std::vector<int> bestSum_(int sum, const std::vector<int>& inarr,
            std::unordered_map<int, std::vector<int>>* hashTable) {
    if (hashTable->find(sum) != hashTable->end()) {
            return hashTable->at(sum);
    }
    std::vector<int> res;
    for (const auto& num : inarr) {
        if (sum == num) {
            // one element vector is the shortest
            res.clear();
            res.emplace_back(num);
            break;
        } else if (sum > num) {
            auto temp = bestSum_(sum - num, inarr, hashTable);
            if (temp.size() != 0 &&
                (res.size() == 0 || (res.size() - 1) > temp.size())) {
                res.clear();
                res.emplace_back(num);
                res.insert(res.end(),
                          std::make_move_iterator(temp.begin()),
                          std::make_move_iterator(temp.end()));
            }
        }
    }
    if (hashTable->find(sum) == hashTable->end()) {
        (*hashTable)[sum] = res;
    } else if (res.size() < hashTable->at(sum).size()) {
        (*hashTable)[sum].clear();
        (*hashTable)[sum].insert((*hashTable)[sum].end(),
                                 res.begin(), res.end());
    }
    return res;
}

std::vector<int> bestSum(int sum, const std::vector<int>& inarr) {
    std::unordered_map<int, std::vector<int>> hashTable;
    return bestSum_(sum, inarr, &hashTable);
}

void printvec(const std::vector<int>& invec) {
    for (const auto& num : invec) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    printvec(bestSum(7, {5, 3, 4, 7}));
    printvec(bestSum(8, {2, 3, 5}));
    printvec(bestSum(8, {1, 4, 5}));
    printvec(bestSum(100, {1, 2, 5, 25}));
    std::cout << "----------" << '\n';
    printvec(bestSum(7, {2, 3}));
    printvec(bestSum(7, {2, 4}));
    printvec(bestSum(300, {7, 15}));
    printvec(bestSum(0, {0, 7, 15}));
    return 0;
}
