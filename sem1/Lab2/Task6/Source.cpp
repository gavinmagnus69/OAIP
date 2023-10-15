#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long double z, a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c == 0) {
        cout << "ERROR";
        return 0;
    }
    if (c >= d && a < d) {
        z = a + b / c;
        cout << setprecision(20) << z;
        return 0;
    }
    if (c < d && a >= d) {
        z = a - b / c;
        cout << setprecision(20) << z;
        return 0;
    }
    z = 0;
    cout << setprecision(20) << z;
    return 0;
}