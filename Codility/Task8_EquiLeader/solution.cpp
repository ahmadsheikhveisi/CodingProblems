// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int equileader_cnt = 0;
    int leader = A[0];
    int leader_cnt = 1;
    for (int cnt = 1; cnt < A.size(); ++cnt)
    {
        int num = A[cnt];
        if (leader_cnt == 0)
        {
            leader_cnt = 1;
            leader = num;
        }
        else
        {
            if (leader == num)
            {
                leader_cnt++;
            }
            else
            {
                leader_cnt--;
            }
        }
    }
    if (leader_cnt == 0)
    {
        return 0;
    }
    
    int leader_total = 0;
    for (auto num : A)
    {
        if (num == leader)
        {
            leader_total++;
        }
    }
    if (leader_total <= A.size() / 2)
    {
        return 0;
    }

    int left_leader_cnt = 0;
    for (int cnt = 0; cnt < A.size(); ++cnt)
    {
        if (A[cnt] == leader)
        {
            left_leader_cnt++;
        }
        int right_leader_cnt = leader_total - left_leader_cnt;
        if ((left_leader_cnt > (cnt + 1) / 2) && 
        (right_leader_cnt > (A.size() - cnt - 1) / 2))
        {
            equileader_cnt++;
        }
    }
    return equileader_cnt;
}

