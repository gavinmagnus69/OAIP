#include <iostream>
using namespace std;
int main() {
    long long x, y;
    long double a, b, c, k;
    cin >> x >> y >> a >> b >> c >> k;
    if (x == y) {
        x = 0;
        y = 0;
    }
    else if (x < y) {
        x = 0;
    }
    else {
        y = 0;
    }
    if (a > b && a > c) {
        a -= k;
    }
    else if (b > a && b > c) {
        b -= k;
    }
    else {
        c -= k;
    }
    cout << x << ' ' << y << '\n' << a << ' ' << b << ' ' << c;
}