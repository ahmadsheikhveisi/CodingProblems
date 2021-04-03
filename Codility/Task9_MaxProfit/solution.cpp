// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() < 2)
    {
        return 0;
    }
    int max_profit = 0;
    int min_price = A[0];

    for (size_t cnt = 1; cnt < A.size(); ++cnt)
    {
        int profit_today = A[cnt] - min_price;
        max_profit = (profit_today > max_profit)?profit_today:max_profit;
        min_price = A[cnt] > min_price?min_price:A[cnt];
    }
    if (max_profit < 0)
        max_profit = 0;
    return max_profit;
}

