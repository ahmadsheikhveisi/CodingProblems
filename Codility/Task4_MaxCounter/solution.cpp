// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> res(N,0);
    int max = 0;
    for (auto num : A)
    {
        if (num < N + 1)
        {
            res[num - 1]++;
            if (res[num - 1] > max)
            {
                max = res[num - 1];
            }
        }
        else
        {
            std::fill(res.begin(),res.end(),max);
        }
    }
    return res;
}
