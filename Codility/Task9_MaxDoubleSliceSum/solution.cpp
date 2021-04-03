// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    vector<int> max_sum_f(len,0);
    max_sum_f[0] = 0;
    int max_sum = A[1];
    for (int cnt = 1; cnt < len; ++cnt)
    {
        max_sum = std::max(max_sum + A[cnt], 0);
        //max_sum = std::max(sum,max_sum);
        max_sum_f[cnt] = max_sum;
    }

    max_sum = A[len - 1];
    vector<int> max_sum_r(len,0);
    max_sum_r.push_back(max_sum);

    for (int cnt = len - 2; cnt >= 0; --cnt)
    {
        max_sum = std::max(max_sum + A[cnt], 0);
        //max_sum = std::max(sum,max_sum);
        max_sum_r[cnt] = max_sum;
    }
    std::reverse(max_sum_r.begin(), max_sum_r.end());
    for (int cnt = 0; cnt < len ; ++cnt)
    {
        std::cout << max_sum_f[cnt] << " " << max_sum_r[cnt] << std::endl;
    }

    max_sum = 0;
    for (int cnt = 1; cnt < len - 1; ++cnt)
    {
        max_sum = std::max(max_sum, max_sum_r[cnt + 1] + max_sum_f[cnt - 1]);
    }

    return max_sum;

}

