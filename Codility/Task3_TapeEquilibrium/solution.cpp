// you can use includes, for example:
// #include <algorithm>

#include <limits.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int res = INT_MAX;
    int len = A.size();
    
    vector<long int> sum(len);
    
    sum[0] = A[0];
    
    for (int cnt = 1; cnt < len - 1; ++cnt)
    {
        sum[cnt] = A[cnt] + sum[cnt - 1];
    }
    
    long int r_sum = A[len - 1];
    for (int cnt = len - 2; cnt >= 0; --cnt)
    {
        int diff = r_sum > sum[cnt]? r_sum - sum[cnt] : sum[cnt] - r_sum;
        if (res > diff)
        {
            res = diff;
        }
        r_sum += A[cnt];
    }
    
    
    return res;
}
