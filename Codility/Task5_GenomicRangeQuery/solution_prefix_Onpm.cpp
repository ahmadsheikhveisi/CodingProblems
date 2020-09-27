// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> res;
    vector<vector<int>> pre_fix_sum(3);
    // to cover the 0..1 we need to know the first occurance
    pre_fix_sum[0].push_back(0);
    pre_fix_sum[1].push_back(0);
    pre_fix_sum[2].push_back(0);
    
    
    //std::cout << pre_fix_sum[0].back() << " " << pre_fix_sum[1].back() << " " << pre_fix_sum[2].back() << std::endl; 
    for (auto it : S)
    {
        pre_fix_sum[0].push_back((it == 'A'?1:0) + pre_fix_sum[0].back());
        pre_fix_sum[1].push_back((it == 'C'?1:0) + pre_fix_sum[1].back());
        pre_fix_sum[2].push_back((it == 'G'?1:0) + pre_fix_sum[2].back());
        
        //std::cout << pre_fix_sum[0].back() << " " << pre_fix_sum[1].back() << " " << pre_fix_sum[2].back() << std::endl; 
    }
    
    for (unsigned int cnt = 0; cnt < P.size(); ++cnt)
    {
        if (P[cnt] == Q[cnt])
        {
            if (S[P[cnt]] == 'A')
            {
                res.push_back(1);
            }
            else if (S[P[cnt]] == 'C')
            {
                res.push_back(2);
            }
            else if (S[P[cnt]] == 'G')
            {
                res.push_back(3);
            }
            else
            {
                res.push_back(4);
            }
        }
        else if (pre_fix_sum[0][Q[cnt]+1] - pre_fix_sum[0][P[cnt]] > 0)
        {
            res.push_back(1);
        }
        else if (pre_fix_sum[1][Q[cnt]+1] - pre_fix_sum[1][P[cnt]] > 0)
        {
            res.push_back(2);
        }
        else if (pre_fix_sum[2][Q[cnt]+1] - pre_fix_sum[2][P[cnt]] > 0)
        {
            res.push_back(3);
        }
        else 
        {
            res.push_back(4);
        }
    }
    
    return res;
}

