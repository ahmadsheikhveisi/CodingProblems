// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> m_stack;
    int leader = -1;
    for (auto it = A.begin(); it < A.end(); ++it)
    {
        if (m_stack.size() > 0)
        {
            if (m_stack.back() == *it)
            {
                m_stack.push_back(*it);
            }
            else
            {
                m_stack.pop_back();
            }
        }
        else
        {
            m_stack.push_back(*it);
        }
    }
    int candidate = std::find(A.begin(), A.end(),m_stack[0]) - A.begin();
    size_t cnt = 0;
    for (auto num : A)
    {
        if (num == m_stack[0])
        {
            cnt++;
        }
    }
    if (cnt > A.size() / 2)
    {
        leader = candidate;
    }
    return leader;
}

