https://app.codility.com/demo/results/trainingADBREG-UCH/

// you can use includes, for example:
// #include <algorithm>
#include <climits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    if (len <= 1)
        return 1;

    vector<int> fibo;
    fibo.push_back(1);
    fibo.push_back(1);
    
    while (fibo.back() < len + 1)
    {
        fibo.push_back(fibo.back() + *(fibo.end() - 2));
        //std::cout << fibo.back() << std::endl; 
    }
    int fibo_size = fibo.size();


    vector<int> min_jumps(A.size() + 2,0);
    min_jumps[0] = 1; // already there

    for (int cnt = 1; cnt < len + 2; ++cnt)
    {
        if (cnt <= len && A[cnt - 1] == 0)
        {
            continue;
        }
        int min_reachable_jumps = len + 2;
        bool found = false;
        for (int fibo_cnt = 1; fibo_cnt < fibo_size; ++fibo_cnt)
        {            
            if (cnt >= fibo[fibo_cnt] && min_jumps[cnt-fibo[fibo_cnt]] > 0 && min_reachable_jumps > min_jumps[cnt-fibo[fibo_cnt]])
            {
                min_reachable_jumps = min_jumps[cnt - fibo[fibo_cnt]];
                found = true;
            }

        }
        if (found)
        {
            min_jumps[cnt] = min_reachable_jumps + 1;
        }
        

    }
    
    return min_jumps.back() - 1;
}

