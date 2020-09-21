// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int res = 0;
    int cnt = 0;
    bool first_one = false;
    while(N)
    {
        //std::cout << N << " " << cnt << " " << res << " " << first_one << std::endl;
        if ( (N & 0x1) == 0x0)
        {
            if (first_one)
            {
                cnt++;
                if (res < cnt)
                {
                    res = cnt;
                }
            }
        }
        else 
        {
            cnt = 0;
            first_one = true;
        }
        N = N >> 1;
    }
    
    return res;
}
