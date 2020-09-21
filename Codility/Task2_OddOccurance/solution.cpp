// you can use includes, for example:
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> tested;
    
    for (auto num : A)
    {
        if (std::find(tested.begin(), tested.end(),num) == tested.end())
        {
            if (std::count(A.begin(), A.end(),num) % 2)
            {
                return num;
            }
            tested.push_back(num);
        }
    }
    
    //NOT FOUND this shouldn't happen
    return 0;
}
