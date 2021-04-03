//this one timed out

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    if (N == 1)
        return 1;
    int count = 2;// because of 1 , n 
    for (int i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            if (i * i == N)
            {
                count ++;
            }
            else
            {
                count+=2;
            }
        }
    }
    return count;
}

