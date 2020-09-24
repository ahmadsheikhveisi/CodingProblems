// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int bit_num = sizeof(int) * 8;
    
    vector<int> hash(A.size()/8 + 1);
    
    for (auto num : A)
    {
        if ((int)hash.size() * bit_num >= num)
        {
            hash[(num-1) / bit_num] |= 0x01 << (num-1)%bit_num;
        }
    }
    
    for (unsigned int cnt = 0; cnt < A.size(); ++cnt)
    {
        if (((hash[cnt/bit_num] >> (cnt%bit_num)) & 0x01) == 0x00)
        {
            return 0;
        }
    }
    return 1;
}
