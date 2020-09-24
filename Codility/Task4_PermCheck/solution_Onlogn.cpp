// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::sort(A.begin(),A.end());
    for (int cnt = 0; cnt < (int)A.size(); ++cnt)
    {
        if (cnt + 1 != A[cnt])
        {
            return 0;
        }
    }
    return 1;
}
