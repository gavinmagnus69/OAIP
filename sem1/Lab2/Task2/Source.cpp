#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double x, y, z;
	cin >> x >> y >> z;
	if ((x + y) > z && (x + z) > y && (y + z) > x) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;

}