#include <iostream>
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
long long mult(long long a[], long long cnt) {
    long long ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans *= a[i];
    }
    return ans;
}
void solve3() {
    long long n;
    long long k;
    std::cout << "enter n of array:\n";
    chklong(&n);
    std::cout << "enter k of array:\n";
    chklong(&k);
    long long** a = new long long* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new long long[k];
    }
    std::cout <<n<<" "<<k<< " enter elements of array:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            std::cin>>a[i][j];
        }
    }
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][i] % 2 == 0) {
            cnt++;
        }
    }
    long long* b = new long long[cnt];
    long long inc = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][i] % 2 == 0) {
            b[inc] = a[i][i];
            inc++;
        }
    }
    long long ans;
    ans = mult(b, cnt);
    if (cnt != 0) {
        std::cout << "\nnew array:\n";
        for (int i = 0; i < cnt; i++) {
            std::cout << b[i] << " ";
        }
        std::cout << "\nmultipling:\n";
        std::cout << "n" << ans;
    }
    if (cnt == 0) {
        std::cout << "\nthere are no elements";
    }
}
/*long long test3(long long** a, int n) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][i] % 2 == 0) {
            cnt++;
        }
    }
    long long* b = new long long[cnt];
    long long inc = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][i] % 2 == 0) {
            b[inc] = a[i][i];
            inc++;
        }
    }
    long long ans;
    long long ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans *= b[i];
    }
    if (cnt != 0) {
        return ans;
    }
    if (cnt == 0) {
        return 2281337;
    }


}*/



int main() {
	solve3();
}