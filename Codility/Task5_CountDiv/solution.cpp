// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if (B == A)
    {
        if (B % K == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (A % K)
    {
        if (A + K - A%K < B)
        {
            A = A + K - A%K;
        }
    }
    if (B % K)
    {
        if (B - B%K > A)
        {
            B = B - B%K;
        }
    }
    //std::cout << A << " " << B << std::endl;
    return (B-A)/K + 1;
    
}