// you can use includes, for example:
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int res = 1;
    
    std::sort(A.begin(),A.end());
    
    for (auto num : A)
    {
        if (num > res)
        {
            return res;
        }
        else if (num == res)
        {
            res++;
        }
    }
    
    return res;
}
