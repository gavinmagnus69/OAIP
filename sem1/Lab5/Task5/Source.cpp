#include <iostream>
#include <cmath>
long double mar(long long a[],long long c) {
    long long sum = 0;
    for (int i = 0; i < c; i++) {
        sum += a[i];
    }
    sum /= c;
    return sum;
}
void chklong(long long* a) {
    while (true) {
        std::cin >> *a;
        std::cin.ignore(111111, '\n');
        if (std::cin.fail() || (std::cin.peek() != '\n' && std::cin.peek() != ' ')) {
            std::cin.clear();
            std::cin.ignore(111111, '\n');
            std::cerr << "Incorrect input,try again\n";
        }
        else
            return;
    }
}
void solve5() {
    long long m;
    long long k;
    std::cout << "Enter m of array:\n";
    chklong(&m);
    std::cout << "enter k of array:\n";
    chklong(&k);
    long long** a = new long long* [m];
    for (int i = 0; i < m; i++) {
        a[i] = new long long[k];
    }
    long long tmp = 0;
    std::cout << "\nenter elements of array(integers only):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
           chklong(&tmp);
           a[j][i] = tmp;
            //std::cin >> a[i][j];
        }
    }
    long long max;
    long long cnt = 0;
    if (k % 2 != 0) {
        max = k - 2;
    }
    else {
        max = k-1;
    }
    for (int i = 1; i <= max; i += 2) {
        for (int j = 0; j < m; j++) {
            if (abs(a[j][i]) % 2 != 0) {
                cnt++;
            }
        
        }
    
    }
    if (cnt == 0) {
        std::cout << "there are no elements like that";
        return ;
    }
    long long inc = 0;
    long long* b = new long long[cnt];
    for (int i = 1; i <= max; i += 2) {
        for (int j = 0; j < m; j++) {
            if (abs(a[j][i]) % 2 != 0) {
                b[inc] = a[j][i];
                inc++;
            }
        }
    }
    long double ans = mar(b, cnt);
    std::cout << " answer = " << ans;
}
int main() {
    solve5();
}