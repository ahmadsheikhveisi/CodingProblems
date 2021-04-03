// you can use includes, for example:
#include <algorithm>
#include <limits>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // std::cout << std::numeric_limits<int>::min()  << std::endl;
    std::sort(A.begin(),A.end());

    for (int cnt = 2; cnt < A.size();++cnt)
    {
        if (A[cnt] > 0 && A[cnt - 1] > 0 && A[cnt - 2] > 0)
        {
            if (A[cnt - 1] > A[cnt] - A[cnt - 2])
            {
                return 1;
            }
        }
    }
    return 0;
}














// you can use includes, for example:
#include <algorithm>
#include <limits>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    // std::cout << std::numeric_limits<int>::min()  << std::endl;
    std::sort(A.begin(),A.end());

    for (int cnt = 2; cnt < A.size();++cnt)
    {
        if (A[cnt] > 0 && A[cnt - 1] > 0 && A[cnt - 2] > 0)
        {
            if ((std::numeric_limits<int>::max() - A[cnt - 1] > A[cnt - 2]) && (A[cnt - 1] + A[cnt - 2] > A[cnt]))
            {
                return 1;
            }
        }
    }
    return 0;
}

