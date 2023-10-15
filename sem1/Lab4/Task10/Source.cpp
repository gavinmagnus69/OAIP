#include <iostream>
#include <stdlib.h>
int main() {
    long long n, sum = 0;
    std::cin >> n;
   long long * arr = new long long[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < n; ++i)
        if (arr[i] > 1)
            sum += arr[i] - 1;
    std::cout <<sum;
    delete [] arr;

}