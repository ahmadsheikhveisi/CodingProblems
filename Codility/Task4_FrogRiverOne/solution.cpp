// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int result = -1;
    
    vector<unsigned int> leaves(A.size()/8 + 1, 0);
    
    int position = 0;
    
    unsigned int bit_size = sizeof(unsigned int) *8;
    
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        leaves[*it/bit_size] |= 0x01 << (*it%bit_size);
        
        //std::cout << leaves[0] << " " << position << " " << bit_size << std::endl;
        
        while (((leaves[(position+1)/bit_size] >> ((position+1)%bit_size)) & 0x01) == 0x01)
        {
            ++position;
            
            if (position >= X)
            {
                result = it - A.begin();
                break;
            }
        }
    }
    
    
    return result;
    
}
