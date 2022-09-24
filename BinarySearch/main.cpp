#include <iostream>
#include <vector>


/* original change three lines*/
int solutionOriginal(int *A, int N, int X) {
    int r, m, l;
    if (N == 0) {
        return -1;
    }
    l = 0;
    r = N - 1;
    while (l < r) {
        m = (l + r) / 2;
        if (A[m] > X) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    if (A[l] == X) {
        return l;
    }
    return -1;
}


int solution(const std::vector<int> &A, int X) {
    int r, m, l;
    auto N{A.size()};
    if (N == 0) {
        return -1;
    }
    l = 0;
    r = N - 1;
    while (l != r) {
        m = (l + r) / 2;
        if (A[m] == X) return m;
        if (A[m] > X) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    if (A[l] == X) {
        return l;
    }
    return -1;
}

int main() {
    std::cout << "exercise1\n";
    {
        std::vector<int>arr{1, 1, 1, 1, 1};
        std::cout << solution(arr, 5) << '\n';
    }
    {
        std::vector<int> arr{1, 2, 5, 9, 9};
        std::cout << solution(arr, 5) << '\n';
    }
    {
        std::vector<int> arr{1, 5, 5, 5, 5};
        std::cout << solution(arr, 1) << '\n';
    }
    {
        std::vector<int> arr{1, 5, 5, 5, 5};
        std::cout << solution(arr, 5) << '\n';
    }
    {
        std::vector<int> arr{1, 5};
        std::cout << solution(arr, 1) << '\n';
    }
    {
        std::vector<int> arr{1, 5, 6};
        std::cout << solution(arr, 6) << '\n';
    }
    return 0;
}
