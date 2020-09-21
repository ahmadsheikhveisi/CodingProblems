// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::sort(A.begin(),A.end());
    
    bool plus = true;
    int sum = 0;
    
    for (auto num : A)
    {
        if (plus)
        {
            sum += num;
        }
        else
        {
            sum-=num;
        }
        plus = !plus;
    }
    
    return sum;
}