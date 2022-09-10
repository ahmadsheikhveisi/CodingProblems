#include <iostream>
#include <vector>

int solution(const std::vector<int>& arr) {
    if (arr.size() < 3) {
        return -1;
    }
    int res = 0;
    int cnt = 1;
    while (cnt < arr.size()) {
        int length = 2;
        int vel = arr[cnt] - arr[cnt - 1];
        ++cnt;
        while ((cnt < arr.size()) && (vel == arr[cnt] - arr[cnt - 1])) {
            ++length;
            ++cnt;
        }
        if (length > 2) {
            res += (length - 1) * (length - 2) / 2;
        }
    }
    return res;
}

int main() {
    std::cout << solution({-1, 1, 3, 3, 3, 2, 3, 2, 1, 0}) << '\n';
    std::cout << solution({3, 2, 1, 0, -1}) << '\n';
    return 0;
}
