// OVERFLOW SOLUTION
/*******************************************************************/
// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    vector<int> res(len,0);
    int lim = *std::max_element(A.begin(), A.end());
    int first = 1;
    int second = 1;
    vector<int> fibo;
    fibo.push_back(first);
    fibo.push_back(second);
    while (lim > 0)
    {
        int temp = second;
        second = first + second;
        first = temp;
        fibo.push_back(second);
        lim--;
    }
    
    for (int cnt = 0; cnt < len; ++cnt)
    {
        res[cnt] = fibo[A[cnt]]%(1<<B[cnt]);
    }
    return res;
}
/*******************************************************************/
// https://app.codility.com/demo/results/training2Y9TDY-5GR/
// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    vector<int> res(len,0);
    int lim = *std::max_element(A.begin(), A.end());
    int bit_num = *std::max_element(begin(B),end(B));
    int bit_filter = (1 << bit_num)-1;
    int first = 1;
    int second = 1;
    vector<int> fibo;
    fibo.push_back(first);
    fibo.push_back(second);
    while (lim > 0)
    {
        int temp = second;
        second = (first + second) & (bit_filter);
        first = temp;
        fibo.push_back(second);
        lim--;
    }
    
    for (int cnt = 0; cnt < len; ++cnt)
    {
        res[cnt] = fibo[A[cnt]] & ((1<<B[cnt]) - 1);
    }
    return res;
}

