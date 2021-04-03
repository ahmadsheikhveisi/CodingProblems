// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    for (int cnt = sqrt(N); cnt > 0; --cnt)
    {
        if (N % cnt == 0)
        {
            return 2 *(cnt + N/cnt);
        }
    }
    return 2*(N + 1);

}

