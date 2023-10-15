#include <iostream>
using namespace std;
int main() {
    long double a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0) {
        cout << "Incorrect input";
        return 0;
    }
    if ((a <= x && b <= y) || (b <= x && a <= y) || (a <= x && c <= y) || (c <= x && a <= y) || (b <= x && c <= y) || (c <= x && b <= y)) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;

}