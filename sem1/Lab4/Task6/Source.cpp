#include <iostream>


int main() {
    std::string op;
    std::cin >> op;
    long long k;
    std::cin >> k;
    long long cnt = 0;
    bool* ck = (bool*)calloc(10, sizeof(bool));
    for (char i : op) {
        if (ck[i - '0'] == false)
            cnt++;
        ck[i - '0'] = true;
    }
    std::cout << cnt << '\n';
    k = op[k - 1] - '0';
    for (long long i = op.size() - 1; i >= 0; i--) {
        if (op[i] - '0' == k)
            std::cout << op.size() - i - 1 << ' ';
    }
}