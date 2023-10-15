#include <iostream>
using namespace std;
int main() {
	long long x, y;
	cin >> x >> y;
	if (!x && !y) {
		cout << "ERROR";
		return 0;
	}
	if (!x || !y) {
		cout << "YES";
		return 0;
	}
	if (!(x % y) || !(y % x)) {
		cout << "YES";
		return 0;
	}
	if ((x % y) || (y % x)) {
		cout << "NO";
		return 0;

	}





	cout << "ERROR";
	return 0;
}