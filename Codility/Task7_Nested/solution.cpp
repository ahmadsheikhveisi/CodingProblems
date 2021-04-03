// you can use includes, for example:
// #include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    vector<char> m_stack;
    for (auto it = S.begin(); it < S.end(); ++it)
    {
        if (*it == '(')
        {
            m_stack.push_back(')');
        }
        else 
        {
            if ((m_stack.size() > 0) && (*it == m_stack.back()))
            {
                m_stack.pop_back();
            }
            else
            {
                return 0;
            }  
        }
    }
    if (m_stack.size() == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

