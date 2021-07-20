/* COPYRIGHT
 * return an array containing any combination of elements in 
 * an array that add up to target sum.
 * if there is no combination, return empty array.
 * we can use one or more of none unique
 * numbsers from array of non negative numbers.
*/

#include <vector>
#include <iostream>
#include <unordered_map>

// time complexity of classical method is O(Size^sum * sum)
// this is because of the copy to the res vector
// space complexity is O(sum)


// time complexity of hash method is O(Size*sum*sum)
// foreach recursive call we need to copy the array
// space complexity is O(sum^2)
// this is because of hashTable which has the length of sum
// and each key have a vector of the same element

std::vector<int> howSum_hash_(int sum, const std::vector<int>& inarr,
                    std::unordered_map<int, std::vector<int>>* hashTable) {
    if (hashTable->find(sum) != hashTable->end()) {
        return hashTable->at(sum);
    }
    std::vector<int> res;
    for (const auto& num : inarr) {
        if (sum == num) {
            res.emplace_back(num);
            break;
        } else if (sum > num) {
            auto temp = howSum_hash_(sum - num, inarr, hashTable);
            if (temp.size() != 0) {
                res.emplace_back(num);
                res.insert(res.end(),
                    std::make_move_iterator(temp.begin()),
                    std::make_move_iterator(temp.end()));
                break;
            }
        }
    }
    (*hashTable)[sum] = res;
    return res;
}

std::vector<int> howSum_hash(int sum, const std::vector<int>& inarr) {
    std::unordered_map<int, std::vector<int>> hashTable;
    return howSum_hash_(sum, inarr, &hashTable);
}

std::vector<int> howSum_table(int sum, const std::vector<int>&invec) {
    std::vector<std::vector<int>> res(sum + 1, std::vector<int>());
    // seed from zero
    for (const auto& num : invec) {
        if (num < res.size()) {
            res[num].push_back(num);
        }
    }
    bool found = false;
    // res[0] is always empty because it is always possible to get no element
    for (auto it = begin(res) + 1; it < end(res) && found == false; ++it) {
        if (it->size() != 0) {
            for (const auto& num : invec) {
                if (it + num < end(res)) {
                    (it + num)->clear();
                    (it + num)->insert((it + num)->end(),
                                      it->begin(), it->end());
                    (it + num)->push_back(num);
                    if (it + num == end(res)) {
                        found = true;
                        break;
                    }
                }
            }
        }
    }

    return res[sum];
}

void printvec(const std::vector<int>& invec) {
    for (const auto& num : invec) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    printvec(howSum_table(7, {2, 3}));  // 2 2 3
    printvec(howSum_table(7, {5, 3, 4, 7}));  // 3 4
    printvec(howSum_table(7, {2, 4}));  // empty
    printvec(howSum_table(8, {2, 3, 5}));  // 2 2 2 2
    printvec(howSum_table(300, {7, 14}));  // empty
    printvec(howSum_table(0, {0, 7, 15}));  // 0
    printvec(howSum_table(0, {1, 7, 15}));  // empty
    return 0;
}
