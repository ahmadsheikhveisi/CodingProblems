/* COPYRIGHT
 * Given two sorted arrays, find all common members
*/

#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> const & a,
    std::vector<int> const & b) {
    std::vector<int> res;
    res.reserve(a.size());
    size_t cntB{0};
    for (size_t cntA{0}; cntA < a.size(); ++cntA) {
        while ((a[cntA] > b[cntB]) && (cntB < b.size())) {
            ++cntB;
        }
        if (a[cntA] == b[cntB]) {
            res.push_back(a[cntA]);
        }
    }
    return res;
}

void printvec(std::vector<int> vec) {
    for (auto mem : vec) {
        std::cout << mem << ' ';
    }
    std::cout << '\n';
}

int main() {
    printvec(solution({1, 3, 5, 8, 10}, {2, 5, 6, 7, 8}));
    printvec(solution({1, 3, 5, 7, 9}, {2, 5, 6, 7, 8}));
    printvec(solution({13, 27, 35, 40, 49, 55, 59},
        {17, 35, 39, 40, 55, 58, 60}));
    return 0;
}
