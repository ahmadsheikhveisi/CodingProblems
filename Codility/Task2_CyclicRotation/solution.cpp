// you can use includes, for example:
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
	if (A.size() == 0)
		return A;
    std::rotate(A.begin(),A.end()-(K%A.size()),A.end());
    return A;
    
}
