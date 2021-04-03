// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> fish;
    int up_streamer = 0;
    for (int cnt = 0; cnt < A.size(); ++cnt)
    {
        if (B[cnt] == 1)
        {
            fish.push_back(A[cnt]);
        }
        else
        {
            while (fish.size() != 0 && (A[cnt] > fish.back()))
            {
                fish.pop_back();
            }
            if (fish.size() == 0)
            {
                up_streamer++;
            }
        }
    }

    return up_streamer + fish.size();
}

