// https://app.codility.com/demo/results/trainingGZZWWX-VAD/
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

int solution(int N, int M) {
    // write your code in C++14 (g++ 6.2.0)
    //if (M >= N)
    //    return N;

    int mgcd = gcd(N,M,1);

    return (N / mgcd);

}

