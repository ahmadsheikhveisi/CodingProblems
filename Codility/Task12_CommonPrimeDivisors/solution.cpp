//https://app.codility.com/demo/results/training5SPFWU-GGE/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int gcd(int a, int b, int res)
{
    if (a == b)
    {
        return res * a;
    }
    else if ((a % 2 == 0) && (b % 2 == 0))
    {
        return gcd(a / 2,b / 2,res * 2);
    }
    else if (a % 2 == 0)
    {
        return gcd(a / 2, b, res);
    }
    else if (b % 2 == 0)
    {
        return gcd(a, b / 2, res);
    }
    else if (a > b)
    {
        return gcd(a - b, b, res);
    }
    else 
    {
        return gcd(a, b - a, res);
    }
}

int getalldivisors(int num, int mgcd)
{
    while (num != 1)
    {
        int tgcd = gcd(num, mgcd, 1);
        if (tgcd == 1)
        {
            return num;
        }
        num /= tgcd;
    }
    return num;
}

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    int res = 0;
    for (int cnt = 0; cnt < len; ++cnt)
    {
        int num1 = A[cnt];
        int num2 = B[cnt];
        int mgcd = gcd(num1,num2,1);
        if (1 == getalldivisors(num1,mgcd) &&
            1 == getalldivisors(num2,mgcd))
        {
            res++;
        }
    }
    return res;
}

