// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    if (N < 3)
        return 0;
    int flags = 0;
    vector<int> peaks(N,0);
    int peaks_count = 0;
    for (int cnt = 1; cnt < N - 1; ++cnt)
    {
        if (A[cnt] > std::max(A[cnt + 1],A[cnt - 1]))
        {
            peaks[cnt] = 1;
            peaks_count++;
        }
    }

    vector<int> next_peak(N,0);
    next_peak[N-1] = -1;

    for (int cnt = N - 2; cnt >= 0; --cnt)
    {
        if (peaks[cnt] == 1)
        {
            next_peak[cnt] = cnt;
        }
        else
        {
            next_peak[cnt] = next_peak[cnt + 1];
        }       
    }
    int cnt = 1;
    while((cnt - 1) * cnt <= N) // we cant have more than N/cnt + 1 flags because of space between flags
    {
        int pos = 0;
        int num = 0;
        while ((pos < N) && (num < cnt))
        {
            pos = next_peak[pos];
            if (pos == -1) // at the end which means cnt = N - 1
            {
                //std::cout << "break" << std::endl;
                break;
            }
            num++;
            //std::cout << "cnt " << cnt << " num " << num << " pos " << pos << " next pos " << pos+cnt << std::endl;
            pos += cnt;
        }
        flags = std::max(num,flags);
        cnt++;
        //std::cout << "------" << std::endl;
    }

    return flags;
    
}

