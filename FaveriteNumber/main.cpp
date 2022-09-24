#include <iostream>

/* original */
int solutionOriginal(int x, int y, int A[], int N) {
    int result = -1, nx = 0, ny = 0;
    for (int cnt = 0; cnt < N; ++cnt) {
        if (A[cnt] == x) {
            ++nx;
        } else if (A[cnt] == y) {
            ++ny;
        }
        if (nx == ny) {
            result = cnt;
        }
    }
    return result;
}


int solution(int x, int y, int A[], int N) {
    int result = -1, nx = 0, ny = 0;
    for (int cnt = 0; cnt < N; ++cnt) {
        if (A[cnt] == x) {
            ++nx;
        } /*else*/ if (A[cnt] == y) {
            ++ny;
        }
        if (nx == ny) {
            result = cnt;
        }
    }
    return result;
}

int main() {
    std::cout << "exercise2\n";
    {
        int A[] = {6, 42, 11, 7, 1, 42};
        std::cout << solution(7, 42, A, 6) << '\n';
    }
    {
        int A[] = {13, 13, 1, 6};
        std::cout << solution(6, 13, A, 4) << '\n';
    }
    {
        int A[] = {13, 13, 1, 6};
        std::cout << solution(7, 14, A, 4) << '\n';
    }
    {
        int A[] = {5, 7, 8, 13, 13, 13, 6};
        std::cout << solution(13, 13, A, 7) << '\n';
    }
    return 0;
}
