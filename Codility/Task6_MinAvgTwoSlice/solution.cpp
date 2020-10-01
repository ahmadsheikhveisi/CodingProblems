// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int m_len = 2;
    int m_index = 0;
    int m_sum = A[0] + A[1];
    int g_sum = m_sum;
    int g_len = 2;
    int g_index = 0;

    for (int cnt = 2; cnt < (int)A.size(); ++cnt)
    {
        //std::cout << (A[cnt] + m_sum) << " " << (A[cnt] + A[cnt - 1]) << std::endl;
        //std::cout << (cnt - m_index + 1) << " " << 2 << std::endl;
        if ((A[cnt] + m_sum)*2 <= (A[cnt] + A[cnt - 1])*(cnt - m_index + 1))
        {
            m_sum = m_sum + A[cnt];
            //std::cout << "same left index " << m_index << " " << m_sum << std::endl;
            m_len = cnt - m_index + 1;
        }
        else
        {
            m_index = cnt - 1;
            m_sum = A[cnt] + A[cnt - 1];
            //std::cout << "new left index " << m_index << " " << m_sum << std::endl;
            m_len = 2;
        }
        
        if (m_len*g_sum > g_len*m_sum)
        {
            g_len = m_len;
            g_sum = m_sum;
            g_index = m_index;
        }
    }
    
    return g_index;
}

