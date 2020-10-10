// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum = 0;
    
    int east_ward_cars = 0;
    
    for (auto car : A)
    {
        if (car == 0)
        {
            east_ward_cars++;
        }
        else
        {
            if (sum > 1000000000 - east_ward_cars)
            {
                sum = -1;
                break;
            }
            sum += east_ward_cars;
        }
    }
    
    return sum;
}

