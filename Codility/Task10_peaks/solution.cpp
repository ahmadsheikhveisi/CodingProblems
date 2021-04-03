// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int res = 0;
    int N = A.size();

    if (N < 3)
        return 0;

    vector<int> peaks(N,0);
    vector<int> peaks_sum(N,0);
    int peaks_count = 0;
    for (int cnt = 1; cnt < N - 1; ++cnt)
    {
        if (A[cnt] > std::max(A[cnt + 1],A[cnt - 1]))
        {
            peaks[cnt] = 1;
            peaks_count++;
        }
        peaks_sum[cnt] = peaks_count;
    }
    peaks_sum[N - 1] = peaks_count;

    vector<int> possible_num_blocks;
    int Nsqrt = sqrt(N);
    for (int cnt = 1; cnt <= Nsqrt; cnt++)
    {
        if (N % cnt == 0)
        {
            possible_num_blocks.push_back(cnt);
            possible_num_blocks.push_back(N/cnt);
        }
    }

    for (int cnt = 0; cnt < possible_num_blocks.size(); ++cnt)
    {
        int previous_index = 0;
        int index = possible_num_blocks[cnt] - 1;
        bool valid = true;
        while ((index < N) && valid)
        {
            if (peaks_sum[index] - peaks_sum[previous_index] < 1)
            {
                valid = false;
            }
            //std::cout << cnt << " " << possible_num_blocks[cnt] << " " << index << " " << peaks_sum[index] << " " << res << " " << valid << " " << previous_index << " " << peaks_sum[previous_index] << std::endl;
            previous_index = index;
            index+= possible_num_blocks[cnt];
        }
        if (valid)
        {
            res = std::max(res,N / possible_num_blocks[cnt]);
        }
    }

    return res;
}

