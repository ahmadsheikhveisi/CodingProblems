// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int product = 0;
   
    std::sort(A.begin(),A.end());
   
    product = A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];
   
    if (product < A[A.size() - 1] * A[0] * A[1])
    {
        product = A[A.size() - 1] * A[0] * A[1];
    }
   
    return product;
}

