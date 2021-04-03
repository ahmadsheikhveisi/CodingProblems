// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    vector<int> max_sum_end(len,0);

    int max_sum = 0;
    for (int cnt = 1; cnt < len - 1; ++cnt)
    {
        max_sum_end[cnt] = std::max(max_sum_end[cnt - 1] + A[cnt], 0);
    }

    vector<int> max_sum_start(len,0);


    for (int cnt = len - 2; cnt > 0; --cnt)
    {
        max_sum_start[cnt] = std::max(max_sum_start[cnt + 1] + A[cnt], 0);
    }

    for (int cnt = 0; cnt < len ; ++cnt)
    {
        std::cout << max_sum_end[cnt] << " " << max_sum_start[cnt] << std::endl;
    }

    for (int cnt = 1; cnt < len - 1; ++cnt)
    {
        std::cout << max_sum_end[cnt - 1] << " " << max_sum_start[cnt + 1] << " " << max_sum << std::endl;
        max_sum = std::max(max_sum, max_sum_start[cnt + 1] + max_sum_end[cnt - 1]);
    }

    return max_sum;

}

