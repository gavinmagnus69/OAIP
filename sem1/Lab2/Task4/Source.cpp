#include <iostream>
using namespace std;
int main() {
	long double x, y;
	cin >> x >> y;
	x == y ? cout << "they are equal" : (x > y ? cout << x : cout << y);
}