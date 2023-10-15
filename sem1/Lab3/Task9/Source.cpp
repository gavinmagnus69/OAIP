#include <iostream>

int main() {

    long long n, k, a0, an, d = -2;
    long long sumA, sumK = 0;

    std::cout << "enter a0, a(n-1) and k\n";
    std::cin >> a0 >> an >> k;
    if ((an - a0) % k) {
        std::cout << "impossible;";
        return 0;
    }
    n = (an - a0) / k + 1;
    sumA = (1 << n);

    if (n % 2 == 1) sumA *= -1;

    sumA = (sumA - 1) / -3;
    sumA *= a0;

    for (long long i = 1; i < n; i++) {
        sumK += d * i;
        d *= -2;
    }
    sumK *= k;
    std::cout << sumA + sumK;
}