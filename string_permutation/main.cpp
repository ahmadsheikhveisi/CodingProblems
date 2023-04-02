/* COPYRIGHT
*/

#include <string>
#include <algorithm>
#include <string_view>
#include <vector>
#include <iostream>
#include <unordered_set>

class Solution {
 private:
    void permuteUnique_(std::vector<int> pre, std::vector<int> nums,
                    std::vector<std::vector<int>>& res) {
        if (nums.size() == 0) {
            res.push_back(pre);
        } else {
            for (size_t cnt{0}; cnt < nums.size(); ++cnt) {
                if ((cnt > 0) && (nums[cnt] == nums[cnt - 1])) {
                    continue;
                }
                auto new_pre = std::vector(pre);
                new_pre.push_back(nums[cnt]);
                auto new_nums = std::vector(nums);
                new_nums.erase(std::next(new_nums.begin(), cnt));
                permuteUnique_(std::move(new_pre), std::move(new_nums), res);
            }
        }
    }

 public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        auto pre = std::vector<int>{};
        pre.reserve(nums.size());
        permuteUnique_(std::move(pre), nums, res);
        return res;
    }
};

void permutation(std::string prefix, std::string str,
                std::unordered_set<std::string> *mset) {
    if (str.size() == 0) {
        std::cout << prefix;
        if (mset->find(prefix) == mset->end()) {
            mset->insert(prefix);
        } else {
            std::cout << " !";
        }
        std::cout << '\n';
    } else {
        for (size_t cnt{0}; cnt < str.size(); ++cnt) {
            if ((cnt > 0) && (str[cnt] == str[cnt -1])) {
                continue;
            }
            permutation(prefix + std::string{str[cnt]},
                    str.substr(0, cnt) + str.substr(cnt + 1), mset);
        }
    }
}

void permutation(std::string str) {
    std::unordered_set<std::string> mset;
    permutation("", std::move(str), &mset);
    std::cout << mset.size() << '\n';
}


int main(void) {
    // std::string str{"113"};
    // std::string str{"ABAB"};
    // std::string str{"AABCDE"};
    // std::sort(str.begin(), str.end());
    // permutation(str);

    std::vector<int> nums{1, 1, 2, 3, 4, 5};
    Solution obj;
    auto res = obj.permuteUnique(nums);
    for (auto const& mem : res) {
        for (auto const& num : mem) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
