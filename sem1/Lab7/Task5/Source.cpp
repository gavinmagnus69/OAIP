#include <iostream>
#include <cmath>
int CountInterestingInInterval(int interval_end)
{
    return  (interval_end + 1) / 10;
}
int main() {
    int n;
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        std::cout << CountInterestingInInterval(n);
        if (i != t - 1) {
            std::cout << "\n";
        }
    }
}