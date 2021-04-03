// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    long long int max_sum = A[0];
    long long int sum = A[0];
    for (size_t cnt = 1; cnt < A.size(); ++cnt)
    {
        sum = (A[cnt]>(A[cnt] + sum))?A[cnt]:A[cnt] + sum;//std::max(A[cnt],A[cnt] + sum);
        max_sum = (sum>max_sum)?sum:max_sum;//std::max(sum,max_sum);
    }

    return max_sum;
}

