#include <iostream>
#include <limits>
#include <cstdlib>

void printArr(int A[], int N) {
    for (int cnt = 0; cnt < N; ++cnt) {
        std::cout << A[cnt] << ',';
    }
    std::cout << '\n';
}

int compare(const void* a, const void* b) {
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) {
         return 0;
     } else if ( int_a < int_b ) {
         return -1;
     } else {
         return 1;
     }
}

int solution(int A[], int N) {
    if (N < 2) {
        return -2;
    }
    long int result = std::numeric_limits<long int>::max();
    qsort(A, N, sizeof(int), compare);
    printArr(A, N);

    for (int cnt = 1; cnt < N; ++cnt) {
        result = std::min(result, (long int)A[cnt] - (long int)A[cnt - 1]);
    }

    if (result > 100000000) {
        return -1;
    }

    return result;
}

int main() {
    std::cout << "exercise3\n";
    /*{
        int arr[] = {0, 3, 3, 7, 5, 3, 11, 1};
        std::cout << solution(arr, 8) << '\n';
    }
    {
        int arr[] = { 7, 10, 3, 11, 1};
        std::cout << solution(arr, 5) << '\n';
    }*/
    {
        int arr[] = { std::numeric_limits<int>::min(),
            std::numeric_limits<int>::max(), 0 , 1};
        std::cout << solution(arr, 4) << '\n';
    }
    return 0;
}
