// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int bit_num = sizeof(int)*8;
    
    vector<int> hash((A.size() / bit_num) + 1);
    
    
    for (auto num : A)
    {
        if ((num > 0) && ((int)hash.size() * bit_num >= num))
        {
            hash[(num - 1)/bit_num] |= 0x01 << (num - 1)%bit_num;
        }
    }
    
    auto it = std::find_if(hash.begin(),hash.end(),[](int a){return a != (int)-1;});
    
    if (it == hash.end())
    {
        return hash.size()*bit_num + 1;
    }
    
    int cnt = 0;
    
    while (*it & 0x01)
    {
        *it >>= 0x01;
        cnt++;
    }
    
    return cnt + 1 + (std::distance(hash.begin(),it) * 32);
    
}
